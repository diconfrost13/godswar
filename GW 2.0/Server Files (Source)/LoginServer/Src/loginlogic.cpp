//========================================================
//
//    Copyright (c) 2006,福州天盟工作室
//    All rights reserved.
//
//    文件名称 ： LoginLogic.cpp
//    摘    要 ： 登陆服务器逻辑
//    
//    当前版本 ： 1.01
//    作    者 ： 李锋军
//    完成日期 ： 2007-01-08
//
//========================================================

#include "..\Inc\stdafx.h"
#include "..\inc\LoginLogic.h"
#include "..\..\Common/Include/Base\Inc\IMessage.h"
#include "..\..\Common/Include/Base\inc\Ini.h"
#include "..\inc\Session.h"
#include "..\..\Common/Include/sNet\Socket.h"

#include <mmsystem.h>

#define   GODSWAR_TESTSWITCH_ON

using namespace std;

#define OUT_PUT(x) #x

enum STATE_TYPE{ OFFLINE, NORMAL, BUSY, FULL };  //开启,空闲,繁忙,已满,关闭

 namespace login
 {
	//-------------------------------------------------
	char CLogin:: ValidateCode[25] ;

	//-------------------------------------------------
	CLogin::CLogin()//20080618: m_pPort(NULL),m_pKernel(NULL)
	{
		sbase::CIni ini("config.ini", true );
		 m_version = ini.GetData( "System", "Version" );
		m_NetService = NULL;
		 m_pDB = NULL;
		m_GameServerInfo.clear();

		m_pSrvIocp = new snet::CIOCP();
		//m_Socket.clear();
	}


	//-------------------------------------------------
	bool
	CLogin::LoadDBSercice()
	{

		char szDBServer[64]	= "";
		char szLoginName[64]= "";
		char szPassword[64]	= "";
		char szDBName[64]	= "";

		sbase::CIni ini("config.ini", false );
		strcpy( szDBServer,ini.GetString( "Database", "DBServer") );
		strcpy( szLoginName,ini.GetString( "Database", "LoginName") );
		strcpy( szPassword,ini.GetString( "Database", "Password") );
		strcpy( szDBName,ini.GetString( "Database", "DBName") );

		 m_pDB = dbtool::DatabaseCreate(szDBServer,  szLoginName, szPassword, szDBName);

		return true;
	}
	//-------------------------------------------------
	CLogin::~CLogin()
	{
		SAFE_DELETE(m_pThread);
		SAFE_DELETE(m_pSrvIocp);

	 	GAMESERVER_SOCKET::iterator it = m_GameServerInfo.begin();
	 	for (; it != m_GameServerInfo.end(); it++)
	 	{
	 		SAFE_DELETE((*it).second);
	 	}
	 	m_GameServerInfo.clear();
	 	m_GameServerMap.clear();
	 
	 
	 	SAFE_RELEASE(m_pDB);
	} 

	//-------------------------------------------------
	//查询数据库,该玩家账户是否存在
	//-------------------------------------------------
	bool CLogin::CheckDB( const char * Name, const char* password, void* socket ) 
	{	
		if (m_pDB)
		{
			CSession  *pSession = new CSession( Name, password, socket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDBRequest();
				return true;
			}
				
		}

		return false;

	}

	void  CLogin::Close()
	{

	}

	//-------------------------------------------------
	//加载网络服务
	//-------------------------------------------------
	bool CLogin::LoadNetService()
	{
		 char szIP[32]	 = {0};
		 char szPort[12] = {0};	 
		 int  PreNew =  0;

		 sbase::CIni _ini("config.ini", false);
		 strcpy(szIP, _ini.GetString("System", "IP"));
		 strcpy(szPort,_ini.GetString("System", "ListenPort"));
		 PreNew = _ini.GetData("System","MaxOnline");

		 printf( ">>Initialize Net...\n");
		 if (!m_pSrvIocp->Init(szIP, szPort, 0, 1, 6, PreNew))
		 {
			 printf( "Initialize Net Failed!\n");
			 return false;
		 }

		return true;
	}

	//----------------------------------------------------------------
	//分析接受队列中的消息包
	//----------------------------------------------------------------
	int CLogin::Process()
	{

		snet::CSocket* pNewSocket = m_pSrvIocp->PopNewConnect();

		//处理新连接
		while( NULL != pNewSocket ) 
		{
			assert( pNewSocket->m_pIOCP );

			NewSocketProc(pNewSocket);

			pNewSocket = m_pSrvIocp->PopNewConnect();
		}

		OnRead();
		OnWrite();

		return 0;
	}

	//-------------------------------------------------
	//登陆服务器启动
	//-------------------------------------------------
	bool 
	CLogin::Run()
	{   
		if(!LoadNetService())
			return false;
		 
#ifdef GODSWAR_TESTSWITCH_ON
		if(!LoadDBSercice())
			return false;
#endif
		m_pThread = sbase::CThread::CreateNew(*this, sbase::CThread::RUN, 10);
		if( m_pThread == NULL )
			return false;
		m_pThread->SetThreadAMask( 12 );
		cout<<"Initialize Successfully!\n"<<endl;
		sbase::SetConsoleFontColor( FOREGROUND_INTENSITY );

		return true;

	}

	//--------------------------------------------------
	//登陆成功,产生校验码
	//--------------------------------------------------
	char*
	CLogin::CreateValidateCode( )
	{
		int RanCheckNum = 0;
	 	char keytemp[5]={0};
	 	memset(CLogin::ValidateCode,0x30,18);
	 	srand((unsigned)timeGetTime());                  //产生随机数种子
	 	for(int i=0;i<6;i++)
	 	{ 
	 		RanCheckNum = rand();                        //产生随机数
	 		_itoa(RanCheckNum,keytemp,16);               //将随机数转换成16进制
	 		memcpy(&CLogin::ValidateCode[i*4],keytemp,strlen(keytemp));
	 	}
	 	CLogin::ValidateCode[24]=0x00;
	 	return CLogin::ValidateCode;
	}

	//---------------------------------------------------
	void
	CLogin::SendMsg( void* buf,  void * pSocket, int nLen ) const
	{
		snet::CSocket* pSendSocket = static_cast<snet::CSocket*>(pSocket);
		pSendSocket->PackMsg((char*)buf, nLen);
	}

	bool 
	CLogin::JudgeValidStr( MSG_LOGIN* pMsgLogin, void *pSocket )
	{

		//构造登陆返回消息
		MSG_LOGIN_RETURN_INFO  Login_info;
		Login_info.Head.usSize    = sizeof(MSG_LOGIN_RETURN_INFO);
		Login_info.Head.usType    = _MSG_LOGIN_RETURN_INFO;


		//长度限制
		if ( strlen( pMsgLogin->Name ) > MAX_ACCOUNT_SIZE  ||  strlen( pMsgLogin->cPassWord ) > MAX_ACCOUNT_SIZE  )
		{
			Login_info.ucInfo = 0 ;
			SendMsg(&Login_info, pSocket, Login_info.Head.usSize);
			static_cast<snet::CSocket*>(pSocket)->Write();
			return false;
		}

		 //帐号限制
		 for ( int a = 0; a < (int)strlen( pMsgLogin->Name ); a++ )
		 {
			if (!( isalpha( pMsgLogin->Name[a] ) || isdigit( pMsgLogin->Name[a] ) || pMsgLogin->Name[a] == '_' ) )
			{
			   Login_info.ucInfo = 0 ;
			   SendMsg(&Login_info, pSocket, Login_info.Head.usSize );
			   static_cast<snet::CSocket*>(pSocket)->Write();
			   return false;
			}
		      
		 }

		return true;
	}

	void CLogin::ReslovePacket( const void * pPacket, snet::CSocket *pSocket)
	{
		
		MsgHead* pszBuff = (MsgHead*)pPacket;

		switch(pszBuff->usType)
		{
		case _MSG_GAMESERVER_INFO:
			{
				MSG_GAMESERVER_INFO*  Server = (MSG_GAMESERVER_INFO*)pszBuff;
				switch(Server->cState)
				{
				case OFFLINE: //启动
				case NORMAL:  //正常
				case BUSY:    //繁忙 
				case FULL:    //已满
					{
						GAMESERVER_ID::iterator itor = m_GameServerMap.find(Server->cID);
						if (itor != m_GameServerMap.end())
						{
							MSG_GAMESERVER_INFO * pServer  = (*itor).second;
							pServer->cState = Server->cState;
						}
						else
						{
							MSG_GAMESERVER_INFO* msg_Register = new MSG_GAMESERVER_INFO;
							memcpy( msg_Register, pszBuff, sizeof( MSG_GAMESERVER_INFO ));
							m_GameServerInfo[pSocket] = msg_Register;
							m_GameServerMap[msg_Register->cID] = msg_Register;
						}

					}
					break;
				}
			}
			break;
		case _MSG_REQUEST_GAMESERVER:
			{
				MSG_REQUEST_GAMESERVER* Choose = (MSG_REQUEST_GAMESERVER*)pszBuff;
				CSession *pPlayerSession = FindAccount( Choose->Name  );
				if (  NULL == pPlayerSession  )
					break;

				if ( pPlayerSession->GetGSCheckFlag() )
					break;

				GAMESERVER_ID::iterator serveritor ;
				serveritor = m_GameServerMap.find(Choose->cGameServerID);
				if( serveritor != m_GameServerMap.end())
				{
					MSG_GAMESERVER_INFO* temp = (*serveritor).second;
					GAMESERVER_SOCKET::iterator servesocket = m_GameServerInfo.begin(); 
					for ( ; servesocket != m_GameServerInfo.end(); servesocket++ )
					{
						if ((*servesocket).second == temp  )
						{
							MSG_RESPONSE_GAMESERVER Serverok;
							Serverok.Head.usSize   = sizeof(MSG_RESPONSE_GAMESERVER);
							Serverok.Head.usType   = _MSG_RESPONSE_GAMESERVER;


							//服务器已满，禁止登录
							if ( serveritor->second->cState == FULL )
							{
								Serverok.cGameServerID = 0;
								Serverok.uiPort        = 0;
								strcpy( Serverok.cIP, "" );
								Serverok.cLoginError = 1;
							}
							else
							{
								Serverok.cGameServerID = temp->cID;
								Serverok.uiPort        = temp->uiPort;
								strcpy( Serverok.cIP, temp->cIP );
								Serverok.cLoginError = 0;
								strcpy(Serverok.cCheckOutText,CreateValidateCode());

								MSG_VALIDATE_GAMESERVER   gameserver_valid;
								gameserver_valid.Head.usType   = _MSG_VALIDATE_GAMESERVER;
								gameserver_valid.Head.usSize   = sizeof(MSG_VALIDATE_GAMESERVER);
								strcpy( gameserver_valid.cCheckOutText, Serverok.cCheckOutText);
								strcpy( gameserver_valid.Accounts, Choose->Name );


								//向游戏服务器发送该玩家的验证信息(也可以将此改为向数据库写入)
								SendMsg( &gameserver_valid,(*servesocket).first, gameserver_valid.Head.usSize);
								pPlayerSession->GSCheckFlag();
							}
							break;
						}
					}
				}
			}
			break;
		case _MSG_VALIDATE_GAMESERVER:
			{
				MSG_VALIDATE_GAMESERVER*  key = (MSG_VALIDATE_GAMESERVER*)pszBuff;
				CSession *pPlayerSession = FindAccount( key->Accounts  );
				if (  NULL != pPlayerSession  )
				{ 
					pPlayerSession->GSCheckFlag();
					GAMESERVER_SOCKET::iterator serveritor ;
					serveritor = m_GameServerInfo.find( pSocket );
					if ( serveritor !=  m_GameServerInfo.end() )
					{
						MSG_RESPONSE_GAMESERVER Serverok;
						Serverok.Head.usSize   = sizeof(MSG_RESPONSE_GAMESERVER);
						Serverok.Head.usType   = _MSG_RESPONSE_GAMESERVER;
						//服务器已满，禁止登录
						if ( serveritor->second->cState == FULL )
						{
							Serverok.cGameServerID = 0;
							Serverok.uiPort        = 0;
							strcpy( Serverok.cIP, "" );
							Serverok.cLoginError = 1;
						}
						else
						{
							Serverok.cGameServerID = serveritor->second->cID;
							Serverok.uiPort        = serveritor->second->uiPort;
							strcpy( Serverok.cIP, serveritor->second->cIP );
							Serverok.cLoginError = 0;
							strcpy(Serverok.cCheckOutText,key->cCheckOutText);  
						}

						//向该玩家登录游戏服务器返回结果
				
						SendMsg(&Serverok, (void*)pPlayerSession->GetSocket(), Serverok.Head.usSize );
						pPlayerSession->AccountCheckFlag();

					}
				}

				//延后删除
				//ClearAccount(pPlayerSession->GetAccount());
				//SAFE_DELETE( pPlayerSession );  

			}
			break;
		case _MSG_BAN_PLAYER:
			break;
		default:
			break;

		}				

	}

	void CLogin::NewSocketProc( snet::CSocket *pSocket )
	{
		MsgHead* pszBuff = NULL;

		if (pSocket->IsValid())
		{
			while (pSocket->Read((char**)&pszBuff))
			{

				switch(pszBuff->usType)
				{
				case _MSG_LOGIN:
					{
						// cout<<"登陆消息..."<<endl;
						MSG_LOGIN*  msg_Login	= (MSG_LOGIN*)pszBuff;

						//版本验证
						if ( msg_Login->fVersion != m_version  )
						{
							MSG_LOGIN_RETURN_INFO  Login_info;
							Login_info.Head.usSize    = sizeof(MSG_LOGIN_RETURN_INFO);
							Login_info.Head.usType    = _MSG_LOGIN_RETURN_INFO;
							Login_info.ucInfo         = 0xff;   
							SendMsg(&Login_info, pSocket, Login_info.Head.usSize);
							pSocket->Write();
							break;
						}

						//字符检测
						if ( !JudgeValidStr( msg_Login, pSocket ) )
						{
							break;
						}

						bool Isfind = true;

#if defined(GODSWAR_TESTSWITCH_ON)
						//查询数据库
						if ( CheckDB( msg_Login->Name, msg_Login->cPassWord, pSocket ) )
						{
							Isfind =  true;
						}
						else
						{
							
						}
#else

#endif
					}
					break;
				case _MSG_GAMESERVER_INFO:
					{
						MSG_GAMESERVER_INFO*  Server = (MSG_GAMESERVER_INFO*)pszBuff;
//						cout<<"GameServer message:"<<Server->ServerName<<endl;
						switch(Server->cState)
						{
						case OFFLINE: //启动
						case NORMAL:  //正常
						case BUSY:    //繁忙 
						case FULL:    //已满
							{
								GAMESERVER_ID::iterator itor = m_GameServerMap.find(Server->cID);
								if (itor != m_GameServerMap.end())
								{
									MSG_GAMESERVER_INFO * pServer  = (*itor).second;
									pServer->cState = Server->cState;
								}
								else
								{
									MSG_GAMESERVER_INFO* msg_Register = new MSG_GAMESERVER_INFO;
									memcpy( msg_Register, pszBuff, sizeof( MSG_GAMESERVER_INFO ));
									m_GameServerInfo[pSocket] = msg_Register;
									m_GameServerMap[msg_Register->cID] = msg_Register;
								}
								
							}
							break;
						default:
							ASSERT(0);
							break;
						}

					}
					break;
				default:
				    return;
				}//end of switch

				pSocket->Remove(pszBuff->usSize);

			} // end while		
		}
		else
		{
			//客户端关闭
			m_pSrvIocp->PushNewClose(pSocket);
		}		
	}

	void CLogin::OnRead()
	{
		snet::CSocket* pSocket  = NULL;
		MsgHead* pszBuff = NULL;
		sbase::CSingleLock xLock(&m_xLock);

		SESSION_MAP::iterator itor = m_AccountsMap.begin();
		while (itor != m_AccountsMap.end())
		{
			pSocket = static_cast<snet::CSocket*>(itor->second->GetSocket());

			if (pSocket->IsValid())
			{
				while (pSocket->Read((char**)&pszBuff))
				{
					//处理消息
					ReslovePacket(pszBuff, pSocket);

					pSocket->Remove(pszBuff->usSize);

				} 	
			} 
			else
			{
				//客户端关闭
				pSocket->GetIOCP()->PushNewClose(pSocket);
				//删除缓存的Account
				ClearAccount(itor->second->GetAccount());
				break;

			} // end if_else
			itor++;
		} // end while

		GAMESERVER_SOCKET::iterator pos = m_GameServerInfo.begin();
		while (pos != m_GameServerInfo.end())
		{
			pSocket = pos->first;

			if (pSocket->IsValid())
			{
				bool ret = pSocket->Read((char**)&pszBuff);
				while (ret)
				{
					//处理消息
					ReslovePacket(pszBuff, pSocket);

					pSocket->Remove(pszBuff->usSize);

					ret = pSocket->Read((char**)&pszBuff);

				} 
			} 
			else
			{
				//客户端关闭
				pSocket->GetIOCP()->PushNewClose(pSocket);

				GAMESERVER_ID::iterator it = m_GameServerMap.find(pos->second->cID);
				if (it != m_GameServerMap.end())
				{
					SAFE_DELETE((*it).second);
					m_GameServerMap.erase(it);
				}
				m_GameServerInfo.erase(pos);
				break;

			} // end if_else

			pos++;
		} // end while
	}

	void CLogin::OnWrite()
	{
		snet::CSocket* pSocket = NULL;
		sbase::CSingleLock xLock(&m_xLock);

		SESSION_MAP::iterator itor = m_AccountsMap.begin();
		while (itor != m_AccountsMap.end())
		{
			pSocket = static_cast<snet::CSocket*>(itor->second->GetSocket());

			if (pSocket->IsValid())
			{
				pSocket->Write();

				if (itor->second->GetAccountFlag())
				{
					//同时删除会话
					ClearAccount(itor->second->GetAccount());				
					
					break;
				}
			} 
			else
			{
				//客户端关闭				
				pSocket->GetIOCP()->PushNewClose(pSocket);
				ClearAccount(itor->second->GetAccount());
				break;

			} // end if_else
			itor++;
		} // end while

		GAMESERVER_SOCKET::iterator pos = m_GameServerInfo.begin();
		while (pos != m_GameServerInfo.end())
		{
			pSocket = pos->first;
			
			if (pSocket->IsValid())
			{
				pSocket->Write();
			} 
			else
			{
				//客户端关闭
				pSocket->GetIOCP()->PushNewClose(pSocket);

				GAMESERVER_ID::iterator it = m_GameServerMap.find(pos->second->cID);
				if (it != m_GameServerMap.end())
				{
					SAFE_DELETE((*it).second);
					m_GameServerMap.erase(it);
				}
				m_GameServerInfo.erase(pos);
				break;

			} // end if_else

			pos++;
		} // end while
	}

	void CLogin::CacheAccounts( std::string StrName, CSession *pSession )
	{
		sbase::CSingleLock xLock(&m_xLock);
		m_AccountsMap[ StrName ] = pSession;
	}

	CSession * CLogin::FindAccount( std::string StrName )
	{
		SESSION_MAP::iterator  itor = m_AccountsMap.find( StrName );
		if ( itor != m_AccountsMap.end() )
			return itor->second;

		return NULL;
	}

	void CLogin::ClearAccount( std::string StrName )
	{
		sbase::CSingleLock xLock(&m_xLock);

		SESSION_MAP::iterator  itor = m_AccountsMap.find( StrName );

		if ( itor != m_AccountsMap.end() )
		{

			SAFE_DELETE( itor->second );
			m_AccountsMap.erase(itor);

		}
	}


	void CLogin::ShowServerList()
	{
		printf("\n               ★=============游 戏 服 务 器 列 表=============★\n");
// 
// 		printf(" ID【%d】 %-25s %-16s:%d\t状态【启动】\n", 10, "技术内测-电信(D)", "192.168.168.168", 5999);
// 		printf(" ID【%d】 %-25s %-16s:%d\t状态【启动】\n", 10, "技术内测", "192.168.168.168", 5999);
		GAMESERVER_ID::iterator itor = m_GameServerMap.begin();
		while (itor != m_GameServerMap.end())
		{

			printf(" ID【%d】 %-25s %-16s:%d\t状态【", itor->second->cID,
				itor->second->ServerName, itor->second->cIP, itor->second->uiPort);

			switch(itor->second->cState)
			{
			case 0: //启动
				printf("启动】\n");
				break;
			case 1:  //正常
				printf("正常】\n");
				break;
			case 2:    //繁忙 
				printf("繁忙】\n");
				break;
			case 3:    //已满
				printf("已满】\n");
				break;
			default:
				break;
			}//end of switch

			itor++;
		} // end while
	}

}
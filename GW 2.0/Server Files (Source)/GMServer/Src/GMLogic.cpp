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

#include "..\inc\GMLogic.h"
//#include "..\..\Lib_Base\Inc\IMessage.h"
#include "..\..\Common/Include/Base\Inc\Ini.h"
//#include "..\..\Lib_Base\Inc\IniFile.h"
//#include "..\..\Lib_Net\inc\KernelMsgDef.h"

//#include "..\..\Lib_Base\Inc\IPCChannel.h"
#include "..\inc\Session.h"

//#include "..\..\Common/Include/sNet\Socket.h"

#define   GODSWAR_TESTSWITCH_ON
#define   MAX_MSG 2000
using namespace std;

#define OUT_PUT(x) #x

//extern ipc::CNamePipe *g_pGMMgr;


bool g_ConncetGS = true;
namespace login
{
	char CGMLogic:: ValidateCode[25] ;
	static USHORT MsgRouter[2000];

	CGMLogic::CGMLogic()
	{
		m_pSrvIocp = new snet::CIOCP();
		sbase::CIni ini("config.ini", false );
		m_version = ini.GetData( "System", "Version" );
		
		m_pDB = NULL;
		m_UserListMap.clear();
		m_AccountsMap.clear();
		memset(m_LastServerTime,0L,sizeof(m_LastServerTime));
		m_SpeakForbidTime = 0;
		//m_Socket.clear();

	}


	CGMLogic::~CGMLogic()
	{
		SAFE_DELETE(m_pThread);

		SAFE_RELEASE(m_pDB);
	} 
	bool CGMLogic::LoadDBSercice()
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
	//连接GS管道服务器
	//-------------------------------------------------
	bool CGMLogic::ConnectGSPipe()
	{
		printf( ">>Initialize GS PipeClient...\n");

 		m_hPipe = LoadLibrary("Pipe.dll");
 
 		if (m_hPipe == NULL)
 		{
 			printf("LoadLibrary Failed!\n");
 
 			FreeLibrary(m_hPipe);
 
 			return false;
 		}


		memset(m_szDBIp, 0, sizeof(m_szDBIp));
		memset(m_szUserPwd, 0, sizeof(m_szUserPwd));
		memset(m_szUserName, 0, sizeof(m_szUserName));

		sbase::CIni ini("config.ini", false);

		strcpy(m_szDBIp, ini.GetString("PipeServer", "IP"));
		strcpy(m_szUserName, ini.GetString("PipeServer", "LoginName"));
		strcpy(m_szUserPwd, ini.GetString("PipeServer", "PassWord"));


		CreatePipeClient pipeclient = (CreatePipeClient)GetProcAddress(m_hPipe, "PipeCliCreate");

		m_pGMMgr = pipeclient("IPC_GAME", m_szDBIp, m_szUserName, m_szUserPwd );


		if (m_pGMMgr == NULL)
		{
			return false;
		}
		
		if ( !m_pGMMgr->Init())
		{
			printf("Initialize GM PipeServer Failed!\n");
			FreeLibrary(m_hPipe);
			return false;
		}

		return m_pGMMgr->GetStatus();

	}

	//-------------------------------------------------
	//加载网络服务
	//-------------------------------------------------
	bool CGMLogic::LoadNetService()
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

	//-------------------------------------------------
	//登陆服务器启动
	//-------------------------------------------------
	bool CGMLogic::Run()
	{   
		////////权限测试////////////////////////
		// 	 LONGLONG flv;
		// 	 flv = 9223372036854775807;
		// 	 char popedom[64];
		// 	 memset(popedom,0L,sizeof(popedom));
		// 	 sprintf(popedom,"%I64d",flv);
		// 
		// 	 LONGLONG a;
		// 	 a = _atoi64(popedom);
		// 	 a = 1;
		//	if ( flv & (1<<5))
		//	{
		//	}
		////////////////////////////////////////	 

		InitUserList();  //初始化配置表，函数映射表 等信息

		//初始化消息与函数对应表
		memset(MsgRouter,0L,sizeof(MsgRouter));
		USHORT Arrysize = 0;
		const MsgHandle*  Talbe = GetSocHandleTab( Arrysize );
		for ( USHORT a = 0; a < MAX_MSG; a++ )
		{
			if ( a < Arrysize )
				MsgRouter[Talbe[a].MSG_ID]  = a; 
		}

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
		if ( !ConnectGSPipe())
			return false;

		cout<<"Initialize Successfully!\n"<<endl;
		sbase::SetConsoleFontColor( FOREGROUND_INTENSITY );
		return true;

	}
	//----------------------------------------------------------------
	//分析接受队列中的消息包
	//----------------------------------------------------------------
	int CGMLogic::Process()
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

	char* CGMLogic::CreateValidateCode( )
	{
		int RanCheckNum = 0;
		char keytemp[5]={0};
		memset(CGMLogic::ValidateCode,0x30,18);
		srand((unsigned)GetTickCount());                  //产生随机数种子
		for(int i=0;i<6;i++)
		{ 
			RanCheckNum = rand();                        //产生随机数
			_itoa(RanCheckNum,keytemp,16);               //将随机数转换成16进制
			memcpy(&CGMLogic::ValidateCode[i*4],keytemp,strlen(keytemp));
		}
		CGMLogic::ValidateCode[24]=0x00;
		return CGMLogic::ValidateCode;
	}

	void CGMLogic::SendMsg(void* buf, void * pSocket, int nLen) const
	{
		snet::CSocket* pSendSocket = static_cast<snet::CSocket*>(pSocket);
		pSendSocket->PackMsg((char*)buf, nLen);
	}

	bool CGMLogic::JudgeValidStr( MSG_LOGIN* pMsgLogin, void *pSocket )
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



	const MsgHandle*  CGMLogic::GetSocHandleTab( USHORT &Size ) const
	{
		static const MsgHandle  MsgEventHandle[] = 
		{
			{ _MSG_INVALID,							&CGMLogic::Handle_Invalid },
			{ _MSG_LOGIN,							&CGMLogic::Handle_Login },
			{ _MSG_CREATE_ACCOUNTS,                 &CGMLogic::Handle_CreateAccount},
			{ _MSG_DELETE_ACCOUNTS,					&CGMLogic::Handle_DeleteAccount},
			{ _MSG_PASSWORD_CHANGE,					&CGMLogic::Handle_PasswordChange},
			{ _MSG_ACCOUNTS_SEARCH,                 &CGMLogic::Handle_AccountSearch},
			{ _MSG_REPOSIT,							&CGMLogic::Handle_Reposit},
			{ _MSG_SENDOBJECT,						&CGMLogic::Handle_SendObject},
			{ _MSG_OBJECT_INFO,						&CGMLogic::Handle_GetObjectInfo},
			{ _MSG_PLACARD,							&CGMLogic::Handle_SetPlacard},
			{ _MSG_PALCARD_DEL,						&CGMLogic::Handle_DelPlacard},
			{ _MSG_KICKROLE,						&CGMLogic::Handle_SetKickPunish},
			{ _MSG_FORBID_SPEAK,					&CGMLogic::Handle_SetSpeakPunish},
			{ _MSG_FORBID_LAND,						&CGMLogic::Handle_SetLandPunish},
			{ _MSG_FORBID_DEL,						&CGMLogic::Handle_DelLandPunish},
			{ _MSG_TALK,							&CGMLogic::Handle_Talk},
			{ _MSG_LIST_REQUEST,					&CGMLogic::Handle_ForbidLand_List},
			{ _MSG_MAINTENANCE,						&CGMLogic::Handle_Server_ShutDown}


		};

		Size = sizeof(MsgEventHandle)/sizeof(MsgHandle);
		return MsgEventHandle;
	}

	int  CGMLogic::GetIndex( int MsgID )
	{
		if ( MsgID < 0 || MsgID >= MAX_MSG )
		{
			return MsgRouter[0];
		}

		return MsgRouter[MsgID];
	}


	void CGMLogic::ClearAccount( void * socket )
	{
		std::map<void *, std::string>::iterator  itor = m_AccountsMap.find( socket );
		if ( itor != m_AccountsMap.end() )
		{
			MSG_GM_ONLINE_INFO_ONE msg_Gm_one;
			msg_Gm_one.Head.usSize = sizeof( MSG_GM_ONLINE_INFO_ONE );
			msg_Gm_one.Head.usType = _MSG_GM_ONLINE_INFO_ONE;
			msg_Gm_one.ucType = 1;
			strcpy(msg_Gm_one.cName,itor->second.c_str());

			std::map<void*,std::string>::iterator  itor1 = m_AccountsMap.begin();
			for (;itor1 != m_AccountsMap.end();itor1++)
			{
				if (itor1->first)
				{
					SendMsg(&msg_Gm_one,itor1->first, msg_Gm_one.Head.usSize);
				}

			}
			m_AccountsMap.erase(itor);
		}
	}
	bool CGMLogic::CheckUser( const char * Name, const char* password,void* socket)
	{
		//构造登陆返回消息
		MSG_LOGIN_RETURN_INFO  Login_info;
		Login_info.Head.usSize    = sizeof(MSG_LOGIN_RETURN_INFO);
		Login_info.Head.usType    = _MSG_LOGIN_RETURN_INFO;

		//防止重复登陆
		if ( FindSocket(Name) )
		{
			Login_info.ucInfo = 3;
			Login_info.lpopedom = 0;
			SendMsg(&Login_info,socket, Login_info.Head.usSize);
			return false;

		}

		std::map<std::string ,USER_INFO>::iterator itor = m_UserListMap.find(Name);
		if (itor != m_UserListMap.end())
		{

			if(strcmp((*itor).second.password, password)  == 0 )
			{
				Login_info.ucInfo = 1;
				Login_info.lpopedom = (*itor).second.popedom;

				//保存socket与GMname的对应关系
				if ( FindAccount( socket ) )
				{
					ClearAccount( socket );
				}
				CacheAccounts(socket, Name);
				SendMsg(&Login_info, socket, Login_info.Head.usSize);
				SendOnlineGM( Name, socket );
				return true;
			}
			else
			{
				Login_info.ucInfo = 2;
				Login_info.lpopedom = 0;
				SendMsg(&Login_info, socket, Login_info.Head.usSize);
				return false;
			}
		}	
		else
		{
			Login_info.ucInfo = 0;
			Login_info.lpopedom = 0;
			SendMsg(&Login_info, socket, Login_info.Head.usSize);
		}
		return false;
	}

	void CGMLogic::InitUserList()
	{
		//读取用户列表
		m_UserListMap.clear();

		char value[32];
		char name[32];
		char popedom[64];

		memset(value,0L,sizeof(value));
		memset(popedom,0L,sizeof(popedom));
		memset(name,0L,sizeof(name));

		sbase::CIni User_ini("./UserList.ini",false);
		int nUserNum = User_ini.GetData("USER","COUNT");

		for (int i=0; i<nUserNum; i++)
		{
			USER_INFO user_info;
			sprintf(value,"USER%d",i);
			strcpy(name,User_ini.GetString(value,"UserName"));
			strcpy(user_info.password,User_ini.GetString(value,"UserPassword"));
			strcpy(popedom,User_ini.GetString(value,"Popedom"));
			user_info.popedom = atoi(popedom);

			m_UserListMap[name] = user_info;
		}

	}


	bool CGMLogic::DB_GetPlayerInfo_Account( const char* Account ,void* socket )
	{
		if (m_pDB)
		{
			CSession  *pSession = new CSession(socket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_PlayerInfo_Account_Request( Account);
				return true;
			}

		}

		return false;
	}
	bool CGMLogic::DB_GetPlayerInfo_Name(const char * Name, void*socket)
	{
		if (m_pDB)
		{
			CSession  *pSession = new CSession(socket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_PlayerInfo_Name_Request(Name);
				return true;
			}

		}

		return false;
	}

	UINT CGMLogic::GetGmPopedom( const char* Name)
	{
		std::map<std::string ,USER_INFO>::iterator itor = m_UserListMap.find(Name);
		if (itor != m_UserListMap.end())
		{
			//帐号存在
			return (*itor).second.popedom;
		}

		return 0;
	}
	void CGMLogic::SendOnlineGM( const char * name,void * socket)
	{
		//	int nGmNum = m_AccountsMap.size();
		int count = 0;

		MSG_GM_ONLINE_INFO_COVER msg_Online_gm;
		msg_Online_gm.Head.usSize = sizeof( MSG_GM_ONLINE_INFO_COVER );
		msg_Online_gm.Head.usType = _MSG_GM_ONLINE_INFO_COVER;

		MSG_GM_ONLINE_INFO_ONE msg_Gm_one;
		msg_Gm_one.Head.usSize = sizeof( MSG_GM_ONLINE_INFO_ONE );
		msg_Gm_one.Head.usType = _MSG_GM_ONLINE_INFO_ONE;
		msg_Gm_one.ucType = 0;
		strcpy(msg_Gm_one.cName,name);

		memset(&msg_Online_gm.cGM,0L,sizeof(msg_Online_gm.cGM));

		std::map<void*,std::string>::iterator  itor = m_AccountsMap.begin();
		for (;itor != m_AccountsMap.end();itor++)
		{
			if (count < 20)
			{
				strcpy(msg_Online_gm.cGM[count].cName,itor->second.c_str());
				count++;
				continue;
			}

			if (count >=20)
			{
				count = 0;
				msg_Online_gm.nGMNum = 20;
				SendMsg(&msg_Online_gm, socket, msg_Online_gm.Head.usSize);
				memset(&msg_Online_gm.cGM,0L,sizeof(msg_Online_gm.cGM));
			}

		}

		if (count > 0)
		{
			msg_Online_gm.nGMNum = count;
			SendMsg(&msg_Online_gm, socket, msg_Online_gm.Head.usSize);
		}

		itor = m_AccountsMap.begin();
		for (;itor != m_AccountsMap.end();itor++)
		{
			if ( itor->first && itor->first != socket )
			{
				SendMsg(&msg_Gm_one, itor->first, msg_Gm_one.Head.usSize);
			}
		}


	}
	void CGMLogic::Handle_Invalid( void* pPortMsg, snet::CSocket* pSocket )
	{
		return;
	}

	void CGMLogic::Handle_SocketClose( void* pPortMsg, snet::CSocket* pSocket )
	{
		ClearAccount( pSocket);
	}
	void CGMLogic::Handle_Login( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_LOGIN *  msg_Login;
		msg_Login = (MSG_LOGIN*)pPortMsg;
		cout<<"Login message:"<<msg_Login->Name<<endl;

		if ( !CheckUser(msg_Login->Name, msg_Login->cPassWord, pSocket))
		{
			cout<<msg_Login->Name<<":登陆失败"<<endl;
			return;
		}

		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"%s--%s",msg_Login->Name,"Login success");
		sbase::GmLogSave(cLogSave);
	}

	void CGMLogic::Handle_CreateAccount( void* pPortMsg, snet::CSocket* pSocket )
	{
		UINT lPopedon = GetGmPopedom(FindAccount(pSocket));
		if ( lPopedon )
		{
			//return;
		}

		MSG_CREATE_ACCOUNTS *  msg_CreateAccount;
		msg_CreateAccount = (MSG_CREATE_ACCOUNTS*)pPortMsg;

		//判断帐号是否存在
		MSG_ZERO_ONE  CreateAccount_return;
		CreateAccount_return.Head.usSize    = sizeof(MSG_ZERO_ONE);
		CreateAccount_return.Head.usType    = _MSG_CREATE_ACCOUNTS_RETURN;

		std::map<std::string ,USER_INFO>::iterator itor = m_UserListMap.find(msg_CreateAccount->cName);
		if (itor != m_UserListMap.end())
		{
			//帐号存在
			CreateAccount_return.ucInfo = 0;
			SendMsg(&CreateAccount_return, pSocket, CreateAccount_return.Head.usSize);
		}
		else
		{
			//写入配置表
			char value[32];
			char section[32];
			char Popedom[64];	
			char Count[16];

			memset(value,0L,sizeof(value));
			memset(section,0L,sizeof(section));
			memset(Popedom,0L,sizeof(Popedom));
			memset(Count,0L,sizeof(Count));

			const char* file = "./UserList.ini";
			//获取用户数
			GetPrivateProfileStringA("USER","COUNT","",value,sizeof(value),file);
			int nUserNum = atoi(value);


			//写入字段
			sprintf(section,"USER%d",nUserNum);
			sprintf(Count,"%d",nUserNum+1);
			WritePrivateProfileStringA("USER","COUNT",Count,file);

			sprintf(Popedom,"%d",msg_CreateAccount->ucAccountsLv);
			WritePrivateProfileStringA(section,"UserName",msg_CreateAccount->cName,file);
			WritePrivateProfileStringA(section,"UserPassword",msg_CreateAccount->cPassWord,file);
			WritePrivateProfileStringA(section,"Popedom",Popedom,file);

			//重新读取配置表
			InitUserList();

			//保存操作日志
			char cLogSave[1024];
			memset(cLogSave,0L,sizeof(cLogSave));
			sprintf(cLogSave,"操作员 %s: %s %s",FindAccount(pSocket),"create account named:",msg_CreateAccount->cName);
			sbase::GmLogSave(cLogSave);

			//发送创建成功消息
			CreateAccount_return.ucInfo = 1;
			SendMsg(&CreateAccount_return, pSocket, CreateAccount_return.Head.usSize);
		}

	}


	void CGMLogic::Handle_DeleteAccount( void* pPortMsg, snet::CSocket* pSocket )
	{
		UINT lPopedon = GetGmPopedom(FindAccount(pSocket));
		if ( lPopedon )
		{
			//return;
		}

		MSG_DELETE_ACCOUNTS *  msg_DeleteAccount;
		msg_DeleteAccount = (MSG_DELETE_ACCOUNTS*)pPortMsg;

		//判断帐号是否存在
		MSG_ZERO_ONE  DeleteAccount_return;
		DeleteAccount_return.Head.usSize    = sizeof(MSG_ZERO_ONE);
		DeleteAccount_return.Head.usType    = _MSG_DELETE_ACCOUNTS_RETURN;

		std::map<std::string ,USER_INFO>::iterator itor = m_UserListMap.find(msg_DeleteAccount->Accounts);
		if (itor != m_UserListMap.end())
		{
			m_UserListMap.erase(itor);

			FILE * fP;
			fP = fopen("./UserList.ini","wb");
			if (fP != NULL)
			{
				fwrite(NULL,0,0,fP);
				fclose(fP);
			}

			char name[32];
			char password[32];
			char popedom[64];
			char Count[16];

			memset(password,0L,sizeof(password));
			memset(name,0L,sizeof(name));
			memset(popedom,0L,sizeof(popedom));
			memset(Count,0L,sizeof(Count));

			const char* file = "./UserList.ini";
			int count = (int)m_UserListMap.size();
			sprintf(Count,"%d",count);
			WritePrivateProfileStringA("USER","COUNT",Count,file);
			count = atoi(Count);

			std::map<std::string ,USER_INFO>::iterator itor1 = m_UserListMap.begin();
			count = 0;
			for (;itor1 != m_UserListMap.end(); itor1++)
			{

				memset(password,0L,sizeof(password));
				memset(name,0L,sizeof(name));
				memset(popedom,0L,sizeof(popedom));
				memset(Count,0L,sizeof(Count));

				sprintf(Count,"USER%d",count);
				strcpy(name,(*itor1).first.c_str());
				strcpy(password,(*itor1).second.password);
				sprintf(popedom,"%d",(*itor1).second.popedom);

				WritePrivateProfileStringA(Count,"UserName",name,file);
				WritePrivateProfileStringA(Count,"UserPassword",password,file);
				WritePrivateProfileStringA(Count,"Popedom",popedom,file);

				count++;
			}

			//保存操作日志
			char cLogSave[1024];
			memset(cLogSave,0L,sizeof(cLogSave));
			sprintf(cLogSave,"操作员 %s: %s %s",FindAccount(pSocket),"delete account named:",msg_DeleteAccount->Accounts);
			sbase::GmLogSave(cLogSave);

			//发送返回信息
			DeleteAccount_return.ucInfo = 1; //1: 删除成功
			SendMsg(&DeleteAccount_return, pSocket, DeleteAccount_return.Head.usSize);


		}
		else
		{
			DeleteAccount_return.ucInfo = 0; //0: 帐号不存在，删除失败
			SendMsg(&DeleteAccount_return, pSocket, DeleteAccount_return.Head.usSize);
		}


	}

	void CGMLogic::Handle_PasswordChange( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_PASSWORD_CHANGE *  msg_PasswordChange;
		msg_PasswordChange = (MSG_PASSWORD_CHANGE*)pPortMsg;

		//判断帐号是否存在
		MSG_ZERO_ONE  PasswordChange_return;
		PasswordChange_return.Head.usSize    = sizeof(MSG_ZERO_ONE);
		PasswordChange_return.Head.usType    = _MSG_PASSWORD_CHANGE_RETURN;

		std::map<std::string ,USER_INFO>::iterator itor = m_UserListMap.find(msg_PasswordChange->cName);
		if (itor != m_UserListMap.end())
		{
			char Count[16];
			char Name[32];
			char PassWord[32];

			memset(Count,0L,sizeof(Count));
			memset(Name,0L,sizeof(Name));

			const char* file = "./UserList.ini";
			GetPrivateProfileStringA("USER","COUNT","",Count,sizeof(Count),file);
			int count = atoi(Count);
			memset(Count,0L,sizeof(Count));

			for (int i=0; i<count; i++)
			{
				sprintf(Count,"USER%d",i);
				GetPrivateProfileStringA(Count,"UserName","",Name,sizeof(Name),file);
				GetPrivateProfileStringA(Count,"UserPassword","",PassWord,sizeof(PassWord),file);

				if (strcmp(Name,msg_PasswordChange->cName) == 0 && strcmp(PassWord,msg_PasswordChange->cOldPassWord) == 0)
				{
					WritePrivateProfileStringA(Count,"UserPassword",msg_PasswordChange->cNewPassWord,file);

					InitUserList();

					PasswordChange_return.ucInfo = 1;
					SendMsg(&PasswordChange_return, pSocket, PasswordChange_return.Head.usSize);
					return;
				}
			}
			PasswordChange_return.ucInfo = 0;
			SendMsg(&PasswordChange_return, pSocket, PasswordChange_return.Head.usSize);

		}
		else
		{
			PasswordChange_return.ucInfo = 0;
			SendMsg(&PasswordChange_return, pSocket, PasswordChange_return.Head.usSize);
		}

	}




	void CGMLogic::Handle_AccountSearch( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_ACCOUNTS_SEARCH * msg_AccountSearch;
		msg_AccountSearch = (MSG_ACCOUNTS_SEARCH*)pPortMsg;

		int nInfoType = msg_AccountSearch->m_ucInfo_type;

		if ( 0 == nInfoType)
		{
			if (m_pDB)
			{
				CSession  *pSession = new CSession(pSocket, *this );
				if ( pSession != NULL )
				{
					pSession->OnDD_GetForbidSpeadTime_Request(  msg_AccountSearch->m_sPlayer_info,0);
				}
			}

			DB_GetPlayerInfo_Account( msg_AccountSearch->m_sPlayer_info ,pSocket);
		}
		else if ( 1 == nInfoType)
		{
			if (m_pDB)
			{
				CSession  *pSession = new CSession(pSocket, *this );
				if ( pSession != NULL )
				{
					pSession->OnDD_GetForbidSpeadTime_Request(  msg_AccountSearch->m_sPlayer_info,1);
				}
			}

			DB_GetPlayerInfo_Name(msg_AccountSearch->m_sPlayer_info, pSocket);
		}

	}


	void CGMLogic::Handle_Reposit( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_REPOSIT * msg_Reposit;
		msg_Reposit = (MSG_REPOSIT *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员 %s: %s %s",FindAccount(pSocket),"Reposit role named:",msg_Reposit->m_cPlayerName);
		sbase::GmLogSave(cLogSave);

		if (g_ConncetGS)
		{
			//向GS发送消息，把该玩家踢下线
			GM_MSG Msg;
			Msg.Head.usType =  KICK_PLAYER;
			Msg.Head.usSize = sizeof(GM_MSG);
			strcpy( Msg.cUser, msg_Reposit->m_cPlayerName );
			int SendLength = 0 ;
			m_pGMMgr->Write( (void *)&Msg, sizeof( GM_MSG ),SendLength );
			Sleep(1000);
		}

		//复位玩家， 写入数据库
		if (m_pDB)
		{
			CSession  *pSession = new CSession(pSocket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_Reposit_Write_Request( msg_Reposit->m_cPlayerName);
			}
		}

	}


	void CGMLogic::Handle_SendObject( void* pPortMsg, snet::CSocket* pSocket )
	{
		UINT lPopedon = GetGmPopedom(FindAccount(pSocket));
		if ( lPopedon )
		{
			//return;
		}

		MSG_SENDOBJECT * msg_SendObject;
		msg_SendObject = (MSG_SENDOBJECT *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员 %s: %s [%d,%d,%d,%d,%d,%d,%d,%d,%d,%d]",FindAccount(pSocket),"send object :",
			msg_SendObject->Base,msg_SendObject->Append[0],msg_SendObject->Append[1],msg_SendObject->Append[2],msg_SendObject->Append[3],msg_SendObject->Append[4],
			msg_SendObject->Binding,msg_SendObject->Overlap,msg_SendObject->BaseLV,msg_SendObject->AppendLv);
		sbase::GmLogSave(cLogSave);


		if (g_ConncetGS)
		{
			//向GS发送消息，把该玩家踢下线
			GM_MSG Msg;
			Msg.Head.usType =  KICK_PLAYER;
			Msg.Head.usSize = sizeof(GM_MSG);
			strcpy( Msg.cUser, msg_SendObject->m_sRole_name );
			int SendLength = 0 ;
			m_pGMMgr->Write( (void *)&Msg, sizeof( GM_MSG ),SendLength );
			Sleep(1000);
		}

		//发送物品，写入数据库
		if (m_pDB)
		{
			CSession  *pSession = new CSession(pSocket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_SendObject_Write_Request( msg_SendObject);
			}
		}


	}

	void CGMLogic::Handle_GetObjectInfo( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_OBJECT_INFO *msg_ObjectInfo;
		msg_ObjectInfo = (MSG_OBJECT_INFO *)pPortMsg;

		if (m_pDB)
		{
			CSession  *pSession = new CSession(pSocket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_GetObject_Request( msg_ObjectInfo->cName);
			}
		}
	}

	void CGMLogic::Handle_SetPlacard( void* pPortMsg, snet::CSocket* pSocket)
	{
		MSG_PLACARD * msg_Placard;
		msg_Placard = (MSG_PLACARD *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员 %s: %s %s",FindAccount(pSocket),"Set Placard:",msg_Placard->m_sPlacardInfo);
		sbase::GmLogSave(cLogSave);

		if (msg_Placard->m_ucPlacardType == 0) //即时公告
		{
			sprintf(msg_Placard->m_sBeginTime,"%s","2008-08-08 08:08:08");
			sprintf(msg_Placard->m_sEndTime,"%s","2008-08-08 08:08:08");
			msg_Placard->m_uInterval = 0;
		}
		//写入数据库
		if (m_pDB)
		{
			CSession  *pSession = new CSession(pSocket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_Placard_Request( msg_Placard );
			}
		}

		Sleep(2000);
		if ( g_ConncetGS )
		{
			//转发msg_Placard消息给GS服务器
			GM_MSG Msg;
			Msg.Head.usType =  SYS_PLACARD;
			Msg.Head.usSize = sizeof(GM_MSG);
			int SendLength = 0 ;
			m_pGMMgr->Write( (void *)&Msg, sizeof( GM_MSG ),SendLength );
		}	

		//设置公告后给所有玩家发送公告列表
		std::map<void*,std::string>::iterator  itor = m_AccountsMap.begin();
		for (;itor != m_AccountsMap.end();itor++)
		{
			if (m_pDB)
			{
				CSession  *pSession = new CSession(itor->first, *this );
				if ( pSession != NULL )
				{
					pSession->OnDB_PlacardList_Request( );
				}
			}
		}
		
	}

	void CGMLogic::Handle_DelPlacard( void* pPortMsg, snet::CSocket* pSocket  )
	{
		MSG_PLACARD_DEL * msg_PlacardDel;
		msg_PlacardDel = (MSG_PLACARD_DEL *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员 %s: %s %d",FindAccount( pSocket ),"Del Placard:",msg_PlacardDel->m_uiPlacardID);
		sbase::GmLogSave(cLogSave);

		//写入数据库
		if (m_pDB)
		{
			CSession  *pSession = new CSession(pSocket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_Del_Placard_Request( msg_PlacardDel->m_uiPlacardID );
			}
		}

		Sleep(2000);
		if ( g_ConncetGS )
		{
			//转发msg_Placard消息给GS服务器
			GM_MSG Msg;
			Msg.Head.usType =  SYS_PLACARD;
			Msg.Head.usSize = sizeof(GM_MSG);
			int SendLength = 0 ;
			m_pGMMgr->Write( (void *)&Msg, sizeof( GM_MSG ),SendLength );
		}
		
		//设置公告后给所有玩家发送公告列表
		std::map<void*,std::string>::iterator  itor = m_AccountsMap.begin();
		for (;itor != m_AccountsMap.end();itor++)
		{
			if (m_pDB)
			{
				CSession  *pSession = new CSession(itor->first, *this );
				if ( pSession != NULL )
				{
					pSession->OnDB_PlacardList_Request( );
				}
			}
		}

	}


	void CGMLogic::Handle_SetKickPunish( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_KICKROLE * msg_KickRole;
		msg_KickRole = (MSG_KICKROLE *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员 %s: %s %s",FindAccount(pSocket),"kick role named:",msg_KickRole->m_role_name);
		sbase::GmLogSave(cLogSave);

		//转发消息给GS服务器
		if (g_ConncetGS)
		{
			GM_MSG Msg;
			Msg.Head.usType =  KICK_PLAYER;
			Msg.Head.usSize = sizeof(GM_MSG);
			strcpy( Msg.cUser, msg_KickRole->m_role_name );
			int SendLength = 0 ;
			m_pGMMgr->Write( (void *)&Msg, sizeof( GM_MSG ),SendLength );
		}
		
	}

	void CGMLogic::Handle_SetSpeakPunish( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_FORBID_SPEAK * msg_ForbidSpeak;
		msg_ForbidSpeak = (MSG_FORBID_SPEAK *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员 %s: %s %s",FindAccount(pSocket),"forbid role speak named:",msg_ForbidSpeak->m_role_name);
		sbase::GmLogSave(cLogSave);
		
		//写入数据库
		if (m_pDB)
		{
			CSession  *pSession = new CSession(pSocket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_ForbidSpead_Request( msg_ForbidSpeak->m_role_name,msg_ForbidSpeak->cGMAccounts,msg_ForbidSpeak->m_uiTimeDefer);
			}
		}
		Sleep(1000);
		//转发消息给GS服务器
		if (g_ConncetGS)
		{
			GM_MSG Msg;
			Msg.Head.usType =  BAN_SPEAK;
			Msg.Head.usSize = sizeof(GM_MSG);
			strcpy( Msg.cUser, msg_ForbidSpeak->m_role_name );
			Msg.IntervalTime = msg_ForbidSpeak->m_uiTimeDefer;
			int SendLength = 0 ;
			m_pGMMgr->Write( (void *)&Msg, sizeof( GM_MSG ),SendLength );
		}


	}

	void CGMLogic::Handle_SetLandPunish( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_FORBID_LAND * msg_ForbidLand;
		msg_ForbidLand = (MSG_FORBID_LAND *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员 %s: %s %s",FindAccount(pSocket),"forbid role land named:",msg_ForbidLand->m_sPlayer_info);
		sbase::GmLogSave(cLogSave);

		//写数据库
		switch( msg_ForbidLand->m_ucInfo_type)
		{
		case 0:
			{
				if (m_pDB)
				{
					CSession  *pSession = new CSession(pSocket, *this );
					if ( pSession != NULL )
					{
						pSession->OnDB_ForbidAccounts_Request( msg_ForbidLand->m_sPlayer_info,msg_ForbidLand->m_sBeginTime,msg_ForbidLand->m_sEndTime,msg_ForbidLand->cGMAccounts,msg_ForbidLand->reason);
					}
				}
			}
			break;
		case 1:
			{
				if (m_pDB)
				{
					CSession  *pSession = new CSession(pSocket, *this );
					if ( pSession != NULL )
					{
						pSession->OnDB_ForbidIp_Request( msg_ForbidLand->m_sPlayer_info,msg_ForbidLand->m_sBeginTime,msg_ForbidLand->m_sEndTime,msg_ForbidLand->cGMAccounts,msg_ForbidLand->reason);
					}
				}

			}
			break;
		default:
			break;
		}

		Sleep(1000);
		if (g_ConncetGS)
		{
			GM_MSG Msg;
			Msg.Head.usType =  KICK_PLAYER;
			Msg.Head.usSize = sizeof(GM_MSG);
			strcpy( Msg.cUser, msg_ForbidLand->m_sPlayer_info );
			int SendLength = 0 ;
			m_pGMMgr->Write( (void *)&Msg, sizeof(GM_MSG),SendLength );
		}


		//设置禁止登陆后，及时向所有的客户端广播消息
		std::map<void*,std::string>::iterator  itor = m_AccountsMap.begin();
		if ( 0 == msg_ForbidLand->m_ucInfo_type )
		{
			for (;itor != m_AccountsMap.end();itor++)
			{
				if (m_pDB)
				{
					CSession  *pSession = new CSession(itor->first, *this );
					if ( pSession != NULL )
					{
						pSession->OnDB_ForbidAccountsList_Request( );
					}
				}
			}
			
		}
		else if ( 1 == msg_ForbidLand->m_ucInfo_type )
		{
			for (;itor != m_AccountsMap.end();itor++)
			{
				if (m_pDB)
				{
					CSession  *pSession = new CSession(itor->first, *this );
					if ( pSession != NULL )
					{
						pSession->OnDB_ForbidIpList_Request( );
					}
				}
			}
		}

	}
	void CGMLogic::Handle_DelLandPunish( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_FORBID_DEL * msg_forbid_del;
		msg_forbid_del = (MSG_FORBID_DEL *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员 %s: %s %s",FindAccount(pSocket),"del forbid role land named:",msg_forbid_del->m_sPlayer_info);
		sbase::GmLogSave(cLogSave);

		//执行存储过程  删除数据库中的记录
		if (m_pDB)
		{
			CSession  *pSession = new CSession(pSocket, *this );
			if ( pSession != NULL )
			{
				pSession->OnDB_Del_Forbid_Request( msg_forbid_del->m_sPlayer_info,msg_forbid_del->m_ucInfo_type);
			}
		}

		Sleep(1000);
		//设置禁止登陆后，及时向所有的客户端广播消息
		std::map<void*,std::string>::iterator  itor = m_AccountsMap.begin();
		if ( 0 == msg_forbid_del->m_ucInfo_type )
		{
			for (;itor != m_AccountsMap.end();itor++)
			{
				if (m_pDB)
				{
					CSession  *pSession = new CSession(itor->first, *this );
					if ( pSession != NULL )
					{
						pSession->OnDB_ForbidAccountsList_Request( );
					}
				}
			}

		}
		else if ( 1 == msg_forbid_del->m_ucInfo_type )
		{
			for (;itor != m_AccountsMap.end();itor++)
			{
				if (m_pDB)
				{
					CSession  *pSession = new CSession(itor->first, *this );
					if ( pSession != NULL )
					{
						pSession->OnDB_ForbidIpList_Request( );
					}
				}
			}
		}
	}



	void CGMLogic::Handle_Talk( void* pPortMsg, snet::CSocket* pSocket )
	{
		//转发消息给GM
		//或者直接发送给GS（目前与GS的通信只有单向性）

		MSG_TALK * msg_Talk;
		msg_Talk = (MSG_TALK *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		sprintf(cLogSave,"操作员:%s 对 %s 说: %s",FindAccount(pSocket),msg_Talk->RoleName, msg_Talk->wcContent);
		sbase::GmLogSave(cLogSave);

		if (msg_Talk->ucType == 0)//GM聊天
		{
			char cRoleName[32];
			void * socket;
			memset(cRoleName,0L,sizeof(cRoleName));
			strcpy(cRoleName,msg_Talk->RoleName);

			strcpy(msg_Talk->RoleName,FindAccount(pSocket));
			socket = FindSocket( cRoleName);
			if ( socket )
			{
				SendMsg(msg_Talk, socket, msg_Talk->Head.usSize);
			}
			else
			{
				//MSG_ERROR msg_error;
				//msg_error.Head.usSize    = sizeof(MSG_ERROR);
				//msg_error.Head.usType    = _MSG_ERROR;
				//sprintf(msg_error.Error,"%s  不在线",FindAccount(pSocket));
				//SendMsg( &msg_error,pPortMsg);
				//SendErrorInfo(_MSG_GOLD_BOX,ErrorId,pPlayer->GetSocket());
			}
		}
		else if ( msg_Talk->ucType == 1 )
		{
			//转发给GS
		}

	}
	void CGMLogic::Handle_ForbidLand_List( void* pPortMsg, snet::CSocket* pSocket )
	{
		MSG_LIST_REQUEST *msg_ForbidLandList;
		msg_ForbidLandList = (MSG_LIST_REQUEST *)pPortMsg;

		if ( 0 == msg_ForbidLandList->ucType )
		{
			if (m_pDB)
			{
				CSession  *pSession = new CSession(pSocket, *this );
				if ( pSession != NULL )
				{
					pSession->OnDB_ForbidAccountsList_Request( );
				}
			}
		}
		else if ( 1 == msg_ForbidLandList->ucType )
		{
			if (m_pDB)
			{
				CSession  *pSession = new CSession(pSocket, *this );
				if ( pSession != NULL )
				{
					pSession->OnDB_ForbidIpList_Request( );
				}
			}
		}
		else if( 3 == msg_ForbidLandList->ucType)
		{
			if (m_pDB)
			{
				CSession  *pSession = new CSession(pSocket, *this );
				if ( pSession != NULL )
				{
					pSession->OnDB_PlacardList_Request( );
				}
			}

		}

	}
	void CGMLogic::Handle_Server_ShutDown( void* pPortMsg, snet::CSocket* pSocket  )
	{
		MSG_MAINTENANCE * msg_maintenance;
		msg_maintenance = (MSG_MAINTENANCE *)pPortMsg;

		//保存操作日志
		char cLogSave[1024];
		memset(cLogSave,0L,sizeof(cLogSave));
		if (msg_maintenance->ucType == 0)
		{
			sprintf(cLogSave,"操作员:%s 获取服务器关闭的时间",FindAccount(pSocket));
		}
		else
		{
			sprintf(cLogSave,"操作员:%s 设置服务器的关闭时间 %s",FindAccount(pSocket),msg_maintenance->m_sTime);
		}
		sbase::GmLogSave(cLogSave);

		////////计算时间////////////////////
		int year,month,day,hour,minute,second;
		struct tm *t;
		time_t currenttime = time(NULL);
		t = localtime(&currenttime);

		sscanf(msg_maintenance->m_sTime,"%d-%d-%d %d:%d:%d",&year,&month,&day,&hour,&minute,&second);
		time_t StartTime = ( day - t->tm_mday )*86400 + ( hour - t->tm_hour )*3600 + ( minute - t->tm_min )*60 + ( second - t->tm_sec );
		////////计算时间////////////////////


		if ( msg_maintenance->ucType == 0 )
		{
			//获取关服务器设置
			MSG_MAINTENANCE_RETURN msg;
			msg.Head.usSize    = sizeof(MSG_MAINTENANCE_RETURN);
			msg.Head.usType    = _MSG_MAINTENANCE_RETURN;
			strcpy(msg.m_sTime,m_LastServerTime);
			SendMsg(&msg, pSocket, msg.Head.usSize);

		}
		else if ( msg_maintenance->ucType == 1)
		{
			if ( StartTime < 0 )
			{
				return;
			}

			strcpy( m_LastServerTime , msg_maintenance->m_sTime);

			GM_MSG Msg;
			Msg.Head.usType =  SYS_SHUTDOWN;
			Msg.Head.usSize = sizeof(GM_MSG);
			sprintf(Msg.data,"%s",msg_maintenance->m_sTime);
			int SendLength = 0 ;
			m_pGMMgr->Write( (void *)&Msg, sizeof( GM_MSG ),SendLength );


			//服务器设置完后的消息返回
			MSG_MAINTENANCE_RETURN msg;
			msg.Head.usSize    = sizeof(MSG_MAINTENANCE_RETURN);
			msg.Head.usType    = _MSG_MAINTENANCE_RETURN;
			strcpy(msg.m_sTime,m_LastServerTime);
			SendMsg(&msg, pSocket, msg.Head.usSize);
		}

		
	}

	void CGMLogic::NewSocketProc( snet::CSocket *pSocket )
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
						ReslovePacket(pszBuff, pSocket);
					}
					break;

				default:
					break;
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

	void CGMLogic::OnRead()
	{
		snet::CSocket* pSocket  = NULL;
		MsgHead* pszBuff = NULL;
		sbase::CSingleLock xLock(&m_xLock);

		SESSION_MAP::iterator itor = m_AccountsMap.begin();
		while (itor != m_AccountsMap.end())
		{
			pSocket = static_cast<snet::CSocket*>(itor->first);

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
				ClearAccount(itor->first);
				break;

			} // end if_else
			itor++;
		} // end while
		
	}

	void CGMLogic::OnWrite()
	{
		snet::CSocket* pSocket = NULL;
		sbase::CSingleLock xLock(&m_xLock);

		SESSION_MAP::iterator itor = m_AccountsMap.begin();
		while (itor != m_AccountsMap.end())
		{

			pSocket = static_cast<snet::CSocket*>(itor->first);

			if (pSocket->IsValid())
			{
				pSocket->Write();

			} 
			else
			{
				//客户端关闭				
				pSocket->GetIOCP()->PushNewClose(pSocket);
				ClearAccount(itor->first);
				break;

			} // end if_else
			itor++;
		} // end while

	}

	void CGMLogic::ReslovePacket( void * pPacket, snet::CSocket *pSocket )
	{
		USHORT temp=0;
		static const  MsgHandle* NetEventHandle = GetSocHandleTab( temp );

		MsgHead* pHead =	(MsgHead*)pPacket;

		(this->*NetEventHandle[GetIndex(pHead->usType)].pfun)( pPacket, pSocket );

	}


}
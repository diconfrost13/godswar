//========================================================
//
//    Copyright (c) 2006,�������߹�����
//    All rights reserved.
//
//    �ļ����� �� GMLogic.h
//    ժ    Ҫ �� ��½�������߼�
//    
//    ��ǰ�汾 �� 1.01
//    ��    �� �� ����
//    ������� �� 2007-01-08
//
//========================================================
#ifndef INC_GMLOGIC_H
#define INC_GMLOGIC_H

#ifdef _WIN32
#pragma once
#endif

#include <algorithm>
#include "..\..\Common/Include/Base\inc\Thread.h"
#include "..\..\Common/Include/DB\Inc\IDB.h"
#include "MsgDefine.h"

#include "../../Common/Include/sNet/IOCP.h"
//#include "../../Lib_Net(Server)/IOCP.h"
#include "..\..\Common/Include\Pipe\IPipe.h"

extern bool g_ConncetGS;
#define  MAX_ACCOUNT_SIZE 16
#define  SERVER_VERSION   1000001 
class CSession;

namespace snet
{
	class CSocket;
}


namespace login
{
	class CGMLogic;
	typedef void(CGMLogic::*pHandleFunc)(void*, snet::CSocket* );
	typedef ipc_np::CPipe* (*CreatePipeClient)(const char *,const char* , const char* , const char* );

	typedef std::map<void*,std::string>	SESSION_MAP;
#pragma pack(push)
#pragma pack(4)
	struct MsgHandle
	{    
		int  MSG_ID;
		pHandleFunc pfun;
	};
#pragma pack(pop)


	struct USER_INFO 
	{
		char		password[32];
		UINT	    popedom;

	};

	class  CGMLogic :public sbase::IThreadEvent
	{
		enum GM_MSG_TYPE { TYPE_NONE, KICK_PLAYER, BAN_SPEAK, SYS_PLACARD, SYS_SHUTDOWN, PLAYER_BAN };
		struct GM_MSG
		{
			MsgHead Head;
			char  cUser[32];
			char  data[255];
			UINT  IntervalTime;
		};

		static char  ValidateCode[25] ;
		friend class CSession;
	public:
		CGMLogic();
		~CGMLogic();
		bool Run();
		void	SendMsg(void* buf, void * pSocket, int nLen) const;
		//����У����
		char* CreateValidateCode( );
		const MsgHandle*        GetSocHandleTab( USHORT &Size ) const;
		int                     GetIndex( int MsgID );
		//��ȡ����ʼ���ܵ�
		bool GetPipeState() 
		{	if ( m_pGMMgr )
				return m_pGMMgr->GetStatus();
			return false;
		}
		bool InitPipe()
		{ 
			if ( m_pGMMgr )
				return m_pGMMgr->Init();
			return false;
		}

	protected:
		virtual    int		    OnThreadCreate	(void)	{ return 0; }
		virtual    int		    OnThreadDestroy	(void)	{ return 0; }
		virtual    int		    OnThreadEvent	(void)	{ return 0; }
		virtual    int		    OnThreadProcess	(void)	{ return Process(); }

	private:
		//�ر�Socket
		void                    CloseScoket(snet::CSocket *pSocket){ /*sbase::CSingleLock xLock1(&m_xLock);*/  };
		//��������������
		bool                    LoadNetService();
		//�������ݿ����
		bool                    LoadDBSercice();
		//����GS�ܵ�			
		bool                    ConnectGSPipe();
		//�߳�ִ����,�������Ϣ������ȡ������
		int                     Process();

		//����������
		void					NewSocketProc(snet::CSocket *pSocket);
		void					OnRead();
		void					OnWrite();
		//������Ϣ
		void					ReslovePacket(void * pPacket, snet::CSocket *pSocket);

		//�ж��ַ���Ч��
		bool                    JudgeValidStr( MSG_LOGIN* pMsgLogin, void *pSocket );
		//�жϿͻ���GM�Ƿ����ʺŵ�½
		bool CheckUser( const char * Name, const char* password,void* socket);
		//���ñ��ȡ����GM�ʺ�
		void InitUserList();
		//��������˺�
		void                    CacheAccounts( void * socket,std::string StrName )
		{
			m_AccountsMap[ socket ] = StrName;
		}
		const char * FindAccount( void * socket)
		{
			std::map<void*,std::string>::iterator  itor = m_AccountsMap.find( socket );
			if ( itor != m_AccountsMap.end() )
				return itor->second.c_str();

			return NULL;
		}
		void* FindSocket( const char * cGMname)
		{
			std::map<void*,std::string>::iterator  itor = m_AccountsMap.begin();
			for (;itor != m_AccountsMap.end();itor++)
			{
				if (strcmp(itor->second.c_str(),cGMname) ==0 )
				{
					return itor->first;
				}
			}
			return NULL;
		}
		void               ClearAccount( void * socket );

	private:
		HMODULE  m_hPipe;
		ipc_np::CPipe *		    m_pGMMgr;
		char m_szDBIp[32];
		char m_szUserName[16];
		char m_szUserPwd[16];
		char m_LastServerTime[32];
		
		sbase::CThread*	        m_pThread;
		dbtool::IDatabase*      m_pDB;
		long                    m_version;
		sbase::CCriticalSection	m_xLock;
		std::map<std::string,USER_INFO>  m_UserListMap;  //�û��ʺ������б�
		SESSION_MAP				m_AccountsMap;

		snet::CIOCP*			m_pSrvIocp;
	public:
		LONGLONG m_SpeakForbidTime;


	private:
		void                    Handle_Invalid( void* pPortMsg, snet::CSocket* pSocket );		//Ĭ����Ϣ����
		void					Handle_SocketClose( void* pPortMsg, snet::CSocket* pSocket );	//����ͻ���socket�رմ���
		void                    Handle_Login( void* pPortMsg, snet::CSocket* pSocket );			//��½
		void                    Handle_CreateAccount( void* pPortMsg, snet::CSocket* pSocket );	//�����ʺ�
		void                    Handle_DeleteAccount( void* pPortMsg, snet::CSocket* pSocket );	//ɾ���ʺ�
		void                    Handle_PasswordChange( void* pPortMsg, snet::CSocket* pSocket ); //��������
		void                    Handle_AccountSearch( void* pPortMsg, snet::CSocket* pSocket );	//��ѯ�����Ϣ
		void					Handle_Reposit( void* pPortMsg, snet::CSocket* pSocket );		//��λ���
		void					Handle_SendObject( void* pPortMsg, snet::CSocket* pSocket );		//����ҷ��ͽ�Ʒ
		void					Handle_GetObjectInfo( void* pPortMsg, snet::CSocket* pSocket );	//��ȡ��Ұ����ֿ�����װ����Ϣ
		void					Handle_SetPlacard( void* pPortMsg, snet::CSocket* pSocket );		//���ù���
		void					Handle_DelPlacard( void* pPortMsg, snet::CSocket* pSocket  );		//ɾ������
		void					Handle_SetKickPunish( void* pPortMsg, snet::CSocket* pSocket );	//����
		void					Handle_SetSpeakPunish( void* pPortMsg, snet::CSocket* pSocket );	//����
		void					Handle_SetLandPunish( void* pPortMsg, snet::CSocket* pSocket );	//��ֹ��½
		void					Handle_DelLandPunish( void* pPortMsg, snet::CSocket* pSocket );	//������ֹ��½
		void					Handle_Talk( void* pPortMsg, snet::CSocket* pSocket );			//����
		void					Handle_ForbidLand_List( void* pPortMsg, snet::CSocket* pSocket );//��ֹ��½�б�
		void					Handle_Server_ShutDown( void* pPortMsg, snet::CSocket* pSocket  ); //�������ر�����

	private:
		bool	DB_GetPlayerInfo_Account(const char* Account ,void* socket );
		bool	DB_GetPlayerInfo_Name(const char * Name, void*socket);
		UINT	GetGmPopedom( const char* Name);	//��ȡGM����Ȩ��
		void    SendOnlineGM( const char * name,void * socket);						//GM��½ʱ������������GM


	};
}


#endif
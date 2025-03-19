//========================================================
//
//    Copyright (c) 2006,欢乐连线工作室
//    All rights reserved.
//
//    文件名称 ： GMLogic.h
//    摘    要 ： 登陆服务器逻辑
//    
//    当前版本 ： 1.01
//    作    者 ： 李锋军
//    完成日期 ： 2007-01-08
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
		//产生校验码
		char* CreateValidateCode( );
		const MsgHandle*        GetSocHandleTab( USHORT &Size ) const;
		int                     GetIndex( int MsgID );
		//获取并初始化管道
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
		//关闭Socket
		void                    CloseScoket(snet::CSocket *pSocket){ /*sbase::CSingleLock xLock1(&m_xLock);*/  };
		//加载网络服务组件
		bool                    LoadNetService();
		//加载数据库服务
		bool                    LoadDBSercice();
		//连接GS管道			
		bool                    ConnectGSPipe();
		//线程执行体,负责从消息队列里取出数据
		int                     Process();

		//处理新连接
		void					NewSocketProc(snet::CSocket *pSocket);
		void					OnRead();
		void					OnWrite();
		//处理消息
		void					ReslovePacket(void * pPacket, snet::CSocket *pSocket);

		//判断字符有效性
		bool                    JudgeValidStr( MSG_LOGIN* pMsgLogin, void *pSocket );
		//判断客户端GM是否有帐号登陆
		bool CheckUser( const char * Name, const char* password,void* socket);
		//配置表读取所有GM帐号
		void InitUserList();
		//缓存玩家账号
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
		std::map<std::string,USER_INFO>  m_UserListMap;  //用户帐号密码列表
		SESSION_MAP				m_AccountsMap;

		snet::CIOCP*			m_pSrvIocp;
	public:
		LONGLONG m_SpeakForbidTime;


	private:
		void                    Handle_Invalid( void* pPortMsg, snet::CSocket* pSocket );		//默认消息处理
		void					Handle_SocketClose( void* pPortMsg, snet::CSocket* pSocket );	//捕获客户端socket关闭处理
		void                    Handle_Login( void* pPortMsg, snet::CSocket* pSocket );			//登陆
		void                    Handle_CreateAccount( void* pPortMsg, snet::CSocket* pSocket );	//创建帐号
		void                    Handle_DeleteAccount( void* pPortMsg, snet::CSocket* pSocket );	//删除帐号
		void                    Handle_PasswordChange( void* pPortMsg, snet::CSocket* pSocket ); //更换密码
		void                    Handle_AccountSearch( void* pPortMsg, snet::CSocket* pSocket );	//查询玩家信息
		void					Handle_Reposit( void* pPortMsg, snet::CSocket* pSocket );		//复位玩家
		void					Handle_SendObject( void* pPortMsg, snet::CSocket* pSocket );		//给玩家发送奖品
		void					Handle_GetObjectInfo( void* pPortMsg, snet::CSocket* pSocket );	//获取玩家包裹仓库身上装备信息
		void					Handle_SetPlacard( void* pPortMsg, snet::CSocket* pSocket );		//设置公告
		void					Handle_DelPlacard( void* pPortMsg, snet::CSocket* pSocket  );		//删除公告
		void					Handle_SetKickPunish( void* pPortMsg, snet::CSocket* pSocket );	//踢人
		void					Handle_SetSpeakPunish( void* pPortMsg, snet::CSocket* pSocket );	//禁言
		void					Handle_SetLandPunish( void* pPortMsg, snet::CSocket* pSocket );	//禁止登陆
		void					Handle_DelLandPunish( void* pPortMsg, snet::CSocket* pSocket );	//撤销禁止登陆
		void					Handle_Talk( void* pPortMsg, snet::CSocket* pSocket );			//聊天
		void					Handle_ForbidLand_List( void* pPortMsg, snet::CSocket* pSocket );//禁止登陆列表
		void					Handle_Server_ShutDown( void* pPortMsg, snet::CSocket* pSocket  ); //服务器关闭设置

	private:
		bool	DB_GetPlayerInfo_Account(const char* Account ,void* socket );
		bool	DB_GetPlayerInfo_Name(const char * Name, void*socket);
		UINT	GetGmPopedom( const char* Name);	//获取GM操作权限
		void    SendOnlineGM( const char * name,void * socket);						//GM登陆时发送所有在线GM


	};
}


#endif
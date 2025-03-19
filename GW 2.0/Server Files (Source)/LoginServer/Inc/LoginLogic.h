//========================================================
//
//    Copyright (c) 2006,欢乐连线工作室
//    All rights reserved.
//
//    文件名称 ： LoginLogic.h
//    摘    要 ： 登陆服务器逻辑
//    
//    当前版本 ： 1.01
//    作    者 ： 李锋军
//    完成日期 ： 2007-01-08
//
//========================================================
#ifndef INC_LOGIN_H
#define INC_LOGIN_H

#ifdef _WIN32
#pragma once
#endif

#include "stdafx.h"
#include <algorithm>
#include "..\..\Common/Include/Base\inc\Thread.h"
#include "..\..\Common/Include/DB\Inc\IDB.h"
#include "..\..\Common\MsgDefine.h"

#include "../../Common/Include/sNet/IOCP.h"

 
 #define  MAX_ACCOUNT_SIZE 16
 #define  SERVER_VERSION   1000001 
 class CSession;
 namespace snet
 {
 	 class CSocket;
 }


 namespace login
 {
 	class  CLogin :public sbase::IThreadEvent
 	{
 		static char  ValidateCode[25] ;
 		friend class CSession;

	public:
		typedef std::map<BYTE, MSG_GAMESERVER_INFO *>	GAMESERVER_ID;
		typedef std::map< snet::CSocket *, MSG_GAMESERVER_INFO *>	GAMESERVER_SOCKET;
		typedef std::map<std::string, CSession *> SESSION_MAP;

	public:
 		CLogin();
 		~CLogin();
 		bool	Run();
 		void	SendMsg(void* buf, void * pSocket, int nLen) const;
 		//产生校验码
 	    char*	CreateValidateCode( );
 		void	Release(){ delete this; }

		void	ShowServerList();

 
 	protected:
 		virtual    int		    OnThreadCreate	(void)	{ return 0; }
 		virtual    int		    OnThreadDestroy	(void)	{ return 0; }
 		virtual    int		    OnThreadEvent	(void)	{ return 0; }
 		virtual    int		    OnThreadProcess	(void)	{ return Process(); }
 
 	private:

 		//关闭Socket
 		void                    CloseScoket(snet::CSocket *pSocket){ sbase::CSingleLock xLock1(&m_xLock); };
 		//加载网络服务组件
 		bool                    LoadNetService();
 		//加载数据库服务
 		bool                    LoadDBSercice();
 		//线程执行体,负责从消息队列里取出数据
 		int                     Process();

		//处理新连接
		void					NewSocketProc(snet::CSocket *pSocket);
		void					OnRead();
		void					OnWrite();
		//处理消息
		void					ReslovePacket(const void * pPacket, snet::CSocket *pSocket);

		void					SessionProc();
		void					GSPacketProc();

 		//检查数据库
 		bool                    CheckDB( const char * Name,const char* password, void* socket ); 
 		//判断字符有效性
 		bool                    JudgeValidStr( MSG_LOGIN* pMsgLogin, void *pSocket );

 		//缓存玩家账号
 		void                    CacheAccounts( std::string StrName, CSession *pSession );
 		CSession *				FindAccount( std::string StrName );
 	    void					ClearAccount( std::string StrName );

 		void					Close();
 	private:
		HMODULE                 m_NetService ;
		SESSION_MAP				m_AccountsMap;

		snet::CIOCP*			m_pSrvIocp;
		sbase::CThread*	        m_pThread;
		dbtool::IDatabase*      m_pDB;
 		long                    m_version;
 		sbase::CCriticalSection	m_xLock;
 		
 		GAMESERVER_SOCKET		m_GameServerInfo;
 		GAMESERVER_ID		    m_GameServerMap;
 	};
 }

#endif
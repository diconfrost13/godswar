//========================================================
//
//    Copyright (c) 2008,欢乐连线工作室
//    All rights reserved.
//
//    文件名称 ： Socket.h
//    摘    要 ： 普通Socket通讯类头文件
//    
//    当前版本 ： 1.00
//    作    者 ： 李锋军
//    完成日期 ： 2008-05-01
//
//========================================================

#ifndef _FILE_SOCKET_H_
#define _FILE_SOCKET_H_

#include "stdafx.h"
#include "CirBuffer.h"

namespace snet
{
	class PerIOData;
	class CIOCP;
	class IEncryptor;

	class CSocket
	{
	public:
		CSocket( CIOCP* pIOCP );
		~CSocket();
         
		//完成通知操作
		void OnRead( PerIOData* pPerIOData );
		void OnWrite();

		//对该socket投递操作
		int PostSend(PerIOData *Sendobj);
		int PostRecv(PerIOData *Recvobj);

		//服务器投递发送请求
		bool Write( void );
		//游戏逻辑向缓冲区中写数据
		bool PackMsg( char *pMsg, size_t iLen );

		//从缓冲区中读出已接受到的数据
		bool Read( char **Paket );
		//游戏逻辑处理完毕，移动缓冲区指针
		void Remove( size_t nLen ){ m_iBuffer.Remove( nLen ); };

		bool IsValid(){ return m_Sock != INVALID_SOCKET && !m_BClosing; };
		void Refresh(); 
		void Initnalize( SOCKET Sock,int Af );
		void Finalize();
		void Release(){ delete this;};

		void*  operator new	(size_t size);
		void   operator delete(void* p);

		size_t GetL(){ return m_oBuffer.GetLength();}

		snet::CIOCP* GetIOCP(){return m_pIOCP;}

		void SetPeerInfo(SOCKADDR *sa, int salen);
		const char*	GetPeerIP();

		size_t GetiSpace(){ return m_iBuffer.Space();} 
	public:
		CIOCP*             m_pIOCP;
		SOCKET             m_Sock;              
		int                m_Af;     
		volatile int       m_BClosing;        
		volatile LONG      OutstandingRecv;
		volatile LONG      OutstandingSend;
		volatile LONG      PendingSend;
		CRITICAL_SECTION   SockCritSec; 
		SOCKADDR_IN		   m_addrRemote;
		CSocket			   *next;
	private:
		IEncryptor      *m_Encryptor;
		CircularBuffer  m_iBuffer;
		CircularBuffer  m_oBuffer;

		char			m_IP[NI_MAXHOST];
		char			m_PORT[NI_MAXSERV];
	};
}

#endif
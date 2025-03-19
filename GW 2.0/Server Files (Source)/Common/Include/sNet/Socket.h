//========================================================
//
//    Copyright (c) 2008,�������߹�����
//    All rights reserved.
//
//    �ļ����� �� Socket.h
//    ժ    Ҫ �� ��ͨSocketͨѶ��ͷ�ļ�
//    
//    ��ǰ�汾 �� 1.00
//    ��    �� �� ����
//    ������� �� 2008-05-01
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
         
		//���֪ͨ����
		void OnRead( PerIOData* pPerIOData );
		void OnWrite();

		//�Ը�socketͶ�ݲ���
		int PostSend(PerIOData *Sendobj);
		int PostRecv(PerIOData *Recvobj);

		//������Ͷ�ݷ�������
		bool Write( void );
		//��Ϸ�߼��򻺳�����д����
		bool PackMsg( char *pMsg, size_t iLen );

		//�ӻ������ж����ѽ��ܵ�������
		bool Read( char **Paket );
		//��Ϸ�߼�������ϣ��ƶ�������ָ��
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
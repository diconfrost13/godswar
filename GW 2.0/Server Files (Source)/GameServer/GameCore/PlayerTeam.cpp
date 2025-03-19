#include "stdafx.h"
#include "Player.h"
#include "..\ServiceLoader.h"

//////////////////////////////////////////////////////////////////////////
// 组队信息 by: David Lin
//////////////////////////////////////////////////////////////////////////
// 
// void CPlayer::LeaveTeam( long leave, int idx )
// {
// 	if( leave == 0 )
// 	{
// 		m_bIsLeader = false;
// 		m_pTeamLeader = NULL;
// 		m_pTeam[0] = NULL;
// 		m_pTeam[1] = NULL;
// 		m_pTeam[2] = NULL;
// 		m_pTeam[3] = NULL;
// 		m_pTeam[4] = NULL;
// 
// 		return;
// 	}
// 	else if( leave == 1 )
// 	{		
// 		CPlayer* player = m_pTeam[idx];
// 
// 		if ( idx == 0 ) 
// 		{
// 			// 队长离队，可以包含主动离开，或者队伍解散
// 			
// 			player->m_bIsLeader = false;
// 			player->m_pTeamLeader = NULL;
// 
// 			for ( int i = idx; i < 4; ++i )
// 			{
// 				m_pTeam[i]	 = m_pTeam[i+1];
// 				m_pTeam[i+1] = NULL;
// 			}
// 
// 			if ( m_pTeam[0] )
// 			{
// 				// 自动成为新队长
// 				m_pTeam[0]->m_bIsLeader = true;
// 				for( int i = 0; i < 5; i++ ) 
// 				{
// 					m_pTeam[0]->m_pTeam[i] = m_pTeam[i];
// 					if ( m_pTeam[0]->m_pTeam[i] )
// 						m_pTeam[0]->m_pTeam[i]->m_pTeamLeader	= m_pTeam[0];
// 				}
// 			}
// 		}
// 		else 
// 		{
// 			if( player )
// 			{
// 				player->m_bIsLeader = false;
// 				player->m_pTeamLeader = NULL;
// 				for ( int i = 0; i < 5; ++i ) 
// 				{
// 					// 恢复默认值
// 					player->m_pTeam[i] = NULL;
// 				}
// 			}
// 
// 			for ( int i = idx; i < 4; ++i )
// 			{
// 				m_pTeam[i]	 = m_pTeam[i+1];
// 				m_pTeam[i+1] = NULL;
// 			}
// 		}
// 
// 		MSG_TEAM msg;
// 
// 		msg.Head.usSize = sizeof( MSG_TEAM );
// 		msg.Head.usType = _MSG_TEAM_DELETE;
// 		msg.uiPlayerID1 = GetID();
// 		msg.uiPlayerID2 = player->GetID();
// 
// 		if ( m_pTeam[0] ) 
// 		{
// 			m_pTeam[0]->m_bIsLeader = true;
// 			m_pTeam[0]->m_pTeamLeader = m_pTeam[0];
// 		}
// 
// 		//player->LeaveTeam();
// 
// 		CGameObject::s_World->SendMsgToClient( &msg, player->GetSocket() );
// 
// 		return;
// 	}
// 	else if( leave == 2 )
// 	{
// 		// 自主离开队伍
// 		/*
// 		if( m_bIsLeader )
// 		{
// 
// 
// 		// 队长特殊处理，指派下一个队长
// 		if( m_pTeam[1] == NULL )
// 		assert( 0 );
// 		CPlayer* p = m_pTeam[1];
// 
// 		for( int i=0; i<4; i++ )
// 		{
// 		m_pTeam[i]->m_pTeamLeader = p;
// 		m_pTeam[i]->m_bIsLeader = false;
// 		p->m_pTeam[i] = m_pTeam[i+1];
// 		}
// 		m_pTeam[1]->m_bIsLeader = true;
// 
// 		}
// 		else
// 		{
// 		// 非队长，请求队长删除自己
// 		m_pTeamLeader->ClearMember( this );
// 		for( int i=0; i<4; i++ )
// 		{
// 		if( m_pTeamLeader->m_pTeam[i] == NULL )
// 		{
// 		m_pTeamLeader->m_pTeam[i] = m_pTeamLeader->m_pTeam[i+1];
// 		m_pTeamLeader->m_pTeam[i+1] = NULL;
// 		}
// 		}
// 		}
// 		*/
// 	}
// 	else if( leave == 3 )
// 	{
// 		// 队伍解散
// 	}
// 
// 
// }
// 
// 
// 
// //------------------------------------------------------------------------------------
// long CPlayer::CreateTeam( CPlayer* pPlayer )
// {
// 	if (!pPlayer)
// 		return -1;
// 
// 	// 检测自己做队长的必要条件
// 	if( m_bIsLeader )
// 		return -1;
// 	if( m_pTeamLeader != NULL )
// 		return -1;
// 
// 	// 检测对方是否能被邀请
// 	if( pPlayer->m_bIsLeader )
// 		return -2;
// 	if( pPlayer->m_pTeamLeader != NULL )
// 		return -2;
// 
// 
// 	m_bIsLeader = true;
// 	m_pTeamLeader = this;
// 	m_pTeam[0] = this;			// 队长位置
// 	//	m_pTeam[1] = pPlayer;		// 第一个队员
// 
// 	pPlayer->m_pTeamLeader = this;
// 
// 	return 0;
// }
// 
// //------------------------------------------------------------------------------------
// 
// 
// long CPlayer::AddMember( CPlayer* pPlayer )
// {
// 	if ( !pPlayer )
// 		return -1;
// 
// 	if( m_pTeamLeader == NULL )				// 没有队伍，则创建队伍
// 	{
// 		CreateTeam( pPlayer );
// 	}
// 
// 
// 	if( !m_bIsLeader )
// 		return -1;							// 非队长无权操作
// 
// 	MSG_TEAM_ADD	team;
// 
// 
// 	// 检查队友是否存在
// 	for ( int i = 0; i < 5; ++i ) 
// 	{
// 		if ( pPlayer == m_pTeam[i] )
// 			return 0;
// 	}
// 
// 	// 寻找空位并添加玩家进队列
// 	for ( int i=0; i<5; i++ )
// 	{
// 		if( m_pTeam[i] == NULL )
// 		{
// 			m_pTeam[i] = pPlayer;
// 			break;
// 		}
// 	}
// 
// 	for ( int i = 0; i < 5; ++i ) 
// 	{
// 		pPlayer->m_pTeam[i] = m_pTeam[i];
// 
// 		if ( m_pTeam[i] != NULL )
// 			team.uiTeamID[i] = m_pTeam[i]->GetID();
// 		else
// 			team.uiTeamID[i] = -1;
// 	}
// 
// 	pPlayer->m_pTeamLeader = this;
// 
// 	team.Head.usSize = sizeof( MSG_TEAM_ADD );
// 	team.Head.usType = _MSG_TEAM_ADD;
// 
// 	for ( int i = 0; i < 5; ++i )
// 	{
// 		if ( m_pTeam[i] != NULL ) 
// 		{
// 			team.uiPlayerID = m_pTeam[i]->GetID();
// 			CGameObject::s_World->SendMsgToClient( &team, m_pTeam[i]->GetSocket() );
// 		}
// 	}
// 
// 	return -2;
// }
// 
// //------------------------------------------------------------------------------------
// void CPlayer::InvitePlayer( CPlayer* pPlayer, void* pBuf  )
// {
// 	CGameObject::s_World->SendMsgToClient( pBuf, pPlayer->GetSocket() );
// }
// 
// //------------------------------------------------------------------------------------
// long CPlayer::RemoveMember( CPlayer* pPlayer )
// {
// 	if (!pPlayer)
// 		return -1;
// 
// 	if( !m_bIsLeader )
// 		return -1;							// 非队长无权操作
// 
// 	for ( int i=0; i<5; i++ )
// 	{
// 		if( m_pTeam[i] == pPlayer )
// 		{
// 				LeaveTeam( 1, i );		// 让目标用户活得被移除信息
// 		}
// 	}
// 
// 	MSG_TEAM_ADD	team;
// 
// 	// 客户端更新队友列表
// 	for ( int i = 0; i < 5; ++i ) 
// 	{
// 		if ( m_pTeam[i] != NULL )
// 			team.uiTeamID[i] = m_pTeam[i]->GetID();
// 		else
// 			team.uiTeamID[i] = -1;
// 	}
// 
// 	team.Head.usSize = sizeof( MSG_TEAM_ADD );
// 	team.Head.usType = _MSG_TEAM_ADD;
// 
// 	for ( int i = 0; i < 5; ++i )
// 	{
// 		if ( m_pTeam[i] != NULL ) {
// 			team.uiPlayerID = m_pTeam[i]->GetID();
// 			CGameObject::s_World->SendMsgToClient( &team, m_pTeam[i]->GetSocket() );
// 		}
// 	}
// 
// 	if ( m_pTeam[1] == NULL )
// 	{
// 		// 只剩一人,除伍解散
// 		if ( m_pTeam[0] != NULL ) 
// 		{
// 			m_pTeam[0]->m_bIsLeader = false;
// 			m_pTeam[0]->m_pTeamLeader = NULL;
// 		}
// 		m_pTeam[0]		= NULL;
// 		m_bIsLeader		= false;
// 		m_pTeamLeader	= NULL;
// 	}
// 
// 	return -2;
// }
// 
// //------------------------------------------------------------------------------------
// long CPlayer::ClearMember( void )
// {
// 	MSG_TEAM_ADD	team;
// 
// 	// 解散队伍
// 	for ( int i = 0; i < 5; ++i ) 
// 	{
// 		team.uiTeamID[i] = -1;
// 	}
// 
// 	team.Head.usSize = sizeof( MSG_TEAM_ADD );
// 	team.Head.usType = _MSG_TEAM_ADD;
// 
// 	// 客户端更新队友列表
// 	for ( int i = 0; i < 5; ++i )
// 	{
// 		if ( m_pTeam[i] != NULL ) 
// 		{
// 			team.uiPlayerID = m_pTeam[i]->GetID();
// 			m_pTeam[i]->m_pTeamLeader = NULL;
// 			m_pTeam[i]->m_bIsLeader = false;
// 			CGameObject::s_World->SendMsgToClient( &team, m_pTeam[i]->GetSocket() );
// 		}
// 	}
// 
// 	for ( int i = 0; i < 5; ++i )
// 	{
// 		m_pTeam[i] = NULL;
// 	}
// 
// 	m_bIsLeader = false;
// 	m_pTeamLeader = NULL;
// 
// 	return -1;
// }
// 
// //------------------------------------------------------------------------------------
// bool CPlayer::IsMember( CPlayer* pPlayer )
// {
// 	if (!pPlayer)
// 		return false;
// 
// 	for( int i=0; i<5; i++ )
// 	{
// 		if( pPlayer == m_pTeam[i] )
// 		{
// 			return true;
// 		}
// 	}
// 
// 	return false;
// }
// 
// //------------------------------------------------------------------------------------
// CPlayer* CPlayer::GetTeamObject( unsigned int nNumber )
// {
// 	if( nNumber > 4 )
// 		return NULL;
// 
// 	if( m_pTeamLeader == NULL )
// 		return NULL;
// 
// 	if( m_bIsLeader )
// 	{
// 		return m_pTeam[nNumber];
// 	}
// 	else
// 	{
// 		return m_pTeamLeader->m_pTeam[nNumber];
// 	}
// 
// 	return NULL;
// }
// 
// //------------------------------------------------------------------------------------
// long CPlayer::Consign( CPlayer* pPlayer )
// {
// 	if (!pPlayer)
// 		return -1;
// 
// 	if( !m_bIsLeader )
// 		return -1;							// 非队长无权操作
// 
// 	if( !IsMember( pPlayer ) )
// 		return -2;
// 
// 
// 	for( int i=0; i<5; i++ )
// 	{
// 		if( m_pTeam[i] == pPlayer )
// 		{
// 			m_pTeam[i] = m_pTeam[0];
// 			m_pTeam[0] = pPlayer;
// 			break;
// 		}
// 	}
// 
// 	m_pTeam[0] = pPlayer;
// 	m_bIsLeader = false;
// 	m_pTeamLeader = pPlayer;
// 	pPlayer->m_bIsLeader = true;
// 
// 	for ( int i = 0; i < 5; ++i )
// 	{
// 		pPlayer->m_pTeam[i] = m_pTeam[i];
// 	}
// 
// 	MSG_TEAM_ADD	team;
// 
// 	// 客户端更新队友列表
// 	for ( int i = 0; i < 5; ++i ) 
// 	{
// 		if ( m_pTeam[i] != NULL )
// 			team.uiTeamID[i] = m_pTeam[i]->GetID();
// 		else
// 			team.uiTeamID[i] = -1;
// 	}
// 
// 	team.Head.usSize = sizeof( MSG_TEAM_ADD );
// 	team.Head.usType = _MSG_TEAM_ADD;
// 
// 	for ( int i = 0; i < 5; ++i )
// 	{
// 		if ( m_pTeam[i] != NULL ) {
// 			team.uiPlayerID = m_pTeam[i]->GetID();
// 			CGameObject::s_World->SendMsgToClient( &team, m_pTeam[i]->GetSocket() );
// 		}
// 
// 		m_pTeam[i] = NULL;
// 	}
// 
// 	return 0;
// }
/////////////////////////被CD于 20071224 注释

//////////////////////////////////////////////////////////////////////////////////////////
//组队新   C.D
//////////////////////////////////////////////////////////////////////////////////////////

int		CPlayer::CreateTeam_New()
{
	//判断自己是不是已经在其他队伍中
	if (m_pTeamLeader != NULL)
	{
		return	-1;
	}
	else
	{
		m_pTeamLeader = this;

		//提示该玩家创建了一个队伍
		MSG_TIP msg_tip;
		msg_tip.Head.usSize = sizeof(MSG_TIP);
		msg_tip.Head.usType = _MSG_TEAM_TIP;
		wmemset( msg_tip.chName, 0 ,64);
		wmemset( msg_tip.tip, 0 ,128);
		std::wstring	buf = L"\0";
		std::wcsncpy( msg_tip.chName, buf.c_str(), buf.length());
		buf = L"你创建了一支队伍";
		
		std::wcsncpy(msg_tip.tip, buf.c_str(), buf.length());
		CGameObject::s_World->SendMsgToClient( &msg_tip, (this)->GetSocket() );
		m_Team_Timer.Clear();
		m_Team_Timer.Startup(1);
		//: )
		return	1;
	}
}

int		CPlayer::AddTeammate_New(CPlayer* _pPlayer)
{	
	if ( !_pPlayer )
	{
		//该玩家不存在
		return	-1;
	}

	//如果对方已经在其他队伍中，
	if ( _pPlayer->m_pTeamLeader != NULL )
	{
		//返回消息：对方已经有自己的队伍
		MSG_TIP msg_tip;
		msg_tip.Head.usSize = sizeof(MSG_TIP);
		msg_tip.Head.usType = _MSG_TEAM_TIP;
		wmemset( msg_tip.chName, 0 ,64);
		wmemset( msg_tip.tip, 0 ,128);
		WCHAR	wcBuf[64];
		wmemset( wcBuf, 0, 64);
		MultiByteToWideChar(CP_ACP, 0, _pPlayer->GetName(), -1, wcBuf, 64 );
		std::wstring buf = wcBuf;				
		std::wcsncpy(msg_tip.chName, buf.c_str(), buf.length() );
		buf = L"已经有自己的队伍";		
		std::wcsncpy(msg_tip.tip, buf.c_str(), buf.length());
		CGameObject::s_World->SendMsgToClient( &msg_tip, (this)->GetSocket() );
		//: )

		return	0;
	}

	//情况1：如果自己没有加入任何队伍，那么创建个新的队伍
	if (m_pTeamLeader == NULL)
	{
		CreateTeam_New();
		return	AddTeammate_New(_pPlayer);
	}

	//情况2：如果自己有队伍，是队长，并且队伍没有满员，则把对方加入队伍	
	if( this == m_pTeamLeader)
	{
		if(m_Teammates.size()<Max_TEAMMATES_NUM)
		{
			//告诉队长和队员，有人加入队伍
			MSG_TIP msg_tip;
			msg_tip.Head.usSize = sizeof(MSG_TIP);
			msg_tip.Head.usType = _MSG_TEAM_TIP;
			wmemset( msg_tip.chName, 0 ,64);
			wmemset( msg_tip.tip, 0 ,128);
			WCHAR	wcBuf[64];
			wmemset( wcBuf, 0, 64 );
			MultiByteToWideChar(CP_ACP, 0, _pPlayer->GetName(), -1, wcBuf, 64 );
			std::wstring buf = wcBuf;				
			std::wcsncpy( msg_tip.chName, buf.c_str(), buf.length());
			buf = L"加入了队伍";
			std::wcsncpy( msg_tip.tip, buf.c_str(), buf.length() );
			
			for ( vector<CPlayer*>::iterator iter = m_Teammates.begin();
					iter != m_Teammates.end();
						iter++)
			{
				CGameObject::s_World->SendMsgToClient( &msg_tip, (*iter)->GetSocket() );
			}
			CGameObject::s_World->SendMsgToClient( &msg_tip, (this)->GetSocket() );
			//: )
			_pPlayer->m_pTeamLeader = this;
			m_Teammates.push_back(_pPlayer);

			//告诉新队员
			wmemset( msg_tip.chName, 0 ,64);
			wmemset( msg_tip.tip, 0 ,128);
			buf = L"\0";
			std::wcsncpy( msg_tip.chName,buf.c_str(), buf.length() );
			buf = L"你已加入队伍";
			std::wcsncpy( msg_tip.tip, buf.c_str(), buf.length() );
			CGameObject::s_World->SendMsgToClient( &msg_tip, (_pPlayer)->GetSocket() );
			UpdateTeam_New(false);
		}
		else
		{
			//返回消息：您的队伍已满
			MSG_TIP msg_tip;
			msg_tip.Head.usSize = sizeof(MSG_TIP);
			msg_tip.Head.usType = _MSG_TEAM_TIP;
			wmemset( msg_tip.chName, 0 ,64);
			wmemset( msg_tip.tip, 0 ,128);
			std::wstring buf = L"\0";
			std::wcsncpy( msg_tip.chName, buf.c_str(), buf.length() );
			buf = L"队伍已满";
			std::wcsncpy(msg_tip.tip, buf.c_str(), buf.length());
			CGameObject::s_World->SendMsgToClient( &msg_tip, (this)->GetSocket() );
			//: )

			return	-1;
		}
	}
	else
	{
		//返回消息：您不是队长
		MSG_TIP msg_tip;
		msg_tip.Head.usSize = sizeof(MSG_TIP);
		msg_tip.Head.usType = _MSG_TEAM_TIP;
		wmemset( msg_tip.chName, 0 ,64);
		wmemset( msg_tip.tip, 0 ,128);
		std::wstring buf = L"\0";
		std::wcsncpy( msg_tip.chName, buf.c_str(), buf.length() );
		buf  = L"你不是队长，没有权限添加队员";
		std::wcsncpy( msg_tip.tip, buf.c_str(), buf.length() );
		CGameObject::s_World->SendMsgToClient( &msg_tip, (this)->GetSocket() );
		//: )

		return -1;
	}

	//其他
	return	0;
}

bool	CPlayer::IsTeammate_New(const CPlayer* _pPlayer)
{	
	if(!_pPlayer)
		return	false;
	//判断自己是否有队伍，是否是队长不影响队友判断
	if (m_pTeamLeader)
	{
		vector<CPlayer*>::iterator	iter;
		for (iter = m_pTeamLeader->m_Teammates.begin(); 
				iter != m_pTeamLeader->m_Teammates.end();
					iter++)
		{
			if ( _pPlayer == (*iter) )
			{
				return	true;
			}			
		}
	}

	return	false;
}

int		CPlayer::RemoveTeammate_New(CPlayer* _pPlayer)
{
	if(!_pPlayer)
		return	0;
	//判断自己是不是队长
	if (this == m_pTeamLeader )
	{
		//判断该玩家_pPlayer 是否在自己的队伍里
		vector<CPlayer*>::iterator	iter;

		if ( 1 == m_Teammates.size() )
		{
			iter = m_Teammates.begin();
			if ( (*iter) == _pPlayer )
			{
				ClearTeam_New();
				return	1;
			}
			
		}

		for ( iter = m_pTeamLeader->m_Teammates.begin(); 
				iter != m_pTeamLeader->m_Teammates.end();
					iter++	)
		{
			if ( _pPlayer == (*iter) )
			{
				//将该玩家移除，并修改其组队标志，告诉该玩家你已离开队伍
				(*iter)->m_pTeamLeader = NULL;

				MSG_TEAM_DESTROY	msg;
				msg.Head.usSize = sizeof(MSG_TEAM_DESTROY);
				msg.Head.usType = _MSG_TEAM_DESTROY;
				MSG_TIP msg_tip;
				msg_tip.Head.usSize = sizeof(MSG_TIP);
				msg_tip.Head.usType = _MSG_TEAM_TIP;
				wmemset( msg_tip.chName, 0 ,64);
				wmemset( msg_tip.tip, 0 ,128);
				std::wstring	buf = L"\0";
				std::wcsncpy(msg_tip.chName, buf.c_str(), buf.length() );
				buf = L"你已离开队伍";
				std::wcsncpy(msg_tip.tip, buf.c_str(), buf.length());

				CGameObject::s_World->SendMsgToClient( &msg, (*iter)->GetSocket() );
				CGameObject::s_World->SendMsgToClient( &msg_tip, (*iter)->GetSocket() );		

				m_pTeamLeader->m_Teammates.erase(iter);

				//告诉队长和所有队员
				WCHAR	wcBuf[64];
				MultiByteToWideChar(CP_ACP, 0, _pPlayer->GetName(), -1, wcBuf, 64 );
				buf = wcBuf;
				wmemset( msg_tip.chName, 0 ,64);
				wmemset( msg_tip.tip, 0 ,128);
				std::wcsncpy(msg_tip.chName, buf.c_str(), buf.length());
				buf = L"已离开队伍";
				std::wcsncpy(msg_tip.tip, buf.c_str(), buf.length());
				CGameObject::s_World->SendMsgToClient( &msg_tip, (this)->GetSocket() );	
				for (vector<CPlayer*>::iterator iter = m_Teammates.begin();
						iter != m_Teammates.end();
							iter++)
				{
					CGameObject::s_World->SendMsgToClient( &msg_tip, (*iter)->GetSocket() );	
				}

				//: )
				UpdateTeam_New(false);
				return	1;
			}
		}
	}
	
	return	0;
}

int		CPlayer::ClearTeam_New()
{
	if (this == m_pTeamLeader)
	{
		MSG_TEAM_DESTROY	msg;
		msg.Head.usSize = sizeof(MSG_TEAM_DESTROY);
		msg.Head.usType = _MSG_TEAM_DESTROY;

		MSG_TIP msg_tip;
		msg_tip.Head.usSize = sizeof(MSG_TIP);
		msg_tip.Head.usType = _MSG_TEAM_TIP;
		wmemset( msg_tip.chName, 0 ,64);
		wmemset( msg_tip.tip, 0 ,128);
		std::wstring buf = L"\0";
		std::wcsncpy(msg_tip.chName, buf.c_str(), buf.length());
		buf = L"队伍解散";
		std::wcsncpy(msg_tip.tip, buf.c_str(), buf.length());
		

		vector<CPlayer*>::iterator	iter;
		//清空所有队友关于队伍的信息，并告诉他们队伍解散
		for ( iter = m_pTeamLeader->m_Teammates.begin(); 
			iter != m_pTeamLeader->m_Teammates.end();
			iter++	)
		{
			(*iter)->m_pTeamLeader = NULL;			
			CGameObject::s_World->SendMsgToClient( &msg, (*iter)->GetSocket() );
			CGameObject::s_World->SendMsgToClient( &msg_tip, (*iter)->GetSocket() );
		}
		//清空自己的队伍信息，发送给自己，队伍解散
		this->m_pTeamLeader = NULL;
		this->m_Teammates.clear();
		CGameObject::s_World->SendMsgToClient( &msg, this->GetSocket() );
		CGameObject::s_World->SendMsgToClient( &msg_tip, (this)->GetSocket() );

	}
	return -1;
}
bool	CPlayer::ChangeLeader_New(CPlayer* _pPlayer)
{
	if (!_pPlayer)
		return	false;
	//判断自己是不是队长
	if (this == m_pTeamLeader )
	{
		//判断_pPlayer是否是本队队员
		if ( IsTeammate_New(_pPlayer) )
		{
			//重新整理本队队长队员信息
			vector<CPlayer*>::iterator	iter =  std::find( m_pTeamLeader->m_Teammates.begin(),m_pTeamLeader->m_Teammates.end(),_pPlayer );
			if (  iter != m_pTeamLeader->m_Teammates.end() )
			{
				this->m_Teammates.erase(iter);				
			}
			
			for ( iter = m_pTeamLeader->m_Teammates.begin(); 
					iter != m_pTeamLeader->m_Teammates.end();
						iter++ )
			{
				//将每个队员的队长信息更新
				//注意：这里把队长自己的leader指针置换成别人了,问题就在此,迭代器再次循环的时候已经是另外一个人的循环了,
				//改变的容器,出错的原因也就在此  2007-12-24 18：39  Fenjune Li
				//已改正
				(*iter)->m_pTeamLeader = _pPlayer;				
			}

			//交换队长权限			
			_pPlayer->m_pTeamLeader = _pPlayer;
			_pPlayer->m_Teammates = m_Teammates;
			this->m_Teammates.clear();
			this->m_pTeamLeader = _pPlayer;
			this->m_Team_Timer.Clear();

			_pPlayer->m_Teammates.push_back(this);
			_pPlayer->UpdateTeam_New(false);

			//通知所有队员变更
			MSG_TIP msg_tip;
			msg_tip.Head.usSize = sizeof(MSG_TIP);
			msg_tip.Head.usType = _MSG_TEAM_TIP;
			wmemset( msg_tip.chName, 0 ,64);
			wmemset( msg_tip.tip, 0 ,128);
			WCHAR	wcBuf[64];
			wmemset( wcBuf, 0, 64 );
			MultiByteToWideChar(CP_ACP, 0, _pPlayer->GetName(), -1, wcBuf, 64 );
			std::wstring buf = wcBuf;
			std::wcsncpy(msg_tip.chName, buf.c_str(), buf.length());
			buf = L"成为了队长";
			std::wcsncpy(msg_tip.tip, buf.c_str(), buf.length());
			for ( iter = _pPlayer->m_Teammates.begin(); 
					iter != _pPlayer->m_Teammates.end();
						iter++	)
			{				
				CGameObject::s_World->SendMsgToClient( &msg_tip, (*iter)->GetSocket() );
			}
			
			wmemset( msg_tip.chName, 0 ,64);
			wmemset( msg_tip.tip, 0 ,128);
			buf = L"\0";
			std::wcsncpy(msg_tip.chName, buf.c_str(), buf.length());
			buf = L"你已成为了队长";
			std::wcsncpy(msg_tip.tip, buf.c_str(), buf.length());
			CGameObject::s_World->SendMsgToClient( &msg_tip, (_pPlayer)->GetSocket() );
			(_pPlayer)->m_Team_Timer.Clear();
			(_pPlayer)->m_Team_Timer.Startup(0.5);


			return	true;
		}
	}

	return false;
}

bool	CPlayer::LeaveTeam_New()
{
	//判断自己是否有队伍
	if (m_pTeamLeader)
	{
		//判断自己在队伍中的身份
		if (this != m_pTeamLeader)
		{
			//如果自己不是队长，则通过自己队长的权限来删除自己
			m_pTeamLeader->RemoveTeammate_New(this);
			return true;
		}
		else
		{
			//如果自己是队长，则需要转交队长权限
			if( ChangeLeader_New(this->m_Teammates.at(0)) )
			{
				m_pTeamLeader->RemoveTeammate_New(this);
				return true;
			}
		}
	}
	return false;
}

int		CPlayer::UpdateTeam_New( bool _bIsDateUpdate )
{
	//判断队伍是否存在
	if (this == m_pTeamLeader)
	{
		//存在就至少包括队长和一名队员
		MSG_TEAM_REFLASH msg;

		msg.Head.usSize = sizeof( MSG_TEAM_REFLASH );
		msg.Head.usType = _MSG_TEAM_REFLASH;
		
		msg.lTeamLeaderID			= this->GetID();		
		msg.uiTeamLeader_HP			= this->GetlHP();
		msg.uiTeamLeader_MaxHP		= this->GetMaxHP();
		msg.uiTeamLeader_Lv			= this->GetRank();
		msg.ucTeamLeader_Class		= this->GetlClass();
		strcpy(msg.chTeamLeader_Name, this->GetName());
		//新增队友的地图和坐标 tavia
		msg.usTeamLeader_MapID = this->GetRegion()->GetID();
		msg.ufTeamLeader_X = this->GetPosX();
		msg.ufTeamLeader_Y = this->GetPosY();
		msg.ufTeamLeader_Z = this->GetPosZ();

		msg.lTeammate0_ID			= m_pTeamLeader->m_Teammates.at(0)->GetID();
		msg.uiTeammate0_HP			= m_pTeamLeader->m_Teammates.at(0)->GetlHP();
		msg.uiTeammate0_MaxHP		= m_pTeamLeader->m_Teammates.at(0)->GetMaxHP();
		msg.uiTeammate0_Lv			= m_pTeamLeader->m_Teammates.at(0)->GetRank();
		msg.ucTeammate0_Class		= m_pTeamLeader->m_Teammates.at(0)->GetlClass();
		strcpy( msg.chTeammate0_Name, m_pTeamLeader->m_Teammates.at(0)->GetName() );
		//新增队友的地图和坐标 tavia
		msg.usTeammate0_MapID = m_pTeamLeader->m_Teammates.at(0)->GetRegion()->GetID();
		msg.ufTeammate0_X = m_pTeamLeader->m_Teammates.at(0)->GetPosX();
		msg.ufTeammate0_Y = m_pTeamLeader->m_Teammates.at(0)->GetPosY();
		msg.ufTeammate0_Z = m_pTeamLeader->m_Teammates.at(0)->GetPosZ();
	
		//如果有两名以上队员
		if ( 2 <= m_Teammates.size() )
		{
			msg.lTeammate1_ID			= m_pTeamLeader->m_Teammates.at(1)->GetID();
			msg.uiTeammate1_HP			= m_pTeamLeader->m_Teammates.at(1)->GetlHP();
			msg.uiTeammate1_MaxHP		= m_pTeamLeader->m_Teammates.at(1)->GetMaxHP();
			msg.uiTeammate1_Lv			= m_pTeamLeader->m_Teammates.at(1)->GetRank();
			msg.ucTeammate1_Class		= m_pTeamLeader->m_Teammates.at(1)->GetlClass();
			strcpy( msg.chTeammate1_Name, m_pTeamLeader->m_Teammates.at(1)->GetName() );
			//新增队友的地图和坐标 tavia
			msg.usTeammate1_MapID = m_pTeamLeader->m_Teammates.at(1)->GetRegion()->GetID();
			msg.ufTeammate1_X = m_pTeamLeader->m_Teammates.at(1)->GetPosX();
			msg.ufTeammate1_Y = m_pTeamLeader->m_Teammates.at(1)->GetPosY();
			msg.ufTeammate1_Z = m_pTeamLeader->m_Teammates.at(1)->GetPosZ();

		}
		else
		{
			msg.lTeammate1_ID			= -1;
			msg.uiTeammate1_HP			= 0;
			msg.uiTeammate1_MaxHP		= 1;
			msg.uiTeammate1_Lv			= 0;
			msg.ucTeammate1_Class		= 0;
			memset(msg.chTeammate1_Name,0,64);
			//新增队友的地图和坐标 tavia
			msg.usTeammate1_MapID = -1;
			msg.ufTeammate1_X = 0;
			msg.ufTeammate1_Y = 0;
			msg.ufTeammate1_Z = 0;

		}

		//如果有三名以上队员
		if ( 3 <= m_Teammates.size() )
		{
			msg.lTeammate2_ID			= m_pTeamLeader->m_Teammates.at(2)->GetID();
			msg.uiTeammate2_HP			= m_pTeamLeader->m_Teammates.at(2)->GetlHP();
			msg.uiTeammate2_MaxHP		= m_pTeamLeader->m_Teammates.at(2)->GetMaxHP();
			msg.uiTeammate2_Lv			= m_pTeamLeader->m_Teammates.at(2)->GetRank();
			msg.ucTeammate2_Class		= m_pTeamLeader->m_Teammates.at(2)->GetlClass();
			strcpy( msg.chTeammate2_Name, m_pTeamLeader->m_Teammates.at(2)->GetName() );
			//新增队友的地图和坐标 tavia
			msg.usTeammate2_MapID = m_pTeamLeader->m_Teammates.at(2)->GetRegion()->GetID();
			msg.ufTeammate2_X = m_pTeamLeader->m_Teammates.at(2)->GetPosX();
			msg.ufTeammate2_Y = m_pTeamLeader->m_Teammates.at(2)->GetPosY();
			msg.ufTeammate2_Z = m_pTeamLeader->m_Teammates.at(2)->GetPosZ();

		}
		else
		{
			msg.lTeammate2_ID			= -1;
			msg.uiTeammate2_HP			= 0;
			msg.uiTeammate2_MaxHP		= 1;
			msg.uiTeammate2_Lv			= 0;
			msg.ucTeammate2_Class		= 0;
			memset(msg.chTeammate2_Name,0,64);
			//新增队友的地图和坐标 tavia
			msg.usTeammate2_MapID = -1;
			msg.ufTeammate2_X = 0;
			msg.ufTeammate2_Y = 0;
			msg.ufTeammate2_Z = 0;
	}

		//如果有4名队员
		if ( 4 <= m_Teammates.size() )
		{
			msg.lTeammate3_ID			= m_pTeamLeader->m_Teammates.at(3)->GetID();
			msg.uiTeammate3_HP			= m_pTeamLeader->m_Teammates.at(3)->GetlHP();
			msg.uiTeammate3_MaxHP		= m_pTeamLeader->m_Teammates.at(3)->GetMaxHP();
			msg.uiTeammate3_Lv			= m_pTeamLeader->m_Teammates.at(3)->GetRank();
			msg.ucTeammate3_Class		= m_pTeamLeader->m_Teammates.at(3)->GetlClass();
			strcpy( msg.chTeammate3_Name, m_pTeamLeader->m_Teammates.at(3)->GetName() );
			//新增队友的地图和坐标 tavia
			msg.usTeammate3_MapID = m_pTeamLeader->m_Teammates.at(3)->GetRegion()->GetID();
			msg.ufTeammate3_X = m_pTeamLeader->m_Teammates.at(3)->GetPosX();
			msg.ufTeammate3_Y = m_pTeamLeader->m_Teammates.at(3)->GetPosY();
			msg.ufTeammate3_Z = m_pTeamLeader->m_Teammates.at(3)->GetPosZ();
		}
		else
		{
			msg.lTeammate3_ID			= -1;
			msg.uiTeammate3_HP			= 0;
			msg.uiTeammate3_MaxHP		= 1;
			msg.uiTeammate3_Lv			= 0;
			msg.ucTeammate3_Class		= 0;
			memset(msg.chTeammate3_Name,0,64);
			//新增队友的地图和坐标 tavia
			msg.usTeammate3_MapID = -1;
			msg.ufTeammate3_X = 0;
			msg.ufTeammate3_Y = 0;
			msg.ufTeammate3_Z = 0;
		}

		msg.bIsDateUpdate = _bIsDateUpdate;

		CGameObject::s_World->SendMsgToClient( &msg, this->GetSocket() );
		vector<CPlayer*>::iterator	iter;
		for ( iter = m_Teammates.begin();
				iter != m_Teammates.end();
					iter++ )
		{
			CGameObject::s_World->SendMsgToClient( &msg, (*iter)->GetSocket() );
		}
	}



	return	1;
}
bool	CPlayer::InitTeam_New()
{
	if (m_pTeamLeader)
	{
		m_Teammates.clear();
		m_pTeamLeader = NULL;
		return	true;
	}
	return	false;
}

void	CPlayer::GetTeamState(int& _count, bool& _IfCouples)
{
	_IfCouples = false;
	_count	   = 0;
	if (m_pTeamLeader)
	{
		_count = m_pTeamLeader->m_Teammates.size();
		_count++;
		if (2 == _count)
		{
			if (m_pTeamLeader->GetGender() != m_pTeamLeader->m_Teammates.at(0)->GetGender())
			{
				_IfCouples = true;
				return;
			}
		}
	}

	return;	
}
////////////////////////////////
//组队新20071219
////////////////////////////////
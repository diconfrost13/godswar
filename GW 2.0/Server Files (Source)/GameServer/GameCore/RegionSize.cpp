//========================================================
//
//    Copyright (c) 2007,欢乐连线工作室
//    All rights reserved.
//
//    文件名称 ： RegionSize.cpp
//    摘    要 ： 场景管理模块(场景小区域操作)
//    
//    当前版本 ： 1.00
//    作    者 ： 林德辉
//    完成日期 ： 2007-01-12
//
//========================================================

#include "StdAfx.h"
#include "Region.h"
#include "GameObject.h"
#include "Player.h"
#include "NPC.h"
#include "Monster.h"


#include "..\ServiceLoader.h"


#include "..\..\Common\MsgDefine.h"
#include "..\..\Common\MsgTypes.h"

extern MSG_OBJECTINFO msg, msg2other;
extern MSG_LEAVE msg_leave;
extern MSG_WALK_BEGIN msg_walk_begin;
extern MSG_WALK_END msg_walk_end;


long CRegion::JoinRegionSizeOperate( int gx, int gy, CPlayer* pPlayer )
{
	if( gx < 0 || gx >= REGION_SIZE )
		return -1;
	if( gy < 0 || gy >= REGION_SIZE )
		return -1;

/*
	for( PlayerIterator it=m_Player[gx][gy].begin(); it!=m_Player[gx][gy].end(); it++ )
	{
		CPlayer* p = *it;

		// send join player to other
		pPlayer->s_World->SendMsgToClient( &msg, p->GetSocket() );

		// send other to player
		msg2other.uiID = p->GetID();
		msg2other.X = p->GetPosX();
		msg2other.Y = p->GetPosY();
		msg2other.Z = p->GetPosZ();
		msg2other.fAtan2 = p->GetAtan2();
		m_pWorld->SendMsgToClient( &msg2other, pPlayer->GetSocket() );

		// send walk message
		if( p->m_eState == OBJECT_RUN )		// 玩家移动
		{
			msg_walk.uiID = p->GetID();
			msg_walk.X = p->m_fDestinationX;
			msg_walk.Y = p->m_fDestinationY;
			msg_walk.Z = p->m_fDestinationZ;
			msg_walk.StartX = p->m_fX;
			msg_walk.StartY = p->m_fY;
			msg_walk.StartZ = p->m_fZ;
			m_pWorld->SendMsgToClient( &msg_walk, pPlayer->GetSocket() );
		}

	}
*/
	return 0;
}

long CRegion::WalkInRegionSizeOperate( int gx, int gy, CPlayer* pPlayer )
{
	if( gx < 0 || gx >= REGION_SIZE )
		return -1;
	if( gy < 0 || gy >= REGION_SIZE )
		return -1;

/*
	for( PlayerIterator it=m_Player[gx][gy].begin(); it!=m_Player[gx][gy].end(); it++ )
	{
		CPlayer* p = *it;

		// send join player to other
		m_pWorld->SendMsgToClient( &msg, p->GetSocket() );

		// send other to player
		msg2other.uiID = p->GetID();
		msg2other.X = p->GetPosX();
		msg2other.Y = p->GetPosY();
		msg2other.Z = p->GetPosZ();
		msg2other.fAtan2 = p->GetAtan2();
		m_pWorld->SendMsgToClient( &msg2other, pPlayer->GetSocket() );

		// send walk message
		if( p->m_eState == OBJECT_RUN )				// 其他玩家移动
		{
			msg_walk.uiID = p->GetID();
			msg_walk.X = p->m_fDestinationX;
			msg_walk.Y = p->m_fDestinationY;
			msg_walk.Z = p->m_fDestinationZ;
			msg_walk.StartX = p->m_fX;
			msg_walk.StartY = p->m_fY;
			msg_walk.StartZ = p->m_fZ;
			p->s_World->SendMsgToClient( &msg_walk, pPlayer->GetSocket() );
		}
		if( pPlayer->m_eState == OBJECT_RUN )		// 玩家移动
		{
			msg_walk.uiID = pPlayer->GetID();
			msg_walk.X = pPlayer->m_fDestinationX;
			msg_walk.Y = pPlayer->m_fDestinationY;
			msg_walk.Z = pPlayer->m_fDestinationZ;
			msg_walk.StartX = pPlayer->m_fX;
			msg_walk.StartY = pPlayer->m_fY;
			msg_walk.StartZ = pPlayer->m_fZ;
			pPlayer->s_World->SendMsgToClient( &msg_walk, p->GetSocket() );
		}

	}
*/

	return 0;
}


long CRegion::WalkOutRegionSizeOperate( int gx, int gy, CPlayer* pPlayer )
{
	if( gx < 0 || gx >= REGION_SIZE )
		return -1;
	if( gy < 0 || gy >= REGION_SIZE )
		return -1;

/*
	for( PlayerIterator it=m_Player[gx][gy].begin(); it!=m_Player[gx][gy].end(); it++ )
	{
		CPlayer* p = *it;

		// send leave player to other
		msg_leave.uiID = pPlayer->GetID();
		p->s_World->SendMsgToClient( &msg_leave, p->GetSocket() );
		msg_leave.uiID = p->GetID();
		p->s_World->SendMsgToClient( &msg_leave, pPlayer->GetSocket() );
	}
*/


	return 0;
}

long CRegion::WalkMsgRegionSizeOperate( int gx, int gy, CPlayer* )
{
	if( gx < 0 || gx >= REGION_SIZE )
		return -1;
	if( gy < 0 || gy >= REGION_SIZE )
		return -1;

/*
	for( PlayerIterator it=m_Player[gx][gy].begin(); it!=m_Player[gx][gy].end(); it++ )
	{
		CPlayer* p = *it;

		// send walk message to other
		p->s_World->SendMsgToClient( &msg_walk, p->GetSocket() );
	}
*/

	return 0;
}

long CRegion::WalkBeginMsgRegionSizeOperate( int gx, int gy, CPlayer*)
{
	if( gx < 0 || gx >= REGION_SIZE )
		return -1;
	if( gy < 0 || gy >= REGION_SIZE )
		return -1;

/*
	for( PlayerIterator it=m_Player[gx][gy].begin(); it!=m_Player[gx][gy].end(); it++ )
	{
		CPlayer* p = *it;

		// send walk message to other
		p->s_World->SendMsgToClient( &msg_walk_begin, p->GetSocket() );
	}
*/

	return 0;
}

long CRegion::WalkEndMsgRegionSizeOperate( int gx, int gy, CPlayer* )
{
	if( gx < 0 || gx >= REGION_SIZE )
		return -1;
	if( gy < 0 || gy >= REGION_SIZE )
		return -1;

/*
	for( PlayerIterator it=m_Player[gx][gy].begin(); it!=m_Player[gx][gy].end(); it++ )
	{
		CPlayer* p = *it;

		// send walk message to other
		p->s_World->SendMsgToClient( &msg_walk_end, p->GetSocket() );
	}
*/

	return 0;
}

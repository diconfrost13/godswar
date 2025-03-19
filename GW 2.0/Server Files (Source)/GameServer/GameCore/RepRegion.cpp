//========================================================
//
//    Copyright (c) 2006,�������߹�����
//    All rights reserved.
//
//    �ļ����� �� RepRegion.cpp
//    ժ    Ҫ �� ������������ģ��
//    
//    ��ǰ�汾 �� 1.00
//    ��    �� �� �ֵ»�
//    ������� �� 2007-01-17
//
//========================================================

#include "StdAfx.h"
#include "RepRegion.h"
#include "..\DataCore.h"
#include "Region.h"
#include "../World.h"

CRepRegion::CRepRegion()
{
	m_lID = 0;
	m_pRegion = NULL;
}

CRepRegion::~CRepRegion(void)
{
// 	for( int i=0; i<MAX_REP_REGION_NUMBER; i++ )
// 	{
// 		m_pRegion[i].Release();
// 	}
	SAFE_DELETE_ARRAY( m_pRegion );
}


long CRepRegion::Init( CWorld* pWorld )
{
	m_pRegion = new CRegion[MAX_REP_REGION_NUMBER];
	for( int i=0; i<MAX_REP_REGION_NUMBER; i++ )
	{
		m_pRegion[i].SetID( i+m_lID*MAX_REP_REGION_NUMBER+MAX_REGION );
//		printf( "[%d] ", i+m_lID*MAX_REP_REGION_NUMBER+MAX_REGION );
		m_pRegion[i].Init( m_pWorld );
		// load from ini
	}

	return 0;
}


long CRepRegion::AI( void )
{
	for( int i=0; i<MAX_REP_REGION_NUMBER; i++ )
	{
		m_pRegion[i].AI();
	}

	return 0;
}


long CRepRegion::GetOnline( void )
{
	long lCountOnline = 0;

	for( int i=0; i<MAX_REP_REGION_NUMBER; i++ )
	{
		lCountOnline += m_pRegion[i].GetOnline();
	}

	return lCountOnline;
}



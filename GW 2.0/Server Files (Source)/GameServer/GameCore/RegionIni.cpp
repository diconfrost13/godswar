#include "StdAfx.h"
#include "Region.h"
#include "GameObject.h"
#include "Player.h"
#include "NPC.h"
#include "Monster.h"
#include "..\DataCore.h"

#include "..\..\Common\MsgDefine.h"
#include "..\..\Common\MsgTypes.h"
#include "../World.h"

extern MSG_OBJECTINFO msg;
extern MSG_DEAD msg_dead;

long g_lMonsterCount = 10000;
long g_lNPCCount = 5000;

// 怪物base表
sbase::CIni iniMonsterObject( "./scene/MonsterObject.ini", false );		// 怪物属性表

bool CRegion::CreateMonsterFromIni( void )
{
	char buf[256];
	char path_monster[256], path_npc[256],path_convey[256];



	int foroutput = 0;
	int monsteroutput = 0;

	//////////////////////////////////////////////////////////////////////////
	// 怪物布局
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// 配置文件装载方法
	//////////////////////////////////////////////////////////////////////////


	memset( path_monster, 0, 256 );
	sprintf( path_monster, "./scene/%s/Monster.ini", m_strName.c_str() );
	sbase::CIni iniMonster( path_monster, false );							// 怪物位置布局表

	// 获取怪物布局
	int count = iniMonster.GetData( "default", "count" );
	foroutput += count;
	monsteroutput += count;


	for( int i=0; i<count; i++ )
	{
		memset( buf, 0, 256 );
		sprintf( buf, "Monster%03d", i );
		const char* pObjectName = iniMonster.GetString(buf,"Object");

		if( pObjectName != NULL )
		{
 			// 创造Monster
 			CMonster* pMonster = m_pWorld->GetMonster( g_lMonsterCount );
 			g_lMonsterCount++;
 			pMonster->m_pRegion = this;
 			pMonster->Activate();
 			pMonster->SetName( pObjectName );
 			pMonster->SetPos( iniMonster.GetFloatData(buf,"X"), 0.0f, iniMonster.GetFloatData(buf,"Z"), true );
 			pMonster->SetRefreshTime( iniMonster.GetData( buf, "RefreshTime" ) );
			pMonster->m_WalkTime = iniMonster.GetData( buf, "IntervalTime" );

			pMonster->m_fAngle                     =  iniMonster.GetData( buf, "Quaternion" );
 			pMonster->m_fIniX 					   =  pMonster->GetPosX();
 			pMonster->m_fIniZ 					   =  pMonster->GetPosZ();
 			pMonster->m_lMode 					   =  iniMonster.GetData( buf,"Mode" );
 			pMonster->m_Level 					   =  iniMonster.GetData( buf,"Level" );
 		    pMonster->SetcRank(  pMonster->m_Level );
			pMonster->m_Quality					   =  iniMonster.GetData( buf, "Quality");
			pMonster->m_MonsterEquiplv			   =  iniMonster.GetData( buf, "MonsterEquiplv");
			pMonster->m_ConfirmConfig.DropNum      =  iniMonster.GetData( buf, "ConfimDropNum"); 
		    pMonster->m_ConfirmConfig.DropProbability = iniMonster.GetData( buf, "ConfimProbability");
			strcpy(pMonster->m_ConfirmConfig.ItemTable,iniMonster.GetString( buf, "ConfimItemTable"));
 			pMonster->m_DropConfig.DropNum         =  iniMonster.GetData( buf,"DropNum" );
 			pMonster->m_DropConfig.DropProbability =  iniMonster.GetData( buf,"DropProbability" );
 			pMonster->m_DropConfig.Distribution    =  iniMonster.GetData( buf,"Distribution" );
  			pMonster->m_QuestID      = iniMonster.GetData(buf , "QuestID");
			pMonster->m_QuestItem[0] = iniMonster.GetData(buf , "QuestItem1");
			pMonster->m_QuestItem[1] = iniMonster.GetData(buf , "QuestItem2");
			pMonster->m_QuestItem[2] = iniMonster.GetData(buf , "QuestItem3");
			pMonster->m_QuestItem[3] = iniMonster.GetData(buf , "QuestItem4");
			pMonster->m_QuestItem[4] = iniMonster.GetData(buf , "QuestItem5");
			pMonster->m_QuestItem[5] = iniMonster.GetData(buf , "QuestItem6");
			pMonster->m_QuestItem[6] = iniMonster.GetData(buf , "QuestItem7");
			pMonster->m_QuestItem[7] = iniMonster.GetData(buf , "QuestItem8");


 			pMonster->SetlFaction(iniMonsterObject.GetFloatData( pObjectName, "Faction" ));											
 			pMonster->m_fActivityRange   = 	iniMonsterObject.GetFloatData( pObjectName, "ActivityRange" );	
 			pMonster->m_fEyeshot         = 	iniMonsterObject.GetFloatData( pObjectName, "Eyeshot" );		
 			pMonster->Param.Exp          = 	iniMonsterObject.GetFloatData( pObjectName, "Exp" );			
 			pMonster->Param.HP           = 	iniMonsterObject.GetFloatData( pObjectName, "HP" );				
			pMonster->Param.HPResume     = 	iniMonsterObject.GetFloatData( pObjectName, "HPResume" );	
 			pMonster->Param.PhyDefend    = 	iniMonsterObject.GetFloatData( pObjectName, "PhyDefence" );		
 			pMonster->Param.MagicDefend  = 	iniMonsterObject.GetFloatData( pObjectName, "MagicDefence" );	
			pMonster->Param.Hit          = 	iniMonsterObject.GetFloatData( pObjectName, "Hit" );
 			pMonster->Param.Miss         = 	iniMonsterObject.GetFloatData( pObjectName, "Miss" );		
			pMonster->Param.FrenzyHit    =  iniMonsterObject.GetFloatData( pObjectName, "CruelHit" );
			pMonster->Param.FrenzyMiss   =  iniMonsterObject.GetFloatData( pObjectName, "CruelMiss" );
			pMonster->Param.PhyDamage    =  iniMonsterObject.GetFloatData( pObjectName, "PhysicsDamage" );
			pMonster->Param.MagicDamage  =  iniMonsterObject.GetFloatData( pObjectName, "MagicDamage" );
			pMonster->Param.DamageSorb   =  iniMonsterObject.GetFloatData( pObjectName, "DamageSorb" );
			pMonster->Param.StatusHit    =  iniMonsterObject.GetFloatData( pObjectName, "StatusHit" );
			pMonster->Param.statusMiss   =  iniMonsterObject.GetFloatData( pObjectName, "StatusMiss" );
 			pMonster->m_SkillInfos[0].SkillID  = (int)iniMonsterObject.GetFloatData( pObjectName , "Skill1ID");
 			pMonster->m_SkillInfos[0].SkillPro = (int)iniMonsterObject.GetFloatData( pObjectName , "Skill1Pro");
 			pMonster->m_SkillInfos[0].SkillCoe = iniMonsterObject.GetFloatData( pObjectName , "Skill1Coe");
 			pMonster->m_SkillInfos[1].SkillID  = (int)iniMonsterObject.GetFloatData( pObjectName , "Skill2ID");
 			pMonster->m_SkillInfos[1].SkillPro = (int)iniMonsterObject.GetFloatData( pObjectName , "Skill2Pro");
 			pMonster->m_SkillInfos[1].SkillCoe = iniMonsterObject.GetFloatData( pObjectName , "Skill2Coe");
 			pMonster->m_SkillInfos[2].SkillID  = (int)iniMonsterObject.GetFloatData( pObjectName , "Skill3ID");
 			pMonster->m_SkillInfos[2].SkillPro = (int)iniMonsterObject.GetFloatData( pObjectName , "Skill3Pro");
 			pMonster->m_SkillInfos[2].SkillCoe = iniMonsterObject.GetFloatData( pObjectName , "Skill3Coe");
 			pMonster->m_SkillInfos[3].SkillID  = (int)iniMonsterObject.GetFloatData( pObjectName , "Skill4ID");
 			pMonster->m_SkillInfos[3].SkillPro = (int)iniMonsterObject.GetFloatData( pObjectName , "Skill4Pro");
 			pMonster->m_SkillInfos[3].SkillCoe = iniMonsterObject.GetFloatData( pObjectName , "Skill4Coe");

 			pMonster->InitObjData(0);

 			// 放入逻辑队列
 			m_listMonster.push_back( pMonster );
 			m_listObject.push_back( (CGameObject*)pMonster );
		}
		else
		{
			printf( "\nCreate Monster Error!\n" );
		}
	}

	//////////////////////////////////////////////////////////////////////////
	//printf( "   单怪:%d", foroutput );
	foroutput = 0;

/*
	//////////////////////////////////////////////////////////////////////////
	// 区域刷怪
	//////////////////////////////////////////////////////////////////////////
	for( int num=0; num<10; num++ )
	{
		memset( path_monster_colony, 0, 256 );
		sprintf( path_monster_colony, "./scene/%s/MonsterColony%02d.ini", m_strName.c_str(), num );
		sbase::CIni iniMonsterColony( path_monster_colony, false );					// 怪物位置布局表

		// 获取怪物布局
		int count = iniMonsterColony.GetData( "default", "count" );
		foroutput += count;
		for( int i=0; i<count; i++ )
		{
			memset( buf, 0, 256 );
			sprintf( buf, "Colony%03d", i );

			// 创造Monster
			int number = iniMonsterColony.GetData( buf, "Number" );
			monsteroutput += number;
			for( int j=0; j<number; j++ )	// 区域怪物密度
			{
				const char* pObjectName = iniMonsterColony.GetString(buf,"Object");

				if( pObjectName != NULL )
				{
					CMonster* pMonster = m_pWorld->GetMonster( g_lMonsterCount );
					g_lMonsterCount++;
					pMonster->m_pRegion = this;
					pMonster->Activate();
					//sprintf( pMonster->m_ObjectData.m_strName, "%s", pObjectName );
					pMonster->SetName( pObjectName );
					pMonster->SetPos( iniMonsterColony.GetFloatData(buf,"X")+(float)(sbase::RandGet( iniMonsterColony.GetData(buf,"Range"), false )), 0.0f, iniMonsterColony.GetFloatData(buf,"Z")+(float)(sbase::RandGet( iniMonsterColony.GetData(buf,"Range"), false )), true );
					pMonster->m_fIniX = pMonster->GetPosX();
					pMonster->m_fIniZ = pMonster->GetPosZ();

					pMonster->SetRefreshTime( iniMonsterColony.GetData( buf, "RefreshTime" ) );
					pMonster->m_lMode = iniMonsterColony.GetData( buf,"Mode" );
					pMonster->m_Level = iniMonsterColony.GetData( buf,"Level" );
					pMonster->SetlLevel( (BYTE)pMonster->m_Level );
					pMonster->m_DropConfig.DropNum = iniMonsterColony.GetData( buf,"DropNum" );
					pMonster->m_DropConfig.DropProbability = iniMonsterColony.GetData( buf,"DropProbability" );
					pMonster->m_DropConfig.Distribution = iniMonsterColony.GetData( buf,"Distribution" );
					pMonster->m_QuestID = iniMonsterColony.GetData(buf , "QuestID");
					pMonster->m_QuestItem[0] = iniMonsterColony.GetData(buf , "QuestItem1");
					pMonster->m_QuestItem[1] = iniMonsterColony.GetData(buf , "QuestItem2");
					pMonster->m_QuestItem[2] = iniMonsterColony.GetData(buf , "QuestItem3");
					pMonster->m_QuestItem[3] = iniMonsterColony.GetData(buf , "QuestItem4");
					pMonster->m_QuestItem[4] = iniMonsterColony.GetData(buf , "QuestItem5");
					pMonster->m_QuestItem[5] = iniMonsterColony.GetData(buf , "QuestItem6");
					pMonster->m_QuestItem[6] = iniMonsterColony.GetData(buf , "QuestItem7");
					pMonster->m_QuestItem[7] = iniMonsterColony.GetData(buf , "QuestItem8");

					pMonster->SetlFaction(iniMonsterObject.GetFloatData( pObjectName, "Faction" ));

					pMonster->m_fActivityRange = iniMonsterObject.GetFloatData( pObjectName, "ActivityRange" );
					pMonster->m_fEyeshot = iniMonsterObject.GetFloatData( pObjectName, "Eyeshot" );
					//pMonster->m_Kidney = iniMonsterObject.GetFloatData( pObjectName, "Kidney" );
					pMonster->Param.StateImmunity = iniMonsterObject.GetFloatData(pObjectName, "StateImmunity" );
					pMonster->Param.Exp_D = iniMonsterObject.GetFloatData(pObjectName, "Exp" );
					pMonster->Param.Base_Parm.HP_D = iniMonsterObject.GetFloatData(pObjectName, "HP" );
					pMonster->Param.Base_Parm.Defend_D = iniMonsterObject.GetFloatData(pObjectName, "Defence" );
					pMonster->Param.Default_Value.Default_Fastness_Fire = iniMonsterObject.GetFloatData(pObjectName, "FireDefence" );
					pMonster->Param.Default_Value.Default_Fastness_Water = iniMonsterObject.GetFloatData(pObjectName, "WaterDefence" );
					pMonster->Param.Default_Value.Default_Fastness_Wind = iniMonsterObject.GetFloatData(pObjectName, "WindDefence" );
					pMonster->Param.Default_Value.Default_Fastness_Terra = iniMonsterObject.GetFloatData(pObjectName, "SoilDefence" );
					pMonster->Param.Default_Value.Defalult_Hit = (int)iniMonsterObject.GetFloatData(pObjectName, "Hit" );
					pMonster->Param.Default_Value.Defalult_Dodge = (int)iniMonsterObject.GetFloatData(pObjectName, "Miss" );
					pMonster->Param.Default_Value.Defalult_MagicExempt = (int)iniMonsterObject.GetFloatData(pObjectName, "MagicImmunity" );
					pMonster->m_SkillInfos[0].SkillID = (int)iniMonsterObject.GetFloatData(pObjectName , "Skill1ID");
					pMonster->m_SkillInfos[0].SkillPro = (int)iniMonsterObject.GetFloatData(pObjectName , "Skill1Pro");
					pMonster->m_SkillInfos[0].SkillCoe = iniMonsterObject.GetFloatData(pObjectName , "Skill1Coe");
					pMonster->m_SkillInfos[1].SkillID = (int)iniMonsterObject.GetFloatData(pObjectName , "Skill2ID");
					pMonster->m_SkillInfos[1].SkillPro = (int)iniMonsterObject.GetFloatData(pObjectName , "Skill2Pro");
					pMonster->m_SkillInfos[1].SkillCoe = iniMonsterObject.GetFloatData(pObjectName , "Skill2Coe");
					pMonster->m_SkillInfos[2].SkillID = (int)iniMonsterObject.GetFloatData(pObjectName , "Skill3ID");
					pMonster->m_SkillInfos[2].SkillPro = (int)iniMonsterObject.GetFloatData(pObjectName , "Skill3Pro");
					pMonster->m_SkillInfos[2].SkillCoe = iniMonsterObject.GetFloatData(pObjectName , "Skill3Coe");
					pMonster->m_SkillInfos[3].SkillID = (int)iniMonsterObject.GetFloatData(pObjectName , "Skill4ID");
					pMonster->m_SkillInfos[3].SkillPro = (int)iniMonsterObject.GetFloatData(pObjectName , "Skill4Pro");
					pMonster->m_SkillInfos[3].SkillCoe = iniMonsterObject.GetFloatData(pObjectName , "Skill4Coe");


					// 放入逻辑队列
					// 					CCell *pCurCell = m_pMap->GetCell( pMonster->GetPosX(), pMonster->GetPosZ() );
					// 					pMonster->SetCurrentCell( pCurCell );
					// 					pMonster->GetCurrentCell()->AddObj( pMonster );
					//pMonster->InitObjData(0);

					m_listMonster.push_back( pMonster );
					m_listObject.push_back( (CGameObject*)pMonster );
				}


			}
		}
	}
	printf( "   群怪区:%d", foroutput );
	foroutput = 0;
*/

	//////////////////////////////////////////////////////////////////////////
	// NPC布局
	//////////////////////////////////////////////////////////////////////////
	for( int num=0; num<10; num++ )
	{
		memset( path_npc, 0, 256 );
		sprintf( path_npc, "./scene/%s/NPC%02d.ini", m_strName.c_str(), num );
		sbase::CIni iniNPC( path_npc, false );							// NPC位置布局表

		// 获取NPC布局
		int count = iniNPC.GetData( "default", "count" );
		foroutput += count;
		for( int i=0; i<count; i++ )
		{
			memset( buf, 0, 256 );
			sprintf( buf, "NPC%03d", i );

			// 创造NPC
			CNPC* pNPC = m_pWorld->GetNPC( g_lNPCCount );
			g_lNPCCount++;


			pNPC->m_pRegion = this;
			pNPC->Activate();
			//sprintf( pNPC->m_ObjectData.m_strName, "%s", iniNPC.GetString(buf,"Name") );
			pNPC->SetName( iniNPC.GetString(buf,"Name") );
			pNPC->SetPos( iniNPC.GetFloatData(buf,"X"), 0.0f, iniNPC.GetFloatData(buf,"Z"), true );
			pNPC->m_fatan2 = iniNPC.GetFloatData(buf,"Atan2");
			pNPC->SetlFaction(iniNPC.GetData( buf, "Faction" ));

			if (iniNPC.GetString(buf , "Script"))
				pNPC->SetScriptName(iniNPC.GetString(buf , "Script"));

			// 放入逻辑队列
			//  			CCell *pCurCell = m_pMap->GetCell( pNPC->GetPosX(), pNPC->GetPosZ() );
			//  			pNPC->SetCurrentCell( pCurCell );
			//  			pNPC->GetCurrentCell()->AddObj( pNPC );
			m_listNPC.push_back( pNPC );
			m_listObject.push_back( (CGameObject*)pNPC );
		}
	}
	//printf( "   NPC:%d", foroutput );
	foroutput = 0;

	//////////////////////////////////////////////////////////////////////////
	// 传送点
	//////////////////////////////////////////////////////////////////////////
	memset( path_convey, 0, 256 );
	sprintf( path_convey, "./scene/%s/Convey.ini", m_strName.c_str() );
	sbase::CIni iniConvey( path_convey, false );							// 传送位置布局表

	// 获取传送点布局
	count = iniConvey.GetData( "default", "count" );
	foroutput += count;
	for( int i=0; i<count; i++ )
	{
		memset( buf, 0, 256 );
		sprintf( buf, "Convey%02d", i );

		tarSceneConvey* pConvey = new tarSceneConvey;
		pConvey->rect_left = iniConvey.GetFloatData( buf, "rect_left" );
		pConvey->rect_top =  iniConvey.GetFloatData( buf, "rect_top" );
		pConvey->rect_right = iniConvey.GetFloatData( buf, "rect_right" );
		pConvey->rect_bottom = iniConvey.GetFloatData( buf, "rect_bottom" );
		pConvey->toScene = iniConvey.GetString( buf, "to" );
		pConvey->toX = iniConvey.GetFloatData( buf, "to_x" );
		pConvey->toZ = iniConvey.GetFloatData( buf, "to_z" );

		m_listConvey.push_back( pConvey );
	}
	//printf( "   传送点:%d", foroutput );

	//printf( "   怪物总数:%d", monsteroutput );

	m_lMonsterQueue = (long)m_listMonster.size();
	if( m_lMonsterQueue > 0 )
	{
//		m_pMonsterQueue = new CMonster[m_lMonsterQueue];
		int kkk=0;
		for( MonsterIterator it=m_listMonster.begin(); it!=m_listMonster.end(); it++ )
		{
			CMonster* pMonster = *it;
			m_pMonsterQueue[kkk] = pMonster;
			kkk++;
		}
	}

	return true;

}

void CRegion::ResetMonster( void )
{
	// 释放
//npc:
	if( m_listNPC.size() != 0 )
	{
		for( NPCIterator it=m_listNPC.begin(); it!=m_listNPC.end(); it++ )
		{
			CNPC* pNPC = *it;
			RemoveNPC( pNPC );
			//goto npc;
		}
	}

//monster:
	if( m_listMonster.size() != 0 )
	{
		for( MonsterIterator it=m_listMonster.begin(); it!=m_listMonster.end(); it++ )
		{
			CMonster* pMonster = *it;
			RemoveMonster( pMonster );
			//goto monster;
		}
	}

	if( m_listConvey.size() != 0 )
	{
		for( SceneConveyIterator it=m_listConvey.begin(); it!=m_listConvey.end(); it++ )
		{
			tarSceneConvey* p = *it;
			SAFE_DELETE( p );
		}
		m_listConvey.clear();
	}

	// 重构
	CreateMonsterFromIni();

	for( NPCIterator it=m_listNPC.begin(); it!=m_listNPC.end(); it++ )
	{
		CNPC* p = *it;
		msg.uiID = p->GetID();
		msg.ucCamp  = p->GetlFaction();
		msg.uiType = _OBJECT_TYPE_NPC;
		msg.X = p->GetPosX();
		msg.Y = p->GetPosY();
		msg.Z = p->GetPosZ();
		msg.fAtan2 = p->GetAtan2();
		sprintf( msg.cName, "%s", p->GetName() );
		// by fenjune SendMsgToPlayer( &msg );
		SendAreaMsgOneToOther( p->GetCurrentCell(), &msg );
	}
	for( MonsterIterator it=m_listMonster.begin(); it!=m_listMonster.end(); it++ )
	{
		CMonster* p = *it;
		if( p->GetState() != MONSTER_STATE_LOST )
		{
			if( p->GetState() != MONSTER_STATE_DEAD )
			{
				msg.uiID = p->GetID();
				msg.uiType = _OBJECT_TYPE_MONSTER;
				msg.X = p->GetPosX();
				msg.Y = p->GetPosY();
				msg.Z = p->GetPosZ();
				msg.fAtan2 = p->GetAtan2();
				msg.uiHP = p->GetlHP();
				msg.uiMaxHP = p->GetMaxHP();
				sprintf( msg.cName, "%s", p->GetName() );
				// by fenjune SendMsgToPlayer( &msg );
				SendAreaMsgOneToOther( p->GetCurrentCell(), &msg );

				// 				msg_dead.uiID = p->GetID();
				// 				SendMsgToPlayer( &msg_dead );
			}
		}
	}
}

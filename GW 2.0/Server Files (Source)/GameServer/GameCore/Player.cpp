#include "StdAfx.h"
#include "Player.h"
#include "Region.h"
#include "..\ServiceLoader.h"
#include "..\ErrorMessage.h"
#include ".\SkillManager.h"
#include "..\..\Common\MsgDefine.h"
#include "..\..\Common\MsgTypes.h"
#include ".\ItemManager.h"
#include "..\..\Common/Include/Base\Inc\IPCChannel.h"
#include ".\GameData.h"
#include "..\DataCore.h"
#include <mysql.h>
#include "..\..\Common/Include/DB\Inc\Database.h"
#include "../World.h"
#include "..\Dial.h"

#include ".\Mat.h"
 

extern MSG_ACTIVESKILL_INFO  msg_activeskill_info;
extern MSG_PASSIVESKILL_INFO msg_passiveskill_info;

extern MSG_DEAD msg_dead;
extern MSG_WALK_END msg_walk_end;
extern MSG_OBJECTINFO msg, msg2other;

extern MSG_SYN_GAMEDATA  msg_syn_gamedata;
extern MSG_USEOREQUIP_ITEM msg_useorequip_item;

//------------------------------------------------------------------------------------
PARAME CPlayer::Param;
ATTACK_PARAM  CPlayer::AttackParam;

//------------------------------------------------------------------------------------

HASH_STR CPlayer::m_Player_RoleName;
HASH_STR CPlayer::m_Player_Accounts;
HASH_INT CPlayer::m_Player_Socket;


//------------------------------------------------------------------------------------
map< string, string >  CPlayer::m_valid_map;
map<  snet::CSocket*, string >  CPlayer::m_Soket_map;

//------------------------------------------------------------------------------------
sbase::CCriticalSection g_xLock;

void CPlayer::AddSocketHashMap( snet::CSocket* PSocket,CPlayer *pPlayer )
{
	m_Player_Socket[ PSocket ] = pPlayer;
}

void CPlayer::DelSocketHashMap( snet::CSocket* PSocket )
{
	HASH_INT::iterator  itor = m_Player_Socket.find( PSocket );
	if ( itor != m_Player_Socket.end() )
	{
		m_Player_Socket.erase( itor );
	}
}

CPlayer* CPlayer::GetPlayerFromSocket( snet::CSocket* PSocket )
{
	HASH_INT::iterator  itor = m_Player_Socket.find( PSocket );
	return ( itor != m_Player_Socket.end() ) ? itor->second : NULL ;
}


void CPlayer::AddAccountsHashMap(string accounts,CPlayer *pPlayer )
{
	m_Player_Accounts[ accounts ] = pPlayer;
}

void CPlayer::DelAccountsHashMap( string accounts )
{

	HASH_STR::iterator  itor = m_Player_Accounts.find( accounts );
	itor = m_Player_Accounts.find( accounts );
	if ( itor != m_Player_Accounts.end() )
	{
		m_Player_Accounts.erase( itor );
	}

}

CPlayer*  CPlayer::GetPlayerFromAccounts( string accounts )
{   
	HASH_STR::iterator  itor = m_Player_Accounts.find( accounts );
	return ( itor != m_Player_Accounts.end() ) ? itor->second : NULL ;
}

void CPlayer::AddRoleNameHashMap(string rolename,CPlayer *pPlayer)
{
	m_Player_RoleName[ rolename ] =  pPlayer;
}

void CPlayer::DelRoleNameHasnMap(  string rolename )
{
	HASH_STR::iterator  itor = m_Player_RoleName.find( rolename );
	if ( itor != m_Player_RoleName.end() )
	{
		m_Player_RoleName.erase( itor );
	}

}

CPlayer* CPlayer::GetPlayerFromRoleName( string rolename )
{
	HASH_STR::iterator  itor = m_Player_RoleName.find( rolename );
	return ( itor != m_Player_RoleName.end() ) ? itor->second : NULL ;
}



//------------------------------------------------------------------------------------
CPlayer::CPlayer(void)
{
	m_eType			= OBJECTTYPE_PLAYER;
	m_GodLastTime	= 0;

	m_pSocket		= NULL;

	Init();
	//回写数据库
	//	LoadPlayerConfig();

	m_Trade.SetThis(this);
	m_Storage.Init(this);
	m_Stall.Init(this);
	m_EquipForge.Init(this);

	m_RunTimer.Startup( PLAYER_AI_TIMER );


	m_pTeamLeader = NULL;
	// 	for (int i = 0; i<MAX_TEAM_NUMBER; i++)
	// 	{
	// 		m_pTeam[i] = NULL;
	// 	}
	ucChannel = 255;
	unTalkTime = 0;
}

//------------------------------------------------------------------------------------
CPlayer::~CPlayer(void)
{
	if (  m_pRec != NULL)
	{ 
		SAFE_RELEASE(m_pRec);
	}
}

LONG CPlayer::GetDBID()
{
	return m_DBID;
}
//------------------------------------------------------------------------------------
//加载玩家相关属性
//------------------------------------------------------------------------------------
void CPlayer::Init()
{
	m_Bags[0].SetActive(true);
	m_eState = OBJECT_IDLE;
	SetJoinFlag( false );
	m_uiSkillEffect = 0 ;
	m_lRefreshTime = 0;
	m_ucCurActiveSkill = -1;
	m_cMsg = -1;
	m_Resume_Timer.Clear();
	m_Relation_Timer.Clear();
	m_ActiveSkillCast_Timer.Clear();
	m_ActiveSkillCool_Timer.Clear();
	m_DelPlayerTimer.Clear();
	m_Team_Timer.Clear();
	m_PassiveSkill.clear();
	m_ActiveSkill.clear();
	m_ucActiveSkillCastTime = 0;
	m_ucActiveSkillCastTime = 0;
	m_WinExp = 0 ;                           
	m_ConvertPoint = 0 ; 
    m_WorldStatus == eROLEINFOWAIT;
	m_pRec = NULL ;
	m_skillTargetObj = NULL ;
	m_targetObj = NULL ;
	m_pConsortia = NULL;
	m_pSocket = NULL;

	memset( &m_ObjectData , 0L, sizeof( m_ObjectData ) );
	memset(&m_BaseData,0L,sizeof(m_BaseData));
	memset(&m_Specialty,0L,sizeof(m_Specialty));
	memset(&m_StatusData,0L,sizeof(m_StatusData));
	memset(&m_EquipData,0L,sizeof(m_EquipData));
	memset(&m_AltarData,0L,sizeof(m_AltarData));
	memset(&m_RegisterTime,0L,sizeof(m_RegisterTime));
	memset(&m_OnlineTime,0L,sizeof(m_OnlineTime));

	m_ValidCode  = "";

	if (GetTrade()->IsTrading() && GetTrade()->GetTrader())
		GetTrade()->GetTrader()->GetTrade()->ClearTrade();

	GetTrade()->ClearTrade();

	for (int i = 0 ; i < MAX_BAGS ; i++)
		m_Bags[i].Clear();
	for (int i = 0 ; i < EquipCount ; i++)
		m_Equips[i].Clear();
	for ( int i = 0; i < MSG_SENDFLAG_COUNT; i ++)
		m_MsgFlag[i] = false;

	m_Storage.Clear();
	m_Storage.SetActive(DEFAULT_STORAGE_COUNT);

	m_Stall.Clear();

	m_Accounts.clear();
	m_ValidCode.clear();
	m_AddRole.clear();
	m_HaveRole.clear();
	m_DeleteRole.clear();
	m_RelationMgr.Clear();
	m_pCurrentCell = NULL;
	m_bOtherHands = false;

	InitTeam_New();//队伍信息清空

	GoldOpendNum = 0;			//宝箱开启次数
	m_GoldBoxId = 0;			//正在开启的宝箱ID
	memset(&m_InDialItemID,0,sizeof(m_InDialItemID));	//入围物品ID
	m_SumRand = 0;				//入围物品总几率

	m_Kills = 0;
	m_OverQuests = 0;
	m_GoldBoxId = 0;
	m_BeginX = 0;
	m_BeginZ = 0;
	m_GM = false;
	//m_SceneChangeFlag = false;
	m_EquipForge.Clear();

	m_Login_time = NULL;
	m_LastUpte_time = NULL;

	//倒计时
	m_bExitGameStart = false;
	m_UpdateTime.Clear();
	m_Start_Time = 0;
	PassTime = 0;

	/*------------------------------------------------------------------------------
	 *作者：C.D
	 *日期：2008-06-16
	 *描述：
	 -----------------------------------------------------------------------------*/	
	m_ChatBubbleType = 0;
	m_bIsPKProtected = false;
	m_bIsGreenName = false;	
	m_bIsFalseName = false;

	SynDBOutStand = 0;
	WillRelease = false;
	m_NumOfSpeaker = 0;

	ClearQuest();
}

//------------------------------------------------------------------------------------
//更改玩家数据(数值型)
//------------------------------------------------------------------------------------
void   CPlayer::SetPropertyValue( unsigned int ivalue, USERDATA  stData )
{ 
	m_pRec->Field( stData ) = ivalue;
}

//------------------------------------------------------------------------------------
//更改玩家数据(字符型)
//------------------------------------------------------------------------------------
void      CPlayer::SetPropertyValue( const char* ivalue, USERDATA  stData )
{
	m_pRec->Field( stData ) = ivalue;
}

//------------------------------------------------------------------------------------
//得到玩家数据(字符型)
//------------------------------------------------------------------------------------
LONG   CPlayer::GetPropertyValue( USERDATA /*stData*/)
{
	return  m_pRec->Field( UINT( 0 ) );
}

//------------------------------------------------------------------------------------
//得到玩家数据(数值型)
//------------------------------------------------------------------------------------
SHORT     CPlayer::GetPropertyValue( USERDATA  stData ) const
{
	return  m_pRec->Field( UINT( stData  ));
}

//------------------------------------------------------------------------------------
//根据被动技能更新角色属性
//------------------------------------------------------------------------------------

// 初始化职业数量以及对应的被动技能
bool CPlayer::InitClassPassiveSkill(void)
{
	sbase::CIni  Skill_ini( "skill/skill.ini", false );
	m_ClassCount = (BYTE)Skill_ini.GetData( "classnum", "Count" );

	char item[32] ;
	memset( item ,0L, sizeof(item));

	string str;
	for(int i=0; i<m_ClassCount;i++)
	{
		vector<int> PassiveSkill;
		memset( item ,0L, sizeof(item));
		sprintf(item,"class",i);
		str = Skill_ini.GetString( "Skill", item);

		while (str.find(",") != -1)
		{
			UINT n = str.find(",");
			str[n] = '\0';
			PassiveSkill.push_back(atoi(str.c_str()));
			str.erase(str.begin() , str.begin() + n + 1);
		}
		m_ClassPassiveSkill.push_back(PassiveSkill);
	}
	return true;
}

//------------------------------------------------------------------------------------
//初始化Obj数据库数据
//------------------------------------------------------------------------------------
bool  CPlayer::InitObjData(long ID)
{
	Init();
	//从数据库得到基本数据
	dbtool::IDatabase* DB = CGameObject::s_World->GetDBAddr( DB_NONE );
	if ( !DB )
	{
		ASSERT(0);
		return false;
	}
	//_asm   int   0x3;
	char szSQL[128];
	sprintf(szSQL, SQL_SELECT_USER_BY_ID , ID);
	sprintf(szSQL,"CALL SP_SELECT_PLAYER_INFO(%d);",ID);
	dbtool::IRecordset* pRes = DB->CreateRecordset( szSQL, dbtool::MODE_EDIT );

	if(!pRes)
		return false;
	if(0 == pRes->CountRecord()) 
		return false;

	pRes->Move(0);
	m_pRec = pRes->GetRecord();
	IF_NOT(m_pRec)
		return false;

	//背包装备
	sprintf(szSQL,"CALL SP_SELECT_KITBAG_INFO(%d);",ID);
	pRes = DB->CreateRecordset( szSQL, dbtool::MODE_EDIT );
	int RecordCount = pRes->CountRecord();
	if ( RecordCount == 1)
	{
		pRes->Move( 0 );
		dbtool::IRecord* rec = pRes->GetRecord();
		for ( int i = 0; i < 6; i++ )                       
		{
			char *EquipInfo=(char *)rec->Field( UINT(i) );  //道具栏1
			if (  CreatePropFromDB( EquipInfo, i ) )
			{
				//产生装备的处理
			}
		}
	}
	else 
	{
		//发送无装备信息
	}


	//将读出来的数据赋值给内部结构体
	char * Name = m_pRec->Field( CHARACTER_NAME );
	SetName( Name );
	char *Gender = m_pRec->Field( CHARACTER_GENDER );
	if ( !strcmp( Gender,"male") )
	{
		SetGender( 1 );
	}
	else if ( !strcmp( Gender,"female") )
	{
		SetGender( 2 );
	}
	m_ObjectData.m_lFaction      		   =    (BYTE)m_pRec->Field( CHARACTER_CAMP );
	m_ObjectData.m_lPrestige     		   =    (USHORT)m_pRec->Field( CHARACTER_PRESTIGE );
	m_ObjectData.m_cKnight       		   =    (BYTE)m_pRec->Field( CHARACTER_EARL_RANK );
	m_ObjectData.m_cUnion        		   =    (USHORT)m_pRec->Field( CHARACTER_CONSORTIA );
	m_ObjectData.m_cUnionBusiness		   =    (BYTE)m_pRec->Field( CHARACTER_CONSORTIA_JOB );
	m_ObjectData.m_uiUionContribute		   =    (UINT)m_pRec->Field( CHARACTER_CONSORTIA_CONTRIBUTE );
	m_ObjectData.m_uiStoreNum			   =    (UINT)m_pRec->Field( CHARACTER_STORE_NUM );
	m_ObjectData.m_uiBagNum				   =    (UINT)m_pRec->Field( CHARACTER_BAG_NUM );
	m_ObjectData.m_lClass			       =    (BYTE)m_pRec->Field( CHARACTER_PROFESSION );
	m_ObjectData.m_cExp					   =    (UINT)m_pRec->Field( CHARACTER_EXP );
	m_ObjectData.m_cRank				   =    (BYTE)m_pRec->Field( CHARACTER_LV );
	m_ObjectData.m_lHP				       =    (UINT)m_pRec->Field( CHARACTER_HP_CUR );
	m_ObjectData.m_lMP				       =    (UINT)m_pRec->Field( CHARACTER_MP_CUR );
	m_ObjectData.m_usAttackDistance        =    (USHORT)m_pRec->Field( CHARACTER_HP_CUR );         //数据库暂时没有此字段
	m_ObjectData.m_usAttackSpeed           =    (USHORT)m_pRec->Field( CHARACTER_HP_CUR );         //数据库暂时没有此字段
	m_ObjectData.m_cHairStyle              =    (BYTE)m_pRec->Field( CHARACTER_HAIRSTYLE );       //数据库暂时没有此字段
	m_ObjectData.m_cPupilColor             =    (BYTE)m_pRec->Field( CHARACTER_FACESHAP );	      //数据库暂时没有此字段
	m_ObjectData.m_usBelief                =    (USHORT)m_pRec->Field( CHARACTER_BELIFE );

	//得到被动技能数据
	sprintf(szSQL, "SELECT skill_id ,practice_degree FROM user_skill WHERE user_id = %d;", ID );
	dbtool::IRecordset *pPassiveSkillRes = DB->CreateRecordset( szSQL, dbtool::MODE_EDIT );
	int count = pPassiveSkillRes->CountRecord();
	dbtool::IRecord *tempRecord;
	BYTE SkillID;
	for ( int i = 0; i < count; i++ )
	{   
		pPassiveSkillRes->Move( i );
		tempRecord  = pPassiveSkillRes->GetRecord();
		SkillID = tempRecord->Field( UINT(0) ) ;
		PASSIVEINFO   passive_info;
		passive_info.Grade = 0;
		//	passive_info.Degree_Practice = tempRecord->Field( 1 );
		m_PassiveSkill[ SkillID ] = passive_info;
		UpdateAttributeInfo( SkillID,TYPE_ADD );
	}

	//得到主动技能数据
	sprintf(szSQL,"SELECT * FROM user_magic WHERE user_id = %d;",ID);
	dbtool::IRecordset* pActiveSkillRes = DB->CreateRecordset( szSQL, dbtool::MODE_EDIT );
	count = pActiveSkillRes->CountRecord();
	for ( int i = 0; i < count; i++ )
	{
		pActiveSkillRes->Move( i);
		tempRecord = pActiveSkillRes->GetRecord();
		ACTIVE_INFO active_info;
		active_info.Time_start     =  time( NULL );
		UINT time = tempRecord->Field( 2 );
		active_info.Time_style     =  ( time == 0 ) ? TIME_STYLE_NONE : TIME_STYLE_COOL;
		active_info.Time_interval  =  time;
		m_ActiveSkill[ tempRecord->Field( 1 ) ] = active_info;	

	}  

	SAFE_RELEASE(pRes);
	SAFE_RELEASE(pActiveSkillRes);
	SAFE_RELEASE(pPassiveSkillRes);

	return true;
}

//-----------------------------------------------------------------------------------
// 离线状态更新DB
//-----------------------------------------------------------------------------------
void CPlayer::UpdateDB_Offline( const char *Name, UINT Union, BYTE UnionDuty )
{
	char szSQL[512];
	memset( szSQL,0L,sizeof(szSQL) );

	dbtool::IDatabase* DB = CGameObject::s_World->GetDBAddr( DB_NONE );
	if ( !DB )
	{
		ASSERT(0);
		return ;
	}

	sprintf( szSQL, OFFLINE_SQL_UPDATE_UNION , Name, Union, UnionDuty,GetcUnionBusiness() );
	DB->ExecuteAsyncSQL( szSQL, ( void * )this, &CPlayer::DealWith_Offline_Update_Uinon );
	InterlockedIncrement(&SynDBOutStand);

}
//-----------------------------------------------------------------------------------
// 离线状态更新祭坛DB
//-----------------------------------------------------------------------------------
void CPlayer::UpdateDB_Altar( const char *Name )
{
	char szSQL[512];
	memset( szSQL,0L,sizeof(szSQL) );

	dbtool::IDatabase* DB = CGameObject::s_World->GetDBAddr( DB_NONE );
	if ( !DB )
	{
		ASSERT(0);
		return ;
	}
	sprintf( szSQL, OFFLINE_SQL_UPDATE_ALTAR_INFO ,Name);
	DB->ExecuteAsyncSQL( szSQL, NULL, NULL );
}

//------------------------------------------------------------------------------------
//角色属性
//------------------------------------------------------------------------------------
void    CPlayer::UpdateDB_RoleAttribute(  CPlayer *pPlayer )
{
	dbtool::IDatabase* DB = CGameObject::s_World->GetDBAddr( DB_NONE );
	DB->ExecuteAsyncSQL( pPlayer->PackRoleAttribute(), ( void * )pPlayer, &CPlayer::DealWith_Update_RoleUpate );
	InterlockedIncrement(&pPlayer->SynDBOutStand);
}

//------------------------------------------------------------------------------------
//道具装备
//------------------------------------------------------------------------------------
UINT CPlayer::GetDBIDByRoleName( string RoleName )
{
	UINT  UserID = 0 ;
	map<string,UINT>::iterator itor = m_HaveRole.find( RoleName );
	if ( itor !=  m_HaveRole.end() )
	{
		UserID = itor->second;
	}
	return UserID;
}

ULONG CPlayer::GetEXP()
{
	return m_ObjectData.m_cExp;
}

UINT CPlayer::GetRank()
{
	return (UINT)GetcRank( );
}



ULONG CPlayer::SetAtttibute( )
{
	m_BaseData.m_lMaxHP             =   CPeizhi::Instance()->GetPlayerMaxHP( GetRank(), GetlClass() );   
	m_BaseData.m_lMaxMP             =	CPeizhi::Instance()->GetPlayerMaxMP( GetRank(), GetlClass() );
	m_BaseData.m_lResumeHP          =   (ULONG)CPeizhi::Instance()->GetPlayerRecoverHP( GetRank(), GetlClass() );
	m_BaseData.m_lResumeMP          =	(ULONG)CPeizhi::Instance()->GetPlayerRecoverMP( GetRank(), GetlClass() );
	m_BaseData.m_lAttack		    =   CPeizhi::Instance()->GetDefaultValue( PLAYER_PHY_ATTACK );
	m_BaseData.m_lDefend		    =   CPeizhi::Instance()->GetDefaultValue( PLAYER_PHY_DEFEND );
	m_BaseData.m_lMagicAttack       =   CPeizhi::Instance()->GetDefaultValue( PLAYER_MAGIC_ATTACK );
	m_BaseData.m_lMagicDefend       =   CPeizhi::Instance()->GetDefaultValue( PLAYER_MAGIC_DEFEND );
	m_BaseData.m_lHit			    =   CPeizhi::Instance()->GetDefaultValue( PLAYER_HIT );
	m_BaseData.m_lDodge		        =   CPeizhi::Instance()->GetDefaultValue( PLAYER_MISS );
/* by lion 为了解决当前值 最大值不匹配问题
	if ( m_ObjectData.m_lHP >= m_BaseData.m_lMaxHP )
		m_ObjectData.m_lHP = m_BaseData.m_lMaxHP;

	if ( m_ObjectData.m_lMP >=  m_BaseData.m_lMaxMP  )
		m_ObjectData.m_lMP = m_BaseData.m_lMaxMP;
*/
	//add by lion 有可能不对 同步当前HP MP
	m_ObjectData.m_lHP = GetMaxHP();
	m_ObjectData.m_lMP = GetMaxMP();

	return 0;
}

void CPlayer::SynTeamData(  void* buf )
{
	//队友 
	// 	if ( NULL != m_pTeam[0]   )
	// 	{
	// 		for ( int a = 0; a < MAX_TEAM_NUMBER; a++ )
	// 		{
	// 			if ( m_pTeam[a] != this && !GetRegion()->GetMap()->IsTwoCellCross( GetCurrentCell(), m_pTeam[a]->GetCurrentCell() ) )
	// 			{
	// 				CGameObject::s_World->SendMsgToClient( buf , m_pTeam[a]->GetSocket() );
	// 			}
	// 		}
	// 	}
	//修改by C.D 20071226
	if (m_pTeamLeader != NULL)
	{
		if ( m_pTeamLeader != this && !GetRegion()->GetMap()->IsTwoCellCross( GetCurrentCell(), m_pTeamLeader->GetCurrentCell() ) )
		{
			CGameObject::s_World->SendMsgToClient( buf , m_pTeamLeader->GetSocket() );
		}
		for ( vector<CPlayer*>::iterator iter = m_pTeamLeader->m_Teammates.begin();
			iter != m_pTeamLeader->m_Teammates.end();
			iter++ )
		{
			if ( (*iter) != this && !GetRegion()->GetMap()->IsTwoCellCross( GetCurrentCell(), (*iter)->GetCurrentCell() ) )
			{
				CGameObject::s_World->SendMsgToClient( buf , (*iter)->GetSocket() );
			}
		}
	}


	//20071226
}

void CPlayer::AddGMControl( ActionElem &elem  )
{
	m_GMctr->Push( elem );
}
//------------------------------------------------------------------------------------
//同步数据 
//------------------------------------------------------------------------------------
void  CPlayer::SynGameData( bool IsSelf )
{
	msg_syn_gamedata.Head.usSize = sizeof( msg_syn_gamedata );
	msg_syn_gamedata.Head.usType = _MSG_SYN_GAMEDATA;
	msg_syn_gamedata.iUserID     = GetID();
	memcpy( &msg_syn_gamedata.sGameData , &m_ObjectData, sizeof( m_ObjectData ) );
	msg_syn_gamedata.sGameData.m_lMP = GetlMP();
	msg_syn_gamedata.sGameData.m_lHP = GetlHP();
	msg_syn_gamedata.sGameData.m_lRegionID  = CGameObject::s_World->GetRegionFromLogicID( GetlRegionID() )->GetID();
	msg_syn_gamedata.sBaseData.m_lMaxHP    			= GetAlllMaxHP();      
	msg_syn_gamedata.sBaseData.m_lMaxMP    			= GetAlllMaxMP();  
	//工会名称 add by lion
//	m_pConsortia =  CGameObject::s_World->g_pConsortiaManager->GetConsortiaInfo( GetcUnion());
//	strcpy( msg_syn_gamedata.sGameData.m_acName, m_pConsortia->acName );
	
	if ( msg_syn_gamedata.sGameData.m_lMP > msg_syn_gamedata.sBaseData.m_lMaxMP)
		msg_syn_gamedata.sGameData.m_lMP = msg_syn_gamedata.sBaseData.m_lMaxMP;
	else if ( msg_syn_gamedata.sGameData.m_lMP < 0 )
		msg_syn_gamedata.sGameData.m_lMP = 0 ;

	if ( msg_syn_gamedata.sGameData.m_lHP > msg_syn_gamedata.sBaseData.m_lMaxHP)
		msg_syn_gamedata.sGameData.m_lHP = msg_syn_gamedata.sBaseData.m_lMaxHP;
	else if ( msg_syn_gamedata.sGameData.m_lHP < 0 )
		msg_syn_gamedata.sGameData.m_lHP = 0;

	msg_syn_gamedata.sBaseData.m_lResumeHP 			= GetAlllResumeHP();              
	msg_syn_gamedata.sBaseData.m_lResumeMP 			= GetAlllResumeMP();              
	msg_syn_gamedata.sBaseData.m_lAttack   			= GetAlllAttack();				  
	msg_syn_gamedata.sBaseData.m_lDefend   			= GetAlllDefend();				  
	msg_syn_gamedata.sBaseData.m_lMagicAttack   	= GetAlllMagicAttack();           
	msg_syn_gamedata.sBaseData.m_lMagicDefend   	= GetAlllMagicDefend();           
	msg_syn_gamedata.sBaseData.m_lHit           	= GetAlllHit();						
	msg_syn_gamedata.sBaseData.m_lDodge         	= GetAlllDodge();					
	msg_syn_gamedata.sBaseData.m_lCritAppend    	= GetAlllCritAppend();            
	msg_syn_gamedata.sBaseData.m_lCritDefend    	= GetAlllCritDefend();            
	msg_syn_gamedata.sBaseData.m_fPhyDamageAppend   = GetAllfPhyDamageAppend();       
	msg_syn_gamedata.sBaseData.m_fMagicDamageAppend = GetAllfMagicDamageAppend();     
	msg_syn_gamedata.sBaseData.m_lDamageSorb        = GetAlllDamageSorb();            
	msg_syn_gamedata.sBaseData.m_fBeCure            = GetAllfBeCure();                
	msg_syn_gamedata.sBaseData.m_fCure              = GetAllfCure();                  
	msg_syn_gamedata.sBaseData.m_lStatusHit         = GetAlllStatusHit();             
	msg_syn_gamedata.sBaseData.m_lStatudDodge       = GetAlllStatudDodge();
	msg_syn_gamedata.iAttackDistance                = GetAttackDistance();
	msg_syn_gamedata.iAttackSpeed                   = GetAttackSpeed();

	if ( IsSelf )
		CGameObject::s_World->SendMsgToClient( &msg_syn_gamedata , GetSocket() );
	else
	{
		//队友( 仅限不在可见区域内)
		//SynTeamData( &msg_syn_gamedata );   
		//周围玩家
		GetRegion()->SendAreaMsgOneToOther( GetCurrentCell(), &msg_syn_gamedata );
	}

}

void  CPlayer::RequestGameData( CPlayer * pPlayer)
{
	msg_syn_gamedata.Head.usSize = sizeof( msg_syn_gamedata );
	msg_syn_gamedata.Head.usType = _MSG_SYN_GAMEDATA;
	msg_syn_gamedata.iUserID     = GetID();
	memcpy( &msg_syn_gamedata.sGameData , &m_ObjectData, sizeof( m_ObjectData ) );
	msg_syn_gamedata.sGameData.m_lMP = GetlMP();
	msg_syn_gamedata.sGameData.m_lHP = GetlHP();
	msg_syn_gamedata.sGameData.m_lRegionID  = CGameObject::s_World->GetRegionFromLogicID( GetlRegionID() )->GetID();
	msg_syn_gamedata.sBaseData.m_lMaxHP    			= GetAlllMaxHP();      
	msg_syn_gamedata.sBaseData.m_lMaxMP    			= GetAlllMaxMP();  

	if ( msg_syn_gamedata.sGameData.m_lMP > msg_syn_gamedata.sBaseData.m_lMaxMP)
		msg_syn_gamedata.sGameData.m_lMP = msg_syn_gamedata.sBaseData.m_lMaxMP;
	else if ( msg_syn_gamedata.sGameData.m_lMP < 0 )
		msg_syn_gamedata.sGameData.m_lMP = 0 ;

	if ( msg_syn_gamedata.sGameData.m_lHP > msg_syn_gamedata.sBaseData.m_lMaxHP)
		msg_syn_gamedata.sGameData.m_lHP = msg_syn_gamedata.sBaseData.m_lMaxHP;
	else if ( msg_syn_gamedata.sGameData.m_lHP < 0 )
		msg_syn_gamedata.sGameData.m_lHP = 0;

	msg_syn_gamedata.sBaseData.m_lResumeHP 			= GetAlllResumeHP();              
	msg_syn_gamedata.sBaseData.m_lResumeMP 			= GetAlllResumeMP();              
	msg_syn_gamedata.sBaseData.m_lAttack   			= GetAlllAttack();				  
	msg_syn_gamedata.sBaseData.m_lDefend   			= GetAlllDefend();				  
	msg_syn_gamedata.sBaseData.m_lMagicAttack   	= GetAlllMagicAttack();           
	msg_syn_gamedata.sBaseData.m_lMagicDefend   	= GetAlllMagicDefend();           
	msg_syn_gamedata.sBaseData.m_lHit           	= GetAlllHit();						
	msg_syn_gamedata.sBaseData.m_lDodge         	= GetAlllDodge();					
	msg_syn_gamedata.sBaseData.m_lCritAppend    	= GetAlllCritAppend();            
	msg_syn_gamedata.sBaseData.m_lCritDefend    	= GetAlllCritDefend();            
	msg_syn_gamedata.sBaseData.m_fPhyDamageAppend   = GetAllfPhyDamageAppend();       
	msg_syn_gamedata.sBaseData.m_fMagicDamageAppend = GetAllfMagicDamageAppend();     
	msg_syn_gamedata.sBaseData.m_lDamageSorb        = GetAlllDamageSorb();            
	msg_syn_gamedata.sBaseData.m_fBeCure            = GetAllfBeCure();                
	msg_syn_gamedata.sBaseData.m_fCure              = GetAllfCure();                  
	msg_syn_gamedata.sBaseData.m_lStatusHit         = GetAlllStatusHit();             
	msg_syn_gamedata.sBaseData.m_lStatudDodge       = GetAlllStatudDodge();
	msg_syn_gamedata.iAttackDistance                = GetAttackDistance();
	msg_syn_gamedata.iAttackSpeed                   = GetAttackSpeed();

    CGameObject::s_World->SendMsgToClient( &msg_syn_gamedata , pPlayer->GetSocket() );
}


//------------------------------------------------------------------------------------
//同步主动技能 
//------------------------------------------------------------------------------------
void  CPlayer::SynClientActiveSkillData()
{
	if ( m_ActiveSkill.size() > 0  )
	{						
		msg_activeskill_info.uiID  = GetID();
		int a = 0;
		map<UINT ,ACTIVEINFO>::iterator itor = m_ActiveSkill.begin();
		for ( ; itor != m_ActiveSkill.end(); itor++ )
		{
			const MagicData*  pActiveSkill = CGameObject::s_World->g_pSkillManager->GetMagic((*itor).first);
			if ( !pActiveSkill || pActiveSkill->bIsEquipUse )
			{
				continue;
			}

			msg_activeskill_info.Magic[a].cType   =  itor->first;
			msg_activeskill_info.Magic[a].usSurplusCoolTime = itor->second.Time_interval; 
			a++;
		}
		msg_activeskill_info.MagicCounts = (USHORT)a;
		//msg_activeskill_info.Head.usSize = sizeof(msg_activeskill_info.Head ) + 6  +  msg_activeskill_info.MagicCounts * sizeof( MAGIC_INFO ) ;
		int size = sizeof(MSG_ACTIVESKILL_INFO) - 150 * sizeof( MAGIC_INFO );
		msg_activeskill_info.Head.usSize = size  +  msg_activeskill_info.MagicCounts * sizeof( MAGIC_INFO ) ;
		CGameObject::s_World->SendMsgToClient( &msg_activeskill_info, GetSocket() );
	}
}


//------------------------------------------------------------------------------------
//同步被动技能 
//------------------------------------------------------------------------------------
void  CPlayer::SynClientPassiveSkillData()
{
	msg_passiveskill_info.SkillCounts = (USHORT)m_PassiveSkill.size(); 
	int size = sizeof(MSG_PASSIVESKILL_INFO) - sizeof( SKILL_INFO ) * 20;
	/*msg_passiveskill_info.Head.usSize = sizeof( msg_passiveskill_info.Head ) + 6 + msg_passiveskill_info.SkillCounts * sizeof( SKILL_INFO ) ;*/
	msg_passiveskill_info.Head.usSize = size + msg_passiveskill_info.SkillCounts * sizeof( SKILL_INFO ) ;
	msg_passiveskill_info.uiID = GetID();

	int a = 0;
	map<UINT ,PASSIVEINFO>::iterator itertor = m_PassiveSkill.begin();
	for ( ; itertor != m_PassiveSkill.end(); itertor++ )
	{
		USHORT UP_LV = 0;
		/*by lion
		switch( itertor->first )
		{
		case SKILL_HALENESS:
		UP_LV= m_EquipData.StrongLevel;
		break;
		case SKILL_FEAT:
		UP_LV = m_EquipData.FeatLevel;
		break;
		case SKILL_DEFEND:
		UP_LV = m_EquipData.DefanceLevel;
		break;
		case SKILL_ARMOURP_ROCTECT:
		UP_LV = m_EquipData.ArmourLevel;
		break;
		case SKILL_ESCRIME:
		UP_LV = m_EquipData.SwordplayLevel;
		break;
		case SKILL_GLAVE_GAS:
		UP_LV = m_EquipData.SwordAirLevel;
		break;
		case SKILL_EXACTITUDE_ATTACK:
		UP_LV = m_EquipData.PrecisionLevel;
		break;
		case SKILL_MUMP:
		UP_LV = m_EquipData.FighterAirLevel;
		break;
		case SKILL_ENERGY:
		UP_LV = m_EquipData.EnergyPowerLevel;
		break;
		case SKILL_ELEMENTS_STRENGTHEN:
		UP_LV = m_EquipData.ElementIntensifyLevel;
		break;
		case SKILL_ELEMENTS:
		UP_LV = m_EquipData.ElementElementsLevel;
		break;
		case SKILL_ELEMENTS_DEFEND:
		UP_LV = m_EquipData.ElementImmunityLevel;
		break;
		case SKILL_ELEMENTS_VOLITION:
		UP_LV = m_EquipData.EnergyFixLevel;
		break;
		case SKILL_FIR_STRENGTHEN:
		UP_LV = m_EquipData.FireIntensifyLevel;
		break;
		case SKILL_FLEXILE:
		UP_LV = m_EquipData.FlexibleShieldLevel;
		break;
		case SKILL_LIFE_CHANNELS:
		UP_LV = m_EquipData.LifeChannelsLevel;
		break;
		default:
		UP_LV= 0 ;
		break;
		}
		*/
		itertor->second.EquipLV = ( UP_LV >= 15 ) ? 15 :UP_LV ;
		msg_passiveskill_info.Skill[a].cType = itertor->first;
		msg_passiveskill_info.Skill[a].Rank  = itertor->second.Grade;
		msg_passiveskill_info.Skill[a].EquipLV = itertor->second.EquipLV;
		msg_passiveskill_info.Skill[a].NextGradePoint   = CPeizhi::Instance()->GetPlayerSkillGradePoint( itertor->second.Grade, itertor->first );
		a++;
	}
	CGameObject::s_World->SendMsgToClient( &msg_passiveskill_info, GetSocket() );
}

//------------------------------------------------------------------------------------
//打包背包信息
//------------------------------------------------------------------------------------
const char *CPlayer::PackBagkitInfo(  int Index )
{
	static char szSQL[4000];
	memset( szSQL,0L,sizeof(szSQL) );

	ItemData BagKitData;
	string TempStr( "");
	char convert[32];

	memset( szSQL,0L,sizeof(szSQL) );

	if (!m_Bags[Index].GetActive())
		return "";

	for ( int i = 0; i < MAX_BAG_GRID; i++ )
	{


		BagKitData = m_Bags[Index].GetItem( i )->GetItemData( );
		TempStr += "[";
		if ( BagKitData.Base != -1)
		{
			TempStr += itoa( BagKitData.Base, convert, 10 )+string(",");

			for ( int i = 0; i< MAX_EQUIPAPPEND_COUNT; i++)
			{
				if (  BagKitData.Append[i] != -1 )
				{
					itoa(  BagKitData.Append[i], convert , 10 );
					TempStr += convert +string(",");
				}
				else
				{
					TempStr +=string(",");
				}
			}

			TempStr +=  string( itoa(  BagKitData.Binding, convert , 10 ) )+string(",");
			TempStr +=  string( itoa(  BagKitData.Overlap, convert , 10 ) )+string(",");
			TempStr +=  string( itoa(  BagKitData.BaseLV, convert , 10 ) )+string(",");
			TempStr +=  string( itoa(  BagKitData.AppendLV, convert , 10 ) )+string(",");
			TempStr +=  string( itoa(  BagKitData.CdKey, convert , 10 ) );

			TempStr += string( "]#");

		}
		else
		{
			TempStr += string("]#");
			continue;
		}
	}


#ifdef GODSWAR_TESTSWITCH_ON
	sprintf( szSQL, SQL_UPDATE_KITBAG_INFO ,m_HaveRole.begin()->second, Index + 1 , TempStr.c_str() );
#else
	sprintf( szSQL, SQL_UPDATE_KITBAG_INFO ,GetDBIDByRoleName( GetName() ), Index + 1, TempStr.c_str() );
#endif

	return szSQL;
}

//------------------------------------------------------------------------------------
// 打包仓库信息
//------------------------------------------------------------------------------------
const char* CPlayer::PackStorageInfo( )
{
	static char szSQL[4000];
	memset( szSQL,0L,sizeof(szSQL) );

	ItemData Store;
	string TempStr( "");
	char convert[32];

	for ( int a = 0; a < ( MAX_STORAGE_GRID >> 1 ) ; a++ )
	{
		Item *pItem = m_Storage.GetItem( a );
		if ( pItem != NULL )
		{
			Store = pItem->GetItemData();
			TempStr += "[";
			if ( Store.Base != -1 )
			{
				TempStr += itoa( Store.Base, convert, 10 )+string(",");
			}
			else
			{
				TempStr += string("]#");
				continue;
			}

			for ( int i = 0; i< MAX_EQUIPAPPEND_COUNT; i++)
			{
				if (  Store.Append[i] != -1 )
				{
					TempStr += itoa( Store.Append[i], convert, 10)+string(",");
				}
				else
				{
					TempStr += string(",");
				}

			}
			sprintf( convert, "%d,", Store.Binding );
			TempStr += convert;
			sprintf( convert, "%d,", Store.Overlap );
			TempStr += convert;
			sprintf( convert, "%d,", Store.BaseLV );
			TempStr += convert;
			sprintf( convert, "%d,", Store.AppendLV );
			TempStr += convert;
			sprintf( convert, "%d", Store.CdKey );
			TempStr += string(convert) + string("]#");

		}
	}
	TempStr += string("[");
	sprintf( convert, "%d", m_Storage.GetMoney() );
	TempStr += string(convert) + string("]#");

#ifdef GODSWAR_TESTSWITCH_ON
	sprintf( szSQL, SQL_UPDATE_KITBAG_INFO ,m_HaveRole.begin()->second,5 , TempStr.c_str() );
#else
	sprintf( szSQL, SQL_UPDATE_KITBAG_INFO ,GetDBIDByRoleName( GetName() ),5 , TempStr.c_str() );
#endif


	return szSQL;   

}

//------------------------------------------------------------------------------------
//打包装备信息
//------------------------------------------------------------------------------------
const char* CPlayer::PackEquipInfo( )
{
	static char szSQL[2000];
	memset( szSQL,0L,sizeof(szSQL) );

	ItemData EquipData;
	string TempStr( "");
	char convert[32];
	for ( int a = 0; a < EquipCount; a++ )
	{
		TempStr += "[";
		EquipData  = m_Equips[a].GetItemData();
		if ( EquipData.Base != -1)
		{
			TempStr += itoa( EquipData.Base, convert, 10 )+string(",");
		}
		else
		{
			TempStr += string("]#");
			continue;
		}



		for ( int i = 0; i< MAX_EQUIPAPPEND_COUNT; i++)
		{
			if (  EquipData.Append[i] != -1 )
			{
				TempStr += itoa( EquipData.Append[i], convert, 10)+string(",");
			}
			else
			{
				TempStr += string(",");
			}

		}
		// 		for ( int i = 0; i< MAX_EQUIPAPPEND_COUNT; i++)
		// 		{
		// 			if (  abs( EquipData.AppendValue[i] - ( -1 ) ) >= 0.00000001f )
		// 			{
		// 				sprintf( convert, "%0.3f", EquipData.AppendValue[i] );
		// 				TempStr += string(convert) + string(",");
		// 			}
		// 			else
		// 			{
		// 				TempStr +=string(",");
		// 			}
		// 		}

		TempStr += string("1,1,");
		TempStr += itoa( EquipData.BaseLV, convert, 10)+string(",");
		sprintf( convert, "%d,%d]#", EquipData.AppendLV,EquipData.CdKey );
		TempStr += convert;

	}

#ifdef GODSWAR_TESTSWITCH_ON
	int a = sprintf( szSQL, SQL_UPDATE_KITBAG_INFO ,m_HaveRole.begin()->second,6 , TempStr.c_str() );
#else
	sprintf( szSQL, SQL_UPDATE_KITBAG_INFO ,GetDBIDByRoleName( GetName() ),6 , TempStr.c_str() );
#endif

	return szSQL;   

}

//------------------------------------------------------------------------------------
//公会数据回写
//------------------------------------------------------------------------------------
const char * CPlayer::PackConsortiaInfo()
{
	//判断会长(会长负责更所属公会的共有信息)
	static char szSQL[2000];
	memset( szSQL,0L,sizeof(szSQL) );

	if ( ( GetcUnionBusiness() ==  CONSORTIA_CHAIRMAN  || GetcUnionBusiness() ==  CONSORTIA_CHAIRMAN ) && GetcUnion() != 0 )
	{
		string TempStr( "");
		char convert[32];
		if ( m_pConsortia == NULL )
		{
			return "";
		}
		std::map<int ,CAltarElem*>::iterator Altar_itor = m_pConsortia->m_pAltar.begin();
		for (; Altar_itor != m_pConsortia->m_pAltar.end();Altar_itor++)
		{
			TempStr += "[";
			itoa( Altar_itor->first , convert , 10 );
			TempStr += convert + string(",");
			itoa( Altar_itor->second->m_LV , convert , 10 );
			TempStr += convert + string("]#");
		}

		sprintf( szSQL, SQL_UPDATE_CONSORTIA_INFO ,m_pConsortia->uiID, m_pConsortia->acName, m_pConsortia->acTextInfo, "会长","副会长", "理事", "精英", "会员","见习会员",m_pConsortia->lfound, m_pConsortia->lbijou, m_pConsortia->iLevel, m_pConsortia->lCredit,TempStr.c_str());
		return szSQL;
	}

	return "";
}

//------------------------------------------------------------------------------------
//好友数据回写
//------------------------------------------------------------------------------------
const char* CPlayer::PackFriendInfo()
{
	static char szSQL[2000];
	memset( szSQL,0L,sizeof(szSQL) );

	string TempStr = m_RelationMgr.PackRelationInfo( TYPE_FRIEND );
	if ( TempStr.empty() )
	{
		return "";
	}
	sprintf( szSQL, SQL_UPDATE_RELATION_INFO ,GetDBIDByRoleName( GetName() ),1, TempStr.c_str() );
	return szSQL;
}

//------------------------------------------------------------------------------------
//黑名单数据回写
//------------------------------------------------------------------------------------
const char* CPlayer::PackBackList()
{
	static char szSQL[2000];
	string TempStr = m_RelationMgr.PackRelationInfo( TYPE_BLACKLIST );
	if ( TempStr.empty() )
	{
		return "";
	}
	sprintf( szSQL, SQL_UPDATE_RELATION_INFO ,GetDBIDByRoleName( GetName() ),2, TempStr.c_str() );
	return szSQL;

}

const char *CPlayer::PackActiveSkill()
{
	static char szSQL[4000];
	memset( szSQL,0L,sizeof(szSQL) );

	string TempStr( "");
	char convert[32];


	map<UINT ,ACTIVE_INFO>::iterator itor = m_ActiveSkill.begin();
	for ( ; itor != m_ActiveSkill.end() ; itor++)
	{
		const MagicData*  pActiveSkill = CGameObject::s_World->g_pSkillManager->GetMagic((*itor).first);
		if ( !pActiveSkill || pActiveSkill->bIsEquipUse )
		{
			continue;
		}

		ACTIVE_INFO active = ( *itor).second;
		time_t surplus_time = 0;
		if ( active.Time_style == TIME_STYLE_COOL )
		{
			//计算该技能剩余冷却时间
			surplus_time  =   active.Time_start + pActiveSkill->usCoolingTime;
			time_t  sss = time( NULL);
			surplus_time -= sss;
			if ( surplus_time < 0 )
			{
				surplus_time = 0;
			}

		}
		else if ( active.Time_style == TIME_STYLE_NONE )
		{
			surplus_time = 0;
		}

		TempStr += "[";
		itoa( itor->first , convert , 10 );
		TempStr += convert + string(",");
		itoa( surplus_time , convert , 10 );
		TempStr += convert + string("]#");

	}

	sprintf( szSQL, SQL_UPDATE_ACTIVESKILL_INFO , GetDBIDByRoleName( GetName() ),TempStr.c_str() );

	return szSQL;
}

const char *CPlayer::PackPassiveSkill()
{
	static char szSQL[4000];
	memset( szSQL,0L,sizeof(szSQL) );

	//等级和熟练度
	string TempStr( "");
	char convert[32];


	map<UINT ,PASSIVEINFO>::iterator itor = m_PassiveSkill.begin();
	for ( ; itor != m_PassiveSkill.end() ; itor++)
	{
		PASSIVEINFO passive = ( *itor).second;
		TempStr += "[";
		itoa( itor->first , convert , 10 );
		TempStr += convert + string(",");
		itoa( passive.Grade , convert , 10 );
		TempStr += convert + string("]#");
	}
	sprintf( szSQL, SQL_UPDATE_PASSIVESKILL_INFO , GetDBIDByRoleName( GetName() ),TempStr.c_str() );
	return szSQL;
}

const char *CPlayer::PackAltarInfo()
{
	static char szSQL[4000];
	memset( szSQL,0L,sizeof(szSQL) );

	if (  m_Altar.size() < 12 )
	{
		return "";
	}
	sprintf( szSQL, SQL_UPDATE_ALTAR_INFO , GetDBIDByRoleName( GetName() ),m_Altar[1],m_Altar[2],m_Altar[3],m_Altar[4],m_Altar[5],m_Altar[6],m_Altar[7],m_Altar[8],m_Altar[9],m_Altar[10],m_Altar[11],m_Altar[12]);
	return szSQL;
	
}

const char *CPlayer::PackQuest()
{
#define SINGLE_QUEST_ID  64  
	static char szSQL[10000];
	memset( szSQL,0L,sizeof(szSQL) );

	string  AllQuest="";
	string  TimeQuest="";
	string  AcceptQuest= "";

	//所有任务完成情况
	char convert[64], TimeQuestConver[64], AcceptQuestConvert[64];
	unsigned __int64  temppack = 0;	
	int a = 0;
	for( ; a < QUEST_COUNT; a++ )
	{
		if (!m_Quests[a].Quest) continue;//break;

		unsigned __int64   converttemp = (unsigned __int64 )( m_Quests[a].Status == QUEST_STATUS_OVER ? 1 : 0  ) ;
		temppack |=  converttemp << ( a % SINGLE_QUEST_ID );

		if ( a % SINGLE_QUEST_ID == SINGLE_QUEST_ID - 1 )
		{ 
			sprintf( convert, "%llu", temppack );
			AllQuest += convert ;
			AllQuest += ",";
			temppack = 0;
		} 

		//任务具体状态
		if (  m_Quests[a].Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED) && !GetAcceptQuest(m_Quests[a].Quest->QuestID) )
		{
			TimeQuest += "[";
			sprintf( TimeQuestConver, "%d", m_Quests[a].Quest->QuestID );
			TimeQuest += TimeQuestConver ;
			TimeQuest += ",";
			sprintf( TimeQuestConver,"%d", m_Quests[a].Completed );
			TimeQuest += TimeQuestConver ;
			TimeQuest += ",";
			sprintf( TimeQuestConver,"%d", (int)m_Quests[a].Status );
			TimeQuest += TimeQuestConver ;
			TimeQuest += ",";
			sprintf( TimeQuestConver,"%d", (__int64)m_Quests[a].TimeUpdata );
			TimeQuest += TimeQuestConver ;
			TimeQuest += ",";
			for ( int i = 0; i < QUEST_OBJECTIVES_COUNT; i++ )
			{
				sprintf( TimeQuestConver,"%d", (int)m_Quests[a].ItemCount[i] );
				TimeQuest += TimeQuestConver;
				TimeQuest += ",";
			}
			for ( int i = 0; i < QUEST_OBJECTIVES_COUNT; i++ )
			{
				sprintf( TimeQuestConver,"%d", (int)m_Quests[a].CreatureCount[i] );
				TimeQuest += TimeQuestConver ;
				TimeQuest += ",";
			}
			TimeQuest += "]#";
		}

		if ( GetAcceptQuest(m_Quests[a].Quest->QuestID) )
		{
			AcceptQuest += "[";
			sprintf( AcceptQuestConvert, "%d", m_Quests[a].Quest->QuestID );
			AcceptQuest += AcceptQuestConvert ;
			AcceptQuest += ",";
			sprintf( AcceptQuestConvert,"%d", m_Quests[a].Completed );
			AcceptQuest += AcceptQuestConvert ;
			AcceptQuest += ",";
			sprintf( AcceptQuestConvert,"%d", (int)m_Quests[a].Status );
			AcceptQuest += AcceptQuestConvert ;
			AcceptQuest += ",";
			sprintf( AcceptQuestConvert,"%d", (__int64)m_Quests[a].TimeUpdata );
			AcceptQuest += AcceptQuestConvert ;
			AcceptQuest += ",";
			for ( int i = 0; i < QUEST_OBJECTIVES_COUNT; i++ )
			{
				sprintf( AcceptQuestConvert,"%d", (int)m_Quests[a].ItemCount[i] );
				AcceptQuest += AcceptQuestConvert;
				AcceptQuest += ",";
			}
			for ( int i = 0; i < QUEST_OBJECTIVES_COUNT; i++ )
			{
				sprintf( AcceptQuestConvert,"%d", (int)m_Quests[a].CreatureCount[i] );
				AcceptQuest += AcceptQuestConvert ;
				AcceptQuest += ","; 
			}
			int kk = 0;
			for ( int kk = 0; kk < QUEST_EXPLORER_COUNT; kk++ );
			{
				sprintf( AcceptQuestConvert,"%d", (int)m_Quests[a].ExplorerComp[kk] );
				AcceptQuest += AcceptQuestConvert ;
				AcceptQuest += ","; 
			}

			AcceptQuest += "]#";
		}


	}

	sprintf( convert, "%llu", temppack );
	AllQuest += convert ;
	AllQuest += ",";


	if (  TimeQuest == "" && AcceptQuest == "" )
	{
		return szSQL;
	}

	sprintf( szSQL, SQL_UPDATE_QUEST_INFO, GetDBIDByRoleName( GetName() ), AllQuest.c_str(), AcceptQuest.c_str(), TimeQuest.c_str() );
	return szSQL;
}

//------------------------------------------------------------------------------------
//道具装备数据回写
//------------------------------------------------------------------------------------
void    CPlayer::UpdateDB_KitBag(  CPlayer *pPlayer )
{
	dbtool::IDatabase* DB = CGameObject::s_World->GetDBAddr( DB_NONE );

	for ( int index =  0; index < MAX_BAGS; index++ )
	{
		DB->ExecuteAsyncSQL( pPlayer->PackBagkitInfo( index ) , ( void *)pPlayer, &CPlayer::DealWith_Update_KitBag );
	    InterlockedIncrement(&pPlayer->SynDBOutStand);
	}
	DB->ExecuteAsyncSQL( pPlayer->PackStorageInfo(), ( void *)pPlayer, &CPlayer::DealWith_Update_KitBag );
	InterlockedIncrement(&pPlayer->SynDBOutStand);
	DB->ExecuteAsyncSQL( pPlayer->PackEquipInfo() ,  ( void *)pPlayer, &CPlayer::DealWith_Update_KitBag );
	InterlockedIncrement(&pPlayer->SynDBOutStand);

}

//------------------------------------------------------------------------------------
//社会关系
//------------------------------------------------------------------------------------
void    CPlayer::UpdateDB_Relation(  CPlayer *pPlayer )
{
	dbtool::IDatabase* DB = CGameObject::s_World->GetDBAddr( DB_NONE );
	DB->ExecuteAsyncSQL( pPlayer->PackFriendInfo(), ( void *)pPlayer, &CPlayer::DealWith_Update_Friend );
	InterlockedIncrement(&pPlayer->SynDBOutStand);
	DB->ExecuteAsyncSQL( pPlayer->PackBackList(), ( void *)pPlayer, &CPlayer::DealWith_Update_BlackList );
	InterlockedIncrement(&pPlayer->SynDBOutStand);
	DB->ExecuteAsyncSQL( pPlayer->PackConsortiaInfo(), ( void *)pPlayer, &CPlayer::DealWith_Update_Consortia );
	InterlockedIncrement(&pPlayer->SynDBOutStand);
}

//-----------------------------------------------------------------------------------
//更新任务 
//-----------------------------------------------------------------------------------
void  CPlayer::UpdateDB_Quest( CPlayer *pPlayer )
{
	dbtool::IDatabase* DB = CGameObject::s_World->GetDBAddr( DB_NONE );
	DB->ExecuteAsyncSQL( pPlayer->PackQuest(), ( void *)pPlayer, &CPlayer::DealWith_Update_Quest );
	InterlockedIncrement(&pPlayer->SynDBOutStand);

}


//------------------------------------------------------------------------------------
//玩家退出回写数据库
//------------------------------------------------------------------------------------
bool    CPlayer::UpDateDB()
{

//  	for ( int i=0;i<300;i++ )
//  	{
 		BackUp();
//  	} 

//	CGameObject::s_World->BackUpConsortia();


	return true;
}

//-----------------------------------------------------------------------------------
// 好友黑名单
//-----------------------------------------------------------------------------------
void CPlayer::SendRelationMsg( void )
{
	//sbase::CSingleLock xLock1(&m_xLock);

	if ( !GetJoinFlag() )
	{
		return;
	}

	if ( IsMsgOK( MSG_RELATION_FRIENDS_FLAG ) || IsMsgOK( MSG_RELATION_BLACKLIST_FLAG ) || IsMsgOK( MSG_RELATION_CONSORTIA_FLAG ))
	{
		return ;
	}

	MSG_RELATIONALL relation_friend,relation_blackList; 
	memset( &relation_friend, 0L, sizeof(MSG_RELATIONALL) );
	std::map< string , RELATION > RelationMgr = m_RelationMgr.m_Relation;

	//好友
	relation_friend.Head.usSize = sizeof(MSG_RELATIONALL) - 30*sizeof(Friend);
	relation_friend.Head.usType = _MSG_RELATIONALL;
	relation_friend.uiUserID = GetID();
	relation_friend.ucType = TYPE_FRIEND;
	relation_friend.cNum =  0;

	memset( &relation_blackList, 0L, sizeof(MSG_RELATIONALL) );
	relation_blackList.Head.usSize = sizeof(MSG_RELATIONALL) - 30*sizeof(Friend);
	relation_blackList.Head.usType = _MSG_RELATIONALL;
	relation_blackList.uiUserID = GetID();
	relation_blackList.ucType = TYPE_BLACKLIST;
	relation_blackList.cNum =  0;

	for ( std::map< string , RELATION >::iterator itor =m_RelationMgr.m_Relation.begin(); itor != m_RelationMgr.m_Relation.end(); itor++ )
	{
		CPlayer *pPlayer = GetPlayerFromRoleName(itor->first);


		if ( itor->second.Type == TYPE_FRIEND ) //好友
		{
			strcpy( relation_friend.sFriend[relation_friend.cNum].Name, itor->first.c_str() ); 
			if ( NULL == pPlayer )
			{
				relation_friend.sFriend[relation_friend.cNum].IsOnline = false;
				relation_friend.sFriend[relation_friend.cNum].usCamp =  itor->second.Camp;
				relation_friend.sFriend[relation_friend.cNum].usBusiness = itor->second.Business;
				relation_friend.sFriend[relation_friend.cNum].usCity = itor->second.City;
				relation_friend.sFriend[relation_friend.cNum].uc_LV = itor->second.LV;
			}
			else
			{
				relation_friend.sFriend[relation_friend.cNum].IsOnline = true;
				relation_friend.sFriend[relation_friend.cNum].usCamp = pPlayer->GetlFaction();
				relation_friend.sFriend[relation_friend.cNum].usBusiness = pPlayer->GetlClass();
				relation_friend.sFriend[relation_friend.cNum].usCity = CGameObject::s_World->GetRegionFromLogicID( GetlRegionID() )->GetID();
				relation_friend.sFriend[relation_friend.cNum].uc_LV = pPlayer->GetcRank();
			}
			relation_friend.cNum++;
			relation_friend.Head.usSize += sizeof(Friend);
		}
		else if ( itor->second.Type == TYPE_BLACKLIST ) //黑名单
		{
			strcpy( relation_blackList.sFriend[relation_blackList.cNum].Name, itor->first.c_str() ); 
			if ( NULL == pPlayer )
			{
				relation_blackList.sFriend[relation_blackList.cNum].IsOnline = false;
				relation_blackList.sFriend[relation_blackList.cNum].usCamp =  itor->second.Camp;
				relation_blackList.sFriend[relation_blackList.cNum].usBusiness = itor->second.Business;
				relation_blackList.sFriend[relation_blackList.cNum].usCity = itor->second.City;
				relation_blackList.sFriend[relation_blackList.cNum].uc_LV = itor->second.LV;
			}
			else
			{
				relation_blackList.sFriend[relation_blackList.cNum].IsOnline = true;
				relation_blackList.sFriend[relation_blackList.cNum].usCamp = pPlayer->GetlFaction();
				relation_blackList.sFriend[relation_blackList.cNum].usBusiness = pPlayer->GetlClass();
				relation_blackList.sFriend[relation_blackList.cNum].usCity = CGameObject::s_World->GetRegionFromLogicID( GetlRegionID() )->GetID();
				relation_blackList.sFriend[relation_blackList.cNum].uc_LV = pPlayer->GetcRank();
			}
			relation_blackList.cNum++;
			relation_blackList.Head.usSize += sizeof(Friend);
		}

	}
	if ( relation_friend.cNum > 0 )
	{
		CGameObject::s_World->SendMsgToClient( &relation_friend, GetSocket() );	
	}
	m_MsgFlag[ MSG_RELATION_FRIENDS_FLAG ] = true;

	if (  relation_blackList.cNum >0 )
	{
		CGameObject::s_World->SendMsgToClient( &relation_blackList, GetSocket() );

	}
	m_MsgFlag[ MSG_RELATION_BLACKLIST_FLAG ] = true;

	//公会
	SendConsortiaMsg();
}

//------------------------------------------------------------------------------------
//向客户端发送公会相关消息
//------------------------------------------------------------------------------------
void CPlayer::SendConsortiaMsg( void )
{
	//sbase::CSingleLock xLock1(&m_xLock);
	//公会信息
	m_pConsortia =  CGameObject::s_World->g_pConsortiaManager->GetConsortiaInfo( GetcUnion());
	if ( NULL != m_pConsortia )
	{
		MSG_CONSORTIA_BASE_INFO BaseInfo;
		//Clustering<ConsortiaRelationElem> *pElems =  CGameObject::s_World->g_pConsortiaManager->GetCurMemberWithJob( m_pConsortia, CONSORTIA_CHAIRMAN );
		BaseInfo.Head.usSize = sizeof( MSG_CONSORTIA_BASE_INFO );
		BaseInfo.Head.usType = _MSG_CONSORTIA_BASE_INFO;
		strcpy( BaseInfo.acName, m_pConsortia->acName );
		strcpy( BaseInfo.acTextInfo, m_pConsortia->acTextInfo );
		BaseInfo.iLevel = m_pConsortia->iLevel;
		BaseInfo.lCredit = m_pConsortia->lCredit;
		BaseInfo.lfound = m_pConsortia->lfound;
		BaseInfo.lbijou = m_pConsortia->lbijou;
		BaseInfo.MaxMember = GetConsortiaMaxMember();
		BaseInfo.AltarCounts = (UINT)m_pConsortia->m_pAltar.size();
		std::map<int ,CAltarElem*>::iterator Altar_itor = m_pConsortia->m_pAltar.begin();
		int i=0;
		for (; Altar_itor != m_pConsortia->m_pAltar.end();Altar_itor++)
		{
			BaseInfo.Altar[i].AltarID = Altar_itor->first;
			BaseInfo.Altar[i].Grade = Altar_itor->second->m_LV;
			i++;
		}
		
		CGameObject::s_World->SendMsgToClient( &BaseInfo, GetSocket() );
	}

	//公会成员
	MSG_CONSORTIA_MEMBER_LIST Memeber_List;       
	Memeber_List.Head.usSize = sizeof( MSG_CONSORTIA_MEMBER_LIST );
	Memeber_List.Head.usType = _MSG_CONSORTIA_MEMBER_LIST;
	Memeber_List.uiCount = 0;
	Memeber_List.IsAll = true;

	stdext::hash_map< ConsortiaElem*, CConsortiaMgr::Member >::iterator itor =  CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.find( m_pConsortia );
	if(  itor !=   CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.end() )
	{

		CConsortiaMgr::Member member = itor->second;
		for ( CConsortiaMgr::Member::iterator iter = member.begin(); iter != member.end(); iter++ )
		{
			Memeber_List.Member[Memeber_List.uiCount] = iter->second.m_Data._Ttype;

			CPlayer *pPlayer= GetPlayerFromRoleName( iter->second.m_Data._Ttype.strName );
			if ( NULL == pPlayer )
			{
				Memeber_List.Member[Memeber_List.uiCount].lMapID = -1;
			}
			else
			{
				Memeber_List.Member[Memeber_List.uiCount].lMapID = s_World->GetRegionFromLogicID(pPlayer->GetlRegionID())->GetID();
				Memeber_List.Member[Memeber_List.uiCount].iLevel = pPlayer->GetcRank();
				Memeber_List.Member[Memeber_List.uiCount].uiContribute = pPlayer->GetuiUionContribute();
			}

			Memeber_List.uiCount++;

			if ( Memeber_List.uiCount == 24  )
			{
				CGameObject::s_World->SendMsgToClient( &Memeber_List, GetSocket() ); 
				Memeber_List.uiCount = 0;
				Memeber_List.IsAll = false;
			}
		}

		if (  Memeber_List.uiCount )
		{
			if ( !Memeber_List.IsAll )
			{
				Memeber_List.IsAll = false;
			}
			CGameObject::s_World->SendMsgToClient( &Memeber_List, GetSocket() ); 
		}
	}

	m_MsgFlag[ MSG_RELATION_CONSORTIA_FLAG ] = true;

}
//------------------------------------------------------------------------------------
//向客户端发送祭坛相关消息
//------------------------------------------------------------------------------------
void CPlayer::SendAltarMsg(void)
{
	//sbase::CSingleLock xLock1(&m_xLock);
	if ( IsMsgOK( MSG_ALTAR_FLAG ) || !IsMsgOK( MSG_RELATION_CONSORTIA_FLAG ) )
	{
		return ;
	}

	if ( !m_pConsortia )
	{
		return;  //没有公会就返回
	}
	//发送祭坛消息
	MSG_ALTAR_INFO altar_info;
	altar_info.Head.usSize = sizeof( MSG_ALTAR_INFO );
	altar_info.Head.usType = _MSG_ALTAR_INFO;

	map<UINT,UINT>::iterator itor = m_Altar.begin();
	int i=0; 
	for (; itor!= m_Altar.end(); itor++)
	{
		if (itor->second != 0)
		{
			altar_info.Altar[i].AltarID = itor->first;
			altar_info.Altar[i].Grade = itor->second;
			LoadAllAltar( altar_info.Altar[i].AltarID );
			i++;
		}
	}
	altar_info.iAltarCounts = i;
	CGameObject::s_World->SendMsgToClient( &altar_info, GetSocket() ); 

	m_MsgFlag[ MSG_ALTAR_FLAG ] = true;
}
//------------------------------------------------------------------------------------
//向客户端发送仓库相关消息
//------------------------------------------------------------------------------------
void CPlayer::SendStorageMsg( void )
{
#define SINGAL_STORAGE_NUM 12
	//sbase::CSingleLock xLock1(&m_xLock);
	MSG_STORAGE  StorageInfo;
	ItemData  KitbagInfo;
	StorageInfo.Head.usType  = _MSG_STORAGE;
	StorageInfo.Head.usSize  = sizeof( StorageInfo.Head ) + 12 ;
	StorageInfo.Money = GetStorage()->GetMoney();
	StorageInfo.cKitBagFlag = 0 ;
	StorageInfo.cLine = 0;
	StorageInfo.uiUserID = GetID();
	int MaxActive = StorageInfo.cActiveNum = GetuiStoreNum();
	int index = 0;
	int TempLine = 0;  
 
	for ( int i = 0; i < MaxActive ; i ++ )
	{
		KitbagInfo = m_Storage.GetItem( i )->GetItemData();
		if ( KitbagInfo.Base != -1 )
		{
			StorageInfo.cKitBagFlag  |= ( 1 << ( i % SINGAL_STORAGE_NUM  ) );
			memcpy( &StorageInfo.SKitBagInfo[ index % SINGAL_STORAGE_NUM ], &KitbagInfo, sizeof( KitBag ) );
			index++;
			StorageInfo.Head.usSize += sizeof( KitBag );
		}

		if (  ( i + 1 ) % SINGAL_STORAGE_NUM == 0 || ( i == MaxActive - 1 ) ) //每次发送12个
		{
			//cout<<"MAX_BAG_GRID can!"<<endl;
			if ( StorageInfo.Head.usSize  >= sizeof( StorageInfo.Head ) + 12  )
			{
				//cout<<"MAX_BAG_GRID OK!"<<endl;
				StorageInfo.cLine  = TempLine ;
				CGameObject::s_World->SendMsgToClient( &StorageInfo, GetSocket() );
				TempLine += 2;
			}

			StorageInfo.Head.usSize  = sizeof( StorageInfo.Head ) + 12 ;
			StorageInfo.cKitBagFlag = 0 ;
			index = 0;
		}
	}
}

//------------------------------------------------------------------------------------
//向客户端发送背包相关消息
//------------------------------------------------------------------------------------
void CPlayer::SendPropertyMsg( void )
{
	MSG_SELFPROPERTY  Property;
	memset( &Property, 0L, sizeof( MSG_SELFPROPERTY ) );
	Property.Head.usSize = sizeof( MSG_SELFPROPERTY );
	Property.Head.usType = _MSG_SELFPROPERTY;
	memcpy( Property.m_strName, m_ObjectData.m_strName ,  sizeof( MSG_SELFPROPERTY  ) - sizeof( Property.Head) );
	Property.m_lRegionID  = CGameObject::s_World->GetRegionFromLogicID( GetlRegionID() )->GetID();
	CGameObject::s_World->SendMsgToClient( &Property, GetSocket() );
}

//------------------------------------------------------------------------------------
//向客户端发送背包相关消息
//------------------------------------------------------------------------------------
void CPlayer::SendKitBagMsg( int flag )
{
	//sbase::CSingleLock xLock1(&m_xLock);
	MSG_KITBAG  KitBag;
	ItemData  KitbagInfo;
	KitBag.Head.usType  = _MSG_KITBAG;
	KitBag.Head.usSize  = sizeof( KitBag.Head ) + 20 ;
 
	KitBag.cStartPos = 0;
	KitBag.cKitBagFlag = 0 ;
	KitBag.ctab = 0;
	KitBag.uiUserID = GetID();
	KitBag.uiBagNum = GetuiBagNum();
	KitBag.uiUpdataNum = flag;
	int index = 0;

	if(!flag)
	{
		for ( int i = 0; i<  MAX_BAG_GRID ; i ++ )
		{
			//cout<<"MAX_BAG_GRID"<<i<<endl;
			KitbagInfo = m_Bags[0].GetItem(i)->GetItemData();
			if ( KitbagInfo.Base != -1 )
			{
				KitBag.cKitBagFlag  |= ( 1 << ( i % 24  ) );
				//注意:这里两个结构不一样
				memcpy( &KitBag.SKitBagInfo[ index % 24 ], &KitbagInfo, sizeof( KitBag.SKitBagInfo[0] ) );
				index++;
				KitBag.Head.usSize += sizeof(  KitBag.SKitBagInfo[0]  );
			}


			if (  i ==  ( MAX_BAG_GRID - 1 ) )
			{
				if ( IsActive()  && !m_MsgFlag[MSG_KITBAG_FLAG] )
				{
					if ( index > 0   )
					{
						//cout<<"MAX_BAG_GRID OK!"<<endl;
						CGameObject::s_World->SendMsgToClient( &KitBag, GetSocket() );			
						//cout<<GetName()<<" SendKitBagMsg Success!"<<endl;	
					}
					m_MsgFlag[MSG_KITBAG_FLAG] = true;

				}
				else
				{
					cout<<GetName()<<" SendKitBagMsg failed!"<<endl;
				}
			}
		}
	}
	else
	{
		m_Bags[GetuiBagNum()-1].SetActive(true);
		s_World->SendMsgToClient( &KitBag, GetSocket() );
	}
}

//------------------------------------------------------------------------------------
//同步客户端技能数据
//------------------------------------------------------------------------------------
void CPlayer::SynchronousClientSkill( bool IsMagic)
{
	//发送玩家主动技能信息
	if ( m_ActiveSkill.size() > 0  && IsMagic && GetJoinFlag() )
	{
		msg_activeskill_info.MagicCounts = (USHORT)m_ActiveSkill.size();
		msg_activeskill_info.Head.usSize = sizeof(msg_activeskill_info.Head ) + 6  +  msg_activeskill_info.MagicCounts * sizeof( MAGIC_INFO ) ;
		msg_activeskill_info.uiID  = GetID();
		int a = 0;
		map<UINT ,ACTIVEINFO>::iterator itor = m_ActiveSkill.begin();
		for ( ; itor != m_ActiveSkill.end(); itor++ )
		{
			msg_activeskill_info.Magic[a].cType   =  itor->first;
			msg_activeskill_info.Magic[a].usSurplusCoolTime = itor->second.Time_interval; 
			a++;
		}
		CGameObject::s_World->SendMsgToClient( &msg_activeskill_info, GetSocket() );
	}

	//发送玩家被动技能信息
	if ( m_PassiveSkill.size() > 0  && !IsMagic  && GetJoinFlag() )
	{
		msg_passiveskill_info.SkillCounts = (USHORT)m_PassiveSkill.size(); 
		msg_passiveskill_info.Head.usSize = sizeof( msg_passiveskill_info.Head ) + 6 + msg_passiveskill_info.SkillCounts * sizeof( SKILL_INFO ) ;
		msg_passiveskill_info.uiID = GetID();

		int a = 0;
		map<UINT ,PASSIVEINFO>::iterator itertor = m_PassiveSkill.begin();
		for ( ; itertor != m_PassiveSkill.end(); itertor++ )
		{
			msg_passiveskill_info.Skill[a].cType = itertor->first;
			msg_passiveskill_info.Skill[a].Rank  = itertor->second.Grade;
			msg_passiveskill_info.Skill[a].EquipLV =itertor->second.EquipLV;
			//			msg_passiveskill_info.Skill[a].Exp   = itertor->second.Degree_Practice;
			a++;

		}
		CGameObject::s_World->SendMsgToClient( &msg_passiveskill_info, GetSocket() );
	}

}


//------------------------------------------------------------------------------------
//向客户端发送技能相关消息
//------------------------------------------------------------------------------------
void   CPlayer::SendSkillMsg(  bool IsActive)
{
//	sbase::CSingleLock xLock1(&m_xLock);
	//发送玩家主动技能信息
	if ( m_ActiveSkill.size() > 0  && IsActive && !m_MsgFlag[MSG_SKILL_ACTIVE_FLAG] && GetJoinFlag() )
	{
		msg_activeskill_info.MagicCounts = (USHORT)m_ActiveSkill.size();
		msg_activeskill_info.Head.usSize = sizeof(msg_activeskill_info.Head ) + 6  +  msg_activeskill_info.MagicCounts * sizeof( MAGIC_INFO ) ;
		msg_activeskill_info.uiID  = GetID();
		int a = 0;
		map<UINT ,ACTIVEINFO>::iterator itor = m_ActiveSkill.begin();
		for ( ; itor != m_ActiveSkill.end(); itor++ )
		{
			msg_activeskill_info.Magic[a].cType   =  itor->first;
			msg_activeskill_info.Magic[a].usSurplusCoolTime = itor->second.Time_interval; 
			a++;
		}
		CGameObject::s_World->SendMsgToClient( &msg_activeskill_info, GetSocket() );
		m_MsgFlag[MSG_SKILL_ACTIVE_FLAG] = true;
	}

	//发送玩家被动技能信息
	if ( m_PassiveSkill.size() > 0  && !IsActive && !m_MsgFlag[MSG_SKILL_PASSIVE_FLAG] && GetJoinFlag() )
	{
		msg_passiveskill_info.SkillCounts = (USHORT)m_PassiveSkill.size(); 
		msg_passiveskill_info.Head.usSize = sizeof( msg_passiveskill_info.Head ) + 6 + msg_passiveskill_info.SkillCounts * sizeof( SKILL_INFO ) ;
		msg_passiveskill_info.uiID = GetID();

		int a = 0;
		map<UINT ,PASSIVEINFO>::iterator itertor = m_PassiveSkill.begin();
		for ( ; itertor != m_PassiveSkill.end(); itertor++ )
		{
			USHORT UP_LV = 0;
			/*
			switch( itertor->first )
			{
			case SKILL_HALENESS:
			UP_LV= m_EquipData.StrongLevel;
			break;
			case SKILL_FEAT:
			UP_LV = m_EquipData.FeatLevel;
			break;
			case SKILL_DEFEND:
			UP_LV = m_EquipData.DefanceLevel;
			break;
			case SKILL_ARMOURP_ROCTECT:
			UP_LV = m_EquipData.ArmourLevel;
			break;
			case SKILL_ESCRIME:
			UP_LV = m_EquipData.SwordplayLevel;
			break;
			case SKILL_GLAVE_GAS:
			UP_LV = m_EquipData.SwordAirLevel;
			break;
			case SKILL_EXACTITUDE_ATTACK:
			UP_LV = m_EquipData.PrecisionLevel;
			break;
			case SKILL_MUMP:
			UP_LV = m_EquipData.FighterAirLevel;
			break;
			case SKILL_ENERGY:
			UP_LV = m_EquipData.EnergyPowerLevel;
			break;
			case SKILL_ELEMENTS_STRENGTHEN:
			UP_LV = m_EquipData.ElementIntensifyLevel;
			break;
			case SKILL_ELEMENTS:
			UP_LV = m_EquipData.ElementElementsLevel;
			break;
			case SKILL_ELEMENTS_DEFEND:
			UP_LV = m_EquipData.ElementImmunityLevel;
			break;
			case SKILL_ELEMENTS_VOLITION:
			UP_LV = m_EquipData.EnergyFixLevel;
			break;
			case SKILL_FIR_STRENGTHEN:
			UP_LV = m_EquipData.FireIntensifyLevel;
			break;
			case SKILL_FLEXILE:
			UP_LV = m_EquipData.FlexibleShieldLevel;
			break;
			case SKILL_LIFE_CHANNELS:
			UP_LV = m_EquipData.LifeChannelsLevel;
			break;
			default:
			UP_LV= 0 ;
			break;
			}
			*/
			itertor->second.EquipLV = ( UP_LV > 15 ) ? 15 : UP_LV ;
			msg_passiveskill_info.Skill[a].cType = itertor->first;
			msg_passiveskill_info.Skill[a].Rank  = itertor->second.Grade;
			msg_passiveskill_info.Skill[a].EquipLV = itertor->second.EquipLV;
			msg_passiveskill_info.Skill[a].NextGradePoint   = CPeizhi::Instance()->GetPlayerSkillGradePoint( itertor->second.Grade, itertor->first );
			a++;

		}
		CGameObject::s_World->SendMsgToClient( &msg_passiveskill_info, GetSocket() );
		m_MsgFlag[MSG_SKILL_PASSIVE_FLAG] = true;
	}

}





void CPlayer::SetMoney(int money)
{
	m_ObjectData.m_lMoney = money;
}

int CPlayer::GetMoney() const
{
	return m_ObjectData.m_lMoney;
}

void CPlayer::SetBijou(int /*bijou*/)
{
	//m_ObjectData.m_lStone;
}

int CPlayer::GetBijou() const
{
	return m_ObjectData.m_lStone;
}

void CPlayer::AddMoney(int money)
{
	m_ObjectData.m_lMoney += money;
}

void CPlayer::AddBijou(int bijou)
{
	m_ObjectData.m_lStone += bijou;
}

void CPlayer::AddPrestige(int Prestige)
{
	m_ObjectData.m_lPrestige += Prestige;
}

void CPlayer::AddPoint(int Point)
{
	m_ConvertPoint += Point;
}

//------------------------------------------------------------------------------------
//根据DB产生相应道具
//------------------------------------------------------------------------------------
bool  CPlayer::CreatePropFromDB(string DBString, int Index)
{
	string    tmpstr;
	string    tmpstr1;
	string    tmpprop;
	ItemData  prop;
	size_t a = 0;
	int c = 0;
	int d;
	size_t b;
	//解析（道具+装备+仓库）
	if ( DBString.empty() )
	{
		return  false;
	}
	while ( !DBString.empty() && DBString != "NULL" )
	{
		b = 0;
		d = 0;
		a = DBString.find_first_of( '#');
		tmpstr.assign( DBString,0,a);
		b = tmpstr.find_first_of( ']' );
		tmpstr.assign( DBString,1,b-1 );
		DBString.erase(0,a+1);
		//装备ID


		tmpstr1 = tmpstr;
		while ( !tmpstr.empty() )
		{   

			d++;				
			b = tmpstr.find_first_of(',');
			if ( b != -1)
			{
				tmpprop.assign( tmpstr,0,b);
				tmpstr.erase(0, b+1 );

			}
			else
			{
				tmpprop.assign(tmpstr.c_str());
				if ( Index == 4 )
				{
					GetStorage()->SetMoney( atoi( tmpprop.c_str() ) );	
				}	
				tmpstr.clear();

			}  

			if ( d == 1)
			{
				prop.Base = atoi( tmpprop.c_str() );
			}
			else if( d >= 2 && d <= 6  )
			{
				if ( tmpprop.empty() )
					prop.Append[ d-2 ] = -1;
				else
					prop.Append[ d-2 ] = atoi( tmpprop.c_str() );
			}	
			else if ( d == 7 )
			{
				prop.Binding  = atoi( tmpprop.c_str() );
			}
			else if ( d == 8 )
			{
				prop.Overlap  = atoi( tmpprop.c_str() );
			}
			else if ( d == 9 )
			{
				prop.BaseLV  = atoi( tmpprop.c_str() );
			}
			else if ( d == 10 )
			{
				prop.AppendLV  = atoi( tmpprop.c_str() );
			}
			else if ( d == 11 )
			{
				prop.CdKey  = atoi( tmpprop.c_str() );
			}
		}

		if (  !tmpstr1.empty() )
		{
			if (  Index <= 3 )
			{ 
				if ( c < 24 )
				{
					ItemManager::Instance()->CreateItem( &prop, m_Bags[Index].GetItem(c) );  //背包
				}
				else
				{
					c = 24;
				}
			}
			else if ( Index == 4 )
			{
				if ( c < 54 )
				{
					ItemManager::Instance()->CreateItem(&prop, m_Storage.GetItem(c) ) ;  //仓库
				}
			}
			else if ( Index == 5 )
			{
				if ( c < EquipCount )
				{
					prop.Binding  = 1;
					prop.Overlap = 1;
					ItemManager::Instance()->CreateItem( &prop, &m_Equips[c] );  //装备
					m_Equips[c].Increase(&m_EquipData);
				}
			}


		}

		c++;
	}

	//设置玩家仓库激活
	if ( Index == 4 )
	{
		m_Storage.SetActive( c - 1 );
	}

	//改变攻击速度
	ChangeAttackSpeed();

	return true;
}

//-----------------------------------------------------------------------------------
// 根据DB更新激活任务
//-----------------------------------------------------------------------------------
bool CPlayer::CreateTimeQuestFromDB( string DBString, eTimeQuest TimeType )
{
	enum { QUEST_ID = 1, QUEST_COMPLATECOUNT, QUEST_STATES, QUEST_UPTETIME, QUEST_ITEMCOUNT, QUEST_CREATURECOUNT, QUEST_EXPLORERCOUNT };
	size_t a = 0;
	string  tmpstr;
	string  tmpquest;
	size_t b;
	int d=0;

	UINT QuestID = 0;
	UINT QuestComplateCount= 0;
	UINT QuestStates=0;
	__int64 QuestUpteTime = 0;
	short QuestItemCount[QUEST_OBJECTIVES_COUNT]= { 0 };
	short QuestCreatureCount[QUEST_OBJECTIVES_COUNT]= { 0 };
	short QuestExplorerCount[QUEST_EXPLORER_COUNT]= { 0 };

	if ( DBString.empty() )
	{
		return  false;
	}
	while ( !DBString.empty() )
	{
		d = 0;
		b = 0;
		a = DBString.find_first_of( '#');
		tmpstr.assign( DBString,0,a);
		b = tmpstr.find_first_of( ']' );
		tmpstr.assign( DBString,1,b-1 );
		DBString.erase(0,a+1);
		while ( !tmpstr.empty() )
		{	

			b = tmpstr.find_first_of(',');
			if ( b != -1)
			{
				d++;
				tmpquest.assign( tmpstr,0,b);
				tmpstr.erase(0, b+1 );
			}

			if ( d == QUEST_ID )
			{
				QuestID = atoi( tmpquest.c_str() );
			}
			else if ( d == QUEST_COMPLATECOUNT )
			{
				QuestComplateCount = atoi( tmpquest.c_str() );
			}
			else if ( d == QUEST_STATES )
			{
				QuestStates = atoi( tmpquest.c_str() );
			}
			else if ( d == QUEST_UPTETIME )
			{
				QuestUpteTime = atoi( tmpquest.c_str() );
			}
			else if ( d == QUEST_ITEMCOUNT )
			{
				QuestItemCount[0] = atoi( tmpquest.c_str() );
				for ( int i = 0; i < QUEST_OBJECTIVES_COUNT - 1; i++ )
				{
					b = tmpstr.find_first_of(',');
					tmpquest.assign( tmpstr,0,b);
					tmpstr.erase(0, b+1 );
					QuestItemCount[i+1] = atoi( tmpquest.c_str() );
				}
			}
			else if ( d == QUEST_CREATURECOUNT )
			{
				QuestCreatureCount[0] = atoi( tmpquest.c_str() );
				for ( int i = 0; i < QUEST_OBJECTIVES_COUNT - 1; i++ )
				{
					b = tmpstr.find_first_of(',');
					tmpquest.assign( tmpstr,0,b);
					tmpstr.erase(0, b+1 );
					QuestCreatureCount[i+1] = atoi( tmpquest.c_str() );
				}
			}
			else if ( d == QUEST_EXPLORERCOUNT )
			{
				QuestExplorerCount[0] = atoi( tmpquest.c_str() );
				for ( int i = 0; i < QUEST_EXPLORER_COUNT - 1; i++ )
				{
					b = tmpstr.find_first_of(',');
					tmpquest.assign( tmpstr,0,b);
					tmpstr.erase(0, b+1 );
					QuestExplorerCount[i+1] = atoi( tmpquest.c_str() );
				}
			}

		}

		//任务描述
		SQuestStatus* qs = this->GetQuest(QuestID);
		qs->Completed  = QuestComplateCount;
		qs->Status     = QuestStatus(QuestStates);
		qs->TimeUpdata = QuestUpteTime;
		memcpy( qs->ItemCount, QuestItemCount, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memcpy( qs->CreatureCount, QuestCreatureCount, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memcpy( qs->ExplorerComp, QuestExplorerCount, QUEST_EXPLORER_COUNT * sizeof(short));

		if ( TIME_ACCEPT == TimeType )
		{
			m_AcceptQuests.push_back( GetQuest( QuestID ) );
		}
	}
	return true;
}


//-----------------------------------------------------------------------------------
// 根据DB更新所有任务
//-----------------------------------------------------------------------------------
bool CPlayer::CreateAllQuestFromDB( string DBString)
{
	size_t a = 0;
	string  tmpstr;
	string  tmpquest;
	int d=0;

	if ( DBString.empty() )
	{
		return  false;
	}

	while ( !DBString.empty() )
	{
		a = DBString.find_first_of( ',');
		tmpstr.assign( DBString,0,a);
		unsigned __int64  QuestDes=  _strtoui64( tmpstr.c_str(), NULL, 10 );
		unsigned __int64  Template = 1;
		for( int c = 0; c<64; c++)
		{
			m_Quests[ d * 64  + c ].Status = ( QuestDes & ( Template << c ) ) ?  QUEST_STATUS_OVER : QUEST_STATUS_NONE;
		}	
		d++;
		DBString.erase(0,a+1);
	}
	return true;
}

//------------------------------------------------------------------------------------
//根据DB产生相应主动技能
//------------------------------------------------------------------------------------
bool CPlayer::CreateActiveSkillFromDB( string DBString )
{
	string    tmpstr;
	string    tmpprop;
	ItemData  prop;
	size_t a = 0;
	size_t b;

	//DBString += "[0,0]#[31,0]#[40,0]#[50,0]#[70,0]#[80,0]#[90,0]#[250,0]#[260,0]#[270,0]#[280,0]#[290,0]#[300,0]#[310,0]#[320,0]#[330,0]#[340,0]#[350,0]#";
	//DBString += "[500,0]#[510,0]#[520,0]#[530,0]#[540,0]#[550,0]#[560,0]#[570,0]#[580,0]#[590,0]#[600,0]#[750,0]#[760,0]#[770,0]#[780,0]#[790,0]#[800,0]#";
	//DBString += "[810,0]#[820,0]#[830,0]#[840,0]#";

	if ( DBString.empty() )
	{
		return  false;
	}

	while ( !DBString.empty() )
	{
		b = 0;
		a = DBString.find_first_of( '#');
		tmpstr.assign( DBString,0,a);
		b = tmpstr.find_first_of( ']' );
		tmpstr.assign( DBString,1,b-1 );
		DBString.erase(0,a+1);
		if ( !tmpstr.empty() )
		{				
			b = tmpstr.find_first_of(',');
			tmpprop.assign( tmpstr,0,b);
			UINT MagicID = atoi( tmpprop.c_str() );
			tmpstr.erase(0, b+1 );
			UINT Time = atoi( tmpstr.c_str() );
			ACTIVE_INFO active_info;
			active_info.Time_start     =  time( NULL );
			active_info.Time_style     =  ( Time == 0 ) ? TIME_STYLE_NONE : TIME_STYLE_COOL;
			active_info.Time_interval  =  Time;  

			if ( MagicID >= GODSKILL_ID  )
			{
				const MagicData *Mag = CGameObject::s_World->g_pSkillManager->GetMagic( MagicID );
				if ( Mag == NULL )
				{
					continue;
				}
				active_info.Time_style       =  TIME_STYLE_COOL;
				active_info.Time_interval    =  CGameObject::s_World->g_pSkillManager->GetMagic( MagicID )->usCoolingTime;
				active_info.Time_start       =  time(NULL);
				m_ActiveSkill[ MagicID ]     =  active_info;	

			}
			else
			{
				m_ActiveSkill[ MagicID ] = active_info;	
			}    
		}

	}
	return true;

}


//------------------------------------------------------------------------------------
//根据DB产生相应被动技能
//------------------------------------------------------------------------------------
bool CPlayer::CreatePassiveSkillFromDB( string DBString )
{
	string    tmpstr;
	string    tmpprop;
	ItemData  prop;
	size_t a = 0;
	size_t b;

	if ( DBString.empty() )
	{
		return  false;
	}

	while ( !DBString.empty() )
	{
		b = 0;
		a = DBString.find_first_of( '#');
		tmpstr.assign( DBString,0,a);
		b = tmpstr.find_first_of( ']' );
		tmpstr.assign( DBString,1,b-1 );
		DBString.erase(0,a+1);
		if ( !tmpstr.empty() )
		{	
			PASSIVEINFO passive_info;			
			b = tmpstr.find_first_of(',');
			tmpprop.assign( tmpstr,0,b);
			UINT SkillID = atoi( tmpprop.c_str() );

			tmpstr.erase(0, b+1 );
			b = tmpstr.find_first_of(',');
			tmpprop.assign( tmpstr,0,b);
			passive_info.Grade = atoi( tmpprop.c_str() );
			tmpstr.erase(0, b+1 );

			//passive_info.Degree_Practice = atoi( tmpstr.c_str() );
			AddPassiveSkill( SkillID, passive_info.Grade, 0 );
		}

	}
	return true;
}

//------------------------------------------------------------------------------------
double RandOne0_1(double& seed)
{		 
	//seed为随机数种子
	seed = ((unsigned long)seed) % MODUL65536;		//以为模对种子取余
	seed = RandCoef2053 * (seed) + RandCoef13849;	//乘、加系数
	seed = ((unsigned long)seed) % MODUL65536;		//以为模对种子取余
	double rand = (seed) / (double)MODUL65536;		//使随机数在[0,1]区间
	return( rand );									//返回随机值
}

//-------------------------------------------------------------------------------------
//[a,b]区间内产生stCount个随即数
//--------------------------------------------------------------------------------------
void 
RandSeries( size_t a, size_t b, size_t& seed, valarray<size_t>& sp, size_t stCount )
{   //a,b为区间左右端点，seed为种子，sp存放随机数序列，stCount指定随机数个数
	size_t stk = b - a + 1;
	size_t stl = 2;
	while(stl < stk) stl = stl + stl;
	size_t modul = 4 * stl;
	stk = seed;
	size_t sti = 0;
	while(sti < stCount)
	{
		stk = 5 * stk;
		stk = stk % modul;
		stl = stk / 4 +a;
		if (stl <= b)
		{
			sp[sti]=stl; 
			sti = sti + 1;
		}
	}
	seed=stk;
}


double AverageRandom(double min,double max)
{
	int minInteger = (int)(min*10000);
	int maxInteger = (int)(max*10000);
	int randInteger = rand()*rand();
	int diffInteger = maxInteger - minInteger;
	int resultInteger = randInteger % diffInteger + minInteger;
	return resultInteger/10000.0;
}

size_t 
Rand_ab_One(size_t a, size_t b, size_t& seed)
{			//a,b为区间左右端点，seed为种子
	size_t rand = 0 ;
	size_t stk = b - a + 1;
	size_t stl = 2;
	while(stl < stk) stl = stl + stl;
	size_t modul = 4 * stl;
	stk = seed;
	size_t sti = 1;
	while(sti <= 1)
	{
		stk = 5 * stk;
		stk = stk % modul;
		stl = stk /4 +a;
		if (stl<=b)
		{
			rand=stl; 
			sti=sti+1;
		}
	}
	seed=stk;
	return(rand);
}


//------------------------------------------------------------------------------------
void CPlayer::Activate( void )
{	
	Init();
	CGameObject::Activate();
}

//------------------------------------------------------------------------------------
//删除角色关系
//------------------------------------------------------------------------------------
bool CPlayer::DeleteRelation( const char *RelationName)
{
	std::string temstr( RelationName );
	m_RelationMgr.DeleteRelation( &temstr );
	return true;
}

//------------------------------------------------------------------------------------
//更新关系数据
//------------------------------------------------------------------------------------
eError CPlayer::UpdateRelation( RELATION &role, char &result) 
{
	//是否添加过该好友
	if ( m_RelationMgr.FindRole( &role.strName ) )
	{
		RELATION *TempRole = m_RelationMgr.GetRelationRole( &role.strName );
		result  = 0;
		if (role.Type == 0)
		{
			if ( TempRole->Type == 0)
			{
				return MSG_ERRO_0220; //该玩家已经是你的好友
			}
			else
			{
				return MSG_ERRO_0221; //该玩家已经在你的黑名单列表中
			}

		}
		else
		{
			if ( TempRole->Type == 1)
			{
				return MSG_ERRO_O224; //你已经把该玩家加入黑名单
			}
			else
			{
				return MSG_ERRO_0225; //该玩家已经在你的好友列表中
			}
		}
	}
	else
	{
		//列表是否已经满员
		if ( m_RelationMgr.IsOverFlow(role.Type) )
		{
			result  = 2;
			if (role.Type == 0)
			{
				return MSG_ERRO_0222;
			}
			return MSG_ERRO_0223;

		}
		else  if ( GetlFaction() !=  role.Camp )
		{
		    return MSG_ERRO_021F;

		}
		else
		{
			m_RelationMgr.AddRelation( role );
			result = 1;
			return NO_MSG_ERRO;
		}

	}
}


//------------------------------------------------------------------------------------
//查找角色
//------------------------------------------------------------------------------------
bool   CPlayer::FindRoleByName(  const void* pBuf )
{
	MSG_ENTER_GAME* pGameEnter = ( MSG_ENTER_GAME* )pBuf;
	map<string,UINT>::iterator  itor = m_HaveRole.find( pGameEnter->cName );
	if ( itor != m_HaveRole.end() )
	{
		RequestGameDataFromDB(  pBuf  );
		return true;
	}

	return false;
}


//------------------------------------------------------------------------------------
//角色基本数据请求
//------------------------------------------------------------------------------------
void  CPlayer::RequestBaseRoleInfoFromDB( const void* pBuf )
{
	MSG_LOGIN_GAMESERVER* pLogin = ( MSG_LOGIN_GAMESERVER* )pBuf;
	char szSQL[128]; 
	sprintf(szSQL,SQL_SELECT_ROLE_INFO, pLogin->Accounts );
	CGameObject::s_World->GetDBAddr( DB_PRI )->ExecuteAsyncSQL( szSQL,( void * )this, &CPlayer::DealWith_Select_RoleBaseInfo );
	InterlockedIncrement(&SynDBOutStand);

}


//------------------------------------------------------------------------------------
//角色添加请求
//------------------------------------------------------------------------------------
void    CPlayer::RequestAddRoleFromDB( const void* pBuf )
{
	MSG_CREATE_ROLE* pCreateRole = ( MSG_CREATE_ROLE* )pBuf;
	ROLE_ATTRIBUTE Role;
	strcpy( Role.Name, pCreateRole->Name );
	Role.ucBelief    = pCreateRole->ucBelief;
	Role.ucCamp      = pCreateRole->cCamp;
	Role.ucGender    = pCreateRole->cGender;
	Role.ucHairStyle = pCreateRole->ucHairStyle;
	Role.uProfession = pCreateRole->ucProfession;
	Role.ucFaceShap  = pCreateRole->ucFaceShap;
	Role.bIsSuccess  = false;

	MSG_MANAGE_RETURN  error;
	error.Head.usSize = sizeof(MSG_MANAGE_RETURN);
	error.Head.usType = _MSG_MANAGE_RETURN;
	error.ucErrorType = _MSG_CREATE_ROLE ;

	//长度限制
	if ( strlen( Role.Name ) > MAX_ROLENAME_SIZE   )
	{
		error.ucDisc = MSG_ERRO_0002;
		CGameObject::s_World->SendMsgToClient( &error, GetSocket() );
		return ;
	}

	//职业等级
	/*
	int F_LV,S_LV;
	if ( !Role.uProfession )
	{
	F_LV = 1;
	S_LV = 0;
	}
	else
	{
	F_LV = 0;
	S_LV = 1;
	}
	*/

	ULONG  MaxHP = CPeizhi::Instance()->GetPlayerMaxHP( 1, Role.uProfession );
	ULONG  MaxMP = CPeizhi::Instance()->GetPlayerMaxMP( 1, Role.uProfession );

	AddRole( Role );
	char szSQL[512]; 
	memset(szSQL, 0L, sizeof(szSQL));
	char *Gender = ( Role.ucGender == 1 )? "male":"female";

	//_asm int 3;
	sprintf(szSQL,SQL_SELECT_SAME_ROLE,GetAccounts(), Role.Name,Gender,Role.ucCamp,Role.uProfession,1, \
		0, 0, 0, MaxHP, MaxMP, 0, Role.ucBelief, Role.ucHairStyle,Role.ucFaceShap );//change by lion

	CGameObject::s_World->GetDBAddr( DB_NONE )->ExecuteAsyncSQL( szSQL,( void * )this, &CPlayer::DealWith_Select_CanRoleAdd );
	InterlockedIncrement(&SynDBOutStand);


}

//------------------------------------------------------------------------------------
//角色删除请求
//------------------------------------------------------------------------------------
void CPlayer::RequestDelRoleFromDB( const void* pBuf )
{
	MSG_DELETE_ROLE* pDelRole = ( MSG_DELETE_ROLE* )pBuf;
	if(! CGameObject::s_World->g_pConsortiaManager->DelRole( pDelRole->Name ) )
	{
		//向客户端发送消息，公会长如果有公会的话，不能删除
		MSG_MANAGE_RETURN  error;
		error.Head.usSize = sizeof(MSG_MANAGE_RETURN);
		error.Head.usType = _MSG_MANAGE_RETURN;
		error.ucErrorType = _MSG_DELETE_ROLE ;
		error.ucDisc = MSG_ERRO_0006;  //公会长如果有公会的话，不能删除
		CGameObject::s_World->SendMsgToClient( &error, GetSocket() );
		return;
	}
	map<string,UINT>::iterator itor = m_HaveRole.find( pDelRole->Name );
	__int64 db_ID = -1;
	if ( itor != m_HaveRole.end() )
	{
		db_ID  = itor->second;
		m_HaveRole.erase(itor);
	}
	char szSQL[128];
	sprintf( szSQL, SQL_DELETE_ROLE_INFO , db_ID );
	CGameObject::s_World->GetDBAddr( DB_NONE )->ExecuteAsyncSQL( szSQL, (void *)this , &CPlayer::DealWith_Update_RoleDel );
	InterlockedIncrement(&SynDBOutStand);
}

//------------------------------------------------------------------------------------
// 公会创建请求
//------------------------------------------------------------------------------------
void CPlayer::RequestAddConsortiaFromDB( const void* pBuf )
{
	MSG_CONSORTIA_CREATE* pDelRole = ( MSG_CONSORTIA_CREATE* )pBuf;

	char szSQL[2000];
	sprintf( szSQL, SQL_UPDATE_CONSORTIA_INFO , -1, pDelRole->ci.acName, pDelRole->ci.acTextInfo, "会长","副会长", "理事", "精英", "会员","见习会员",m_pConsortia->lfound, m_pConsortia->lbijou, m_pConsortia->iLevel, m_pConsortia->lCredit,"" );
	CGameObject::s_World->GetDBAddr( DB_NONE )->ExecuteAsyncSQL( szSQL, (void *)this , &CPlayer::DealWith_Select_CanConsortiaAdd );
	InterlockedIncrement(&SynDBOutStand);
}

//------------------------------------------------------------------------------------
//玩家登录请求数据
//------------------------------------------------------------------------------------
void CPlayer::RequestGameDataFromDB( const void* pBuf )
{
	UINT UserID = 0;
	char szSQL[128]; 
	MSG_ENTER_GAME* pGameValid = ( MSG_ENTER_GAME* )pBuf;
#ifdef GODSWAR_TESTSWITCH_ON

	UserID = atoi( pGameValid->cName );
	m_HaveRole[pGameValid->cName] =  UserID;
#else
	map<string,UINT>::iterator itor = m_HaveRole.find( pGameValid->cName );
	if ( itor !=  m_HaveRole.end() )
	{
		UserID = itor->second;

		printf("%s进入游戏:[IP:%s]\n",pGameValid->cName,m_pSocket->GetPeerIP());
	}
#endif

	dbtool::IDatabase *pDB = s_World->GetDBAddr( DB_NONE );
	if ( NULL == pDB )
		return ;

	sprintf(szSQL,SQL_SELECT_PLAYER_INFO, UserID );
	pDB->ExecuteAsyncSQL( szSQL,( void *)this, &CPlayer::DealWith_Select_RoleAttribute );
	InterlockedIncrement(&SynDBOutStand);

	sprintf(szSQL,SQL_SELECT_KITBAG_INFO, UserID );
	pDB->ExecuteAsyncSQL( szSQL,(void *)this,  &CPlayer::DealWith_Select_KitBag );
	InterlockedIncrement(&SynDBOutStand);

	sprintf(szSQL,SQL_SELECT_PASSIVEKILL_INFO, UserID );
	pDB->ExecuteAsyncSQL( szSQL,(void *)this,  &CPlayer::DealWith_Select_PassiveSkill );
	InterlockedIncrement(&SynDBOutStand);

	sprintf(szSQL,SQL_SELECT_ACTIVESKILL_INFO,UserID );
	pDB->ExecuteAsyncSQL( szSQL,(void *)this,  &CPlayer::DealWith_Select_ActiveSkill );
	InterlockedIncrement(&SynDBOutStand);
	
	sprintf(szSQL,SQL_SELECT_RELATION_INFO,UserID );
	pDB->ExecuteAsyncSQL( szSQL,(void *)this,  &CPlayer::DealWith_Select_Relation );
	InterlockedIncrement(&SynDBOutStand);

	sprintf(szSQL,SQL_SELECT_QUEST_INFO,UserID );
	pDB->ExecuteAsyncSQL( szSQL,(void *)this,  &CPlayer::DealWith_Select_Quest );
	InterlockedIncrement(&SynDBOutStand);

	sprintf(szSQL,SQL_SELECT_ALTAR_INFO,UserID );
	pDB->ExecuteAsyncSQL( szSQL,(void *)this,  &CPlayer::DealWith_Select_Altar );
	InterlockedIncrement(&SynDBOutStand);


}


//------------------------------------------------------------------------------------
//添加角色基本
//------------------------------------------------------------------------------------
void   CPlayer::DealWith_Select_CanRoleAdd( dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
		return;
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	MSG_MANAGE_RETURN  error;
	error.Head.usSize = sizeof(MSG_MANAGE_RETURN);
	error.Head.usType = _MSG_MANAGE_RETURN;
	error.ucErrorType = _MSG_CREATE_ROLE ;
	error.ucDisc = MSG_ERRO_0005;             //已经被注册

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		CGameObject::s_World->SendMsgToClient( &error, pPlayer->GetSocket() );
		return ;
	}


	//int RecordCount = pRes->CountRecord();

	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
		return ;
	//__int64 id1 = Record->Field( UINT( 0 ) );
	const char *RoleName = Record->Field( 1 );
	__int64 LastID = Record->Field( 2 );
	__int64 id = Record->Field( 3 );





	map<string,ROLE_ATTRIBUTE>::iterator  itor = pPlayer->m_AddRole.find( RoleName );

	if ( id >= 1 )
	{
		if ( itor != pPlayer->m_AddRole.end() )
		{
			pPlayer->m_AddRole.erase( itor );
			error.ucDisc = MSG_ERRO_0005;           //已经被注册
		}


	}
	else if	( id == 0 )
	{ 
		//插入已有角色
		pPlayer->m_HaveRole[RoleName] = LastID;

		if ( itor != pPlayer->m_AddRole.end() )
		{
			itor->second.bIsSuccess = true;
		}
		error.ucDisc = MSG_ERRO_0001;


	}
	CGameObject::s_World->SendMsgToClient( &error, pPlayer->GetSocket() );

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//------------------------------------------------------------------------------------
// 能否创建工会
//------------------------------------------------------------------------------------
void CPlayer::DealWith_Select_CanConsortiaAdd( dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
		return;
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
		return ;

	UINT LastID = Record->Field( 1 );

	ConsortiaLevelUp *Basefound = pPlayer->s_World->g_pConsortiaManager->GetConsortiaLevelUp( 1);
	MSG_CONSORTIA_CREATE_RESPONSE  Response;
	Response.Head.usSize = sizeof( MSG_CONSORTIA_CREATE_RESPONSE );
	Response.Head.usType = _MSG_CONSORTIA_CREATE_RESPONSE;
	Response.Style = 0;
	memcpy( Response.ci.acChairman, pPlayer->GetName(), 32 );
	memcpy( Response.ci.acName, pPlayer->GetConsortia(), 32 );
	memcpy( Response.ci.acTextInfo, pPlayer->GetConsortia()->acTextInfo, 32 );
	Response.ci.iLevel = 1;
	Response.ci.lCredit = 0;    //这个数字需要动态赋值 目前先放着
	Response.ci.AltarCounts = 0;//这个数字需要动态赋值 目前先放着
	Response.ci.MaxMember = 50; //这个数字需要动态赋值 目前先放着
	Response.ci.lfound = Basefound->lfound;
	Response.ci.lbijou = Basefound->lbijou;
	Response.cm.acDuty = CONSORTIA_CHAIRMAN;
	memcpy( Response.cm.acMemberName, pPlayer->GetName(), 32 );
	Response.cm.iLevel = pPlayer->GetcRank();
	Response.cm.lMapID = CGameObject::s_World->GetRegionFromLogicID(pPlayer->GetlRegionID())->GetID();
	Response.cm.lPlayerID = pPlayer->GetID();
	Response.uiPlayerID = pPlayer->GetID();


	if ( LastID == -1 )
	{
		ASSERT(0);
	}  
	else 
	{
		//改变公会ID
		pPlayer->GetConsortia()->uiID = LastID; 

		//添加新成员
		ConsortiaRelationElem temp;
		temp.strName = pPlayer->GetName();
		temp.Job = CONSORTIA_CHAIRMAN;
		temp.LV = pPlayer->GetcRank();
		temp.lMapID = CGameObject::s_World->GetRegionFromLogicID(pPlayer->GetlRegionID())->GetID();
		temp.ucBusiness = pPlayer->GetlClass();
		temp.uiContribute = pPlayer->GetuiUionContribute();
		 CGameObject::s_World->g_pConsortiaManager->Add( pPlayer->GetConsortia(), temp );
		memset( &temp, 0L, sizeof(ConsortiaRelationElem) );
		pPlayer->SetcUnion( LastID );
		pPlayer->SetcUnionBusiness( CONSORTIA_CHAIRMAN );
		CGameObject::s_World->SendMsgToClient( &Response, pPlayer->GetSocket() );
		pPlayer->ReflashUnavilableVec();
	}	

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//------------------------------------------------------------------------------------
// 任务数据处理
//------------------------------------------------------------------------------------
void CPlayer::DealWith_Select_Quest( dbtool::PSQL_RESULT result )
{
	enum { DB_ID, DB_ALLQUEST, DB_ACTIVEQUEST, DB_TIMEQUEST, DB_PROFESSION, DB_CAMP, DB_LV,DB_SLV, DB_BELIEF };
	if ( result->Falg == NULL )
	{
		return ;
	}

	// 	IF_NOT( result ) 
	// 		return;
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	int RecordCount = pRes->CountRecord();

	if ( RecordCount == 1)
	{
		pRes->Move( 0 );
		dbtool::IRecord *Record = pRes->GetRecord();
		IF_NOT( Record )
			return ;

		//UINT ID = Record->Field( UINT( DB_ID ) );
		char* AllQuest= Record->Field( DB_ALLQUEST );
		char* ActiveQuest = Record->Field( DB_ACTIVEQUEST );
		char* TimeQuest = Record->Field( DB_TIMEQUEST );

		pPlayer->SetlClass( BYTE(  Record->Field( DB_PROFESSION ) ));
		pPlayer->SetlFaction( BYTE(  Record->Field( DB_CAMP ) ));
		pPlayer->SetcRank( BYTE(  Record->Field( DB_LV ) ));
		pPlayer->SetusBelief( (USHORT)(  Record->Field( DB_BELIEF ) ));

		pPlayer->CreateAllQuestFromDB( AllQuest ) ;
		pPlayer->CreateTimeQuestFromDB( ActiveQuest, TIME_ACCEPT  );
		pPlayer->CreateTimeQuestFromDB( TimeQuest, TIME_NO_ACCEPT  );
	}
	else 
	{
		return;
	}

	//pPlayer->OnProcess_KitBag( pPlayer );

	pPlayer->LoadQuest();

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();

}

//------------------------------------------------------------------------------------
//角色基本数据处理
//------------------------------------------------------------------------------------
void CPlayer::DealWith_Select_RoleBaseInfo( dbtool::PSQL_RESULT result )
{

	IF_NOT( result ) 
		return;
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	int RecordCount = pRes->CountRecord();

	//得到被动技能数据
	dbtool::IRecord *tempRecord;
	MSG_ROLE_INFO   RoleInfo ;
	int i;
	memset( &RoleInfo,0L,sizeof(MSG_ROLE_INFO) );

	char *Gender;
	string Name("");
	for ( i = 0; i < RecordCount; i++ )
	{   
		pRes->Move( i );
		tempRecord  = pRes->GetRecord();
		if ( i == 0 )
		{
			Name = (char *)tempRecord->Field( UINT(0) );
			strcpy( RoleInfo.Name, Name.c_str() );
			Gender   = tempRecord->Field( 1 );
			if ( !strcmp( Gender,"male") )
			{
				RoleInfo.ucGender = 1;
			}
			else if ( !strcmp( Gender,"female") )
			{
				RoleInfo.ucGender = 0;
			}
			RoleInfo.cCamp = tempRecord->Field( 2 );
			RoleInfo.ucLV  = tempRecord->Field( 3 );
			RoleInfo.ucProfession = tempRecord->Field( 4 );//by lion 职业
			//			RoleInfo.ucScholarLV  = tempRecord->Field( 4 );
			RoleInfo.ucHairStyle  = tempRecord->Field( 5 );
			RoleInfo.ucFaceShap = tempRecord->Field( 6 );
			for ( int a = 0; a < MAX_EQUIP_COUNT; a++ )
			{
				RoleInfo.iEquip[ a ]  = (long)tempRecord->Field( 8 + a );
			}


		}
		else if ( i == 1 )
		{
			Name = (char *)tempRecord->Field( UINT(0) );
			strcpy( RoleInfo.Name1, Name.c_str() );
			Gender   = tempRecord->Field( 1 );
			if ( !strcmp( Gender,"male") )
			{
				RoleInfo.ucGender1 = 1;
			}
			else if ( !strcmp( Gender,"female") )
			{
				RoleInfo.ucGender1 = 0;
			}
			RoleInfo.cCamp1 = tempRecord->Field( 2 );
			RoleInfo.ucLV1  = tempRecord->Field( 3 );
			RoleInfo.ucProfession1 = tempRecord->Field( 4 );//by lion 职业
			//			RoleInfo.ucScholarLV1  = tempRecord->Field( 4 );
			RoleInfo.ucHairStyle1  = tempRecord->Field( 5 );
			RoleInfo.ucFaceShap1 = tempRecord->Field( 6 );
			for ( int a = 0; a < MAX_EQUIP_COUNT; a++ )
			{
				RoleInfo.iEquip1[ a ]  = (long)tempRecord->Field( 8 + a );
			}
		}
		else if ( i == 2 )
		{
			Name = (char *)tempRecord->Field( UINT(0) );
			strcpy( RoleInfo.Name2, Name.c_str() );
			Gender   = tempRecord->Field( 1 );
			if ( !strcmp( Gender,"male") )
			{
				RoleInfo.ucGender2 = 1;
			}
			else if ( !strcmp( Gender,"female") )
			{
				RoleInfo.ucGender2 = 0;
			}
			RoleInfo.cCamp2 = tempRecord->Field( 2 );
			RoleInfo.ucLV2  = tempRecord->Field( 3 );
			RoleInfo.ucProfession2 = tempRecord->Field( 4 );//by lion 职业
			//			RoleInfo.ucScholarLV2  = tempRecord->Field( 4 );
			RoleInfo.ucHairStyle2  = tempRecord->Field( 5 );
			RoleInfo.ucFaceShap2 = tempRecord->Field( 6 );
			for ( int a = 0; a < MAX_EQUIP_COUNT; a++ )
			{
				RoleInfo.iEquip2[ a ]  = (long)tempRecord->Field( 8 + a );
			}
		}
		else if ( i == 3 )
		{
			Name = (char *)tempRecord->Field( UINT(0) );
			strcpy( RoleInfo.Name3, Name.c_str() );
			Gender   = tempRecord->Field( 1 );
			if ( !strcmp( Gender,"male") )
			{
				RoleInfo.ucGender3 = 1;
			}
			else if ( !strcmp( Gender,"female") )
			{
				RoleInfo.ucGender3 = 0;
			}
			RoleInfo.cCamp3 = tempRecord->Field( 2 );
			RoleInfo.ucLV3  = tempRecord->Field( 3 );
			RoleInfo.ucProfession3 = tempRecord->Field( 4 );//by lion 职业
			//			RoleInfo.ucScholarLV3  = tempRecord->Field( 4 );
			RoleInfo.ucHairStyle3  = tempRecord->Field( 5 );
			RoleInfo.ucFaceShap3 = tempRecord->Field( 6 );
			for ( int a = 0; a < MAX_EQUIP_COUNT; a++ )
			{
				RoleInfo.iEquip3[ a ]  = (long)tempRecord->Field( 8 + a );
			}
		}
		UINT DB_id = tempRecord->Field( 7 );
		pPlayer->m_HaveRole[Name] =  DB_id;
	}

	RoleInfo.Head.usType  =  _MSG_ROLE_INFO;
	RoleInfo.Head.usSize  =  sizeof( MSG_ROLE_INFO ) ;
	RoleInfo.ucNum        =  i ;

	CGameObject::s_World->SendMsgToClient( &RoleInfo, pPlayer->GetSocket( ) );
	pPlayer->SetWorldStatus( eROLELOGIN );

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();


}


//------------------------------------------------------------------------------------
//背包数据处理
//------------------------------------------------------------------------------------
void CPlayer::DealWith_Select_KitBag(dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
		return;
	// 
	// 	IF_NOT( result->Falg )  //写数据库失败
	// 		return;
	if ( result->Falg == NULL )
	{
		return ;
	}

	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	int RecordCount = pRes->CountRecord();

	if ( RecordCount == 1)
	{
		pRes->Move( 0 );
		dbtool::IRecord* rec = pRes->GetRecord();
		for ( int i = 0; i < 5; i++ )                       
		{
			char *EquipInfo=(char *)rec->Field( UINT(i) );  //道具栏1
			//__asm int 3;
			if (  pPlayer->CreatePropFromDB( EquipInfo, i ) )
			{
				//产生装备的处理
			}
		}
	}
	else 
	{
		//发送无装备信息
	}

	pPlayer->OnProcess_KitBag( pPlayer );

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();

}


//------------------------------------------------------------------------------------
//被动技能数据处理
//------------------------------------------------------------------------------------
void CPlayer::DealWith_Select_PassiveSkill(dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
		return;
	// 	IF_NOT( result->Falg )  //写数据库失败
	// 		return;

	if ( result->Falg == NULL )
	{
		return ;
	}

	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	int RecordCount = pRes->CountRecord();

	//得到被动技能数据
	dbtool::IRecord *tempRecord;
	for ( int i = 0; i < RecordCount; i++ )
	{   
		pRes->Move( i);
		tempRecord = pRes->GetRecord();
		char * DBString = tempRecord->Field( UINT(0) );
		pPlayer->CreatePassiveSkillFromDB( DBString );

	}
	pPlayer->OnProcess_PassiveSkill( pPlayer );

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}


//------------------------------------------------------------------------------------
//主动技能数据处理
//------------------------------------------------------------------------------------
void CPlayer::DealWith_Select_ActiveSkill(dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
		return;
	// 	IF_NOT( result->Falg )  //写数据库失败
	// 		return;

	if ( result->Falg == NULL )
	{
		return ;
	}

	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);

	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;
	int RecordCount = pRes->CountRecord();

	//得到主动技能数
	dbtool::IRecord *tempRecord;
	for ( int i = 0; i < RecordCount; i++ )
	{
		pRes->Move( i);
		tempRecord = pRes->GetRecord();
		char * DBString = tempRecord->Field( UINT(0) );
		pPlayer->CreateActiveSkillFromDB( DBString );	
	}
	pPlayer->OnProcess_ActiveSkill( pPlayer );

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();


}
//----------------------------------------------------------------------------------
//供奉祭坛处理
//-----------------------------------------------------------------------------------
void CPlayer::DealWith_Select_Altar(dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
		return;

	if ( result->Falg == NULL )
	{
		return ;
	}

	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	dbtool::IRecord *tempRecord;
	int RecordCount = pRes->CountRecord();
	if (RecordCount == 0)
	{
		return;
	}
	pRes->Move( 0);
	tempRecord = pRes->GetRecord();
	if (!tempRecord)
	{
		return;
	}
	for ( int i = 1; i< pRes->FieldsCount(); i++ )
	{

		pPlayer->InitAltar(i,(UINT)tempRecord->Field(UINT(i)));
		
	}
	pPlayer->SendAltarMsg();

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();

}
//------------------------------------------------------------------------------------
//社会关系处理
//------------------------------------------------------------------------------------
void CPlayer::DealWith_Select_Relation(dbtool::PSQL_RESULT result )
{
	//__asm int 3;
	IF_NOT( result ) 
		return;
	// 	IF_NOT( result->Falg )  //d数据库失败
	// 		return;
	if ( result->Falg == NULL )
	{
		return ;
	}

	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	dbtool::IRecord *tempRecord;
	int RecordCount = pRes->CountRecord();
	for ( int i = 0; i<RecordCount; i++ )
	{
		RELATION Relation;
		pRes->Move( i);
		tempRecord = pRes->GetRecord();
		Relation.strName = (char*)tempRecord->Field(UINT(0));
		Relation.Business = (BYTE)tempRecord->Field(1);
		Relation.Camp = (BYTE)tempRecord->Field(2);
		Relation.City = (BYTE)tempRecord->Field(3);
		Relation.LV = (BYTE)tempRecord->Field(4);
		//		Relation.S_LV = (BYTE)tempRecord->Field(5);
		Relation.Type = (BYTE)tempRecord->Field(6) == 0? TYPE_FRIEND: TYPE_BLACKLIST;
		char Result = 0;
		pPlayer->UpdateRelation( Relation, Result );	
	}
	pPlayer->SendRelationMsg();

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();

}

//------------------------------------------------------------------------------------
//基本属性处理
//------------------------------------------------------------------------------------
void CPlayer::DealWith_Select_RoleAttribute( dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
		return;
	// 	IF_NOT( result->Falg )  //读数据库失败
	// 		return;

	if ( result->Falg == NULL )
	{
		return ;
	}

	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	int RecordCount = pRes->CountRecord();

	if(0 == RecordCount ) 
	{
		pPlayer->SetActive( false );
		return ;
	}
	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
		return ;

	//装备
	char *Equip = Record->Field( UINT(CHARACTER_EQUIP));
	pPlayer->CreatePropFromDB( Equip, 5 );

	//GM
	pPlayer->SetGM( !!(BYTE)Record->Field( CHARACTER_GMFLAG) );

	//UINT id = Record->Field( UINT( CHARACTER_ID ) );

	//将读出来的数据赋值给内部结构体
	char * Name = Record->Field( CHARACTER_NAME );
	pPlayer->SetName( Name );

	pPlayer->SetRegisterTime( Record->Field( CHARACTER_REGISTER_TIME ) );
	pPlayer->SetOnlineTime( Record->Field( CHARACTER_MUTE_TIME ));

	char *Gender = Record->Field( CHARACTER_GENDER );

	if ( !strcmp( Gender,"male") )
	{
		pPlayer->m_ObjectData.m_Gender =  1;
	}
	else if ( !strcmp( Gender,"female") )
	{
		pPlayer->m_ObjectData.m_Gender =  0;
	}

	pPlayer->m_ObjectData.m_lFaction      		    =    (BYTE)Record->Field( CHARACTER_CAMP );
	pPlayer->m_ObjectData.m_lPrestige     		    =    (USHORT)Record->Field( CHARACTER_PRESTIGE );
	pPlayer->m_ObjectData.m_cKnight       		    =    (BYTE)Record->Field( CHARACTER_EARL_RANK );
	pPlayer->m_ObjectData.m_cUnion        		    =     Record->Field( CHARACTER_CONSORTIA );
	pPlayer->m_ObjectData.m_cUnionBusiness		    =    (BYTE)Record->Field( CHARACTER_CONSORTIA_JOB );
	pPlayer->m_ObjectData.m_uiUionContribute		=    (UINT)Record->Field( CHARACTER_CONSORTIA_CONTRIBUTE );
	pPlayer->m_ObjectData.m_uiStoreNum				=    (UINT)Record->Field( CHARACTER_STORE_NUM );
	pPlayer->m_ObjectData.m_uiBagNum				=    (UINT)Record->Field( CHARACTER_BAG_NUM );
	pPlayer->m_ObjectData.m_lClass			        =    (BYTE)Record->Field( CHARACTER_PROFESSION );
	pPlayer->m_ObjectData.m_cExp                    =    (UINT)Record->Field( CHARACTER_EXP );
	pPlayer->m_ObjectData.m_cRank                   =    (BYTE)Record->Field( CHARACTER_LV );
	pPlayer->m_ObjectData.m_lHP				        =    (UINT)Record->Field( CHARACTER_HP_CUR );
	pPlayer->m_ObjectData.m_lMP				        =    (UINT)Record->Field( CHARACTER_MP_CUR );
	pPlayer->m_ObjectData.m_usAttackDistance        =    1;           //裸人默认值
	pPlayer->m_ObjectData.m_usAttackSpeed           =    1500;         //裸人默认值
	pPlayer->m_ObjectData.m_cHairStyle              =    (BYTE)Record->Field( CHARACTER_HAIRSTYLE );  
	pPlayer->m_ObjectData.m_cPupilColor             =    (BYTE)Record->Field( CHARACTER_FACESHAP );
	pPlayer->m_ObjectData.m_lRegionID               =    (BYTE)Record->Field( CHARACTER_CURMAP );  
	pPlayer->m_ObjectData.m_fX                      =    (float)Record->Field( CHARACTER_CURPOS_X );
	pPlayer->m_ObjectData.m_fZ                      =    (float)Record->Field( CHARACTER_CURPOS_Z );
	pPlayer->m_ObjectData.m_lMoney                  =    (UINT)Record->Field( CHARACTER_MONEY );
	pPlayer->m_ObjectData.m_lStone                  =    (UINT)Record->Field( CHARACTER_STONE );
	pPlayer->m_ObjectData.m_usBelief                =    (USHORT)Record->Field( CHARACTER_BELIFE );
	pPlayer->SetBaselMaxHP( (UINT)Record->Field( CHARACTER_MAXHP ) );                     
	pPlayer->SetBaselMaxMP( (UINT)Record->Field( CHARACTER_MAXMP ) );                        

	pPlayer->SetSkillPoint( (UINT)Record->Field( CHARACTER_SKILLPOINT ) );
	pPlayer->SetSkillExp( (UINT)Record->Field( CHARACTER_SKILLEXP ) ) ;

	//防止玩家意外进入档格容错处理
	if ( pPlayer->m_ObjectData.m_fX <= -240.f || pPlayer->m_ObjectData.m_fX >=  240.0f 
		|| pPlayer->m_ObjectData.m_fZ <= -240.f || pPlayer->m_ObjectData.m_fZ >=  240.0f )
	{
		if ( pPlayer->m_ObjectData.m_lFaction  == 0 )
		{
			pPlayer->m_ObjectData.m_fX  =   CGameObject::s_World->GetRegionFromLogicID( pPlayer->GetlRegionID() )->GetSpartaRevival()->X;
			pPlayer->m_ObjectData.m_fZ  =   CGameObject::s_World->GetRegionFromLogicID( pPlayer->GetlRegionID() )->GetSpartaRevival()->Z;
		}
		else
		{
			pPlayer->m_ObjectData.m_fX  =  CGameObject::s_World->GetRegionFromLogicID( pPlayer->GetlRegionID() )->GetAthensRevival()->X;
			pPlayer->m_ObjectData.m_fZ =   CGameObject::s_World->GetRegionFromLogicID( pPlayer->GetlRegionID() )->GetAthensRevival()->Z;
		}
	}

	pPlayer->SetAtttibute( );
	pPlayer->SetNextGradeEXP( );
	pPlayer->m_DBID = pPlayer->m_HaveRole[Name];
	_asm
	{
		mov  eax,pPlayer
			push CGameObject::s_World
			push pPlayer
			mov  ebx,[eax]pPlayer.OnProcess_Attribute
			call ebx
			add  esp, 8
	}
	pPlayer->m_MsgFlag[MSG_ATTRIBUTE_FLAG] = true;
	
	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}


//-----------------------------------------------------------------------------------
//更新角色属性返回
//-----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_RoleAttribute( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update role attribute failed! "<<endl;
	}
	else
	{
		//cout<<pPlayer->GetAccounts()<<"Update role attribute success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//-----------------------------------------------------------------------------------
//更新背包装备返回
//-----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_KitBag( dbtool::PSQL_RESULT result )
{

	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update kitbag failed! "<<endl;
	}
	else
	{
		//cout<<pPlayer->GetAccounts()<<"Update role kitbag success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//-----------------------------------------------------------------------------------
//更新主动技能返回
//-----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_ActiveSkill( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update active skill failed! "<<endl;
	}
	else
	{
		cout<<pPlayer->GetAccounts()<<"Update active skill success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//-----------------------------------------------------------------------------------
//更新被动技能返回
//-----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_PassiveSkill( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update passive skill failed! "<<endl;
	}
	else
	{
		cout<<pPlayer->GetAccounts()<<"Update passive skill success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//-----------------------------------------------------------------------------------
//更新社会关系返回
//-----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_Relation( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update relation failed! "<<endl;
	}
	else
	{
		// cout<<pPlayer->GetAccounts()<<"Update relation success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}


//-----------------------------------------------------------------------------------
//删除角色返回
//-----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_RoleUpate( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update  role info  failed! "<<endl;
	}
	else
	{
		cout<<pPlayer->GetAccounts()<<"Update  role info  success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}


//-----------------------------------------------------------------------------------
//删除角色返回
//-----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_RoleDel( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update delete role failed! "<<endl;
		//向客户端发送消息
		MSG_MANAGE_RETURN  error;
		error.Head.usSize = sizeof(MSG_MANAGE_RETURN);
		error.Head.usType = _MSG_MANAGE_RETURN;
		error.ucErrorType = _MSG_DELETE_ROLE ;
		error.ucDisc = MSG_ERRO_0007;  //删除角色失败
		CGameObject::s_World->SendMsgToClient( &error, pPlayer->GetSocket() );
	}
	else
	{	
		//向客户端发送消息
		MSG_MANAGE_RETURN  error;
		error.Head.usSize = sizeof(MSG_MANAGE_RETURN);
		error.Head.usType = _MSG_MANAGE_RETURN;
		error.ucErrorType = _MSG_DELETE_ROLE ;
		error.ucDisc = MSG_ERRO_0008;  //删除角色成功
		CGameObject::s_World->SendMsgToClient( &error, pPlayer->GetSocket() );
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//----------------------------------------------------------------------------------
// 更新好友信息
//----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_Friend( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}
	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update Friend failed! "<<endl;
	}
	else
	{
		cout<<pPlayer->GetAccounts()<<"Update Friend success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//----------------------------------------------------------------------------------
// 更新黑名单信息
//----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_BlackList( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}
	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update BlackList failed! "<<endl;
	}
	else
	{
		cout<<pPlayer->GetAccounts()<<"Update BlackList success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}


//----------------------------------------------------------------------------------
// 离线更新工会信息
//----------------------------------------------------------------------------------
void CPlayer::DealWith_Offline_Update_Uinon( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
		return ;

	int RecordCount = pRes->CountRecord();

	if( 0 == RecordCount ) 
		return ;

	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
		return ;
	//公会
	char Success = Record->Field( (UINT)0 );
	const char* RoleName = Record->Field( 1 );
	char  OldDuty = Record->Field( 2 );
	BYTE  NewDuty = Record->Field( 3 );
	UINT  Union   = Record->Field( 4 );
	if (  Success == 1 )
	{
		if ( CONSORTIA_NONE == NewDuty  )
		{
			//向所有成员广播玩家被提出公会的消息
			MSG_CONSORTIA_MEMBER_DEL  BeDel;
			memset(&BeDel, 0L, sizeof(BeDel) );
			BeDel.Head.usSize = sizeof( MSG_CONSORTIA_MEMBER_DEL );
			BeDel.Head.usType = _MSG_CONSORTIA_MEMBER_DEL;
			strcpy( BeDel.strName, RoleName );
			pPlayer->BroadcastConsortiaMsg( &BeDel );
			 CGameObject::s_World->g_pConsortiaManager->Del( pPlayer->GetConsortia(), RoleName );
			//更新公会成员列表
			pPlayer->BroadcastConMemberInfo();
		}
		else
		{
			MSG_CONSORTIA_DUTY  consortia_duty;
			consortia_duty.Head.usSize = sizeof( MSG_CONSORTIA_DUTY );
			consortia_duty.Head.usType = _MSG_CONSORTIA_DUTY; 
			strcpy( consortia_duty.OldName, pPlayer->GetName() );
			consortia_duty.OldDuty = OldDuty;
			strcpy( consortia_duty.NewName,RoleName );
			consortia_duty.NewDuty  = NewDuty;

			//向所有成员发送修改公告消息  
			pPlayer->BroadcastConsortiaMsg( &consortia_duty );
		}

	}
	else 
	{
		cout<<"Change consortia duty failed! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();

}

//----------------------------------------------------------------------------------
// 更新公会信息
//----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_Consortia( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update BlackList failed! "<<endl;
	}
	else
	{
		cout<<pPlayer->GetAccounts()<<"Update BlackList success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//----------------------------------------------------------------------------------
//任务信息
//----------------------------------------------------------------------------------
void CPlayer::DealWith_Update_Quest( dbtool::PSQL_RESULT result )
{
	CPlayer *pPlayer = static_cast< CPlayer * >(result->pPlayer);
	if ( pPlayer == NULL )
	{
		return ;
	}

	InterlockedDecrement(&pPlayer->SynDBOutStand);
	if ( !result->Falg &&  !result )
	{
		cout<<pPlayer->GetAccounts()<<"Update Quest failed! "<<endl;
	}
	else
	{
		cout<<pPlayer->GetAccounts()<<"Update Quest success! "<<endl;
	}

	if ( pPlayer->WillRelease && pPlayer->SynDBOutStand == 0 )
		pPlayer->RealActive();
}

//------------------------------------------------------------------------------------
//缓存校验码
//------------------------------------------------------------------------------------
void    CPlayer::CacheValidCode( string Accounts, string Valid  )
{
	sbase::CSingleLock xLock(&g_xLock);
	m_valid_map[Accounts]  = Valid;

}

//------------------------------------------------------------------------------------
//缓存校验码
//------------------------------------------------------------------------------------
void CPlayer::CacheSocket(  snet::CSocket* PSocket, string strAccounts )
{
	if ( m_valid_map.find( strAccounts) != m_valid_map.end() )
	{
		m_Soket_map[ PSocket] = strAccounts;
	}

}

//------------------------------------------------------------------------------------
//验证
//------------------------------------------------------------------------------------
bool   CPlayer::ValidateLogin( string validcode )
{
	return  ( validcode == m_valid )? true: false;
}

//------------------------------------------------------------------------------------
//得到验证码
//------------------------------------------------------------------------------------
string   CPlayer::GetValidCode( string Accounts )
{
	map< string, string >::iterator  itor = m_valid_map.find( Accounts ) ; 
	if ( itor != m_valid_map.end() )
	{
		return itor->second;
	}

	return string("");
}

//------------------------------------------------------------------------------------
//清除验证码
//------------------------------------------------------------------------------------
void CPlayer::ClearValidCode(  snet::CSocket* PSocket )
{

	string Accounts("");
	map<  snet::CSocket*, string >::iterator  itor = m_Soket_map.find( PSocket ) ; 
	if ( itor != m_Soket_map.end() )
	{

		Accounts = itor->second;
		m_Soket_map.erase( itor );
	}	

	sbase::CSingleLock xLock1(&g_xLock);
	map< string, string >::iterator  itor1 = m_valid_map.find( Accounts ) ; 
	if ( itor1 != m_valid_map.end() )
	{
		m_valid_map.erase( itor1 );
	}
}

//------------------------------------------------------------------------------------
//得到验证码
//------------------------------------------------------------------------------------
void   CPlayer::AddRole( ROLE_ATTRIBUTE Role )
{
	m_AddRole[ Role.Name ]  =  Role;
}

//------------------------------------------------------------------------------------
//得到验证码
//------------------------------------------------------------------------------------
void   CPlayer::SelectRole( string Name )
{

}

//------------------------------------------------------------------------------------
//得到验证码
//------------------------------------------------------------------------------------
void    CPlayer::DelRole( string Name )
{
	m_DeleteRole.push_back( Name );
	char szSQL[128];
	sprintf( szSQL, SQL_DELETE_ROLE_INFO , Name.c_str() );
	CGameObject::s_World->GetDBAddr( DB_NONE )->ExecuteAsyncSQL( szSQL, (void *)this , &CPlayer::DealWith_Update_RoleDel );
	InterlockedIncrement(&SynDBOutStand);
}

void	CPlayer::SetSkillMsg( MSG_SKILL* pSkillMsg )
{
	memcpy( &m_SkillMsg, pSkillMsg, sizeof( MSG_SKILL ) );
}

//----------------------------------------------------------------------------------
// 备份数据
//----------------------------------------------------------------------------------
bool  CPlayer::BackUp()
{
// 	if (  CGameObject::s_World->g_pBackUpMgr->GetStatus() )
// 	{
		if ( GetJoinFlag() )
		{
			BackUP_RoleAttribute();
			BackUp_KitBag();
			BackUp_ActiveSkill();
			BackUp_PassiveSkill();
			BackUp_Relation();
			BackUp_Quest();
		}
		return true;
//	}
    sbase::ConsoleWriteColorText( FOREGROUND_GREEN,"%s玩家数据保存" ,GetName());
	return false;
}

bool  CPlayer::BackUP_RoleAttribute( void )
{
	//更新进入游戏角色数据
	//int SendLength = 0;
	static BACKUP_MSG  Msg;
	memset( &Msg,0L,sizeof(Msg) );
	Msg.Head.usType = TYPE_ROLE_ATTRIBUTE;
	
	strcpy( Msg.SQL, this->PackRoleAttribute() );
	if ( strlen( Msg.SQL )  == 0  )
	{
		return false;
	}
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	//CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	//CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize,SendLength);

	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );
	

	return true;

}

bool  CPlayer::BackUp_ActiveSkill( void )
{
	if ( !IsMsgOK( MSG_SKILL_ACTIVE_FLAG ) )
	{
		return false;
	}

	//int SendLength = 0;
	static BACKUP_MSG  Msg;
	memset( Msg.SQL,0L,sizeof(Msg.SQL));

	Msg.Head.usType = TYPE_ROLE_ACTIVESKILL;
	strcpy( Msg.SQL, this->PackActiveSkill() );
	if ( strlen( Msg.SQL )  == 0  )
	{
		return false ;
	}
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );

	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength  );

	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );

	return true;
}

bool  CPlayer::BackUp_PassiveSkill( void )
{
	if ( !IsMsgOK( MSG_SKILL_ACTIVE_FLAG ) )
	{
		return false;
	}

	//int SendLength = 0;
	static BACKUP_MSG  Msg;
	memset( Msg.SQL,0L,sizeof(Msg.SQL));
	Msg.Head.usType = TYPE_ROLE_PASSIVESKILL;
	strcpy( Msg.SQL, this->PackPassiveSkill() );
	if ( strlen( Msg.SQL )  == 0  )
	{
		return false ;
	}
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );

	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength  );
	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );
	return true;
}

bool  CPlayer::BackUp_Relation( void )
{
	//int SendLength = 0;
	static BACKUP_MSG  Msg;
	memset( Msg.SQL,0L,sizeof(Msg.SQL));

	//好友 
	if ( !IsMsgOK( MSG_RELATION_FRIENDS_FLAG ))
	{
		goto BlckList;
	}

	Msg.Head.usType = TYPE_ROLE_FRIEND;
	strcpy( Msg.SQL, this->PackFriendInfo() );
	if ( strlen( Msg.SQL )  == 0  )
	{
		goto BlckList;
	}
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength  );

	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );
	
	//黑名单

BlckList:	
	if ( !IsMsgOK( MSG_RELATION_BLACKLIST_FLAG ))
	{
		goto Consortia;
	}
	memset(&Msg.SQL, 0, sizeof(Msg.SQL));
	Msg.Head.usType = TYPE_ROLE_BLACKLIST;
	strcpy( Msg.SQL, this->PackBackList() );
	if ( strlen( Msg.SQL )  == 0  )
	{
		goto Consortia;
	}
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	// CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength );
	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );
	 

	//公会
Consortia: 	
	if ( !IsMsgOK( MSG_RELATION_CONSORTIA_FLAG ))
	{
		goto Altar;
	}
	memset(&Msg.SQL, 0, sizeof(Msg.SQL));
	Msg.Head.usType = TYPE_ROLE_CONSORTIA;
	strcpy( Msg.SQL, this->PackConsortiaInfo() );
	if ( strlen( Msg.SQL )  == 0  )
	{
		goto Altar;
	}
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength  );
	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );
	 

	//祭坛
Altar:
	if ( !IsMsgOK( MSG_ALTAR_FLAG ))
	{
		return false;
	}
	Msg.Head.usType = TYPE_ROLE_ALTAR;
	memset(Msg.SQL,0L,sizeof(Msg.SQL));
	strcpy( Msg.SQL, this->PackAltarInfo() );
	if ( 0 == strlen(Msg.SQL)  )
	{
		return false;
	}
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength  );
	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );
	return true;
}

bool  CPlayer::BackUp_KitBag( void )
{
	if ( !IsMsgOK( MSG_KITBAG_FLAG ) )
	{
		return false;
	}

	//int SendLength = 0;
	static BACKUP_MSG  Msg;
	memset( Msg.SQL,0L,sizeof(Msg.SQL));

	for ( int index =  0; index < MAX_BAGS; index++ )
	{
		strcpy( Msg.SQL, PackBagkitInfo( index  ) );
		if ( strlen( Msg.SQL )  == 0  )
		{
			continue ;
		}
		if ( index == 0 )
		{
			Msg.Head.usType = TYPE_ROLE_KITBAG1;
		}
		else if ( index == 1 )
		{
			Msg.Head.usType = TYPE_ROLE_KITBAG2;
		}
		else if ( index == 2 )
		{
			Msg.Head.usType = TYPE_ROLE_KITBAG3;
		}
		else if ( index == 3  )
		{
			Msg.Head.usType = TYPE_ROLE_KITBAG4;
		}

		Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
		//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
		 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
		 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength  );
		CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );

		memset(&Msg.SQL, 0, sizeof(Msg.SQL));
	}

	memset(&Msg.SQL, 0, sizeof(Msg.SQL));
	Msg.Head.usType = TYPE_ROLE_STORAGE;
	strcpy( Msg.SQL, PackStorageInfo() );
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize,SendLength );
	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );
	
	memset(&Msg.SQL, 0, sizeof(Msg.SQL));
	Msg.Head.usType = TYPE_ROLE_EQUIP;
	strcpy( Msg.SQL, PackEquipInfo() );
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength  );
	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );

	return true;
}


bool  CPlayer::BackUp_Quest( void )
{
	static  BACKUP_MSG  Msg;
	//int SendLength = 0;
	Msg.Head.usType = TYPE_ROLE_QUEST;
	memset( Msg.SQL,0L,sizeof(Msg.SQL));
	strcpy( Msg.SQL, this->PackQuest()  );
	Msg.Head.usSize = sizeof(MsgHead)+strlen( Msg.SQL );
	//Msg.Head.usSize = Msg.Head.usSize + (4 - Msg.Head.usSize %4);
	 //CGameObject::s_World->g_pBackUpMgr->SetSendBuf((void *)&Msg, Msg.Head.usSize );
	 //CGameObject::s_World->g_pBackUpMgr->Write((void *)&Msg, Msg.Head.usSize, SendLength  );
	CGameObject::s_World->WriteToBackBuff( (char*)&Msg, Msg.Head.usSize );

	return true;
}

//----------------------------------------------------------------------------
//普通聊天频道（所在地图）
//----------------------------------------------------------------------------
// void CPlayer::TalkToMap( const char* pBuf, int nSize, BYTE ucType )
// {
// 	PlayerList  pList =   GetRegion()->GetPlayerList();
// 	list< CPlayer* >::iterator  itor = pList.begin();
// 	for ( ; itor != pList.end(); itor++ )
// 	{
// 		this->TalkToPlayer( *itor, pBuf, nSize, ucType );
// 	}
// }

//----------------------------------------------------------------------------
//阵营频道（所在阵营）
//----------------------------------------------------------------------------
// void CPlayer::TalkToCamp( const char* pBuf, int nSize, BYTE ucType )
// {
// 	for( int i=0; i<ACADEMIC_PLAYER_MEM_ID; i++ )
// 	{
// 		if ( CGameObject::s_World->g_pPlayer[i].IsActive()  && ( CGameObject::s_World->g_pPlayer[i].GetlFaction() == GetlFaction( ) ) )
// 		{
// 			this->TalkToPlayer(  &CGameObject::s_World->g_pPlayer[i], pBuf, nSize, ucType );
// 		}
// 	}
// }

//----------------------------------------------------------------------------
//队伍频道（所在队伍）
//----------------------------------------------------------------------------
// void CPlayer::TalkToTeam( const char* pBuf, int nSize, BYTE ucType )
// {
// 	//修改 by C.D 20071226
// 	if (NULL != m_pTeamLeader)
// 	{
// 		this->TalkToPlayer( m_pTeamLeader,  pBuf, nSize, ucType);
// 		for ( vector<CPlayer*>::iterator iter = m_Teammates.begin();
// 			iter != m_Teammates.end();
// 			iter++ )
// 		{
// 			this->TalkToPlayer( (*iter),  pBuf, nSize, ucType);
// 		}
// 	}
// 	//////////20071226
// 	// 	for ( int a = 0; a < MAX_TEAM_NUMBER; a++  )
// 	// 	{
// 	// 		this->TalkToPlayer( m_pTeam[a],  pBuf, nSize, ucType);
// 	// 	}
// }

//----------------------------------------------------------------------------
//工会频道（所在公会）
//----------------------------------------------------------------------------
// void CPlayer::TalkToUnion( const char* , int, BYTE )
// { 
// 	return;
// }

//----------------------------------------------------------------------------
//私聊频道（单个玩家 ）
//----------------------------------------------------------------------------
// void CPlayer::TalkToPlayer( CPlayer *pPlayer, const char*, int nSize ,BYTE ucType )
// {
// 	MSG_TALK TalkTo;
// 	TalkTo.Head.usType = _MSG_TALK;
// 	TalkTo.Head.usSize = sizeof(MsgHead) + 11; // + chat length
// 	TalkTo.uiUserID = pPlayer->GetID();
// 	if( pPlayer == NULL )
// 	{
// 		//		TalkTo.uiOppositeID = -1;
// 	}
// 
// 	else
// 	{
// 		//		TalkTo.uiOppositeID = 0;//pTarget->GetID();
// 	}
// 
// 
// 	TalkTo.ucType = ucType;
// 	TalkTo.ucTextSize = nSize;
// 	//	wmemcpy( TalkTo.cContent, pBuf, nSize );//cContent已改成宽字符,小心
// 
// 	TalkTo.Head.usSize += nSize;
// 
// 	CGameObject::s_World->SendMsgToClient( &TalkTo, pPlayer->GetSocket() );
// }

//-------------------------------------------------------
//将其他对象信息同步给自己
//-------------------------------------------------------
void CPlayer::AynObjToObj( CCell *pOldCell, CCell *pNewCell )
{
	//__asm int 3;
	//同步旧区域Obj
	std::vector<CCell*>  OldCell =  GetRegion()->GetMap()->AreaCollisionTest( pNewCell, pOldCell );
	std::vector<CCell*>::iterator  CellIter = OldCell.begin();
	for ( ; CellIter != OldCell.end(); CellIter ++ )
	{
		CCell *pCell = (*CellIter);
		pCell->SynOldObjInfoToPlayer( this );
	}

	//同步新区域Obj
	std::vector<CCell*>  NewCell =  GetRegion()->GetMap()->AreaCollisionTest( pOldCell, pNewCell );
	std::vector<CCell*>::iterator  CellItor = NewCell.begin();
	for ( ; CellItor != NewCell.end(); CellItor ++ )
	{
		CCell *pCell = (*CellItor);
		pCell->SynNewObjInfoToPlayer( this );
	}
}

//-------------------------------------------------------
//将自己的信息同步给其他玩家
//-------------------------------------------------------
void CPlayer::AynMeToOther( CCell *pOldCell, CCell *pNewCell)
{
	CGameObject::AynMeToOther( pOldCell, pNewCell  );

}


bool CPlayer::HaveConsortia()
{
	return m_pConsortia != NULL;
}

//-------------------------------------------------------
// 刷新关系数据
//-------------------------------------------------------
void CPlayer::RefreshRelation()
{
	//向客户端同步关系数据
	MSG_RELATIONALL relation_friend,relation_blackList; 
	memset( &relation_friend, 0L, sizeof(MSG_RELATIONALL) );
	std::map< string , RELATION > RelationMgr = m_RelationMgr.m_Relation;

	//好友
	relation_friend.Head.usSize = sizeof(MSG_RELATIONALL) - 30*sizeof(Friend);
	relation_friend.Head.usType = _MSG_RELATIONALL;
	relation_friend.uiUserID = GetID();
	relation_friend.ucType = TYPE_FRIEND;
	relation_friend.cNum =  0;

	memset( &relation_blackList, 0L, sizeof(MSG_RELATIONALL) );
	relation_blackList.Head.usSize = sizeof(MSG_RELATIONALL) - 30*sizeof(Friend);
	relation_blackList.Head.usType = _MSG_RELATIONALL;
	relation_blackList.uiUserID = GetID();
	relation_blackList.ucType = TYPE_BLACKLIST;
	relation_blackList.cNum =  0;

	for ( std::map< string , RELATION >::iterator itor =m_RelationMgr.m_Relation.begin(); itor != m_RelationMgr.m_Relation.end(); itor++ )
	{
		CPlayer *pPlayer = GetPlayerFromRoleName(itor->first);


		if ( itor->second.Type == TYPE_FRIEND ) //好友
		{
			if ( relation_friend.cNum >= MAX_FRIENDS_COUNT )
               continue;

			strcpy( relation_friend.sFriend[relation_friend.cNum].Name, itor->first.c_str() ); 
			if ( NULL == pPlayer )
			{
				relation_friend.sFriend[relation_friend.cNum].IsOnline = false;
				relation_friend.sFriend[relation_friend.cNum].usCamp =  itor->second.Camp;
				relation_friend.sFriend[relation_friend.cNum].usBusiness = itor->second.Business;
				relation_friend.sFriend[relation_friend.cNum].usCity = itor->second.City;
				relation_friend.sFriend[relation_friend.cNum].uc_LV = itor->second.LV;
			}
			else
			{
				relation_friend.sFriend[relation_friend.cNum].IsOnline = true;
				relation_friend.sFriend[relation_friend.cNum].usCamp = pPlayer->GetlFaction();
				relation_friend.sFriend[relation_friend.cNum].usBusiness = pPlayer->GetlClass();
				relation_friend.sFriend[relation_friend.cNum].usCity = pPlayer->s_World->GetRegionFromLogicID( pPlayer->GetlRegionID() )->GetID();
				relation_friend.sFriend[relation_friend.cNum].uc_LV = pPlayer->GetcRank();
			}
			relation_friend.cNum++;
			relation_friend.Head.usSize += sizeof(Friend);
		}
		else if ( itor->second.Type == TYPE_BLACKLIST ) //黑名单
		{
			if ( relation_blackList.cNum >= MAX_FRIENDS_COUNT )
				continue;

			strcpy( relation_blackList.sFriend[relation_blackList.cNum].Name, itor->first.c_str() ); 
			if ( NULL == pPlayer )
			{
				relation_blackList.sFriend[relation_blackList.cNum].IsOnline = false;
				relation_blackList.sFriend[relation_blackList.cNum].usCamp =  itor->second.Camp;
				relation_blackList.sFriend[relation_blackList.cNum].usBusiness = itor->second.Business;
				relation_blackList.sFriend[relation_blackList.cNum].usCity = itor->second.City;
				relation_blackList.sFriend[relation_blackList.cNum].uc_LV = itor->second.LV;
			}
			else
			{
				relation_blackList.sFriend[relation_blackList.cNum].IsOnline = true;
				relation_blackList.sFriend[relation_blackList.cNum].usCamp = pPlayer->GetlFaction();
				relation_blackList.sFriend[relation_blackList.cNum].usBusiness = pPlayer->GetlClass();
				relation_blackList.sFriend[relation_blackList.cNum].usCity = pPlayer->s_World->GetRegionFromLogicID( pPlayer->GetlRegionID() )->GetID();
				relation_blackList.sFriend[relation_blackList.cNum].uc_LV = pPlayer->GetcRank();
			}
			relation_blackList.cNum++;
			relation_blackList.Head.usSize += sizeof(Friend);
		}

	}
	if ( relation_friend.cNum > 0 )
	{
		CGameObject::s_World->SendMsgToClient( &relation_friend, GetSocket() );	
	}

	if (  relation_blackList.cNum >0 )
	{
		CGameObject::s_World->SendMsgToClient( &relation_blackList, GetSocket() );
	}

	//公会基本信息
	BroadcastConsortiaBaseInfo();
	//公会成员
	MSG_CONSORTIA_MEMBER_LIST Memeber_List;       
	Memeber_List.Head.usSize = sizeof( MSG_CONSORTIA_MEMBER_LIST );
	Memeber_List.Head.usType = _MSG_CONSORTIA_MEMBER_LIST;
	Memeber_List.uiCount = 0;
	Memeber_List.IsAll = true;

	stdext::hash_map< ConsortiaElem*, CConsortiaMgr::Member >::iterator itor =  CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.find( m_pConsortia );
	if(  itor !=   CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.end() )
	{
		CConsortiaMgr::Member member = itor->second;
		for ( CConsortiaMgr::Member::iterator iter = member.begin(); iter != member.end(); iter++ )
		{
			Memeber_List.Member[Memeber_List.uiCount] = iter->second.m_Data._Ttype;

			CPlayer *pPlayer= GetPlayerFromRoleName( iter->second.m_Data._Ttype.strName );
			if ( NULL == pPlayer )
			{
				Memeber_List.Member[Memeber_List.uiCount].lMapID = -1;
			}
			else
			{
				Memeber_List.Member[Memeber_List.uiCount].lMapID = pPlayer->s_World->GetRegionFromLogicID(pPlayer->GetlRegionID())->GetID();
				Memeber_List.Member[Memeber_List.uiCount].iLevel = pPlayer->GetcRank();
				Memeber_List.Member[Memeber_List.uiCount].uiContribute = pPlayer->GetuiUionContribute();
			}

			Memeber_List.uiCount++;

			if ( Memeber_List.uiCount == 24  )
			{
				CGameObject::s_World->SendMsgToClient( &Memeber_List, GetSocket() ); 
				Memeber_List.uiCount = 0;
				Memeber_List.IsAll = false;
			}
		}

		if (  Memeber_List.uiCount )
		{
			if ( !Memeber_List.IsAll )
			{
				Memeber_List.IsAll = false;
			}
			CGameObject::s_World->SendMsgToClient( &Memeber_List, GetSocket() ); 
		}
	}

}

//-------------------------------------------------------
// 是否是该工会职务
//-------------------------------------------------------
bool CPlayer::IsThisDuty( CONSORTIA_JOB_TYPE Duty )
{
	if( m_pConsortia )
		return  CGameObject::s_World->g_pConsortiaManager->GetCurMemberWithJob( m_pConsortia, Duty, GetName() ) == NULL ? false : true ;
	return false;
}

//-------------------------------------------------------
// 所在工会是否满员
//-------------------------------------------------------
bool CPlayer::IsMemeberFull()
{
	if (m_pConsortia)
		return  CGameObject::s_World->g_pConsortiaManager->IsMemberFull( m_pConsortia );
	return true;
}

//-------------------------------------------------------
//获取公会的人数上限
//-------------------------------------------------------
int CPlayer::GetConsortiaMaxMember()
{
	return  CGameObject::s_World->g_pConsortiaManager->GetConsortiaMaxMember( m_pConsortia );
}

//-------------------------------------------------------
//获取公会的当前人数
//-------------------------------------------------------
int CPlayer::GetConsortiaCurrentMember()
{
	return  CGameObject::s_World->g_pConsortiaManager->GetConsortiaSize( m_pConsortia );
}
//-------------------------------------------------------
//获取公会的最大祭坛数
//-------------------------------------------------------
int CPlayer::GetConsortiaMaxAltar()
{
	if ( !m_pConsortia)
	{
		return 0;
	}
	return  CGameObject::s_World->g_pConsortiaManager->GetConsortiaMaxAltar( m_pConsortia->iLevel );
	
	
}
//-------------------------------------------------------
//获取公会当前的祭坛个数
//-------------------------------------------------------
int CPlayer::GetConCurrentAltarNum()
{
	if ( !m_pConsortia)
	{
		return 0;
	}
	return m_pConsortia->m_pAltar.size();
	
}
//-------------------------------------------------------
//获取玩家当前已有的祭坛
//------------------------------------------------------
vector<int>& CPlayer::GetHavePlayerAltars()												
{
	static vector<int> Has;
	Has.clear();
	map<UINT,UINT>::iterator itor = m_Altar.begin();
	for ( ; itor != m_Altar.end(); itor++ )
	{
		if (itor->second != 0)
		{
			Has.push_back(itor->first);
		}
	}
	return Has;
}

//读取数据库中玩家的所有祭坛
void CPlayer::InitAltar(UINT id,UINT level)
{
	m_Altar[id] = level;
}
//-------------------------------------------------------
// 由主动发起邀请的玩家负责添加
//-------------------------------------------------------
void CPlayer::AddConsortiaMember( ConsortiaRelationElem &rElems )
{
	//向老成员发送新成员加入消息
	MSG_CONSORTIA_MEMBER_LIST Memeber_List;       
	Memeber_List.Head.usSize = sizeof( MSG_CONSORTIA_MEMBER_LIST );
	Memeber_List.Head.usType = _MSG_CONSORTIA_MEMBER_LIST;
	Memeber_List.uiCount = 1;
	Memeber_List.IsAll = false;
	Memeber_List.Member[0].acDuty = CONSORTIA_MEMBER;
	strcpy(Memeber_List.Member[0].acMemberName, rElems.strName.c_str() );
	Memeber_List.Member[0].iLevel = rElems.LV;
	Memeber_List.Member[0].lMapID = rElems.lMapID;
	Memeber_List.Member[0].ucBusiness = rElems.ucBusiness;  
	Memeber_List.Member[0].uiContribute = rElems.uiContribute;  
	BroadcastConsortiaMsg( &Memeber_List );

	//添加新成员
	 CGameObject::s_World->g_pConsortiaManager->Add( m_pConsortia, rElems );
}

//-------------------------------------------------------
// 会长解散工会
//-------------------------------------------------------
eError CPlayer::DismissConsortia()
{
	if ( !m_pConsortia )
	{
		//威胁值加1
		return NO_MSG_ERRO;
	}
	//判断会长
	if (  !IsThisDuty( CONSORTIA_CHAIRMAN )  )
	{
		return MSG_ERRO_0377;
	}

	//向所有成员发送解散公会消息  
	MSG_CONSORTIA_DISMISS  ConsortiaDismiss;
	ConsortiaDismiss.Head.usSize = sizeof( MSG_CONSORTIA_DISMISS );
	ConsortiaDismiss.Head.usType = _MSG_CONSORTIA_DISMISS;
	strcpy(ConsortiaDismiss.cPlayerName, GetName());
	BroadcastConsortiaMsg( &ConsortiaDismiss );

	ConsortiaElem*  temp = m_pConsortia;

	//改变所有成员的公会属性
	stdext::hash_map< ConsortiaElem*, CConsortiaMgr::Member >::iterator itor =  CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.find( m_pConsortia );
	if(  itor !=   CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.end() )
	{
		CConsortiaMgr::Member member = itor->second;
		for ( CConsortiaMgr::Member::iterator iter = member.begin(); iter != member.end(); iter++ )
		{

			CPlayer *pPlayer = GetPlayerFromRoleName(  iter->first );
			if ( NULL != pPlayer)
			{
				pPlayer->ClearAllAltar();
				pPlayer->SetcUnion( 0 );
				pPlayer->SetcUnionBusiness( 0 );
				pPlayer->SetConsortiaInfo( NULL );
				
			}
			else
			{
				UpdateDB_Offline( iter->second.m_Data._Ttype.strName.c_str(), 0, 0 ); //清除数据库中自己的公会信息
				UpdateDB_Altar(   iter->second.m_Data._Ttype.strName.c_str() );     //清除数据库中的所有祭坛
			}
		}
	}

	//解散公会 
	if(	 CGameObject::s_World->g_pConsortiaManager->DismissConsortia( temp ) )
	{
		return NO_MSG_ERRO;
	}

	return NO_MSG_ERRO;
}


//-------------------------------------------------------
// 自动离开公会 
//-------------------------------------------------------
eError CPlayer::DelMeFromConsortia( )
{
	if ( !m_pConsortia)
	{
		//威胁值加1
		return NO_MSG_ERRO;
	}

	MSG_CONSORTIA_EXIT  Exit;
	memset(&Exit, 0L, sizeof(Exit) );
	Exit.Head.usSize = sizeof( MSG_CONSORTIA_EXIT );
	Exit.Head.usType = _MSG_CONSORTIA_EXIT;
	strcpy( Exit.StrName, GetName() );

	//自己是会长,任命新会长
	if ( GetcUnionBusiness() == CONSORTIA_CHAIRMAN )
	{
		CConsortiaMgr::ClusteringElems  *pMember1 =  CGameObject::s_World->g_pConsortiaManager->GetCurMemberWithJob( m_pConsortia, CONSORTIA_ASSISTANT_CHAIRMAN );
		CConsortiaMgr::ClusteringElems  *pMember2 =  CGameObject::s_World->g_pConsortiaManager->GetCurMemberWithJob( m_pConsortia, CONSORTIA_DIRECTOR );
		CConsortiaMgr::ClusteringElems  *pMember3 =  CGameObject::s_World->g_pConsortiaManager->GetCurMemberWithJob( m_pConsortia, CONSORTIA_CADREMAN );
		CConsortiaMgr::ClusteringElems  *pMember4 =  CGameObject::s_World->g_pConsortiaManager->GetCurMemberWithJob( m_pConsortia, CONSORTIA_MEMBER );
		CConsortiaMgr::ClusteringElems  *pMember5 =  CGameObject::s_World->g_pConsortiaManager->GetCurMemberWithJob( m_pConsortia, CONSORTIA_PROBATION_MEMBER );
		
		if (  ( pMember1 != NULL )  || ( pMember2 != NULL ) || ( pMember3 != NULL )|| ( pMember4 != NULL ) || ( pMember5 != NULL) )
		{
			//如果公会里面还有人  会长脱离失败
			return MSG_ERRO_0395;
		}	
		else
		{
			//解散公会
			DismissConsortia();
			return NO_MSG_ERRO;
		}
	}

	//向所有成员广播自己离开公会消息 
	BroadcastConsortiaMsg( &Exit );

	 CGameObject::s_World->g_pConsortiaManager->Del( m_pConsortia, GetName() );

	//重新发送公会成员列表
	BroadcastConMemberInfo();

	//清除数据库信息
	ClearAllAltar();	//清除所有祭坛 等待场景刷新保存数据库
	SetcUnion(0);
	SetcUnionBusiness(0);
	SetConsortiaInfo( NULL );
	

	return NO_MSG_ERRO;
}


//-------------------------------------------------------------
//修改公会公告
//-------------------------------------------------------------
eError CPlayer::ChangeConsortiaPlacard( const char *Placard )                                         
{
	if ( !m_pConsortia)
	{
		//威胁值加1
		return NO_MSG_ERRO;
	}

	//判断会长
	if (  !IsThisDuty( CONSORTIA_CHAIRMAN ) && !IsThisDuty( CONSORTIA_ASSISTANT_CHAIRMAN )  )
	{
		return MSG_ERRO_03A4;
	}

	//改变本公会公告
	strcpy( m_pConsortia->acTextInfo, Placard );

	MSG_CONSORTIA_BASE_INFO  ConsortiaInfo;
	memset( &ConsortiaInfo, 0L, sizeof( MSG_CONSORTIA_BASE_INFO ));
	ConsortiaInfo.Head.usSize = sizeof( MSG_CONSORTIA_BASE_INFO );
	ConsortiaInfo.Head.usType = _MSG_CONSORTIA_BASE_INFO;
	ConsortiaInfo.iLevel = m_pConsortia->iLevel;
	ConsortiaInfo.lCredit = m_pConsortia->lCredit;
	ConsortiaInfo.lfound = m_pConsortia->lfound;
	ConsortiaInfo.lbijou = m_pConsortia->lbijou;
	strcpy( ConsortiaInfo.acName, m_pConsortia->acName );
	strcpy(ConsortiaInfo.acTextInfo, Placard );

	//向所有成员发送修改公告消息  
	BroadcastConsortiaMsg( &ConsortiaInfo );

	return NO_MSG_ERRO;
}


//-------------------------------------------------------------
//晋升
//-------------------------------------------------------------
bool CPlayer::AppointDuty( std::string StrName, CONSORTIA_JOB_TYPE Duty )
{
	if ( !m_pConsortia)
	{
		//威胁值加1
		return NO_MSG_ERRO;
	}

	//判断会长
	if (  GetcUnionBusiness() < CONSORTIA_ASSISTANT_CHAIRMAN  ||  Duty <= CONSORTIA_NONE ||  Duty > CONSORTIA_CHAIRMAN || GetName() == StrName ||
		(  CGameObject::s_World->g_pConsortiaManager->GetConsortiaSize( m_pConsortia ) == 1 && GetcUnionBusiness() == CONSORTIA_CHAIRMAN ) )
	{
		return false;
	}

	if ( Duty == CONSORTIA_NONE )
		return false;

	CPlayer *pPlayer = NULL;
	pPlayer = GetPlayerFromRoleName( StrName );
	if ( pPlayer != NULL && pPlayer->GetcUnionBusiness() == Duty )
	{
		//防止两个人同时晋升或降级一个人
		return false;
	}
	if (  CGameObject::s_World->g_pConsortiaManager->GrantJob( m_pConsortia, GetName(), StrName, Duty ) )
	{
		if ( pPlayer != NULL )
		{
			pPlayer->SetcUnionBusiness( Duty );

			MSG_CONSORTIA_DUTY  consortia_duty;
			consortia_duty.Head.usSize = sizeof( MSG_CONSORTIA_DUTY );
			consortia_duty.Head.usType = _MSG_CONSORTIA_DUTY; 
			strcpy( consortia_duty.OldName, GetName() );
			consortia_duty.OldDuty = GetcUnionBusiness();
			strcpy( consortia_duty.NewName,StrName.c_str() );
			consortia_duty.NewDuty  = Duty;

			//向所有成员发送修改公告消息  
			BroadcastConsortiaMsg( &consortia_duty );
		}
		else
		{
			UpdateDB_Offline( StrName.c_str(), m_pConsortia->uiID, Duty );	
		}

		//转让会长
		if ( GetcUnionBusiness() == CONSORTIA_CHAIRMAN &&  Duty == CONSORTIA_CHAIRMAN )
		{
			if (  CGameObject::s_World->g_pConsortiaManager->GrantJob( m_pConsortia, GetName(), string(GetName()), CONSORTIA_MEMBER ) )
			{
				SetcUnionBusiness( CONSORTIA_MEMBER );
				MSG_CONSORTIA_DUTY  consortia_duty;
				consortia_duty.Head.usSize = sizeof( MSG_CONSORTIA_DUTY );
				consortia_duty.Head.usType = _MSG_CONSORTIA_DUTY; 
				strcpy( consortia_duty.OldName, GetName() );
				consortia_duty.OldDuty = CONSORTIA_CHAIRMAN;
				strcpy( consortia_duty.NewName,GetName() );
				consortia_duty.NewDuty  = CONSORTIA_MEMBER;

				//向所有成员发送修改公告消息  
				BroadcastConsortiaMsg( &consortia_duty );
			}
		}

		return true;
	}
	else
	{
		return false;
	}



	return true;
}


//--------------------------------------------------------------------
// 会长移除成员
//--------------------------------------------------------------------
eError  CPlayer::DelMemeber( std::string StrName )    
{
	if ( !m_pConsortia)
	{
		//威胁值加1
		return NO_MSG_ERRO;
	}

	//判断会长
	if (  GetcUnionBusiness() < CONSORTIA_DIRECTOR )
	{
		return MSG_ERRO_03C2;
	}

	CPlayer *pPlayer = GetPlayerFromRoleName( StrName );
	//删除自己
	if ( pPlayer == this )
	{
		DelMeFromConsortia();
	}
	else
	{
		//更新被踢玩家
		if ( NULL !=  pPlayer )
		{
			//不能剔除自己平级或者高于自己的玩家
			if ( pPlayer->GetcUnionBusiness() >= GetcUnionBusiness() )
			{
				return MSG_ERRO_03C3;
			}
			else
			{
				pPlayer->ClearAllAltar();  //清除所有祭坛
				pPlayer->SetcUnion( 0 );
				pPlayer->SetcUnionBusiness( 0 );
				pPlayer->SetConsortiaInfo( NULL );
			
				//向所有成员广播玩家被提出公会的消息
				MSG_CONSORTIA_MEMBER_DEL  BeDel;
				memset(&BeDel, 0L, sizeof(BeDel) );
				BeDel.Head.usSize = sizeof( MSG_CONSORTIA_MEMBER_DEL );
				BeDel.Head.usType = _MSG_CONSORTIA_MEMBER_DEL;
				strcpy( BeDel.strName, StrName.c_str() );
				BroadcastConsortiaMsg( &BeDel );

				 CGameObject::s_World->g_pConsortiaManager->Del( m_pConsortia, StrName );
				//重新发送公会成员列表
				BroadcastConMemberInfo();
				
			}
		}
		else
		{
			UpdateDB_Offline( StrName.c_str(), 0, CONSORTIA_NONE );  //清除数据库中自己的公会信息
			UpdateDB_Altar(  StrName.c_str() );     //清除数据库中的所有祭坛

		}
	}

	return NO_MSG_ERRO;
}


//---------------------------------------------------------------------
// 广播公会消息
//---------------------------------------------------------------------
bool CPlayer::BroadcastConsortiaMsg( void* buf  )
{
	if ( !m_pConsortia )
		return false;
	stdext::hash_map< ConsortiaElem*, CConsortiaMgr::Member >::iterator itor =  CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.find( m_pConsortia );
	if(  itor !=   CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.end() )
	{
		CConsortiaMgr::Member member = itor->second;
		for ( CConsortiaMgr::Member::iterator iter = member.begin(); iter != member.end(); iter++ )
		{
			CPlayer *pPlayer = GetPlayerFromRoleName(  iter->first );
			if ( NULL != pPlayer )
				if (pPlayer->ucChannel & defGUILD)
					CGameObject::s_World->SendMsgToClient( buf, pPlayer->GetSocket() ); 	
		}
	}
	return true;
}
//---------------------------------------------------------------------
// 广播公会基本信息消息
//---------------------------------------------------------------------
bool CPlayer::BroadcastConsortiaBaseInfo()
{
	if ( NULL != m_pConsortia )
	{
		MSG_CONSORTIA_BASE_INFO BaseInfo;
		BaseInfo.Head.usSize = sizeof( MSG_CONSORTIA_BASE_INFO );
		BaseInfo.Head.usType = _MSG_CONSORTIA_BASE_INFO;
		strcpy( BaseInfo.acName, m_pConsortia->acName );
		strcpy( BaseInfo.acTextInfo, m_pConsortia->acTextInfo );
		BaseInfo.iLevel = m_pConsortia->iLevel;
		BaseInfo.lCredit = m_pConsortia->lCredit;
		BaseInfo.lfound = m_pConsortia->lfound;
		BaseInfo.lbijou = m_pConsortia->lbijou;
		BaseInfo.MaxMember = GetConsortiaMaxMember();
		BaseInfo.AltarCounts = m_pConsortia->m_pAltar.size();
		std::map<int ,CAltarElem*>::iterator Altar_itor = m_pConsortia->m_pAltar.begin();
		int i=0;
		for (; Altar_itor != m_pConsortia->m_pAltar.end();Altar_itor++)
		{
			BaseInfo.Altar[i].AltarID = Altar_itor->first;
			BaseInfo.Altar[i].Grade = Altar_itor->second->m_LV;
			i++;
		}

		BroadcastConsortiaMsg(&BaseInfo);
	}
	return true;
}

//----------------------------------------------------------------------
// 广播公会成员列表（添加删除或是离开公会是用到）
//----------------------------------------------------------------------
bool CPlayer::BroadcastConMemberInfo()
{
	//公会成员
	if ( m_pConsortia)
	{
		MSG_CONSORTIA_MEMBER_LIST Memeber_List;       
		Memeber_List.Head.usSize = sizeof( MSG_CONSORTIA_MEMBER_LIST );
		Memeber_List.Head.usType = _MSG_CONSORTIA_MEMBER_LIST;
		Memeber_List.uiCount = 0;
		Memeber_List.IsAll = true;

		stdext::hash_map< ConsortiaElem*, CConsortiaMgr::Member >::iterator itor =  CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.find( m_pConsortia );
		if(  itor !=   CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.end() )
		{

			CConsortiaMgr::Member member = itor->second;
			for ( CConsortiaMgr::Member::iterator iter = member.begin(); iter != member.end(); iter++ )
			{
				Memeber_List.Member[Memeber_List.uiCount] = iter->second.m_Data._Ttype;

				CPlayer *pPlayer= GetPlayerFromRoleName( iter->second.m_Data._Ttype.strName );
				if ( NULL == pPlayer )
				{
					Memeber_List.Member[Memeber_List.uiCount].lMapID = -1;
				}
				else
				{
					Memeber_List.Member[Memeber_List.uiCount].lMapID = pPlayer->GetRegion() ? pPlayer->GetRegion()->GetID() : -1 ;
					Memeber_List.Member[Memeber_List.uiCount].iLevel = pPlayer->GetcRank();
					Memeber_List.Member[Memeber_List.uiCount].uiContribute = pPlayer->GetuiUionContribute();
				}

				Memeber_List.uiCount++;

				if ( Memeber_List.uiCount == 24  )
				{
					CGameObject::s_World->SendMsgToClient( &Memeber_List, GetSocket() ); 
					Memeber_List.uiCount = 0;
					Memeber_List.IsAll = false;
				}
			}

			if (  Memeber_List.uiCount )
			{
				if ( !Memeber_List.IsAll )
				{
					Memeber_List.IsAll = false;
				}
				CGameObject::s_World->SendMsgToClient( &Memeber_List, GetSocket() ); 
			}
		}
	}
	return true;

}
//----------------------------------------------------------------------
// 职业转换
//----------------------------------------------------------------------
void CPlayer::ChangePlayeBuniness( int NewBuniness )
{
	m_PassiveSkill.clear();				//清空被动技能表
	InitClassPassiveSkill();			//初始化职业技能信息
	if(NewBuniness >= m_ClassCount){ASSERT(0);}		//没有这个职业

	m_ObjectData.m_lClass = NewBuniness;

	vector<int>::iterator iter = m_ClassPassiveSkill[NewBuniness].begin();
	for(;iter != m_ClassPassiveSkill[NewBuniness].end();iter++)
	{
		AddPassiveSkill( (*iter), 0 );
	}
	/*by lion
	switch( NewBuniness )
	{
	case FIGHTER_ONE:
	{
	m_ObjectData.m_lClass = FIGHTER_ONE;
	AddPassiveSkill( SKILL_ESCRIME, 0 );  //剑术
	AddPassiveSkill( SKILL_GLAVE_GAS, 0 );  //剑气
	}
	break;
	case FIGHTER_TWO:
	{
	m_ObjectData.m_lClass = FIGHTER_TWO;
	AddPassiveSkill( SKILL_EXACTITUDE_ATTACK, 0 );  //精准攻击
	AddPassiveSkill( SKILL_MUMP, 0 );  //斗气
	}
	break;
	case SCHOLAR_ONE:
	{
	m_ObjectData.m_lClass = SCHOLAR_ONE;
	AddPassiveSkill( SKILL_ELEMENTS_VOLITION, 0 );  //元素意志
	AddPassiveSkill( SKILL_FIR_STRENGTHEN, 0 );  //火焰强化

	}
	break;
	case SCHOLAR_TWO:
	{
	m_ObjectData.m_lClass = SCHOLAR_TWO;
	AddPassiveSkill( SKILL_FLEXILE, 0 );  //柔韧护盾
	AddPassiveSkill( SKILL_LIFE_CHANNELS, 0 );  //生命通道
	}
	break;
	default:
	ASSERT(0);
	break;
	}
	*/
}

bool CPlayer::CalculateExp( bool TarIsDead , int )
{
	if ( CGameObject::CalculateExp( TarIsDead, CPeizhi::Instance()->GetDefaultValue( PLAYER_SKILL_EXP  ) ) )
	{
		SynGameData( false );
		return true;
	}
 
	return false;
}

bool  CPlayer::RefreshLoginQueue( int QueueIndex )
{
	if ( m_WorldStatus == eROLEINFOWAIT )
	{
		MSG_LOGIN_QUEUE  msg_surplus;
		msg_surplus.Head.usSize  = sizeof( MSG_LOGIN_QUEUE );
		msg_surplus.Head.usType  = _MSG_LOGIN_QUEUE;
		msg_surplus.iSurplusNum  = QueueIndex;
		s_World->SendMsgToClient( &msg_surplus, GetSocket() );
		return true;
	}
	return false;

};

const char* CPlayer::PackRoleAttribute()
{
	static char szSQL[512];
	memset( szSQL,0L,sizeof(szSQL) );

	const char *Gender ;

	//防止进入档格
	float temp_X, temp_Z;
	if ( GetLastMsg() == _MSG_WALK_BEGIN )
	{
		GetLastPos( temp_X,  temp_Z );
	}
	else
	{
		temp_X =  GetfX();
		temp_Z =  GetfZ();
	}

	//更新进入游戏角色数据
	char LoginTime[32],LastUpdte[32];
	sprintf(LoginTime,"%d-%d-%d %d:%d:%d",1900+m_Login_time->tm_year, m_Login_time->tm_mon+1,m_Login_time->tm_mday,m_Login_time->tm_hour,m_Login_time->tm_min,m_Login_time->tm_sec);
	sprintf(LastUpdte,"%d:%d:%d",m_LastUpte_time->tm_hour,m_LastUpte_time->tm_min,m_LastUpte_time->tm_sec);

	time_t  timep;
	time(&timep);
	m_LastUpte_time=localtime(&timep);

	Gender = (  GetGender() == 1 )? "male":"female";
	map<string,UINT>::iterator itor1 =  m_HaveRole.find( GetName() );
	if ( itor1 != m_HaveRole.end() )
	{
		sprintf( szSQL, SQL_UPDATE_ROLE_INFO ,itor1->second, Gender,  GetlFaction(),  GetlClass(),  GetcRank(), \
			GetcRank(), GetcExp(), GetcExp(),  GetlHP(),  GetlMP(), 0,  GetlRegionID(),  
			temp_X, temp_Z, GetlMoney(),  GetlStone(), GetcUnion(), GetcUnionBusiness(), GetuiUionContribute(),GetuiStoreNum(),GetuiBagNum(),GetSkillPoint(), GetSkillExp(), 
			GetMaxHP(), GetMaxMP(), GetlPrestige(), LoginTime, LastUpdte );
	}
	return szSQL;
}

//------------------------------------------------------------
//踢人
//------------------------------------------------------------
bool CPlayer::GM_Handler_kick( ActionElem &elem )
{
	if ( elem.Head.usType == ACTION_KICK_PLAYER  )
	{
		CGameObject::s_World->CloseSocket( static_cast<CPlayer*>(elem.Obj) );
		return true;
	}

	return false;
}

//------------------------------------------------------------
//禁言
//------------------------------------------------------------
bool CPlayer::GM_Handler_speak( ActionElem &elem )
{
 	if ( elem.Head.usType == ACTION_BAN_SPEAK  )
 	{
		time_t CurrentTime = time(NULL);//测试用 记得删除掉
 		if ( elem.OriginalTime +  elem.IntervalTime  <  CurrentTime  )
 		{
			//删除对应的角色名
			CGameObject::s_World->Del_SpeakForbidPlayer(elem.ObjName);
 			return true;
 		}
 	}

	return false;
}

//------------------------------------------------------------
//添加道具
//------------------------------------------------------------
bool CPlayer::GM_Handler_item( ActionElem &elem )
{
// 	if ( elem.Head.usType == ACTION_PLAYER_ITEM  )
// 	{
// 		//step 1:添加装备
// 
// 		//step 2:踢玩家下线
// 		CGameObject::s_World->CloseSocket( static_cast<CPlayer*>(elem.Obj) );
// 
// 		return true;
// 	}

	return false;
}

eError CPlayer::ConsortiaLevelup()
{
	//还没有建立公会
	if (! m_pConsortia)
	{
		return MSG_ERRO_03C5;
	}

	//判断是否有权限
	if ( IsThisDuty( CONSORTIA_CHAIRMAN ) || IsThisDuty( CONSORTIA_ASSISTANT_CHAIRMAN ))
	{
		if ( m_pConsortia->iLevel >= MAX_CONSORTIA_GRADE)
		{
			return MSG_ERRO_O3C4; //公会已经最大等级
		}

		if ( m_pConsortia->LevelUp(this) )
		{
			BroadcastConsortiaBaseInfo();
			return MSG_ERRO_03C6; 
		}
		else
		{
			return MSG_ERRO_03C7;
		}
	}

	return MSG_ERRO_03A4;  //非正副会长
}

bool CPlayer::AltarLevelUp(int ID)
{
	if ( IsThisDuty( CONSORTIA_CHAIRMAN ) || IsThisDuty( CONSORTIA_ASSISTANT_CHAIRMAN ))
		return m_pConsortia->AltarLevelUp(this,ID);
	return false;
}

bool CPlayer::CreateAltar(int ID)
{
	if ( IsThisDuty( CONSORTIA_CHAIRMAN ) || IsThisDuty( CONSORTIA_ASSISTANT_CHAIRMAN ) &&  GetConCurrentAltarNum() < GetConsortiaMaxAltar())
	{
		if ( ID < 1 || ID >12)
		{
			//没有的祭坛号
			return false;
		}
		if (m_pConsortia->CreateAltar(ID))
		{
			//成功创建完祭坛后向客户端重新发送一次公会的基本信息
			BroadcastConsortiaBaseInfo();
			return true;

		}
	}
		


	return false;
}

bool CPlayer::DelAltar(int ID)
{
	if ( IsThisDuty( CONSORTIA_CHAIRMAN ) || IsThisDuty( CONSORTIA_ASSISTANT_CHAIRMAN ))
	{
		//删除玩家身上对应的祭坛及所影响的数据
		DelConMember_AltarInfo( (UINT)ID );
		if ( m_pConsortia->DelAltar(ID) )
		{
			//更新客户端公会成员的公会基本信息
			BroadcastConsortiaBaseInfo();
			
			

			return true;
		}
	}

	return false;
}

//删除玩家身上对应的祭坛及所影响的数据
void CPlayer::DelConMember_AltarInfo( UINT ID )
{
	stdext::hash_map< ConsortiaElem*, CConsortiaMgr::Member >::iterator itor =  CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.find( m_pConsortia );
	if(  itor !=   CGameObject::s_World->g_pConsortiaManager->m_ConsortiaMemberMap.end() )
	{
		CConsortiaMgr::Member member = itor->second;
		for ( CConsortiaMgr::Member::iterator iter = member.begin(); iter != member.end(); iter++ )
		{
			CPlayer *pPlayer = GetPlayerFromRoleName(  iter->first );
			if ( NULL != pPlayer)
			{
				pPlayer->ClearOneAltar( ID );
			}
			else
			{
				//处理离线的玩家数据库中的祭坛等级
				ClearOneAltar_fromDB(iter->second.m_Data._Ttype.strName.c_str(),ID);
			}
		}
	}
}
//处理在线玩家（删除玩家身上对应的祭坛及所影响的数据）
void CPlayer::ClearOneAltar(UINT ID)
{
	map<UINT,UINT>::iterator itor = m_Altar.find(ID);
	if (itor != m_Altar.end())
	{
		if (itor->second != 0)
		{
			OblationLevelUp( ID,eALTAR_DELETE);
		}
	}
}
void CPlayer::ClearOneAltar_fromDB(const char *name,UINT ID)
{
	char szSQL[512];
	memset( szSQL,0L,sizeof(szSQL) );

	dbtool::IDatabase* DB = CGameObject::s_World->GetDBAddr( DB_NONE );
	if ( !DB )
	{
		ASSERT(0);
		return ;
	}
	sprintf( szSQL, OFFLINE_SQL_UPDATE_ONE_ALTAR_INFO ,name,ID);
	DB->ExecuteAsyncSQL( szSQL, NULL, NULL );
}

//得到确定祭坛的供奉等级
UINT  CPlayer::GetOblationLV(int ID)
{
	map<UINT,UINT>::iterator itor = m_Altar.find( ID );
	if ( itor == m_Altar.end() )
		return 1000;

	return itor->second;
}

//----------------------------------------------------------
//提升祭坛供奉等级(脚本处理升级消耗及添加性能数据)
//----------------------------------------------------------
bool CPlayer::OblationLevelUp(UINT ID,eAltarDealType type)
{
	if ( !m_pConsortia )
	{
		return false;
	}
	return m_pConsortia->OblationLevelUp(this,ID,type);
}
//----------------------------------------------------------
//提升祭坛供奉等级
//----------------------------------------------------------
bool  CPlayer::UPOblationLV(UINT ID)
{
	map<UINT,UINT>::iterator itor = m_Altar.find( ID );
	if ( itor == m_Altar.end() )
		return false;

	m_Altar[ID]++;

	//向该玩家发送祭坛列表（全部的祭坛重新发送一次）
	UpdateAltarMsg();
	
   return true;
}

//-----------------------------------------------------
//删除供奉的祭坛
//-----------------------------------------------------
bool CPlayer::DelOblation( UINT ID )
{
	map<UINT,UINT>::iterator itor = m_Altar.find( ID );
	if ( itor == m_Altar.end() )
		return false;

	m_Altar[ID] = 0;
	
	//向该玩家发送祭坛列表（全部的祭坛重新发送一次）
	UpdateAltarMsg();

	return true;
}

//---------------------------------------------------
//清除所有祭坛祭坛
//---------------------------------------------------
void CPlayer::ClearAllAltar()
{
	//清空祭坛
	map<UINT,UINT>::iterator itor = m_Altar.begin();
	for (; itor != m_Altar.end(); itor++)
	{
		//清除祭坛带来的效果
		OblationLevelUp( itor->first,eALTAR_DELETE);
	}
	
	//向客户端更新祭坛
	UpdateAltarMsg();
}

//----------------------------------------------------
//人物上线时 加载祭坛的特效
//----------------------------------------------------
void CPlayer::LoadAllAltar(UINT ID)
{
	m_pConsortia->OblationLevelUp(this,ID,eALTAR_LOAD_EFFECT);
}

void CPlayer::UpdateAltarMsg()
{
	//发送祭坛消息
	MSG_ALTAR_INFO altar_info;
	altar_info.Head.usSize = sizeof( MSG_ALTAR_INFO );
	altar_info.Head.usType = _MSG_ALTAR_INFO;

	map<UINT,UINT>::iterator itor = m_Altar.begin();
	int i=0; 
	for (; itor!= m_Altar.end(); itor++)
	{
		if (itor->second != 0)
		{
			altar_info.Altar[i].AltarID = itor->first;
			altar_info.Altar[i].Grade = itor->second;
			i++;
		}
	}
	altar_info.iAltarCounts = i;
	CGameObject::s_World->SendMsgToClient( &altar_info, GetSocket() ); 
}

UINT  CPlayer::GetVendAttr(int Type)
{
	enum eType{ITEM_TRADE_PRESTIGE,ITEM_TRADE_CONSORTIA_CONTRIBUTE,ITEM_TRADE_MONEY,ITEM_TRADE_BIJOU};
	switch( Type )
	{
	case ITEM_TRADE_PRESTIGE:
		return GetlPrestige();
		break;
	case ITEM_TRADE_CONSORTIA_CONTRIBUTE:
		break; 
	case ITEM_TRADE_MONEY:
		break;
	case ITEM_TRADE_BIJOU:
		break;
	default:
		break;
	}
}

void CPlayer::SendAddItem(ItemData& itemData ,Item& item)
{
	//发送物品增加消息
	MSG_SYS_ADD_ITEM add_item;
	add_item.Head.usSize = sizeof( MSG_SYS_ADD_ITEM );
	add_item.Head.usType = _MSG_SYS_ADD_ITEM;

	add_item.itemData = itemData;

	//判断包裹是否有空位
	int ItemNum = 0;
	ItemNum = GetFreeItemOverlap(&item);
	if (ItemNum < itemData.Overlap)
	{
		//外挂
		return ;
	}
	CGameObject::s_World->SendMsgToClient( &add_item, GetSocket() ); 

}

void CPlayer::SubOverlap()
{
	if(TempScriptItem!=NULL)
	{
		if ((--TempScriptItem->m_Overlap) == 0)
			TempScriptItem->Clear();
	}
	else
	{
		sbase::ConsoleWriteColorText( FOREGROUND_GREEN,"TempScriptItem=null" );
	}
}

void CPlayer::SendUseOrEquip(int type)
{
	if( !type )
	{
		msg_useorequip_item.Index = (USHORT)TempScriptIndex;
		msg_useorequip_item.Num = (USHORT)TempScriptNum;
		msg_useorequip_item.uiID = GetID();
		msg_useorequip_item.False = false;
		msg_useorequip_item.ChangeF=GetcHairStyle();
		GetRegion()->SendAreaMsgOneToOther( GetCurrentCell(), &msg_useorequip_item );
		msg_useorequip_item.ChangeF=0;
	}
	else
	{
		MSG_SKILL_UPGRADE  Skill_UpGrade;
		Skill_UpGrade.Head.usSize = sizeof( MSG_SKILL_UPGRADE );
		Skill_UpGrade.Head.usType = _MSG_SKILL_UPGRADE;
		Skill_UpGrade.uiSkillID   = -1;
		Skill_UpGrade.uiPlayerID  = GetID();
		//Skill_UpGrade.uiCurrentSkillGrade = m_PassiveSkill[ ucSkillID ].Grade;
		//Skill_UpGrade.uiNextSkillGradePoint = CPeizhi::Instance()->GetPlayerSkillGradePoint( m_PassiveSkill[ ucSkillID ].Grade, pskill->ucID );
		Skill_UpGrade.uiSurplusPoint = m_ConvertPoint;
		s_World->SendMsgToClient( &Skill_UpGrade, GetSocket() );
	}
}

bool CPlayer::OnRead()
{
	if (m_pSocket == NULL)
	{
		return false;
	}

	sbase::MsgHead* pszBuff = NULL;

	if (m_pSocket->IsValid())
	{
		if ( m_pSocket->GetiSpace() <= 8192 )
		{
			AddDanger( 3 );
			sbase::LogException("Message type Exception ,Accounts : %s, Role: %s,[Too many packet]", GetAccounts(), GetName() );
			return true;
		}

		int Turn = 0;
		while (m_pSocket->Read((char**)&pszBuff) && Turn <= 50 )
		{
			
			if ( pszBuff->usSize == 0 )
			{
				AddDanger(3);
				sbase::LogException("Message type Exception ,Accounts : %s, Role: %s,[Packet is zero ]", GetAccounts(), GetName() );
				return true;
			}

			s_World->m_pSocketHandle->ResloveGamePacket(pszBuff, this);

			m_pSocket->Remove(pszBuff->usSize);
			    
			Turn++;

		}



		return true;
	}
	else
	{
		//客户端关闭
		//printf("%s将延时20秒退出游戏...\n",GetName());
		m_pSocket->GetIOCP()->PushNewClose(m_pSocket);
        //DelayExit(max(PLAYER_DEAD_TIMER - PassTime,0));
		DelayExit(0);
		return false;
		
	}
	


}

void CPlayer::DelayExit( time_t time )
{
	m_DelPlayerTimer.Startup(time);
	m_pSocket = NULL;
}

bool CPlayer::OnSend()
{
	if (m_pSocket == NULL)
	{
		return false;
	}

	if (m_pSocket->IsValid())
	{
 		 if ( !m_pSocket->Write() )
 		 {
 			 m_pSocket->GetIOCP()->PushNewClose(m_pSocket);
 			 DelayExit(0);
 			 return false;
 		 }
 		 else
            return true;
	} 
	else
	{
		//客户端关闭
		//printf("%s将延时20秒退出游戏...\n",GetName());
		m_pSocket->GetIOCP()->PushNewClose(m_pSocket);
	    //DelayExit(max(PLAYER_DEAD_TIMER - PassTime,0));
		DelayExit(0);
		return false;		

	} // end if_else
	
}

bool CPlayer::IsMove()
{
	if (m_DelPlayerTimer.IsActive())
	{
		if (m_DelPlayerTimer.IsExpire())
		{

			for( list< tarSceneChange* >::iterator it = s_World->g_listSceneChange.begin(); it != s_World->g_listSceneChange.end(); it++ )
			{
				tarSceneChange* p = *it;
				if(p->pPlayer->GetID() == GetID() )
				{
					SAFE_DELETE( p );
					s_World->g_listSceneChange.erase(it);
					break;
				}

			}

			if(GetGoldBoxId())
			{
				CDial::Instance()->SetPlayer(this);
				CDial::Instance()->DefaultItem(GetGoldBoxId());
				if(IsDoubleItem())
				{
					CDial::Instance()->SecondItem(GetGoldBoxId());
				}

			}

			if ( GetJoinFlag() )
			{
				if (IsDead())
				{
					Revive( eREVIVE_FREE );

					for ( list< tarSceneChange* >::iterator iter = s_World->g_listSceneChange.begin() ; iter != s_World->g_listSceneChange.end() ; iter++)
					{
						if ((*iter)->pPlayer == this )
						{
							s_World->GetRegion( (*iter)->lFromSceneID )->RemoveObject( (*iter)->pPlayer->GetID() );
							(*iter)->pPlayer->SetPos( (*iter)->x, 0.0f, (*iter)->z );
							(*iter)->pPlayer->SetlRegionID(  s_World->GetRegion((*iter)->lToSceneID)->GetLogicID() ) ;

							SAFE_DELETE(*iter);

							s_World->g_listSceneChange.erase(iter);

							break;
						}
					}
				}
				GetRegion()->RemovePlayer( this );
			}

			//防止重复登陆后造成先登陆的玩家帐号清掉
			CPlayer *pPlayer = GetPlayerFromAccounts( GetAccounts() );
			if ( pPlayer ==  this )
			{
				DelAccountsHashMap( GetAccounts() );
			}

			DelRoleNameHasnMap( GetName() );	
			DelSocketHashMap( GetSocket() );

			LeaveTeam_New();
			s_World->RemovePlayer(this);

		    return true;
		}
	}

	return false;
}

void CPlayer::ExitGame_TimeStart()
{
	m_bExitGameStart = true;
	m_UpdateTime.Startup( PLAYER_DEAD_TIMER );
	m_Start_Time = GetTickCount();
	PassTime = 0;

}
void CPlayer::ExitGame_TimeEnd()
{
	m_bExitGameStart = false;
	m_UpdateTime.Clear();
	PassTime = 0;
}
bool CPlayer::GetTimeStart()
{
	return m_bExitGameStart;
}
void CPlayer::Updata_SurplusTime()
{
	if ( m_UpdateTime.IsExpire() )
	{
		m_bExitGameStart = false;
		PassTime = PLAYER_DEAD_TIMER;
		return;
	}

	time_t Cur_Time = timeGetTime();
	time_t count = Cur_Time - m_Start_Time;
	PassTime =count;
}

bool CPlayer::IsEnterWorld()
{
	return (m_WorldStatus == eGAMEWORLD)?true:false;
}

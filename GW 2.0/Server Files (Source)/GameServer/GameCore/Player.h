//========================================================
//
//    Copyright (c) 2006,欢乐连线工作室
//    All rights reserved.
//
//    文件名称 ： Player.h
//    摘    要 ： 动态对象功能模块
//    
//    当前版本 ： 1.00
//    作    者 ： 林德辉
//    完成日期 ： 2007-01-17
//
//    修    改 ： 李锋军
//    完成日期 ： 2007-02-10
//
//========================================================

 
#pragma once
#include "../stdafx.h"
#include <WinSock2.h>
#include "GameObject.h"
#include "Bag.h"
#include "Storage.h"
#include "Trade.h"
#include "Stall.h"
#include "QuestDef.h"
#include "EquipForge.h"
#include <valarray>
#include <iostream>
#include <algorithm>
#include <hash_map>
#include <vector>
#include <map>
#include ".\RoleRelation.h"
#include "../../common/msgdefine.h"
#include "..\ErrorMessage.h"
#include "../World.h"

#define PLAYER_AI_TIMER			100				// 毫秒
#define PLAYER_DEAD_TIMER		20000	


#ifndef  GODSWAR_TESTSWITCH_ON
#define   GODSWAR_TESTSWITCH_ON  
#endif

#undef  GODSWAR_TESTSWITCH_ON

#define  MAX_ONLINE_PLAYER 5000
#define  GODSKILL_ID  6000
#define MAX_ROLENAME_SIZE 16
#define MAX_CONSORTIA_GRADE 12

enum PLAYTE_MSG_FLAG
{   
	MSG_ATTRIBUTE_FLAG,
	MSG_SKILL_ACTIVE_FLAG,
	MSG_SKILL_PASSIVE_FLAG,
	MSG_KITBAG_FLAG,
	MSG_RELATION_FRIENDS_FLAG,
	MSG_RELATION_BLACKLIST_FLAG,
	MSG_RELATION_CONSORTIA_FLAG,
	MSG_QUEST_FLAG,
	MSG_ALTAR_FLAG,
	MSG_SENDFLAG_COUNT,
};
/*by lion
enum PLAYER_SKILL_TYPE
{
SKILL_HALENESS,            //健壮
SKILL_FEAT,                //武艺
SKILL_DEFEND,              //防御
SKILL_ARMOURP_ROCTECT,     //甲胄保护
SKILL_GLAVE_GAS,           //剑气
SKILL_ESCRIME,             //剑术
SKILL_EXACTITUDE_ATTACK,   //精准攻击
SKILL_MUMP,                //斗气
SKILL_ENERGY,              //活力
SKILL_ELEMENTS_STRENGTHEN, //元素强化
SKILL_ELEMENTS,            //元素原理
SKILL_ELEMENTS_DEFEND,     //元素抵抗
SKILL_ELEMENTS_VOLITION,   //元素意志
SKILL_FIR_STRENGTHEN,      //火焰强化
SKILL_FLEXILE,             //柔韧护盾
SKILL_LIFE_CHANNELS,       //生命通道

};
*/
enum eCharacterAttribute
{
	CHARACTER_ID,                                          //角色ID
	CHARACTER_ACCOUNTS_ID,                                 //帐号ID
	CHARACTER_NAME,                                        //角色名称
	CHARACTER_GENDER,                                      //角色性别
	CHARACTER_GMFLAG,                                      //GM标志 
	CHARACTER_CAMP,                                        //角色阵营
	CHARACTER_PROFESSION,                                  //角色职业
	CHARACTER_LV,					                       //等级
	CHARACTER_SCHOLAR_LV,                                  //学者职业等级  已停用@@@
	CHARACTER_EXP,					                       //经验
	CHARACTER_SCHOLAR_EXP,                                 //学者经验      已停用@@@
	CHARACTER_HP_CUR,                                      //HP当前
	CHARACTER_MP_CUR,                                      //MP当前
	CHARACTER_STAUS,                                       //状态
	CHARACTER_BELIFE,                                      //信仰
	CHARACTER_PRESTIGE,                                    //声望
	CHARACTER_EARL_RANK,                                   //爵位
	CHARACTER_CONSORTIA,                                   //工会
	CHARACTER_CONSORTIA_JOB,                               //工会职业
	CHARACTER_CONSORTIA_CONTRIBUTE,						   //工会贡献
	CHARACTER_STORE_NUM,								   //仓库个数
	CHARACTER_BAG_NUM,									   //包裹个数
	CHARACTER_HAIRSTYLE,                                   //发型
	CHARACTER_FACESHAP,									   //脸型
	CHARACTER_CURMAP,                                      //当前地图
	CHARACTER_CURPOS_X,                                    //当前X坐标
	CHARACTER_CURPOS_Z,                                    //当前Z坐标
	CHARACTER_MONEY,                                       //金钱
	CHARACTER_STONE,                                       //宝石
	CHARACTER_SKILLPOINT,                                  //金钱
	CHARACTER_SKILLEXP,                                    //宝石
	CHARACTER_MAXHP,                                       //最大HP
	CHARACTER_MAXMP,                                       //最大MP
	CHARACTER_REGISTER_TIME,                               //角色注册时间
	CHARACTER_LASTLOGIN_TIME,                              //最后登录时间
	CHARACTER_MUTE_TIME,                                   //总在线时间	
	CHARACTER_EQUIP,                                       //装备
};


enum EquipType
{
	EquipHead = 0,		//头盔
	EquipAmulet,		//护身符
	EquipGlove,			//手套
	EquipArmor,			//盔甲
	EquipCuff,			//护腕
	EquipGirdle,		//腰带
	EquipShoes,			//鞋子
	EquipLeggins,		//护胫
	EquipRing1,			//戒指1
	EquipRing2,			//戒指2
 
	EquipMainHand1,		//主手1
	EquipAuxiliaryHand1,//副手1

	EquipCount
};


enum eTimeQuest
{
	TIME_NO_ACCEPT =0 ,
	TIME_ACCEPT ,
};

enum eAltarDealType
{
	eALTAR_LEVEL_UP,  //供奉祭坛的升级处理
	eALTAR_DELETE,	  //供奉祭坛的删除处理
	eALTAR_LOAD_EFFECT //供奉祭坛在人物上线时的祭坛效果加载

};

enum eReviveType
{
	eREVIVE_STONE,	//金币复活
	eREVIVE_MONEY,	//银币复活
	eREVIVE_FREE,	//免费复活
};
//MYSQL SP
//#define  _MAKE_PLOY_
#ifndef _MAKE_PLOY_ 
static char*  SQL_SELECT_SAME_ROLE         		=  "CALL SP_INSERT_ROLE_INFO(\'%s\',\'%s\',\'%s\',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);";
static char*  SQL_SELECT_ROLE_INFO         		=  "CALL SP_SELECT_ROLE_INFO(\'%s\');";
static char*  SQL_SELECT_PLAYER_INFO       		=  "CALL SP_SELECT_PLAYER_INFO(%d);"; 
static char*  SQL_SELECT_KITBAG_INFO       		=  "CALL SP_SELECT_KITBAG_INFO(%d);";
static char*  SQL_SELECT_ACTIVESKILL_INFO  		=  "CALL SP_SELECT_ACTIVESKILL_INFO(%d);"; 
static char*  SQL_SELECT_PASSIVEKILL_INFO  		=  "CALL SP_SELECT_PASSIVESKILL_INFO(%d);";
static char*  SQL_SELECT_ALTAR_INFO				=  "CALL SP_SELECT_ALTAR_INFO(%d);";
static char*  SQL_SELECT_RELATION_INFO       	=  "CALL SP_SELECT_RELATION_INFO(%d);";
static char*  SQL_INSERT_ROLE_INFO         		=  "CALL SP_INSERT_ROLE_INFO(\'%s\',\'%s\',\'%s\',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);";
static char*  SQL_UPDATE_ROLE_INFO         		=  "CALL SP_UPDATE_ROLE_INFO(%d,\'%s\',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%0.4f,%0.4f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\'%s\',\'%s\');";
static char*  SQL_DELETE_ROLE_INFO         		=  "CALL SP_DELETE_ROLE_INFO(%d);";
static char*  SQL_UPDATE_KITBAG_INFO       		=  "SET NAMES 'GBK';CALL SP_UPDATE_KITBAG_INFO(%d,%d,\'%s\');";
static char*  SQL_UPDATE_ACTIVESKILL_INFO       =  "CALL SP_UPDATE_ACTIVESKILL_INFO( %d, \'%s\' );";
static char*  SQL_UPDATE_PASSIVESKILL_INFO      =  "CALL SP_UPDATE_PASSIVESKILL_INFO( %d, \'%s\' );";
static char*  SQL_UPDATE_ALTAR_INFO				=  "CALL SP_UPDATE_ALTAR_INFO(%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);";
static char*  OFFLINE_SQL_UPDATE_ALTAR_INFO		=  "CALL OFFLINE_SQL_UPDATE_ALTAR_INFO(\'%s\');";
static char*  OFFLINE_SQL_UPDATE_ONE_ALTAR_INFO	=  "CALL OFFLINE_SQL_UPDATE_ONE_ALTAR_INFO(\'%s\',%d);";
static char*  SQL_UPDATE_RELATION_INFO       	=  "SET NAMES 'GBK';CALL SP_UPDATE_RELATION_INFO(%d,%d,\'%s\');";
static char*  SQL_UPDATE_CONSORTIA_INFO         =  "CALL SP_UPDATE_CONSORTIA_INFO(%d,\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',%d, %d, %d, %d,\'%s\');";
static char*  OFFLINE_SQL_UPDATE_UNION          =  "CALL OFFLINE_SQL_UPDATE_UNION( \'%s\',%d,%d,%d );";
static char*  SQL_DELETE_CONSORTIA_INFO			=  "CALL SP_DELETE_CONSORTIA_INFO(%d);";
static char*  SQL_SELECT_QUEST_INFO             =  "CALL SP_SELECT_QUEST_INFO( %d );";
static char*  SQL_UPDATE_QUEST_INFO             =  "CALL SP_UPDATE_QUEST_INFO( %d, \'%s\',\'%s\',\'%s\' );";
#else
static char*  SQL_SELECT_SAME_ROLE         		=  "CALL PLOY_SP_INSERT_ROLE_INFO(\'%s\',\'%s\',\'%s\',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);";
static char*  SQL_SELECT_ROLE_INFO         		=  "CALL PLOY_SP_SELECT_ROLE_INFO(\'%s\');";
static char*  SQL_SELECT_PLAYER_INFO       		=  "CALL PLOY_SP_SELECT_PLAYER_INFO(%d);"; 
static char*  SQL_SELECT_KITBAG_INFO       		=  "CALL PLOY_SP_SELECT_KITBAG_INFO(%d);";
static char*  SQL_SELECT_ACTIVESKILL_INFO  		=  "CALL PLOY_SP_SELECT_ACTIVESKILL_INFO(%d);"; 
static char*  SQL_SELECT_PASSIVEKILL_INFO  		=  "CALL PLOY_SP_SELECT_PASSIVESKILL_INFO(%d);";
static char*  SQL_SELECT_RELATION_INFO       	=  "CALL PLOY_SP_SELECT_RELATION_INFO(%d);";
static char*  SQL_INSERT_ROLE_INFO         		=  "CALL PLOY_SP_INSERT_ROLE_INFO(\'%s\',\'%s\',\'%s\',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);";
static char*  SQL_UPDATE_ROLE_INFO         		=  "CALL PLOY_SP_UPDATE_ROLE_INFO(%d,\'%s\',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%0.4f,%0.4f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\'%s\',\'%s\');";
static char*  SQL_DELETE_ROLE_INFO         		=  "CALL PLOY_SP_DELETE_ROLE_INFO(%d);";
static char*  SQL_UPDATE_KITBAG_INFO       		=  "SET NAMES 'GBK';CALL PLOY_SP_UPDATE_KITBAG_INFO(%d,%d,\'%s\');";
static char*  SQL_UPDATE_ACTIVESKILL_INFO       =  "CALL PLOY_SP_UPDATE_ACTIVESKILL_INFO( %d, \'%s\' );";
static char*  SQL_UPDATE_PASSIVESKILL_INFO      =  "CALL PLOY_SP_UPDATE_PASSIVESKILL_INFO( %d, \'%s\' );";
static char*  SQL_UPDATE_RELATION_INFO       	=  "SET NAMES 'GBK';CALL PLOY_SP_UPDATE_RELATION_INFO(%d,%d,\'%s\');";
static char*  SQL_UPDATE_CONSORTIA_INFO         =  "CALL PLOY_SP_UPDATE_CONSORTIA_INFO(%d,\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',\'%s\',%d, %d, %d, %d,\'%s\');";
static char*  OFFLINE_SQL_UPDATE_UNION          =  "CALL PLOY_OFFLINE_SQL_UPDATE_UNION( \'%s\',%d,%d );";
static char*  SQL_DELETE_CONSORTIA_INFO			=  "CALL PLOY_SP_DELETE_CONSORTIA_INFO(%d);";
static char*  SQL_SELECT_QUEST_INFO             =  "CALL PLOY_SP_SELECT_QUEST_INFO( %d );";
static char*  SQL_UPDATE_QUEST_INFO             =  "CALL PLOY_SP_UPDATE_QUEST_INFO( %d, \'%s\',\'%s\',\'%s\' );"; 
#endif

typedef struct  
{
	PARAMETER_LIST  Figher_Parm;
	PARAMETER_LIST  Scholar_Parm;
	DEFAULT_LIST    Default_Value;
	float           Grade_A;
	float           Grade_B;
	float           Grade_C;
	float           Skill_A;
	float           Skill_B;
	float           Skill_C;	
} PARAME ;



//管道通讯用

enum SQL_STYLE
{
	TYPE_ROLE_ATTRIBUTE = 10,
	TYPE_ROLE_ACTIVESKILL,
	TYPE_ROLE_PASSIVESKILL,
	TYPE_ROLE_KITBAG1,
	TYPE_ROLE_KITBAG2,
	TYPE_ROLE_KITBAG3,
	TYPE_ROLE_KITBAG4,
	TYPE_ROLE_EQUIP,
	TYPE_ROLE_STORAGE,
	TYPE_ROLE_QUEST,
	TYPE_ROLE_FRIEND,
	TYPE_ROLE_BLACKLIST,
	TYPE_ROLE_CONSORTIA,
	TYPE_ROLE_ALTAR,

	TYPE_MGR_CONSORTIA,
	RYPE_ROLE_COUNT,
};

//08.7.8 by_czq
struct BACKUP_MSG 
{
	MsgHead Head;
// 		UINT  ID;
// 		SQL_STYLE  Type;
	char  SQL[4000];
};


struct  ROLE_ATTRIBUTE
{
	char     Name[32];                          //角色名
	BYTE     ucGender;                          //性别
	BYTE     ucCamp;                            //阵营
	BYTE     uProfession;                       //职业
	BYTE     ucHairStyle;                       //发型
	BYTE	 ucFaceShap;						//脸型
	BYTE     ucBelief;                          //信仰
	bool     bIsSuccess;                        //是否添加成功
} ;

class CRegion;
class CPlayer;


struct SkillBackup 
{
	int RSkillID;
	int RItemID;

	int SkillID[SKILLBACKUPCOUNT];
	int ItemID[SKILLBACKUPCOUNT];
};

class NameHasher : public stdext::hash_compare <std::string>
{
public:
	size_t operator() (const std::string& s) const
	{
		size_t h = 0;
		std::string::const_iterator p, p_end;
		for(p = s.begin(), p_end = s.end(); p != p_end; ++p)
		{
			h = 31 * h + (*p);
		}
		return h;
	}
	bool operator() (const std::string& s1, const std::string& s2) const
	{
		return s1 < s2;
	}
};

typedef stdext::hash_map<snet::CSocket*, CPlayer*>  HASH_INT;
typedef stdext::hash_map<std::string, CPlayer*, NameHasher> HASH_STR;

enum GAMESTATUS { eROLEINFOWAIT , eROLELOGIN , eLOADMAP, eGAMEWORLD , eSCENECHANGE };

class CPlayer :	public CGameObject, private IObj
{
	typedef struct
	{
		PARAMETER_LIST  Parm;
		//by lion	PARAMETER_LIST  Scholar_Parm;
		DEFAULT_LIST    Default_Value;

	} PARAM ;
public:
	CPlayer(void);
	~CPlayer(void);

	LONG GetDBID();

	void Activate( void );
	//设置玩家对应SOCKET
	void SetSocket( snet::CSocket *pSocket ) { m_pSocket = pSocket; CPlayer::AddSocketHashMap( pSocket ,this ); }
	//得到玩家对应SOCKET
	snet::CSocket* GetSocket( void ) { return m_pSocket; }
//	void SetSocket(snet::CSocket *pSocket ){m_pSocket = pSocket;}
	Trade* GetTrade(){return &m_Trade;}
	// 属性部分
	CPlayer* GetTeamObject( unsigned int nNumber );
	bool IsLeader( void ) { if (this == m_pTeamLeader)return true; return false;}//return m_bIsLeader; }
	bool IsTeam( void ) { if( m_pTeamLeader != NULL ) return true; return false;}

	//角色适配
	void AddRole( ROLE_ATTRIBUTE Role );
	void SelectRole( string Name );
	void DelRole( string Name );

	eError UpdateRelation( RELATION &role, char &result)  ;
	bool DeleteRelation( const char *RelationName);

	volatile bool    WillRelease;
	volatile long    SynDBOutStand;
	void Init();

	// 用于优化，拆分AI/Run
	virtual void AI( void );
	int CheckBlock(int Mid,float x,float z);
	virtual void Run( void );
	bool OnRead();
	bool OnSend();
	void DelayExit( time_t time );
	sbase::CTimerMS m_RunTimer;

	sbase::CTimerMS m_DelPlayerTimer;
	UINT  GetVendAttr(int Type);
	//重置
	virtual void Release( void )
	{ 
		UpDateDB();

		if ( SynDBOutStand == 0 )
		{
			CGameObject::Release();
		}
		else
		{
			WillRelease = true;
		}
		
	}

	void  RealActive()
	{
	   CGameObject::Release();
	}
	virtual bool CalculateExp( bool TarIsDead , int exp = 1 );
	//命中
	ULONG CPlayer::GetHit();
	//躲避
	ULONG CPlayer::GetDodge();
	//角色HP恢复
	UINT GetHPRecover();
	//角色MP恢复
	UINT GetMPRecover();

	void SendNoteToClient( const char * Note );  //弹出式消息
	void SendSysNoteToClient(const char * Note); //左下角的系统消息
	void SendMidNoteToClient(const char* Note);//出现在屏幕中间的消息
	//重新刷新时间
	void ResetTimer( float  IntervalTime ,TIME_STYLE timeStyle);
	//是否超时
	bool IsRefresh( TIME_STYLE timeStyle );
	void SetPropertyValue( unsigned int ivalue, USERDATA  stData );
	void SetPropertyValue( const char* ivalue, USERDATA  stData );
	LONG GetPropertyValue(USERDATA  stData );
	SHORT GetPropertyValue(USERDATA  stData ) const;
	const char* GetIP(){ return m_pSocket->GetPeerIP();};
	const char* GetAccounts(){ return m_Accounts.c_str();};
	void  SetName( const char * RoleName ){ __super::SetName( RoleName );CPlayer::AddRoleNameHashMap( m_ObjectData.m_strName, this ); };
	//---------------------------------------------------------------------------------------------
	void  SetRegisterTime( const char * RegisterTime ){ strcpy( m_RegisterTime, RegisterTime ); };
	void  SetOnlineTime( UINT uiOnline ){ m_OnlineTime = uiOnline; };
	const char *  GetRegisterTime(){ return m_RegisterTime;};
	UINT  GetOnlineTime(){ return m_OnlineTime; };
	//---------------------------------------------------------------------------------------------
	void  SetAccounts(string Accounts){  m_Accounts = Accounts;CPlayer::AddAccountsHashMap( Accounts, this ); };
	const char* GetValidCode(){ return m_ValidCode.c_str(); };
	void SetValidCode( string ValidCode){ m_ValidCode = ValidCode;};
	bool GetJoinFlag(){ return m_HaveJoin;};
	void SetJoinFlag( bool Flag ){ m_HaveJoin = Flag; if( Flag ) {ResetResumeTimer(); ResetRelationTimer();} };
	bool FindRoleByName( const void* pBuf ); 
	void RefreshRelation();

	//最后一条消息
	void SetLastMsg(int);
	int GetLastMsg(){ return m_cMsg ;}

	//最后一个开始行走的坐标
	void SetLastPos( float X, float Z ){ m_BeginX = X; m_BeginZ = Z; }
	void GetLastPos( float &X, float &Z ){  X = m_BeginX ; Z = m_BeginZ ; };

	//初始化玩家数据（从数据库获取）
	bool InitObjData(long  ID)  ;
	//根据被动技能改变角色属性值
	void UpdateAttributeInfo( UINT  SkillID, AttributeType Type = TYPE_UPDATE );
	//主动技能开始冷却的时间
	bool SetActiveSkillStartTime( int ucSkillID);
	//设置当前技能的ID
	void SetCurActiveSkillID( int ucActiveSkillID);
	//获得当前技能的ID
	int GetCurActiveSkillID();
	//设置该玩家获得的最后一条消息类型
	void SetLastMsg(char MsgID);

	//添加被动技能等级或者改变已有技能登记
	void AddPassiveSkill( int ucSkillID, int iRank = 1, int EXP = 0);
	//找到被动技能
	bool DelPassiveSkill( int ucSkillID );
	//找到被动技能
	bool FindPassiveSkill( int ucSkillID,UINT *Degree = NULL  );
	//添加主动技能
	bool AddActiveSkill( int ucSkillID );
	//删除主动技能
	void DelActiveSkill( int ucSkillID );
	//找到主动技能
	bool FindActiveSkill( int ucSkillID );
	//魔法是否处于冷却状态
	bool IsActiveSkillCooling( int ucSkillID );
	//改变魔法状态
	void ChangeActiveSkillStatus( int ucSkillID, TIME_STYLE status );
	//玩家退出时候回写数据库
	bool UpDateDB();
	//发送深恩开始累计的消息
	bool IsGodSkillTimeOut( int MagicID );
	//物理攻击的时候计算各个技能熟练度
	bool CalculatePassivePracticeDegree( PhysiacalAttack Type, ATTACK_TYPE eAttackType, bool IsDead = false );
	//魔法攻击时候计算各个技能熟练度
	void CalculatePassivePracticeDegree(  int MagicID, ATTACK_TYPE eAttackType, bool IsDead = false );
	//计算被攻击物理攻击时候技能熟练度
	void BePhysicalAttackedPassivePracticeDegree( PhysiacalAttack Style, ATTACK_TYPE AttackType );
	//计算被魔法攻击时候的技能熟练度
	void BeMagicAttackPassivePracticeDegree( UINT MagicID,  ATTACK_TYPE AttackType );
	//判断属于哪系魔法
	Magic_Attack JudgeMagicStyle( UINT MagicID );
	//改变技能熟练度 
	bool ChanegeDegree( int ucSkillID, int Buffer);
	UINT GetTotalSkillGrade( );
	bool IsEquipThis( const MagicData*  pMagic  );
	bool IsEquipThis( const SKillData*  pSkill  );
	void SynchronousClientSkill( bool IsMagic);
	//判断技能升级
	bool PassiveSkillUpgrade(UINT  SkillID, int *Rank = NULL );
	//判断是属于那系攻击（仅指物理）
	PhysiacalAttack JudgeWeaponKind()
	{
		int main = EquipMainHand1;
//		int Auxiliary = EquipAuxiliaryHand1;

		if (m_Equips[main].IsClear())
			return ATTACK_UBAEMED;
		else if (m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_Axes || 
			m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_TwoHandsAxes)
			return ATTACK_HAMMER;
		else if (m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_Swords || 
			m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_TwoHandsSwords)
			return ATTACK_CHOP;
		else if (m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_Spears || 
			m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_Javelins)
			return ATTACK_STICK;
		else if (m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_Bows)
			return ATTACK_SHOT;
		else if (m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_Wands || 
			m_Equips[main].GetItemBaseAttribute()->eSkillFlag == SF_Staffs)
			return ATTACK_STAFF;

		return   ATTACK_UBAEMED; 
	}

	//人物升级的处理
	void PlayerUpGrade( bool IsUpGrade );
	//计算人物升级所需要的经验
	void SetNextGradeEXP(  );
	UINT GetNextGradeExp(  );
	//计算物理攻击伤害
	INT CalculateAttackDamage(  CGameObject& pObj , float iPower = 0);
	//计算经验和等级
	void CalculateExpAndLevel( CGameObject& pTarObj );
	//计算声望兑换到的经验的升级处理
	void CalculatePrestigeExpLevel();
	//计算金钱
	void CalculateMoney( CGameObject* pObj );
	//计算魔法攻击伤害
	INT CalculateAttackDamage( int MagicID, CGameObject &pObj );
	//计算攻击力
	UINT CalculateAttack();
	//计算魔法（装备＋被动技能　）
	UINT CalculateMagic();
	size_t GetHaveRoleNum(){ return m_HaveRole.size();};
	//得到数据
	ULONG GetEXP() ;
	UINT GetRank();
	//计算人物基本属性
	ULONG SetAtttibute( );
	//同步数据(区域数据) 
	void  SynGameData( bool IsSelf );
	void  SynClientActiveSkillData();
	void  SynClientPassiveSkillData();
	void  RequestGameData( CPlayer * );
	//同步数据(队伍数据)
	void  SynTeamData( void* buf );

	void AddExp(int exp);
	void ChangePlayeBuniness( int NewBuniness );
	//打包DB数据
	const char *PackRoleAttribute();
	const char *PackEquipInfo();
	const char *PackBagkitInfo( int Index );
	const char *PackStorageInfo();
	const char *PackConsortiaInfo();
	const char *PackFriendInfo();
	const char *PackBackList();
	const char *PackActiveSkill();
	const char *PackPassiveSkill();
	const char *PackAltarInfo();
	const char *PackQuest();


	//校验码缓存
	static void CacheValidCode( string Accounts, string Valid );
	static void ClearValidCode(  snet::CSocket* PSocket  );
	static void CacheSocket(  snet::CSocket* PSocket, string strAccounts );
	//验证校验码
	bool ValidateLogin( string validcode );
	UINT GetDBIDByRoleName( string RoleName);

	//玩家搜索同步(Hash)
	static void AddSocketHashMap( snet::CSocket* PSocket,CPlayer *pPlayer );
	static void DelSocketHashMap( snet::CSocket* PSocket );
	static CPlayer *GetPlayerFromSocket( snet::CSocket* PSocket );

	static void AddAccountsHashMap( string accounts,CPlayer *pPlayer );
	static void DelAccountsHashMap( string accounts );
	static CPlayer *GetPlayerFromAccounts( string accounts );

	static void AddRoleNameHashMap( string rolename,CPlayer *pPlayer);
	static void DelRoleNameHasnMap(  string rolename );
	static CPlayer *GetPlayerFromRoleName( string rolename );

	//得到验证码
	static string GetValidCode( string Accounts );

	//数据发送
	void SendSkillMsg( bool IsActive );
	void SendKitBagMsg(int flag );
	void SendPropertyMsg( void );
	void SendStorageMsg( void );
	void SendRelationMsg( void );
	void SendConsortiaMsg( void );
	void SendAltarMsg(void);

	//GM操作
	static bool GM_Handler_kick( ActionElem &elem );
	static bool GM_Handler_speak( ActionElem &elem );
	static bool GM_Handler_item( ActionElem &elem );

	//数据处理
	static void DealWith_Select_RoleAttribute( dbtool::PSQL_RESULT result );
	static void DealWith_Select_KitBag( dbtool::PSQL_RESULT result );
	static void DealWith_Select_ActiveSkill( dbtool::PSQL_RESULT result );
	static void DealWith_Select_PassiveSkill( dbtool::PSQL_RESULT result );
	static void DealWith_Select_Altar(dbtool::PSQL_RESULT result );
	static void DealWith_Select_Relation( dbtool::PSQL_RESULT result );
	static void DealWith_Select_RoleBaseInfo( dbtool::PSQL_RESULT result );
	static void DealWith_Select_CanRoleAdd( dbtool::PSQL_RESULT result );
	static void DealWith_Select_CanConsortiaAdd( dbtool::PSQL_RESULT result );
	static void DealWith_Select_Quest( dbtool::PSQL_RESULT result );

	//数据更新
	static void UpdateDB_RoleAttribute( CPlayer *pPlayer );
	static void UpdateDB_KitBag(  CPlayer *pPlayer );
	static void UpdateDB_ActiveSkill(  CPlayer *pPlayer );
	static void UpdateDB_PassiveSkill(  CPlayer *pPlayer );
	static void UpdateDB_Relation(  CPlayer *pPlayer );
	static void UpdateDB_Quest( CPlayer *pPlayer );
	void UpdateDB_Offline( const char *Name, UINT Union, BYTE UnionDuty );
	void UpdateDB_Altar( const char *Name );

	//结果处理
	static void DealWith_Update_RoleAttribute( dbtool::PSQL_RESULT result );
	static void DealWith_Update_KitBag( dbtool::PSQL_RESULT result );
	static void DealWith_Update_ActiveSkill( dbtool::PSQL_RESULT result );
	static void DealWith_Update_PassiveSkill( dbtool::PSQL_RESULT result );
	static void DealWith_Update_Relation( dbtool::PSQL_RESULT result );
	static void DealWith_Update_RoleDel( dbtool::PSQL_RESULT result );
	static void DealWith_Update_RoleUpate( dbtool::PSQL_RESULT result );
	static void DealWith_Update_Friend( dbtool::PSQL_RESULT result );
	static void DealWith_Update_BlackList( dbtool::PSQL_RESULT result );
	static void DealWith_Update_Consortia( dbtool::PSQL_RESULT result );
	static void DealWith_Offline_Update_Uinon( dbtool::PSQL_RESULT result );
	static void DealWith_Update_Quest( dbtool::PSQL_RESULT result );

	//数据请求
	void RequestGameDataFromDB( const void* pBuf );
	void RequestBaseRoleInfoFromDB( const void* pBuf  );
	void RequestAddRoleFromDB( const void* pBuf );
	void RequestDelRoleFromDB( const void* pBuf );
	void RequestAddConsortiaFromDB( const void* pBuf );

	//DB数据处理
	void ( *OnProcess_Attribute ) ( CPlayer *pPlayer,void *Loader );
	void ( *OnProcess_KitBag )( CPlayer *pPlayer );
	void ( *OnProcess_PassiveSkill )( CPlayer *pPlayer );
	void ( *OnProcess_ActiveSkill )( CPlayer *pPlayer );
	AttackRadius GetAttackRadius();

// 	//聊天专用
// 	void TalkToMap( const char* pBuf, int nSize, BYTE ucType );//普通
// 	void TalkToCamp( const char* pBuf, int nSize, BYTE ucType );//阵营
// 	void TalkToTeam( const char* pBuf, int nSize, BYTE ucType );//队伍聊天
// 	void TalkToUnion( const char* pBuf, int nSize, BYTE ucType );//工会
// 	void TalkToPlayer( CPlayer *pPlayer, const char* pBuf, int nSize,BYTE ucType );//私聊

	//备份数据
	bool  BackUp();
	bool  BackUP_RoleAttribute( void );
	bool  BackUp_KitBag( void );
	bool  BackUp_ActiveSkill( void );
	bool  BackUp_PassiveSkill( void );
	bool  BackUp_Relation( void );
	bool  BackUp_Quest( void );


	//公会相关消息
	void  SendConsortiaInvite(void);
	void  SendConsortiaExit(void);
	void  SendConsortiaRespond(void);
	void  SendConsortiaBroadcast(void);

	//捡物品
	bool PickupDrops(Item* p);
	//使用或装备
	bool UseQuestItem(int questid);
	Item* GetEquip(){ return m_Equips;}

// 	/*------------------------------------------------------------------------------
// 	 *作者：C.D
// 	 *日期：2008-06-01
// 	 *描述：遍历身上装备的装备，如果期限到，则将他们删除
// 	 -----------------------------------------------------------------------------*/
// 	void    SendEquipTimeEnd(int index,int type,int bagnum);
// 	void	ClearExpiredItem( void );
// 	bool	IsExpired(tm*	_pTime);
// 	void	SetItemActivated(Item* _pItem, bool	_IsActivated); 

	bool UseOrEquip(int index , int num);
	bool SetEquip(int index , int num , int indexaim);
	bool MoveEquip(int index , int indexaim , int numaim);
	int  MoveItem(int index , int num , int indexaim , int numaim /*,int overlay = 0*/);
	//拆分物品
	int  BreakItem(int index , int num , int indexaim , int numaim ,int overlay = 0);
	void AddItem(Item* item , int index , int num);
	void AddItem(Item* item , int count);
	bool AddItem(Item* item);

	Item* FindItem(int id,int* bag,int* num);
	bool  DelItem(int index,int num);
	Item* TempScriptItem;
	int   TempScriptIndex;
	int   TempScriptNum;
	void  SubOverlap();
	void  SendUseOrEquip(int type);

	eError SellItem(int index , int num);
	Item* GetItem(int index , int num);
	int GetFreeItemCount();
	int GetFreeItemOverlap(Item* p);

	Storage* GetStorage(){return &m_Storage;}
	Stall* GetStall(){return &m_Stall;}

	bool StorageToBag(int index);
	bool StorageToBag(int index , int baginex , int bagnum);
	bool BagToStoragePly(int baginex , int bagnum,int num);
	bool BagToStorage(int baginex , int bagnum , int index);

	//钱
	int GetMoney() const;
	int GetBijou() const;
	void SetMoney(int money);
	void SetBijou(int bijou);
	void AddMoney(int money);
	void AddBijou(int bijou);
	void AddPrestige(int Prestige);
	void AddPoint(int Point);

	virtual HandType GetHandType();
	virtual eError Revive( int type );    //复活类型0：金币复活 1： 银币复活 2：免费复活
	virtual void Dead( CGameObject  *pObj );

	void Fly(int id , float x = 0 , float y = 0 , float z = 0);

	void ChangeAttackSpeed();
	void ChangeHp();

	//将其他对象信息同步给自己
	virtual void AynObjToObj( CCell *pOldCell, CCell *pNewCell );
	//将自己的信息同步给其他玩家
	virtual void AynMeToOther( CCell *pOldCell, CCell *pNewCell );

	//公会相关
	//******************************************************************************************************************
	long GetConsortia_lfound()							//获取公会资金
	{
		if ( m_pConsortia )
		{
			return m_pConsortia->lfound;
		}
		return 0;
	};
	void SetConsortia_lfound( long lfound)				//设置公会资金
	{
		if ( m_pConsortia )
		{
			m_pConsortia->lfound += lfound;
			if (m_pConsortia->lfound < 0 )
			{
				m_pConsortia->lfound = 0;
			}
		}
	};
	long GetConsortia_lbijou()							//获取公会宝石
	{
		if ( m_pConsortia )
		{
			return m_pConsortia->lbijou;
		}
		return 0;
	};
	void SetConsortia_lbijou(long lbijou)				//设置公会宝石
	{
		if ( m_pConsortia )
		{
			m_pConsortia->lbijou += lbijou;
			if ( m_pConsortia->lbijou < 0)
			{
				m_pConsortia->lbijou = 0;
			}
		}
	};
	void SetConsortiaInfo(ConsortiaElem *Consortia)     //设置公会信息    
	{
		m_pConsortia = Consortia; 
		if ( NULL == Consortia )
		{
			SetcUnion(0);
		}
		else
		{
			SetcUnion( (USHORT)Consortia->uiID );
		}

	};        
	ConsortiaElem *GetConsortia(){ return m_pConsortia; };                              //获得自己的公会
	int GetConsortiaLevel(){ return m_pConsortia->iLevel;};								//获得自己公会的等级
	void AddConsortiaMember( ConsortiaRelationElem &rElems );                           //添加成员          
	eError DismissConsortia();                                                          //解散公会 
	bool HaveConsortia();                                                               //是否有公会
	bool IsThisDuty( CONSORTIA_JOB_TYPE Duty );                                         //是否是该公会职务
	bool IsMemeberFull();                                                               //所属公会是否满员
	eError DelMeFromConsortia( );                                                       //删除成员
	eError ChangeConsortiaPlacard( const char *);                                       //修改公会公告
	bool AppointDuty( std::string StrName, CONSORTIA_JOB_TYPE Duty );                   //任命职务
	eError DelMemeber( std::string StrName );                                           //移出成员
	bool BroadcastConsortiaMsg( void* buf );                                            //广播公会消息
	bool BroadcastConsortiaBaseInfo();													//广播公会的基本信息
	bool BroadcastConMemberInfo();														//广播公会成员列表（添加删除或是离开公会是用到）
	int GetConsortiaMaxMember();														//获取公会的人数上限
	int GetConsortiaCurrentMember();													//获取公会的当前人数
	int GetConsortiaMaxAltar();															//返回公会能建造的最大祭坛数
	int GetConCurrentAltarNum();														//获取公会当前的祭坛个数
	vector<int>& GetHavePlayerAltars();													//获取玩家当前已有的供奉祭坛
	void InitAltar(UINT id,UINT level);													//初始化加载数据库的供奉祭坛
	/*--------------------------------------------------------
	功能：公会成员提升公会等级
	参数：无
	返回：bool：提升公会等级成功返回true，否则返回false
	作者：李锋军
	备注：具有相应权限的公会的成员才能提示公会等级
	日期：2008-3-25
	----------------------------------------------------------*/
	eError ConsortiaLevelup();
	/*--------------------------------------------------------
	功能：公会成员提升祭坛等级
	参数：ID：要提升的祭坛ID
	返回：bool：提升该祭坛供奉等级成功返回true，否则返回false
	作者：李锋军
	备注：需要消耗个人公会贡献，提升的等级受公会等级的限制
	日期：2008-3-25
	----------------------------------------------------------*/
	bool AltarLevelUp(int ID);
	/*--------------------------------------------------------
	功能：创建祭坛
	参数：ID：所要创建祭坛的ID
	返回：bool：创建成功返回true，否则返回false
	作者：李锋军
	备注：具有权限的公会玩家创建祭坛
	日期：2008-3-26
	----------------------------------------------------------*/
	bool CreateAltar(int ID);
	/*--------------------------------------------------------
	功能：得到现有祭坛
	参数：
	返回：
	作者：李锋军
	备注：得到现有祭坛
	日期：2008-3-26
	----------------------------------------------------------*/
	vector<int>& GetHaveAltars(){ return m_pConsortia->GetHaveAltars(); };
	/*--------------------------------------------------------
	功能：删除祭坛
	参数：ID：所要删除祭坛的ID
	返回：bool：删除成功返回true，否则返回false
	作者：李锋军
	备注：具有权限的公会玩家删除祭坛
	日期：2008-3-26
	----------------------------------------------------------*/
	bool DelAltar(int ID);
	/*--------------------------------------------------------
	功能：得到确定祭坛的供奉等级
	参数：ID：所要获取的祭坛的ID
	返回：int :玩家对该祭坛的供奉等级
	作者：李锋军
	备注：得到玩家对祭坛的供奉等级
	日期：2008-3-27
	----------------------------------------------------------*/
	UINT  GetOblationLV(int ID);
	
	/*--------------------------------------------------------
	功能：公会成员提升祭坛供奉等级,删除供奉等级,加载供奉等级(脚本处理升级的消耗后回调 UPOblation() 处理玩家的升级)
	参数：ID：要提升的祭坛ID
	返回：bool：提升该祭坛供奉等级成功返回true，否则返回false
	作者：李锋军
	备注：公会成员提升供奉等级
	日期：2008-3-25
	----------------------------------------------------------*/
	bool OblationLevelUp(UINT ID ,eAltarDealType type);
	
	bool  UPOblationLV(UINT ID);  //升级供奉等级后的处理
	bool DelOblation( UINT ID );  //删除供奉等级后的处理


	void ClearAllAltar();					//玩家离开公会或者被公会踢出时就没有祭坛
	void LoadAllAltar( UINT ID );					//人物上线时 加载祭坛的特效
	void UpdateAltarMsg();					//向客户端发送更新祭坛
	void ClearOneAltar(UINT ID);			//(公会删除祭坛时调用)  删除玩家身上对应的祭坛及所影响的数据 （处理在线玩家）
	void ClearOneAltar_fromDB(const char *name,UINT ID);		//(公会删除祭坛时调用)  删除玩家身上对应的祭坛及所影响的数据 （处理下线玩家）
	void DelConMember_AltarInfo( UINT ID );	//(公会删除祭坛时调用)  删除玩家身上对应的祭坛及所影响的数据
	//***************************************************************************************************************************************************

	SQuestStatus* GetAcceptQuest(int id);
	SQuestStatus* GetQuest(int id);

	void Explorer();//探索任务验证
	void FindQuest();
	eError AcceptQuest(int id);
	eError CancelQuest(int id);
	bool CanAcceptQuest(int id , bool db = false);
	void ClearQuest();
	void LoadQuest();
	void ViewQuest(int id);

	void QuestUpdata();
 	void TimeQuestUpdate(int id);
	void TimeOverQuestUpdate(int id);
	eError CompleteQuest(int id , int choice);
	void LevelUpdata();
	bool QuestStatusUpdata(int id);
	bool IfLoopQuestAccepted( int m_questid );
	void QuestKILL(int id);
	void QuestCast(int id);
	eError ChkQsB4Accept( SQuestStatus* sqs );
	void SendAcceptQuestMsg( SQuestStatus* sqs );
	void SendQuestToMembers( SQuestStatus* sqs );
	void ReflashUnavilableVec();//刷新未激活->激活的任务
	void ReflashAvilaVec();//刷新激活->未激活的任务
	void H_ConsortiaQuest(int q_type);//处理公会任务
	void AccpetConsortiaQuest(int index, int q_type);//接受公会任务
	void ConsortiaReward( SQuestStatus* sqs);//公会奖励
	void CastConsortiaQuest();//公会任务消耗
	void CancelConsortiaQuest();//公会任务取消

	EquipForge* GetEquipForge(){return &m_EquipForge;}

	//GM
	void  SetGM( bool isGm ){ m_GM = isGm; }
	bool  IsGM(){ return m_GM; }
	bool  IsMsgOK( PLAYTE_MSG_FLAG Type ){ return m_MsgFlag[ Type ]; };

	void  SetWorldStatus( GAMESTATUS eStatus )
	{ 
		m_WorldStatus = eStatus ; 
		if ( eGAMEWORLD == eStatus )
		{
			time_t  timep;
			time(&timep);
		    m_Login_time=localtime(&timep);
			m_LastUpte_time = m_Login_time;
		}
	  }
	GAMESTATUS  GetWorldStatus(){ return m_WorldStatus ;  }

	bool  IsEnterWorld();
	bool  RefreshLoginQueue( int QueueIndex );
    map<string,UINT> &GetAllRole()
	{
		return  m_HaveRole;
	}

	void AddGMControl( ActionElem &elem );
	bool HasTalkBan(){ return m_GMctr->HaveActionCtr( ACTION_BAN_SPEAK );}
	void DelTalkBan(){ m_GMctr->DelActionCtr( ACTION_BAN_SPEAK );};
public:

	SkillBackup m_SkillBackup;

//组队部分（新）//
public:
	GAMESTATUS m_WorldStatus;
//	CPlayer* m_pTeam[MAX_TEAM_NUMBER];			// 组队信息
	bool	 m_bIsLeader;						// 队长标记
	CPlayer* m_pTeamLeader;						// 队长实体指针

#define Max_TEAMMATES_NUM	4
	
	vector<CPlayer*>	m_Teammates;
public:
	int		CreateTeam_New();
	int		AddTeammate_New(CPlayer* _pPlayer);
	int	RemoveTeammate_New(CPlayer* _pPlayer);
	int		ClearTeam_New();
	bool	ChangeLeader_New(CPlayer* _pPlayer);
	bool	IsTeammate_New(const CPlayer* _pPlayer);
	int		UpdateTeam_New(bool _bIsDateUpdate);
	bool	LeaveTeam_New();
	bool	InitTeam_New();
	void	GetTeamState(int& _count, bool& _IfCouples);
//职业部分 by lion 20080327
	int m_ClassCount;								//职业数量
	vector<vector<int>> m_ClassPassiveSkill;					//职业被动技能表

	bool QuestTeamLimit( int qid );//组队限制检查
	bool QuestClassLimit( int qid );//职业限制检查
	bool QuestConsortiaLimit( int qid );//公会限制
	bool IsConsortiaQuest( int qid );

public:
	Trade	 m_Trade;
 
	void SetSkillMsg( MSG_SKILL* pSkillMsg );
	MSG_SKILL		m_SkillMsg;						// skillmsg备份
 	static ATTACK_PARAM         AttackParam;
   // bool m_SceneChangeFlag;								//场景切换标记
    //del warning
	bool IsGoldBoxExist(int keyid);							//宝箱、钥匙是否存在
    void SetGoldBoxId(UINT base_id){m_GoldBoxId = base_id;}					//设置宝箱ID
    UINT GetGoldBoxId(){return m_GoldBoxId;}						//获取宝箱ID
    void SetInDialItemID(UINT index,UINT ID){m_InDialItemID[index] = ID;}		//设置入围物品ID
    void SetSumRand(UINT Sum){m_SumRand = Sum;}						//设置入围物品总几率
    UINT* GetInDialItemID(){return m_InDialItemID;}					//设置入围物品ID
    UINT GetSumRand(){return m_SumRand;}						//设置入围物品总几率
    bool ExpendGoldBoxId(int gold_box_id,int keyid);		//旧			//宝箱消耗
    bool ExpendGoldBoxKey(BYTE Iter);							//钥匙消耗
    bool ExpendGoldBoxIter(BYTE IterBox,BYTE IterKey,int base_id,int keyid);		//临时			//消耗宝箱和钥匙


    BYTE CanOpenbox(BYTE Iter,UINT base_id,int keyid);							//是否可开启宝箱
    bool IsDoubleItem();								//宝箱计数增加 返回值决定是否双倍发送物品
    void SetCurrentIter(BYTE Iter){current_iter = Iter;}				//设置当前宝箱位置
    BYTE GetCurrentIter(){return current_iter;}						//获取当前宝箱位置
    void SetCurBoxItem(Item& item){memcpy(&cur_box_item,&item,sizeof(Item));}				//设置当前宝箱位置
    Item& GetCurBoxItem(){return cur_box_item;}				//设置当前宝箱位置




// 	/*------------------------------------------------------------------------------
// 	 *作者：C.D
// 	 *日期：2008-06-04
// 	 *描述：商城道具实现的属性修改
// 	 -----------------------------------------------------------------------------*/
// 	void SetChatBubbleType(BYTE _type){m_ChatBubbleType = _type;}
// 	BYTE GetChatBubbleType(void){return m_ChatBubbleType;}



public:
	void SendAddItem(ItemData& itemData ,Item& item);
private:
    sbase::CCriticalSection	m_xLock;
	bool m_GM;
	float m_BeginX,m_BeginZ;
	EquipForge m_EquipForge;
	LONG m_DBID;
	tm  *m_Login_time;
	tm  *m_LastUpte_time;
	//----------------临时--------------------
	char m_RegisterTime[64];
	UINT m_OnlineTime;
	//----------------------------------------

	//玩家SOCKET
	snet::CSocket*	m_pSocket;
	UINT m_NextGradeExp;   //下一个等级升级所需经验

	ConsortiaElem *m_pConsortia;
	dbtool::IRecord *m_pRec;
	int m_cMsg;
	bool m_HaveJoin;    //是否已经加入场景
	string m_valid;
	string m_Accounts;    //帐号
	string m_ValidCode;   //校验码
	bool m_MsgFlag[MSG_SENDFLAG_COUNT];

	//bag
	Bag m_Bags[MAX_BAGS];
	Item m_Equips[EquipCount];
	bool m_bOtherHands;

	Storage m_Storage;
	Stall m_Stall;

	int m_Kills;				//杀怪数量
	int m_OverQuests;			//完成任务数量
	UINT GoldOpendNum;			//宝箱开启次数
	UINT m_GoldBoxId;			//正在开启的宝箱ID
	UINT m_InDialItemID[DIALITEMCOUNT];	//入围物品ID
	UINT m_SumRand;				//入围物品总几率
	BYTE current_iter;			//当前锁定宝箱
	Item cur_box_item;			//当前生成物品

// 	/*------------------------------------------------------------------------------
// 	 *作者：C.D
// 	 *日期：2008-06-04
// 	 *描述：由消费道具中产生的特有属性，例如：聊天气泡的样式
// 	 -----------------------------------------------------------------------------*/
// 	BYTE m_ChatBubbleType;

	SQuestStatus m_Quests[QUEST_COUNT];

	map<int , SQuestStatus*> m_TimeQuestsMap;
	//map<int , SQuestStatus*> m_QuestsMap;

	vector<SQuestStatus*> m_AcceptQuests;
	vector<SQuestStatus*> m_AvailableQuests;
	vector<SQuestStatus*> m_UnavailableQuests;

	//关系管理器
	CRelationManager    m_RelationMgr;

	map<string,ROLE_ATTRIBUTE> m_AddRole;     //新加角色
	map<string,UINT> m_HaveRole;			  //已有角色
	vector<string> m_DeleteRole;              //删除角色

	static PARAME Param;
	static map< string, string > m_valid_map;
	static map<  snet::CSocket*, string>  m_Soket_map;

	static HASH_STR m_Player_RoleName;
	static HASH_STR m_Player_Accounts;
	static HASH_INT m_Player_Socket;

private:
	Item* GetEmpty();
	bool CreatePropFromDB(string DBString, int Index);
    bool CreateActiveSkillFromDB( string DBString );
    bool CreatePassiveSkillFromDB( string DBString );
	bool CreateAllQuestFromDB( string DBString);
	bool CreateTimeQuestFromDB( string DBString, eTimeQuest TimeType );
	// 初始化职业数量以及对应的被动技能
	bool InitClassPassiveSkill(void);


/*------------------------------------------------------------------------------
*作者：C.D
*日期：2008-06-16
*描述：商城道具
-----------------------------------------------------------------------------*/
public:

	void SetChatBubbleType(BYTE _type){m_ChatBubbleType = _type;}
	BYTE GetChatBubbleType(void){return m_ChatBubbleType;}

	/*------------------------------------------------------------------------------	
	*描述：遍历身上装备和道具，如果期限到，则将他们删除
	-----------------------------------------------------------------------------*/
	void    SendEquipTimeEnd(int index,int type,int bagnum);
	void	ClearExpiredItem( void );
	bool	IsExpired(tm*	_pTime);
	void	SetItemActivated(Item* _pItem, bool	_IsActivated);

	/*------------------------------------------------------------------------------	
	*描述：神圣的橄榄枝之类道具功能，是否进入PK保护状态
	-----------------------------------------------------------------------------*/
	void	SetPKProtected(bool _IsProtected){m_bIsPKProtected = _IsProtected;}
	bool	IsPKProtected(void){return	m_bIsPKProtected;}

	/*------------------------------------------------------------------------------
	*描述：赫尔墨斯头巾之类道具功能，是否显示绿名
	-----------------------------------------------------------------------------*/
	void	SetGreenName(bool _IsGreenName){m_bIsGreenName = _IsGreenName;}
	bool	IsGreenName(void){return	m_bIsGreenName;}

	/*------------------------------------------------------------------------------
	*描述：月神的丝柏树叶之类道具功能，显示假名
	-----------------------------------------------------------------------------*/
	void	SetFalseName(bool _bIsFalseName){m_bIsFalseName = _bIsFalseName;}
	bool	IsFalseName(void){return	m_bIsFalseName;}

	/*------------------------------------------------------------------------------
	*描述：世界聊天频道使用权限
	-----------------------------------------------------------------------------*/
	int		GetNumOfSpeaker(void){return	m_NumOfSpeaker;}
	int		UseSpeaker(void){return	--m_NumOfSpeaker;}

	/*------------------------------------------------------------------------------
	*描述：获取包裹中道具的个数
	-----------------------------------------------------------------------------*/
	int		GetNumOfItem(const int	_ID);
	bool	UseItem(const int _ID, int _Num = 1);

private:
	/*------------------------------------------------------------------------------
	*描述：使用中的商城道具
	-----------------------------------------------------------------------------*/
	vector<Item>	MallItemInUseList;

	/*------------------------------------------------------------------------------
	*描述：由消费道具中产生的特有属性，例如：聊天气泡的样式
	-----------------------------------------------------------------------------*/
	BYTE m_ChatBubbleType;

	/*------------------------------------------------------------------------------
	*描述：是否PK保护
	-----------------------------------------------------------------------------*/
	bool m_bIsPKProtected;

	/*------------------------------------------------------------------------------
	*描述：是否显示绿名
	-----------------------------------------------------------------------------*/
	bool m_bIsGreenName;

	/*------------------------------------------------------------------------------
	*描述：显示假名
	-----------------------------------------------------------------------------*/
	bool m_bIsFalseName;

	/*------------------------------------------------------------------------------
	*描述：显示假名
	-----------------------------------------------------------------------------*/
	int	m_NumOfSpeaker;
	
//--------------------------------------商城道具-------------------------------------
//-----------------------------------------------------------------------------------

public:

	/*------------------------------------------------------------------------------
	*描述：//玩家退出处理
	-----------------------------------------------------------------------------*/
	bool IsMove(); //是则从Region中移除
	void ExitGame_TimeStart();
	void ExitGame_TimeEnd();
	bool GetTimeStart();
	void Updata_SurplusTime();

private:
	bool m_bExitGameStart;
	sbase::CTimerMS m_UpdateTime;
	time_t	m_Start_Time;
	time_t  PassTime;

public:
	BYTE	ucChannel;//聊天频道的屏蔽选择
	UINT	unTalkTime;


};

double RandOne0_1(double& seed);
void RandSeries( size_t a, size_t b, size_t& seed, valarray<size_t>& sp, size_t stCount );
double AverageRandom(double min,double max);
size_t Rand_ab_One(size_t a, size_t b, size_t& seed);


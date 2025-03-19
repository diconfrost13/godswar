//========================================================
//
//    Copyright (c) 2006,�������߹�����
//    All rights reserved.
//
//    �ļ����� �� Player.h
//    ժ    Ҫ �� ��̬������ģ��
//    
//    ��ǰ�汾 �� 1.00
//    ��    �� �� �ֵ»�
//    ������� �� 2007-01-17
//
//    ��    �� �� ����
//    ������� �� 2007-02-10
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

#define PLAYER_AI_TIMER			100				// ����
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
SKILL_HALENESS,            //��׳
SKILL_FEAT,                //����
SKILL_DEFEND,              //����
SKILL_ARMOURP_ROCTECT,     //���б���
SKILL_GLAVE_GAS,           //����
SKILL_ESCRIME,             //����
SKILL_EXACTITUDE_ATTACK,   //��׼����
SKILL_MUMP,                //����
SKILL_ENERGY,              //����
SKILL_ELEMENTS_STRENGTHEN, //Ԫ��ǿ��
SKILL_ELEMENTS,            //Ԫ��ԭ��
SKILL_ELEMENTS_DEFEND,     //Ԫ�صֿ�
SKILL_ELEMENTS_VOLITION,   //Ԫ����־
SKILL_FIR_STRENGTHEN,      //����ǿ��
SKILL_FLEXILE,             //���ͻ���
SKILL_LIFE_CHANNELS,       //����ͨ��

};
*/
enum eCharacterAttribute
{
	CHARACTER_ID,                                          //��ɫID
	CHARACTER_ACCOUNTS_ID,                                 //�ʺ�ID
	CHARACTER_NAME,                                        //��ɫ����
	CHARACTER_GENDER,                                      //��ɫ�Ա�
	CHARACTER_GMFLAG,                                      //GM��־ 
	CHARACTER_CAMP,                                        //��ɫ��Ӫ
	CHARACTER_PROFESSION,                                  //��ɫְҵ
	CHARACTER_LV,					                       //�ȼ�
	CHARACTER_SCHOLAR_LV,                                  //ѧ��ְҵ�ȼ�  ��ͣ��@@@
	CHARACTER_EXP,					                       //����
	CHARACTER_SCHOLAR_EXP,                                 //ѧ�߾���      ��ͣ��@@@
	CHARACTER_HP_CUR,                                      //HP��ǰ
	CHARACTER_MP_CUR,                                      //MP��ǰ
	CHARACTER_STAUS,                                       //״̬
	CHARACTER_BELIFE,                                      //����
	CHARACTER_PRESTIGE,                                    //����
	CHARACTER_EARL_RANK,                                   //��λ
	CHARACTER_CONSORTIA,                                   //����
	CHARACTER_CONSORTIA_JOB,                               //����ְҵ
	CHARACTER_CONSORTIA_CONTRIBUTE,						   //���ṱ��
	CHARACTER_STORE_NUM,								   //�ֿ����
	CHARACTER_BAG_NUM,									   //��������
	CHARACTER_HAIRSTYLE,                                   //����
	CHARACTER_FACESHAP,									   //����
	CHARACTER_CURMAP,                                      //��ǰ��ͼ
	CHARACTER_CURPOS_X,                                    //��ǰX����
	CHARACTER_CURPOS_Z,                                    //��ǰZ����
	CHARACTER_MONEY,                                       //��Ǯ
	CHARACTER_STONE,                                       //��ʯ
	CHARACTER_SKILLPOINT,                                  //��Ǯ
	CHARACTER_SKILLEXP,                                    //��ʯ
	CHARACTER_MAXHP,                                       //���HP
	CHARACTER_MAXMP,                                       //���MP
	CHARACTER_REGISTER_TIME,                               //��ɫע��ʱ��
	CHARACTER_LASTLOGIN_TIME,                              //����¼ʱ��
	CHARACTER_MUTE_TIME,                                   //������ʱ��	
	CHARACTER_EQUIP,                                       //װ��
};


enum EquipType
{
	EquipHead = 0,		//ͷ��
	EquipAmulet,		//�����
	EquipGlove,			//����
	EquipArmor,			//����
	EquipCuff,			//����
	EquipGirdle,		//����
	EquipShoes,			//Ь��
	EquipLeggins,		//����
	EquipRing1,			//��ָ1
	EquipRing2,			//��ָ2
 
	EquipMainHand1,		//����1
	EquipAuxiliaryHand1,//����1

	EquipCount
};


enum eTimeQuest
{
	TIME_NO_ACCEPT =0 ,
	TIME_ACCEPT ,
};

enum eAltarDealType
{
	eALTAR_LEVEL_UP,  //�����̳����������
	eALTAR_DELETE,	  //�����̳��ɾ������
	eALTAR_LOAD_EFFECT //�����̳����������ʱ�ļ�̳Ч������

};

enum eReviveType
{
	eREVIVE_STONE,	//��Ҹ���
	eREVIVE_MONEY,	//���Ҹ���
	eREVIVE_FREE,	//��Ѹ���
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



//�ܵ�ͨѶ��

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
	char     Name[32];                          //��ɫ��
	BYTE     ucGender;                          //�Ա�
	BYTE     ucCamp;                            //��Ӫ
	BYTE     uProfession;                       //ְҵ
	BYTE     ucHairStyle;                       //����
	BYTE	 ucFaceShap;						//����
	BYTE     ucBelief;                          //����
	bool     bIsSuccess;                        //�Ƿ���ӳɹ�
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
	//������Ҷ�ӦSOCKET
	void SetSocket( snet::CSocket *pSocket ) { m_pSocket = pSocket; CPlayer::AddSocketHashMap( pSocket ,this ); }
	//�õ���Ҷ�ӦSOCKET
	snet::CSocket* GetSocket( void ) { return m_pSocket; }
//	void SetSocket(snet::CSocket *pSocket ){m_pSocket = pSocket;}
	Trade* GetTrade(){return &m_Trade;}
	// ���Բ���
	CPlayer* GetTeamObject( unsigned int nNumber );
	bool IsLeader( void ) { if (this == m_pTeamLeader)return true; return false;}//return m_bIsLeader; }
	bool IsTeam( void ) { if( m_pTeamLeader != NULL ) return true; return false;}

	//��ɫ����
	void AddRole( ROLE_ATTRIBUTE Role );
	void SelectRole( string Name );
	void DelRole( string Name );

	eError UpdateRelation( RELATION &role, char &result)  ;
	bool DeleteRelation( const char *RelationName);

	volatile bool    WillRelease;
	volatile long    SynDBOutStand;
	void Init();

	// �����Ż������AI/Run
	virtual void AI( void );
	int CheckBlock(int Mid,float x,float z);
	virtual void Run( void );
	bool OnRead();
	bool OnSend();
	void DelayExit( time_t time );
	sbase::CTimerMS m_RunTimer;

	sbase::CTimerMS m_DelPlayerTimer;
	UINT  GetVendAttr(int Type);
	//����
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
	//����
	ULONG CPlayer::GetHit();
	//���
	ULONG CPlayer::GetDodge();
	//��ɫHP�ָ�
	UINT GetHPRecover();
	//��ɫMP�ָ�
	UINT GetMPRecover();

	void SendNoteToClient( const char * Note );  //����ʽ��Ϣ
	void SendSysNoteToClient(const char * Note); //���½ǵ�ϵͳ��Ϣ
	void SendMidNoteToClient(const char* Note);//��������Ļ�м����Ϣ
	//����ˢ��ʱ��
	void ResetTimer( float  IntervalTime ,TIME_STYLE timeStyle);
	//�Ƿ�ʱ
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

	//���һ����Ϣ
	void SetLastMsg(int);
	int GetLastMsg(){ return m_cMsg ;}

	//���һ����ʼ���ߵ�����
	void SetLastPos( float X, float Z ){ m_BeginX = X; m_BeginZ = Z; }
	void GetLastPos( float &X, float &Z ){  X = m_BeginX ; Z = m_BeginZ ; };

	//��ʼ��������ݣ������ݿ��ȡ��
	bool InitObjData(long  ID)  ;
	//���ݱ������ܸı��ɫ����ֵ
	void UpdateAttributeInfo( UINT  SkillID, AttributeType Type = TYPE_UPDATE );
	//�������ܿ�ʼ��ȴ��ʱ��
	bool SetActiveSkillStartTime( int ucSkillID);
	//���õ�ǰ���ܵ�ID
	void SetCurActiveSkillID( int ucActiveSkillID);
	//��õ�ǰ���ܵ�ID
	int GetCurActiveSkillID();
	//���ø���һ�õ����һ����Ϣ����
	void SetLastMsg(char MsgID);

	//��ӱ������ܵȼ����߸ı����м��ܵǼ�
	void AddPassiveSkill( int ucSkillID, int iRank = 1, int EXP = 0);
	//�ҵ���������
	bool DelPassiveSkill( int ucSkillID );
	//�ҵ���������
	bool FindPassiveSkill( int ucSkillID,UINT *Degree = NULL  );
	//�����������
	bool AddActiveSkill( int ucSkillID );
	//ɾ����������
	void DelActiveSkill( int ucSkillID );
	//�ҵ���������
	bool FindActiveSkill( int ucSkillID );
	//ħ���Ƿ�����ȴ״̬
	bool IsActiveSkillCooling( int ucSkillID );
	//�ı�ħ��״̬
	void ChangeActiveSkillStatus( int ucSkillID, TIME_STYLE status );
	//����˳�ʱ���д���ݿ�
	bool UpDateDB();
	//���������ʼ�ۼƵ���Ϣ
	bool IsGodSkillTimeOut( int MagicID );
	//��������ʱ������������������
	bool CalculatePassivePracticeDegree( PhysiacalAttack Type, ATTACK_TYPE eAttackType, bool IsDead = false );
	//ħ������ʱ������������������
	void CalculatePassivePracticeDegree(  int MagicID, ATTACK_TYPE eAttackType, bool IsDead = false );
	//���㱻����������ʱ����������
	void BePhysicalAttackedPassivePracticeDegree( PhysiacalAttack Style, ATTACK_TYPE AttackType );
	//���㱻ħ������ʱ��ļ���������
	void BeMagicAttackPassivePracticeDegree( UINT MagicID,  ATTACK_TYPE AttackType );
	//�ж�������ϵħ��
	Magic_Attack JudgeMagicStyle( UINT MagicID );
	//�ı似�������� 
	bool ChanegeDegree( int ucSkillID, int Buffer);
	UINT GetTotalSkillGrade( );
	bool IsEquipThis( const MagicData*  pMagic  );
	bool IsEquipThis( const SKillData*  pSkill  );
	void SynchronousClientSkill( bool IsMagic);
	//�жϼ�������
	bool PassiveSkillUpgrade(UINT  SkillID, int *Rank = NULL );
	//�ж���������ϵ��������ָ����
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

	//���������Ĵ���
	void PlayerUpGrade( bool IsUpGrade );
	//����������������Ҫ�ľ���
	void SetNextGradeEXP(  );
	UINT GetNextGradeExp(  );
	//�����������˺�
	INT CalculateAttackDamage(  CGameObject& pObj , float iPower = 0);
	//���㾭��͵ȼ�
	void CalculateExpAndLevel( CGameObject& pTarObj );
	//���������һ����ľ������������
	void CalculatePrestigeExpLevel();
	//�����Ǯ
	void CalculateMoney( CGameObject* pObj );
	//����ħ�������˺�
	INT CalculateAttackDamage( int MagicID, CGameObject &pObj );
	//���㹥����
	UINT CalculateAttack();
	//����ħ����װ�����������ܡ���
	UINT CalculateMagic();
	size_t GetHaveRoleNum(){ return m_HaveRole.size();};
	//�õ�����
	ULONG GetEXP() ;
	UINT GetRank();
	//���������������
	ULONG SetAtttibute( );
	//ͬ������(��������) 
	void  SynGameData( bool IsSelf );
	void  SynClientActiveSkillData();
	void  SynClientPassiveSkillData();
	void  RequestGameData( CPlayer * );
	//ͬ������(��������)
	void  SynTeamData( void* buf );

	void AddExp(int exp);
	void ChangePlayeBuniness( int NewBuniness );
	//���DB����
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


	//У���뻺��
	static void CacheValidCode( string Accounts, string Valid );
	static void ClearValidCode(  snet::CSocket* PSocket  );
	static void CacheSocket(  snet::CSocket* PSocket, string strAccounts );
	//��֤У����
	bool ValidateLogin( string validcode );
	UINT GetDBIDByRoleName( string RoleName);

	//�������ͬ��(Hash)
	static void AddSocketHashMap( snet::CSocket* PSocket,CPlayer *pPlayer );
	static void DelSocketHashMap( snet::CSocket* PSocket );
	static CPlayer *GetPlayerFromSocket( snet::CSocket* PSocket );

	static void AddAccountsHashMap( string accounts,CPlayer *pPlayer );
	static void DelAccountsHashMap( string accounts );
	static CPlayer *GetPlayerFromAccounts( string accounts );

	static void AddRoleNameHashMap( string rolename,CPlayer *pPlayer);
	static void DelRoleNameHasnMap(  string rolename );
	static CPlayer *GetPlayerFromRoleName( string rolename );

	//�õ���֤��
	static string GetValidCode( string Accounts );

	//���ݷ���
	void SendSkillMsg( bool IsActive );
	void SendKitBagMsg(int flag );
	void SendPropertyMsg( void );
	void SendStorageMsg( void );
	void SendRelationMsg( void );
	void SendConsortiaMsg( void );
	void SendAltarMsg(void);

	//GM����
	static bool GM_Handler_kick( ActionElem &elem );
	static bool GM_Handler_speak( ActionElem &elem );
	static bool GM_Handler_item( ActionElem &elem );

	//���ݴ���
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

	//���ݸ���
	static void UpdateDB_RoleAttribute( CPlayer *pPlayer );
	static void UpdateDB_KitBag(  CPlayer *pPlayer );
	static void UpdateDB_ActiveSkill(  CPlayer *pPlayer );
	static void UpdateDB_PassiveSkill(  CPlayer *pPlayer );
	static void UpdateDB_Relation(  CPlayer *pPlayer );
	static void UpdateDB_Quest( CPlayer *pPlayer );
	void UpdateDB_Offline( const char *Name, UINT Union, BYTE UnionDuty );
	void UpdateDB_Altar( const char *Name );

	//�������
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

	//��������
	void RequestGameDataFromDB( const void* pBuf );
	void RequestBaseRoleInfoFromDB( const void* pBuf  );
	void RequestAddRoleFromDB( const void* pBuf );
	void RequestDelRoleFromDB( const void* pBuf );
	void RequestAddConsortiaFromDB( const void* pBuf );

	//DB���ݴ���
	void ( *OnProcess_Attribute ) ( CPlayer *pPlayer,void *Loader );
	void ( *OnProcess_KitBag )( CPlayer *pPlayer );
	void ( *OnProcess_PassiveSkill )( CPlayer *pPlayer );
	void ( *OnProcess_ActiveSkill )( CPlayer *pPlayer );
	AttackRadius GetAttackRadius();

// 	//����ר��
// 	void TalkToMap( const char* pBuf, int nSize, BYTE ucType );//��ͨ
// 	void TalkToCamp( const char* pBuf, int nSize, BYTE ucType );//��Ӫ
// 	void TalkToTeam( const char* pBuf, int nSize, BYTE ucType );//��������
// 	void TalkToUnion( const char* pBuf, int nSize, BYTE ucType );//����
// 	void TalkToPlayer( CPlayer *pPlayer, const char* pBuf, int nSize,BYTE ucType );//˽��

	//��������
	bool  BackUp();
	bool  BackUP_RoleAttribute( void );
	bool  BackUp_KitBag( void );
	bool  BackUp_ActiveSkill( void );
	bool  BackUp_PassiveSkill( void );
	bool  BackUp_Relation( void );
	bool  BackUp_Quest( void );


	//���������Ϣ
	void  SendConsortiaInvite(void);
	void  SendConsortiaExit(void);
	void  SendConsortiaRespond(void);
	void  SendConsortiaBroadcast(void);

	//����Ʒ
	bool PickupDrops(Item* p);
	//ʹ�û�װ��
	bool UseQuestItem(int questid);
	Item* GetEquip(){ return m_Equips;}

// 	/*------------------------------------------------------------------------------
// 	 *���ߣ�C.D
// 	 *���ڣ�2008-06-01
// 	 *��������������װ����װ����������޵���������ɾ��
// 	 -----------------------------------------------------------------------------*/
// 	void    SendEquipTimeEnd(int index,int type,int bagnum);
// 	void	ClearExpiredItem( void );
// 	bool	IsExpired(tm*	_pTime);
// 	void	SetItemActivated(Item* _pItem, bool	_IsActivated); 

	bool UseOrEquip(int index , int num);
	bool SetEquip(int index , int num , int indexaim);
	bool MoveEquip(int index , int indexaim , int numaim);
	int  MoveItem(int index , int num , int indexaim , int numaim /*,int overlay = 0*/);
	//�����Ʒ
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

	//Ǯ
	int GetMoney() const;
	int GetBijou() const;
	void SetMoney(int money);
	void SetBijou(int bijou);
	void AddMoney(int money);
	void AddBijou(int bijou);
	void AddPrestige(int Prestige);
	void AddPoint(int Point);

	virtual HandType GetHandType();
	virtual eError Revive( int type );    //��������0����Ҹ��� 1�� ���Ҹ��� 2����Ѹ���
	virtual void Dead( CGameObject  *pObj );

	void Fly(int id , float x = 0 , float y = 0 , float z = 0);

	void ChangeAttackSpeed();
	void ChangeHp();

	//������������Ϣͬ�����Լ�
	virtual void AynObjToObj( CCell *pOldCell, CCell *pNewCell );
	//���Լ�����Ϣͬ�����������
	virtual void AynMeToOther( CCell *pOldCell, CCell *pNewCell );

	//�������
	//******************************************************************************************************************
	long GetConsortia_lfound()							//��ȡ�����ʽ�
	{
		if ( m_pConsortia )
		{
			return m_pConsortia->lfound;
		}
		return 0;
	};
	void SetConsortia_lfound( long lfound)				//���ù����ʽ�
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
	long GetConsortia_lbijou()							//��ȡ���ᱦʯ
	{
		if ( m_pConsortia )
		{
			return m_pConsortia->lbijou;
		}
		return 0;
	};
	void SetConsortia_lbijou(long lbijou)				//���ù��ᱦʯ
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
	void SetConsortiaInfo(ConsortiaElem *Consortia)     //���ù�����Ϣ    
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
	ConsortiaElem *GetConsortia(){ return m_pConsortia; };                              //����Լ��Ĺ���
	int GetConsortiaLevel(){ return m_pConsortia->iLevel;};								//����Լ�����ĵȼ�
	void AddConsortiaMember( ConsortiaRelationElem &rElems );                           //��ӳ�Ա          
	eError DismissConsortia();                                                          //��ɢ���� 
	bool HaveConsortia();                                                               //�Ƿ��й���
	bool IsThisDuty( CONSORTIA_JOB_TYPE Duty );                                         //�Ƿ��Ǹù���ְ��
	bool IsMemeberFull();                                                               //���������Ƿ���Ա
	eError DelMeFromConsortia( );                                                       //ɾ����Ա
	eError ChangeConsortiaPlacard( const char *);                                       //�޸Ĺ��ṫ��
	bool AppointDuty( std::string StrName, CONSORTIA_JOB_TYPE Duty );                   //����ְ��
	eError DelMemeber( std::string StrName );                                           //�Ƴ���Ա
	bool BroadcastConsortiaMsg( void* buf );                                            //�㲥������Ϣ
	bool BroadcastConsortiaBaseInfo();													//�㲥����Ļ�����Ϣ
	bool BroadcastConMemberInfo();														//�㲥�����Ա�б����ɾ�������뿪�������õ���
	int GetConsortiaMaxMember();														//��ȡ�������������
	int GetConsortiaCurrentMember();													//��ȡ����ĵ�ǰ����
	int GetConsortiaMaxAltar();															//���ع����ܽ��������̳��
	int GetConCurrentAltarNum();														//��ȡ���ᵱǰ�ļ�̳����
	vector<int>& GetHavePlayerAltars();													//��ȡ��ҵ�ǰ���еĹ����̳
	void InitAltar(UINT id,UINT level);													//��ʼ���������ݿ�Ĺ����̳
	/*--------------------------------------------------------
	���ܣ������Ա��������ȼ�
	��������
	���أ�bool����������ȼ��ɹ�����true�����򷵻�false
	���ߣ�����
	��ע��������ӦȨ�޵Ĺ���ĳ�Ա������ʾ����ȼ�
	���ڣ�2008-3-25
	----------------------------------------------------------*/
	eError ConsortiaLevelup();
	/*--------------------------------------------------------
	���ܣ������Ա������̳�ȼ�
	������ID��Ҫ�����ļ�̳ID
	���أ�bool�������ü�̳����ȼ��ɹ�����true�����򷵻�false
	���ߣ�����
	��ע����Ҫ���ĸ��˹��ṱ�ף������ĵȼ��ܹ���ȼ�������
	���ڣ�2008-3-25
	----------------------------------------------------------*/
	bool AltarLevelUp(int ID);
	/*--------------------------------------------------------
	���ܣ�������̳
	������ID����Ҫ������̳��ID
	���أ�bool�������ɹ�����true�����򷵻�false
	���ߣ�����
	��ע������Ȩ�޵Ĺ�����Ҵ�����̳
	���ڣ�2008-3-26
	----------------------------------------------------------*/
	bool CreateAltar(int ID);
	/*--------------------------------------------------------
	���ܣ��õ����м�̳
	������
	���أ�
	���ߣ�����
	��ע���õ����м�̳
	���ڣ�2008-3-26
	----------------------------------------------------------*/
	vector<int>& GetHaveAltars(){ return m_pConsortia->GetHaveAltars(); };
	/*--------------------------------------------------------
	���ܣ�ɾ����̳
	������ID����Ҫɾ����̳��ID
	���أ�bool��ɾ���ɹ�����true�����򷵻�false
	���ߣ�����
	��ע������Ȩ�޵Ĺ������ɾ����̳
	���ڣ�2008-3-26
	----------------------------------------------------------*/
	bool DelAltar(int ID);
	/*--------------------------------------------------------
	���ܣ��õ�ȷ����̳�Ĺ���ȼ�
	������ID����Ҫ��ȡ�ļ�̳��ID
	���أ�int :��ҶԸü�̳�Ĺ���ȼ�
	���ߣ�����
	��ע���õ���ҶԼ�̳�Ĺ���ȼ�
	���ڣ�2008-3-27
	----------------------------------------------------------*/
	UINT  GetOblationLV(int ID);
	
	/*--------------------------------------------------------
	���ܣ������Ա������̳����ȼ�,ɾ������ȼ�,���ع���ȼ�(�ű��������������ĺ�ص� UPOblation() ������ҵ�����)
	������ID��Ҫ�����ļ�̳ID
	���أ�bool�������ü�̳����ȼ��ɹ�����true�����򷵻�false
	���ߣ�����
	��ע�������Ա��������ȼ�
	���ڣ�2008-3-25
	----------------------------------------------------------*/
	bool OblationLevelUp(UINT ID ,eAltarDealType type);
	
	bool  UPOblationLV(UINT ID);  //��������ȼ���Ĵ���
	bool DelOblation( UINT ID );  //ɾ������ȼ���Ĵ���


	void ClearAllAltar();					//����뿪������߱������߳�ʱ��û�м�̳
	void LoadAllAltar( UINT ID );					//��������ʱ ���ؼ�̳����Ч
	void UpdateAltarMsg();					//��ͻ��˷��͸��¼�̳
	void ClearOneAltar(UINT ID);			//(����ɾ����̳ʱ����)  ɾ��������϶�Ӧ�ļ�̳����Ӱ������� ������������ң�
	void ClearOneAltar_fromDB(const char *name,UINT ID);		//(����ɾ����̳ʱ����)  ɾ��������϶�Ӧ�ļ�̳����Ӱ������� ������������ң�
	void DelConMember_AltarInfo( UINT ID );	//(����ɾ����̳ʱ����)  ɾ��������϶�Ӧ�ļ�̳����Ӱ�������
	//***************************************************************************************************************************************************

	SQuestStatus* GetAcceptQuest(int id);
	SQuestStatus* GetQuest(int id);

	void Explorer();//̽��������֤
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
	void ReflashUnavilableVec();//ˢ��δ����->���������
	void ReflashAvilaVec();//ˢ�¼���->δ���������
	void H_ConsortiaQuest(int q_type);//����������
	void AccpetConsortiaQuest(int index, int q_type);//���ܹ�������
	void ConsortiaReward( SQuestStatus* sqs);//���ά��
	void CastConsortiaQuest();//������������
	void CancelConsortiaQuest();//��������ȡ��

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

//��Ӳ��֣��£�//
public:
	GAMESTATUS m_WorldStatus;
//	CPlayer* m_pTeam[MAX_TEAM_NUMBER];			// �����Ϣ
	bool	 m_bIsLeader;						// �ӳ����
	CPlayer* m_pTeamLeader;						// �ӳ�ʵ��ָ��

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
//ְҵ���� by lion 20080327
	int m_ClassCount;								//ְҵ����
	vector<vector<int>> m_ClassPassiveSkill;					//ְҵ�������ܱ�

	bool QuestTeamLimit( int qid );//������Ƽ��
	bool QuestClassLimit( int qid );//ְҵ���Ƽ��
	bool QuestConsortiaLimit( int qid );//��������
	bool IsConsortiaQuest( int qid );

public:
	Trade	 m_Trade;
 
	void SetSkillMsg( MSG_SKILL* pSkillMsg );
	MSG_SKILL		m_SkillMsg;						// skillmsg����
 	static ATTACK_PARAM         AttackParam;
   // bool m_SceneChangeFlag;								//�����л����
    //del warning
	bool IsGoldBoxExist(int keyid);							//���䡢Կ���Ƿ����
    void SetGoldBoxId(UINT base_id){m_GoldBoxId = base_id;}					//���ñ���ID
    UINT GetGoldBoxId(){return m_GoldBoxId;}						//��ȡ����ID
    void SetInDialItemID(UINT index,UINT ID){m_InDialItemID[index] = ID;}		//������Χ��ƷID
    void SetSumRand(UINT Sum){m_SumRand = Sum;}						//������Χ��Ʒ�ܼ���
    UINT* GetInDialItemID(){return m_InDialItemID;}					//������Χ��ƷID
    UINT GetSumRand(){return m_SumRand;}						//������Χ��Ʒ�ܼ���
    bool ExpendGoldBoxId(int gold_box_id,int keyid);		//��			//��������
    bool ExpendGoldBoxKey(BYTE Iter);							//Կ������
    bool ExpendGoldBoxIter(BYTE IterBox,BYTE IterKey,int base_id,int keyid);		//��ʱ			//���ı����Կ��


    BYTE CanOpenbox(BYTE Iter,UINT base_id,int keyid);							//�Ƿ�ɿ�������
    bool IsDoubleItem();								//����������� ����ֵ�����Ƿ�˫��������Ʒ
    void SetCurrentIter(BYTE Iter){current_iter = Iter;}				//���õ�ǰ����λ��
    BYTE GetCurrentIter(){return current_iter;}						//��ȡ��ǰ����λ��
    void SetCurBoxItem(Item& item){memcpy(&cur_box_item,&item,sizeof(Item));}				//���õ�ǰ����λ��
    Item& GetCurBoxItem(){return cur_box_item;}				//���õ�ǰ����λ��




// 	/*------------------------------------------------------------------------------
// 	 *���ߣ�C.D
// 	 *���ڣ�2008-06-04
// 	 *�������̳ǵ���ʵ�ֵ������޸�
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
	//----------------��ʱ--------------------
	char m_RegisterTime[64];
	UINT m_OnlineTime;
	//----------------------------------------

	//���SOCKET
	snet::CSocket*	m_pSocket;
	UINT m_NextGradeExp;   //��һ���ȼ��������辭��

	ConsortiaElem *m_pConsortia;
	dbtool::IRecord *m_pRec;
	int m_cMsg;
	bool m_HaveJoin;    //�Ƿ��Ѿ����볡��
	string m_valid;
	string m_Accounts;    //�ʺ�
	string m_ValidCode;   //У����
	bool m_MsgFlag[MSG_SENDFLAG_COUNT];

	//bag
	Bag m_Bags[MAX_BAGS];
	Item m_Equips[EquipCount];
	bool m_bOtherHands;

	Storage m_Storage;
	Stall m_Stall;

	int m_Kills;				//ɱ������
	int m_OverQuests;			//�����������
	UINT GoldOpendNum;			//���俪������
	UINT m_GoldBoxId;			//���ڿ����ı���ID
	UINT m_InDialItemID[DIALITEMCOUNT];	//��Χ��ƷID
	UINT m_SumRand;				//��Χ��Ʒ�ܼ���
	BYTE current_iter;			//��ǰ��������
	Item cur_box_item;			//��ǰ������Ʒ

// 	/*------------------------------------------------------------------------------
// 	 *���ߣ�C.D
// 	 *���ڣ�2008-06-04
// 	 *�����������ѵ����в������������ԣ����磺�������ݵ���ʽ
// 	 -----------------------------------------------------------------------------*/
// 	BYTE m_ChatBubbleType;

	SQuestStatus m_Quests[QUEST_COUNT];

	map<int , SQuestStatus*> m_TimeQuestsMap;
	//map<int , SQuestStatus*> m_QuestsMap;

	vector<SQuestStatus*> m_AcceptQuests;
	vector<SQuestStatus*> m_AvailableQuests;
	vector<SQuestStatus*> m_UnavailableQuests;

	//��ϵ������
	CRelationManager    m_RelationMgr;

	map<string,ROLE_ATTRIBUTE> m_AddRole;     //�¼ӽ�ɫ
	map<string,UINT> m_HaveRole;			  //���н�ɫ
	vector<string> m_DeleteRole;              //ɾ����ɫ

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
	// ��ʼ��ְҵ�����Լ���Ӧ�ı�������
	bool InitClassPassiveSkill(void);


/*------------------------------------------------------------------------------
*���ߣ�C.D
*���ڣ�2008-06-16
*�������̳ǵ���
-----------------------------------------------------------------------------*/
public:

	void SetChatBubbleType(BYTE _type){m_ChatBubbleType = _type;}
	BYTE GetChatBubbleType(void){return m_ChatBubbleType;}

	/*------------------------------------------------------------------------------	
	*��������������װ���͵��ߣ�������޵���������ɾ��
	-----------------------------------------------------------------------------*/
	void    SendEquipTimeEnd(int index,int type,int bagnum);
	void	ClearExpiredItem( void );
	bool	IsExpired(tm*	_pTime);
	void	SetItemActivated(Item* _pItem, bool	_IsActivated);

	/*------------------------------------------------------------------------------	
	*��������ʥ�����֦֮����߹��ܣ��Ƿ����PK����״̬
	-----------------------------------------------------------------------------*/
	void	SetPKProtected(bool _IsProtected){m_bIsPKProtected = _IsProtected;}
	bool	IsPKProtected(void){return	m_bIsPKProtected;}

	/*------------------------------------------------------------------------------
	*�������ն�ī˹ͷ��֮����߹��ܣ��Ƿ���ʾ����
	-----------------------------------------------------------------------------*/
	void	SetGreenName(bool _IsGreenName){m_bIsGreenName = _IsGreenName;}
	bool	IsGreenName(void){return	m_bIsGreenName;}

	/*------------------------------------------------------------------------------
	*�����������˿����Ҷ֮����߹��ܣ���ʾ����
	-----------------------------------------------------------------------------*/
	void	SetFalseName(bool _bIsFalseName){m_bIsFalseName = _bIsFalseName;}
	bool	IsFalseName(void){return	m_bIsFalseName;}

	/*------------------------------------------------------------------------------
	*��������������Ƶ��ʹ��Ȩ��
	-----------------------------------------------------------------------------*/
	int		GetNumOfSpeaker(void){return	m_NumOfSpeaker;}
	int		UseSpeaker(void){return	--m_NumOfSpeaker;}

	/*------------------------------------------------------------------------------
	*��������ȡ�����е��ߵĸ���
	-----------------------------------------------------------------------------*/
	int		GetNumOfItem(const int	_ID);
	bool	UseItem(const int _ID, int _Num = 1);

private:
	/*------------------------------------------------------------------------------
	*������ʹ���е��̳ǵ���
	-----------------------------------------------------------------------------*/
	vector<Item>	MallItemInUseList;

	/*------------------------------------------------------------------------------
	*�����������ѵ����в������������ԣ����磺�������ݵ���ʽ
	-----------------------------------------------------------------------------*/
	BYTE m_ChatBubbleType;

	/*------------------------------------------------------------------------------
	*�������Ƿ�PK����
	-----------------------------------------------------------------------------*/
	bool m_bIsPKProtected;

	/*------------------------------------------------------------------------------
	*�������Ƿ���ʾ����
	-----------------------------------------------------------------------------*/
	bool m_bIsGreenName;

	/*------------------------------------------------------------------------------
	*��������ʾ����
	-----------------------------------------------------------------------------*/
	bool m_bIsFalseName;

	/*------------------------------------------------------------------------------
	*��������ʾ����
	-----------------------------------------------------------------------------*/
	int	m_NumOfSpeaker;
	
//--------------------------------------�̳ǵ���-------------------------------------
//-----------------------------------------------------------------------------------

public:

	/*------------------------------------------------------------------------------
	*������//����˳�����
	-----------------------------------------------------------------------------*/
	bool IsMove(); //�����Region���Ƴ�
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
	BYTE	ucChannel;//����Ƶ��������ѡ��
	UINT	unTalkTime;


};

double RandOne0_1(double& seed);
void RandSeries( size_t a, size_t b, size_t& seed, valarray<size_t>& sp, size_t stCount );
double AverageRandom(double min,double max);
size_t Rand_ab_One(size_t a, size_t b, size_t& seed);


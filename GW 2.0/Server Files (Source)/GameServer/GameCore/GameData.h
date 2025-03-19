#pragma  once

//�������У�����ϵ��
const float   PARAMATER1 	=  1.000f;
const float   PARAMATER2 	=  5.000f;
const float   PARAMATER3 	=  0.025f;
const float   PARAMATER4 	=  0.250f;


#define   RandCoef2053     2053	
#define   RandCoef13849    13849
#define   MODUL65536       65536

enum USERDATA
{
   USERDATA_CURHP,
   USERDATA_NMAE,
   USERDATA_CURMP,

};

enum SkillFalg
{
	SF_Swords = 0,
	SF_TwoHandsSwords,
	SF_Axes,
	SF_TwoHandsAxes,
	SF_Spears,
	SF_Javelins,
	SF_Bows,
	SF_Wands,
	SF_Staffs,
	SF_Shields,
	SF_Armors,
	SF_Cloths,
	SF_Heads,
	SF_Cuffs,
	SF_Leggins,
	SF_Glove,
	SF_Shoes,
	SF_Girdle,
	SF_Amulet,
	SF_Ring,

	SF_Count
};

// Object��������
enum eObjectState{
	OBJECT_IDLE = 0,													// ����״̬
	OBJECT_FIGHT,														// ս��״̬
	OBJECT_WALK,														// ����״̬
	OBJECT_RUN,															// ����״̬
	OBJECT_DEAD,														// ����״̬
	OBJECT_PICKUP,														// ʰȡ״̬
	OBJECT_GHOST,														// ���״̬
	OBJECT_ATTACK = 100,												// ����״̬
	OBJECT_CAST,														// ʩ��״̬
	OBJECT_PERFORM,														// ִ��״̬
	OBJECT_BUSYTIME,													// �޷�����
};

// Object��������
enum eObjectType{
	OBJECTTYPE_UNKNOW = 0,												// δ֪
	OBJECTTYPE_PLAYER,													// ���
	OBJECTTYPE_NPC,														// NPC
	OBJECTTYPE_MONSTER,													// ����
	OBJECTTYPE_BOSS,													// BOSS
	OBJECTTYPE_PET,														// ����
	OBJECTTYPE_BUILDING,												// ������
	OBJECTTYPE_VIP,														// VIP
	OBJECTTYPE_GM,														// GM
	OBJECTTYPE_GameProgramer,											// ...
};

// ְҵ���
enum eLevel
{
	OCCUPATION_WARRIOR = 0,												// ս��
	OCCUPATION_BUSINESSMAN,												// ����
	OCCUPATION_SCHOLAR,													// ѧ��
};

// ��Ӫ���
enum eFaction
{
	FACTION_ATHEN = 0,
	FACTION_SPARTA,
};

enum AttackRadius
{
	Melee = 0,
	Range,

	AttackRadiusCount
};

//�������ܼӳ�����
enum AttributeType
{
	TYPE_ADD,
	TYPE_UPDATE,
	TYPE_DELETE,
	TYPE_EQUIP_DEC,
	TYPE_EQUIP_INC
};

// ��󸽼�������
#define MAX_EQUIPAPPEND_COUNT 5
#define MAX_DROPS 8

//����������
#define MAX_BAGS 4
#define MAX_BAG_GRID 24
#define MAX_STORAGE_GRID 64
#define ACADEMIC_NPC_MEM_ID_ITEMTABS 16
#define ACADEMIC_NPC_MEM_ID_ITEMS 112
#define MAX_INC_STATUS      10
#define MAX_DEC_STATUS      10 
#define MAX_NAME 32
#define MAX_EQUIP_COUNT 12
#define MAX_FRIENDS_COUNT  30
#define MAX_SINGLESEND_KITBAG 12
#define MAX_TEAM_NUMBER 5
#define QUEST_OBJECTIVES_COUNT 4
#define QUEST_EXPLORER_COUNT 4
#define QUEST_SOURCE_ITEM_IDS_COUNT 4
#define QUEST_REWARD_CHOICES_COUNT 6
#define QUEST_REWARDS_COUNT 4
#define QUEST_DEPLINK_COUNT 10
#define QUEST_NPCTAKE_COUNT 20
#define QUEST_FIND_COUNT 20
#define QUEST_PLAYER_COUNT 20
#define QUEST_COUNT 1000
#define PLAYER_MAXLV  200
#define MONSTER_MAXLV 200


#define SKILLBACKUPCOUNT 16	

#define MAX_ITEM_OVERLAY 99

class CGameObject;
//����
struct  SKillData	
{
	BYTE            ucID;                                       //����ID
	char 		    Name[64] ;                        			//��������
	UINT            PrefixID;                                   //ǰ�ü���ID
	UINT            RrefixRank;                                 //ǰ�õȼ�Ҫ�� 
	UINT            TotalRank;                                  //�ܵȼ�Ҫ��
	std::vector<UINT>    EquipRequest;                          //װ��Ҫ��
	std::map<UINT,float> Effect;                                //Ч��
};

//ħ������ʽ
struct MagicData
{ 
	 UINT         	ucID;                                       //���
	 CHAR    	  	cName[64] ;                         		//����
	 BYTE           ucStyle;                                    //���ͣ����棬���棩
	 BYTE           ucEffect;                                   //״̬�˺�
	 USHORT         sMP;                                        //����MP
	 FLOAT          fPower1;                                     //��������1
	 FLOAT          fPower2;                                     //��������2
	 BYTE           ucDistance;                                 //���
	 BYTE           ucRange;                                    //��Χ
	 BYTE           ucRequest_Lv;                               //ְҵ�ȼ�Ҫ��
	 UINT           uiMoney;                                    //�ķѽ�Ǯ
	 FLOAT	 	  	ucIntonateTime;                       		//����ʱ��
	 FLOAT   	  	usCoolingTime;                        		//��ȴʱ��
	 char			ScriptFun[64];								//�ű�����
	 UINT			ucTarget;									//�ͷŶ���
	 UINT			ucAffectObj;								//Ӱ��Ŀ��
	 int			iEffectTurn;								//Ч������
	 float			fTimeInterval;								//ʱ����
	 int			iProperty;									//ħ������
	 bool           bIsEquipUse;                                //���߼���
	 int            iEnmity;                                    //���ӵĳ��
	 int            StatusOdds;                                 //״̬���Ӽ���
	 int            Kind;                                       //����
	 BYTE           Priority;                                   //���ȼ���
	 std::vector<int> m_Status;                                //����״̬
	 std::vector<UINT> EquipRequest;                            //װ��Ҫ��
};

struct ItemData
{
	int	Base;
	char BaseLV;
	int  Append[MAX_EQUIPAPPEND_COUNT];
	char AppendLV;
	char Binding;
	char Overlap;
	long CdKey;		//��Ʒ����Ψһ��ʶ

	ItemData()
		:
	Base(-1) ,BaseLV(0), 
		AppendLV(0) ,
		Binding(0) ,
		Overlap(0),
		CdKey(0)
	{
		for (int i = 0 ; i < MAX_EQUIPAPPEND_COUNT ; i++)
			Append[i] = -1;
	}
};

struct Data
{
	LONG                    m_lMaxHP;                       //HP����
	LONG                    m_lMaxMP;                       //MP����
	LONG                    m_lResumeHP;                    //HP�ָ�
	LONG                    m_lResumeMP;                    //MP�ָ�
	LONG					m_lAttack;				        //��������
	LONG					m_lDefend;				    	//���������
	LONG                    m_lMagicAttack;                 //ħ������
	LONG                    m_lMagicDefend;                 //ħ������
	LONG					m_lHit;						    //����
	LONG					m_lDodge;						//���
	LONG                    m_lCritAppend;                  //�����ӳ�
	LONG                    m_lCritDefend;                  //�����ֿ�
	FLOAT                   m_fPhyDamageAppend;             //�����˺��ӳ�
	FLOAT                   m_fMagicDamageAppend;           //ħ���˺��ӳ�
	LONG                    m_lDamageSorb;                  //�˺�����
	FLOAT                   m_fBeCure;                      //�ܵ��ļ�������Ч��
	FLOAT                   m_fCure;                        //ʹ�õļ�������Ч�� 
	LONG                    m_lStatusHit;                   //״̬�ɹ��ʼӳ�
	LONG                    m_lStatudDodge;                 //״̬�ɹ��ʵֿ�
};

//NPC������Ϣ�����
struct NpcItemData 
{
	int	Base;
	char AppendLV;
	char BaseLV;
	char Binding;
	char Overlap;
	char Sell;

	char BuyType[3];
	UINT BuyConsume[3];
	char BuyTypeNum;


	NpcItemData()
		:
		Base(-1) , 
		AppendLV(0) ,
		BaseLV(0),
		Binding(0) ,
		Overlap(0),
		Sell(0),
		BuyTypeNum(0)
	{
		for (int j=0; j < 3; j++)
		{
			BuyType[j] = -1;
			BuyConsume[j] = 0;
		}
	}
};
//�̳���Ϣ�����
struct MallItemData 
{
	int	Base;
	int	Append[MAX_EQUIPAPPEND_COUNT];
	char AppendLV;
	char BaseLV;
	char Binding;
	char Overlap;
	char Sell;

	char BuyType[3];
	UINT BuyConsume[3];
	char BuyTypeNum;
	int Discount;
	char New;
	char Hot;

	MallItemData()
		:
	Discount(100),
		Base(-1) , 
		AppendLV(0) ,
		Binding(0) ,
		Overlap(0),
		Sell(0),
		BuyTypeNum(0)
	{
		for (int i = 0 ; i < MAX_EQUIPAPPEND_COUNT ; i++)
			Append[i] = -1;
		for (int j=0; j < 3; j++)
		{
			BuyType[j] = -1;
			BuyConsume[j] = 0;
		}
	}
};

//�����̳ǵȼ��ۿ۱�
struct DiscountData 
{
	char level;
	int  StoneDiscount;
	int  GloryDiscount;
};
//��̳��Ϣ
struct Consortia_AltarInfo 
{
	UINT AltarID;
	UINT Grade;
};

//װ��
struct EquipData  : public Data
{
    int         m_AttackDistance;     //��������
	int         m_AttackSpeed;        //�����ٶ�
};

//ר��
struct SkillData :  public  Data
{

};

//����
struct BaseData : public Data
{

};

struct AltarData : public Data
{

};

//״̬
struct StatusData : public Data
{
	float   m_HaltIntonate;            //�жϱ�������(����Ч��)
	float   m_ReboundDamage;           //�����˺�(����Ч��)
	float   m_NonMoving;               //�����ƶ�
	float   m_NonMagicUsing;           //����ʹ��ħ��(bool)
	float   m_NonZSUsing;              //����ʹ����ʽ(bool)
	float   m_NonAttackUsing;          //����ʹ����ͨ����(bool)
	float   m_NonPropUsing;            //����ʹ�õ���(bool)
	float   m_ReturnDamage;            //�����˺�(float)
	float   m_ChangeIntonateTime;      //�ı�����ʱ��(float)
	float   m_BeMagicDamage;           //�ܵ�ħ���˺�(float)
	float   m_CreateMagicDamage;       //���ħ���˺�(float)
	float   m_BeAttackDamage;          //�ܵ������˺�(float)
	float   m_CreateAttackDamage;      //��������˺�(float)
	float   m_GetEXP;                  //�õ�����ֵ(float)
	float   m_AddHP;                   //����HP(int)
	float   m_DecHP;                   //����HP(int)
	float   m_AddMP;                   //����MP(int)
	float   m_DecMP;                   //����MP(int)
    StatusData()
	{
		memset( this,0L,sizeof(StatusData) );
	}
};

// ��ɫ��������
struct ObjectData
{
	char					m_strName[MAX_NAME];				//����
	BYTE                    m_Gender;                           //�Ա�0��Ů 1���� 
	USHORT					m_lRegionID;						//��ǰ�ĳ������
	FLOAT					m_fX, m_fY, m_fZ;					//��ǰ����
	FLOAT					m_fSpeed;							//�ƶ��ٶ�
	USHORT					m_lStyle;							//��������
	BYTE					m_lFaction;							//������Ӫ 0��˹�ʹ� 1���ŵ� 
	USHORT					m_lPrestige;						//����
	BYTE                    m_cKnight;                          //��λ
	USHORT                  m_cUnion;                           //����
	BYTE                    m_cUnionBusiness;                   //����ְ��
	UINT                    m_uiUionContribute;                 //���ṱ��
	UINT					m_uiStoreNum;						//�ֿ����
	UINT					m_uiBagNum;							//��������
	BYTE			        m_lClass;			                //ְҵ
	UINT                    m_cExp;				                //��ɫ���� add by lion
	BYTE                    m_cRank;			                //��ɫ�ȼ� add by lion
	long					m_lHP;								//HP
	long					m_lMP;								//MP
	USHORT                  m_usAttackDistance;                 //���﹥����Χ
	USHORT                  m_usAttackSpeed;                    //�����ٶ�
	BYTE                    m_cHairStyle;                       //����
	BYTE                    m_cPupilColor;                      //ͫɫ
	USHORT                  m_usBelief;                         //����
	UINT					m_lMoney;							//��Ǯ
	UINT                    m_lStone;                           //��ʯ
//	char			m_acName[64];                   //��������
};


enum {
    PROPERTY_PHY,
	PROPERTY_MAG,
	PROPERTY_CURE,
	PROPERTY_FLY
};

enum CONSORTIA_JOB_TYPE
{
	CONSORTIA_CHAIRMAN           =  0x06,                           //�᳤
	CONSORTIA_ASSISTANT_CHAIRMAN =  CONSORTIA_CHAIRMAN-1,           //���᳤
	CONSORTIA_DIRECTOR 			 =  CONSORTIA_CHAIRMAN-2,           //����
	CONSORTIA_CADREMAN 			 =  CONSORTIA_CHAIRMAN-3,           //��Ӣ
	CONSORTIA_MEMBER   			 =  CONSORTIA_CHAIRMAN-4,           //��Ա
	CONSORTIA_PROBATION_MEMBER   =  CONSORTIA_CHAIRMAN-5,           //��ϰ��Ա
	CONSORTIA_NONE			     =  CONSORTIA_CHAIRMAN-6,           //��
};


#define  SIZE_OF_REGION 256.0f
#define  SIZE_OF_GRID  32.0f
#define  NUMBER_OF_REGION_GRID 16

//�����������
struct Consortia_Member
{
	long lPlayerID;                    //���ID
	CONSORTIA_JOB_TYPE acDuty;         //ְ��
	char acMemberName[32];             //��Ա����
	BYTE ucBusiness;                    //ְҵ
	UINT uiContribute;                  //����
	BYTE iLevel;			            //�ȼ�add by lion
	long lMapID;                       //���ڵ�ͼID,-1Ϊ����,0�ŵ�....
	Consortia_Member()
	{
		lPlayerID = -1;
		acDuty = CONSORTIA_NONE;
		::ZeroMemory(acMemberName,sizeof(acMemberName));
		ucBusiness = 0;
		uiContribute = 0;
		iLevel = 0; //add by lion
		lMapID = -1;
	}
};

struct Consortia_Info
{
	char acName[64];                   //��������
	char acChairman[32];               //�᳤����
	BYTE iLevel;                       //����ȼ�
	long lCredit;                      //��������
	long lfound;                       //�ʽ�
	long lbijou;                       //��ʯ
	char acTextInfo[256];              //���ṫ��
	int			MaxMember;					 //������������
	UINT		AltarCounts;				 //���ᴴ����̳�ĸ���
	Consortia_AltarInfo		Altar[9];					 //�����ļ�̳ID��
	Consortia_Info()
	{
		::ZeroMemory(acName,sizeof(acName));
		::ZeroMemory(acChairman,sizeof(acChairman));
		iLevel = 0;
		lCredit = 0;
		lfound = 0;                      
		lbijou = 0;                     
		::ZeroMemory(acTextInfo,sizeof(acTextInfo));
		MaxMember = 0;
		AltarCounts = 0;
		::ZeroMemory(Altar,sizeof(Altar));
	}
};
//////////////////////////////////////////////////
//��Ϸ����define��
//////////////////////////////////////////////////

#define CREATE_CONSORTIA_NEED_LEVEL 30
#define CREATE_CONSORTIA_NEED_MONEY 0
#define CREATE_CONSORTIA_NEED_ITEM  4100
#define DUTYCHAIRNAME "�᳤"
#define DUTYMEMBERNAME "��Ա"

//World.h 
#define LOGIC_TIMEOUT   			40									  
#define REGION_BACKUP_TIMEOUT 		1000*30	
#define CONSOR_BACKUP_TIMEOUT 		300000
#define GM_TIMEOUT                  3600000 
#define HINT_TIMEOUT                1000
#define QUEUE_TIMEOUT			    10000

#define LOGIC2NET_TIMEOUT   		2000
#define LOGIC_LIMIT_TIMEOUT 		1000	// �߼�����
#define LOGIC_CYCLE_DELAY_TIMEOUT 	120		// ʱ�����壬50��/��


#define LOGIC_CYCLE_DELAY			20
#define LOGIN_QUEUE_REFRESH			20000
#define SURVEY_ONLIEN_TIME			20*60*1000

//SkillManager.h
#define  MAX_STATUS_EFFECT			32
#define  MAX_SKILL_EFFECT			19

//RoleRelation.h 
#define  MAX_RELATION_NUM			30
#define  MAX_CONSORTIA_MEMBER_SIZE	500
#define  MAX_ALTAR_NUM				8
#define  CONSORTIA_REFRESH_DAY		86400



////////END////////
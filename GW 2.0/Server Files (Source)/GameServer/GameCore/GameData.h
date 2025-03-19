#pragma  once

//计算命中，暴击系数
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

// Object动作特征
enum eObjectState{
	OBJECT_IDLE = 0,													// 空闲状态
	OBJECT_FIGHT,														// 战斗状态
	OBJECT_WALK,														// 行走状态
	OBJECT_RUN,															// 奔跑状态
	OBJECT_DEAD,														// 死亡状态
	OBJECT_PICKUP,														// 拾取状态
	OBJECT_GHOST,														// 灵魂状态
	OBJECT_ATTACK = 100,												// 攻击状态
	OBJECT_CAST,														// 施法状态
	OBJECT_PERFORM,														// 执行状态
	OBJECT_BUSYTIME,													// 无法动作
};

// Object类型特性
enum eObjectType{
	OBJECTTYPE_UNKNOW = 0,												// 未知
	OBJECTTYPE_PLAYER,													// 玩家
	OBJECTTYPE_NPC,														// NPC
	OBJECTTYPE_MONSTER,													// 怪物
	OBJECTTYPE_BOSS,													// BOSS
	OBJECTTYPE_PET,														// 宠物
	OBJECTTYPE_BUILDING,												// 建筑物
	OBJECTTYPE_VIP,														// VIP
	OBJECTTYPE_GM,														// GM
	OBJECTTYPE_GameProgramer,											// ...
};

// 职业标记
enum eLevel
{
	OCCUPATION_WARRIOR = 0,												// 战斗
	OCCUPATION_BUSINESSMAN,												// 商人
	OCCUPATION_SCHOLAR,													// 学者
};

// 阵营标记
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

//被动技能加成类型
enum AttributeType
{
	TYPE_ADD,
	TYPE_UPDATE,
	TYPE_DELETE,
	TYPE_EQUIP_DEC,
	TYPE_EQUIP_INC
};

// 最大附加属性数
#define MAX_EQUIPAPPEND_COUNT 5
#define MAX_DROPS 8

//背包最大格子
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
//技能
struct  SKillData	
{
	BYTE            ucID;                                       //技能ID
	char 		    Name[64] ;                        			//技能名称
	UINT            PrefixID;                                   //前置技能ID
	UINT            RrefixRank;                                 //前置等级要求 
	UINT            TotalRank;                                  //总等级要求
	std::vector<UINT>    EquipRequest;                          //装备要求
	std::map<UINT,float> Effect;                                //效果
};

//魔法，招式
struct MagicData
{ 
	 UINT         	ucID;                                       //编号
	 CHAR    	  	cName[64] ;                         		//名称
	 BYTE           ucStyle;                                    //类型（增益，减益）
	 BYTE           ucEffect;                                   //状态伤害
	 USHORT         sMP;                                        //消耗MP
	 FLOAT          fPower1;                                     //基本威力1
	 FLOAT          fPower2;                                     //基本威力2
	 BYTE           ucDistance;                                 //射程
	 BYTE           ucRange;                                    //范围
	 BYTE           ucRequest_Lv;                               //职业等级要求
	 UINT           uiMoney;                                    //耗费金钱
	 FLOAT	 	  	ucIntonateTime;                       		//吟唱时间
	 FLOAT   	  	usCoolingTime;                        		//冷却时间
	 char			ScriptFun[64];								//脚本函数
	 UINT			ucTarget;									//释放对象
	 UINT			ucAffectObj;								//影响目标
	 int			iEffectTurn;								//效果次数
	 float			fTimeInterval;								//时间间隔
	 int			iProperty;									//魔法属性
	 bool           bIsEquipUse;                                //道具技能
	 int            iEnmity;                                    //增加的仇恨
	 int            StatusOdds;                                 //状态附加几率
	 int            Kind;                                       //种类
	 BYTE           Priority;                                   //优先级别
	 std::vector<int> m_Status;                                //附带状态
	 std::vector<UINT> EquipRequest;                            //装备要求
};

struct ItemData
{
	int	Base;
	char BaseLV;
	int  Append[MAX_EQUIPAPPEND_COUNT];
	char AppendLV;
	char Binding;
	char Overlap;
	long CdKey;		//物品生成唯一标识

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
	LONG                    m_lMaxHP;                       //HP上限
	LONG                    m_lMaxMP;                       //MP上限
	LONG                    m_lResumeHP;                    //HP恢复
	LONG                    m_lResumeMP;                    //MP恢复
	LONG					m_lAttack;				        //物理攻击力
	LONG					m_lDefend;				    	//物理防御力
	LONG                    m_lMagicAttack;                 //魔法攻击
	LONG                    m_lMagicDefend;                 //魔法防御
	LONG					m_lHit;						    //命中
	LONG					m_lDodge;						//躲避
	LONG                    m_lCritAppend;                  //暴击加成
	LONG                    m_lCritDefend;                  //暴击抵抗
	FLOAT                   m_fPhyDamageAppend;             //物理伤害加成
	FLOAT                   m_fMagicDamageAppend;           //魔法伤害加成
	LONG                    m_lDamageSorb;                  //伤害吸收
	FLOAT                   m_fBeCure;                      //受到的技能治疗效果
	FLOAT                   m_fCure;                        //使用的技能治疗效果 
	LONG                    m_lStatusHit;                   //状态成功率加成
	LONG                    m_lStatudDodge;                 //状态成功率抵抗
};

//NPC贩卖消息结果体
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
//商城消息结果体
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

//公会商城等级折扣表
struct DiscountData 
{
	char level;
	int  StoneDiscount;
	int  GloryDiscount;
};
//祭坛信息
struct Consortia_AltarInfo 
{
	UINT AltarID;
	UINT Grade;
};

//装备
struct EquipData  : public Data
{
    int         m_AttackDistance;     //攻击距离
	int         m_AttackSpeed;        //攻击速度
};

//专长
struct SkillData :  public  Data
{

};

//基本
struct BaseData : public Data
{

};

struct AltarData : public Data
{

};

//状态
struct StatusData : public Data
{
	float   m_HaltIntonate;            //中断别人吟唱(特殊效果)
	float   m_ReboundDamage;           //返还伤害(特殊效果)
	float   m_NonMoving;               //不能移动
	float   m_NonMagicUsing;           //不能使用魔法(bool)
	float   m_NonZSUsing;              //不能使用招式(bool)
	float   m_NonAttackUsing;          //不能使用普通攻击(bool)
	float   m_NonPropUsing;            //不能使用道具(bool)
	float   m_ReturnDamage;            //返还伤害(float)
	float   m_ChangeIntonateTime;      //改变吟唱时间(float)
	float   m_BeMagicDamage;           //受到魔法伤害(float)
	float   m_CreateMagicDamage;       //造成魔法伤害(float)
	float   m_BeAttackDamage;          //受到物理伤害(float)
	float   m_CreateAttackDamage;      //造成物理伤害(float)
	float   m_GetEXP;                  //得到经验值(float)
	float   m_AddHP;                   //增加HP(int)
	float   m_DecHP;                   //减少HP(int)
	float   m_AddMP;                   //增加MP(int)
	float   m_DecMP;                   //减少MP(int)
    StatusData()
	{
		memset( this,0L,sizeof(StatusData) );
	}
};

// 角色属性数据
struct ObjectData
{
	char					m_strName[MAX_NAME];				//名称
	BYTE                    m_Gender;                           //性别0：女 1：男 
	USHORT					m_lRegionID;						//当前的场景标记
	FLOAT					m_fX, m_fY, m_fZ;					//当前坐标
	FLOAT					m_fSpeed;							//移动速度
	USHORT					m_lStyle;							//外形特征
	BYTE					m_lFaction;							//所属阵营 0：斯巴达 1：雅典 
	USHORT					m_lPrestige;						//声望
	BYTE                    m_cKnight;                          //爵位
	USHORT                  m_cUnion;                           //公会
	BYTE                    m_cUnionBusiness;                   //公会职务
	UINT                    m_uiUionContribute;                 //公会贡献
	UINT					m_uiStoreNum;						//仓库个数
	UINT					m_uiBagNum;							//包裹个数
	BYTE			        m_lClass;			                //职业
	UINT                    m_cExp;				                //角色经验 add by lion
	BYTE                    m_cRank;			                //角色等级 add by lion
	long					m_lHP;								//HP
	long					m_lMP;								//MP
	USHORT                  m_usAttackDistance;                 //人物攻击范围
	USHORT                  m_usAttackSpeed;                    //攻击速度
	BYTE                    m_cHairStyle;                       //发型
	BYTE                    m_cPupilColor;                      //瞳色
	USHORT                  m_usBelief;                         //信仰
	UINT					m_lMoney;							//金钱
	UINT                    m_lStone;                           //宝石
//	char			m_acName[64];                   //公会名称
};


enum {
    PROPERTY_PHY,
	PROPERTY_MAG,
	PROPERTY_CURE,
	PROPERTY_FLY
};

enum CONSORTIA_JOB_TYPE
{
	CONSORTIA_CHAIRMAN           =  0x06,                           //会长
	CONSORTIA_ASSISTANT_CHAIRMAN =  CONSORTIA_CHAIRMAN-1,           //副会长
	CONSORTIA_DIRECTOR 			 =  CONSORTIA_CHAIRMAN-2,           //理事
	CONSORTIA_CADREMAN 			 =  CONSORTIA_CHAIRMAN-3,           //精英
	CONSORTIA_MEMBER   			 =  CONSORTIA_CHAIRMAN-4,           //会员
	CONSORTIA_PROBATION_MEMBER   =  CONSORTIA_CHAIRMAN-5,           //见习会员
	CONSORTIA_NONE			     =  CONSORTIA_CHAIRMAN-6,           //无
};


#define  SIZE_OF_REGION 256.0f
#define  SIZE_OF_GRID  32.0f
#define  NUMBER_OF_REGION_GRID 16

//公会相关数据
struct Consortia_Member
{
	long lPlayerID;                    //玩家ID
	CONSORTIA_JOB_TYPE acDuty;         //职务
	char acMemberName[32];             //成员名字
	BYTE ucBusiness;                    //职业
	UINT uiContribute;                  //贡献
	BYTE iLevel;			            //等级add by lion
	long lMapID;                       //所在地图ID,-1为离线,0雅典....
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
	char acName[64];                   //公会名称
	char acChairman[32];               //会长名称
	BYTE iLevel;                       //公会等级
	long lCredit;                      //公会声望
	long lfound;                       //资金
	long lbijou;                       //宝石
	char acTextInfo[256];              //公会公告
	int			MaxMember;					 //公会人数上限
	UINT		AltarCounts;				 //公会创建祭坛的个数
	Consortia_AltarInfo		Altar[9];					 //创建的祭坛ID号
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
//游戏世界define区
//////////////////////////////////////////////////

#define CREATE_CONSORTIA_NEED_LEVEL 30
#define CREATE_CONSORTIA_NEED_MONEY 0
#define CREATE_CONSORTIA_NEED_ITEM  4100
#define DUTYCHAIRNAME "会长"
#define DUTYMEMBERNAME "会员"

//World.h 
#define LOGIC_TIMEOUT   			40									  
#define REGION_BACKUP_TIMEOUT 		1000*30	
#define CONSOR_BACKUP_TIMEOUT 		300000
#define GM_TIMEOUT                  3600000 
#define HINT_TIMEOUT                1000
#define QUEUE_TIMEOUT			    10000

#define LOGIC2NET_TIMEOUT   		2000
#define LOGIC_LIMIT_TIMEOUT 		1000	// 逻辑限速
#define LOGIC_CYCLE_DELAY_TIMEOUT 	120		// 时间脉冲，50次/秒


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
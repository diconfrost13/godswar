//=====================================================================================================================
//
//		Copyright (c) 2008,欢乐连线工作室
//		All rights reserved
//
//		文件名称：
//		摘    要：道具物品属性数据
//				  
//
//		当前版本：Ver1.00
//		作    者：赖滔
//		完成日期：2008-03-15
//
//=====================================================================================================================

#ifndef _ITEM_H_
#define _ITEM_H_

#include "GameData.h"
#include <vector>
#include <string>
class CPlayer;
 
enum ItemColor
{
	IC_WHITE = 0,
	IC_GREEN,
	IC_BLUE,
	IC_PURPLE,

	IC_COUNT
};

enum MaterialType
{
	MT_BASE= 0,
	MT_APPEND,

	MT_COUNT
};

// enum ItemAppendPhyle
// {
// 	Attack = 0,
// 	State,
// 	Defence,
// 	Colligation,
// 	MagicAttack,
// 	MagicDefence,
// 	MagicColligation,
// 	Energy,
// 	Cure,
// 
// 	ItemAppendPhyleCount
// };



struct BaseAttribute
{
	__int64 GreenCard;		//绿卡

	bool Binding;			//是否是绑定
	bool Equip;				//是否可装备
	bool Use;				//是否可用
	bool Treasure;			//宝箱
	bool Auto;				//自动使用

	int Money;				//金币
	int Bijou;				//宝石

	int Overlap;			//最大重叠
	int	Color;				//颜色

	int Character;			//道具品质

	BaseAttribute()
		:	GreenCard(0) ,
		Binding(false) , 
		Money(0) , Bijou(0) ,
		Equip(false) , Use(false) , Treasure(false) , Auto(false) ,
		Overlap(1) , 
		Color(IC_WHITE) ,
		Character(0)
	{

	}
};

static std::string HANDS_STRING[] = 
{
	"OneHand",			//单手
	"TwoHand",			//双手
	"MainHand",			//主手
	"AuxiliaryHand",	//副手
	""
};

static std::string ITEM_TYPE_STRING[] = 
{
	"weapon",				//武器
	"shield",				//盾牌

	"head",					//头盔
	"amulet",				//护身符
	"glove",				//手套
	"armor",				//盔甲
	"cloth",				//布甲
	"cuff",					//护腕
	"girdle",				//腰带
	"shoes",				//鞋子
	"leggins",				//护胫
	"ring",					//戒指

	"consume item",			//消费道具

	""
};

// static std::string WEAPON_TYPE_STRING[] =
// {
// 	"Swords",
// 	"TwoHandsSwords",
// 	"Axes",
// 	"TwoHandsAxes",
// 	"Spears",
// 	"Javelins",
// 	"Bows",
// 	"Wands",
// 	"Staffs"
// 
// 	""
// };

// static std::string ITEM_APPENDPHYLE_STRING[] =
// {
// 	"Attack",
// 	"State",
// 	"Defence",
// 	"Colligation",
// 	"MagicAttack",
// 	"MagicDefence",
// 	"MagicColligation",
// 	"Energy",
// 	"Cure",
// 
// 	""
// };

static std::string ITEM_APPENDTYPE_STRING[] =
{
	"AttackA" ,
	"DefenceA" ,
	"AddMagicAk",
	"AddMagicRec" ,
	"Hit",
	"Miss",
	"FuryAkAdd",
	"FuryAkRec",
	"PhysicalDamage",
	"MagicDamage" ,
	"InjureImbibe",
	"State",
	"StateImmunity" ,
	"MaxHP" ,
	"MaxMP" ,
	"HPRestore" ,
	"MPRestore",
	"AcceptCure",
	"Cure",

	""
};

struct ItemBaseAttribute : public BaseAttribute
{
	enum ItemType
	{
		Weapon = 0,
		Shield,

		Head,
		Amulet,
		Glove,
		Armor,
		Cloth,
		Cuff,
		Girdle,
		Shoes,
		Leggins,
		Ring,

		ConsumeItem,

		ItemTypeCount
	};

	enum EquipHand
	{
		OneHand = 0,		//单手
		TwoHand,			//双手

		MainHand,			//主手
		AuxiliaryHand,		//副手

		EquipHandCount
	};

	int ID;							//id
	int Faction;					//阵营
	bool SkillBook;					//技能书

	vector<int> Class;				//职业限制
	int	eSkillFlag;					//技能书标记
	int	PrevSkillID;				//需要技能ID
	int SkillLearnID;				//学习技能ID
	int SkillID;					//技能ID
	int QuestID;

	int Random;						//稀有度

	int DistributionMin;			//相性最小值
	int DistributionMax;			//相性最大值

	vector<int>		Attack;			//近战攻击力
	vector<float>	fAttackRadius;	//攻击范围		
	vector<float>   AttackSpeed;	//攻击速度

	vector<int>     Defence;		//物理防御

	vector<int>		Hit;			//命中
	vector<int>		Miss;			//闪避

	vector<int>		MAXHP;			//值	
	vector<int>		MAXMP;			//值

	vector<float> AcceptCure;		//受到的技能治疗效果	
	vector<float> Cure;				//使用的技能治疗效果	

	vector<float> PhysicalDamage;	//物理伤害	
	vector<float> MagicDamage;		//魔法伤害

	float PhysicalDamageAbsorb;		//吸收伤害
	float MagicDamageAbsorb;		//吸收魔法伤害	

	int	MaterialType;				//宝石类型
	int MaterialCharacter;			//宝石品质
	int MaterialProyAdd;            //宝石合成成功率

	std::vector<int> MainAttribute;	//附加属性	

	ItemType EType;					//类别e

	std::vector<int>	QuestsID;	//任务ID

	EquipHand eEquipHand;			//装备手

	AttackRadius eAttackRadius;		//近战远程

	//赖滔 新增 -----------------------------------
	//vector<int> Distribution;
	vector<int>	MagicAk;			//魔法攻击
	vector<int> MagicRec;			//魔法防御
	vector<int>	InjureImbibe;		//伤害吸收
	vector<int>	State;				//状态类成功率
	vector<int>	StateImmunity;		//状态类抵抗率
	vector<int>	FuryAddAk;			//暴击加成
	vector<int>	FuryAddRec;			//暴击抵抗
	int			PlayLv;				//玩家等级
	int			Quest;				//任务标识
	int			GoldBoxIdx;			//宝箱标识
	int			BindType;			//道具绑定类型
	int			Suit;               //套装标识
	int 		ArmsEff;			//武器特效

	int			KEY;				//钥匙标识
	int			Stone;				//宝石
	int			Glory;				//荣誉
	int			GLevel;				//公会等级
	int			Discount;			//对应折扣

	/*------------------------------------------------------------------------------
	 *作者：C.D
	 *日期：2008-05-29
	 *描述：商城道具属性
	 -----------------------------------------------------------------------------*/
	int			Mode;							//-1：该道具不产生作用 0：离线计时消耗 1：离线不计时消耗 2：耐久消耗 3：到期时间 4：永久改变
	int			ChangeDateType;					//改变方式 0：无改变方式 适用于改变装束，显示之类 1：倍数改变 2：纯粹加减改变
	int			LastTime_ms;					//持续时间	
	int			TimeStart_ms;					//开始时间点（服务器） 离线不计时消耗的时候，每次上线将重新更新。
	tm			ExpiredTime;					//装备保质期 离线记时的时候用到
	int			Endurance;						//耐久值				
	float		Param;							//改变的参数，可以是倍数，也可以加减数值。用于永久改变数值
	vector<int>	UseSkillID;						//改变属性的ID 假设：1001：改变HP；1002：改变MP……具体对应关系由策划和程序共同约定
	int			UndoSkillID;

	ItemBaseAttribute()
		:	ID(0) , SkillBook(false) ,
		MAXHP(0) , MAXMP(0) ,
		Attack(0) , fAttackRadius(0) , AttackSpeed(0) , 
		Defence(0) , 
		Hit(0) , Miss(0) ,
		PhysicalDamageAbsorb(0) , MagicDamageAbsorb(0) , PhysicalDamage(0) , MagicDamage(0) ,
		State(0) , StateImmunity(0) , AcceptCure(0) , Cure(0) , 
		DistributionMin(-1) , DistributionMax(-1) ,
		EType(ItemTypeCount) , eEquipHand(EquipHandCount) , eAttackRadius(AttackRadiusCount) ,
		Suit(0) , PlayLv(-1),
		PrevSkillID(-1) , SkillLearnID(-1) ,
		SkillID(-1) , QuestID(-1), eSkillFlag(SF_Count) ,
		MaterialType(-1) , MaterialCharacter(-1) ,MaterialProyAdd(-1),
		Faction(-1),KEY(-1),GoldBoxIdx(-1),
		Mode(-1),ChangeDateType(0),LastTime_ms(0),TimeStart_ms(0),Endurance(0),Param(0.0),UndoSkillID(0)
	{
		MAXHP.assign( 5, 0 );
		MAXMP.assign( 5, 0 );
		Attack.assign( 5, 0 );
		Defence.assign( 5, 0 );       
		MagicAk.assign( 5, 0 );      
		MagicRec.assign( 5, 0 ); 
		Hit.assign( 5, 0 );				
		Miss.assign( 5, 0 );	
		FuryAddAk.assign( 5, 0 );      
		FuryAddRec.assign( 5, 0 );    
		PhysicalDamage.assign( 5, 0 );
		MagicDamage.assign( 5, 0 );
		InjureImbibe.assign( 5, 0 );
		AcceptCure.assign( 5, 0 );    
		Cure.assign( 5, 0 );         
		State.assign( 5, 0 );     
		StateImmunity.assign( 5, 0 );
		fAttackRadius.assign( 5,0 );
		AttackSpeed.assign(5,0)	;
		UseSkillID.assign(5,0);
	}
};

struct ItemAppendAttribute
{

	enum ItemAppendType
	{
		AttackA,
		DefenceA,
		AddMagicAk,
		AddMagicRec,
		Hit,
		Miss,
		FuryAkAdd,
		FuryAkRec,
		PhysicalDamage,
		MagicDamage,
		InjureImbibe,
		State,
		StateImmunity,
		MaxHP,
		MaxMP,
		HPRestore,
		MPRestore,
		AcceptCure,
		Cure,
		ItemAppendTypeCount
	};

	int ID;

	int Type;//ItemAppendType Type 新附加tao

	std::vector<float> LvInfo;

	std::vector<int> Distribution;
	int DistributionRandom;
	int Random;

	int Flag;
	ItemAppendAttribute()
		:	ID(0) ,Type(ItemAppendTypeCount) ,
		DistributionRandom(0) , Random(0)
	{

	}
};

struct DropConfig
{
	int DropNum;
	int DropProbability;
	int AppendDropProbability;
	int Distribution;

	DropConfig()
		:	DropNum(0) ,
		DropProbability(0) , AppendDropProbability(0) ,
		Distribution(0)
	{

	}
};

struct  ConfirmDrop  : public DropConfig
{
	char  ItemTable[12];
	ConfirmDrop():DropConfig()
	{
	   strcpy(ItemTable,"NULL");
	}
};

class Item
{
public:

	Item();
	~Item();

	bool HasClass(int n);

	void SetItemBaseAttribute(ItemBaseAttribute* attribute);
	ItemBaseAttribute* GetItemBaseAttribute();

	void SetItemAppendAttribute(ItemAppendAttribute* attribute , int index);
	ItemAppendAttribute* GetItemAppendAttribute(int index);
	void ClearAppendAttribute();

	int InsertAppendAttribute(ItemAppendAttribute* attribute);

	ItemData GetItemData();

	int GetEquipLV(){ return m_BaseAttribute->PlayLv;}

	void Init(int Base , int* Append , int BaseLV, int Appendlevel, int Overlap);

	void Clear();
	bool IsClear();

	bool IsFull();

	int m_Overlap;

	bool m_Binding;
	//买卖专业
	char m_BuyType[3];

	//del warning
	unsigned int m_BuyConsume[3];
	char m_BuyTypeNum;
	int Discount;
	int StoneDiscount;
	int GloryDiscount;

	int BaseLevel;
	int AppLevel;
	long ICdKey;

	/*------------------------------------------------------------------------------
	 *作者：C.D
	 *日期：2008-06-03
	 *描述：商城装备特有属性
	 -----------------------------------------------------------------------------*/
	tm			ExpiredDate;					//装备到期时间
	bool		IsExpired;						//是否过期
	bool		IsActivated;					//是否被激活


	bool m_Lock;

	void Increase(EquipData* data);
	void Decrease(EquipData* data);

	bool Push(Item* item);

	SkillFalg GetSkillFalg();

protected:
private:

	ItemAppendAttribute* m_ItemAppendAttributes[MAX_EQUIPAPPEND_COUNT];

	ItemBaseAttribute* m_BaseAttribute;
};

struct MallBase 
{
	int Discount;
	char New;
	char Hot;
	MallBase()
		:
	Discount(100),
		New(0) ,
		Hot(0) 
	{

	}
};
struct AssociationDiscount 
{
	char level;
	int StoneDiscount;
	int GloryDiscount;
};

struct ReviveConsum
{
	int money;
	int stone;
};
#endif


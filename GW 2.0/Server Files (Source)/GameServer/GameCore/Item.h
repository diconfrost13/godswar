//=====================================================================================================================
//
//		Copyright (c) 2008,�������߹�����
//		All rights reserved
//
//		�ļ����ƣ�
//		ժ    Ҫ��������Ʒ��������
//				  
//
//		��ǰ�汾��Ver1.00
//		��    �ߣ�����
//		������ڣ�2008-03-15
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
	__int64 GreenCard;		//�̿�

	bool Binding;			//�Ƿ��ǰ�
	bool Equip;				//�Ƿ��װ��
	bool Use;				//�Ƿ����
	bool Treasure;			//����
	bool Auto;				//�Զ�ʹ��

	int Money;				//���
	int Bijou;				//��ʯ

	int Overlap;			//����ص�
	int	Color;				//��ɫ

	int Character;			//����Ʒ��

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
	"OneHand",			//����
	"TwoHand",			//˫��
	"MainHand",			//����
	"AuxiliaryHand",	//����
	""
};

static std::string ITEM_TYPE_STRING[] = 
{
	"weapon",				//����
	"shield",				//����

	"head",					//ͷ��
	"amulet",				//�����
	"glove",				//����
	"armor",				//����
	"cloth",				//����
	"cuff",					//����
	"girdle",				//����
	"shoes",				//Ь��
	"leggins",				//����
	"ring",					//��ָ

	"consume item",			//���ѵ���

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
		OneHand = 0,		//����
		TwoHand,			//˫��

		MainHand,			//����
		AuxiliaryHand,		//����

		EquipHandCount
	};

	int ID;							//id
	int Faction;					//��Ӫ
	bool SkillBook;					//������

	vector<int> Class;				//ְҵ����
	int	eSkillFlag;					//��������
	int	PrevSkillID;				//��Ҫ����ID
	int SkillLearnID;				//ѧϰ����ID
	int SkillID;					//����ID
	int QuestID;

	int Random;						//ϡ�ж�

	int DistributionMin;			//������Сֵ
	int DistributionMax;			//�������ֵ

	vector<int>		Attack;			//��ս������
	vector<float>	fAttackRadius;	//������Χ		
	vector<float>   AttackSpeed;	//�����ٶ�

	vector<int>     Defence;		//�������

	vector<int>		Hit;			//����
	vector<int>		Miss;			//����

	vector<int>		MAXHP;			//ֵ	
	vector<int>		MAXMP;			//ֵ

	vector<float> AcceptCure;		//�ܵ��ļ�������Ч��	
	vector<float> Cure;				//ʹ�õļ�������Ч��	

	vector<float> PhysicalDamage;	//�����˺�	
	vector<float> MagicDamage;		//ħ���˺�

	float PhysicalDamageAbsorb;		//�����˺�
	float MagicDamageAbsorb;		//����ħ���˺�	

	int	MaterialType;				//��ʯ����
	int MaterialCharacter;			//��ʯƷ��
	int MaterialProyAdd;            //��ʯ�ϳɳɹ���

	std::vector<int> MainAttribute;	//��������	

	ItemType EType;					//���e

	std::vector<int>	QuestsID;	//����ID

	EquipHand eEquipHand;			//װ����

	AttackRadius eAttackRadius;		//��սԶ��

	//���� ���� -----------------------------------
	//vector<int> Distribution;
	vector<int>	MagicAk;			//ħ������
	vector<int> MagicRec;			//ħ������
	vector<int>	InjureImbibe;		//�˺�����
	vector<int>	State;				//״̬��ɹ���
	vector<int>	StateImmunity;		//״̬��ֿ���
	vector<int>	FuryAddAk;			//�����ӳ�
	vector<int>	FuryAddRec;			//�����ֿ�
	int			PlayLv;				//��ҵȼ�
	int			Quest;				//�����ʶ
	int			GoldBoxIdx;			//�����ʶ
	int			BindType;			//���߰�����
	int			Suit;               //��װ��ʶ
	int 		ArmsEff;			//������Ч

	int			KEY;				//Կ�ױ�ʶ
	int			Stone;				//��ʯ
	int			Glory;				//����
	int			GLevel;				//����ȼ�
	int			Discount;			//��Ӧ�ۿ�

	/*------------------------------------------------------------------------------
	 *���ߣ�C.D
	 *���ڣ�2008-05-29
	 *�������̳ǵ�������
	 -----------------------------------------------------------------------------*/
	int			Mode;							//-1���õ��߲��������� 0�����߼�ʱ���� 1�����߲���ʱ���� 2���;����� 3������ʱ�� 4�����øı�
	int			ChangeDateType;					//�ı䷽ʽ 0���޸ı䷽ʽ �����ڸı�װ������ʾ֮�� 1�������ı� 2������Ӽ��ı�
	int			LastTime_ms;					//����ʱ��	
	int			TimeStart_ms;					//��ʼʱ��㣨�������� ���߲���ʱ���ĵ�ʱ��ÿ�����߽����¸��¡�
	tm			ExpiredTime;					//װ�������� ���߼�ʱ��ʱ���õ�
	int			Endurance;						//�;�ֵ				
	float		Param;							//�ı�Ĳ����������Ǳ�����Ҳ���ԼӼ���ֵ���������øı���ֵ
	vector<int>	UseSkillID;						//�ı����Ե�ID ���裺1001���ı�HP��1002���ı�MP���������Ӧ��ϵ�ɲ߻��ͳ���ͬԼ��
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

	int Type;//ItemAppendType Type �¸���tao

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
	//����רҵ
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
	 *���ߣ�C.D
	 *���ڣ�2008-06-03
	 *�������̳�װ����������
	 -----------------------------------------------------------------------------*/
	tm			ExpiredDate;					//װ������ʱ��
	bool		IsExpired;						//�Ƿ����
	bool		IsActivated;					//�Ƿ񱻼���


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


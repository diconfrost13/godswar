#include "stdafx.h"
#include "ItemManager.h"
#include "Monster.h"
#include "ItemBackup.h"
#include <time.h>

ItemManager* ItemManager::m_This = NULL;

unsigned __int64 g_TradeID = 1;
unsigned __int64 g_StallID = 100000000001;	//1M,以后是STALL用.

ItemManager::ItemManager()
{

}

ItemManager::~ItemManager()
{

}

ItemManager* ItemManager::Instance()
{
	if (!m_This)
		m_This = new ItemManager();

	return m_This;
}

void ItemManager::Release()
{
	delete this;

	m_This = NULL;
}


#include "../DataCore.h"

void ItemManager::Init()
{
	::_get_timezone(&m_TimeZone);

	LoadItemBaseAttribute("./Item/ItemBaseAttribute.xml");
	LoadItemAppendAttribute("./Item/ItemAppendAttribute.xml");
	LoadEquipForge("./Item/EquipForge.xml");
	LoadBijouForge("./Item/BijouForge.xml");

	LoadItemShop("./Item/ItemShop.xml");
	LoadRevive("./Item/Revive.xml");

	//printf("\n");
	// 	Item item = CreateItem(5 , 10 , CharacterD , 1000);
	// 	BackupStall(1 , 1 , &item , 1 , 1 , 1);
	// 	BackupStall(1 , 1 , &item , 2 , 2 , 2);

	// 	CMonster* monster = new CMonster();
	// 	monster->m_DropItems[0].Clear();
	// 	monster->m_DropConfig.DropProbability = 100;
	// 	monster->m_DropConfig.DropNum = 1;
	// 	monster->m_DropConfig.Distribution = 10;
	// 	monster->m_Level = 3;
	// 
	// 	for (int i = 0 ; i < 100 ; i++)
	// 	{	
	// 		//Item item = CreateItem(5 , 10 , CharacterD , 1000);
	// 
	// 
	// 
	// 		Item item = *CreateItem(monster);
	// 
	// 		printf("ID: %d  " , item.GetItemBaseAttribute()->ID);
	// 
	// 		for (int j = 0 ; j < MAX_EQUIPAPPEND_COUNT ; j++)
	// 		{
	// 			printf("\t");
	// 
	// 			if (item.GetItemAppendAttribute(j))
	// 			{
	// 				//printf(item.GetItemAppendAttribute(j)->AttributeName.c_str());
	// 				//printf(" value %f" , item.m_Append[j]);
	// 			}
	// 		}
	// 
	// 		printf("\n");
	// 	}

}

bool ItemManager::LoadEquipForge(const char* path)
{
	if (!XMLBase::Load(path))
		return false;

	TiXmlElement* root = XMLBase::m_TiXmlDocument.RootElement();

	if (!root)
		return false;

	if (strcmp(root->Value() , "EquipForge"))
		return false;

	TiXmlElement* child = root->FirstChildElement();

	while (child)
	{
		TiXmlAttribute* attr = child->FirstAttribute();

		int id;
		EquipForgeBase base;
		int level;
		EquipForgeAppend append;

		memset(&base,0x00,sizeof(EquipForgeBase));
		memset(&append,0x00,sizeof(EquipForgeAppend));

		while(attr)
		{
			if (strcmp(attr->Name() , "ID") == 0)
				id = attr->IntValue();
			else if (strcmp(attr->Name() , "NextID") == 0)
				base.NextID = attr->IntValue();
			else if (strcmp(attr->Name() , "BadID") == 0)
				base.BadID = attr->IntValue();
			else if (strcmp(attr->Name() , "Probability") == 0)
				base.Probability = attr->IntValue();

			else if (strcmp(attr->Name() , "BaseProyAdd") == 0)
			{
				string s = attr->Value();

				while (s.find(",") != -1)
				{
					UINT n = (UINT)s.find(",");
					s[n] = '\0';
					base.BaseProyAdd.push_back(atoi(s.c_str()));
					s.erase(s.begin() , s.begin() + n + 1);
				}
				base.BaseProyAdd.push_back(atoi(s.c_str()));
			}
			else if (strcmp(attr->Name() , "AppendProyAdd") == 0)
			{
				string s = attr->Value();

				while (s.find(",") != -1)
				{
					UINT n = (UINT)s.find(",");
					s[n] = '\0';
					base.AppendProyAdd.push_back(atoi(s.c_str()));
					s.erase(s.begin() , s.begin() + n + 1);
				}
				base.AppendProyAdd.push_back(atoi(s.c_str()));
			}

			if (strcmp(attr->Name() , "Level") == 0)
				level = attr->IntValue();
			else if (strcmp(attr->Name() , "Probability") == 0)
				append.Probability = attr->IntValue();
			else if (strcmp(attr->Name() , "MaterialCharacter") == 0)
				append.MaterialCharacter = attr->IntValue();

			else if (strcmp(attr->Name() , "Amoney") == 0)
			{
				string s = attr->Value();

				while (s.find(",") != -1)
				{
					UINT n = (UINT)s.find(",");
					s[n] = '\0';
					base.Amoney.push_back(atoi(s.c_str()));
					s.erase(s.begin() , s.begin() + n + 1);
				}
				base.Amoney.push_back(atoi(s.c_str()));
			}
			else if (strcmp(attr->Name() , "Bmoney") == 0)
			{
				string s = attr->Value();

				while (s.find(",") != -1)
				{
					UINT n = (UINT)s.find(",");
					s[n] = '\0';
					base.Bmoney.push_back(atoi(s.c_str()));
					s.erase(s.begin() , s.begin() + n + 1);
				}
				base.Bmoney.push_back(atoi(s.c_str()));
			}
			else if (strcmp(attr->Name() , "Cmoney") == 0)
			{
				string s = attr->Value();

				while (s.find(",") != -1)
				{
					UINT n = (UINT)s.find(",");
					s[n] = '\0';
					base.Cmoney.push_back(atoi(s.c_str()));
					s.erase(s.begin() , s.begin() + n + 1);
				}
				base.Cmoney.push_back(atoi(s.c_str()));
			}
			attr = attr->Next();
		}

		m_EquipForgeBase[id] = base;
		m_EquipForgeAppend[level] = append;


		child = child->NextSiblingElement();
	}

	return true;
}

bool ItemManager::LoadBijouForge(const char* path)
{
	if (!XMLBase::Load(path))
		return false;

	TiXmlElement* root = XMLBase::m_TiXmlDocument.RootElement();

	if (!root)
		return false;

	if (strcmp(root->Value() , "BijouForge"))
		return false;

	TiXmlElement* child = root->FirstChildElement();

	while (child)
	{
		TiXmlAttribute* attr = child->FirstAttribute();

		int id;
		EquipForgeBase base;
		int level;
		EquipForgeAppend append;

		memset(&base,0x00,sizeof(EquipForgeBase));
		memset(&append,0x00,sizeof(EquipForgeAppend));

		while(attr)
		{
			if (strcmp(attr->Name() , "ID") == 0)
				id = attr->IntValue();
			else if (strcmp(attr->Name() , "NextID") == 0)
				base.NextID = attr->IntValue();
			else if (strcmp(attr->Name() , "BadID") == 0)
				base.BadID = attr->IntValue();
			else if (strcmp(attr->Name() , "Probability") == 0)
				base.Probability = attr->IntValue();
			else if (strcmp(attr->Name() , "MaterialProyAdd") == 0)
				base.MaterialProyAdd = attr->IntValue();

			else if (strcmp(attr->Name() , "MaterialType") == 0)
				base.MaterialType = attr->IntValue();

			if (strcmp(attr->Name() , "Level") == 0)
				level = attr->IntValue();
			else if (strcmp(attr->Name() , "Probability") == 0)
				append.Probability = attr->IntValue();
			else if (strcmp(attr->Name() , "MaterialCharacter") == 0)
				append.MaterialCharacter = attr->IntValue();


			attr = attr->Next();
		}

		m_EquipForgeBase[id] = base;
		//m_EquipForgeAppend[level] = append;


		child = child->NextSiblingElement();
	}

	return false;
}

//加载物品配置表
void ItemManager::AddBaseAttribute(TiXmlElement* root)
{
	ItemBaseAttribute eba;

	//eba.AttributeName = root->Value();
	//eba.TypeString = root->Parent()->Value();

	TiXmlAttribute* attr = root->FirstAttribute();

	while (attr)
	{
		//if (strcmp(attr->Name() , "Hair") == 0)
		//	eba.Hair = (attr->IntValue() == 1);
		if (strcmp(attr->Name() , "ID") == 0)
		{
			eba.ID = attr->IntValue();
		}
		else if (strcmp(attr->Name() , "Faction") == 0)
			eba.Faction = attr->IntValue();
		else if (strcmp(attr->Name() , "Icon") == 0)
		{

		}
		else if (strcmp(attr->Name() , "Sell") == 0)
		{

		}
		else if (strcmp(attr->Name() , "Type") == 0)
		{
			int i = 0;

			for ( ; i < ItemBaseAttribute::ItemTypeCount ; i++)
			{
				if (strcmp(attr->Value() , ITEM_TYPE_STRING[i].c_str()) == 0)
					break;
			}

			assert(i != ItemBaseAttribute::ItemTypeCount);
			eba.EType = (ItemBaseAttribute::ItemType)i;
		}
		else if (strcmp(attr->Name() , "Distribution") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				//eba.Distribution.push_back( atoi(s.c_str()) );
				eba.DistributionMin = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}
			eba.DistributionMax = atoi(s.c_str());
			//eba.Distribution.push_back(atoi(s.c_str()));
		}
		else if (strcmp(attr->Name() , "Random") == 0)
		{ 
			eba.Random = attr->IntValue(); 
		}
		else if (strcmp(attr->Name() , "MagicAk") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{

				//del warning
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.MagicAk[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.MagicAk[index] = atoi(s.c_str());
		}	
		else if (strcmp(attr->Name() , "Defence") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.Defence[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.Defence[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "MagicRec") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.MagicRec[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.MagicRec[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "MainAttribute") == 0)
		{
			string s = attr->Value();
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.MainAttribute.push_back(atoi(s.c_str()));
				s.erase(s.begin() , s.begin() + n + 1);
			}
			eba.MainAttribute.push_back(atoi(s.c_str()));
		}
		else if (strcmp(attr->Name() , "Class") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';

				eba.Class.push_back(atoi(s.c_str()));

				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.Class.push_back(atoi(s.c_str()));
		}
		else if (strcmp(attr->Name() , "SkillFlag") == 0)
			eba.eSkillFlag = attr->IntValue();
		//else if (strcmp(attr->Name() , "PrevSkillID") == 0)
		//	eba.PrevSkillID = attr->IntValue();
		//by lion
		//else if (strcmp(attr->Name() , "Level") == 0)
		//	eba.Level=attr->IntValue();
		//by lion
		else if (strcmp(attr->Name() , "Attack") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.Attack[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.Attack[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "AttackRadius") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.fAttackRadius[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.fAttackRadius[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "AttackSpeed") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.AttackSpeed[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.AttackSpeed[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "BindType") == 0){ eba.BindType = attr->IntValue(); }
		else if (strcmp(attr->Name() , "PlayLv") == 0){ eba.PlayLv = attr->IntValue(); }

		else if (strcmp(attr->Name() , "Hit") == 0)
		{
			string s = attr->Value();
			int index =0 ;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.Hit[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.Hit[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "Miss") == 0)
		{
			string s = attr->Value();
			int index =0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.Miss[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.Miss[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "MaxHP") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.MAXHP[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.MAXHP[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "MaxMP") == 0)
		{
			string s = attr->Value();
			int index = 0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.MAXMP[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.MAXMP[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "State") == 0)
		{
			string s = attr->Value();
			int index = 0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.State[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.State[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "StateImmunity") == 0)
		{
			string s = attr->Value();
			int index = 0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.StateImmunity[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.StateImmunity[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "InjureImbibe") == 0)
		{
			string s = attr->Value();
			int index = 0 ;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.InjureImbibe[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.InjureImbibe[index] = atoi(s.c_str());
		}	
		else if (strcmp(attr->Name() , "FuryAddAk") == 0)
		{
			string s = attr->Value();
			int index = 0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.FuryAddAk[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.FuryAddAk[index] = atoi(s.c_str());
		}	
		else if (strcmp(attr->Name() , "FuryAddRec") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.FuryAddRec[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.FuryAddRec[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "AcceptCure") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.AcceptCure[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.AcceptCure[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "Cure") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.Cure[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.Cure[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "PhysicalDamage") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.PhysicalDamage[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.PhysicalDamage[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "MagicDamage") == 0)
		{
			string s = attr->Value();
			int index=0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.MagicDamage[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}

			eba.MagicDamage[index] = atoi(s.c_str());
		}
		else if (strcmp(attr->Name() , "PhysicalDamageAbsorb") == 0)
			eba.PhysicalDamageAbsorb = attr->DoubleValue();
		else if (strcmp(attr->Name() , "MagicDamageAbsorb") == 0)
			eba.MagicDamageAbsorb = attr->DoubleValue();
		else if (strcmp(attr->Name() , "Suit") == 0)
			eba.Suit = attr->IntValue();
		else if (strcmp(attr->Name() , "Money") == 0)
			eba.Money = attr->IntValue();
		else if (strcmp(attr->Name() , "Overlap") == 0)
			eba.Overlap = attr->IntValue();
		else if (strcmp(attr->Name() , "Use") == 0)
			eba.Use = attr->IntValue();
		else if (strcmp(attr->Name() , "Equip") == 0)
			eba.Equip = attr->IntValue();
		else if (strcmp(attr->Name() , "Skill") == 0)
			eba.SkillID = attr->IntValue();
		else if (strcmp(attr->Name() , "PrevSkillID") == 0)
		{
			eba.PrevSkillID = attr->IntValue();
			eba.SkillBook = true;
		}
		else if (strcmp(attr->Name() , "SkillID") == 0)
			eba.SkillLearnID = attr->IntValue();
		else if (strcmp(attr->Name() , "Skill") == 0)
			eba.SkillID = attr->IntValue();
		else if (strcmp(attr->Name() , "Quest") == 0)
			eba.QuestID = attr->IntValue();
		else if (strcmp(attr->Name() , "MaterialType") == 0)
			eba.MaterialType = attr->IntValue();
		else if (strcmp(attr->Name() , "MaterialCharacter") == 0)
			eba.MaterialCharacter = attr->IntValue();
		else if (strcmp(attr->Name() , "Hand") == 0)
			eba.eEquipHand = (ItemBaseAttribute::EquipHand)attr->IntValue();
		else if (strcmp(attr->Name() , "GoldBoxIdx") == 0)
			eba.GoldBoxIdx = attr->IntValue();
		else if (strcmp(attr->Name() , "KEY") == 0)
			eba.KEY = attr->IntValue();

		//------------------商城卖出的有尝道具 by C.D
		else if (strcmp(attr->Name() , "Mode") == 0)
			eba.Mode = attr->IntValue();
		else if (strcmp(attr->Name() , "ChangeDateType") == 0)
			eba.ChangeDateType = attr->IntValue();
		else if (strcmp(attr->Name() , "LastTime_S") == 0)
			eba.LastTime_ms = attr->IntValue() * 1000;
		else if (strcmp(attr->Name() , "Endurance") == 0)
			eba.Endurance = attr->IntValue();
		else if (strcmp(attr->Name() , "Param") == 0)
			eba.Param = attr->IntValue();
		else if (strcmp(attr->Name() , "UseSkillID") == 0)
		{
			string s = attr->Value();
			int index = 0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				eba.UseSkillID[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
			}
			eba.UseSkillID[index] = atoi(s.c_str());
		}
// 		else if (strcmp(attr->Name(), "ExpiredDate") == 0)
// 		{			
// 			int		timer[8];
// 			string s = attr->Value();
// 			int index = 0;
// 			while (s.find(",") != -1)
// 			{
// 				UINT n = (UINT)s.find(",");
// 				s[n] = '\0';
// 				timer[index] = atoi(s.c_str());
// 				s.erase(s.begin() , s.begin() + n + 1);
// 				index++;
// 				ASSERT(index<=5);//年月日时分秒，只有6个参数
// 			}
// 			timer[index] = atoi(s.c_str());
// 			eba.ExpiredDate.tm_year	= timer[0]-1900; //年
// 			eba.ExpiredDate.tm_mon	= timer[1]-1;//月
// 			eba.ExpiredDate.tm_mday	= timer[2];//日
// 			eba.ExpiredDate.tm_hour	= timer[3];//时
// 			eba.ExpiredDate.tm_min	= timer[4];//分
// 			eba.ExpiredDate.tm_sec	= timer[5];//秒			
// 		}
		else if (strcmp(attr->Name() , "ExpiredTime") == 0)
		{
			int		timer[8];
			string s = attr->Value();
			int index = 0;
			while (s.find(",") != -1)
			{
				UINT n = (UINT)s.find(",");
				s[n] = '\0';
				timer[index] = atoi(s.c_str());
				s.erase(s.begin() , s.begin() + n + 1);
				index++;
				ASSERT(index<=5);//年月日时分秒，只有6个参数
			}
			timer[index] = atoi(s.c_str());
			eba.ExpiredTime.tm_year	= timer[0]; //年
			eba.ExpiredTime.tm_mon	= timer[1];//月
			eba.ExpiredTime.tm_mday	= timer[2];//日
			eba.ExpiredTime.tm_hour	= timer[3];//时
			eba.ExpiredTime.tm_min	= timer[4];//分
			eba.ExpiredTime.tm_sec	= timer[5];//秒		
		}
		else if (strcmp(attr->Name() , "UndoSkillID") == 0)
			eba.UndoSkillID = attr->IntValue();
		//  [5/31/2008]by C.D 
		attr = attr->Next();
	}

	m_ItemBaseAttribute.push_back(eba);
}

bool ItemManager::LoadItemBaseAttribute(const char* path)
{
	if (!XMLBase::Load(path))
		return false;

	TiXmlElement* root = XMLBase::m_TiXmlDocument.RootElement();

	if (!root)
		return false;

	if (strcmp(root->Value() , "ItemBaseAttribute"))
		return false;

	TiXmlElement* child = root->FirstChildElement();

	while (child)
	{
		if (strcmp(child->Value() , "Weapons") == 0)
		{
			TiXmlElement* element = child->FirstChildElement();

			while (element)
			{
				TiXmlElement* weapon = element->FirstChildElement();

				while (weapon)
				{
					AddBaseAttribute(weapon);

					weapon = weapon->NextSiblingElement();
				}

				element = element->NextSiblingElement();
			}
		}
		//else if (strcmp(child->Value() , "heads") == 0)
		//{
		//	TiXmlElement* element = child->FirstChildElement();

		//	while (element)
		//	{
		//		TiXmlElement* head = element->FirstChildElement();

		//		while (head)
		//		{
		//			AddBaseAttribute(head);

		//			head = head->NextSiblingElement();
		//		}

		//		element = element->NextSiblingElement();
		//	}
		//}
		else
		{
			TiXmlElement* element = child->FirstChildElement();

			while (element)
			{
				AddBaseAttribute(element);

				element = element->NextSiblingElement();
			}
		}

		child = child->NextSiblingElement();
	}

	for (size_t i = 0 ; i < m_ItemBaseAttribute.size() ; i++)
	{
		if (m_ItemBaseAttributeMap.find(m_ItemBaseAttribute[i].ID) != m_ItemBaseAttributeMap.end())
			ASSERT(0);

		m_ItemBaseAttributeMap[m_ItemBaseAttribute[i].ID] = &m_ItemBaseAttribute[i];
	}

	return true;
}

bool ItemManager::LoadItemShop(const char* path)
{
	//cdx
	if (!XMLBase::Load(path))
		return false;

	TiXmlElement* root = XMLBase::m_TiXmlDocument.RootElement();

	if (!root)
		return false;

	if (strcmp(root->Value() , "ItemShop"))
		return false;

	TiXmlElement* child = root->FirstChildElement();

	while (child)
	{
		if (strcmp(child->Value() , "Shop") == 0)
		{
			TiXmlElement* element = child->FirstChildElement();

			while (element)
			{
				TiXmlAttribute* attr = element->FirstAttribute();

				int id;
				MallBase base;

				while(attr)
				{
					if (strcmp(attr->Name() , "ID") == 0)
						id = attr->IntValue();
					else if (strcmp(attr->Name() , "Discount") == 0)
						base.Discount = attr->IntValue();	
					else if (strcmp(attr->Name() , "New") == 0)
						base.New = (char)attr->IntValue();	
					else if (strcmp(attr->Name() , "Hot") == 0)
						base.Hot = (char)attr->IntValue();	
					attr = attr->Next();
				}

				m_MallBase[id] = base;

				element = element->NextSiblingElement();
			}
		}
		else if (strcmp(child->Value() , "Guild") == 0)
		{
			TiXmlElement* element = child->FirstChildElement();

			while (element)
			{
				TiXmlAttribute* attr = element->FirstAttribute();

				int level;
				AssociationDiscount discount;

				while(attr)
				{
					if (strcmp(attr->Name() , "Glevel") == 0)
					{
						level = attr->IntValue();
						discount.level = level;
					}
					else if (strcmp(attr->Name() , "DiscountA") == 0)
						discount.StoneDiscount = attr->IntValue();
					else if (strcmp(attr->Name() , "DiscountB") == 0)
						discount.GloryDiscount = attr->IntValue();		
					attr = attr->Next();
				}

				m_AssociationDiscount[level] = discount;

				element = element->NextSiblingElement();
			}
		}

		child = child->NextSiblingElement();
	}
	return true;

}

bool ItemManager::LoadRevive( const char* path)
{
	//cdx
	if (!XMLBase::Load(path))
		return false;

	TiXmlElement* root = XMLBase::m_TiXmlDocument.RootElement();

	if (!root)
		return false;

	if (strcmp(root->Value() , "Revive"))
		return false;

	TiXmlElement* child = root->FirstChildElement();

	while (child)
	{
		if (strcmp(child->Value() , "ReviveConsume") == 0)
		{
			TiXmlElement* element = child->FirstChildElement();

			while (element)
			{
				TiXmlAttribute* attr = element->FirstAttribute();

				int level;
				ReviveConsum consume;

				while(attr)
				{
					if (strcmp(attr->Name() , "level") == 0)
						level = attr->IntValue();
					else if (strcmp(attr->Name() , "money") == 0)
						consume.money = attr->IntValue();	
					else if (strcmp(attr->Name() , "stone") == 0)
						consume.stone = attr->IntValue();	
					attr = attr->Next();
				}

				m_ReviveConsume[level] = consume;

				element = element->NextSiblingElement();
			}
		}
		
		child = child->NextSiblingElement();
	}

	return true;
}
//新附加tao
bool ItemManager::LoadItemAppendAttribute(const char* path)
{
	if (!XMLBase::Load(path))
		return false;

	TiXmlElement* root = XMLBase::m_TiXmlDocument.RootElement();

	if (!root)
		return false;

	if (strcmp(root->Value() , "ItemAppendAttribute"))
		return false;

	TiXmlElement* type = root->FirstChildElement();

	int LoadNum=0;
	while (type)
	{
		TiXmlAttribute* attr = type->FirstAttribute();

		ItemAppendAttribute eaa;

		while (attr)
		{
			if (strcmp(attr->Name() , "Distribution") == 0)
			{
				string s = attr->Value();

				while (s.find(",") != -1)
				{
					UINT n = (UINT)s.find(",");
					s[n] = '\0';
					eaa.Distribution.push_back(atoi(s.c_str()));
					s.erase(s.begin() , s.begin() + n + 1);
				}

				eaa.Distribution.push_back(atoi(s.c_str()));
			}
			else if (strcmp(attr->Name() , "Type") == 0)
				eaa.Type = attr->IntValue();
			else if (strcmp(attr->Name() , "ID") == 0)
				eaa.ID = attr->IntValue();
			else if (strcmp(attr->Name() , "L1") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L2") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L3") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L4") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L5") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L6") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L7") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L8") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L9") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L10") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L11") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L12") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L13") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L14") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L15") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "Flag") == 0)
				eaa.Flag = attr->IntValue();

			attr = attr->Next();
		}

		m_ItemAppendAttribute[LoadNum] = eaa;
		m_ItemAppendAttributeMap[eaa.ID] = &m_ItemAppendAttribute[LoadNum];
		LoadNum++;
		type = type->NextSiblingElement();
	}

	for (int i = 0 ; i < LoadNum ; i++)//
	{
		for (size_t k = 0 ; k < m_ItemAppendAttribute[i].Distribution.size() ; k++)
		{
			m_ItemDistributionMap[m_ItemAppendAttribute[i].Distribution[k]] = &m_ItemAppendAttribute[i];
		}
	}

	return true;
}

//新附加tao
/*bool ItemManager::LoadItemAppendAttribute(const char* path)
{
	if (!XMLBase::Load(path))
		return false;

	TiXmlElement* root = XMLBase::m_TiXmlDocument.RootElement();

	if (!root)
		return false;

	if (strcmp(root->Value() , "ItemAppendAttribute"))
		return false;

	TiXmlElement* type = root->FirstChildElement();

	while (type)
	{
		TiXmlAttribute* attr = type->FirstAttribute();

		ItemAppendAttribute eaa;

		while (attr)
		{
			if (strcmp(attr->Name() , "Distribution") == 0)
			{
				string s = attr->Value();

				while (s.find(",") != -1)
				{
					UINT n = (UINT)s.find(",");
					s[n] = '\0';
					eaa.Distribution.push_back(atoi(s.c_str()));
					s.erase(s.begin() , s.begin() + n + 1);
				}

				eaa.Distribution.push_back(atoi(s.c_str()));
			}

			else if (strcmp(attr->Name() , "ID") == 0)
				eaa.ID = attr->IntValue();
			else if (strcmp(attr->Name() , "L1") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L2") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L3") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L4") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L5") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L6") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L7") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L8") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L9") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L10") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L11") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L12") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L13") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L14") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "L15") == 0)
				eaa.LvInfo.push_back(attr->DoubleValue());
			else if (strcmp(attr->Name() , "Flag") == 0)
				eaa.Flag = attr->IntValue();

			attr = attr->Next();
		}

		for (int i = 0 ; i < ItemAppendAttribute::ItemAppendTypeCount ; i++)
		{
			if (strcmp(type->Value() , ITEM_APPENDTYPE_STRING[i].c_str()) == 0)
			{
				eaa.Type = (ItemAppendAttribute::ItemAppendType)i;
				break;
			}
		}

		m_ItemAppendAttribute[eaa.Type] = eaa;

		type = type->NextSiblingElement();

	}


	for (int i = 0 ; i < ItemAppendAttribute::ItemAppendTypeCount ; i++)//
	{
		if (m_ItemAppendAttributeMap.find(m_ItemAppendAttribute[i].ID) != m_ItemAppendAttributeMap.end())
			ASSERT(0);

		m_ItemAppendAttributeMap[m_ItemAppendAttribute[i].ID] = &m_ItemAppendAttribute[i];

		for (size_t k = 0 ; k < m_ItemAppendAttribute[i].Distribution.size() ; k++)
		{
			if (m_ItemDistributionMap.find(m_ItemAppendAttribute[i].Distribution[k]) != m_ItemDistributionMap.end())
				ASSERT(0);

			m_ItemDistributionMap[m_ItemAppendAttribute[i].Distribution[k]] = &m_ItemAppendAttribute[i];
		}
	}

	return true;
}*/

EquipForgeBase* ItemManager::GetEquipForgeBase(int id)
{
	map<int , EquipForgeBase>::iterator iter = m_EquipForgeBase.find(id);

	if (iter != m_EquipForgeBase.end())
		return &iter->second;

	return NULL;
}

EquipForgeAppend* ItemManager::GetEquipForgeAppend(int id)
{
	map<int , EquipForgeAppend>::iterator iter = m_EquipForgeAppend.find(id);

	if (iter != m_EquipForgeAppend.end())
		return &iter->second;

	return NULL;
}

void ItemManager::CreateItem(ItemData* pData , Item* pItem)
{
	char Ifbuf[128];

	if ( NULL == pItem )
	{
		_stprintf(Ifbuf,"CreateItem() NULL == pItem");
		sbase::SysLogSave(Ifbuf);
		return ;
	}

	if ( NULL == pData )
	{
		_stprintf(Ifbuf,"CreateItem() NULL == pData");
		sbase::SysLogSave(Ifbuf);
		return ;
	}

	if(!pItem->GetItemBaseAttribute())
	{
		_stprintf(Ifbuf,"CreateItem() !pItem->GetItemBaseAttribute()");
		sbase::SysLogSave(Ifbuf);
	}

	if(pItem->BaseLevel<=0 || pItem->BaseLevel>5 || pItem->AppLevel<=0 || pItem->AppLevel>10)
	{
		_stprintf(Ifbuf,"CreateItem() Lv error %d,%d",pItem->BaseLevel,pItem->AppLevel);
		sbase::SysLogSave(Ifbuf);
	}

	if (m_ItemBaseAttributeMap.find(pData->Base) == m_ItemBaseAttributeMap.end())
	{
		pItem->Clear();
		return;
	}

	pItem->Clear();

	pItem->SetItemBaseAttribute(m_ItemBaseAttributeMap[pData->Base]);

	pItem->m_Binding = !!pData->Binding;
	pItem->m_Overlap = pData->Overlap;

	for (int i = 0 ; i < MAX_EQUIPAPPEND_COUNT ; i++)
	{
		if (m_ItemAppendAttributeMap.find(pData->Append[i]) != m_ItemAppendAttributeMap.end())
			pItem->SetItemAppendAttribute(m_ItemAppendAttributeMap[pData->Append[i]] , i);
	}

	pItem->BaseLevel = pData->BaseLV;
	pItem->AppLevel = pData->AppendLV;

	CreateItemKey( pItem );
}

void  ItemManager::CreateItemKey( Item*pItem )
{	 
	char Ifbuf[128];
	if(!pItem)
	{
		_stprintf(Ifbuf,"!pItem");
		sbase::SysLogSave(Ifbuf);
	}

	if(!pItem->GetItemBaseAttribute())
	{
		_stprintf(Ifbuf,"!pItem->GetItemBaseAttribute()");
		sbase::SysLogSave(Ifbuf);
	}
	else
	{
		//根据时间性质产生不同的CdKey序列号
		time_t	timep;
		time(&timep);
		tm* tm_buf = localtime(&timep);
		static int CurAddTimeValue=0;
		ItemData *Idata = &pItem->GetItemData();
		Idata->CdKey=tm_buf->tm_yday+1900+tm_buf->tm_mon+1+tm_buf->tm_mday+tm_buf->tm_hour+tm_buf->tm_min+tm_buf->tm_sec+CurAddTimeValue;
		pItem->ICdKey=Idata->CdKey;
		CurAddTimeValue++;
	}
}

Item* ItemManager::CreateConfimItem( CMonster* pMonster )
{
	int Random = sbase::RandGet(100);

	UINT BaseID = pMonster->m_DropItemMgr.FindThisProbability( Random );

	for (vector<ItemBaseAttribute>::iterator i = m_ItemBaseAttribute.begin() ; i != m_ItemBaseAttribute.end() ; i++)
	{
		if ( (*i).ID == BaseID )
		{
			Item* pItem = NULL;
			pItem = pMonster->GetFreeItem();

			if (!pItem)
				break;

			pMonster->m_Drops++;
			pItem->m_Overlap = 1;

			pItem->SetItemBaseAttribute(&(*i));

			if (pItem->GetItemBaseAttribute()->EType == ItemBaseAttribute::ConsumeItem)
				return pItem;

			for ( int i = 0,M = pMonster->m_DropItemMgr.GetAppCount(BaseID); i < M ; i++)
			{
				int App = pMonster->m_DropItemMgr.GetAppendValues( BaseID,i );
				if (m_ItemAppendAttributeMap.find( App ) == m_ItemAppendAttributeMap.end())
					continue;

				ItemAppendAttribute* append = m_ItemAppendAttributeMap[App];
				pItem->InsertAppendAttribute(append);
			}

			pItem->BaseLevel = pMonster->m_DropItemMgr.GetBaseLV( BaseID );
			pItem->AppLevel = pMonster->m_DropItemMgr.GetAppendLV( BaseID );
			CreateItemKey(pItem);
			return pItem;
		}
	}

	return NULL;
}

Item* ItemManager::CreateItem(CMonster* pMonster)
{
	int distribution = pMonster->m_DropConfig.Distribution;

	int minlevel = pMonster->m_MonsterEquiplv > 20 ? pMonster->m_MonsterEquiplv - 20 : 1;
	int maxlevel = pMonster->m_MonsterEquiplv < 110 ? pMonster->m_MonsterEquiplv + 10 : 120;

	//  	if (maxlevel > 30)
	//  		return NULL;

	list<ItemBaseAttribute*> Items;

	int random = 0;

	//找到符合相性条件的Item集合
	for (vector<ItemBaseAttribute>::iterator i = m_ItemBaseAttribute.begin() ; i != m_ItemBaseAttribute.end() ; i++)
	{
		//tao
		//if (!(Items.BaseLevel >= minlevel && Items.BaseLevel <= maxlevel) && 
		//!(Items.BaseLevel == 0 ))
		//continue;

		if (  ( i->PlayLv != -1 )&& !( i->PlayLv >= minlevel &&  i->PlayLv <= maxlevel )  )
		{
			continue;
		}

		if (i->DistributionMin > i->DistributionMax)
		{
			if (i->DistributionMin <= distribution || i->DistributionMax >= distribution)
			{
				Items.push_back(&(*i));
				random += i->Random;
			}
		}
		else if (i->DistributionMin <= distribution && i->DistributionMax >= distribution)
		{
			Items.push_back(&(*i));
			random += i->Random;
		}
	}

	//干掉已经掉的
	for (int i = 0 ; i < pMonster->m_Drops ; i++)
	{
		Items.remove(pMonster->m_DropItems[i].GetItemBaseAttribute());
	}

	random = sbase::RandGet(random);

	int rand = 0;
	Item* item = NULL;

	for (list<ItemBaseAttribute*>::iterator i = Items.begin() ; i != Items.end() ; i++)
	{
		if ((*i)->Random + rand > random)
		{
			item = pMonster->GetFreeItem();

			if (!item)
				break;

			pMonster->m_Drops++;

			item->SetItemBaseAttribute((*i));

			//m_Items.push_back(item);

			break;
		}
		else
			rand += (*i)->Random;
	}

	if (!item)
		return NULL;

	//掉一个,
	item->m_Overlap = 1;

	if (item->GetItemBaseAttribute()->EType == ItemBaseAttribute::ConsumeItem)
		return item;

	//  	int max = item->GetItemBaseAttribute()->DistributionMax;
	//  	int min = item->GetItemBaseAttribute()->DistributionMin;

	//		int randomappends = max > min ? max - min : min - max;

	for (int i = 0 ; i < pMonster->m_Quality ; i++)
	{
		//  		rand = sbase::RandGet(randomappends) + item->GetItemBaseAttribute()->DistributionMin;
		// 
		//  		if (rand > MAXAPPENDS)
		//  			rand -= MAXAPPENDS;

		rand = sbase::RandGet(MAXAPPENDS*2);


		//如果随机到没有的,在随机一次
		if (m_ItemDistributionMap.find(rand) == m_ItemDistributionMap.end())
		{
			//  			rand = sbase::RandGet(randomappends) + item->GetItemBaseAttribute()->DistributionMin;
			// 
			//  			if (rand > MAXAPPENDS)
			//  				rand -= MAXAPPENDS;
			// 
			//  			if (m_ItemAppendAttributeMap.find(rand) == m_ItemAppendAttributeMap.end())
			continue;
		}

		ItemAppendAttribute* append = m_ItemDistributionMap[rand];

		item->InsertAppendAttribute(append);
	}

	item->BaseLevel = 1;
	item->AppLevel = 1;

	//强制变为4个附加
	item->SetItemAppendAttribute(NULL,4);
	
	CreateItemKey( item )	;
	//	item->GetItemBaseAttribute()->GreenCard = time(0) + m_TimeZone;

	//GREENCARD ,,用来作道具唯一标识,道具跟踪,恢复用,没用到
	return item;
}

Item* ItemManager::CreateItemAppend(Item* item,int CreateNum)
{
	int SetNum=0;
	while(SetNum!=CreateNum)
	{
		//  		rand = sbase::RandGet(randomappends) + item->GetItemBaseAttribute()->DistributionMin;
		// 
		//  		if (rand > MAXAPPENDS)
		//  			rand -= MAXAPPENDS;

		int rand = sbase::RandGet(MAXAPPENDS*2);


		//如果随机到没有的,在随机一次
		if (m_ItemDistributionMap.find(rand) == m_ItemDistributionMap.end())
		{
			//  			rand = sbase::RandGet(randomappends) + item->GetItemBaseAttribute()->DistributionMin;
			// 
			//  			if (rand > MAXAPPENDS)
			//  				rand -= MAXAPPENDS;
			// 
			//  			if (m_ItemAppendAttributeMap.find(rand) == m_ItemAppendAttributeMap.end())
			continue;
		}

		ItemAppendAttribute* append = m_ItemDistributionMap[rand];

		int ok=item->InsertAppendAttribute(append);
		if( !ok )
		{
			char Ifbuf[128];
			ItemData data = item->GetItemData();
			_stprintf(Ifbuf,"+附加属性ID:%d CreateNum:%d",data.Append[SetNum],CreateNum);
			sbase::ConsoleWriteColorText( FOREGROUND_RED,Ifbuf );
			SetNum ++;
		}
	}
 
	return item;
}


MallBase* ItemManager::GetMallItemAppend(int id)
{
	map<int ,MallBase>::iterator iter = m_MallBase.find(id);

	if (iter != m_MallBase.end())
	{
		return &iter->second;
	}

	return NULL;

}
AssociationDiscount* ItemManager::GetAssociationMallItemDiscount(int Level)
{
	map<int ,AssociationDiscount>::iterator iter = m_AssociationDiscount.find(Level);

	if (iter != m_AssociationDiscount.end())
	{
		return &iter->second;
	}

	return NULL;

}
std::map<int , AssociationDiscount> ItemManager::GetAssociationDiscount()
{
	return m_AssociationDiscount;
}

int ItemManager::GetReviveConsum(int Level,int ReviveType)
{
	map<int ,ReviveConsum>::iterator iter = m_ReviveConsume.find(Level);
	if (iter != m_ReviveConsume.end())
	{
		if ( ReviveType == 0 )
		{
			return iter->second.stone;
		}
		else if ( ReviveType == 1 )
		{
			return iter->second.money;
		}
	}
	return -1;
}
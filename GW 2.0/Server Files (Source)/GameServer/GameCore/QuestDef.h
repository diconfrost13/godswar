#ifndef _QUESTDEF_H_
#define _QUESTDEF_H_

#include <vector>
#include "GameData.h"
#include "Item.h"
#pragma  warning(disable:4702)
class CPlayer;

//enum
//{
//	INVALIDREASON_DONT_HAVE_REQ        = 0,
//	INVALIDREASON_DONT_HAVE_REQLEVEL   = 1,
//	INVALIDREASON_DONT_HAVE_RACE       = 6,
//	INVALIDREASON_HAVE_TIMED_QUEST     = 12,
//	INVALIDREASON_HAVE_QUEST           = 13,
//	INVALIDREASON_DONT_HAVE_REQ_ITEMS  = 19+1,
//	INVALIDREASON_DONT_HAVE_REQ_MONEY  = 21+1,              //1.12.1
//};

//enum
//{
//	QUEST_PARTY_MSG_SHARRING_QUEST  = 0,
//	QUEST_PARTY_MSG_CANT_TAKE_QUEST = 1,
//	QUEST_PARTY_MSG_ACCEPT_QUEST    = 2,
//	QUEST_PARTY_MSG_REFUSE_QUEST    = 3,
//	QUEST_PARTY_MSG_TO_FAR          = 4,
//	QUEST_PARTY_MSG_BUSY            = 5,
//	QUEST_PARTY_MSG_LOG_FULL        = 6,
//	QUEST_PARTY_MSG_HAVE_QUEST      = 7,
//	QUEST_PARTY_MSG_FINISH_QUEST    = 8,
//};

enum QuestFaction
{
	QUEST_FACTION_NONE = -1,
	QUEST_FACTION_SPARTA,
	QUEST_FACTION_ATHENS,

};
/*
enum QuestClass
{
	QUEST_CLASS_NONE = -1,
	QUEST_CLASS_FIGHTER,
	QUEST_CLASS_SCHOLAR,
	QUEST_CLASS_FIGHTER1,
	QUEST_CLASS_FIGHTER2,
	QUEST_CLASS_SCHOLAR1,
	QUEST_CLASS_SCHOLAR2
};
*/
enum QuestBelief
{
	QUEST_BELIEF_NONE = -1,

};

// enum __QuestRace
// {
// 	QUEST_RACE_NONE            = 0,
// 	QUEST_RACE_HUMAN           = 1,
// 	QUEST_RACE_ORC             = 2,
// 	QUEST_RACE_DWARF           = 3,
// 	QUEST_RACE_NIGHTELF        = 4,
// 	QUEST_RACE_UNDEAD          = 5,
// 	QUEST_RACE_TAUREN          = 6,
// 	QUEST_RACE_GNOME           = 7,
// 	QUEST_RACE_TROLL           = 8,
// };

//enum __QuestTradeSkill
//{
//	QUEST_TRSKILL_NONE           = 0,
//	QUEST_TRSKILL_ALCHEMY        = 1,
//	QUEST_TRSKILL_BLACKSMITHING  = 2,
//	QUEST_TRSKILL_COOKING        = 3,
//	QUEST_TRSKILL_ENCHANTING     = 4,
//	QUEST_TRSKILL_ENGINEERING    = 5,
//	QUEST_TRSKILL_FIRSTAID       = 6,
//	QUEST_TRSKILL_HERBALISM      = 7,
//	QUEST_TRSKILL_LEATHERWORKING = 8,
//	QUEST_TRSKILL_POISONS        = 9,
//	QUEST_TRSKILL_TAILORING      = 10,
//	QUEST_TRSKILL_MINING         = 11,
//	QUEST_TRSKILL_FISHING        = 12,
//	QUEST_TRSKILL_SKINNING       = 13,
//	QUEST_TRSKILL_JEWELCRAFTING  = 14,
//};

enum QuestSort
{
	QUEST_SORT_STORY = 0,
	QUEST_SORT_STORIES,
	QUEST_SORT_REWARD,
	QUEST_SORT_CLASS,
	QUEST_SORT_FACTION,
	QUEST_SORT_DAYS,
	QUEST_SORT_LOOP,		//链式（循环）任务
	QUEST_SORT_RANDOM,		//随机（道具）任务
	QUEST_SORT_CONSORTIA,	//公会任务

	QUEST_SORT_COUNT
};

enum QuestStatus
{
	QUEST_STATUS_NONE = 0,
	QUEST_STATUS_AVAILABLE,
	QUEST_STATUS_UNAVAILABLE,
	QUEST_STATUS_COMPLETE,
	QUEST_STATUS_INCOMPLETE,
	QUEST_STATUS_FAILD,
	QUEST_STATUS_OVER,


	MAX_QUEST_STATUS
};

enum QuestTimeStatus
{
	QUEST_TIMESTATUS_NONE = 0,
	QUEST_TIMESTATUS_DAY = 86400,
	QUEST_TIMESTATUS_WEEK = 604800,

	MAX_QUESTTIME_STATUS
};

enum QuestGiverStatus
{
	DIALOG_STATUS_NONE = 0,
	DIALOG_STATUS_UNAVAILABLE,
	DIALOG_STATUS_CHAT,
	DIALOG_STATUS_INCOMPLETE,
	DIALOG_STATUS_REWARD_REP,
	DIALOG_STATUS_AVAILABLE,
	DIALOG_STATUS_REWARD_OLD,
	DIALOG_STATUS_REWARD,
};

enum QuestSpecialFlags
{
	QUEST_SPECIAL_FLAGS_NONE			= 0,
	QUEST_SPECIAL_FLAGS_DELIVER			= 1,
	QUEST_SPECIAL_FLAGS_MAP_EXPOLORER	= 2,
	QUEST_SPECIAL_FLAGS_SPEAKTO			= 4,

	QUEST_SPECIAL_FLAGS_KILL_OR_CAST	= 8,
	QUEST_SPECIAL_FLAGS_TIMED			= 16,
	QUEST_SPECIAL_FLAGS_REPEATABLE		= 32,

	QUEST_SPECIAL_FLAGS_REPUTATION		= 64,

	QUEST_SPECIAL_FLAGS_LOOP			= 128,//循环
};

struct ExplorerInfo
{
	int MapID;
	int PosX;
	int PosY;
	int PosZ;
	int Radius;
};

//enum TeamQuestLimits
//{
//	TQL_NONE	= -1;//无限制
//	TQL_TWOMANS	= 1;//两人用以上任务
//	TQL_FIVEMANS = 2;//五人任务
//	TQL_COUPLES  = 3;//夫妻任务
//}

struct QuestInfo
{
	int NPCID;

	int QuestID;			//ID
	int QuestSort;			//种类
	int MinLevel;			//等级下限
	int MaxLevel;			//等级上限

	int RequiredLevel;		//等级
	std::vector<int> RequiredClass;		//职业
	int RequiredBelief;		//信仰
	int RequiredFaction;	//阵营

	int TeamLimit;			//队伍限制

	int TimeStatus;			//计时任务

	time_t TimeUpdata;		//更新时间
	time_t MinTime;			//最小时间段
	time_t MaxTime;			//最大时间段

	int	MaxNum;				//最大完成数
	int Repeat;				//重复次数

	int SpecialFlags;		//标志位
	//int Color;			//颜色

	std::vector<ExplorerInfo*> ExplorerInfos;//探索信息

	int Kill;				//杀怪数量
	int QuestCount;			//完成任务数量

	int PrevQuestId;		//前置任务
	int NextQuestId;		//后续任务
	std::vector<int> NextQuestsID;	//后续任务

	int Money;				//钱
	int Bijou;				//宝石
	int	RewardMoney;		//报酬钱
	int RewardBijou;		//报酬宝石

	int UionBijou;		//公会奖励金
	int UionMoney;		//公会奖励银
	int ReqConsortiaLV;    //公会任务级别限制

	bool TimeOver;			//时间超时

	short Item[QUEST_OBJECTIVES_COUNT];
	short Creature[QUEST_OBJECTIVES_COUNT];

	short ItemCount[QUEST_OBJECTIVES_COUNT];
	short CreatureCount[QUEST_OBJECTIVES_COUNT];

	short ItemProbability[QUEST_OBJECTIVES_COUNT];

	ItemData RewardItem[QUEST_REWARDS_COUNT];

//  std::string Title;
//  std::string Details;
//  std::string Objectives;
//	std::string Append;
// 	std::string CompletionText;
// 	std::string IncompleteText;
// 	std::string EndText;

	void Clear()
	{
		NPCID = -1;

		TimeOver = false;

		TimeStatus = 0;

		QuestID = -1; QuestSort = 0;
		MinLevel = 0; MaxLevel = 0;
		RequiredBelief = -1; RequiredFaction = -1; RequiredLevel = -1;

		RequiredClass.clear();

		MaxNum = 0;
		SpecialFlags = 0;
		PrevQuestId = 0; NextQuestId = 0;
		Money = 0; Bijou = 0; RewardMoney = 0; RewardBijou = 0;

		Repeat = 0;
		//Color = 0;

		TimeUpdata = 0; MinTime = 0; MaxTime = 0;

		memset(Item , 0 , QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(Creature , 0 , QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(ItemCount , 0 , QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(CreatureCount , 0 , QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(ItemProbability , 0 , QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(RewardItem , 0 , QUEST_REWARDS_COUNT * sizeof(ItemData));
	}

	QuestInfo()
	:	NPCID(-1) ,
		QuestID(-1) , QuestSort(0) , 
		MinLevel(0) , MaxLevel(0) ,
		//RequiredClass(-1) ,
		RequiredBelief(-1) , RequiredFaction(-1) , RequiredLevel(-1) ,
		TimeStatus(0) ,
		TimeUpdata(0) , MinTime(0) , MaxTime(0) ,
		MaxNum(0) , 
		SpecialFlags(0) , 
		PrevQuestId(0) , NextQuestId(0) , 
		Money(0) , Bijou(0) , RewardMoney(0) , RewardBijou(0) , 
		Repeat(0) ,
		TimeOver(false) ,
		TeamLimit(-1),
		UionBijou(0),
		UionMoney(0),
		ReqConsortiaLV(0)

	{
		for (int i = 0 ; i < QUEST_OBJECTIVES_COUNT ; i++)
		{
			ItemCount[i] = 0;
			CreatureCount[i] = 0;

			memset(ItemCount , 0 , QUEST_OBJECTIVES_COUNT * sizeof(short));
			memset(CreatureCount , 0 , QUEST_OBJECTIVES_COUNT * sizeof(short));
		}
	}

	bool HasSpecialFlag( int flag ) const { return (SpecialFlags & flag ) != 0; }
};

struct QuestReward
{
	//这里面所有东西都是看不到的，玩家不可见。

	QuestReward()
	:	NPCID(-1) ,
		QuestID(-1) ,
		Credit(0) , Contribute(0) , EXP(0) , SkillPoint(0) ,
		SpecialFlags(0) , SpecialCount(0),
		UionContribute(0)
	{
	}

	void Clear()
	{
		NPCID = -1;
		QuestID = -1;

		Credit = 0; Contribute = 0; 
		EXP = 0; SkillPoint = 0;
		SpecialFlags = 0; SpecialCount = 0;		
	}

	int NPCID;

	int QuestID;

	int Credit;			//？？荣誉？
	int Contribute;		//贡献
	int EXP;			//经验
	int SkillPoint;		//技能点

	int SpecialFlags;	//特殊奖励标识
	int SpecialCount;	//特殊奖励数量

	int UionContribute;	//公会奖励贡献
};


struct SQuestStatus
{
	SQuestStatus()
	:	Quest(NULL) , Reward(NULL) ,
		Status(QUEST_STATUS_NONE) ,
		Completed(0) , TimeUpdata(0) , TimeLimit(0)
	{
		memset(ItemCount,    0, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(CreatureCount, 0, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(ExplorerComp,    0, QUEST_EXPLORER_COUNT * sizeof(bool));
		
		m_Timer.Startup(1);
	}

	//探索任务完成情况检查
	bool IsFinishedExplorer()
	{
		std::vector<ExplorerInfo*>::iterator it = Quest->ExplorerInfos.begin();
		bool bFinished = true;

		for ( int index=0; it != Quest->ExplorerInfos.end(); it++, index++)
		{
			//ExplorerInfo* info = (ExplorerInfo*)(*it);
			if ( !ExplorerComp[index])
			{
				bFinished = false;
				break;
			}
		}

		return bFinished;
	}

	//验证探索任务
	int Explorer(int mapid, float posx, float posz)
	{
		if(!Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_MAP_EXPOLORER))
			return false;

		std::vector<ExplorerInfo*>::iterator it = Quest->ExplorerInfos.begin();
		
		for (int index = 0; it != Quest->ExplorerInfos.end(); it++, index++)
		{
			ExplorerInfo* info = (ExplorerInfo*)(*it);
			if ( !ExplorerComp[index] && mapid == info->MapID )
			{
				static int RADIUS = 10;
				int length = (info->PosX -posx ) * (info->PosX -posx ) + (info->PosZ - posz ) * (info->PosZ - posz );
				if( length < RADIUS * RADIUS)
				{
					ExplorerComp[index] = true;
					//if( !IsFinishedExplorer() )
					//	return true;
					return index;
				}
			}
		}
		return -1;
	}

	bool Kill(int id)
	{
		if (id == -1 && Status != QUEST_STATUS_INCOMPLETE)
			return false;

		if (!Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL_OR_CAST))
			return false;

		for (int i = 0 ; i < QUEST_OBJECTIVES_COUNT ; i++)
		{
			if (Quest->Creature[i] == id)
			{
				if (CreatureCount[i] >= Quest->CreatureCount[i])
					return false;
				else
				{
					CreatureCount[i]++;
					return true;
				}
			}
		}

		return false;
	}

	bool Cast(int id)
	{
		if (id == -1 && Status != QUEST_STATUS_INCOMPLETE)
			return false;

		if (!Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL_OR_CAST))
			return false;

		for (int i = 0 ; i < QUEST_OBJECTIVES_COUNT ; i++)
		{
			if (Quest->Item[i] == id)
			{
				//这里加一个掉落几率
				if (sbase::RandGet(100) < Quest->ItemProbability[i])
				{
					if (ItemCount[i] >= Quest->ItemCount[i])
						return false;
					else
					{
						ItemCount[i]++;
						return true;
					}
				}
				else
					return false;
			}
		}

		return false;
	}

	void Clear()
	{
		TimeLimit = 0;

		memset(ItemCount,    0, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(CreatureCount, 0, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(ExplorerComp,    0, QUEST_EXPLORER_COUNT * sizeof(bool));
	}

	bool UpdataTime()
	{
		TimeUpdata = (int)Quest->TimeUpdata + Quest->TimeStatus;

		// 如果已经完成，其他情况不变
		if (Status == QUEST_STATUS_OVER)
			Status = QUEST_STATUS_AVAILABLE;

		if (Completed)
		{
			Completed = 0;
			return true;
		}

		return false;
	}

	void Release()
	{
		Quest = NULL;
		Reward = NULL;

		Status = QUEST_STATUS_NONE;

		Completed = 0;
		TimeLimit = 0;

		memset(ItemCount,    0, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(CreatureCount, 0, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(ExplorerComp,    0, QUEST_EXPLORER_COUNT * sizeof(bool));
	}

	bool Cancel()
	{
		if (!Quest)
			return false;

		memset(ItemCount,    0, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(CreatureCount, 0, QUEST_OBJECTIVES_COUNT * sizeof(short));
		memset(ExplorerComp,    0, QUEST_EXPLORER_COUNT * sizeof(bool));

		if (Quest->TimeOver)
		{
			Status = QUEST_STATUS_UNAVAILABLE;
			return false;
		}

		Status = QUEST_STATUS_AVAILABLE;

		return true;
	}

	bool Accept()
	{
		if (Status != QUEST_STATUS_AVAILABLE)
			return false;

		Status = QUEST_STATUS_INCOMPLETE;

		return true;
	}

	bool CanAccept()
	{
		return Status == QUEST_STATUS_AVAILABLE;
	}

	bool Complete()
	{
		Clear();

		Completed++;

		if (Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_REPEATABLE))
		{
			if (Quest->Repeat > 0 && Completed >= Quest->Repeat)
				Status = QUEST_STATUS_OVER;
			else if ( Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_LOOP))//循环任务特殊处理
			{
				Status = QUEST_STATUS_UNAVAILABLE;
			}
			else
				Status = QUEST_STATUS_AVAILABLE;
		}
		else if ( Quest->QuestSort == QUEST_SORT_RANDOM )//道具任务特殊处理
		{
			Status = QUEST_STATUS_AVAILABLE;
		}
		else
		{
			Status = QUEST_STATUS_OVER;
		}

		return true;
	}

	int UpData(int level)
	{
		if (!m_Timer.IsExpire())
			return QUEST_STATUS_NONE;

		m_Timer.Update();

		if (!Quest)
			return QUEST_STATUS_NONE;

		//如果完成，失败
		if (Status == QUEST_STATUS_COMPLETE || Status == QUEST_STATUS_FAILD)
			return QUEST_STATUS_NONE;

		if (Quest->RequiredLevel > level)
			return QUEST_STATUS_NONE;

		if (Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_SPEAKTO))
		{
			Status = QUEST_STATUS_COMPLETE;

			return QUEST_STATUS_COMPLETE;
		}

// 		if (Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
// 		{
// 			//判断计时
// 			if (Quest->TimeOver)
// 			{
// 				Status = QUEST_STATUS_FAILD;
// 
// 				return QUEST_STATUS_FAILD;
// 			}
// 		}

		if (Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_KILL_OR_CAST))
		{
			for (int i = 0 ; i < QUEST_OBJECTIVES_COUNT ; i++)
			{
				if (ItemCount[i] < Quest->ItemCount[i])
					return QUEST_STATUS_NONE;
				if (CreatureCount[i] < Quest->CreatureCount[i])
					return QUEST_STATUS_NONE;

				Status = QUEST_STATUS_COMPLETE;

				return QUEST_STATUS_COMPLETE;
			}
		}

		if (Quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_MAP_EXPOLORER))//探索任务更新
		{
			if( IsFinishedExplorer() )
			{
				Status = QUEST_STATUS_COMPLETE;

				return QUEST_STATUS_COMPLETE;
			}
		}

		return QUEST_STATUS_NONE;
	}

	//int ExploredCount;
	sbase::CTimer m_Timer;

	QuestInfo *Quest;
	QuestReward* Reward;

	QuestStatus Status;

	time_t	TimeLimit;									//任务时限

	time_t TimeUpdata;									//更新时间

	char Completed;										//完成次数

	short ItemCount[QUEST_OBJECTIVES_COUNT];
	short CreatureCount[QUEST_OBJECTIVES_COUNT];
	bool ExplorerComp[QUEST_EXPLORER_COUNT];
};

#endif






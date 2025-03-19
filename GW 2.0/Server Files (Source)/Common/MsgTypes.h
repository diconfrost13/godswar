//========================================================
//
//    Copyright (c) 2006,欢乐连线工作室
//    All rights reserved.
//
//    文件名称 ： MsgType.h
//    摘    要 ： 消息号定义
//    
//    当前版本 ： 1.01
//    作    者 ： 李锋军
//    完成日期 ： 2007-01-12
//
//========================================================

#pragma once

#define  VALIDATECODE_LENTH        25                    //校验码长度
#define  GAMESERVERNAME_LENGTH     32               
#define  ACCOUNTS_LENGTH           32               
#define  PASSWORD_LENGTH           32
#define  ROLENAME_LENGTH           32


enum
{
	_OBJECT_TYPE_PLAYER				 = 0x10,
	_OBJECT_TYPE_NPC				 ,
	_OBJECT_TYPE_MONSTER			 ,
	_OBJECT_TYPE_BOSS				 ,
};

enum
{
	// 网络连接功能消息
	_MSG_INVALID		        	 =  0,

    //client<->login server
	_MSG_LOGIN                       =  1,
	_MSG_LOGIN_RETURN_INFO           ,                   //登陆服务器返回
	_MSG_REQUEST_GAMESERVER          ,                   //请求游戏服务器

	//loginserver<--->gamereserser
	_MSG_VALIDATE_GAMESERVER         = 300,              //游戏服务器验证码

	//client<->game server
	_MSG_LOGIN_GAMESERVER            =  10000,           //登录游戏服务器
	_MSG_RESPONSE_GAMESERVER         ,                   //返回选择游戏服务器IP
	_MSG_ROLE_INFO                   ,                   //角色信息
	_MSG_CREATE_ROLE                 ,                   //创建角色
	_MSG_DELETE_ROLE                 ,                   //删除角色
	_MSG_GAMESERVER_READY            ,                   //游戏服务器就绪
	_MSG_ENTER_GAME                  ,					 //客户端就绪,准备进入游戏
	_MSG_CLIENT_READY                ,                   //客户端初始化完毕
	_MSG_GAMESERVER_INFO			 ,

	// 信息功能消息
	_MSG_SELFINFO                    ,				     //自己的信息
	_MSG_OBJECTINFO                  ,
	_MSG_LEAVE						 ,
	_MSG_COLONY_LEAVE                ,                   //群体消亡

	// 游戏功能消息
	_MSG_WALK_BEGIN                  , 
	_MSG_WALK_END                    ,
	_MSG_SCENE_CHANGE                ,

	// 战斗功能消息
	_MSG_FIGHT						 ,
	_MSG_ATTACK						 ,
	_MSG_DEAD						 ,
	_MSG_BACKHOME					 ,
	_MSG_DROPS						 ,
	_MSG_UPGRADE					 ,

	// 装备道具功能消息
	_MSG_KITBAG                      ,
	_MSG_STORAGE                     ,

	// 交互功能消息
	_MSG_TALK                        ,
	_MSG_TALKCHANNEL				 ,
	//_MSG_TRADE					 ,

	// 服务端参数，系数
	_MSG_PARAMATER                   ,
	// 技能功能消息
	_MSG_SKILL                       ,
	_MSG_ACTIVESKILL_INFO            ,
	_MSG_PASSIVESKILL_INFO           ,
	_MSG_SELFPROPERTY                ,
	_MSG_EFFECT                      ,
	_MSG_MAGIC_DAMAGE                ,
	_MSG_MAGIC_PERFORM				 ,
	_MSG_MAGIC_CLUSTER_DAMAGE		 ,


	// 职业功能消息
	_MSG_LEARN						 ,                   //学习技能
	_MSG_SKILL_UPGRADE               ,                   //技能升级

	_MSG_PICKUPDROPS				 ,					 //拾取
	_MSG_USEOREQUIP					 ,					 //使用或装备
	_MSG_MOVEITEM					 ,					 //移动物品
	_MSG_BREAK_ITEM					 ,					 //拆分物品
	_MSG_STORAGEITEM				 ,					 //存储物品
	_MSG_SELL						 ,					 //卖物品

	_MSG_STALL						 ,					 //摆摊
	_MSG_STALLADDITEM				 ,					 //添加物品
	_MSG_STALLDELITEM				 ,					 //刪除物品
	_MSG_STALLITEM					 ,					 //摆摊物品
	_MSG_STALLBUYITEM				 ,					 //买

	_MSG_TALKNPC					 ,					 //NPC对话
	_MSG_NPCDATA					 ,					 //NPC数据
	_MSG_SYS_NPC_DATA				 ,	    		     //系统NPC数据
	_MSG_SYS_FUN_USE                 ,                   //系统功能使用
	_MSG_NPCITEMDATA				 ,					 //NPC贩卖数据
	_MSG_NPCSTORAGEDATA				 ,					 //NPC仓库数据
	_MSG_NPCSELL					 ,					 //NPC贩卖

	//任务
	_MSG_NPCQUEST					 ,					 //任务
	_MSG_NPCNEXTQUEST				 ,					 //后续任务
	_MSG_NPCQUESTS					 ,					 //任务列表
	_MSG_NPCQUESTSAVAILABLE			 ,					 //任务刷新，可接
	_MSG_NPCQUESTSUNAVAILABLE		 ,					 //任务刷新，不可接
	_MSG_NPCQUESTREWARD				 ,					 //任务报酬
	_MSG_NPCQUESTVIEW				 ,					 //查看任务信息
	_MSG_NPCACCEPTQUEST				 ,					 //接受任务
	_MSG_NPCCANCELQUEST				 ,					 //取消任务
	_MSG_NPCCOMPLETEQUEST			 ,					 //完成任务
	_MSG_NPCQUESTFAILD				 ,					 //任务失败
	_MSG_NPCREWARDQUEST				 ,					 //完成任务报酬
	_MSG_NPCQUESTKILLORCAST			 ,					 //同步杀怪收集
	_MSG_PLAYER_ACCEPTQUESTS		 ,					 //同步接受任务
	_MSG_FINDQUEST					 ,					 //查找任务
	_MSG_FINDQUESTRESULT			 ,					 //查找任务结果


	//HP,MP回复
	_MSG_RESUNE                      ,

	//好友
	_MSG_RELATIONALL                 ,
	_MSG_RELATION_REQUEST            ,
	_MSG_RELATION_RESPONSE           ,
	_MSG_RELATION_DELETE             ,
	_MSG_RELATION                    , 

	//交易
	_MSG_TRADE						 ,
	_MSG_TRADE_MONEY				 ,
	_MSG_TRADE_ITEM					 ,
	_MSG_TRADE_ADDITEM				 ,
	_MSG_TRADE_REMOVEITEM			 ,

	_MSG_EQUIPFORGE					,
	_MSG_EQUIPFORGE_EQUIP			,
	_MSG_EQUIPFORGE_MATERIAL		,
	_MSG_EQUIPFORGE_EQUIPCANCEL		,
	_MSG_EQUIPFORGE_MATERIALCANCEL	,
	_MSG_EQUIPFORGE_CANCEL			,

	//宝箱转盘 by lion
	_MSG_GOLD_BOX					,

	_MSG_EXPLORER_QUEST				,					//探索任务验证

	_MSG_GOLD_BOX_RETURN				,

	_MSG_TEAM_INVITE				,		//client -> server  && server -> client邀请加入队伍
	_MSG_TEAM_REQUEST				,
	_MSG_TEAM_INFO					,
	_MSG_TEAM_ADD					,		//client -> server加入队伍
	_MSG_TEAM_DELETE				,		//client -> server开除队员		
	_MSG_TEAM_REPLACELEADER			,		//client -> server更换队长
	_MSG_TEAM_DISSOLVE				,		//client -> server队伍解散
	_MSG_TEAM_LEAVE					,		//client -> server脱离队伍
	_MSG_TEAM_TIP					,		//server -> client队伍提示消息
	_MSG_TEAM_REJECT				,		//client -> server拒绝加入队伍
	_MSG_TEAM_REFLASH				,		//server -> client更新队伍
	_MSG_TEAM_DESTROY				,		//server -> client队伍解散

	_MSG_UPDATE_MP					,

	//公会
	_MSG_CONSORTIA_CREATE           ,        //创建公会
	_MSG_CONSORTIA_CREATE_RESPONSE  ,        //创建后返回值 
	_MSG_CONSORTIA_BASE_INFO        ,        //公会会基本信息
	_MSG_CONSORTIA_MEMBER_LIST      ,        //成员列表
	_MSG_CONSORTIA_INVITE           ,        //邀请加入公会
	_MSG_CONSORTIA_DISMISS          ,        //解散公会
	_MSG_CONSORTIA_RESPONSE         ,        //响应邀请
	_MSG_CONSORTIA_EXIT             ,        //退出公会
	_MSG_CONSORTIA_TEXT             ,        //公会公告
	_MSG_CONSORTIA_DUTY             ,        //任命职务
	_MSG_CONSORTIA_MEMBER_DEL       ,        //移除成员

	//祭坛
	_MSG_ALTAR_INFO					,		 //祭坛消息

	//服务器错误
	_MSG_ERROR						,
	_MSG_MANAGE_RETURN              ,

	//技能点数升级
	_MSG_SKILLPOINT_UPGRADE         ,

	//同步数据
	_MSG_SYN_GAMEDATA               ,

	//状态
	_MSG_STATUS           ,

	//排队
	_MSG_LOGIN_QUEUE,

    //服务器通知
	_MSG_SERVER_NOTE,
	_MSG_SKILLBACKUP,
	_MSG_SKILL_INTERRUPT             ,                   //技能中断

	//GS->AS
	_MSG_KEY_RETURN,                                    //GS校验码返回
	_MSG_BAN_PLAYER,
	_MSG_CONSORTIA_LVUP,	                           //公会升级
	_MSG_ALTAR_CREATE,	                               //创建祭坛
	_MSG_ALTAR_LVUP,		                          //祭坛升级
	_MSG_ALTAR_OBLATION,	                          //祭坛供奉

	_MSG_MALLITEMDATA,				//GameServer <---> client  返回游戏商城物品列表
	_MSG_ASSOCIATIONITEMDATA,       //GameServer <---> client  返回工会商城物品列表
	_MSG_MALLSELL,					//GameServer <---> client  游戏商城贩卖
	_MSG_ASSOCIATIONSELL,			//GameServer <---> client  工会商城贩卖
	_MSG_ASSOCIATIONDISCOUNT,		//GameServer ----> client  服务器发给客户端的商城折扣表(为动态改变折扣)
	//声望
	_MSG_CRETIT_EXCHANGE             ,                   //声望兑换
	_MSG_QUESTEXPLORERRESULT		,					 //
	//增加一个物品
	_MSG_SYS_ADD_ITEM		,					 //增加物品
	_MSG_SYS_DEL_ITEM		,					//减少物品
	_MSG_COUNT,
	_MSG_TARGETINFO,
	_MSG_DELAY_EXIT,								//倒计时退出

	_MSG_WALK,
};    

enum {
	TARGET_SELF				= 1,		// 自己
	TARGET_SAME_FACTION		= 2,		// 同阵营不包括自己
	TARGET_DIFF_FACTION		= 4,		// 不同阵营
	TARGET_MONSTER			= 8,		// 怪物
	TARGET_POS				= 16,		// 地图点
	TARGET_PK_OBJ			= 32,		// 可PK对象
	TARGET_ASHES            = 64        // 尸体
};

// //公会返回类型
// typedef enum{
// 	CONSORTIA_SUCCEED       = 0,              // 邀请对方并接受成功
// 	CONSORTIA_REJECT        = 1,              // 被邀请方拒绝
// 	CONSORTIA_INVITE_NO_CONSORTIA = 2,        // 发出的邀请人没有公会
// 	CONSORTIA_INVITE_NO_ACCESS    = 3,        // 发出的邀请人没有权限
// 	CONSORTIA_INVITE_FULL         = 4,        // 发同的邀请人成员已满
// 	CONSORTIA_INVITED_NO_LOGIN    = 5,        // 被邀请的人不在线
// 	CONSORTIA_INVITED_HAVE_CONSORTIA = 6,     // 被邀请的人已经有公会
// 	CONSORTIA_INVITE_NO_LOGIN        = 7,     // 邀请人已经下线
// }ENUM_CONSORTIA;

#define MAX_CONSORTIA_MEMBER_COUNT 200        //公会最大成员个数

//聊天消息类型
#define					defWHISPER				1
#define					defTEAM					2
#define					defGUILD				4
#define					defCAMP					8
#define					defLOCAL				16	
#define					defMESSAGE				32

#define					defSYSTEM				129
#define					defWORLD				130
#define					defWHISPER_SELF				131
#define					defGM					132
#define					DIALITEMCOUNT				16				//转盘物品数量

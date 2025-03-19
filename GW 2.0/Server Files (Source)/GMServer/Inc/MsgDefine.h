//========================================================
//
//    Copyright (c) 2006,福州天盟工作室
//    All rights reserved.
//
//    文件名称 ： MsgDefine.h
//    摘    要 ： 消息结构定义
//    
//    当前版本 ： 1.01
//    作    者 ： 李锋军
//    完成日期 ： 2007-01-12
//
//========================================================

#pragma once
#include ".\MsgTypes.h"
#pragma warning(disable:4010)

//消息头
struct  MsgHead
{
	USHORT	usSize;
	USHORT	usType;
};

//登陆消息\
( Client  ----> GMServer )
struct  MSG_LOGIN
{
	MsgHead  Head;
	char     Name[ACCOUNTS_LENGTH];
	char     cPassWord[PASSWORD_LENGTH];
	long     fVersion;
};

//登陆返回\
( GMServer  ----> Client )
struct  MSG_LOGIN_RETURN_INFO
{
	MsgHead 	 Head;
	BYTE    	 ucInfo;                //0:ID没有注册;1:登陆成功;2:帐号密码错误 3：已经登陆
	UINT		lpopedom;				//客户端权限
};

//GM信息
struct GmInfo 
{
	char cName[32];
};

//在线GM\
( GMServer  ----> Client )
struct MSG_GM_ONLINE_INFO_COVER
{
	MsgHead  Head;
	UINT nGMNum;
	GmInfo cGM[20];
};

struct MSG_GM_ONLINE_INFO_ONE
{
	MsgHead Head;
	UINT ucType;    //0 ：上线  1 ：下线
	char cName[32];
};

//创建帐号\
(  Client ----> GMServer )
struct  MSG_CREATE_ACCOUNTS //add by lion
{
	MsgHead  Head;
	char     cGMAccounts[ACCOUNTS_LENGTH];
	char     cName[ACCOUNTS_LENGTH];	    //帐号
	char     cPassWord[PASSWORD_LENGTH];	//密码
	UINT	 ucAccountsLv;			        //权限

};

//删除帐号\
(  Client ----> GMServer )
struct  MSG_DELETE_ACCOUNTS
{
	MsgHead  Head;
	char	 cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
	char     Accounts[ACCOUNTS_LENGTH];         //其他人或自己的帐号名
};

//修改密码
//(  Client ----> GameServer )
struct MSG_PASSWORD_CHANGE
{
	MsgHead	 Head;
	char     cName[ACCOUNTS_LENGTH];	        //帐号
	char     cOldPassWord[PASSWORD_LENGTH];		//旧密码
	char     cNewPassWord[PASSWORD_LENGTH];		//新密码
};

//返回操作结果 0 ，1 类型
struct MSG_ZERO_ONE
{
	MsgHead  Head;
	BYTE	 ucInfo;    //格式 0：成功 1：失败
};


//错误返回\
( GameServer  ----> Client )
struct MSG_MANAGE_RETURN //choose by lion
{
	MsgHead		Head;
	USHORT		ucErrorType;	//错误标号
	BYTE		ucDisc;			//错误类
};

//装备信息
struct  Equip 
{
	int Base;
	UINT BaseLV;
	int Append[5];
	UINT AppendLevel;
};

//包裹仓库信息
struct KitBag
{
	int Base;
	int BaseLV;
	int Append[5];
	UINT AppendLV;
	UINT Binding;
	UINT Overlap;
	//long CdKey;
}; 

//角色信息
struct MSG_ROLE_INFO
{
	UINT    	uiUserID;							//角色ID
	char		m_strName[32];						//名称
	char		m_Gender[16];						//性别：女1：男
	UCHAR		m_ucIsGM;							//GM标志
	BYTE		m_lFaction;							//所属阵营0：雅典1：斯巴达
	BYTE		m_lClass;							//职业
	UINT        m_cExp;							    //经验
	BYTE		m_cRank;							//等级

	UINT		m_lHP;								//HP
	UINT		m_lMP;								//MP
	USHORT		m_usBelief;							//信仰
	USHORT		m_lPrestige;						//声望
	BYTE		m_cKnight;							//爵位
	USHORT		m_cUnion;							//公会
	BYTE		m_cUnionBusiness;					//公会职务

	UINT        m_uiUionContribute;                 //公会贡献new
	UINT		m_uiStoreNum;						//仓库个数new
	UINT		m_uiBagNum;							//包裹个数new

	BYTE		m_cHairStyle;						//发型
	USHORT		m_lRegionID;						//当前的场景标记
	FLOAT		m_fX;								//X坐标
	FLOAT		m_fY;								//Y坐标
	UINT		m_lMoney;							//金钱
	UINT		m_lSKillPoint;						//技能点数
	UINT		m_lMAXHP;							//最大HP
	UINT		m_lMAXMP;							//最大MP
	char		m_sLastOnlineTime[TIME_LENGTH];		//注册时间
	char		m_sRegisterTime[TIME_LENGTH];		//最后在线时间
	char		m_sAllOnlineTime[TIME_LENGTH];		//在线总时间
	LONGLONG	m_llForbidSpeak;			        //禁言时间
}; 
//获取帐号信息
//(  Client ----> GMServer )
struct MSG_ACCOUNTS_SEARCH	//add by lion
{
	MsgHead		Head;
	BYTE		m_ucInfo_type;						//信息类型  0： 帐号 1：角色名
	char		m_sPlayer_info[32];					//玩家信息
};


//帐号信息\
( GMServer ----> Client )
struct  MSG_ACCOUNTS_INFO //add by lion
{
	MsgHead  Head;
	char		Accounts[ACCOUNTS_LENGTH];			//帐号名
	char		m_sIP[IP_LENGTH];					//IP
	char		Mac[MAC_LENGTH];					//MAC
	BYTE		m_RoleNum;
	MSG_ROLE_INFO	m_RoleInfo[2];					//角色信息
};


//聊天\
( Client  ----> GMServer || GMServer  ----> Client )  
struct MSG_TALK
{
	MsgHead		Head;
	char		RoleName[ROLENAME_LENGTH];			//角色名
	BYTE		ucType;								//  0:私聊频道; 1:队伍频道; 2:公会频道; 3:阵营频道; 4:区域频道; 5:世界频道;
	INT			ucTextSize;							//聊天内容大小
	BYTE		ucResPlayerNameSize;				//自己名字大小
	BYTE		ucAimPlayerNameSize;				//私聊专用
	WCHAR		wcContent[256];						//聊天内容 max length 512  content = AimName + ResName + Talk
};

//错误信息\
(GMServer  ----> Client)
struct MSG_ERROR
{
	MsgHead		Head;
	char		Error[MAX_NAME];
};

//公告信息
//(  Client ----> GMServer )
struct MSG_PLACARD    /////////////////////////////?????????????????????
{
	MsgHead		Head;
	UINT		m_uiPlacardID;						//公告ID
	char		cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
	BYTE		m_ucPlacardType;					//公告类型   // 0：即时公告 1： 循环公告
	BYTE		m_ucSendType;						//发送模式  0：聊天模式 1：跑马灯模式 2：对话框模式
	char		m_sBeginTime[TIME_LENGTH];			//开始时间
	char		m_sEndTime[TIME_LENGTH];			//结束时间
	UINT		m_uInterval;						//循环间隔
	char		m_sPlacardInfo[PLACARD_LENGTH];		//公告内容
};

struct MSG_PLACARD_RETURN:public MSG_PLACARD
{
	BYTE ucType;			//0: 清空（开始）  1：增加
};

struct MSG_PLACARD_DEL 
{
	MsgHead		Head;
	UINT		m_uiPlacardID;						//公告ID
	char		cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
};

//将玩家复位
//(  Client ----> GMServer )
struct MSG_REPOSIT
{
	MsgHead		Head;
	char		cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
	char		m_cPlayerName[ROLENAME_LENGTH];		//玩家名字
};

//物品发放
//(  Client ----> GMServer )
struct	MSG_SENDOBJECT
{
	MsgHead		Head;
	char		cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
	char		m_sRole_name[ROLENAME_LENGTH];		//角色名字

	int		Base;									//装备类型
	int		Append[5];								//附加属性

	UINT		Binding;							//装备绑定
	UINT		Overlap;							//叠加数量
	UINT	    BaseLV	;							//装备品质等级
	UINT		AppendLv;							//装备附加属性等级
};

//踢玩家下线
//(  Client ----> GMServer )
struct	MSG_KICKROLE
{
	MsgHead		Head;
	char		cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
	char		m_role_name[ROLENAME_LENGTH];		//角色名
};
//禁言玩家
//(  Client ----> GMServer )
struct	MSG_FORBID_SPEAK
{
	MsgHead		Head;
	char		cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
	char		m_role_name[ROLENAME_LENGTH];		//角色名
	UINT		m_uiTimeDefer;						//持续时间 单位：秒
};

//暂时禁止登陆
////////////////////////////////////////////////////////////
struct FORBID_INFO
{
	char		cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
	char		m_sPlayer_info[64];					//玩家信息
	char		reason[256];						//惩罚原因、理由
	char		m_sBeginTime[TIME_LENGTH];			//开始时间
	char		m_sEndTime[TIME_LENGTH];			//结束时间
};
//撤销禁止登陆
struct MSG_FORBID_DEL
{
	MsgHead		Head;
	BYTE		m_ucInfo_type;				//信息类型 0：帐号 1：IP 2：MAC
	char		cGMAccounts[ACCOUNTS_LENGTH];
	char		m_sPlayer_info[64];

};

struct  MSG_HEAD 
{
	MsgHead		Head;
};
struct	MSG_FORBID_LAND :public MSG_HEAD ,public FORBID_INFO
{
	BYTE		m_ucInfo_type;				//信息类型  0 帐号 1 IP 2 MAC
};
/////////////////////////////////////////////////
//获取玩家物品信息
//(  Client ----> GMServer )
struct MSG_OBJECT_INFO
{
	MsgHead		Head;
	char		cName[32];
};


//玩家装备信息
//(GMServer－>Client )
struct MSG_EQUIP_INFO
{
	MsgHead		Head;
	Equip		sEquip[24];			//装备物品 MAX_EQUIP_COUNT
};

//玩家包裹信息
//(GMServer－>Client )
struct MSG_KITBAG_INFO
{
	MsgHead		Head;
	KitBag		SKitBagInfo[24];	//包裹内物品 
};

//玩家仓库信息
//(GMServer－>Client )
struct MSG_STORAGE_INFO
{
	MsgHead		Head;
	int			money;
	KitBag		StorageBigInfo[18];	//仓库内物品 
};

//(  Client ----> GameServer )
struct MSG_LIST_REQUEST
{
	MsgHead Head;
	UINT ucType;    //0:帐号  1:IP列表  2:MAC列表 3： 公告
};

struct MSG_LIST_REQUEST_RETURN
{
	MsgHead Head;
	UINT ucType;				//0 ：清空  1：添加
	UINT list_type;				//0:帐号  1:IP列表  2:MAC列表 
	FORBID_INFO land_msg;	//
};

//(  Client ----> GameServer )
struct MSG_MAINTENANCE//维护
{
	MsgHead		Head;
	UINT		ucType;			//0 ：获取  1： 设置
	char		cGMAccounts[ACCOUNTS_LENGTH];		//操作GM
	char		m_sTime[TIME_LENGTH];			//维护时间
};

//( GMServer  ----> Client )
struct MSG_MAINTENANCE_RETURN//维护返回
{
	MsgHead		Head;
	char		m_sTime[TIME_LENGTH];			//维护时间
};








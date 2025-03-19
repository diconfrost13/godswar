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
#include "..\GameServer\GameCore\GameData.h"
#include "..\GameServer\GameCore\Item.h"
#pragma warning(disable:4010)

//消息头
struct  MsgHead
{
	USHORT	usSize;
	USHORT	usType;
};

//登陆消息\
( Client  ----> LoginServer )
struct  MSG_LOGIN
{
	MsgHead  Head;
	char     Name[MAX_NAME];
	char     cPassWord[MAX_NAME];
	long     fVersion;
};

//登陆返回 \
( LoginServer  ----> Client )
struct  MSG_LOGIN_RETURN_INFO
{
	MsgHead 	 Head;
	BYTE    	 ucInfo;                              //0:ID没有注册;1:登陆成功;2:重复登陆;3:密码错误;4:版本错误
};

//登陆消息\
( Client  ----> LoginServer )
struct  MSG_PIPESERVER_INFO
{
	MsgHead  Head;
	int      ucInfo;									//0:登入失败;1:登陆成功;2:注册
};

//注册游戏服务器\
( GameServer ----> LoginServer ) \
( LoginServer----> Client      )
struct MSG_GAMESERVER_INFO 
{
	MsgHead  Head;
	char     cIP[MAX_NAME];
	UINT     uiPort;
	BYTE     cID;                         //服务器ID
	char     ServerName[MAX_NAME];              //游戏服务器名字
	BYTE     cState;                      //0:启动;1:空闲;2:繁忙;3:已满;4:关闭

};


//玩家请求服务器\
( Client  ----> LoginServer )
struct  MSG_REQUEST_GAMESERVER
{
	MsgHead 	 Head;  
	char         Name[MAX_NAME];                           //玩家帐号
	BYTE         cGameServerID;                      //将要进入的游戏服务器ID
};

//向游戏服务器发送校验\
( LoginServer ----> GameServer )
struct  MSG_VALIDATE_GAMESERVER                      //也可以向gameserver发送登录消息
{
	MsgHead 	 Head; 
	char         Accounts[MAX_NAME];                       //帐号
	char    	 cCheckOutText[VALIDATECODE_LENTH] ; //校验码
};

//登录游戏服务器\
( Client ----> GameServer )
struct   MSG_LOGIN_GAMESERVER
{
	MsgHead 	 Head; 
	char         Accounts[MAX_NAME];                       //帐号
	char    	 cCheckOutText[VALIDATECODE_LENTH] ; //校验码
};

//刷新排队
struct MSG_LOGIN_QUEUE
{
	MsgHead 	 Head; 
	int          iSurplusNum;           //还剩余登陆人数
};

//服务器通知
struct MSG_SERVER_NOTE
{
	MsgHead 	 Head; 
	char         cNote[256];           //服务器通知
};

//玩家请求服务器返回\
( LoginServer ----> Client)
struct MSG_RESPONSE_GAMESERVER 
{
	MsgHead 	 Head; 
	BYTE         cGameServerID;                      //将要进入的游戏服务器ID
	char         cIP[MAX_NAME];                            //将要进入的游戏服务器IP
	UINT         uiPort;                             //将要进入的游戏服务器端口
	BYTE         cLoginError;                        //返回失败类型
	char    	 cCheckOutText[VALIDATECODE_LENTH] ; //校验码
};



//游戏服务机器可以连接
struct  MSG_GAMESERVER_READY 
{
	MsgHead  Head;
	BYTE     cServerID;                  //游戏服务器ID 
	BYTE     cLoginError;                //0:登录成功 1:服务器繁忙
};

//客户端初始化\
( Client  ----> GameServer )
struct MSG_ENTER_GAME
{
	MsgHead  Head;
	char     cName[ROLENAME_LENGTH];                           //进入游戏的角色
	char     cCheckOutText[VALIDATECODE_LENTH];                //校验码
};



//创建角色\
(  Client ----> GameServer )
struct  MSG_CREATE_ROLE 
{
	MsgHead  Head;
	char     Name[ROLENAME_LENGTH];             //角色名
	BYTE     cGender;                           //性别
	BYTE     cCamp;                             //阵营
	BYTE     ucProfession;                      //职业
	BYTE     ucBelief;                          //信仰
	BYTE     ucHairStyle;                       //发型
	BYTE	 ucFaceShap;						//脸型	

};
//删除角色\
(  Client ----> GameServer )
struct  MSG_DELETE_ROLE 
{
	MsgHead  Head;
	char     Accounts[ROLENAME_LENGTH];          //帐号名
	char     Name[ROLENAME_LENGTH];              //角色名

};
//角色信息 \
( GameServer ----> Client )
struct  MSG_ROLE_INFO 
{
	MsgHead  Head;
	BYTE     ucNum;                             //角色个数
	
	char     Name[ROLENAME_LENGTH];             //角色名
	BYTE     cCamp;                             //阵营
	BYTE     ucProfession;                      //职业
	BYTE     ucLV;								//等级
	BYTE     ucGender;                          //性别
	BYTE     ucHairStyle;                       //发型
	BYTE	 ucFaceShap;						//脸型
	INT      iEquip[MAX_EQUIP_COUNT];           //装备

	char     Name1[ROLENAME_LENGTH];            //角色名
	BYTE     cCamp1;                            //阵营
	BYTE     ucProfession1;                     //职业
	BYTE     ucLV1;                             //等级
	BYTE     ucGender1;                         //性别
	BYTE     ucHairStyle1;                      //发型
	BYTE	 ucFaceShap1;						//脸型
	INT      iEquip1[MAX_EQUIP_COUNT];          //装备

	char     Name2[ROLENAME_LENGTH];             //角色名
	BYTE     cCamp2;                             //阵营
	BYTE     ucProfession2;                      //职业
	BYTE     ucLV2;                              //等级
	BYTE     ucGender2;                          //性别
	BYTE     ucHairStyle2;                       //发型
	BYTE	 ucFaceShap2;						 //脸型
	INT      iEquip2[MAX_EQUIP_COUNT];           //装备

	char     Name3[ROLENAME_LENGTH];			 //角色名
	BYTE     cCamp3;                             //阵营
	BYTE     ucProfession3;                      //职业
	BYTE     ucLV3;                              //等级
	BYTE     ucGender3;                          //性别
	BYTE     ucHairStyle3;                       //发型
	BYTE	 ucFaceShap3;						 //脸型
	INT      iEquip3[MAX_EQUIP_COUNT];           //装备


};


//客户端进入Main状态\
( Client  ----> GameServer )
struct MSG_CLIENT_READY
{
	MsgHead  Head;
	USHORT   usUserID;                                         //进入游戏的角色
	char     cCheckOutText[VALIDATECODE_LENTH];                //校验码
};


//错误返回\
( GameServer  ----> Client )
struct MSG_MANAGE_RETURN 
{
	MsgHead  	 Head;
	USHORT        ucErrorType;                //错误标号
	int          ucDisc;                     //错误类

};

struct Equip
{
	int	Base;
	char BaseLV;
	int	Append[MAX_EQUIPAPPEND_COUNT];
	char AppendLV;

};

struct KitBag
{
	int Base;
	char BaseLV;
	int Append[MAX_EQUIPAPPEND_COUNT];
	char AppendLV;
	char Binding;
	char Overlap;
};

//自己的信息\
( GameServer  ----> Client )
struct MSG_SELFINFO
{
	MsgHead 				Head;
	LONG					lDB_id;						 //数据库ID
	char	                cName[MAX_NAME];             //名称
	BYTE                    ucGender;                    //性别
	BYTE                    ucCamp;                      //阵营
	BYTE                    ucBelief;                    //信仰
	BYTE                    ucProfession;                //职业
	BYTE                    ucHairStyle;                 //发型
	BYTE					ucFaceShap;					 //脸型
	USHORT  				usMapID;                     //地图ID
	USHORT                  cEquipPos;                   //装备位置标志
	UINT    				uiUserID;                    //玩家ID
	FLOAT   				X,Y,Z;                       //当前坐标
	UINT                    uiMaxHP;                     //最大HP
	UINT                    uiMaxMP;                     //最大MP
	UINT                    uiCurHP;                     //当前HP
	UINT                    uiCurMP;                     //当前MP
	UINT                    uiExp;                       //经验
	UINT                    uiMaxExp;                    //升下一级所需要的经验
	UINT                    uiSkillPoint;                //技能能点数
	UINT                    uiSkillExp;                  //技能经验
	Equip                   SEquip[MAX_EQUIP_COUNT];     //装备

};

//自己的信息\
( GameServer  ----> Client )
struct MSG_SELFPROPERTY
{
	MsgHead 				Head;
	char					m_strName[32];						//名称
	BYTE                    m_Gender;                           //性别0：女 1：男 
	USHORT					m_lRegionID;						//当前的场景标记
	FLOAT					m_fX, m_fY, m_fZ;					//当前坐标
	FLOAT					m_fSpeed;							//移动速度
	USHORT					m_lStyle;							//外形特征
	BYTE					m_lFaction;							//所属阵营 0：雅典 1：斯巴达
	USHORT					m_lPrestige;						//声望
	BYTE                    m_cKnight;                          //爵位
	USHORT                  m_cUnion;                           //公会
	BYTE                    m_cUnionBusiness;                   //公会职务
	UINT                    m_uiUionContribute;                 //公会贡献
	UINT					m_uiStoreNum;						//仓库个数
	UINT					m_uiBagNum;							//包裹个数
	BYTE					m_lClass;							//职业
	UINT                    m_cExp;								//经验
	BYTE                    m_cRank;							//等级
	long					m_lHP;								//HP
	long					m_lMP;								//MP
	USHORT                  m_usAttackDistance;                 //人物攻击范围
	USHORT                  m_usAttackSpeed;                    //攻击速度
	BYTE                    m_cHairStyle;                       //发型
	BYTE                    m_cPupilColor;                      //瞳色(脸型)
	USHORT                  m_usBelief;                         //信仰
	UINT					m_lMoney;							//金钱
	UINT                    m_lStone;                           //宝石
};


//系统参数	\
( GameServer －> Client )
struct MSG_PARAMATER
{	
	MsgHead Head;
	int     Figher_HP_A;
	float   Figher_HP_B;
	float   Figher_HP_C;
	float	Figher_HP_D;
	int     Figher_MP_A;
	float   Figher_MP_B;
	float   Figher_MP_C;
	int     Figher_Attack_A;
	float	Figher_Attack_B;
	float	Figher_Attack_C;
	float	Figher_Attack_D;
	int	    Figher_Defend_A;
	float	Figher_Defend_B;
	float	Figher_Defend_C;
	float	Figher_Defend_D;
	int		Figher_MagicExempt_A;
	int		Figher_MagicExempt_B;
	float	Figher_MagicExempt_C;
	int	    Figher_MagicResist_A;
	float	Figher_MagicResist_B;

	int     Schloar_HP_A;
	float   Schloar_HP_B;
	float   Schloar_HP_C;
	float	Schloar_HP_D;
	int     Schloar_MP_A;
	float   Schloar_MP_B;
	float   Schloar_MP_C;
	int     Schloar_Attack_A;
	float	Schloar_Attack_B;
	float	Schloar_Attack_C;
	float	Schloar_Attack_D;
	int	    Schloar_Defend_A;
	float	Schloar_Defend_B;
	float	Schloar_Defend_C;
	float	Schloar_Defend_D;
	int		Schloar_MagicExempt_A;
	int		Schloar_MagicExempt_B;
	float	Schloar_MagicExempt_C;
	int	    Schloar_MagicResist_A;
	float	Schloar_MagicResist_B;

	int     Defalult_Hit ;
	int	    Defalult_Dodge;
	int	    Defalult_MagicExempt;
	float	Default_Fastness_Wind;
	float	Default_Fastness_Fire ;
	float	Default_Fastness_Terra;
	float	Default_Fastness_Water;
	float	Default_Resume_HP;
	float   Default_Resume_MP;

	float   Grade_A;
	float   Grade_B;
	float   Grade_C;

	float   Skill_A;
	float   Skill_B;
	float   Skill_C;	
};

//背包的信息\
( GameServer  ----> Client )
struct MSG_KITBAG
{
	MsgHead 				 Head;
	UINT    				 uiUserID;                   //玩家ID
	UINT					 uiBagNum;					 //当前包数
	UINT					 uiUpdataNum;				 //更新可用包间数目
	char                     ctab;                       //第几页
	char                     cStartPos;                  //起始位置
	UINT                     cKitBagFlag;                //各个位置有无道具的标识
	KitBag                   SKitBagInfo[24];            //每次发送24个 
};

//仓库信息\
( GameServer  ----> Client )
struct MSG_STORAGE
{
	MsgHead 				 Head;
	int						 Money;						  //金钱
	UINT    				 uiUserID;                    //玩家ID
	char                     cActiveNum;                  //激活数量
	char                     cLine;                       //第几行
	USHORT                   cKitBagFlag;                 //各个位置有无道具的标识
	KitBag                   SKitBagInfo[12];             //每次发送12个 
};

struct Friend
{
	char    Name[18];          //名字
	bool     IsOnline;         //是否在线
	USHORT   usCamp;           //阵营
	USHORT   usBusiness;       //职业
	USHORT   usCity;           //城市
	USHORT   uc_LV;            //等级

};

//好友\
( GameServer  ----> Client )
struct MSG_RELATIONALL
{
	MsgHead 				 Head;
	UINT    				 uiUserID;                    //玩家ID
	BYTE                     ucType;                      //类型 	
	BYTE                     cNum;                        //数量
	Friend                   sFriend[MAX_FRIENDS_COUNT];                 //最大允许数量30
};


// 其他对象信息(活物)\
( GameServer  ----> Client )
struct MSG_OBJECTINFO
{
	MsgHead  Head;
	long     DB_id;						 //数据库ID
	UINT     uiID;						 //游戏ID
	UINT	 uiType;					 //类型(_OBJECT_TYPE_PLAYER/_OBJECT_TYPE_NPC...)
	USHORT   usMapID;                    //地图ID
	float    X,Y,Z;                      //当前坐标
	float	 fAtan2;					 //面部朝向
	bool	 Stall;						 //摆摊状态
	wchar_t	 StallText[MAX_NAME];		 //摆摊字符
	char	 cName[MAX_NAME];		     //名称
	UINT     uiMaxHP;                    //最大HP
	UINT     uiHP;                       //当前HP
	BYTE     ucGender;                    //性别
	BYTE     ucCamp;                     //阵营
	BYTE     ucBelief;                   //信仰
	BYTE     ucProfession;               //职业
	BYTE     ucHairStyle;                //发型
	BYTE	 ucFaceShap;				 //脸型
	UINT     ucLV;                       //等级
	UINT     iStatusCount;               //目前状态个数
	UINT     iStautsDis[MAX_INC_STATUS+MAX_INC_STATUS];//状态ID
	USHORT   cEquipPos;                  //装备位置标志
	Equip    SEquip[MAX_EQUIP_COUNT];    //装备	
};


//聊天\
( Client  ----> GameServer || GameServer  ----> Client )  

struct MSG_TALK
{
	MsgHead		Head;
	INT			uiUserID;                   //玩家ID
	INT			ucTextSize;                 //聊天内容大小
	BYTE		ucType;                     //  0:私聊频道; 1:队伍频道; 2:公会频道; 3:阵营频道; 4:区域频道; 5:世界频道;
	BYTE		ucResPlayerNameSize;		//自己名字大小
	BYTE		ucAimPlayerNameSize;        //私聊专用
	BYTE		ucChatBubbleSytle;			//聊天气泡的样式 0表示默认
 	WCHAR		wcContent[256];              //聊天内容max length 512
// 
// 	INT			ItemCount;					//装备数量
// 	Item		ItemList[3];				//装备信息
};

struct MSG_TALKCHANNEL 
{
	MsgHead		Head;
	BYTE		ucChannel;
};

//行走\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_WALK
{
	MsgHead   Head;
	UINT      uiID;     
	USHORT    usMapID;                    //地图ID
	float     x,z,fatan;
	long	  lState;
};

//行走开始\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_WALK_BEGIN
{
	MsgHead   Head;
	UINT      uiID;     
	USHORT    usMapID;                    //地图ID

	UINT	  uiTick;
	float     X,Y,Z;
	float     OffsetX, OffsetY, OffsetZ;
};

//行走结束\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_WALK_END
{
	MsgHead   Head;
	UINT      uiID;     
	USHORT    usMapID;                    //地图ID

	UINT	  uiTick;
	float     X,Y,Z;
	float	  fAtan2;				 	  //面部朝向
	USHORT    usSkillFlag;                //默认0（普通用法），1技能用的标志，保证状态不被切换
};



//战斗状态
struct MSG_FIGHT
{
	MsgHead	Head;

	UINT uiID;
	UINT uiTargetID;

	bool Fight;
};

//攻击\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_ATTACK
{
	MsgHead   Head;
	UINT      uiID;     
	float     X,Y,Z;
	UINT	  uiObjectID;
	long	  uiDamage;
	BYTE      ucWeaponType;           //攻击武器类型
	BYTE      ucAttackType;           //攻击类型：暴击1：命中2：miss
};

//死亡\
( GameServer  ----> Client )
struct MSG_DEAD
{
	MsgHead   Head;
	UINT      uiID;			                         //死亡者ID
	INT  	  playerID[MAX_TEAM_NUMBER];			 //队伍最大数
	UINT	  playerMoney[MAX_TEAM_NUMBER];		     //相应的人物金钱
	UINT	  Exp[MAX_TEAM_NUMBER];                  //等级经验
	UINT	  SkillExp[MAX_TEAM_NUMBER];             //技能经验
	UINT	  SkillPoint[MAX_TEAM_NUMBER];           //技能点 
	UINT      KillerID;                              //攻击方ID
	UINT      KillerPre;                             //攻击方获得声望
};

//死亡回城
struct MSG_BACKHOME 
{
	MsgHead Head;
	UINT	uiID;
	int		ReviveType;
};

//HP,MP回复
struct MSG_RESUNE
{
	MsgHead Head;
	ULONG   ulHP;
	ULONG   ulMP;
};

//掉落
struct MSG_DROPS
{
	MsgHead   Head;
	UINT      uiID;

	int	      DropNum;
	char	  Drops[256];
};

//技能\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_SKILL 
{
	MsgHead   Head;
	UINT      uiID; 
	int       cType;                 //魔法,招式ID 
	BYTE      cStep;                 //施法阶段 0:施法,1:执行
	int	      uiObjectID;            //目标ID
	BYTE      ucMP;                  //魔法数值减少
	float	  x;					 //客户端x坐标
	float	  z;					 //客户端z坐标
	float	  x1;					 //目标x坐标
	float	  z1;					 //目标y坐标
};


//魔法,招式\
(  GameServer  ----> Client )
struct MSG_MAGIC_DAMAGE
{
	MsgHead   Head;
	UINT      uiID;                 //玩家ID
	INT	      uiObjectID;           //目标ID
	BYTE	  Attack_Type;			//技能攻击命中类型(暴击,命中,Miss)
	BYTE      Status_Type;          //状态命中类型(命中,Miss)  
	BYTE	  bType;				//0:HP,1:MP
	int		  iPower;               //伤害数值
	int       ucMagicID;            //技能ID
	float	  x1;					//技能目标位置x
	float	  z1;					//技能目标位置z
};

struct MSG_MAGIC_PERFORM
{
	MsgHead		Head;
	UINT		uiID;
	INT		uiObjectID;			// 对象ID,-1时表示
	UINT		ucMagicID;			// 魔法id
	float		x;					// 群体魔法的目标位置
	float		z;					// 群体魔法的目标位置
};

struct MAGIC_DAMAGE {
	UINT		uiObjectID;			// 
	BYTE		Attack_Type;
	BYTE		ucType;				// 0-HP, 1-MP
	int			iPower;				// 效果
};
#pragma pack(push)
#pragma pack(1)
struct MSG_MAGIC_CLUSTER_DAMAGE
{
	MsgHead			Head;
	UINT			uiID;
	int				iCount;
	UINT		    ucMagicID;			// 魔法id
	char            bHitStatus;         // 状态命中
	MAGIC_DAMAGE	magicDamage[100];
};
#pragma pack(pop)

//学习技能\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_LEARN 
{
	MsgHead   Head;
	UINT      uiID;                  
	BYTE      cType;                 //技能类型
	BYTE      cKinds;                //技能或魔/招式(0:技能，1：魔法 ，2：招式 )
	BOOL      bIsSucced;             //学习技能成功
};



struct  MAGIC_INFO 
{ 
	int       cType;                 //技能ID
	USHORT    usSurplusCoolTime; 
};
//主动技能属性\
(  GameServer  ----> Client )
struct MSG_ACTIVESKILL_INFO 
{
	MsgHead    Head;
	UINT       uiID; 
	USHORT     MagicCounts;
	MAGIC_INFO  Magic[150];                //招式魔法的最大数量

};


struct  SKILL_INFO 
{
	int       cType;                  //技能ID
	USHORT    Rank;                   //等级
	USHORT    EquipLV;                //装备提升等级
	UINT      NextGradePoint;         //升级所需点数
};
//被动动技能属性\
(  GameServer  ----> Client )
struct MSG_PASSIVESKILL_INFO 
{
	MsgHead    Head;
	UINT       uiID;  
	USHORT     SkillCounts;
	SKILL_INFO  Skill[20];          //技能最大数量
};

//魔法属性\
(  GameServer  ----> Client )
struct MSG_MAGIC_PARAMETER
{
	MsgHead   	Head;
	UINT      	uiID;
	BYTE      	cType;                 	//技能类型ID
	char      	cName[64];             	//技能名称
	BYTE      	ucRank;                	//技能等级
	BYTE      	ucPractice;            	//技能熟练度
	USHORT       lMaxHP;                	//最大生命值
	USHORT       lMaxMP;                	//最大魔法值 
	USHORT       lDodge;                	//躲避
	USHORT       lHit;                  	//命中
	USHORT      	lMagicExempt;         	//魔法豁免
	float      	lTerra_Protect;       	//防御力(地)
	float      	lWater_Protect;       	//防御力(水)
	float      	lFire_Protect;        	//防御力(火)
	float        lWind_Protect;        	//防御力(风)
	USHORT       lPhysics_Protect;       //防御力(物理)
	float        fTerra_Max;             //最大值(地)
	float        fWater_Max;             //最大值(水)
	float        fFire_Max;              //最大值(火)
	float        fWind_Max;              //最大值(风)
};



//人物升级	  \
(  GameServer  ----> Client )
struct  MSG_UPGRADE 
{
	MsgHead   Head;
	UINT      ID;
	UINT      Rank;
	UINT      MaxEXP;
	UINT      CurEXP;
	UINT      MAXHP;
	UINT      CURHP;
	UINT      MAXMP;
	UINT      CURMP;
};



//特效\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_EFFECT 
{
	MsgHead   Head;
	UINT      uiID; 

	float     fColor1R;
	float     fColor1G;
	float     fColor1B;

	float     fColor2R;
	float     fColor2G;
	float     fColor2B;

	float     fColor3R;
	float     fColor3G;
	float     fColor3B;
};

//技能被打断的ID
struct MSG_SKILL_INTERRUPT
{
	MsgHead   Head;
	UINT      uiID;                      //被打断的ID
};


//离开\
( GameServer  ----> Client )
struct MSG_LEAVE
{
	MsgHead   Head;
	UINT      uiID;						 // ID
};


//群体消亡\
( GameServer  ----> Client )           
struct MSG_COLONY_LEAVE
{
	MsgHead   Head;
	USHORT    usNum;                    //数量     
	UINT      uiID[800];		        // ID
};


//更新场景\
( GameServer  ----> Client )
struct MSG_SCENE_CHANGE 
{
	MsgHead   Head;
	UINT      uiUserID;
	float     X,Y,Z;
	USHORT    usCurMapID;                    //当前地图ID
	USHORT    usNextMapID;                   //将要进入的地图ID
};



//拾取道具\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_PICKUP_DROPS
{
	MsgHead	Head;
	UINT	uiID;
	UINT	uiMonsterID;
	int		PickupIndex;
};


//装备或使用道具\
( Client  ----> GameServer )
struct MSG_USEOREQUIP_ITEM
{
	MsgHead	Head;

	UINT uiID;

	unsigned short Index;
	unsigned short Num;

	int ChangeF;
	int Base;
	int Append[MAX_EQUIPAPPEND_COUNT];

	char AppendLevel;
	char BaseLevel;

	bool False;
};

//移動道具\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_MOVE_ITEM
{
	MsgHead	Head;

	UINT uiID;

	short	Index;
	short	Num;

	short	IndexAim;
	short	NumAim;

	int Base;
	int Append[MAX_EQUIPAPPEND_COUNT];
	char AppendLevel;
	char BaseLevel;
	//short Overlap;
};

//物品拆分
struct MSG_BREAK_ITEM
{
	MsgHead	Head;

	short Flags;//0,锁物品，1，解锁物品，2，拆分物品
	short Index;
	short Num;
	short IndexAim;
	short NumAim;

	short Overlap;
};

//存储道具\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_STORAGE_ITEM
{
	MsgHead Head;

	short	Index;

	short	IndexAim;
	short	NumAim;

	int		Money;

	bool	Storage;
};

//卖道具\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_SELL
{
	MsgHead			Head;

	unsigned short	Index;
	unsigned short	Num;
};

struct MSG_STALL
{
	MsgHead		Head;

	UINT		uiID;	
	bool		State;

	wchar_t		Text[MAX_NAME];
	char		SellerName[MAX_NAME];

};

struct MSG_STALLADDITEM 
{
	MsgHead		Head;

	int			Index;
	int			Pocket;

	int			BagIndex;
	int			BagNum;

	int			Money;
	int			Bijou;

	__int64		StallID;
};

struct MSG_STALLDELITEM 
{
	MsgHead		Head;

	int			Index;
	int			Pocket;
};

struct MSG_STALLITEM 
{
	MsgHead		Head;

	UINT		uiID;
	char		SellerName[MAX_NAME];

	__int64		StallID;

	int			Pocket;
	int			Index;

	int			BaseID;
	int			Append[MAX_EQUIPAPPEND_COUNT];

	int			BaseLevel;
	int			AppLevel;
	int			Overlap;

	int			Money;
	int			Bijou; 
};

struct MSG_STALLBUYITEM
{
	MsgHead		Head;

	UINT		uiSellID;
	UINT		uiBuyID;

	char		SellerName[MAX_NAME];
	char		CustomName[MAX_NAME];

	__int64		StallID;

	int			Pocket;
	int			Index;
};


//NPC对话
struct MSG_TALK_NPC 
{
	MsgHead	Head;

	UINT NPCID;

	int NPCFlag;

	int SysFlag;

	char Talk[MAX_NAME];
};

//NPC数据
struct MSG_NPC_DATA
{
	MsgHead Head;

	UINT	NPCID;
};

//NPC道具数据
struct MSG_NPC_ITEMDATA
{
	MsgHead Head;

	UINT	NPCID;
	char TabIndex;
	char MaxTabIndex;
	char ItemCount;
	NpcItemData Itemdata[32];
};

//商城道具数据
struct MSG_MALL_ITEMDATA 
{
	MsgHead Head;
	char TabIndex;
	char MaxTabIndex;
	char ItemCount;
	MallItemData Itemdata[16];
};
//获取商城道具数据
struct MSG_GETITEMDATA 
{
	MsgHead Head;
	UINT	userID;
};

//NPC仓库
struct MSG_NPC_STORAGEDATA 
{
	MsgHead Head;

	UINT	NPCID;

	int		Storage;
};

//NPC贩卖
struct MSG_NPC_SELL 
{
	MsgHead Head;
	UINT NPCID;
	int Index;
	int Num;
	int Count;
	int Base;
};

//商城贩卖
struct MSG_MALL_SELL 
{
	MsgHead Head;
	int Index;
	int Num;
	int Count;
	int Base;
};
//工会商城折扣
struct MSG_ASSOCIATIONDISCOUNT 
{
	MsgHead Head;
	char    Num;
	DiscountData Data[30];
};
struct NPCQuest 
{
	int		QuestID;
	bool	Available;
};

struct PlayerQuest 
{
	int		QuestID;

	int		NPCID;
	int		RewardNPCID;
	int		QuestSort;

	int		Money;									//任务需要金钱
	int		Bijou;									//任务需要宝石
	int		RewardMoney;							//回报金钱
	int		RewardBijou;							//回报金币

	short	Item[QUEST_OBJECTIVES_COUNT];			//任务需要收集道具ID
	short	Creature[QUEST_OBJECTIVES_COUNT];		//任务需要杀怪ID
	short	ItemCount[QUEST_OBJECTIVES_COUNT];		//任务需要收集道具数量
	short	CreatureCount[QUEST_OBJECTIVES_COUNT];	//任务需要杀怪数量
	bool	ExplorerState[QUEST_EXPLORER_COUNT];	//任务需要杀怪数量
	
	char	SpecialFlags;							//标志位
	char	Status;
	char	Completed;
	short	ItemCompletedCount[QUEST_OBJECTIVES_COUNT];
	short	CreatureCompletedCount[QUEST_OBJECTIVES_COUNT];	

	ItemData RewardItem[QUEST_REWARDS_COUNT];	//回报道具
};

struct MSG_ExplorerQuest //探索任务验证
{
	MsgHead Head;
	int		QuestID;
};

struct MSG_FINDQUEST
{
	MsgHead		Head;
	int			Nothing;
};

struct MSG_FINDQUESTRESULT
{
	MsgHead		Head;

	int			Count;

	short		Quest[QUEST_FIND_COUNT];
};

//NPC任务
struct MSG_NPC_QUEST
{
	MsgHead		Head;

	UINT		NPCID;

	NPCQuest	Quest;
};

//NPC后续任务
struct MSG_NPC_NEXTQUEST
{
	MsgHead	Head;

	UINT	NPCID;
	int		QuestID;
	int		QuestSort;

	int		SpecialFlags;							//标志位

	short	Item[QUEST_OBJECTIVES_COUNT];			//任务需要收集道具ID
	short	Creature[QUEST_OBJECTIVES_COUNT];		//任务需要杀怪ID
	short	ItemCount[QUEST_OBJECTIVES_COUNT];		//任务需要收集道具数量
	short	CreatureCount[QUEST_OBJECTIVES_COUNT];	//任务需要杀怪数量

	int		Money;									//任务需要金钱
	int		Bijou;									//任务需要宝石
	int		RewardMoney;							//回报金钱
	int		RewardBijou;							//回报金币

	ItemData RewardItem[QUEST_REWARDS_COUNT];		//回报道具
};

//NPC任务列表
struct MSG_NPC_QUESTS
{
	MsgHead	Head;

	UINT	NPCID;

	int		Count;

	NPCQuest Quest[QUEST_NPCTAKE_COUNT];
};

//可以接受任务,升级时,或任务刷新时同步
struct MSG_NPC_QUESTSAVAILABLE
{
	MsgHead Head;

	int		Count;
	UINT	NPCID[QUEST_PLAYER_COUNT * 4];
	int		QuestID[QUEST_PLAYER_COUNT * 4];
};

//不可以接受任务,升级时,或任务刷新时同步
struct MSG_NPC_QUESTSUNAVAILABLE
{
	MsgHead Head;

	int		Count;
	UINT	NPCID[QUEST_PLAYER_COUNT * 4];
	int		QuestID[QUEST_PLAYER_COUNT * 4];
};

//NPC任务回报
struct MSG_NPC_QUESTREWARD
{
	MsgHead Head;

	UINT	NPCID;

	int		Count;

	int		QuestID[QUEST_NPCTAKE_COUNT];
};


//查看任务信息
struct MSG_NPC_QUESTVIEW
{
	MsgHead Head;

	UINT	NPCID;
	int		QuestID;
	int		QuestSort;

	int		SpecialFlags;							//标志位

	short	Item[QUEST_OBJECTIVES_COUNT];			//任务需要收集道具ID
	short	Creature[QUEST_OBJECTIVES_COUNT];		//任务需要杀怪ID
	short	ItemCount[QUEST_OBJECTIVES_COUNT];		//任务需要收集道具数量
	short	CreatureCount[QUEST_OBJECTIVES_COUNT];	//任务需要杀怪数量

	int		Money;									//任务需要金钱
	int		Bijou;									//任务需要宝石
	int		RewardMoney;							//回报金钱
	int		RewardBijou;							//回报金币

	ItemData RewardItem[QUEST_REWARDS_COUNT];	//回报道具
};

//同步接受中任务
struct MSG_PLAYER_ACCEPTQUESTS 
{
	MsgHead		Head;

	int			Count;

	PlayerQuest Quests[3];
};

//接受任务
struct MSG_NPC_ACCEPTQUEST 
{
	MsgHead Head;

	int		NPCID;
	int		RewardNPCID;

	int		QuestID;


	int		QuestSort;

	int		SpecialFlags;							//标志位

	short	Item[QUEST_OBJECTIVES_COUNT];			//任务需要收集道具ID
	short	Creature[QUEST_OBJECTIVES_COUNT];		//任务需要杀怪ID
	short	ItemCount[QUEST_OBJECTIVES_COUNT];		//任务需要收集道具数量
	short	CreatureCount[QUEST_OBJECTIVES_COUNT];	//任务需要杀怪数量

	int		Money;									//任务需要金钱
	int		Bijou;									//任务需要宝石
	int		RewardMoney;							//回报金钱
	int		RewardBijou;							//回报金币

	ItemData RewardItem[QUEST_REWARDS_COUNT];	//回报道具
};

//取消任务
struct MSG_NPC_CANCELQUEST 
{
	MsgHead Head;

	int		NPCID;
	int		RewardNPCID;

	int		QuestID;

	bool	Available;
};

//完成任务
struct MSG_NPC_COMPLETEQUEST 
{
	MsgHead	Head;

	int		RewardNPCID;

	int		QuestID;
	int		Choice;
};

//任务失败
struct MSG_NPC_QUESTFAILD
{
	MsgHead	Head;

	int		RewardNPCID;

	int		QuestID;
};

//完成任务报酬
struct MSG_NPC_REWARDQUEST 
{
	MsgHead	Head;

	int		NPCID;
	int		RewardNPCID;

	int		QuestID;
	int		Choice;

	//因为这个没有同步，只存在服务器，所以每次完成时发送一次
	int		Credit;			//荣誉？
	int		Contribute;		//贡献
	int		EXP;			//经验
	int		SkillPoint;		//技能经验

	int		SpecialFlags;	//特殊奖励标识
	int		SpecialCount;	//特殊奖励数量

	ItemData Item;
};

//同步杀怪收集
struct MSG_NPC_QUESTKILLORCAST 
{
	MsgHead Head;

	int		QuestID;
	int		NPCID;

	bool	Kill;
	int		KillOrCastID;
};

//同步探索任务
struct MSG_NPC_QUESTEXPLORERRESULT 
{
	MsgHead Head;

	int		QuestID;
	int		NPCID;
	int		Index;
};

//更新好友/黑名单信息
struct  MSG_RELATION
{
	MsgHead		Head;
	char    	cName[ROLENAME_LENGTH];   //名字
	BYTE    	bUnion;       //阵营
	BYTE        ucCity;       //城市
	BYTE        Business;     //职业
	BYTE        LV;		      //等级
	bool    	IsOnline;     //是否在线   
	BYTE        Style;        //类型
};



//好友请求\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_RELATION_REQUEST
{
	MsgHead		Head;
	char    	cName_Request[ROLENAME_LENGTH];
	char        cName_Response[ROLENAME_LENGTH]; 
	char        cType;
	char        Error;          //针对服务器，角色回应不需要  
};

//好友回应
struct MSG_RELATION_RESPONSE
{
	MsgHead		Head;
	char    	cName_Request[ROLENAME_LENGTH];
	bool        IsAgree;            //是否同意
};

//删除社会关系
struct MSG_RELATION_DELETE
{
	MsgHead		Head;
	char    	cName_Request[ROLENAME_LENGTH];
	BYTE        Style;     //0:好友,1:黑名单,2:工会
};

//交易\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_TRADE
{
	MsgHead		Head;
	UINT		uiID;
	UINT		uiObjectID;
	int			State;
	int			TraderState;
	char		chName[64];
	char		chObjectName[64];
};

//交易金钱\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_TRADE_MONEY
{
	MsgHead		Head;
	UINT		uiID;
	int			Money;
	int			Bijou;
	char		chName[64];
};

//交易道具\
( GameServer  ----> Client )
struct MSG_TRADE_ITEM
{
	MsgHead		Head;
	UINT		uiID;
	int			Index;
	int			BaseID;
	int			Append[MAX_EQUIPAPPEND_COUNT];
	char		AppendLevel;
	char		BaseLevel;
	int			Overlap;
	char		chName[64];
};

//交易道具\
( Client  ----> GameServer )
struct MSG_TRADE_ADDITEM
{
	MsgHead		Head;
	UINT		uiID;
	int			Index;
	int			Bag;
	int			Grid;
	char		chName[64];
};

//移除交易道具\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_TRADE_REMOVEITEM 
{
	MsgHead		Head;
	UINT		uiID;
	int			Index;
	char		chName[64];
};

//装备合成
struct MSG_EQUIPFORGE_EQUIP 
{
	MsgHead		Head;

	int			Index;		//装备武器索引号
	int			Num;		//那个包索引号
	int         Type;        //区分主/付装备
};

struct MSG_EQUIPFORGE_MATERIAL
{
	MsgHead		Head;

	int			Index;		//在那个包号
	int			Num;		//宝石索引号
	int         Type;        //区分宝石类型(宝石,水晶,幸运金币)
}; 

struct MSG_EUQIPFORGE 
{
	MsgHead		Head;
	bool		Success;
	int         Type;		//合成类型:装备打造=0,宝石合成=1,装备合成=2
	int         BaseLv;     //新等级
	int         AppLv;
	int         AppId[5];	//新合成的附加属性

};

struct MSG_EQUIPFORGE_EQUIPCANCEL
{
	MsgHead		Head;
};

struct MSG_EQUIPFORGE_MATERIALCANCEL
{
	MsgHead		Head;
};

struct MSG_EQUIPFORGE_CANCEL
{
	MsgHead		Head;
};

struct MSG_TEAM
{
	MsgHead		Head;
	UINT		uiResPlayer;
	char		chResPlayer[64];
	char		chAimPlayer[64];
};

struct MSG_TEAMINFO 
{
	MsgHead		Head;
	char		chAimName[64];	
	bool		bIsAimInTeam;
	bool		bIsSelfInTeam;
};

struct MSG_TEAM_ADD
{
	MsgHead		Head;
	UINT		uiPlayerID;
	int			uiTeamID[5];
};

//组队刷新消息体
struct MSG_TEAM_REFLASH 
{
	MsgHead		Head;

	long		lTeamLeaderID;//队长的ID，用于转发队伍聊天信息
	UINT		uiTeamLeader_HP;
	UINT		uiTeamLeader_MaxHP;
	UINT		uiTeamLeader_Lv;
	BYTE		ucTeamLeader_Class;
	char		chTeamLeader_Name[64];
	SHORT		usTeamLeader_MapID;                    //地图ID
	float		ufTeamLeader_X;                      //当前X坐标
	float		ufTeamLeader_Y;                      //当前Y坐标
	float		ufTeamLeader_Z;                      //当前Z坐标

	long		lTeammate0_ID;
	UINT		uiTeammate0_HP;
	UINT		uiTeammate0_MaxHP;
	UINT		uiTeammate0_Lv;
	char		chTeammate0_Name[64];
	BYTE		ucTeammate0_Class;
	SHORT		usTeammate0_MapID;                    //地图ID
	float		ufTeammate0_X;                      //当前X坐标
	float		ufTeammate0_Y;                      //当前Y坐标
	float		ufTeammate0_Z;                      //当前Z坐标

	long		lTeammate1_ID;
	UINT		uiTeammate1_HP;
	UINT		uiTeammate1_MaxHP;
	UINT		uiTeammate1_Lv;
	char		chTeammate1_Name[64];
	BYTE		ucTeammate1_Class;
	SHORT		usTeammate1_MapID;                    //地图ID
	float		ufTeammate1_X;                      //当前X坐标
	float		ufTeammate1_Y;                      //当前Y坐标
	float		ufTeammate1_Z;                      //当前Z坐标

	long		lTeammate2_ID;
	UINT		uiTeammate2_HP;
	UINT		uiTeammate2_MaxHP;
	UINT		uiTeammate2_Lv;
	char		chTeammate2_Name[64];
	BYTE		ucTeammate2_Class;
	SHORT		usTeammate2_MapID;                    //地图ID
	float		ufTeammate2_X;                      //当前X坐标
	float		ufTeammate2_Y;                      //当前Y坐标
	float		ufTeammate2_Z;                      //当前Z坐标

	long		lTeammate3_ID;
	UINT		uiTeammate3_HP;
	UINT		uiTeammate3_MaxHP;
	UINT		uiTeammate3_Lv;
	char		chTeammate3_Name[64];
	BYTE		ucTeammate3_Class;
	SHORT		usTeammate3_MapID;                    //地图ID
	float		ufTeammate3_X;                      //当前X坐标
	float		ufTeammate3_Y;                      //当前Y坐标
	float		ufTeammate3_Z;                      //当前Z坐标

	bool		bIsDateUpdate;

};

//组队消失消息体
struct MSG_TEAM_DESTROY 
{
	MsgHead		Head;
};

struct MSG_TIP
{
	MsgHead		Head;
	WCHAR		chName[64];
	WCHAR		tip[128];
};



//公会相关消息体
struct MSG_CONSORTIA_CREATE
{
	MsgHead     Head;
	UINT        uiPlayerID;                              //创建者ID
	Consortia_Info ci;                                   //公会信息
	Consortia_Member cm;                                 //创建者相关信息
	MSG_CONSORTIA_CREATE()
	{
		::ZeroMemory(&ci,sizeof(ci));
	}
};

#pragma pack(push)
#pragma pack(1)
struct MSG_CONSORTIA_CREATE_RESPONSE
{
	MsgHead          Head;
	UINT             uiPlayerID;                              //创建者ID
	Consortia_Info   ci;                                      //公会信息
	Consortia_Member cm;                            
	BYTE             Style;                                   //0成功,1等级不够,2金钱不够,3已经有公会 4未知
};
#pragma  pack(pop)

struct MSG_CONSORTIA_BASE_INFO
{
	MsgHead     Head;
	char		acName[64];                   //公会名称
	BYTE		iLevel;                       //公会等级
	long        lfound;                       //资金
	long        lbijou;                       //宝石
	long		lCredit;                      //公会声望
	char	    acTextInfo[256];              //公会公告
	int			MaxMember;					 //公会人数上限
	UINT		AltarCounts;				 //公会创建祭坛的个数
	Consortia_AltarInfo		Altar[9];					 //创建的祭坛ID号
};

struct  CONSORTIA_MEMBER1
{
	char acMemberName[32];             //成员名字
	char lMapID;                       //所在地图ID,-1为离线,0雅典....
	BYTE acDuty;                       //职务 6会长 5副会长 4理事 3精英 2会员 1见习会员
	BYTE iLevel;			           //等级
	BYTE ucBusiness;                   //职业
	UINT uiContribute;                 //贡献

	template<typename T>
	 CONSORTIA_MEMBER1& operator = ( const T &Element ) 
	{
	   strcpy( acMemberName, Element.strName.c_str() );
	   lMapID = (BYTE)Element.lMapID;
	   iLevel = (BYTE)Element.LV;
	   acDuty = (BYTE)Element.Job;
	   ucBusiness = (BYTE)Element.ucBusiness;
	   uiContribute = (UINT)Element.uiContribute;

	   return *this;
	}

};

struct MSG_CONSORTIA_MEMBER_LIST
{
	MsgHead     Head;
	UINT        uiReceivePlayerID;                       //接受者ID
	UINT        uiCount;                                 //条数
	CONSORTIA_MEMBER1 Member[24];
	bool        IsAll;
};

struct MSG_CONSORTIA_INVITE
{
	MsgHead     Head;
	UINT        uiInvitePlayerID;       //发邀请的ID
	char        ciInvitedName[32];      //被邀请的ID
	char        ciConsortiaName[64];    //工会的名字
};


//解散公会 
struct MSG_CONSORTIA_DISMISS
{
	MsgHead     Head;
	char        cPlayerName[32];             //会长的ID
};

//请求响应 
struct MSG_CONSORTIA_RESPONSE
{
	MsgHead     Head;
	BYTE        Style;                  //返回的类型
	UINT        uiSendPlayerID;         //发送者ID
	char        ciReceiveName[32];      //对方名字
};

//退出公会 
struct  MSG_CONSORTIA_EXIT 
{
	MsgHead     Head;
	char        StrName[32];             //退出玩家的名字
	char        NewDutyName[32];         //新任玩家的名字
	char        Duty;                    //新任职务
};

struct MSG_CONSORTIA_TEXT
{
	MsgHead     Head;
    UINT        uiPlayerID;               //会长/理事的ID
	char        NewPlacard[128];         //公会公告
};

struct MSG_CONSORTIA_DUTY
{
   MsgHead     Head;
   char        OldName[32];                 //旧任玩家的名字
   char        OldDuty;                     //旧职务
   char        NewName[32];                 //新任玩家的名字
   char        NewDuty;                     //新任职务
   
};

struct MSG_CONSORTIA_MEMBER_DEL
{
	MsgHead     Head;
    UINT        uiPlayerID;
	char        strName[32];
};

// 祭坛
struct MSG_ALTAR_INFO 
{
	MsgHead     Head;
	int			iAltarCounts;
	Consortia_AltarInfo  Altar[20];
};
//===============END=================//

struct MSG_SKILL_BACKUP 
{
	MsgHead     Head;
	
	int			ID[SKILLBACKUPCOUNT];
	int			Item[SKILLBACKUPCOUNT];

	int			RID;
	int			RItem;
};

//技能点数升级\
( GameServer  ----> Client )
struct MSG_SKILLPOINT_UPGRADE
{
    MsgHead     Head;
	UINT        uiPlayerID;
	UINT        SKillPoint;
};

//升级被动技能等级
struct MSG_SKILL_UPGRADE
{
	MsgHead     Head;
	UINT        uiPlayerID;
	UINT        uiSkillID;
	UINT        uiCurrentSkillGrade;
	UINT        uiNextSkillGradePoint;
	UINT        uiSurplusPoint;
};

//同步客户端数据\
( GameServer  ----> Client )
struct MSG_SYN_GAMEDATA
{
	MsgHead     Head;
	UINT        iUserID;
	ObjectData  sGameData;
    Data        sBaseData;
	int         iAttackDistance;    
	int         iAttackSpeed;   
};

//状态消失
struct MSG_STATUS
{
	MsgHead     Head;
	UINT        uiID;                //objID
	UINT        uiCount;
	UINT        uiStatusID[MAX_INC_STATUS+MAX_DEC_STATUS];
	USHORT      uiSurplusTime[MAX_INC_STATUS+MAX_DEC_STATUS];
	StatusData  Data;
};

//错误信息\
(GameServer  ----> Client)
struct MSG_ERROR 
{
	MsgHead		Head;
	char		Error[MAX_NAME];
};

struct MSG_UPDATE_MP {
	MsgHead		Head;
	UINT		playerID;
	int			mp;
};

struct MSG_CONSORTIA_LVUP
{
	MsgHead		Head;
    UINT        iUserID;  
};

struct MSG_ALTAR_CREATE
{
	MsgHead		Head;
	UINT        iUserID; 
	BYTE        iAltarID;
};

struct MSG_ALTAR_LVUP
{
	MsgHead		Head;
	UINT        iUserID;
	BYTE        iAltarID;
};

struct MSG_ALTAR_OBLATION
{
	MsgHead		Head;
	UINT        iUserID;
	BYTE        iAltarID;
};

//声望兑换红宝石，绿宝石，金币，经验
struct MSG_CRETIT_EXCHANGE
{
	MsgHead Head;
	UINT					iUserID;				//玩家的id
	USHORT					iPrestige;						//声望
	UINT                    iExp;				//角色经验 
	UINT					iMoney;							//金钱
	int						iMaterialType;		//宝石的类型
	unsigned short			Num;				//宝石的数量
};

//转盘消息 by lion
//( Client ----> GameServer )
struct MSG_GOLD_BOX
{
	MsgHead Head;
	BYTE	Type;			//转盘消息类型 0： 打开转盘 1： 开始旋转  2：默认物品 8：直接打开
	UINT	GoldBoxId;		//宝箱ID
	BYTE	Iter;			//宝箱所在位置
};


//转盘消息返回 by lion
//( GameServer ----> Client)
struct MSG_GOLD_BOX_RETURN
{
	MsgHead		Head;
	BYTE		ucInfo;		//0:宝箱不存在 1:成功 2：物品已满 3：生成1个物品 4：生成2个物品 5： 默认物品
	UINT		DialItem[DIALITEMCOUNT+1];	//宝箱可生成物品ID
};

//增加一个物品 by tavia
//( GameServer ----> Client)
struct MSG_SYS_ADD_ITEM
{
	MsgHead		Head;
	ItemData	itemData;		
};
struct MSG_SYS_DEL_ITEM
{
	MsgHead		Head;
	int		    index;
	int         num;
	ItemData	itemData;
};

struct MSG_TARGETINFO
{
	MsgHead		Head;
	UINT		resPlayerID;
	char		AimName[64];
};

struct MSG_DELAY_EXIT 
{
	MsgHead		Head;
	int			type;
};

//功能NPC获取列表
struct MSG_SYS_NPC_DATA
{
	MsgHead		Head;
	UINT	    NPCID;
	int			NpcType;		//判断是什么功能的NPC
	int         State[8];
};

//系统功能使用
struct MSG_SYS_FUN_USE 
{
	MsgHead		Head;
	UINT	    NPCID;
	int			NpcType;
	USHORT      Data[20];
	bool        NextWin; 
};

//校验码返回\
(GameServer  ----> Client)
struct MSG_KEY_RETURN
{
	MsgHead		Head;
	char         Account[32];
};

struct MSG_PLAYER_BAN
{
	MsgHead		Head;
	char        Str[32];
	char        Reason[32];
	char        GM[32];
	char        Style;
};

struct MSG_MAGIC_APPEND 
{
	MsgHead Head;

	int		Money;
	int		EXP;
	int		SkillPoint;
};

struct MSG_CONSORTIA_LIST
{
	MsgHead     Head;
	UINT        uiReceivePlayerID;                       //接受者ID
	UINT        uiCount;                                 //条数
	Consortia_Member cm[10];                             //公会列表,一次10条
	Consortia_Info   ci;                                 //公会信息
	MSG_CONSORTIA_LIST()
	{
		::ZeroMemory(cm,sizeof(MSG_CONSORTIA_LIST)*10);
	}
};


//========================================================
//
//    Copyright (c) 2006,欢乐连线工作室
//    All rights reserved.
//
//    文件名称 ： Session.h
//    摘    要 ： 链接请求中转
//    
//    当前版本 ： 1.01
//    作    者 ： 李锋军
//    完成日期 ： 2007-05-30
//
//========================================================
#ifndef INC_SESSION_H
#define INC_SESSION_H

#ifdef _WIN32
#pragma once
#endif

//#include "..\..\Lib_Base\Inc\mempool.h"
#include ".\GMLogic.h"

//class CMemoryPool;
namespace login
{
	class CGMLogic;
}

static char*  SQL_SELECT_ACCOUNT_INFO   =  "CALL SP_SELECT_ACCOUNTS_INFO(\'%s\',\'%s\',\'%s\');";

static char * SQL_SELECT_PLAYER_INFO_FROM_ACCOUNT = "CALL GM_SP_SELECT_PLAYER_INFO_FROM_ACCOUNT(\'%s\');";				//根据帐号返回该帐号下的所有角色信息
static char * SQL_SELECT_PLAYER_INFO_FROM_NAME = "CALL GM_SP_SELECT_PLAYER_INFO_FROM_NAME(\'%s\');";					//根据角色名还回角色信息
static char * SQL_UPDATE_REPOSIT = "CALL GM_SP_UPDATE_PLAYER_POSIT(\'%s\')";											//修改玩家的坐标
static char * SQL_INSERT_SEND_OBJECT = "CALL GM_SP_INSERT_SEND_OBJECT(\'%s\',\'%s\')";									//向数据库写入发送的物品
static char * SQL_SELECT_PLAYER_OBJECT = "CALL GM_SP_SELECT_PLAYER_OBJECT(\'%s\');";									//获取玩家的包裹，物品，仓库信息
static char * SQL_INSERT_FORBID_ACCOUNT = " CALL GM_SP_INSERT_FORBID_ACCOUNT(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\');";		//禁止玩家帐号登陆
static char * SQL_INSERT_FORBID_IP = "CALL GM_SP_INSERT_FORBID_IP(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\');";				//禁止玩家IP登陆
static char * SQL_SELECT_FORBID_ACCOUNT_LIST = "CALL GM_SP_SELECT_FORBID_ACCOUNT_LIST();";								//获取禁止玩家帐号列表
static char * SQL_SELECT_FORBID_IP_LIST = "CALL GM_SP_SELECT_FORBID_IP_LIST();";										//获取禁止玩家IP列表
static char * SQL_UPDATE_SPEAKFORBID = "CALL GM_SP_UPDATE_SPEAKFORBID(\'%s\',\'%s\',%d);";								//禁言玩家 写入数据库(包括添加 删除 修改)
static char * SQL_SELECT_FORBID_TIME	= "CALL GM_SP_SELECT_FORBID_TIME(\'%s\',%d);";									//获取禁言时间
static char * SQL_UPDATE_PLACARD = "CALL GM_SP_UPDATE_PLACARD(%d,\'%s\',%d,%d,\'%s\',\'%s\',%d,\'%s\');";				//公告 写入数据库(包括添加 删除 修改)
static char * SQL_SELECT_PLACARD = "CALL GM_SP_SELECT_PLACARD();";														//获取公告列表
static char * SQL_DELECT_PLACARD = "CALL GM_SP_DELETE_PLACARD(%d);";													//删除公告
static char * SQL_DELECT_FORBID = "CALL GM_SP_DELETE_FORBID(\'%s\',%d);";												//删除 禁止登陆列表

class  CSession
{
	enum {	

		CHARACTER_ID,                                          //角色ID
		CHARACTER_ACCOUNTS_ID,                                 //帐号ID
		CHARACTER_NAME,                                        //角色名称
		CHARACTER_GENDER,                                      //角色性别
		CHARACTER_GMFLAG,                                      //GM标志 
		CHARACTER_CAMP,                                        //角色阵营
		CHARACTER_PROFESSION,                                  //角色职业
		CHARACTER_LV,					                       //等级
		CHARACTER_SCHOLAR_LV,                                  //学者职业等级  已停用@@@
		CHARACTER_EXP,					                       //经验
		CHARACTER_SCHOLAR_EXP,                                 //学者经验      已停用@@@
		CHARACTER_HP_CUR,                                      //HP当前
		CHARACTER_MP_CUR,                                      //MP当前
		CHARACTER_STAUS,                                       //状态
		CHARACTER_BELIFE,                                      //信仰
		CHARACTER_PRESTIGE,                                    //声望
		CHARACTER_EARL_RANK,                                   //爵位
		CHARACTER_CONSORTIA,                                   //工会
		CHARACTER_CONSORTIA_JOB,                               //工会职业
		CHARACTER_CONSORTIA_CONTRIBUTE,						   //工会贡献
		CHARACTER_STORE_NUM,								   //仓库个数
		CHARACTER_BAG_NUM,									   //包裹个数
		CHARACTER_HAIRSTYLE,                                   //发型
		CHARACTER_FACESHAP,									   //脸型
		CHARACTER_CURMAP,                                      //当前地图
		CHARACTER_CURPOS_X,                                    //当前X坐标
		CHARACTER_CURPOS_Z,                                    //当前Z坐标
		CHARACTER_MONEY,                                       //金钱
		CHARACTER_STONE,                                       //宝石
		CHARACTER_SKILLPOINT,                                  //技能点
		CHARACTER_SKILLEXP,                                    //技能经验
		CHARACTER_MAXHP,                                       //最大HP
		CHARACTER_MAXMP,                                       //最大MP
		CHARACTER_REGISTER_TIME,                               //角色注册时间
		CHARACTER_LASTLOGIN_TIME,                              //最后登录时间
		CHARACTER_MUTE_TIME,                                   //总在线时间	
		IP,													   //IP
		MAC												       //物理地址
	};

public:
	CSession(void * Socket,login::CGMLogic &Logion);
	~CSession();
	CSession & operator=( const CSession & ) {}

	void                Release(){ delete this; };
	void*               GetSocket(){ return m_Socket; };
	void                OnDB_PlayerInfo_Name_Request(const char *Name);
	void				OnDB_PlayerInfo_Account_Request(const char* Account);
	void				OnDB_Reposit_Write_Request(const char* Name);
	void				OnDB_SendObject_Write_Request(MSG_SENDOBJECT * SendObject);
	void				OnDB_GetObject_Request(const char * name);
	void				OnDB_ForbidAccounts_Request(const char* Accounts,const char* StartTime,const char* EndTime,const char* cGmName,const char * cReason);
	void				OnDB_ForbidIp_Request(const char* cIP,const char* StartTime,const char* EndTime,const char* cGmName,const char * cReason);
	void				OnDB_Del_Forbid_Request(const char* cIpAccounts, UINT Type);
	void				OnDB_ForbidAccountsList_Request();
	void				OnDB_ForbidIpList_Request();
	void				OnDB_ForbidSpead_Request(const char* Name,const char* GM_Name,UINT TimeDefer);
	void				OnDD_GetForbidSpeadTime_Request( const char* Name,UINT Type);
	void				OnDB_Placard_Request( MSG_PLACARD * msg_placard );
	void				OnDB_Del_Placard_Request( UINT id);
	void				OnDB_PlacardList_Request();
public:
	//登录处理
	static	 void		OnDB_Response( dbtool::PSQL_RESULT result );
	static   void       OnDB_PlayerInfo_Name_Response(dbtool::PSQL_RESULT result);
	static   void		OnDB_PlayerInfo_Account_Response(dbtool::PSQL_RESULT result) ;
	static   void		OnDB_Reposit_Write_Respone(dbtool::PSQL_RESULT result);
	static   void		OnDB_SendObject_Write_Respone(dbtool::PSQL_RESULT result);
	static	 void		OnDB_GetObject_Respone( dbtool::PSQL_RESULT result );
	static	 void	    OnDB_GetForbidAccount_Respone( dbtool::PSQL_RESULT result );
	static   void		OnDB_GetForbidIP_Respone( dbtool::PSQL_RESULT result );
	static	 void	    OnDB_ForbidSpead_Respone( dbtool::PSQL_RESULT result );
	static 	 void		OnDD_GetForbidSpeadTime_Respone( dbtool::PSQL_RESULT result);
	static	 void		OnDB_Placard_Respone( dbtool::PSQL_RESULT result );
	static   void		OnDB_PlacardList_Respone( dbtool::PSQL_RESULT result );

private:
	static void	CreateBagFromDB(std::string DBString, CSession* pSession);
	static void	CreateStorageFromDB(std::string DBString, CSession* pSession);
	static void	CreateEquipFromDB(std::string DBString, CSession* pSession);

protected:
private:
	void*               m_Socket;
	login::CGMLogic       &m_Logion;
	//DECLARE_FIXEDSIZE_ALLOCATOR(CSession);
};


#endif
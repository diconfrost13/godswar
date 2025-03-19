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

#define  VALIDATECODE_LENTH		25                    //校验码长度
#define  GAMESERVERNAME_LENGTH	32               
#define  ACCOUNTS_LENGTH		32               
#define  PASSWORD_LENGTH		32
#define  ROLENAME_LENGTH		32
#define  MAC_LENGTH				64
#define  TIME_LENGTH			32
#define  IP_LENGTH				32
#define  PLACARD_LENGTH			512
#define  MAX_NAME				32
#define  MAX_EQUIPAPPEND_COUNT	14


enum
{
		// 网络连接功能消息
	_MSG_INVALID		    =  0,
	_MSG_LOGIN              =  1000,	//登陆服务器
	_MSG_LOGIN_RETURN_INFO	,			//登陆服务器返回
	_MSG_GM_ONLINE_INFO_COVER,			//登陆返回在线GM
	_MSG_GM_ONLINE_INFO_ONE,			//返回GM上下线消息		
	_MSG_CREATE_ACCOUNTS	,			//创建帐号
	_MSG_CREATE_ACCOUNTS_RETURN,		//创建帐号返回
	_MSG_DELETE_ACCOUNTS	,			//删除帐号
	_MSG_DELETE_ACCOUNTS_RETURN,		//删除帐号返回
	_MSG_PASSWORD_CHANGE,				//修改密码
	_MSG_PASSWORD_CHANGE_RETURN,		//修改密码返回
	_MSG_ACCOUNTS_SEARCH	,			//获取帐号信息
	_MSG_ACCOUNTS_INFO		,			//帐号信息返回
	_MSG_ACCOUNTS_INFO_RETURN,			//帐号信息获取情况返回 
	_MSG_PLACARD			,			//公告信息--
	_MSG_PLACARD_RETURN		,			//公告信息返回
	_MSG_PALCARD_DEL		,			//删除公告信息
	_MSG_REPOSIT			,			//玩家复位信息
	_MSG_REPOSIT_RETURN		,			//玩家复位消息返回
	_MSG_SENDOBJECT			,			//物品发放信息
	_MSG_SENDOBJECT_RETURN	,			//物品发送信息返回

	// 信息功能消息
	_MSG_MANAGE_RETURN		,			//错误返回
	_MSG_ERROR				,			//错误信息

	// 交互功能消息
	_MSG_TALK				,			//聊天--
	_MSG_KICKROLE			,			//踢人--
	_MSG_KICKROLE_RETURN	,			//踢人返回--
	_MSG_FORBID_SPEAK		,			//禁言--

	_MSG_FORBID_LAND		,			//禁登陆
	_MSG_FORBID_DEL			,			//撤销禁止登陆
	_MSG_FORBID_LAND_RETURN	,			//禁止登陆返回

	_MSG_OBJECT_INFO		,			//获取物品信息
	_MSG_EQUIP_INFO			,			//装备
	_MSG_KITBAG_INFO		,			//包裹
	_MSG_STORAGE_INFO		,			//仓库
	_MSG_LIST_REQUEST		,			//获取 （禁止 公告） 列表
	_MSG_LIST_REQUEST_RETURN,			//列表返回

	_MSG_MAINTENANCE,					//设置服务器关闭请求
	_MSG_MAINTENANCE_RETURN,			//服务器关闭设置返回

};

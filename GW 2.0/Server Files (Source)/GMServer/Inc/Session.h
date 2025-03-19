//========================================================
//
//    Copyright (c) 2006,�������߹�����
//    All rights reserved.
//
//    �ļ����� �� Session.h
//    ժ    Ҫ �� ����������ת
//    
//    ��ǰ�汾 �� 1.01
//    ��    �� �� ����
//    ������� �� 2007-05-30
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

static char * SQL_SELECT_PLAYER_INFO_FROM_ACCOUNT = "CALL GM_SP_SELECT_PLAYER_INFO_FROM_ACCOUNT(\'%s\');";				//�����ʺŷ��ظ��ʺ��µ����н�ɫ��Ϣ
static char * SQL_SELECT_PLAYER_INFO_FROM_NAME = "CALL GM_SP_SELECT_PLAYER_INFO_FROM_NAME(\'%s\');";					//���ݽ�ɫ�����ؽ�ɫ��Ϣ
static char * SQL_UPDATE_REPOSIT = "CALL GM_SP_UPDATE_PLAYER_POSIT(\'%s\')";											//�޸���ҵ�����
static char * SQL_INSERT_SEND_OBJECT = "CALL GM_SP_INSERT_SEND_OBJECT(\'%s\',\'%s\')";									//�����ݿ�д�뷢�͵���Ʒ
static char * SQL_SELECT_PLAYER_OBJECT = "CALL GM_SP_SELECT_PLAYER_OBJECT(\'%s\');";									//��ȡ��ҵİ�������Ʒ���ֿ���Ϣ
static char * SQL_INSERT_FORBID_ACCOUNT = " CALL GM_SP_INSERT_FORBID_ACCOUNT(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\');";		//��ֹ����ʺŵ�½
static char * SQL_INSERT_FORBID_IP = "CALL GM_SP_INSERT_FORBID_IP(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\');";				//��ֹ���IP��½
static char * SQL_SELECT_FORBID_ACCOUNT_LIST = "CALL GM_SP_SELECT_FORBID_ACCOUNT_LIST();";								//��ȡ��ֹ����ʺ��б�
static char * SQL_SELECT_FORBID_IP_LIST = "CALL GM_SP_SELECT_FORBID_IP_LIST();";										//��ȡ��ֹ���IP�б�
static char * SQL_UPDATE_SPEAKFORBID = "CALL GM_SP_UPDATE_SPEAKFORBID(\'%s\',\'%s\',%d);";								//������� д�����ݿ�(������� ɾ�� �޸�)
static char * SQL_SELECT_FORBID_TIME	= "CALL GM_SP_SELECT_FORBID_TIME(\'%s\',%d);";									//��ȡ����ʱ��
static char * SQL_UPDATE_PLACARD = "CALL GM_SP_UPDATE_PLACARD(%d,\'%s\',%d,%d,\'%s\',\'%s\',%d,\'%s\');";				//���� д�����ݿ�(������� ɾ�� �޸�)
static char * SQL_SELECT_PLACARD = "CALL GM_SP_SELECT_PLACARD();";														//��ȡ�����б�
static char * SQL_DELECT_PLACARD = "CALL GM_SP_DELETE_PLACARD(%d);";													//ɾ������
static char * SQL_DELECT_FORBID = "CALL GM_SP_DELETE_FORBID(\'%s\',%d);";												//ɾ�� ��ֹ��½�б�

class  CSession
{
	enum {	

		CHARACTER_ID,                                          //��ɫID
		CHARACTER_ACCOUNTS_ID,                                 //�ʺ�ID
		CHARACTER_NAME,                                        //��ɫ����
		CHARACTER_GENDER,                                      //��ɫ�Ա�
		CHARACTER_GMFLAG,                                      //GM��־ 
		CHARACTER_CAMP,                                        //��ɫ��Ӫ
		CHARACTER_PROFESSION,                                  //��ɫְҵ
		CHARACTER_LV,					                       //�ȼ�
		CHARACTER_SCHOLAR_LV,                                  //ѧ��ְҵ�ȼ�  ��ͣ��@@@
		CHARACTER_EXP,					                       //����
		CHARACTER_SCHOLAR_EXP,                                 //ѧ�߾���      ��ͣ��@@@
		CHARACTER_HP_CUR,                                      //HP��ǰ
		CHARACTER_MP_CUR,                                      //MP��ǰ
		CHARACTER_STAUS,                                       //״̬
		CHARACTER_BELIFE,                                      //����
		CHARACTER_PRESTIGE,                                    //����
		CHARACTER_EARL_RANK,                                   //��λ
		CHARACTER_CONSORTIA,                                   //����
		CHARACTER_CONSORTIA_JOB,                               //����ְҵ
		CHARACTER_CONSORTIA_CONTRIBUTE,						   //���ṱ��
		CHARACTER_STORE_NUM,								   //�ֿ����
		CHARACTER_BAG_NUM,									   //��������
		CHARACTER_HAIRSTYLE,                                   //����
		CHARACTER_FACESHAP,									   //����
		CHARACTER_CURMAP,                                      //��ǰ��ͼ
		CHARACTER_CURPOS_X,                                    //��ǰX����
		CHARACTER_CURPOS_Z,                                    //��ǰZ����
		CHARACTER_MONEY,                                       //��Ǯ
		CHARACTER_STONE,                                       //��ʯ
		CHARACTER_SKILLPOINT,                                  //���ܵ�
		CHARACTER_SKILLEXP,                                    //���ܾ���
		CHARACTER_MAXHP,                                       //���HP
		CHARACTER_MAXMP,                                       //���MP
		CHARACTER_REGISTER_TIME,                               //��ɫע��ʱ��
		CHARACTER_LASTLOGIN_TIME,                              //����¼ʱ��
		CHARACTER_MUTE_TIME,                                   //������ʱ��	
		IP,													   //IP
		MAC												       //�����ַ
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
	//��¼����
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
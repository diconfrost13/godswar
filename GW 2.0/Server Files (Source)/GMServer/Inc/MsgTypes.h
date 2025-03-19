//========================================================
//
//    Copyright (c) 2006,�������߹�����
//    All rights reserved.
//
//    �ļ����� �� MsgType.h
//    ժ    Ҫ �� ��Ϣ�Ŷ���
//    
//    ��ǰ�汾 �� 1.01
//    ��    �� �� ����
//    ������� �� 2007-01-12
//
//========================================================

#pragma once

#define  VALIDATECODE_LENTH		25                    //У���볤��
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
		// �������ӹ�����Ϣ
	_MSG_INVALID		    =  0,
	_MSG_LOGIN              =  1000,	//��½������
	_MSG_LOGIN_RETURN_INFO	,			//��½����������
	_MSG_GM_ONLINE_INFO_COVER,			//��½��������GM
	_MSG_GM_ONLINE_INFO_ONE,			//����GM��������Ϣ		
	_MSG_CREATE_ACCOUNTS	,			//�����ʺ�
	_MSG_CREATE_ACCOUNTS_RETURN,		//�����ʺŷ���
	_MSG_DELETE_ACCOUNTS	,			//ɾ���ʺ�
	_MSG_DELETE_ACCOUNTS_RETURN,		//ɾ���ʺŷ���
	_MSG_PASSWORD_CHANGE,				//�޸�����
	_MSG_PASSWORD_CHANGE_RETURN,		//�޸����뷵��
	_MSG_ACCOUNTS_SEARCH	,			//��ȡ�ʺ���Ϣ
	_MSG_ACCOUNTS_INFO		,			//�ʺ���Ϣ����
	_MSG_ACCOUNTS_INFO_RETURN,			//�ʺ���Ϣ��ȡ������� 
	_MSG_PLACARD			,			//������Ϣ--
	_MSG_PLACARD_RETURN		,			//������Ϣ����
	_MSG_PALCARD_DEL		,			//ɾ��������Ϣ
	_MSG_REPOSIT			,			//��Ҹ�λ��Ϣ
	_MSG_REPOSIT_RETURN		,			//��Ҹ�λ��Ϣ����
	_MSG_SENDOBJECT			,			//��Ʒ������Ϣ
	_MSG_SENDOBJECT_RETURN	,			//��Ʒ������Ϣ����

	// ��Ϣ������Ϣ
	_MSG_MANAGE_RETURN		,			//���󷵻�
	_MSG_ERROR				,			//������Ϣ

	// ����������Ϣ
	_MSG_TALK				,			//����--
	_MSG_KICKROLE			,			//����--
	_MSG_KICKROLE_RETURN	,			//���˷���--
	_MSG_FORBID_SPEAK		,			//����--

	_MSG_FORBID_LAND		,			//����½
	_MSG_FORBID_DEL			,			//������ֹ��½
	_MSG_FORBID_LAND_RETURN	,			//��ֹ��½����

	_MSG_OBJECT_INFO		,			//��ȡ��Ʒ��Ϣ
	_MSG_EQUIP_INFO			,			//װ��
	_MSG_KITBAG_INFO		,			//����
	_MSG_STORAGE_INFO		,			//�ֿ�
	_MSG_LIST_REQUEST		,			//��ȡ ����ֹ ���棩 �б�
	_MSG_LIST_REQUEST_RETURN,			//�б���

	_MSG_MAINTENANCE,					//���÷������ر�����
	_MSG_MAINTENANCE_RETURN,			//�������ر����÷���

};

//========================================================
//
//    Copyright (c) 2006,�������˹�����
//    All rights reserved.
//
//    �ļ����� �� MsgDefine.h
//    ժ    Ҫ �� ��Ϣ�ṹ����
//    
//    ��ǰ�汾 �� 1.01
//    ��    �� �� ����
//    ������� �� 2007-01-12
//
//========================================================

#pragma once
#include ".\MsgTypes.h"
#pragma warning(disable:4010)

//��Ϣͷ
struct  MsgHead
{
	USHORT	usSize;
	USHORT	usType;
};

//��½��Ϣ\
( Client  ----> GMServer )
struct  MSG_LOGIN
{
	MsgHead  Head;
	char     Name[ACCOUNTS_LENGTH];
	char     cPassWord[PASSWORD_LENGTH];
	long     fVersion;
};

//��½����\
( GMServer  ----> Client )
struct  MSG_LOGIN_RETURN_INFO
{
	MsgHead 	 Head;
	BYTE    	 ucInfo;                //0:IDû��ע��;1:��½�ɹ�;2:�ʺ�������� 3���Ѿ���½
	UINT		lpopedom;				//�ͻ���Ȩ��
};

//GM��Ϣ
struct GmInfo 
{
	char cName[32];
};

//����GM\
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
	UINT ucType;    //0 ������  1 ������
	char cName[32];
};

//�����ʺ�\
(  Client ----> GMServer )
struct  MSG_CREATE_ACCOUNTS //add by lion
{
	MsgHead  Head;
	char     cGMAccounts[ACCOUNTS_LENGTH];
	char     cName[ACCOUNTS_LENGTH];	    //�ʺ�
	char     cPassWord[PASSWORD_LENGTH];	//����
	UINT	 ucAccountsLv;			        //Ȩ��

};

//ɾ���ʺ�\
(  Client ----> GMServer )
struct  MSG_DELETE_ACCOUNTS
{
	MsgHead  Head;
	char	 cGMAccounts[ACCOUNTS_LENGTH];		//����GM
	char     Accounts[ACCOUNTS_LENGTH];         //�����˻��Լ����ʺ���
};

//�޸�����
//(  Client ----> GameServer )
struct MSG_PASSWORD_CHANGE
{
	MsgHead	 Head;
	char     cName[ACCOUNTS_LENGTH];	        //�ʺ�
	char     cOldPassWord[PASSWORD_LENGTH];		//������
	char     cNewPassWord[PASSWORD_LENGTH];		//������
};

//���ز������ 0 ��1 ����
struct MSG_ZERO_ONE
{
	MsgHead  Head;
	BYTE	 ucInfo;    //��ʽ 0���ɹ� 1��ʧ��
};


//���󷵻�\
( GameServer  ----> Client )
struct MSG_MANAGE_RETURN //choose by lion
{
	MsgHead		Head;
	USHORT		ucErrorType;	//������
	BYTE		ucDisc;			//������
};

//װ����Ϣ
struct  Equip 
{
	int Base;
	UINT BaseLV;
	int Append[5];
	UINT AppendLevel;
};

//�����ֿ���Ϣ
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

//��ɫ��Ϣ
struct MSG_ROLE_INFO
{
	UINT    	uiUserID;							//��ɫID
	char		m_strName[32];						//����
	char		m_Gender[16];						//�Ա�Ů1����
	UCHAR		m_ucIsGM;							//GM��־
	BYTE		m_lFaction;							//������Ӫ0���ŵ�1��˹�ʹ�
	BYTE		m_lClass;							//ְҵ
	UINT        m_cExp;							    //����
	BYTE		m_cRank;							//�ȼ�

	UINT		m_lHP;								//HP
	UINT		m_lMP;								//MP
	USHORT		m_usBelief;							//����
	USHORT		m_lPrestige;						//����
	BYTE		m_cKnight;							//��λ
	USHORT		m_cUnion;							//����
	BYTE		m_cUnionBusiness;					//����ְ��

	UINT        m_uiUionContribute;                 //���ṱ��new
	UINT		m_uiStoreNum;						//�ֿ����new
	UINT		m_uiBagNum;							//��������new

	BYTE		m_cHairStyle;						//����
	USHORT		m_lRegionID;						//��ǰ�ĳ������
	FLOAT		m_fX;								//X����
	FLOAT		m_fY;								//Y����
	UINT		m_lMoney;							//��Ǯ
	UINT		m_lSKillPoint;						//���ܵ���
	UINT		m_lMAXHP;							//���HP
	UINT		m_lMAXMP;							//���MP
	char		m_sLastOnlineTime[TIME_LENGTH];		//ע��ʱ��
	char		m_sRegisterTime[TIME_LENGTH];		//�������ʱ��
	char		m_sAllOnlineTime[TIME_LENGTH];		//������ʱ��
	LONGLONG	m_llForbidSpeak;			        //����ʱ��
}; 
//��ȡ�ʺ���Ϣ
//(  Client ----> GMServer )
struct MSG_ACCOUNTS_SEARCH	//add by lion
{
	MsgHead		Head;
	BYTE		m_ucInfo_type;						//��Ϣ����  0�� �ʺ� 1����ɫ��
	char		m_sPlayer_info[32];					//�����Ϣ
};


//�ʺ���Ϣ\
( GMServer ----> Client )
struct  MSG_ACCOUNTS_INFO //add by lion
{
	MsgHead  Head;
	char		Accounts[ACCOUNTS_LENGTH];			//�ʺ���
	char		m_sIP[IP_LENGTH];					//IP
	char		Mac[MAC_LENGTH];					//MAC
	BYTE		m_RoleNum;
	MSG_ROLE_INFO	m_RoleInfo[2];					//��ɫ��Ϣ
};


//����\
( Client  ----> GMServer || GMServer  ----> Client )  
struct MSG_TALK
{
	MsgHead		Head;
	char		RoleName[ROLENAME_LENGTH];			//��ɫ��
	BYTE		ucType;								//  0:˽��Ƶ��; 1:����Ƶ��; 2:����Ƶ��; 3:��ӪƵ��; 4:����Ƶ��; 5:����Ƶ��;
	INT			ucTextSize;							//�������ݴ�С
	BYTE		ucResPlayerNameSize;				//�Լ����ִ�С
	BYTE		ucAimPlayerNameSize;				//˽��ר��
	WCHAR		wcContent[256];						//�������� max length 512  content = AimName + ResName + Talk
};

//������Ϣ\
(GMServer  ----> Client)
struct MSG_ERROR
{
	MsgHead		Head;
	char		Error[MAX_NAME];
};

//������Ϣ
//(  Client ----> GMServer )
struct MSG_PLACARD    /////////////////////////////?????????????????????
{
	MsgHead		Head;
	UINT		m_uiPlacardID;						//����ID
	char		cGMAccounts[ACCOUNTS_LENGTH];		//����GM
	BYTE		m_ucPlacardType;					//��������   // 0����ʱ���� 1�� ѭ������
	BYTE		m_ucSendType;						//����ģʽ  0������ģʽ 1�������ģʽ 2���Ի���ģʽ
	char		m_sBeginTime[TIME_LENGTH];			//��ʼʱ��
	char		m_sEndTime[TIME_LENGTH];			//����ʱ��
	UINT		m_uInterval;						//ѭ�����
	char		m_sPlacardInfo[PLACARD_LENGTH];		//��������
};

struct MSG_PLACARD_RETURN:public MSG_PLACARD
{
	BYTE ucType;			//0: ��գ���ʼ��  1������
};

struct MSG_PLACARD_DEL 
{
	MsgHead		Head;
	UINT		m_uiPlacardID;						//����ID
	char		cGMAccounts[ACCOUNTS_LENGTH];		//����GM
};

//����Ҹ�λ
//(  Client ----> GMServer )
struct MSG_REPOSIT
{
	MsgHead		Head;
	char		cGMAccounts[ACCOUNTS_LENGTH];		//����GM
	char		m_cPlayerName[ROLENAME_LENGTH];		//�������
};

//��Ʒ����
//(  Client ----> GMServer )
struct	MSG_SENDOBJECT
{
	MsgHead		Head;
	char		cGMAccounts[ACCOUNTS_LENGTH];		//����GM
	char		m_sRole_name[ROLENAME_LENGTH];		//��ɫ����

	int		Base;									//װ������
	int		Append[5];								//��������

	UINT		Binding;							//װ����
	UINT		Overlap;							//��������
	UINT	    BaseLV	;							//װ��Ʒ�ʵȼ�
	UINT		AppendLv;							//װ���������Եȼ�
};

//���������
//(  Client ----> GMServer )
struct	MSG_KICKROLE
{
	MsgHead		Head;
	char		cGMAccounts[ACCOUNTS_LENGTH];		//����GM
	char		m_role_name[ROLENAME_LENGTH];		//��ɫ��
};
//�������
//(  Client ----> GMServer )
struct	MSG_FORBID_SPEAK
{
	MsgHead		Head;
	char		cGMAccounts[ACCOUNTS_LENGTH];		//����GM
	char		m_role_name[ROLENAME_LENGTH];		//��ɫ��
	UINT		m_uiTimeDefer;						//����ʱ�� ��λ����
};

//��ʱ��ֹ��½
////////////////////////////////////////////////////////////
struct FORBID_INFO
{
	char		cGMAccounts[ACCOUNTS_LENGTH];		//����GM
	char		m_sPlayer_info[64];					//�����Ϣ
	char		reason[256];						//�ͷ�ԭ������
	char		m_sBeginTime[TIME_LENGTH];			//��ʼʱ��
	char		m_sEndTime[TIME_LENGTH];			//����ʱ��
};
//������ֹ��½
struct MSG_FORBID_DEL
{
	MsgHead		Head;
	BYTE		m_ucInfo_type;				//��Ϣ���� 0���ʺ� 1��IP 2��MAC
	char		cGMAccounts[ACCOUNTS_LENGTH];
	char		m_sPlayer_info[64];

};

struct  MSG_HEAD 
{
	MsgHead		Head;
};
struct	MSG_FORBID_LAND :public MSG_HEAD ,public FORBID_INFO
{
	BYTE		m_ucInfo_type;				//��Ϣ����  0 �ʺ� 1 IP 2 MAC
};
/////////////////////////////////////////////////
//��ȡ�����Ʒ��Ϣ
//(  Client ----> GMServer )
struct MSG_OBJECT_INFO
{
	MsgHead		Head;
	char		cName[32];
};


//���װ����Ϣ
//(GMServer��>Client )
struct MSG_EQUIP_INFO
{
	MsgHead		Head;
	Equip		sEquip[24];			//װ����Ʒ MAX_EQUIP_COUNT
};

//��Ұ�����Ϣ
//(GMServer��>Client )
struct MSG_KITBAG_INFO
{
	MsgHead		Head;
	KitBag		SKitBagInfo[24];	//��������Ʒ 
};

//��Ҳֿ���Ϣ
//(GMServer��>Client )
struct MSG_STORAGE_INFO
{
	MsgHead		Head;
	int			money;
	KitBag		StorageBigInfo[18];	//�ֿ�����Ʒ 
};

//(  Client ----> GameServer )
struct MSG_LIST_REQUEST
{
	MsgHead Head;
	UINT ucType;    //0:�ʺ�  1:IP�б�  2:MAC�б� 3�� ����
};

struct MSG_LIST_REQUEST_RETURN
{
	MsgHead Head;
	UINT ucType;				//0 �����  1�����
	UINT list_type;				//0:�ʺ�  1:IP�б�  2:MAC�б� 
	FORBID_INFO land_msg;	//
};

//(  Client ----> GameServer )
struct MSG_MAINTENANCE//ά��
{
	MsgHead		Head;
	UINT		ucType;			//0 ����ȡ  1�� ����
	char		cGMAccounts[ACCOUNTS_LENGTH];		//����GM
	char		m_sTime[TIME_LENGTH];			//ά��ʱ��
};

//( GMServer  ----> Client )
struct MSG_MAINTENANCE_RETURN//ά������
{
	MsgHead		Head;
	char		m_sTime[TIME_LENGTH];			//ά��ʱ��
};








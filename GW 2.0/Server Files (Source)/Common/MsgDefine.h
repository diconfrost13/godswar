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
#include "..\GameServer\GameCore\GameData.h"
#include "..\GameServer\GameCore\Item.h"
#pragma warning(disable:4010)

//��Ϣͷ
struct  MsgHead
{
	USHORT	usSize;
	USHORT	usType;
};

//��½��Ϣ\
( Client  ----> LoginServer )
struct  MSG_LOGIN
{
	MsgHead  Head;
	char     Name[MAX_NAME];
	char     cPassWord[MAX_NAME];
	long     fVersion;
};

//��½���� \
( LoginServer  ----> Client )
struct  MSG_LOGIN_RETURN_INFO
{
	MsgHead 	 Head;
	BYTE    	 ucInfo;                              //0:IDû��ע��;1:��½�ɹ�;2:�ظ���½;3:�������;4:�汾����
};

//��½��Ϣ\
( Client  ----> LoginServer )
struct  MSG_PIPESERVER_INFO
{
	MsgHead  Head;
	int      ucInfo;									//0:����ʧ��;1:��½�ɹ�;2:ע��
};

//ע����Ϸ������\
( GameServer ----> LoginServer ) \
( LoginServer----> Client      )
struct MSG_GAMESERVER_INFO 
{
	MsgHead  Head;
	char     cIP[MAX_NAME];
	UINT     uiPort;
	BYTE     cID;                         //������ID
	char     ServerName[MAX_NAME];              //��Ϸ����������
	BYTE     cState;                      //0:����;1:����;2:��æ;3:����;4:�ر�

};


//������������\
( Client  ----> LoginServer )
struct  MSG_REQUEST_GAMESERVER
{
	MsgHead 	 Head;  
	char         Name[MAX_NAME];                           //����ʺ�
	BYTE         cGameServerID;                      //��Ҫ�������Ϸ������ID
};

//����Ϸ����������У��\
( LoginServer ----> GameServer )
struct  MSG_VALIDATE_GAMESERVER                      //Ҳ������gameserver���͵�¼��Ϣ
{
	MsgHead 	 Head; 
	char         Accounts[MAX_NAME];                       //�ʺ�
	char    	 cCheckOutText[VALIDATECODE_LENTH] ; //У����
};

//��¼��Ϸ������\
( Client ----> GameServer )
struct   MSG_LOGIN_GAMESERVER
{
	MsgHead 	 Head; 
	char         Accounts[MAX_NAME];                       //�ʺ�
	char    	 cCheckOutText[VALIDATECODE_LENTH] ; //У����
};

//ˢ���Ŷ�
struct MSG_LOGIN_QUEUE
{
	MsgHead 	 Head; 
	int          iSurplusNum;           //��ʣ���½����
};

//������֪ͨ
struct MSG_SERVER_NOTE
{
	MsgHead 	 Head; 
	char         cNote[256];           //������֪ͨ
};

//����������������\
( LoginServer ----> Client)
struct MSG_RESPONSE_GAMESERVER 
{
	MsgHead 	 Head; 
	BYTE         cGameServerID;                      //��Ҫ�������Ϸ������ID
	char         cIP[MAX_NAME];                            //��Ҫ�������Ϸ������IP
	UINT         uiPort;                             //��Ҫ�������Ϸ�������˿�
	BYTE         cLoginError;                        //����ʧ������
	char    	 cCheckOutText[VALIDATECODE_LENTH] ; //У����
};



//��Ϸ���������������
struct  MSG_GAMESERVER_READY 
{
	MsgHead  Head;
	BYTE     cServerID;                  //��Ϸ������ID 
	BYTE     cLoginError;                //0:��¼�ɹ� 1:��������æ
};

//�ͻ��˳�ʼ��\
( Client  ----> GameServer )
struct MSG_ENTER_GAME
{
	MsgHead  Head;
	char     cName[ROLENAME_LENGTH];                           //������Ϸ�Ľ�ɫ
	char     cCheckOutText[VALIDATECODE_LENTH];                //У����
};



//������ɫ\
(  Client ----> GameServer )
struct  MSG_CREATE_ROLE 
{
	MsgHead  Head;
	char     Name[ROLENAME_LENGTH];             //��ɫ��
	BYTE     cGender;                           //�Ա�
	BYTE     cCamp;                             //��Ӫ
	BYTE     ucProfession;                      //ְҵ
	BYTE     ucBelief;                          //����
	BYTE     ucHairStyle;                       //����
	BYTE	 ucFaceShap;						//����	

};
//ɾ����ɫ\
(  Client ----> GameServer )
struct  MSG_DELETE_ROLE 
{
	MsgHead  Head;
	char     Accounts[ROLENAME_LENGTH];          //�ʺ���
	char     Name[ROLENAME_LENGTH];              //��ɫ��

};
//��ɫ��Ϣ \
( GameServer ----> Client )
struct  MSG_ROLE_INFO 
{
	MsgHead  Head;
	BYTE     ucNum;                             //��ɫ����
	
	char     Name[ROLENAME_LENGTH];             //��ɫ��
	BYTE     cCamp;                             //��Ӫ
	BYTE     ucProfession;                      //ְҵ
	BYTE     ucLV;								//�ȼ�
	BYTE     ucGender;                          //�Ա�
	BYTE     ucHairStyle;                       //����
	BYTE	 ucFaceShap;						//����
	INT      iEquip[MAX_EQUIP_COUNT];           //װ��

	char     Name1[ROLENAME_LENGTH];            //��ɫ��
	BYTE     cCamp1;                            //��Ӫ
	BYTE     ucProfession1;                     //ְҵ
	BYTE     ucLV1;                             //�ȼ�
	BYTE     ucGender1;                         //�Ա�
	BYTE     ucHairStyle1;                      //����
	BYTE	 ucFaceShap1;						//����
	INT      iEquip1[MAX_EQUIP_COUNT];          //װ��

	char     Name2[ROLENAME_LENGTH];             //��ɫ��
	BYTE     cCamp2;                             //��Ӫ
	BYTE     ucProfession2;                      //ְҵ
	BYTE     ucLV2;                              //�ȼ�
	BYTE     ucGender2;                          //�Ա�
	BYTE     ucHairStyle2;                       //����
	BYTE	 ucFaceShap2;						 //����
	INT      iEquip2[MAX_EQUIP_COUNT];           //װ��

	char     Name3[ROLENAME_LENGTH];			 //��ɫ��
	BYTE     cCamp3;                             //��Ӫ
	BYTE     ucProfession3;                      //ְҵ
	BYTE     ucLV3;                              //�ȼ�
	BYTE     ucGender3;                          //�Ա�
	BYTE     ucHairStyle3;                       //����
	BYTE	 ucFaceShap3;						 //����
	INT      iEquip3[MAX_EQUIP_COUNT];           //װ��


};


//�ͻ��˽���Main״̬\
( Client  ----> GameServer )
struct MSG_CLIENT_READY
{
	MsgHead  Head;
	USHORT   usUserID;                                         //������Ϸ�Ľ�ɫ
	char     cCheckOutText[VALIDATECODE_LENTH];                //У����
};


//���󷵻�\
( GameServer  ----> Client )
struct MSG_MANAGE_RETURN 
{
	MsgHead  	 Head;
	USHORT        ucErrorType;                //������
	int          ucDisc;                     //������

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

//�Լ�����Ϣ\
( GameServer  ----> Client )
struct MSG_SELFINFO
{
	MsgHead 				Head;
	LONG					lDB_id;						 //���ݿ�ID
	char	                cName[MAX_NAME];             //����
	BYTE                    ucGender;                    //�Ա�
	BYTE                    ucCamp;                      //��Ӫ
	BYTE                    ucBelief;                    //����
	BYTE                    ucProfession;                //ְҵ
	BYTE                    ucHairStyle;                 //����
	BYTE					ucFaceShap;					 //����
	USHORT  				usMapID;                     //��ͼID
	USHORT                  cEquipPos;                   //װ��λ�ñ�־
	UINT    				uiUserID;                    //���ID
	FLOAT   				X,Y,Z;                       //��ǰ����
	UINT                    uiMaxHP;                     //���HP
	UINT                    uiMaxMP;                     //���MP
	UINT                    uiCurHP;                     //��ǰHP
	UINT                    uiCurMP;                     //��ǰMP
	UINT                    uiExp;                       //����
	UINT                    uiMaxExp;                    //����һ������Ҫ�ľ���
	UINT                    uiSkillPoint;                //�����ܵ���
	UINT                    uiSkillExp;                  //���ܾ���
	Equip                   SEquip[MAX_EQUIP_COUNT];     //װ��

};

//�Լ�����Ϣ\
( GameServer  ----> Client )
struct MSG_SELFPROPERTY
{
	MsgHead 				Head;
	char					m_strName[32];						//����
	BYTE                    m_Gender;                           //�Ա�0��Ů 1���� 
	USHORT					m_lRegionID;						//��ǰ�ĳ������
	FLOAT					m_fX, m_fY, m_fZ;					//��ǰ����
	FLOAT					m_fSpeed;							//�ƶ��ٶ�
	USHORT					m_lStyle;							//��������
	BYTE					m_lFaction;							//������Ӫ 0���ŵ� 1��˹�ʹ�
	USHORT					m_lPrestige;						//����
	BYTE                    m_cKnight;                          //��λ
	USHORT                  m_cUnion;                           //����
	BYTE                    m_cUnionBusiness;                   //����ְ��
	UINT                    m_uiUionContribute;                 //���ṱ��
	UINT					m_uiStoreNum;						//�ֿ����
	UINT					m_uiBagNum;							//��������
	BYTE					m_lClass;							//ְҵ
	UINT                    m_cExp;								//����
	BYTE                    m_cRank;							//�ȼ�
	long					m_lHP;								//HP
	long					m_lMP;								//MP
	USHORT                  m_usAttackDistance;                 //���﹥����Χ
	USHORT                  m_usAttackSpeed;                    //�����ٶ�
	BYTE                    m_cHairStyle;                       //����
	BYTE                    m_cPupilColor;                      //ͫɫ(����)
	USHORT                  m_usBelief;                         //����
	UINT					m_lMoney;							//��Ǯ
	UINT                    m_lStone;                           //��ʯ
};


//ϵͳ����	\
( GameServer ��> Client )
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

//��������Ϣ\
( GameServer  ----> Client )
struct MSG_KITBAG
{
	MsgHead 				 Head;
	UINT    				 uiUserID;                   //���ID
	UINT					 uiBagNum;					 //��ǰ����
	UINT					 uiUpdataNum;				 //���¿��ð�����Ŀ
	char                     ctab;                       //�ڼ�ҳ
	char                     cStartPos;                  //��ʼλ��
	UINT                     cKitBagFlag;                //����λ�����޵��ߵı�ʶ
	KitBag                   SKitBagInfo[24];            //ÿ�η���24�� 
};

//�ֿ���Ϣ\
( GameServer  ----> Client )
struct MSG_STORAGE
{
	MsgHead 				 Head;
	int						 Money;						  //��Ǯ
	UINT    				 uiUserID;                    //���ID
	char                     cActiveNum;                  //��������
	char                     cLine;                       //�ڼ���
	USHORT                   cKitBagFlag;                 //����λ�����޵��ߵı�ʶ
	KitBag                   SKitBagInfo[12];             //ÿ�η���12�� 
};

struct Friend
{
	char    Name[18];          //����
	bool     IsOnline;         //�Ƿ�����
	USHORT   usCamp;           //��Ӫ
	USHORT   usBusiness;       //ְҵ
	USHORT   usCity;           //����
	USHORT   uc_LV;            //�ȼ�

};

//����\
( GameServer  ----> Client )
struct MSG_RELATIONALL
{
	MsgHead 				 Head;
	UINT    				 uiUserID;                    //���ID
	BYTE                     ucType;                      //���� 	
	BYTE                     cNum;                        //����
	Friend                   sFriend[MAX_FRIENDS_COUNT];                 //�����������30
};


// ����������Ϣ(����)\
( GameServer  ----> Client )
struct MSG_OBJECTINFO
{
	MsgHead  Head;
	long     DB_id;						 //���ݿ�ID
	UINT     uiID;						 //��ϷID
	UINT	 uiType;					 //����(_OBJECT_TYPE_PLAYER/_OBJECT_TYPE_NPC...)
	USHORT   usMapID;                    //��ͼID
	float    X,Y,Z;                      //��ǰ����
	float	 fAtan2;					 //�沿����
	bool	 Stall;						 //��̯״̬
	wchar_t	 StallText[MAX_NAME];		 //��̯�ַ�
	char	 cName[MAX_NAME];		     //����
	UINT     uiMaxHP;                    //���HP
	UINT     uiHP;                       //��ǰHP
	BYTE     ucGender;                    //�Ա�
	BYTE     ucCamp;                     //��Ӫ
	BYTE     ucBelief;                   //����
	BYTE     ucProfession;               //ְҵ
	BYTE     ucHairStyle;                //����
	BYTE	 ucFaceShap;				 //����
	UINT     ucLV;                       //�ȼ�
	UINT     iStatusCount;               //Ŀǰ״̬����
	UINT     iStautsDis[MAX_INC_STATUS+MAX_INC_STATUS];//״̬ID
	USHORT   cEquipPos;                  //װ��λ�ñ�־
	Equip    SEquip[MAX_EQUIP_COUNT];    //װ��	
};


//����\
( Client  ----> GameServer || GameServer  ----> Client )  

struct MSG_TALK
{
	MsgHead		Head;
	INT			uiUserID;                   //���ID
	INT			ucTextSize;                 //�������ݴ�С
	BYTE		ucType;                     //  0:˽��Ƶ��; 1:����Ƶ��; 2:����Ƶ��; 3:��ӪƵ��; 4:����Ƶ��; 5:����Ƶ��;
	BYTE		ucResPlayerNameSize;		//�Լ����ִ�С
	BYTE		ucAimPlayerNameSize;        //˽��ר��
	BYTE		ucChatBubbleSytle;			//�������ݵ���ʽ 0��ʾĬ��
 	WCHAR		wcContent[256];              //��������max length 512
// 
// 	INT			ItemCount;					//װ������
// 	Item		ItemList[3];				//װ����Ϣ
};

struct MSG_TALKCHANNEL 
{
	MsgHead		Head;
	BYTE		ucChannel;
};

//����\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_WALK
{
	MsgHead   Head;
	UINT      uiID;     
	USHORT    usMapID;                    //��ͼID
	float     x,z,fatan;
	long	  lState;
};

//���߿�ʼ\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_WALK_BEGIN
{
	MsgHead   Head;
	UINT      uiID;     
	USHORT    usMapID;                    //��ͼID

	UINT	  uiTick;
	float     X,Y,Z;
	float     OffsetX, OffsetY, OffsetZ;
};

//���߽���\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_WALK_END
{
	MsgHead   Head;
	UINT      uiID;     
	USHORT    usMapID;                    //��ͼID

	UINT	  uiTick;
	float     X,Y,Z;
	float	  fAtan2;				 	  //�沿����
	USHORT    usSkillFlag;                //Ĭ��0����ͨ�÷�����1�����õı�־����֤״̬�����л�
};



//ս��״̬
struct MSG_FIGHT
{
	MsgHead	Head;

	UINT uiID;
	UINT uiTargetID;

	bool Fight;
};

//����\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_ATTACK
{
	MsgHead   Head;
	UINT      uiID;     
	float     X,Y,Z;
	UINT	  uiObjectID;
	long	  uiDamage;
	BYTE      ucWeaponType;           //������������
	BYTE      ucAttackType;           //�������ͣ�����1������2��miss
};

//����\
( GameServer  ----> Client )
struct MSG_DEAD
{
	MsgHead   Head;
	UINT      uiID;			                         //������ID
	INT  	  playerID[MAX_TEAM_NUMBER];			 //���������
	UINT	  playerMoney[MAX_TEAM_NUMBER];		     //��Ӧ�������Ǯ
	UINT	  Exp[MAX_TEAM_NUMBER];                  //�ȼ�����
	UINT	  SkillExp[MAX_TEAM_NUMBER];             //���ܾ���
	UINT	  SkillPoint[MAX_TEAM_NUMBER];           //���ܵ� 
	UINT      KillerID;                              //������ID
	UINT      KillerPre;                             //�������������
};

//�����س�
struct MSG_BACKHOME 
{
	MsgHead Head;
	UINT	uiID;
	int		ReviveType;
};

//HP,MP�ظ�
struct MSG_RESUNE
{
	MsgHead Head;
	ULONG   ulHP;
	ULONG   ulMP;
};

//����
struct MSG_DROPS
{
	MsgHead   Head;
	UINT      uiID;

	int	      DropNum;
	char	  Drops[256];
};

//����\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_SKILL 
{
	MsgHead   Head;
	UINT      uiID; 
	int       cType;                 //ħ��,��ʽID 
	BYTE      cStep;                 //ʩ���׶� 0:ʩ��,1:ִ��
	int	      uiObjectID;            //Ŀ��ID
	BYTE      ucMP;                  //ħ����ֵ����
	float	  x;					 //�ͻ���x����
	float	  z;					 //�ͻ���z����
	float	  x1;					 //Ŀ��x����
	float	  z1;					 //Ŀ��y����
};


//ħ��,��ʽ\
(  GameServer  ----> Client )
struct MSG_MAGIC_DAMAGE
{
	MsgHead   Head;
	UINT      uiID;                 //���ID
	INT	      uiObjectID;           //Ŀ��ID
	BYTE	  Attack_Type;			//���ܹ�����������(����,����,Miss)
	BYTE      Status_Type;          //״̬��������(����,Miss)  
	BYTE	  bType;				//0:HP,1:MP
	int		  iPower;               //�˺���ֵ
	int       ucMagicID;            //����ID
	float	  x1;					//����Ŀ��λ��x
	float	  z1;					//����Ŀ��λ��z
};

struct MSG_MAGIC_PERFORM
{
	MsgHead		Head;
	UINT		uiID;
	INT		uiObjectID;			// ����ID,-1ʱ��ʾ
	UINT		ucMagicID;			// ħ��id
	float		x;					// Ⱥ��ħ����Ŀ��λ��
	float		z;					// Ⱥ��ħ����Ŀ��λ��
};

struct MAGIC_DAMAGE {
	UINT		uiObjectID;			// 
	BYTE		Attack_Type;
	BYTE		ucType;				// 0-HP, 1-MP
	int			iPower;				// Ч��
};
#pragma pack(push)
#pragma pack(1)
struct MSG_MAGIC_CLUSTER_DAMAGE
{
	MsgHead			Head;
	UINT			uiID;
	int				iCount;
	UINT		    ucMagicID;			// ħ��id
	char            bHitStatus;         // ״̬����
	MAGIC_DAMAGE	magicDamage[100];
};
#pragma pack(pop)

//ѧϰ����\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_LEARN 
{
	MsgHead   Head;
	UINT      uiID;                  
	BYTE      cType;                 //��������
	BYTE      cKinds;                //���ܻ�ħ/��ʽ(0:���ܣ�1��ħ�� ��2����ʽ )
	BOOL      bIsSucced;             //ѧϰ���ܳɹ�
};



struct  MAGIC_INFO 
{ 
	int       cType;                 //����ID
	USHORT    usSurplusCoolTime; 
};
//������������\
(  GameServer  ----> Client )
struct MSG_ACTIVESKILL_INFO 
{
	MsgHead    Head;
	UINT       uiID; 
	USHORT     MagicCounts;
	MAGIC_INFO  Magic[150];                //��ʽħ�����������

};


struct  SKILL_INFO 
{
	int       cType;                  //����ID
	USHORT    Rank;                   //�ȼ�
	USHORT    EquipLV;                //װ�������ȼ�
	UINT      NextGradePoint;         //�����������
};
//��������������\
(  GameServer  ----> Client )
struct MSG_PASSIVESKILL_INFO 
{
	MsgHead    Head;
	UINT       uiID;  
	USHORT     SkillCounts;
	SKILL_INFO  Skill[20];          //�����������
};

//ħ������\
(  GameServer  ----> Client )
struct MSG_MAGIC_PARAMETER
{
	MsgHead   	Head;
	UINT      	uiID;
	BYTE      	cType;                 	//��������ID
	char      	cName[64];             	//��������
	BYTE      	ucRank;                	//���ܵȼ�
	BYTE      	ucPractice;            	//����������
	USHORT       lMaxHP;                	//�������ֵ
	USHORT       lMaxMP;                	//���ħ��ֵ 
	USHORT       lDodge;                	//���
	USHORT       lHit;                  	//����
	USHORT      	lMagicExempt;         	//ħ������
	float      	lTerra_Protect;       	//������(��)
	float      	lWater_Protect;       	//������(ˮ)
	float      	lFire_Protect;        	//������(��)
	float        lWind_Protect;        	//������(��)
	USHORT       lPhysics_Protect;       //������(����)
	float        fTerra_Max;             //���ֵ(��)
	float        fWater_Max;             //���ֵ(ˮ)
	float        fFire_Max;              //���ֵ(��)
	float        fWind_Max;              //���ֵ(��)
};



//��������	  \
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



//��Ч\
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

//���ܱ���ϵ�ID
struct MSG_SKILL_INTERRUPT
{
	MsgHead   Head;
	UINT      uiID;                      //����ϵ�ID
};


//�뿪\
( GameServer  ----> Client )
struct MSG_LEAVE
{
	MsgHead   Head;
	UINT      uiID;						 // ID
};


//Ⱥ������\
( GameServer  ----> Client )           
struct MSG_COLONY_LEAVE
{
	MsgHead   Head;
	USHORT    usNum;                    //����     
	UINT      uiID[800];		        // ID
};


//���³���\
( GameServer  ----> Client )
struct MSG_SCENE_CHANGE 
{
	MsgHead   Head;
	UINT      uiUserID;
	float     X,Y,Z;
	USHORT    usCurMapID;                    //��ǰ��ͼID
	USHORT    usNextMapID;                   //��Ҫ����ĵ�ͼID
};



//ʰȡ����\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_PICKUP_DROPS
{
	MsgHead	Head;
	UINT	uiID;
	UINT	uiMonsterID;
	int		PickupIndex;
};


//װ����ʹ�õ���\
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

//�Ƅӵ���\
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

//��Ʒ���
struct MSG_BREAK_ITEM
{
	MsgHead	Head;

	short Flags;//0,����Ʒ��1��������Ʒ��2�������Ʒ
	short Index;
	short Num;
	short IndexAim;
	short NumAim;

	short Overlap;
};

//�洢����\
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

//������\
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


//NPC�Ի�
struct MSG_TALK_NPC 
{
	MsgHead	Head;

	UINT NPCID;

	int NPCFlag;

	int SysFlag;

	char Talk[MAX_NAME];
};

//NPC����
struct MSG_NPC_DATA
{
	MsgHead Head;

	UINT	NPCID;
};

//NPC��������
struct MSG_NPC_ITEMDATA
{
	MsgHead Head;

	UINT	NPCID;
	char TabIndex;
	char MaxTabIndex;
	char ItemCount;
	NpcItemData Itemdata[32];
};

//�̳ǵ�������
struct MSG_MALL_ITEMDATA 
{
	MsgHead Head;
	char TabIndex;
	char MaxTabIndex;
	char ItemCount;
	MallItemData Itemdata[16];
};
//��ȡ�̳ǵ�������
struct MSG_GETITEMDATA 
{
	MsgHead Head;
	UINT	userID;
};

//NPC�ֿ�
struct MSG_NPC_STORAGEDATA 
{
	MsgHead Head;

	UINT	NPCID;

	int		Storage;
};

//NPC����
struct MSG_NPC_SELL 
{
	MsgHead Head;
	UINT NPCID;
	int Index;
	int Num;
	int Count;
	int Base;
};

//�̳Ƿ���
struct MSG_MALL_SELL 
{
	MsgHead Head;
	int Index;
	int Num;
	int Count;
	int Base;
};
//�����̳��ۿ�
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

	int		Money;									//������Ҫ��Ǯ
	int		Bijou;									//������Ҫ��ʯ
	int		RewardMoney;							//�ر���Ǯ
	int		RewardBijou;							//�ر����

	short	Item[QUEST_OBJECTIVES_COUNT];			//������Ҫ�ռ�����ID
	short	Creature[QUEST_OBJECTIVES_COUNT];		//������Ҫɱ��ID
	short	ItemCount[QUEST_OBJECTIVES_COUNT];		//������Ҫ�ռ���������
	short	CreatureCount[QUEST_OBJECTIVES_COUNT];	//������Ҫɱ������
	bool	ExplorerState[QUEST_EXPLORER_COUNT];	//������Ҫɱ������
	
	char	SpecialFlags;							//��־λ
	char	Status;
	char	Completed;
	short	ItemCompletedCount[QUEST_OBJECTIVES_COUNT];
	short	CreatureCompletedCount[QUEST_OBJECTIVES_COUNT];	

	ItemData RewardItem[QUEST_REWARDS_COUNT];	//�ر�����
};

struct MSG_ExplorerQuest //̽��������֤
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

//NPC����
struct MSG_NPC_QUEST
{
	MsgHead		Head;

	UINT		NPCID;

	NPCQuest	Quest;
};

//NPC��������
struct MSG_NPC_NEXTQUEST
{
	MsgHead	Head;

	UINT	NPCID;
	int		QuestID;
	int		QuestSort;

	int		SpecialFlags;							//��־λ

	short	Item[QUEST_OBJECTIVES_COUNT];			//������Ҫ�ռ�����ID
	short	Creature[QUEST_OBJECTIVES_COUNT];		//������Ҫɱ��ID
	short	ItemCount[QUEST_OBJECTIVES_COUNT];		//������Ҫ�ռ���������
	short	CreatureCount[QUEST_OBJECTIVES_COUNT];	//������Ҫɱ������

	int		Money;									//������Ҫ��Ǯ
	int		Bijou;									//������Ҫ��ʯ
	int		RewardMoney;							//�ر���Ǯ
	int		RewardBijou;							//�ر����

	ItemData RewardItem[QUEST_REWARDS_COUNT];		//�ر�����
};

//NPC�����б�
struct MSG_NPC_QUESTS
{
	MsgHead	Head;

	UINT	NPCID;

	int		Count;

	NPCQuest Quest[QUEST_NPCTAKE_COUNT];
};

//���Խ�������,����ʱ,������ˢ��ʱͬ��
struct MSG_NPC_QUESTSAVAILABLE
{
	MsgHead Head;

	int		Count;
	UINT	NPCID[QUEST_PLAYER_COUNT * 4];
	int		QuestID[QUEST_PLAYER_COUNT * 4];
};

//�����Խ�������,����ʱ,������ˢ��ʱͬ��
struct MSG_NPC_QUESTSUNAVAILABLE
{
	MsgHead Head;

	int		Count;
	UINT	NPCID[QUEST_PLAYER_COUNT * 4];
	int		QuestID[QUEST_PLAYER_COUNT * 4];
};

//NPC����ر�
struct MSG_NPC_QUESTREWARD
{
	MsgHead Head;

	UINT	NPCID;

	int		Count;

	int		QuestID[QUEST_NPCTAKE_COUNT];
};


//�鿴������Ϣ
struct MSG_NPC_QUESTVIEW
{
	MsgHead Head;

	UINT	NPCID;
	int		QuestID;
	int		QuestSort;

	int		SpecialFlags;							//��־λ

	short	Item[QUEST_OBJECTIVES_COUNT];			//������Ҫ�ռ�����ID
	short	Creature[QUEST_OBJECTIVES_COUNT];		//������Ҫɱ��ID
	short	ItemCount[QUEST_OBJECTIVES_COUNT];		//������Ҫ�ռ���������
	short	CreatureCount[QUEST_OBJECTIVES_COUNT];	//������Ҫɱ������

	int		Money;									//������Ҫ��Ǯ
	int		Bijou;									//������Ҫ��ʯ
	int		RewardMoney;							//�ر���Ǯ
	int		RewardBijou;							//�ر����

	ItemData RewardItem[QUEST_REWARDS_COUNT];	//�ر�����
};

//ͬ������������
struct MSG_PLAYER_ACCEPTQUESTS 
{
	MsgHead		Head;

	int			Count;

	PlayerQuest Quests[3];
};

//��������
struct MSG_NPC_ACCEPTQUEST 
{
	MsgHead Head;

	int		NPCID;
	int		RewardNPCID;

	int		QuestID;


	int		QuestSort;

	int		SpecialFlags;							//��־λ

	short	Item[QUEST_OBJECTIVES_COUNT];			//������Ҫ�ռ�����ID
	short	Creature[QUEST_OBJECTIVES_COUNT];		//������Ҫɱ��ID
	short	ItemCount[QUEST_OBJECTIVES_COUNT];		//������Ҫ�ռ���������
	short	CreatureCount[QUEST_OBJECTIVES_COUNT];	//������Ҫɱ������

	int		Money;									//������Ҫ��Ǯ
	int		Bijou;									//������Ҫ��ʯ
	int		RewardMoney;							//�ر���Ǯ
	int		RewardBijou;							//�ر����

	ItemData RewardItem[QUEST_REWARDS_COUNT];	//�ر�����
};

//ȡ������
struct MSG_NPC_CANCELQUEST 
{
	MsgHead Head;

	int		NPCID;
	int		RewardNPCID;

	int		QuestID;

	bool	Available;
};

//�������
struct MSG_NPC_COMPLETEQUEST 
{
	MsgHead	Head;

	int		RewardNPCID;

	int		QuestID;
	int		Choice;
};

//����ʧ��
struct MSG_NPC_QUESTFAILD
{
	MsgHead	Head;

	int		RewardNPCID;

	int		QuestID;
};

//������񱨳�
struct MSG_NPC_REWARDQUEST 
{
	MsgHead	Head;

	int		NPCID;
	int		RewardNPCID;

	int		QuestID;
	int		Choice;

	//��Ϊ���û��ͬ����ֻ���ڷ�����������ÿ�����ʱ����һ��
	int		Credit;			//������
	int		Contribute;		//����
	int		EXP;			//����
	int		SkillPoint;		//���ܾ���

	int		SpecialFlags;	//���⽱����ʶ
	int		SpecialCount;	//���⽱������

	ItemData Item;
};

//ͬ��ɱ���ռ�
struct MSG_NPC_QUESTKILLORCAST 
{
	MsgHead Head;

	int		QuestID;
	int		NPCID;

	bool	Kill;
	int		KillOrCastID;
};

//ͬ��̽������
struct MSG_NPC_QUESTEXPLORERRESULT 
{
	MsgHead Head;

	int		QuestID;
	int		NPCID;
	int		Index;
};

//���º���/��������Ϣ
struct  MSG_RELATION
{
	MsgHead		Head;
	char    	cName[ROLENAME_LENGTH];   //����
	BYTE    	bUnion;       //��Ӫ
	BYTE        ucCity;       //����
	BYTE        Business;     //ְҵ
	BYTE        LV;		      //�ȼ�
	bool    	IsOnline;     //�Ƿ�����   
	BYTE        Style;        //����
};



//��������\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_RELATION_REQUEST
{
	MsgHead		Head;
	char    	cName_Request[ROLENAME_LENGTH];
	char        cName_Response[ROLENAME_LENGTH]; 
	char        cType;
	char        Error;          //��Է���������ɫ��Ӧ����Ҫ  
};

//���ѻ�Ӧ
struct MSG_RELATION_RESPONSE
{
	MsgHead		Head;
	char    	cName_Request[ROLENAME_LENGTH];
	bool        IsAgree;            //�Ƿ�ͬ��
};

//ɾ������ϵ
struct MSG_RELATION_DELETE
{
	MsgHead		Head;
	char    	cName_Request[ROLENAME_LENGTH];
	BYTE        Style;     //0:����,1:������,2:����
};

//����\
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

//���׽�Ǯ\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_TRADE_MONEY
{
	MsgHead		Head;
	UINT		uiID;
	int			Money;
	int			Bijou;
	char		chName[64];
};

//���׵���\
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

//���׵���\
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

//�Ƴ����׵���\
( Client  ----> GameServer || GameServer  ----> Client )
struct MSG_TRADE_REMOVEITEM 
{
	MsgHead		Head;
	UINT		uiID;
	int			Index;
	char		chName[64];
};

//װ���ϳ�
struct MSG_EQUIPFORGE_EQUIP 
{
	MsgHead		Head;

	int			Index;		//װ������������
	int			Num;		//�Ǹ���������
	int         Type;        //������/��װ��
};

struct MSG_EQUIPFORGE_MATERIAL
{
	MsgHead		Head;

	int			Index;		//���Ǹ�����
	int			Num;		//��ʯ������
	int         Type;        //���ֱ�ʯ����(��ʯ,ˮ��,���˽��)
}; 

struct MSG_EUQIPFORGE 
{
	MsgHead		Head;
	bool		Success;
	int         Type;		//�ϳ�����:װ������=0,��ʯ�ϳ�=1,װ���ϳ�=2
	int         BaseLv;     //�µȼ�
	int         AppLv;
	int         AppId[5];	//�ºϳɵĸ�������

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

//���ˢ����Ϣ��
struct MSG_TEAM_REFLASH 
{
	MsgHead		Head;

	long		lTeamLeaderID;//�ӳ���ID������ת������������Ϣ
	UINT		uiTeamLeader_HP;
	UINT		uiTeamLeader_MaxHP;
	UINT		uiTeamLeader_Lv;
	BYTE		ucTeamLeader_Class;
	char		chTeamLeader_Name[64];
	SHORT		usTeamLeader_MapID;                    //��ͼID
	float		ufTeamLeader_X;                      //��ǰX����
	float		ufTeamLeader_Y;                      //��ǰY����
	float		ufTeamLeader_Z;                      //��ǰZ����

	long		lTeammate0_ID;
	UINT		uiTeammate0_HP;
	UINT		uiTeammate0_MaxHP;
	UINT		uiTeammate0_Lv;
	char		chTeammate0_Name[64];
	BYTE		ucTeammate0_Class;
	SHORT		usTeammate0_MapID;                    //��ͼID
	float		ufTeammate0_X;                      //��ǰX����
	float		ufTeammate0_Y;                      //��ǰY����
	float		ufTeammate0_Z;                      //��ǰZ����

	long		lTeammate1_ID;
	UINT		uiTeammate1_HP;
	UINT		uiTeammate1_MaxHP;
	UINT		uiTeammate1_Lv;
	char		chTeammate1_Name[64];
	BYTE		ucTeammate1_Class;
	SHORT		usTeammate1_MapID;                    //��ͼID
	float		ufTeammate1_X;                      //��ǰX����
	float		ufTeammate1_Y;                      //��ǰY����
	float		ufTeammate1_Z;                      //��ǰZ����

	long		lTeammate2_ID;
	UINT		uiTeammate2_HP;
	UINT		uiTeammate2_MaxHP;
	UINT		uiTeammate2_Lv;
	char		chTeammate2_Name[64];
	BYTE		ucTeammate2_Class;
	SHORT		usTeammate2_MapID;                    //��ͼID
	float		ufTeammate2_X;                      //��ǰX����
	float		ufTeammate2_Y;                      //��ǰY����
	float		ufTeammate2_Z;                      //��ǰZ����

	long		lTeammate3_ID;
	UINT		uiTeammate3_HP;
	UINT		uiTeammate3_MaxHP;
	UINT		uiTeammate3_Lv;
	char		chTeammate3_Name[64];
	BYTE		ucTeammate3_Class;
	SHORT		usTeammate3_MapID;                    //��ͼID
	float		ufTeammate3_X;                      //��ǰX����
	float		ufTeammate3_Y;                      //��ǰY����
	float		ufTeammate3_Z;                      //��ǰZ����

	bool		bIsDateUpdate;

};

//�����ʧ��Ϣ��
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



//���������Ϣ��
struct MSG_CONSORTIA_CREATE
{
	MsgHead     Head;
	UINT        uiPlayerID;                              //������ID
	Consortia_Info ci;                                   //������Ϣ
	Consortia_Member cm;                                 //�����������Ϣ
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
	UINT             uiPlayerID;                              //������ID
	Consortia_Info   ci;                                      //������Ϣ
	Consortia_Member cm;                            
	BYTE             Style;                                   //0�ɹ�,1�ȼ�����,2��Ǯ����,3�Ѿ��й��� 4δ֪
};
#pragma  pack(pop)

struct MSG_CONSORTIA_BASE_INFO
{
	MsgHead     Head;
	char		acName[64];                   //��������
	BYTE		iLevel;                       //����ȼ�
	long        lfound;                       //�ʽ�
	long        lbijou;                       //��ʯ
	long		lCredit;                      //��������
	char	    acTextInfo[256];              //���ṫ��
	int			MaxMember;					 //������������
	UINT		AltarCounts;				 //���ᴴ����̳�ĸ���
	Consortia_AltarInfo		Altar[9];					 //�����ļ�̳ID��
};

struct  CONSORTIA_MEMBER1
{
	char acMemberName[32];             //��Ա����
	char lMapID;                       //���ڵ�ͼID,-1Ϊ����,0�ŵ�....
	BYTE acDuty;                       //ְ�� 6�᳤ 5���᳤ 4���� 3��Ӣ 2��Ա 1��ϰ��Ա
	BYTE iLevel;			           //�ȼ�
	BYTE ucBusiness;                   //ְҵ
	UINT uiContribute;                 //����

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
	UINT        uiReceivePlayerID;                       //������ID
	UINT        uiCount;                                 //����
	CONSORTIA_MEMBER1 Member[24];
	bool        IsAll;
};

struct MSG_CONSORTIA_INVITE
{
	MsgHead     Head;
	UINT        uiInvitePlayerID;       //�������ID
	char        ciInvitedName[32];      //�������ID
	char        ciConsortiaName[64];    //���������
};


//��ɢ���� 
struct MSG_CONSORTIA_DISMISS
{
	MsgHead     Head;
	char        cPlayerName[32];             //�᳤��ID
};

//������Ӧ 
struct MSG_CONSORTIA_RESPONSE
{
	MsgHead     Head;
	BYTE        Style;                  //���ص�����
	UINT        uiSendPlayerID;         //������ID
	char        ciReceiveName[32];      //�Է�����
};

//�˳����� 
struct  MSG_CONSORTIA_EXIT 
{
	MsgHead     Head;
	char        StrName[32];             //�˳���ҵ�����
	char        NewDutyName[32];         //������ҵ�����
	char        Duty;                    //����ְ��
};

struct MSG_CONSORTIA_TEXT
{
	MsgHead     Head;
    UINT        uiPlayerID;               //�᳤/���µ�ID
	char        NewPlacard[128];         //���ṫ��
};

struct MSG_CONSORTIA_DUTY
{
   MsgHead     Head;
   char        OldName[32];                 //������ҵ�����
   char        OldDuty;                     //��ְ��
   char        NewName[32];                 //������ҵ�����
   char        NewDuty;                     //����ְ��
   
};

struct MSG_CONSORTIA_MEMBER_DEL
{
	MsgHead     Head;
    UINT        uiPlayerID;
	char        strName[32];
};

// ��̳
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

//���ܵ�������\
( GameServer  ----> Client )
struct MSG_SKILLPOINT_UPGRADE
{
    MsgHead     Head;
	UINT        uiPlayerID;
	UINT        SKillPoint;
};

//�����������ܵȼ�
struct MSG_SKILL_UPGRADE
{
	MsgHead     Head;
	UINT        uiPlayerID;
	UINT        uiSkillID;
	UINT        uiCurrentSkillGrade;
	UINT        uiNextSkillGradePoint;
	UINT        uiSurplusPoint;
};

//ͬ���ͻ�������\
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

//״̬��ʧ
struct MSG_STATUS
{
	MsgHead     Head;
	UINT        uiID;                //objID
	UINT        uiCount;
	UINT        uiStatusID[MAX_INC_STATUS+MAX_DEC_STATUS];
	USHORT      uiSurplusTime[MAX_INC_STATUS+MAX_DEC_STATUS];
	StatusData  Data;
};

//������Ϣ\
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

//�����һ��챦ʯ���̱�ʯ����ң�����
struct MSG_CRETIT_EXCHANGE
{
	MsgHead Head;
	UINT					iUserID;				//��ҵ�id
	USHORT					iPrestige;						//����
	UINT                    iExp;				//��ɫ���� 
	UINT					iMoney;							//��Ǯ
	int						iMaterialType;		//��ʯ������
	unsigned short			Num;				//��ʯ������
};

//ת����Ϣ by lion
//( Client ----> GameServer )
struct MSG_GOLD_BOX
{
	MsgHead Head;
	BYTE	Type;			//ת����Ϣ���� 0�� ��ת�� 1�� ��ʼ��ת  2��Ĭ����Ʒ 8��ֱ�Ӵ�
	UINT	GoldBoxId;		//����ID
	BYTE	Iter;			//��������λ��
};


//ת����Ϣ���� by lion
//( GameServer ----> Client)
struct MSG_GOLD_BOX_RETURN
{
	MsgHead		Head;
	BYTE		ucInfo;		//0:���䲻���� 1:�ɹ� 2����Ʒ���� 3������1����Ʒ 4������2����Ʒ 5�� Ĭ����Ʒ
	UINT		DialItem[DIALITEMCOUNT+1];	//�����������ƷID
};

//����һ����Ʒ by tavia
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

//����NPC��ȡ�б�
struct MSG_SYS_NPC_DATA
{
	MsgHead		Head;
	UINT	    NPCID;
	int			NpcType;		//�ж���ʲô���ܵ�NPC
	int         State[8];
};

//ϵͳ����ʹ��
struct MSG_SYS_FUN_USE 
{
	MsgHead		Head;
	UINT	    NPCID;
	int			NpcType;
	USHORT      Data[20];
	bool        NextWin; 
};

//У���뷵��\
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
	UINT        uiReceivePlayerID;                       //������ID
	UINT        uiCount;                                 //����
	Consortia_Member cm[10];                             //�����б�,һ��10��
	Consortia_Info   ci;                                 //������Ϣ
	MSG_CONSORTIA_LIST()
	{
		::ZeroMemory(cm,sizeof(MSG_CONSORTIA_LIST)*10);
	}
};


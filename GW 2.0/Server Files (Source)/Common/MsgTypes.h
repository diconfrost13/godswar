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

#define  VALIDATECODE_LENTH        25                    //У���볤��
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
	// �������ӹ�����Ϣ
	_MSG_INVALID		        	 =  0,

    //client<->login server
	_MSG_LOGIN                       =  1,
	_MSG_LOGIN_RETURN_INFO           ,                   //��½����������
	_MSG_REQUEST_GAMESERVER          ,                   //������Ϸ������

	//loginserver<--->gamereserser
	_MSG_VALIDATE_GAMESERVER         = 300,              //��Ϸ��������֤��

	//client<->game server
	_MSG_LOGIN_GAMESERVER            =  10000,           //��¼��Ϸ������
	_MSG_RESPONSE_GAMESERVER         ,                   //����ѡ����Ϸ������IP
	_MSG_ROLE_INFO                   ,                   //��ɫ��Ϣ
	_MSG_CREATE_ROLE                 ,                   //������ɫ
	_MSG_DELETE_ROLE                 ,                   //ɾ����ɫ
	_MSG_GAMESERVER_READY            ,                   //��Ϸ����������
	_MSG_ENTER_GAME                  ,					 //�ͻ��˾���,׼��������Ϸ
	_MSG_CLIENT_READY                ,                   //�ͻ��˳�ʼ�����
	_MSG_GAMESERVER_INFO			 ,

	// ��Ϣ������Ϣ
	_MSG_SELFINFO                    ,				     //�Լ�����Ϣ
	_MSG_OBJECTINFO                  ,
	_MSG_LEAVE						 ,
	_MSG_COLONY_LEAVE                ,                   //Ⱥ������

	// ��Ϸ������Ϣ
	_MSG_WALK_BEGIN                  , 
	_MSG_WALK_END                    ,
	_MSG_SCENE_CHANGE                ,

	// ս��������Ϣ
	_MSG_FIGHT						 ,
	_MSG_ATTACK						 ,
	_MSG_DEAD						 ,
	_MSG_BACKHOME					 ,
	_MSG_DROPS						 ,
	_MSG_UPGRADE					 ,

	// װ�����߹�����Ϣ
	_MSG_KITBAG                      ,
	_MSG_STORAGE                     ,

	// ����������Ϣ
	_MSG_TALK                        ,
	_MSG_TALKCHANNEL				 ,
	//_MSG_TRADE					 ,

	// ����˲�����ϵ��
	_MSG_PARAMATER                   ,
	// ���ܹ�����Ϣ
	_MSG_SKILL                       ,
	_MSG_ACTIVESKILL_INFO            ,
	_MSG_PASSIVESKILL_INFO           ,
	_MSG_SELFPROPERTY                ,
	_MSG_EFFECT                      ,
	_MSG_MAGIC_DAMAGE                ,
	_MSG_MAGIC_PERFORM				 ,
	_MSG_MAGIC_CLUSTER_DAMAGE		 ,


	// ְҵ������Ϣ
	_MSG_LEARN						 ,                   //ѧϰ����
	_MSG_SKILL_UPGRADE               ,                   //��������

	_MSG_PICKUPDROPS				 ,					 //ʰȡ
	_MSG_USEOREQUIP					 ,					 //ʹ�û�װ��
	_MSG_MOVEITEM					 ,					 //�ƶ���Ʒ
	_MSG_BREAK_ITEM					 ,					 //�����Ʒ
	_MSG_STORAGEITEM				 ,					 //�洢��Ʒ
	_MSG_SELL						 ,					 //����Ʒ

	_MSG_STALL						 ,					 //��̯
	_MSG_STALLADDITEM				 ,					 //�����Ʒ
	_MSG_STALLDELITEM				 ,					 //�h����Ʒ
	_MSG_STALLITEM					 ,					 //��̯��Ʒ
	_MSG_STALLBUYITEM				 ,					 //��

	_MSG_TALKNPC					 ,					 //NPC�Ի�
	_MSG_NPCDATA					 ,					 //NPC����
	_MSG_SYS_NPC_DATA				 ,	    		     //ϵͳNPC����
	_MSG_SYS_FUN_USE                 ,                   //ϵͳ����ʹ��
	_MSG_NPCITEMDATA				 ,					 //NPC��������
	_MSG_NPCSTORAGEDATA				 ,					 //NPC�ֿ�����
	_MSG_NPCSELL					 ,					 //NPC����

	//����
	_MSG_NPCQUEST					 ,					 //����
	_MSG_NPCNEXTQUEST				 ,					 //��������
	_MSG_NPCQUESTS					 ,					 //�����б�
	_MSG_NPCQUESTSAVAILABLE			 ,					 //����ˢ�£��ɽ�
	_MSG_NPCQUESTSUNAVAILABLE		 ,					 //����ˢ�£����ɽ�
	_MSG_NPCQUESTREWARD				 ,					 //���񱨳�
	_MSG_NPCQUESTVIEW				 ,					 //�鿴������Ϣ
	_MSG_NPCACCEPTQUEST				 ,					 //��������
	_MSG_NPCCANCELQUEST				 ,					 //ȡ������
	_MSG_NPCCOMPLETEQUEST			 ,					 //�������
	_MSG_NPCQUESTFAILD				 ,					 //����ʧ��
	_MSG_NPCREWARDQUEST				 ,					 //������񱨳�
	_MSG_NPCQUESTKILLORCAST			 ,					 //ͬ��ɱ���ռ�
	_MSG_PLAYER_ACCEPTQUESTS		 ,					 //ͬ����������
	_MSG_FINDQUEST					 ,					 //��������
	_MSG_FINDQUESTRESULT			 ,					 //����������


	//HP,MP�ظ�
	_MSG_RESUNE                      ,

	//����
	_MSG_RELATIONALL                 ,
	_MSG_RELATION_REQUEST            ,
	_MSG_RELATION_RESPONSE           ,
	_MSG_RELATION_DELETE             ,
	_MSG_RELATION                    , 

	//����
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

	//����ת�� by lion
	_MSG_GOLD_BOX					,

	_MSG_EXPLORER_QUEST				,					//̽��������֤

	_MSG_GOLD_BOX_RETURN				,

	_MSG_TEAM_INVITE				,		//client -> server  && server -> client����������
	_MSG_TEAM_REQUEST				,
	_MSG_TEAM_INFO					,
	_MSG_TEAM_ADD					,		//client -> server�������
	_MSG_TEAM_DELETE				,		//client -> server������Ա		
	_MSG_TEAM_REPLACELEADER			,		//client -> server�����ӳ�
	_MSG_TEAM_DISSOLVE				,		//client -> server�����ɢ
	_MSG_TEAM_LEAVE					,		//client -> server�������
	_MSG_TEAM_TIP					,		//server -> client������ʾ��Ϣ
	_MSG_TEAM_REJECT				,		//client -> server�ܾ��������
	_MSG_TEAM_REFLASH				,		//server -> client���¶���
	_MSG_TEAM_DESTROY				,		//server -> client�����ɢ

	_MSG_UPDATE_MP					,

	//����
	_MSG_CONSORTIA_CREATE           ,        //��������
	_MSG_CONSORTIA_CREATE_RESPONSE  ,        //�����󷵻�ֵ 
	_MSG_CONSORTIA_BASE_INFO        ,        //����������Ϣ
	_MSG_CONSORTIA_MEMBER_LIST      ,        //��Ա�б�
	_MSG_CONSORTIA_INVITE           ,        //������빫��
	_MSG_CONSORTIA_DISMISS          ,        //��ɢ����
	_MSG_CONSORTIA_RESPONSE         ,        //��Ӧ����
	_MSG_CONSORTIA_EXIT             ,        //�˳�����
	_MSG_CONSORTIA_TEXT             ,        //���ṫ��
	_MSG_CONSORTIA_DUTY             ,        //����ְ��
	_MSG_CONSORTIA_MEMBER_DEL       ,        //�Ƴ���Ա

	//��̳
	_MSG_ALTAR_INFO					,		 //��̳��Ϣ

	//����������
	_MSG_ERROR						,
	_MSG_MANAGE_RETURN              ,

	//���ܵ�������
	_MSG_SKILLPOINT_UPGRADE         ,

	//ͬ������
	_MSG_SYN_GAMEDATA               ,

	//״̬
	_MSG_STATUS           ,

	//�Ŷ�
	_MSG_LOGIN_QUEUE,

    //������֪ͨ
	_MSG_SERVER_NOTE,
	_MSG_SKILLBACKUP,
	_MSG_SKILL_INTERRUPT             ,                   //�����ж�

	//GS->AS
	_MSG_KEY_RETURN,                                    //GSУ���뷵��
	_MSG_BAN_PLAYER,
	_MSG_CONSORTIA_LVUP,	                           //��������
	_MSG_ALTAR_CREATE,	                               //������̳
	_MSG_ALTAR_LVUP,		                          //��̳����
	_MSG_ALTAR_OBLATION,	                          //��̳����

	_MSG_MALLITEMDATA,				//GameServer <---> client  ������Ϸ�̳���Ʒ�б�
	_MSG_ASSOCIATIONITEMDATA,       //GameServer <---> client  ���ع����̳���Ʒ�б�
	_MSG_MALLSELL,					//GameServer <---> client  ��Ϸ�̳Ƿ���
	_MSG_ASSOCIATIONSELL,			//GameServer <---> client  �����̳Ƿ���
	_MSG_ASSOCIATIONDISCOUNT,		//GameServer ----> client  �����������ͻ��˵��̳��ۿ۱�(Ϊ��̬�ı��ۿ�)
	//����
	_MSG_CRETIT_EXCHANGE             ,                   //�����һ�
	_MSG_QUESTEXPLORERRESULT		,					 //
	//����һ����Ʒ
	_MSG_SYS_ADD_ITEM		,					 //������Ʒ
	_MSG_SYS_DEL_ITEM		,					//������Ʒ
	_MSG_COUNT,
	_MSG_TARGETINFO,
	_MSG_DELAY_EXIT,								//����ʱ�˳�

	_MSG_WALK,
};    

enum {
	TARGET_SELF				= 1,		// �Լ�
	TARGET_SAME_FACTION		= 2,		// ͬ��Ӫ�������Լ�
	TARGET_DIFF_FACTION		= 4,		// ��ͬ��Ӫ
	TARGET_MONSTER			= 8,		// ����
	TARGET_POS				= 16,		// ��ͼ��
	TARGET_PK_OBJ			= 32,		// ��PK����
	TARGET_ASHES            = 64        // ʬ��
};

// //���᷵������
// typedef enum{
// 	CONSORTIA_SUCCEED       = 0,              // ����Է������ܳɹ�
// 	CONSORTIA_REJECT        = 1,              // �����뷽�ܾ�
// 	CONSORTIA_INVITE_NO_CONSORTIA = 2,        // ������������û�й���
// 	CONSORTIA_INVITE_NO_ACCESS    = 3,        // ������������û��Ȩ��
// 	CONSORTIA_INVITE_FULL         = 4,        // ��ͬ�������˳�Ա����
// 	CONSORTIA_INVITED_NO_LOGIN    = 5,        // ��������˲�����
// 	CONSORTIA_INVITED_HAVE_CONSORTIA = 6,     // ����������Ѿ��й���
// 	CONSORTIA_INVITE_NO_LOGIN        = 7,     // �������Ѿ�����
// }ENUM_CONSORTIA;

#define MAX_CONSORTIA_MEMBER_COUNT 200        //��������Ա����

//������Ϣ����
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
#define					DIALITEMCOUNT				16				//ת����Ʒ����

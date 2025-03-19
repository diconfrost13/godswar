//========================================================
//
//    Copyright (c) 2006,欢乐连线工作室
//    All rights reserved.
//
//    文件名称 ： ServieLoader.h
//    摘    要 ： 游戏服务器初始化
//    
//    当前版本 ： 1.01
//    作    者 ： 李锋军
//    完成日期 ： 2007-01-18

//    当前版本 ： 1.02
//    作    者 ： 李锋军
//    完成日期 ： 2007-05-23
//    修改说明 ： 1,将每条消息处理函数都返回一个eError的错误代码，用于客户端返回
//========================================================

#pragma  once

#include "ErrorMessage.h"
#include <hash_map>
#include <vector>
#include <map>
#include "../Common/Include/cNet/Socket.h"
#include "../Common/Include/cNet/IOCP.h"


#include "../Common/Include/Pipe/IPipe.h"

#define  PIPE_TIMER			1000
#define	 REGISTER_DB_TIMER	1000*30
#define  CHECKT_PIPE_TIMER	30000

#define  MAX_THREAD_DB  1
enum STATE_TYPE{ OFFLINE, NORMAL, BUSY, FULL };  //开启,空闲,繁忙,已满,关闭
enum DB_TYPE{  DB_PRI, DB_READ, DB_WRITE, DB_NONE };

class ServerSocketEventHandle;
class ClientSocketEventHandle;
class GSMaster;
class CPlayer;

typedef eError(ServerSocketEventHandle::*pSHandleFun)(const void*, CPlayer* );
typedef eError(ClientSocketEventHandle::*pCHandleFun)(const void*, GSMaster* );

#pragma pack(push)
#pragma pack(4)
struct SSockHandle
{    
	int  MSG_ID;
	pSHandleFun pfun;
};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(4)
struct CSockHandle
{    
	int  MSG_ID;
	pCHandleFun pfun;
};
#pragma pack(pop)


class CWorld;
//游戏世界服务基类
class  IService
{
	enum eServiceStatus
	{
		SERVICE_CLOSE,
		SERVICE_OPEN
	};
public:
	IService():m_Status(SERVICE_CLOSE){}
	virtual ~IService(){}
	virtual bool  Init()    =0;
	virtual void  Start(){ m_Status = SERVICE_OPEN; };
	virtual void  Stop(){ m_Status = SERVICE_CLOSE; };	 
	virtual void  Release() =0;
	virtual void  Run()     =0;
	bool IsOpen(){ return m_Status == SERVICE_OPEN; }
	virtual void* GetValue(){return NULL;};

protected:
	sbase::CTimerMS   m_Timer;
	eServiceStatus m_Status;
public:
	CWorld* m_pWorld;
};

//数据库服务
class  DBService : public IService
{
#define  DB_TIMER	5000
public:
	DBService(CWorld* pWorld);
	bool  Init();       
	void  Release();
	void  Run();
	void* GetValue(){return m_pDB;}
protected:
private:
	dbtool::IDatabase*       m_pDB/*[MAX_THREAD_DB]*/;
};

//管道服务
class  PipeService : public IService, private sbase::IThreadEvent
{
	typedef ipc_np::CPipe* (*CreatePipeClient)(const char *,const char* , const char* , const char* );

public:
	PipeService(CWorld* pWorld);
	bool  Init();        
	void  Release();
	void  Run( );

	bool OnRead();

	bool OnSend();

	virtual int		OnThreadCreate	(void){ return 0; }		
	virtual int		OnThreadDestroy	(void){ return 0; }	
	virtual int		OnThreadEvent	(void){ return 0; }          
	virtual int		OnThreadProcess	(void);

protected:

	bool ConnectDBServer();
	bool RegisterDBServer();

	void ReadIni();

private:
	sbase::CCriticalSection	m_xLock;
	sbase::CThread*			m_pThread;
	sbase::CTimerMS			m_ConsortiaTimer;

	sbase::CTimerMS			m_RegTimer;

	sbase::CTimerMS			m_CheckTimer;
	char m_szDBIp[32];
	char m_szUserName[16];
	char m_szUserPwd[16];

	HMODULE  m_hPipe;

};

class CommandService;
typedef int(* pFunPrintf)(const char*,...);
typedef void(CommandService::*pKeyFunc)(char *,pFunPrintf);
struct KeyCommand
{
	const char * cmd;
	unsigned char cmdLen;
	pKeyFunc pfun;
	const char * Note;
	long lID;
};

//命令行服务
class  CommandService : public IService
{	
#define  COMMAND_TIMER	50
public:
	CommandService(CWorld* pWorld);
	bool  Init();        
	void  Release();
	void  Run();
protected:
private:
	long Command( void );
	long ParseCommand( char* Argcommand );
	KeyCommand* GetConmandFunTable();
public:
	void Key_Help( char *,pFunPrintf );           //帮助
	void Key_Exit( char *,pFunPrintf );           //立即关闭服务器
	void Key_Quit( char *,pFunPrintf );           //指定的秒数后关闭服务器
	void Key_List( char *,pFunPrintf );           //玩家列表
	void Key_Fps( char *,pFunPrintf );            //AI帧数
	void Key_Resource( char *,pFunPrintf );       //资源
	void Key_Reset( char *,pFunPrintf );          //重置
	void Key_Role( char *,pFunPrintf );           //角色信息
	void Key_Accounts( char *,pFunPrintf );       //帐号信息
	void Key_Queue( char *,pFunPrintf );          //消息队列状态
	void Key_Reloadselling( char *,pFunPrintf );  //摆摊
	void Key_Reloadquest( char *,pFunPrintf );    //任务
	void Key_Broadcast( char *,pFunPrintf );      //世界范围广播系统消息
	void Key_Send( char *,pFunPrintf );           //给一个玩家发送消息
	void Key_SaveAll( char *,pFunPrintf );        //保存所有角色
	void Key_Kick( char *,pFunPrintf );           //将用户踢下线
	void Key_Move( char *,pFunPrintf );           //移动玩家坐标
	void Key_Expand( char *,pFunPrintf );         //扩展在线人数上限

};

#define CMD_FORMAT(a) a,(sizeof(a)-1)
static KeyCommand Commands[]=
{
	{CMD_FORMAT("help"),          &CommandService::Key_Help,            "Display this help",             			0},
	{CMD_FORMAT("exit"),          &CommandService::Key_Exit,         	"Shutdown immediately ",         			1},
	{CMD_FORMAT("quit"),          &CommandService::Key_Quit,         	"Shutdown several minutes later",			2},
	{CMD_FORMAT("list"),          &CommandService::Key_List,         	"Display the player information", 			3},
	{CMD_FORMAT("fps"),           &CommandService::Key_Fps,          	"Display the AI speed",            			4},
	{CMD_FORMAT("resource"),      &CommandService::Key_Resource,     	"Display the resource information",			5},
	{CMD_FORMAT("reset"),         &CommandService::Key_Reset,        	"Reset the resource of game world",   		6},
	{CMD_FORMAT("role"),          &CommandService::Key_Role,         	"Display the role information",    			7},
	{CMD_FORMAT("accounts"),      &CommandService::Key_Accounts,        "Display the accounts information",    		8},
	{CMD_FORMAT("queue"),         &CommandService::Key_Queue,           "Shoe the message queue number", 	    	9},
	{CMD_FORMAT("reloadselling"), &CommandService::Key_Reloadselling,   "Reset the selling",               		 	10},
	{CMD_FORMAT("reloadquest"),   &CommandService::Key_Reloadquest,     "Reset the quest",              			11},
	{CMD_FORMAT("broadcast"),     &CommandService::Key_Broadcast,       "Broadcast system message",        			12},
	{CMD_FORMAT("send"),          &CommandService::Key_Send,            "Send message to player",            		13},
	{CMD_FORMAT("saveall"),       &CommandService::Key_SaveAll,         "Save player data all of game world",   	14},
	{CMD_FORMAT("kick"),          &CommandService::Key_Kick,            "Kick player",        	            		15},
	{CMD_FORMAT("move"),          &CommandService::Key_Move,            "Reset player position",	           		16},
	{CMD_FORMAT("expand"),        &CommandService::Key_Expand,          "Expand max player num",	           		17},	
}; 

#define  AllCmds sizeof(Commands)/sizeof(KeyCommand)



//注册服务
class  RegisterService : public IService
{
#define  REGISTER_TIMER	 10000
public:
	RegisterService(CWorld* pWorld, cnet::CIOCP* pNetClient);
	bool	Init();    
	void	ReStart();     
	void	Release();
	void	Run();

	bool	SendMsgToServer(void *pMsg, int ilen)
	{
		return	m_pClientSck->PackMsg((char*)pMsg, ilen);	
	};

	static string	GetValidCode( string strAccounts )
	{
		map< string, string >::iterator  itor = m_valid_map.find( strAccounts ) ; 
		if ( itor != m_valid_map.end() )
		{
			return itor->second;
		}

		return string("");
	}
	//校验码缓存
	static void CacheValidCode( string Accounts, string Valid )
	{
		sbase::CSingleLock xLock(&m_xLock);
		m_valid_map[Accounts]  = Valid;

	}
	static void ClearValidCode(  snet::CSocket* PSocket  )
	{

		string Accounts("");
		map<  snet::CSocket*, string >::iterator  itor = m_Soket_map.find( PSocket ) ; 
		if ( itor != m_Soket_map.end() )
		{

			Accounts = itor->second;
			m_Soket_map.erase( itor );
		}	

		sbase::CSingleLock xLock1(&m_xLock);
		map< string, string >::iterator  itor1 = m_valid_map.find( Accounts ) ; 
		if ( itor1 != m_valid_map.end() )
		{
			m_valid_map.erase( itor1 );
		}
	}
	static void CacheSocket(  snet::CSocket* PSocket, string strAccounts )
	{
		if ( m_valid_map.find( strAccounts) != m_valid_map.end() )
		{
			m_Soket_map[ PSocket] = strAccounts;
		}

	}


protected:
private:
	const char*	GetHostIP();
	bool		RegisterToLoginServer(void);
	bool		ConnectLoginServer(); 
//	bool	    PackMsg( char* pMsg, int nLen);
	bool		OnRead();
	bool		OnWrite();
	//处理消息
	//void		ReslovePacket(const void * pPacket, snet::CSocket *pSocket);

	//设置自己状态
	void		SetState(STATE_TYPE eState){m_eState = eState;}
	STATE_TYPE	GetState(){return m_eState;}
private:
	cnet::CIOCP*	m_pNetClient;
	cnet::CSocket*	m_pClientSck;

	char			m_strServerIP[64];
	UINT			m_nServerPort;
	BYTE			m_ID;
	string			m_Name;
	UINT            m_nListenPort;
	UINT            m_nPlayerNum;

	//自己的状态
	STATE_TYPE      m_eState;

	bool			m_bIsConnect;

	string			m_strHostIp;

	static map< string, string > m_valid_map;	//登入服务器返回的检验码
	static map< snet::CSocket*, string>  m_Soket_map;
	static sbase::CCriticalSection m_xLock;

};


//排队服务
class  QueueService : public IService
{
#define  QUEUE_TIMER	10000
public:
	QueueService(CWorld* pWorld);
	~QueueService();
	bool  Init();       
	void  Release();
	void  Run();
protected:
private:
	sbase::CCriticalSection m_xLock;
};

//备份服务
class  BackUpService : public IService, private sbase::IThreadEvent
{
#define  BACKUP_TIMER	 10000
public:

	BackUpService(CWorld* pWorld, cnet::CIOCP* pNetClient);
	~BackUpService();


	virtual int		OnThreadCreate	(void){ return 0; }		
	virtual int		OnThreadDestroy	(void){ return 0; }	
	virtual int		OnThreadEvent	(void){ return 0; }          
	virtual int		OnThreadProcess	(void);

	bool  Init();       
	void  Release();
	void  Run();

	bool	SendMsgToServer(void *pMsg, int ilen);


	bool	GetState(){ return m_bConnectDB;}
	void	SetState(bool bState);

private:
	bool		RegisterToPipeServer(void);
	bool		ConnectPipeServer(); 
	bool		OnWrite();
	bool		OnRead();

protected:
private:
	cnet::CIOCP*	m_pNetClient;
	cnet::CSocket*	m_pClientSocket;

	char			m_strServerIP[64];
	UINT			m_nServerPort;

	bool			m_bIsConnect;
	bool			m_bConnectDB;

	sbase::CThread*			m_pThread;

	sbase::CTimerMS			m_ConsortiaTimer;

	sbase::CTimerMS			m_PlayerTimer;

	sbase::CCriticalSection m_xLock;
};


class ServerSocketEventHandle
{
#define MSX_SERVER_MSG 20000
public:
	ServerSocketEventHandle();
	~ServerSocketEventHandle();
	void ResloveGamePacket( const void * pPacket, CPlayer * pPlayer );
	void SendErrorInfo(int ErrID, CPlayer * pPlayer);

protected:

private:
	USHORT MsgRouter[MSX_SERVER_MSG];
private:
	const SSockHandle* GetSockHandleTab( USHORT &Size ) const;
	int GetIndex( int MsgID );

	eError	Handle_SockSetup( const void*, CPlayer* );
	eError  Handle_SocketClose( const void*, CPlayer* );
	eError  Handle_EnterGame( const void*, CPlayer* );
	eError  Handle_ClientReady( const void*, CPlayer* );
	eError  Handle_LoginGS( const void*, CPlayer* );	
	eError  Handle_CreateRole( const void*, CPlayer*f );
	eError  Handle_DelRole( const void*, CPlayer*f );
	eError  Handle_WalkBegin( const void*, CPlayer* );
	eError  Handle_Walk( const void*, CPlayer* );
	eError  Handle_WaklEnd( const void*, CPlayer* );
	eError  Handle_Fight( const void*, CPlayer* );
	eError  Handle_Attack( const void*, CPlayer* );
	eError  Handle_Skill(  const void*, CPlayer*  );
	eError  Handle_Learn(  const void*, CPlayer*  );
	eError  Handle_SkillBackup( const void*, CPlayer*  );
	eError  Handle_SkillUpgrade( const void*, CPlayer*  );
	eError  Handle_SkillInterrupt( const void*, CPlayer* );
	eError  Handle_Effect( const void*, CPlayer* );
	eError  Handle_Talk( const void*, CPlayer* );
	eError	Handle_TalkChannel( const void*, CPlayer* );
	eError  Handle_Drop( const void*, CPlayer* );
	eError  Handle_Equip( const void*, CPlayer*  );
	eError  Handle_MoveItem( const void*, CPlayer* );
	eError  Handle_BreakItem( const void*, CPlayer* );
	eError  Handle_Sell( const void*, CPlayer* );
	eError  Handle_StorageItem( const void*, CPlayer* );
	eError  Handle_Stall( const void*, CPlayer* );
	eError  Handle_StallItem( const void*, CPlayer* );
	eError  Handle_StallAddItem( const void*, CPlayer* );
	eError  Handle_StallDelItem( const void*, CPlayer* );
	eError  Handle_StallBuyItem( const void*, CPlayer* );
	eError  Handle_TalkNPC( const void*, CPlayer* );
	eError  Handle_NPCData( const void*, CPlayer* );
	eError  Handle_NPCSell( const void*, CPlayer* );
	eError	Handle_MallSell( const void*, CPlayer* );
	eError	Handle_AssociationSell(  const void*, CPlayer* );
	eError	Handle_MallItemData( const void*, CPlayer* );
	eError	Handle_AssociationItemData( const void*, CPlayer* );
	eError	Handle_Explorer( const void*, CPlayer* );
	eError  Handle_FindQuest( const void*, CPlayer* );
	eError  Handle_NPCAcceptQuest( const void*, CPlayer* );
	eError  Handle_NPCCancelQuest( const void*, CPlayer* );
	eError  Handle_NPCCompleteQuest( const void*, CPlayer* );
	eError  Handle_NPCQuestView( const void*, CPlayer* );
	eError  Handle_RelationRequest( const void*, CPlayer* );
	eError  Handle_RelationResponse( const void*, CPlayer* );
	eError  Handle_RelationDel( const void*, CPlayer* );
	eError  Handle_Trade( const void*, CPlayer* );
	eError  Handle_TradeMoney( const void*, CPlayer* );
	eError  Handle_TradeAddItem( const void*, CPlayer* );
	eError  Handle_TradeRemoveItem( const void*, CPlayer* );
	eError  Handle_EquipForge( const void*, CPlayer* );
	eError  Handle_EquipForge_Equip( const void*, CPlayer* );
	eError  Handle_EquipMaterial( const void*, CPlayer* );
	eError  Handle_EquipCancel( const void*, CPlayer* );
	eError  Handle_EquipMaterialCancel( const void*, CPlayer* );
	eError  Handle_EquipForgeCacel( const void*, CPlayer* );
	eError  Handle_TeamInvite( const void*, CPlayer* );
	eError  Handle_TeamReject( const void*, CPlayer* );
	eError	Handle_TeamInfo( const void*, CPlayer* );
	eError  Handle_TeamAdd( const void*, CPlayer* );
	eError  Handle_TeamDel( const void*, CPlayer* );
	eError  Handle_TeamLeader( const void*, CPlayer* );
	eError  Handle_TeamDissolve( const void*, CPlayer* );
	eError  Handle_TeamLeave( const void*, CPlayer* );
	eError  Handle_BackHome( const void*, CPlayer* );
	eError  Handle_ConsortiaCreate( const void*, CPlayer* );
	eError  Handle_ConsortiaInvite( const void*, CPlayer* );
	eError  Handle_ConsortiaMemDel( const void*, CPlayer* );
	eError  Handle_ConsortiaText( const void*, CPlayer* );
	eError  Handle_ConsortiaDuty( const void*, CPlayer* );
	eError  Handle_ConsortiaDimiss( const void*, CPlayer* );
	eError  Handle_ConsortiaResponse( const void*, CPlayer* );
	eError  Handle_ConsortiaExit( const void*, CPlayer* );
	eError  Handle_ConsortiaLevelUp( const void*, CPlayer* );
	eError  Handle_CreateAltar( const void*, CPlayer* );
	eError  Handle_AltarLevelUp( const void*, CPlayer* );
	eError  Handle_AltarOblation( const void*, CPlayer* );
	eError  Handle_CretitExchange( const void*, CPlayer* );
	eError  Handle_OpenGoldBox( const void*, CPlayer* );
	eError  Handle_SysFunNPC( const void*, CPlayer* );
	eError	Handle_GetTargetInfo( const void*, CPlayer* );
	eError  Handle_UnknowMsg( const void*, CPlayer* );
	eError  Handle_DelayExit( const void*, CPlayer* );

};

class ClientSocketEventHandle
{
#define  MAX_CLIENT_MSG 600
public:
	ClientSocketEventHandle( GSMaster* pMaster );
	~ClientSocketEventHandle();
	void ResloveGamePacket( const void * pPacket );

protected:
private:
	USHORT MsgRouter[MAX_CLIENT_MSG];
	GSMaster* m_pMaster;
private:
	const CSockHandle* GetSockHandleTab( USHORT &Size ) const; 
	int GetIndex( int MsgID );
	eError Handle_UnknowMsg( const void* pPortMsg, GSMaster* pMaster );
	eError Handle_CheckWords( const void* pPortMsg, GSMaster* pMaster );
};

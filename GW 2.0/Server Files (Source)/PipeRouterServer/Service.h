
#ifndef _FILE_SERVICE_H_
#define _FILE_SERVICE_H_ 

#include "../Common/Include/Base/Inc/Timer.h"
#include "../Common/Include/Base/inc/Thread.h"
#include "../Common/Include/DB/Inc/IDB.h"
#include "../Common/Include/Pipe/IPipe.h"
#include <deque>


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
	virtual void  Stop() { m_Status = SERVICE_CLOSE; }; 
	virtual void  Release() =0;
	virtual void  Run()     =0;
	bool IsOpen(){ return m_Status == SERVICE_OPEN; }
protected:
	sbase::CTimerMS   m_Timer;
	eServiceStatus m_Status;
public:
};


//管道服务
class  PipeService : public IService , private sbase::IThreadEvent 
{

     #define PIPE_TIMER		5000
	 #define SQL_MAXSIZE	4096
	typedef vector<PIPE_INFO> PIPE_VEC;
public:
	PipeService();
	~PipeService();
	bool  Init();      
	void  Stop();    
	void  Release();
	void  Run( );

	bool  OnRead();
	
	virtual int		OnThreadCreate	(void){ return 0; }		
	virtual int		OnThreadDestroy	(void){ return 0; }	
	virtual int		OnThreadEvent	(void){ return 0; }          
	virtual int		OnThreadProcess	(void);

protected:
private:
	CRITICAL_SECTION	m_CriSec;
	sbase::CThread*		m_pThread;
	ipc_np::CPipeRouter*	m_Pipe;

	HMODULE				m_PipeDll;

	PIPE_VEC			m_setPipe;

	int					m_nRouterCount;

	sbase::CTimerMS     m_TimerCheck;	//定时检测管道服务器是否断开

	
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

 class CMaster;
//命令行服务
class  CommandService : public IService 
{	
	#define  COMMAND_TIMER	50
public:
	CommandService( CMaster* pMaster );
	~CommandService();			   
	bool  Init();      
	void  Stop();    
	void  Release();
	void  Run();
protected:
private:
	long Command( void );
	long ParseCommand( char* Argcommand );
	KeyCommand* GetConmandFunTable();
public:
	void Key_Help( char *,pFunPrintf );           //帮助
	void Key_ShutdownServ( char *,pFunPrintf );   //关闭
private:
	CMaster *m_pMaster;
	char strKeyBuffer[256];
	long lKeyCount;

};

#define CMD_FORMAT(a) a,(sizeof(a)-1)
static KeyCommand Commands[]=
{
	{CMD_FORMAT("help"),          &CommandService::Key_Help,            "Display this help",             			                0},
	{CMD_FORMAT("quit"),		  &CommandService::Key_ShutdownServ,    "ShutDown the PipeRouter Server in several times",             	    1},
	{CMD_FORMAT("exit"),          &CommandService::Key_ShutdownServ,    "ShutDown the PipeRouter Server immediately",             	        2},
}; 

#define  AllCmds sizeof(Commands)/sizeof(KeyCommand)

#endif
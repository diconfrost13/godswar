#include "stdafx.h"
#include "Service.h"
#include "../Common/Include/Base/Inc/Ini.h"
#include "Master.h"

typedef ipc_np::CPipeRouter* (*CreatePipeRouter)();


PipeService::PipeService():m_Pipe(NULL)
{
	InitializeCriticalSection(&m_CriSec);
}

PipeService::~PipeService()
{
	SAFE_DELETE( m_pThread );
	DeleteCriticalSection(&m_CriSec);

	m_Pipe->Release();
	FreeLibrary(m_PipeDll);
}


bool PipeService::Init()
{
	printf("Initialize PipeServer...\n");
	m_PipeDll = LoadLibrary("Pipe.dll"); 
	if ( NULL == m_PipeDll)
	{
		return 0;
	}

	//加载服务端网络组建 
	CreatePipeRouter PipeServ =(CreatePipeRouter)::GetProcAddress(m_PipeDll, "PipeRouterCreate");
	if (!PipeServ)
	{
		FreeLibrary(m_PipeDll);
		return false;
	}


	m_Pipe = PipeServ();

	if(m_Pipe == NULL)
		return false;

	//读取配置文件
	char szPipeName[32] = {0};
	char szIP[32]		= {0};
	char LoginName[16]	= {0};

	char PassWord[16]	= {0};
	int  total =  0;

	sbase::CIni _ini("config.ini", false);

	m_nRouterCount = _ini.GetData("RouterNum", "Total");

	for ( int i=0; i<m_nRouterCount; i++ )
	{
		memset(szIP, 0, sizeof(szIP));
		memset(LoginName, 0, sizeof(LoginName));
		memset(PassWord, 0, sizeof(PassWord));
		memset(szPipeName, 0, sizeof(szPipeName));

		char temp[16] = {0};
		sprintf(temp, "Router%d", i+1);

		strcpy(szPipeName,_ini.GetString(temp, "PipeName"));
		strcpy(szIP, _ini.GetString(temp, "ServerIP"));
		strcpy(LoginName,_ini.GetString(temp, "LoginName"));
		strcpy(PassWord,_ini.GetString(temp, "PassWord"));

		PIPE_INFO info;
		memcpy(&info.szPipeName, szPipeName, sizeof(info.szPipeName));
		memcpy(&info.szIP, szIP, sizeof(info.szIP));
		memcpy(&info.szLoginName, LoginName, sizeof(info.szLoginName));
		memcpy(&info.szPassWord, PassWord, sizeof(info.szPassWord));

		m_setPipe.push_back(info);

		//m_Pipe->AddPipeInfo(szPipeName, szIP, LoginName, PassWord);
		m_Pipe->AddPipeInfo(info);


	} // end for


	if ( !m_Pipe->Init() )
	{
		printf("Initialize PipeServer Failed!\n");
		return false;
	}


	m_Timer.Startup(PIPE_TIMER);
	m_TimerCheck.Startup(PIPE_TIMER);

	Start();

	m_pThread = sbase::CThread::CreateNew(*this, sbase::CThread::RUN, 11 );
	if (!m_pThread)
	{
		::MessageBox(NULL, "Create NetWorker thread fail.", "Error", MB_OK|MB_ICONERROR);

		return false;
	}

	m_pThread->SetThreadAMask( 12 );
	return  true;
}

void PipeService::Stop()
{

}

void PipeService::Release()
{
	delete this;
}

void PipeService::Run()
{
	if ( !IsOpen() )
	{
		return;
	}

	for ( int i=0; i<m_nRouterCount; i++ )
	{
		if ( m_Timer.IsExpire() )
		{
			if ( !m_Pipe->GetStatus(i) )
			{
				m_Pipe->InitClient(i);
				m_Timer.Startup(PIPE_TIMER);
			}
		}
		if ( m_TimerCheck.IsExpire() )
		{
			if ( !m_Pipe->CheckPipeState(i) )
			{
				sbase::ConsoleWriteColorText(FOREGROUND_RED, "%s PipeServer Close!", m_setPipe[i].szPipeName );

				//printf("%s PipeServer Close!\n", m_setPipe[i].szPipeName)
				m_TimerCheck.Startup(PIPE_TIMER);
			}
		}

	} 


}

int PipeService::OnThreadProcess()
{

	m_Pipe->Recv(NULL);
	

	return 1;
}

bool PipeService::OnRead()
{

	
	return true;

}


//======================================
CommandService::CommandService(CMaster* pMaster):lKeyCount(0),m_pMaster(pMaster)
{
	memset(strKeyBuffer,0L,sizeof(strKeyBuffer));
}

CommandService::~CommandService()
{

}


bool CommandService::Init()
{
	m_Timer.Startup( COMMAND_TIMER );
	Start();

	printf( "\nDBServer> " );	
	return true;
}

void CommandService::Stop()
{
	IService::Stop();
}

void CommandService::Release()
{
	delete this;
}

void CommandService::Run()
{
	if ( !IsOpen() )
		return ;

	if ( m_Timer.IsExpire() )
	{
		if( Command( ) == -1 )
			exit(1);

		m_Timer.Update();

	}

}

long CommandService::ParseCommand( char* Argcommand )
{
	unsigned int x;
	size_t l= strlen(Argcommand);
	if(l<2)                                                 //return;//some dirty check
	{
		return 0;
	}

	for ( x=0;x<AllCmds;x++)
		if(!memcmp(Commands[x].cmd,Argcommand,Commands[x].cmdLen ))
		{
			(this->*Commands[x].pfun)(&Argcommand[Commands[x].cmdLen],&::printf);
			break;
		}
		if(x==AllCmds)
		{
			sbase::ConsoleWriteColorText( FOREGROUND_RED, "		...Unknown command!\n ");
		}
		return 1;
}


long CommandService::Command( void )
{
	if( kbhit() )
	{
		int key = getch( );
		switch( key )
		{
		case 13:			// Enter
			{
				if( lKeyCount == 0 )
					break;

				ParseCommand( strKeyBuffer  );
				// reset command
				lKeyCount = 0;
				memset( strKeyBuffer, 0, 256 );
			}
			break;
		case 8:				// BackSpace
			{
				if( lKeyCount > 0 )
				{
					printf( "\b \b" );
					strKeyBuffer[lKeyCount] = 0;
					lKeyCount--;
				}
			}
			break;
		case 27:			// ESC
			{
				// clear command
				lKeyCount = 0;
				memset( strKeyBuffer, 0, 256 );
				printf( "   ...[Cancel]\nCommand: " );
			}
			break;
		default:
			{
				if( lKeyCount >= 255 )
				{
					break;
				}
				strKeyBuffer[ lKeyCount ] = (char)key;
				lKeyCount++;
				printf( "%c", key );
				//				printf( "%d\n", key );			// test key marker
			}
			break;
		}
	}

	return 1;	
}

void  CommandService::Key_Help( char *, pFunPrintf pPrintf )
{
	printf("\n");
	for ( int a = 0 ; a < AllCmds; a++ )
	{
		printf( "%-16s  %-20s%-25s\n", Commands[a].cmd, "-",Commands[a].Note);
	}
	pPrintf( "\nDBServer> " );	
}

void CommandService::Key_ShutdownServ( char * command,pFunPrintf pPrintf )
{
	time_t time = 0;
	char *StrTime;
	int x=0;
	while(command[x]==' ')
		x++;
	StrTime = &command[x];
	if(!strlen(StrTime))
	{
		m_pMaster->ShutDownServ( 0 );
		sbase::ConsoleWriteColorText( FOREGROUND_RED, "\nPipeRouter Server  shutdown immediately!\x0d\x0a",time);
		return;
	}

	time = atol(StrTime);
	if ( time != 0 )
	{
		m_pMaster->ShutDownServ( time );
		sbase::ConsoleWriteColorText( FOREGROUND_RED,"\nnPipeRouter Server will shutdown in %d seconds!\x0d\x0a",time);
	}
	pPrintf( "\nDBServer> " );	

}



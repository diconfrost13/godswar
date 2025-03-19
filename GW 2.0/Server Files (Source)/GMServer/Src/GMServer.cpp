// LoginServer.cpp : Defines the entry point for the console application.
//
#include "..\Inc\stdafx.h"

#include "../../Common/Include/Base/Inc/Timer.h"
//#include "..\..\Lib_Base\Inc\IPCChannel.h"

#include "..\inc\GMLogic.h"
#include "..\inc\Command.h"
using namespace std;
using namespace login;


extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow ();

int _tmain(int , _TCHAR* )
{
	sbase::SetConsoleTitle( "GodsWar GM Server" );
	//屏蔽关闭按钮（ 禁止非法退出 ）
	HWND  hWnd  = GetConsoleWindow();
	::ShowWindow( hWnd, SW_SHOWMINIMIZED );
	if (hWnd)
	{   
		HMENU  hMenu  =  GetSystemMenu( hWnd, FALSE );   
		//DeleteMenu(hMenu,SC_MINIMIZE, MF_GRAYED | MF_DISABLED);
		DeleteMenu(hMenu,SC_MAXIMIZE  , MF_GRAYED | MF_DISABLED);
		DeleteMenu(hMenu,SC_SIZE, MF_GRAYED | MF_DISABLED);
		DeleteMenu(hMenu, SC_CLOSE , MF_GRAYED | MF_DISABLED);
	}
	sbase::SetConsoleFontColor(FOREGROUND_GREEN);

	cout<<"               ★★★★★★★★★★★★★★★★★★★★★★★★★"<<endl;
	cout<<"               ★                                              ★"<<endl;
	cout<<"               ★             GodsWar GM Server                ★"<<endl;
	cout<<"               ★       Copyright (c) 2007,欢乐连线工作室      ★"<<endl;
	cout<<"               ★             All rights reserved.             ★"<<endl;
	cout<<"               ★                                              ★"<<endl;
	cout<<"               ★★★★★★★★★★★★★★★★★★★★★★★★★\n\n\n"<<endl;

	cout<<"Initialize GMServer"<<endl;
	//set  PRI
#ifdef WIN32
	{
		HANDLE hProcess = GetCurrentProcess();

		unsigned long appAff;
		unsigned long sysAff;
		if(GetProcessAffinityMask(hProcess,&appAff,&sysAff))
		{
			UINT curAff = 12;
			SetProcessAffinityMask(hProcess,curAff);
		}

		SetPriorityClass(hProcess,HIGH_PRIORITY_CLASS);
	}

#endif

	CGMLogic* LoginServer = new CGMLogic;

	if ( LoginServer == NULL )
	{
		cout<<"加载失败！"<<endl;
	}
	if( !LoginServer->Run() )
	{
		cout<<"运行失败！"<<endl;
	}

	sbase::CTimer timerStatus;
	timerStatus.Startup( 7 );
	CommandInit();
	bool bRun = true;
	while( bRun )
	{

		// 显示服务器状态周期
		if( timerStatus.IsExpire() )
		{
			printf( "\nGMServer Run: \n" );
			if ( !LoginServer->GetPipeState())
			{
				LoginServer->InitPipe();
			}
			timerStatus.Startup( 10 );
		}

		// operate command
		if( Command( ) == -1 )
		{
			// 发送登出消息
			bRun = false;
		}
		Sleep( 1 );
	}

	delete LoginServer;

	return 0;
}
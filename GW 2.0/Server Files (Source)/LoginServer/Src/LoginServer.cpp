// LoginServer.cpp : Defines the entry point for the console application.
#include "..\Inc\stdafx.h"
#include <windows.h>
#include <WinSock2.h>
#include <tchar.h>
#include <iostream>
#include "..\..\Common/Include/Base\Inc\Timer.h"

#include "..\inc\LoginLogic.h"
#include "..\inc\Command.h"
using namespace std;
using namespace login;

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow ();

int _tmain(int , _TCHAR* )
{
 	sbase::SetConsoleTitle( "GodsWar LoginServer" );
 	//屏蔽关闭按钮（ 禁止非法退出 ）
 	HWND  hWnd  = GetConsoleWindow();
 	if (hWnd)
 	{   
 		HMENU  hMenu  =  GetSystemMenu( hWnd, FALSE );   
 		//DeleteMenu(hMenu,SC_MINIMIZE, MF_GRAYED | MF_DISABLED);
 		DeleteMenu(hMenu,SC_MAXIMIZE  , MF_GRAYED | MF_DISABLED);
 		DeleteMenu(hMenu,SC_SIZE, MF_GRAYED | MF_DISABLED);
 		DeleteMenu(hMenu, SC_CLOSE , MF_GRAYED | MF_DISABLED);
 	}
 //	sbase::SetConsoleFontColor(FOREGROUND_GREEN);
 
 	cout<<"               ★★★★★★★★★★★★★★★★★★★★★★★★★"<<endl;
 	cout<<"               ★                                              ★"<<endl;
 	cout<<"               ★             GodsWar Login Server             ★"<<endl;
 	cout<<"               ★       Copyright (c) 2007,欢乐连线工作室      ★"<<endl;
 	cout<<"               ★             All rights reserved.             ★"<<endl;
 	cout<<"               ★                                              ★"<<endl;
 	cout<<"               ★★★★★★★★★★★★★★★★★★★★★★★★★\n\n\n"<<endl;

	sbase::SetConsoleFontColor( FOREGROUND_GREEN  | 0x0009 );

 	printf("Initialize LoginServer...\n");

	sbase::SetConsoleFontColor();
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
 	
 	CLogin* LoginServer = new CLogin;
 	if ( LoginServer == NULL )
 	{
 		cout<<"加载失败！"<<endl;
 	}
 	if( !LoginServer->Run() )
 	{
 		cout<<"运行失败！"<<endl;
 	}

//  	sbase::CTimer timerStatus;
//  	timerStatus.Startup( 7 );
// 	CommandInit();

 	bool bRun = true;

	loginserver::IService * pService = new loginserver::CommandService(LoginServer);

	pService->Init();

 	while( bRun )
 	{
 
		bRun = pService->Run();

 		Sleep( 1 );
 	}
 
	pService->Release();
 	LoginServer->Release();

	return 0;
}



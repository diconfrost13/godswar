// PRServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Master.h"


int _tmain(int argc, _TCHAR* argv[])
{

	CMaster master;

	if ( !master.Init() )
	{
		return 0;
	}

	while ( !CMaster::m_stopEvent )
	{
		master.Run();
		Sleep(1);
	}

	master.Release();

	return 0;
}



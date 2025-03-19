// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once


#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <string>
//#include <memory.h>
#include <conio.h>
#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <time.h>
//#include <omp.h>

#include <map>

#include <windows.h>
#include <WinSock2.h>

#pragma comment( lib, "winmm.lib" )
using namespace std;


#ifdef _DEBUG
	#pragma comment( lib, "..\\Common\\Lib\\Debug\\DBD.lib" )
	#pragma comment( lib, "..\\Common\\Lib\\Debug\\PipeD.lib" )
	#pragma comment( lib, "..\\Common\\Lib\\Debug\\BaseD.lib" )
	#pragma comment( lib, "..\\Common\\Lib\\Debug\\SNetD.lib" )
//#pragma comment( lib, "..\\Lib\\SNetD.lib" )

#else
	#pragma comment( lib, "..\\Common\\Lib\\Release\\DB.lib" )
	#pragma comment( lib, "..\\Common\\Lib\\Release\\Pipe.lib" )
	#pragma comment( lib, "..\\Common\\Lib\\Release\\Base.lib" )
	#pragma comment( lib, "..\\Common\\Lib\\Release\\SNet.lib" )
#endif

// TODO: reference additional headers your program requires here

// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#ifndef _WIN32_WINNT		// 允许使用特定于 Windows XP 或更高版本的功能。
#define _WIN32_WINNT 0x0501	// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif						


#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <Windows.h>

#include "../Common/Include/Base/Inc/SvrBase.h"

using namespace std;

#pragma comment( lib, "winmm.lib" )

#ifdef _DEBUG
    #pragma comment( lib, "..\\Common\\Lib\\Debug\\DBD.lib" )
    #pragma comment( lib, "..\\Common\\Lib\\Debug\\PipeD.lib" )
	#pragma comment( lib, "..\\Common\\Lib\\Debug\\BaseD.lib" )
#else
    #pragma comment( lib, "..\\Common\\Lib\\Release\\DB.lib" )
    #pragma comment( lib, "..\\Common\\Lib\\Release\\Pipe.lib" )
	#pragma comment( lib, "..\\Common\\Lib\\Release\\Base.lib" )
#endif



// TODO: 在此处引用程序需要的其他头文件

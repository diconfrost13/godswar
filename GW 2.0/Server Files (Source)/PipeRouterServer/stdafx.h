// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#ifndef _WIN32_WINNT		// ����ʹ���ض��� Windows XP ����߰汾�Ĺ��ܡ�
#define _WIN32_WINNT 0x0501	// ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
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



// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�

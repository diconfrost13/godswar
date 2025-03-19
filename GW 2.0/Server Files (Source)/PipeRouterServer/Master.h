
#pragma once

#include "Service.h"

class CMaster
{
	enum eServieType
	{
		SERVICE_PIPE,
		SERVICE_COMAND,
		SERVICE_COUNT,
	};
	friend class CommandService;

	enum ePipeType
	{
		Pipe_GS,
		Pipe_DB,
		Pipe_COUNT,
	};
					/*--------------------------------------*/
					/*				��Ա������				*/
					/*--------------------------------------*/
public:
	CMaster();
	~CMaster();

public:

	static volatile bool m_stopEvent;

	bool Init();

	void Run();

	void Release();

protected:
private:
	void UpdateTime();
	void ShutDownServ( time_t time );

					/*--------------------------------------*/
					/*				��Ա������				*/
					/*--------------------------------------*/
public:
protected:
private:

	HMODULE m_hPipeDll;

	sbase::CTimer m_ShutdownTimer;
	IService* m_Service[SERVICE_COUNT];

}; // end class CMaster

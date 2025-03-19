//---------------------------------------------------------------------------
// Desc:	命令行解释响应部分
// Createor:林德辉(David Lin)
// Date:	2004-10-11
// 
// Last Update: 林德辉(David Lin)
// Update Data: 2004-10-11
//---------------------------------------------------------------------------

#include "../Inc/stdafx.h"
//#include "GMLogic.h"

using namespace std;

extern bool g_ConncetGS;
struct tagCommand
{
	string strCommand;
	long lID;
};

char strKeyBuffer[256];
long lKeyCount = 0;


#define MAX_COMMAND_TOTAL			8
tagCommand COMMAND[ MAX_COMMAND_TOTAL ];


long Command( void );
long CommandCheck( string strCommand );
void CommandInit( void );


long Command( void )
{
	// Commands
	while( kbhit() )
	{
		int key = getch( );
		switch( key )
		{
		case 13:			// Enter
			{
				if( lKeyCount == 0 )
					break;

				// check command
				switch( CommandCheck( strKeyBuffer ) )
				{
				case 0:			// exit
					{
						printf( "   ...[Execute]\n\nshutdown server ...\n" );
						return -1;
					}
					break;
				case 1:
					{
						printf( "   ...[Execute]\n");
						printf( "\nCommand: " );
					}
					break;
				case 2:
					{
						printf( "   ...[Execute]\n");
						printf( "\nCommand: " );
					}
					break;
				case 3:
					{
						g_ConncetGS = false;
						printf( "  ......[closegs Success!!]\n");
						printf( "\nCommand: " );
					}
					break;
				case 4:
					{
						g_ConncetGS = true;
						printf( "   ......[opengs Success!!]\n");
						printf( "\nCommand: " );
					}
					break;
				default:
					{
						printf( "   ...[Error]\nCommand: " );
					}
					break;
				}

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
		//Sleep( 10 );
	}

	return 0;
}


long CommandCheck( string strCommand )
{
	for( int i=0; i<MAX_COMMAND_TOTAL; i++ )
	{
		if( strCommand.compare( COMMAND[i].strCommand ) == 0 )
		{
			return COMMAND[i].lID;
		}
	}
	return -1;
}


void CommandInit( void )
{
	COMMAND[0].strCommand = "exit";
	COMMAND[0].lID = 0;
	COMMAND[1].strCommand = "quit";
	COMMAND[1].lID = 0;
	COMMAND[2].strCommand = "list";
	COMMAND[2].lID = 1;
	COMMAND[3].strCommand = "res";
	COMMAND[3].lID = 2;
	COMMAND[4].strCommand = "resource";
	COMMAND[4].lID = 2;
	COMMAND[5].strCommand = "resource1";
	COMMAND[5].lID = 2;
	COMMAND[6].strCommand = "closegs";
	COMMAND[6].lID = 3;
	COMMAND[7].strCommand = "opengs";
	COMMAND[7].lID = 4;




	memset( strKeyBuffer, 0, 256 );
	printf( "Command System\t\t\t\t\t\tReady!\n\nCommand: " );
}

#include "../Inc/stdafx.h"

#include "..\Inc\Session.h"

//#include "..\..\Lib_Base\Inc\mempool.h"
//#include "..\inc\GMLogic.h"

//-------------------------------------------------------
//初始化内存池
//-------------------------------------------------------
//DEFINE_FIXEDSIZE_ALLOCATOR( CSession, 2000, CMemoryPool::GROW_FAST );
//-------------------------------------------------------

CSession::CSession(void * Socket,login::CGMLogic &Logion):m_Logion(Logion)
{
	m_Socket = Socket;
}

//-------------------------------------------------------
CSession::~CSession()
{

}

void CSession::OnDB_Response( dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	int RecordCount = pRes->CountRecord();
	if( 0 >= RecordCount ) 
	{
		SAFE_DELETE( pSession );
		//返回错误信息
		return;
	}
	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
	{
		SAFE_DELETE( pSession );
		//返回错误信息 msg
	}

	MSG_ZERO_ONE msg_Forbid_return;
	msg_Forbid_return.Head.usSize = sizeof(MSG_ZERO_ONE);
	msg_Forbid_return.Head.usType = _MSG_FORBID_LAND_RETURN;
	int iSuccess = Record->Field(UINT(0));
	if ( iSuccess )
	{
		//发送成功消息
		msg_Forbid_return.ucInfo = 1;
	}
	else
	{
		//发送错误信息  该名字或者帐号不存在
		msg_Forbid_return.ucInfo = 0;
	}

	pSession->m_Logion.SendMsg( &msg_Forbid_return, pSession->m_Socket, msg_Forbid_return.Head.usSize );

	SAFE_DELETE( pSession );
}
//-------------------------------------------------------
//查询数据库
//-------------------------------------------------------
void CSession::OnDB_PlayerInfo_Name_Request(const char *Name)
{
	char szSQL[128]; 
	sprintf( szSQL,SQL_SELECT_PLAYER_INFO_FROM_NAME, Name );
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_PlayerInfo_Name_Response );
}

void CSession::OnDB_PlayerInfo_Name_Response(dbtool::PSQL_RESULT result)
{
	//给客户端发送  _MSG_ACCOUNTS_INFO
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	MSG_ZERO_ONE msg_AccountsInfo_return;
	msg_AccountsInfo_return.Head.usSize    = sizeof(MSG_ZERO_ONE);
	msg_AccountsInfo_return.Head.usType    = _MSG_ACCOUNTS_INFO_RETURN;

	int RecordCount = pRes->CountRecord();
	if( 0 >= RecordCount ) 
	{
		msg_AccountsInfo_return.ucInfo = 0;
		pSession->m_Logion.SendMsg( &msg_AccountsInfo_return,pSession->m_Socket, msg_AccountsInfo_return.Head.usSize );

		SAFE_DELETE( pSession );
		//返回错误信息
		return;
	}

	if ( 1 < RecordCount)
	{
		msg_AccountsInfo_return.ucInfo = 0;
		pSession->m_Logion.SendMsg( &msg_AccountsInfo_return,pSession->m_Socket, msg_AccountsInfo_return.Head.usSize  );
		SAFE_DELETE( pSession );
		//返回错误信息
	}

	MSG_ACCOUNTS_INFO  msg_account_info;
	msg_account_info.Head.usSize    = sizeof(MSG_ACCOUNTS_INFO);
	msg_account_info.Head.usType    = _MSG_ACCOUNTS_INFO;
	msg_account_info.m_RoleNum = (BYTE)RecordCount;


	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
	{
		msg_AccountsInfo_return.ucInfo = 0;
		pSession->m_Logion.SendMsg( &msg_AccountsInfo_return,pSession->m_Socket, msg_account_info.Head.usSize );

		SAFE_DELETE( pSession );
		//返回错误信息 msg
	}

	msg_account_info.m_RoleInfo[0].uiUserID = Record->Field(UINT(CHARACTER_ID));
	strcpy(msg_account_info.m_RoleInfo[0].m_strName,Record->Field(UINT(CHARACTER_NAME)));
	strcpy(msg_account_info.m_RoleInfo[0].m_Gender , Record->Field(UINT(CHARACTER_GENDER)));
	msg_account_info.m_RoleInfo[0].m_ucIsGM = Record->Field(UINT(CHARACTER_GMFLAG));
	msg_account_info.m_RoleInfo[0].m_lFaction = Record->Field(UINT(CHARACTER_CAMP));
	msg_account_info.m_RoleInfo[0].m_lClass = Record->Field(UINT(CHARACTER_PROFESSION));
	msg_account_info.m_RoleInfo[0].m_cExp = Record->Field(UINT(CHARACTER_EXP));
	msg_account_info.m_RoleInfo[0].m_cRank = Record->Field(UINT(CHARACTER_LV));
	msg_account_info.m_RoleInfo[0].m_lHP = Record->Field(UINT(CHARACTER_HP_CUR));
	msg_account_info.m_RoleInfo[0].m_lMP = Record->Field(UINT(CHARACTER_MP_CUR));
	msg_account_info.m_RoleInfo[0].m_usBelief = Record->Field(UINT(CHARACTER_BELIFE));
	msg_account_info.m_RoleInfo[0].m_lPrestige = Record->Field(UINT(CHARACTER_PRESTIGE));
	msg_account_info.m_RoleInfo[0].m_cKnight = Record->Field(UINT(CHARACTER_EARL_RANK));
	msg_account_info.m_RoleInfo[0].m_cUnion = Record->Field(UINT(CHARACTER_CONSORTIA));
	msg_account_info.m_RoleInfo[0].m_cUnionBusiness = Record->Field(UINT(CHARACTER_CONSORTIA_JOB));

	msg_account_info.m_RoleInfo[0].m_uiUionContribute = Record->Field(UINT(CHARACTER_CONSORTIA_CONTRIBUTE));
	msg_account_info.m_RoleInfo[0].m_uiStoreNum = Record->Field(UINT(CHARACTER_STORE_NUM));
	msg_account_info.m_RoleInfo[0].m_uiBagNum = Record->Field(UINT(CHARACTER_BAG_NUM));

	msg_account_info.m_RoleInfo[0].m_cHairStyle = Record->Field(UINT(CHARACTER_HAIRSTYLE));
	msg_account_info.m_RoleInfo[0].m_lRegionID = Record->Field(UINT(CHARACTER_CURMAP));
	msg_account_info.m_RoleInfo[0].m_fX = Record->Field(UINT(CHARACTER_CURPOS_X));
	msg_account_info.m_RoleInfo[0].m_fY = Record->Field(UINT(CHARACTER_CURPOS_Z));
	msg_account_info.m_RoleInfo[0].m_lMoney = Record->Field(UINT(CHARACTER_MONEY));
	msg_account_info.m_RoleInfo[0].m_lSKillPoint = Record->Field(UINT(CHARACTER_SKILLPOINT));
	msg_account_info.m_RoleInfo[0].m_lMAXHP = Record->Field(UINT(CHARACTER_MAXHP));
	msg_account_info.m_RoleInfo[0].m_lMAXMP = Record->Field(UINT(CHARACTER_MAXMP));
	strcpy(msg_account_info.m_RoleInfo[0].m_sLastOnlineTime,Record->Field(UINT(CHARACTER_LASTLOGIN_TIME)));
	strcpy(msg_account_info.m_RoleInfo[0].m_sRegisterTime,Record->Field(UINT(CHARACTER_REGISTER_TIME)));
	sprintf(msg_account_info.m_RoleInfo[0].m_sAllOnlineTime,"%d",Record->Field(UINT(CHARACTER_MUTE_TIME)));
	strcpy(msg_account_info.Accounts,Record->Field(UINT(CHARACTER_ACCOUNTS_ID)));
	strcpy(msg_account_info.m_sIP,Record->Field(UINT(IP)));
	strcpy(msg_account_info.Mac,Record->Field(UINT(MAC)));
	msg_account_info.m_RoleInfo[0].m_llForbidSpeak = pSession->m_Logion.m_SpeakForbidTime;



	//构造登陆返回消息
	//将消息放投递进发送队列
	pSession->m_Logion.SendMsg( &msg_account_info,pSession->m_Socket, msg_account_info.Head.usSize );
	SAFE_DELETE( pSession );


}

void CSession::OnDB_PlayerInfo_Account_Request(const char* Account)
{
	char szSQL[128]; 
	memset(szSQL,0L,sizeof(szSQL));
	sprintf( szSQL,SQL_SELECT_PLAYER_INFO_FROM_ACCOUNT,Account);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_PlayerInfo_Account_Response );
}

void CSession::OnDB_PlayerInfo_Account_Response(dbtool::PSQL_RESULT result)
{
	//给客户端发送  _MSG_ACCOUNTS_INFO
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	MSG_ZERO_ONE msg_AccountsInfo_return;
	msg_AccountsInfo_return.Head.usSize    = sizeof(MSG_ZERO_ONE);
	msg_AccountsInfo_return.Head.usType    = _MSG_ACCOUNTS_INFO_RETURN;

	int RecordCount = pRes->CountRecord();
	if( 0 == RecordCount ) 
	{
		msg_AccountsInfo_return.ucInfo = 0;
		pSession->m_Logion.SendMsg( &msg_AccountsInfo_return,pSession->m_Socket, msg_AccountsInfo_return.Head.usSize );

		SAFE_DELETE( pSession );
		return;
	}

	MSG_ACCOUNTS_INFO  msg_account_info;
	msg_account_info.Head.usSize    = sizeof(MSG_ACCOUNTS_INFO);
	msg_account_info.Head.usType    = _MSG_ACCOUNTS_INFO;
	msg_account_info.m_RoleNum = (BYTE)RecordCount;

	for (int i=0; i<RecordCount; i++)
	{
		pRes->Move(i);
		dbtool::IRecord *Record = pRes->GetRecord();
		IF_NOT( Record )
		{
			msg_AccountsInfo_return.ucInfo = 0;
			pSession->m_Logion.SendMsg( &msg_AccountsInfo_return,pSession->m_Socket, msg_account_info.Head.usSize );
			SAFE_DELETE( pSession );
			//返回错误信息 msg
		}

		msg_account_info.m_RoleInfo[i].uiUserID = Record->Field(UINT(CHARACTER_ID));
		strcpy(msg_account_info.m_RoleInfo[i].m_strName,Record->Field(UINT(CHARACTER_NAME)));
		strcpy(msg_account_info.m_RoleInfo[i].m_Gender , Record->Field(UINT(CHARACTER_GENDER)));
		msg_account_info.m_RoleInfo[i].m_ucIsGM = Record->Field(UINT(CHARACTER_GMFLAG));
		msg_account_info.m_RoleInfo[i].m_lFaction = Record->Field(UINT(CHARACTER_CAMP));
		msg_account_info.m_RoleInfo[i].m_lClass = Record->Field(UINT(CHARACTER_PROFESSION));
		msg_account_info.m_RoleInfo[i].m_cExp = Record->Field(UINT(CHARACTER_EXP));
		msg_account_info.m_RoleInfo[i].m_cRank = Record->Field(UINT(CHARACTER_LV));
		msg_account_info.m_RoleInfo[i].m_lHP = Record->Field(UINT(CHARACTER_HP_CUR));
		msg_account_info.m_RoleInfo[i].m_lMP = Record->Field(UINT(CHARACTER_MP_CUR));
		msg_account_info.m_RoleInfo[i].m_usBelief = Record->Field(UINT(CHARACTER_BELIFE));
		msg_account_info.m_RoleInfo[i].m_lPrestige = Record->Field(UINT(CHARACTER_PRESTIGE));
		msg_account_info.m_RoleInfo[i].m_cKnight = Record->Field(UINT(CHARACTER_EARL_RANK));
		msg_account_info.m_RoleInfo[i].m_cUnion = Record->Field(UINT(CHARACTER_CONSORTIA));
		msg_account_info.m_RoleInfo[i].m_cUnionBusiness = Record->Field(UINT(CHARACTER_CONSORTIA_JOB));

		msg_account_info.m_RoleInfo[i].m_uiUionContribute = Record->Field(UINT(CHARACTER_CONSORTIA_CONTRIBUTE));
		msg_account_info.m_RoleInfo[i].m_uiStoreNum = Record->Field(UINT(CHARACTER_STORE_NUM));
		msg_account_info.m_RoleInfo[i].m_uiBagNum = Record->Field(UINT(CHARACTER_BAG_NUM));

		msg_account_info.m_RoleInfo[i].m_cHairStyle = Record->Field(UINT(CHARACTER_HAIRSTYLE));
		msg_account_info.m_RoleInfo[i].m_lRegionID = Record->Field(UINT(CHARACTER_CURMAP));
		msg_account_info.m_RoleInfo[i].m_fX = Record->Field(UINT(CHARACTER_CURPOS_X));
		msg_account_info.m_RoleInfo[i].m_fY = Record->Field(UINT(CHARACTER_CURPOS_Z));
		msg_account_info.m_RoleInfo[i].m_lMoney = Record->Field(UINT(CHARACTER_MONEY));
		msg_account_info.m_RoleInfo[i].m_lSKillPoint = Record->Field(UINT(CHARACTER_SKILLPOINT));
		msg_account_info.m_RoleInfo[i].m_lMAXHP = Record->Field(UINT(CHARACTER_MAXHP));
		msg_account_info.m_RoleInfo[i].m_lMAXMP = Record->Field(UINT(CHARACTER_MAXMP));
		strcpy(msg_account_info.m_RoleInfo[i].m_sLastOnlineTime,Record->Field(UINT(CHARACTER_LASTLOGIN_TIME)));
		strcpy(msg_account_info.m_RoleInfo[i].m_sRegisterTime,Record->Field(UINT(CHARACTER_REGISTER_TIME)));
		sprintf(msg_account_info.m_RoleInfo[i].m_sAllOnlineTime,"%d",Record->Field(UINT(CHARACTER_MUTE_TIME)));
		strcpy(msg_account_info.Accounts,Record->Field(UINT(CHARACTER_ACCOUNTS_ID)));
		strcpy(msg_account_info.m_sIP,Record->Field(UINT(IP)));
		strcpy(msg_account_info.Mac,Record->Field(UINT(MAC)));
		msg_account_info.m_RoleInfo[i].m_llForbidSpeak = pSession->m_Logion.m_SpeakForbidTime; 


	}
	//构造登陆返回消息
	//将消息放投递进发送队列
	pSession->m_Logion.SendMsg( &msg_account_info,pSession->m_Socket, msg_account_info.Head.usSize );
	SAFE_DELETE( pSession );

}

void CSession::OnDB_Reposit_Write_Request(const char* Name)
{
	//先把玩家踢下线 在执行数据库

	char szSQL[128]; 
	sprintf( szSQL,SQL_UPDATE_REPOSIT, Name );
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_Reposit_Write_Respone );

}

void CSession::OnDB_Reposit_Write_Respone( dbtool::PSQL_RESULT result )
{
	//给客户端发送操作结果
	//先判断玩家是否存在
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	MSG_ZERO_ONE msg_Reposit_return;
	msg_Reposit_return.Head.usSize    = sizeof(MSG_ZERO_ONE);
	msg_Reposit_return.Head.usType    = _MSG_REPOSIT_RETURN;

	int RecordCount = pRes->CountRecord();
	if( 0 == RecordCount ) 
	{
		SAFE_DELETE( pSession );
		//返回错误信息
		msg_Reposit_return.ucInfo = 0; //该玩家不存在
	}
	else
	{
		msg_Reposit_return.ucInfo = 1; //复位成功
	}

	pSession->m_Logion.SendMsg( &msg_Reposit_return,pSession->m_Socket, msg_Reposit_return.Head.usSize );
	SAFE_DELETE( pSession );



}

void CSession::OnDB_SendObject_Write_Request(MSG_SENDOBJECT * SendObject)
{
	//调用存储过程，写入数据库  SQL_INSERT_SEND_OBJECT
	//SendObject->Base;
	char cItem[100];
	char szSQL[128]; 
	memset(cItem,0L,sizeof(cItem));

	sprintf(cItem,"[%d,,,,,,%d,%d,%d,%d,0]",SendObject->Base,SendObject->Binding,SendObject->Overlap,SendObject->BaseLV,SendObject->AppendLv);
	if ( SendObject->Append[0] != -1)
	{
		sprintf(cItem,"[%d,%d,,,,,%d,%d,%d,%d,0]",SendObject->Base,SendObject->Append[0],SendObject->Binding,SendObject->Overlap,SendObject->BaseLV,SendObject->AppendLv);
		if( SendObject->Append[1] != -1 )
		{
			sprintf(cItem,"[%d,%d,%d,,,,%d,%d,%d,%d,0]",SendObject->Base,SendObject->Append[0],SendObject->Append[1],SendObject->Binding,SendObject->Overlap,SendObject->BaseLV,SendObject->AppendLv);	
			if ( SendObject->Append[2] != -1 )
			{
				sprintf(cItem,"[%d,%d,%d,%d,,,%d,%d,%d,%d,0]",SendObject->Base,SendObject->Append[0],SendObject->Append[1],SendObject->Append[2],
					SendObject->Binding,SendObject->Overlap,SendObject->BaseLV,SendObject->AppendLv);	
				if (SendObject->Append[3] != -1)
				{
					sprintf(cItem,"[%d,%d,%d,%d,%d,,%d,%d,%d,%d,0]",SendObject->Base,SendObject->Append[0],SendObject->Append[1],SendObject->Append[2],
						SendObject->Append[3],SendObject->Binding,SendObject->Overlap,SendObject->BaseLV,SendObject->AppendLv);	
					if ( SendObject->Append[4] != -1 )
					{
						sprintf(cItem,"[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,0]",SendObject->Base,SendObject->Append[0],SendObject->Append[1],SendObject->Append[2],
							SendObject->Append[3],SendObject->Append[4],SendObject->Binding,SendObject->Overlap,SendObject->BaseLV,SendObject->AppendLv);	
					}
				}
			}
		}
	}

	sprintf( szSQL,SQL_INSERT_SEND_OBJECT, SendObject->m_sRole_name,cItem );
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_SendObject_Write_Respone );



}

void CSession::OnDB_SendObject_Write_Respone(dbtool::PSQL_RESULT result)
{
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	int RecordCount = pRes->CountRecord();
	if( 0 >= RecordCount ) 
	{
		SAFE_DELETE( pSession );
		//返回错误信息
		return;
	}
	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
	{
		SAFE_DELETE( pSession );
		//返回错误信息 msg
	}

	MSG_ZERO_ONE msg_return;
	msg_return.Head.usSize = sizeof(MSG_ZERO_ONE);
	msg_return.Head.usType = _MSG_SENDOBJECT_RETURN;
	int iSuccess = Record->Field(UINT(0));
	if ( iSuccess )
	{
		//发送成功消息
		msg_return.ucInfo = 1;
	}
	else
	{
		//发送错误信息
		msg_return.ucInfo = 0;
	}

	pSession->m_Logion.SendMsg( &msg_return,pSession->m_Socket, msg_return.Head.usSize );
	SAFE_DELETE( pSession );

}


void CSession::OnDB_GetObject_Request( const char* name)
{
	char szSQL[128]; 
	sprintf( szSQL,SQL_SELECT_PLAYER_OBJECT, name );
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_GetObject_Respone );
}

void CSession::OnDB_GetObject_Respone( dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	int RecordCount = pRes->CountRecord();
	if( 0 == RecordCount ) 
	{
		SAFE_DELETE( pSession );
		//返回错误信息
		return;
	}

	enum
	{
		eBag,
		eStorage,
		eEquip
	};

	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
	{
		SAFE_DELETE( pSession );
		//返回错误信息 msg
	}

	char *BagInfo=(char *)Record->Field( UINT(eBag) );
	CreateBagFromDB(BagInfo,pSession);

	char *StorageInfo=(char*)Record->Field(UINT(eStorage));
	CreateStorageFromDB(StorageInfo,pSession);

	char *EquipInfo=(char *)Record->Field( UINT(eEquip) );
	CreateEquipFromDB(EquipInfo,pSession);

	SAFE_DELETE( pSession );


}
void CSession::CreateBagFromDB(std::string DBString, CSession* pSession)
{
	MSG_KITBAG_INFO msg_BagInfo;
	msg_BagInfo.Head.usSize    = sizeof(MSG_KITBAG_INFO);
	msg_BagInfo.Head.usType    = _MSG_KITBAG_INFO;

	int iBagIndex = 0;
	std::string    tmpstr;
	std::string    tmpprop;
	size_t a = 0;
	int d;
	size_t b;
	//解析（道具+装备+仓库）
	if ( DBString.empty() )
	{
		return ;
	}
	while ( !DBString.empty() && DBString != "NULL" )
	{
		b = 0;
		d = 0;
		a = DBString.find_first_of( '#');
		tmpstr.assign( DBString,0,a);
		b = tmpstr.find_first_of( ']' );
		tmpstr.assign( DBString,1,b-1 );
		DBString.erase(0,a+1);

		if (tmpstr.empty())
		{
			msg_BagInfo.SKitBagInfo[iBagIndex].Base = -1;
		}

		while ( !tmpstr.empty() )
		{   

			d++;				
			b = tmpstr.find_first_of(',');
			if ( b != -1)
			{
				tmpprop.assign( tmpstr,0,b);
				tmpstr.erase(0, b+1 );
			}
			else
			{
				tmpprop.assign(tmpstr.c_str());
				tmpstr.clear();
			}

			if ( d == 1)
			{
				msg_BagInfo.SKitBagInfo[iBagIndex].Base = atoi( tmpprop.c_str() );
			}
			else if( d >= 2 && d <= 6  )
			{
				if ( tmpprop.empty() )
					msg_BagInfo.SKitBagInfo[iBagIndex].Append[ d-2 ] = -1;
				else
					msg_BagInfo.SKitBagInfo[iBagIndex].Append[ d-2 ] = atoi( tmpprop.c_str() );
			}	
			else if ( d == 7 )
			{
				msg_BagInfo.SKitBagInfo[iBagIndex].Binding  = atoi( tmpprop.c_str() );
			}
			else if ( d == 8 )
			{
				msg_BagInfo.SKitBagInfo[iBagIndex].Overlap  = atoi( tmpprop.c_str() );
			}
			else if ( d == 9 )
			{
				msg_BagInfo.SKitBagInfo[iBagIndex].BaseLV  = atoi( tmpprop.c_str() );
			}
			else if ( d == 10 )
			{
				msg_BagInfo.SKitBagInfo[iBagIndex].AppendLV  = atoi( tmpprop.c_str() );
			}
			else if ( d == 11 )
			{
				//msg_BagInfo.SKitBagInfo[iBagIndex].CdKey  = atol( tmpprop.c_str() );tao
			}
		}
		iBagIndex++;

	}

	pSession->m_Logion.SendMsg( &msg_BagInfo, pSession->m_Socket, msg_BagInfo.Head.usSize );


}
void CSession::CreateStorageFromDB(std::string DBString, CSession* pSession)
{
	MSG_STORAGE_INFO msg_StorageInfo;
	msg_StorageInfo.Head.usSize    = sizeof(MSG_STORAGE_INFO);
	msg_StorageInfo.Head.usType    = _MSG_STORAGE_INFO;

	int iStorageIndex = 0;
	std::string    tmpstr;
	std::string    tmpprop;
	size_t a = 0;
	int d;
	size_t b;
	//解析（道具+装备+仓库）
	if ( DBString.empty() )
	{
		return ;
	}
	while ( !DBString.empty() && DBString != "NULL" )
	{
		b = 0;
		d = 0;
		a = DBString.find_first_of( '#');
		tmpstr.assign( DBString,0,a);
		b = tmpstr.find_first_of( ']' );
		tmpstr.assign( DBString,1,b-1 );
		DBString.erase(0,a+1);
		//装备ID

		if (tmpstr.empty())
		{
			if ( iStorageIndex < 18)
			{
				msg_StorageInfo.StorageBigInfo[iStorageIndex].Base = -1;
			}
		}

		while ( !tmpstr.empty() )
		{   

			d++;				
			b = tmpstr.find_first_of(',');
			if ( b != -1)
			{
				tmpprop.assign( tmpstr,0,b);
				tmpstr.erase(0, b+1 );
			}
			else
			{
				tmpprop.assign(tmpstr.c_str());
				if ( iStorageIndex >=18)
				{
					msg_StorageInfo.money = atoi( tmpprop.c_str() ) ;
				}
				tmpstr.clear();
				break;
			}

			if ( d == 1)
			{
				msg_StorageInfo.StorageBigInfo[iStorageIndex].Base = atoi( tmpprop.c_str() );
			}
			else if( d >= 2 && d <= 6  )
			{
				if ( tmpprop.empty() )
					msg_StorageInfo.StorageBigInfo[iStorageIndex].Append[ d-2 ] = -1;
				else
					msg_StorageInfo.StorageBigInfo[iStorageIndex].Append[ d-2 ] = atoi( tmpprop.c_str() );
			}	
			else if ( d == 7 )
			{
				msg_StorageInfo.StorageBigInfo[iStorageIndex].Binding  = (UINT)(atoi( tmpprop.c_str() ));
			}
			else if ( d == 8 )
			{
				msg_StorageInfo.StorageBigInfo[iStorageIndex].Overlap  = (UINT)(atoi( tmpprop.c_str() ));
			}
			else if ( d == 9 )
			{
				msg_StorageInfo.StorageBigInfo[iStorageIndex].BaseLV  = (UINT)(atoi( tmpprop.c_str() ));
			}
			else if ( d == 10 )
			{
				msg_StorageInfo.StorageBigInfo[iStorageIndex].AppendLV  = (UINT)(atoi( tmpprop.c_str() ));
			}
			else if ( d == 11 )
			{
				//msg_StorageInfo.StorageBigInfo[iStorageIndex].CdKey  = (long)(atol( tmpprop.c_str() ));tao
			}
		}
		iStorageIndex++;

	}

	pSession->m_Logion.SendMsg( &msg_StorageInfo,pSession->m_Socket, msg_StorageInfo.Head.usSize );

}
void CSession::CreateEquipFromDB(std::string DBString, CSession* pSession)
{
	MSG_EQUIP_INFO msg_EquipInfo;
	msg_EquipInfo.Head.usSize    = sizeof(MSG_EQUIP_INFO);
	msg_EquipInfo.Head.usType    = _MSG_EQUIP_INFO;

	int iEquipIndex = 0;
	std::string    tmpstr;
	std::string    tmpprop;
	size_t a = 0;
	int d;
	size_t b;
	//解析（道具+装备+仓库）
	if ( DBString.empty() )
	{
		return ;
	}
	while ( !DBString.empty() && DBString != "NULL" )
	{
		b = 0;
		d = 0;
		a = DBString.find_first_of( '#');
		tmpstr.assign( DBString,0,a);
		b = tmpstr.find_first_of( ']' );
		tmpstr.assign( DBString,1,b-1 );
		DBString.erase(0,a+1);
		//装备ID

		if (tmpstr.empty())
		{
			msg_EquipInfo.sEquip[iEquipIndex].Base = -1;
		}

		while ( !tmpstr.empty() )
		{   

			d++;				
			b = tmpstr.find_first_of(',');
			if ( b != -1)
			{
				tmpprop.assign( tmpstr,0,b);
				tmpstr.erase(0, b+1 );
			}
			else
			{
				tmpprop.assign(tmpstr.c_str());
				tmpstr.clear();
			}

			if ( d == 1)
			{
				msg_EquipInfo.sEquip[iEquipIndex].Base = atoi( tmpprop.c_str() );
			}
			else if( d >= 2 && d <= 6  )
			{
				if ( tmpprop.empty() )
					msg_EquipInfo.sEquip[iEquipIndex].Append[ d-2 ] = -1;
				else
					msg_EquipInfo.sEquip[iEquipIndex].Append[ d-2 ] = atoi( tmpprop.c_str() );
			}	
			else if ( d == 7 )
			{
				//msg_EquipInfo.sEquip[iBagIndex].Binding  = atoi( tmpprop.c_str() );
			}
			else if ( d == 8 )
			{
				//msg_EquipInfo.sEquip[iBagIndex].Overlap  = atoi( tmpprop.c_str() );
			}
			else if ( d == 9 )
			{
				msg_EquipInfo.sEquip[iEquipIndex].BaseLV  = atoi( tmpprop.c_str() );
			}
			else if ( d == 10 )
			{
				msg_EquipInfo.sEquip[iEquipIndex].AppendLevel  = atoi( tmpprop.c_str() );
			}

		}
		iEquipIndex++;

	}

	pSession->m_Logion.SendMsg( &msg_EquipInfo,pSession->m_Socket, msg_EquipInfo.Head.usSize );

}


void CSession::OnDB_ForbidAccounts_Request(const char* Accounts,const char* StartTime,const char* EndTime,const char* cGmName,const char * cReason)
{
	char szSQL[512]; 
	sprintf( szSQL,SQL_INSERT_FORBID_ACCOUNT, Accounts,StartTime,EndTime,cGmName,cReason );
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_Response );
}

void CSession::OnDB_ForbidIp_Request(const char* cIP,const char* StartTime,const char* EndTime,const char* cGmName,const char * cReason)
{
	char szSQL[512]; 
	sprintf( szSQL,SQL_INSERT_FORBID_IP, cIP,StartTime,EndTime,cGmName,cReason );
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_Response );
}
void CSession::OnDB_Del_Forbid_Request(const char* cIpAccounts, UINT Type)
{
	char szSQL[512]; 
	sprintf( szSQL,SQL_DELECT_FORBID, cIpAccounts,Type);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_Placard_Respone );
}
void CSession::OnDB_ForbidAccountsList_Request()
{
	char szSQL[128]; 
	strcpy( szSQL,SQL_SELECT_FORBID_ACCOUNT_LIST);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_GetForbidAccount_Respone );
}
void CSession::OnDB_ForbidIpList_Request()
{
	char szSQL[128]; 
	strcpy( szSQL,SQL_SELECT_FORBID_IP_LIST);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_GetForbidIP_Respone );
}

void CSession::OnDB_ForbidSpead_Request(const char* Name,const char* GM_Name,UINT TimeDefer)
{
	char szSQL[256]; 
	sprintf( szSQL,SQL_UPDATE_SPEAKFORBID,Name,GM_Name,TimeDefer);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_ForbidSpead_Respone );
}
void CSession::OnDD_GetForbidSpeadTime_Request( const char* Name,UINT Type)
{
	char szSQL[256]; 
	sprintf( szSQL,SQL_SELECT_FORBID_TIME,Name,Type);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDD_GetForbidSpeadTime_Respone );
}
void CSession::OnDB_Placard_Request( MSG_PLACARD * msg_placard )
{
	char szSQL[512]; 
	sprintf( szSQL,SQL_UPDATE_PLACARD,msg_placard->m_uiPlacardID,msg_placard->cGMAccounts,msg_placard->m_ucPlacardType,msg_placard->m_ucSendType,msg_placard->m_sBeginTime,msg_placard->m_sEndTime,msg_placard->m_uInterval,msg_placard->m_sPlacardInfo);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_Placard_Respone );
}

void CSession::OnDB_Del_Placard_Request( UINT id)
{
	char szSQL[512]; 
	sprintf( szSQL,SQL_DELECT_PLACARD,id);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_Placard_Respone );
}

void CSession::OnDB_PlacardList_Request()
{
	char szSQL[512]; 
	strcpy( szSQL,SQL_SELECT_PLACARD);
	m_Logion.m_pDB->ExecuteAsyncSQL( szSQL,(void *)this, &CSession::OnDB_PlacardList_Respone );
}
void CSession::OnDB_GetForbidAccount_Respone( dbtool::PSQL_RESULT result )
{

	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	int RecordCount = pRes->CountRecord();
	if( 0 == RecordCount ) 
	{
		SAFE_DELETE( pSession );
		return;
	}

	MSG_LIST_REQUEST_RETURN  msg_forbidlist_return;
	msg_forbidlist_return.Head.usSize    = sizeof(MSG_LIST_REQUEST_RETURN);
	msg_forbidlist_return.Head.usType    = _MSG_LIST_REQUEST_RETURN;
	msg_forbidlist_return.list_type = 0 ;
	msg_forbidlist_return.ucType = 0 ;

	for (int i=0; i<RecordCount; i++)
	{
		pRes->Move(i);
		dbtool::IRecord *Record = pRes->GetRecord();
		IF_NOT( Record )
		{
			SAFE_DELETE( pSession );
			return;
		}

	else if ( i == 0 )
	{
		msg_forbidlist_return.ucType = 0 ;
	}
	else
	{
		msg_forbidlist_return.ucType = 1 ;
	}

	strcpy( msg_forbidlist_return.land_msg.m_sPlayer_info,Record->Field(UINT(0)) );
	strcpy( msg_forbidlist_return.land_msg.m_sBeginTime,Record->Field(UINT(2)) );
	strcpy( msg_forbidlist_return.land_msg.m_sEndTime,Record->Field(UINT(3)) );
	strcpy( msg_forbidlist_return.land_msg.cGMAccounts,Record->Field(UINT(4)) );
	strcpy( msg_forbidlist_return.land_msg.reason,Record->Field(UINT(5)) );

	pSession->m_Logion.SendMsg( &msg_forbidlist_return,pSession->m_Socket, msg_forbidlist_return.Head.usSize );

	}



	SAFE_DELETE( pSession );
}
void CSession::OnDB_GetForbidIP_Respone( dbtool::PSQL_RESULT result )
{

	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	int RecordCount = pRes->CountRecord();
	if( 0 == RecordCount ) 
	{
		SAFE_DELETE( pSession );
		return;
	}

	MSG_LIST_REQUEST_RETURN  msg_forbidlist_return;
	msg_forbidlist_return.Head.usSize    = sizeof(MSG_LIST_REQUEST_RETURN);
	msg_forbidlist_return.Head.usType    = _MSG_LIST_REQUEST_RETURN;
	msg_forbidlist_return.list_type = 1 ;
	msg_forbidlist_return.ucType = 0 ;

	for (int i=0; i<RecordCount; i++)
	{
		pRes->Move(i);
		dbtool::IRecord *Record = pRes->GetRecord();
		IF_NOT( Record )
		{
			SAFE_DELETE( pSession );
			return;
		}
		if ( i  == 0)
		{
			msg_forbidlist_return.ucType = 0 ;
		}
		else
		{
			msg_forbidlist_return.ucType = 1 ;
		}

		strcpy( msg_forbidlist_return.land_msg.m_sPlayer_info,Record->Field(UINT(0)) );
		strcpy( msg_forbidlist_return.land_msg.m_sBeginTime,Record->Field(UINT(1)) );
		strcpy( msg_forbidlist_return.land_msg.m_sEndTime,Record->Field(UINT(2)) );
		strcpy( msg_forbidlist_return.land_msg.cGMAccounts,Record->Field(UINT(3)) );
		strcpy( msg_forbidlist_return.land_msg.reason,Record->Field(UINT(4)) );


		pSession->m_Logion.SendMsg( &msg_forbidlist_return,pSession->m_Socket, msg_forbidlist_return.Head.usSize );

	}

	SAFE_DELETE( pSession );
}

void CSession::OnDB_ForbidSpead_Respone( dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}
	SAFE_DELETE( pSession );
}
void CSession::OnDB_Placard_Respone( dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}
	SAFE_DELETE( pSession );
}
void CSession::OnDB_PlacardList_Respone( dbtool::PSQL_RESULT result )
{
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	int RecordCount = pRes->CountRecord();
	if( 0 == RecordCount ) 
	{
		SAFE_DELETE( pSession );
		return;
	}

	MSG_PLACARD_RETURN  msg_placard_return;
	msg_placard_return.Head.usSize    = sizeof(MSG_PLACARD_RETURN);
	msg_placard_return.Head.usType    = _MSG_PLACARD_RETURN;
	msg_placard_return.ucType = 0 ;

	for (int i=0; i<RecordCount; i++)
	{
		pRes->Move(i);
		dbtool::IRecord *Record = pRes->GetRecord();
		IF_NOT( Record )
		{
			SAFE_DELETE( pSession );
			return;
		}
		if ( i  == 0)
		{
			msg_placard_return.ucType = 0 ;
		}
		else
		{
			msg_placard_return.ucType = 1 ;
		}

		msg_placard_return.m_uiPlacardID = Record->Field(UINT(0)) ;
		strcpy( msg_placard_return.cGMAccounts,Record->Field(UINT(1)) );
		msg_placard_return.m_ucPlacardType = Record->Field(UINT(2)) ;
		msg_placard_return.m_ucSendType = Record->Field(UINT(3)) ;

		strcpy( msg_placard_return.m_sBeginTime,Record->Field(UINT(4)) );
		strcpy( msg_placard_return.m_sEndTime,Record->Field(UINT(5)) );
		msg_placard_return.m_uInterval = Record->Field(UINT(6)) ;
		strcpy( msg_placard_return.m_sPlacardInfo,Record->Field(UINT(7)) );
		

		pSession->m_Logion.SendMsg( &msg_placard_return, pSession->m_Socket, msg_placard_return.Head.usSize );

	}

	SAFE_DELETE( pSession );
}

void CSession::OnDD_GetForbidSpeadTime_Respone( dbtool::PSQL_RESULT result)
{
	IF_NOT( result ) 
	{
		return;
	}
	CSession *pSession = static_cast< CSession* >(result->pPlayer); 
	if ( pSession == NULL )
	{
		return;
	}

	dbtool::IRecordset *pRes =  result->pResult;
	if(!pRes)
	{
		SAFE_DELETE( pSession );
		return;
	}

	int RecordCount = pRes->CountRecord();
	if( 0 == RecordCount ) 
	{
		pSession->m_Logion.m_SpeakForbidTime = 0;
		SAFE_DELETE( pSession );
		return;
	}

	pRes->Move(0);
	dbtool::IRecord *Record = pRes->GetRecord();
	IF_NOT( Record )
	{
		SAFE_DELETE( pSession );
		return;
	}

	pSession->m_Logion.m_SpeakForbidTime = (LONGLONG)Record->Field(UINT(0)) ;
	if ( pSession->m_Logion.m_SpeakForbidTime <=0)
	{
		pSession->m_Logion.m_SpeakForbidTime = 0;
	}

	SAFE_DELETE( pSession );
}
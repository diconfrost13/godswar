//========================================================
//
//    Copyright (c) 2008,�������߹�����
//    All rights reserved.
//
//    �ļ����ƣ�
//    ժ    Ҫ��װ�������ϳ��߼��ж�
//    
//    ��ǰ�汾��1.00
//    ��    �ߣ�����
//    ������ڣ�2008-3-20
//
//========================================================
#include "stdafx.h"
#include "EquipForge.h"
#include "Player.h"
#include "ItemManager.h"
#include "..\..\Common\MsgDefine.h"
#include "..\..\Common\MsgTypes.h"
#include "..\ServiceLoader.h"
#include "..\ErrorMessage.h"

extern MSG_EQUIPFORGE_EQUIP msg_equipforge_equip;
extern MSG_EQUIPFORGE_MATERIAL msg_equipforge_material;
extern MSG_EUQIPFORGE msg_equipforge;


EquipForge::EquipForge()
{

}

EquipForge::~EquipForge()
{

}

void EquipForge::Init(CPlayer* player)
{
	m_Player = player;
}

eError EquipForge::ClearEquip()
{
	//���װ���໺�����ݶ���

	for(int i=0;i<6;i++)
	{
		//if (m_Equip[i])
			//m_Equip[i]->m_Lock = false;

		m_Equip[i] = NULL;
	}
	return NO_MSG_ERRO;
}

eError EquipForge::ClearMaterial()
{
	//��ձ�ʯ�໺�����ݶ���

	for(int i=0;i<6;i++)
	{
		//if (m_Material[i])
		//	m_Material[i]->m_Lock = false;

		m_Material[i] = NULL;
	}
	return NO_MSG_ERRO;
}

eError EquipForge::ClearForge()
{

	for(int i=0;i<6;i++)
	{
		//if (m_Equip[i])
		//	m_Equip[i]->m_Lock = false;

		//if (m_Material[i])
		//	m_Material[i]->m_Lock = false;

		m_Material[i] = NULL;
		m_Equip[i] = NULL;
	}

	Clear();
	return NO_MSG_ERRO;
}

eError EquipForge::SetEquip(Item* equip , int  , int num, int type)
{
	if (!equip)
	{
		//�ϳ����
		m_Player->AddDanger();
		sbase::LogException("Message type Exception ,Accounts : %s, Role: %s,[_MSG_EQUIPFORGE_EQUIP]", m_Player->GetAccounts(), m_Player->GetName() );
		return MSG_ERRO_0296;
	}

	if (equip->IsClear())
	{

		return MSG_ERRO_0296;
	}

	if (!equip->GetItemBaseAttribute())
	{
		return MSG_ERRO_0296;
	}

	if (equip->BaseLevel <= 0 || equip->BaseLevel > 5 || equip->AppLevel <= 0 || equip->AppLevel > 10 )
	{
		return MSG_ERRO_0296;
	}

	if (!equip->GetItemBaseAttribute()->Equip)
	{
		return MSG_ERRO_0296;
	}

	if (equip->m_Lock)
	{
	
		return MSG_ERRO_0296;
	}

	//if (m_Equip[0])
	//	m_Equip[0]->m_Lock = true;


	//������Ϣ�����ݷֱ����뻺��װ�������
	if(type==1){ m_Equip[0] = equip; 	}

	if(type==15){ m_Equip[0] = equip; 	}
	if(type==16){ m_Equip[1] = equip; 	}
	if(type==17){ m_Equip[2] = equip; 	}
	if(type==18){ m_Equip[3] = equip; 	}
	if(type==19){ m_Equip[4] = equip; 	}
	if(type==20){ m_Equip[5] = equip; 	}


	// 	msg_equipforge_equip.Index = index;
	// 	msg_equipforge_equip.Num = num;
	// 
	// 	g_pLoader->SendMsgToClient(&msg_equipforge_equip , m_Player->GetSocket());

	
	return NO_MSG_ERRO;
}

eError EquipForge::SetMaterial(Item* material , int  , int num, int type)
{

	if (!material)
	{
		//�ϳ����
		m_Player->AddDanger();
		sbase::LogException("Message type Exception ,Accounts : %s, Role: %s,[_MSG_EQUIPFORGE_MATERIAL]", m_Player->GetAccounts(), m_Player->GetName() );
		return MSG_ERRO_02A5;
	}

	if (!material->GetItemBaseAttribute())
	{
		return MSG_ERRO_02A5;
	}

	if (material->IsClear())
	{

		//return;
	}

	if (material->m_Lock)
	{

		return MSG_ERRO_02A5;
	}

	
	//material->m_Lock = true;

	//if (m_Material[0])
	//	m_Material[0]->m_Lock = false;


	//m_Material[0] = material; 

	//������Ϣ�����ݷֱ����뻺�汦ʯ�����
	if(type==2)
	{ m_Material[0] = material; }

	if(type==3){ m_Material[1] = material; }
	if(type==4){ m_Material[2] = material; }
	if(type==5){ m_Material[3] = material; }
	if(type==6){ m_Material[4] = material; }

	if(type==8)
	{ m_Material[0] = material; 	}
	if(type==9){ m_Material[1] = material; 	 }
	if(type==10){ m_Material[2] = material;  }
	if(type==11){ m_Material[3] = material;  }
	if(type==12){ m_Material[4] = material;  }
	if(type==13){ m_Material[5] = material;  }

	// 	msg_equipforge_material.Index = index;
	// 	msg_equipforge_material.Num = num;
	//  
	// 	g_pLoader->SendMsgToClient(&msg_equipforge_material , m_Player->GetSocket());
	return NO_MSG_ERRO;
}

//��ʼ����ʱ�����
void EquipForge::Clear()
{
	for(int i=0;i<6;i++)
	{
		if(m_Equip[i]!=NULL)
		{
			//m_Equip[i]->m_Lock = false;
			m_Equip[i] = NULL;
		}
	
		if(m_Material[i]!=NULL)
		{
			//m_Material[i]->m_Lock = false;
			m_Material[i] = NULL;
		}
	}
}

eError EquipForge::Forge(int type)
{
	//���ֺϳ���������
	if(!type)
	{
		if (!m_Equip[0] || !m_Material[0])
		{
			return MSG_ERRO_0287;
		}

		if (m_Equip[0]->IsClear() || m_Material[0]->IsClear())
		{
			return MSG_ERRO_0287;
		}

		if (m_Equip[0]->BaseLevel <= 0 || m_Equip[0]->BaseLevel > 5 || m_Equip[0]->AppLevel <= 0 || m_Equip[0]->AppLevel > 10 )
		{
			return MSG_ERRO_0287;
		}

		if (!m_Equip[0]->GetItemBaseAttribute() || !m_Material[0]->GetItemBaseAttribute())
		{
			return MSG_ERRO_0287;
		}

		//�жϺϳɶ�������(��������װ��)
		EquipForgeBase* efb = ItemManager::Instance()->GetEquipForgeBase(m_Material[0]->GetItemBaseAttribute()->ID);
		if(!efb)
		{ 
			return MSG_ERRO_0287;
		}

		if(efb->MaterialType==1)  //A_ID��ʯ1,2 Id change
		{
			ForgeBase();
		}
		if(efb->MaterialType==2)//A_�������Ա�ʯ1,2 up lv
		{
			ForgeBaseData();
		}
		if(efb->MaterialType==3)//A_�������Ա�ʯ1,2 up lv
		{
			ForgeAppend();
		}

		Clear();
	}
	else if(type==1)
	{
		for(int i=0;i<6;i++)
		{
			if(!m_Material[i]){return NO_MSG_ERRO;}
			else
			{
				if(!m_Material[i]->GetItemBaseAttribute()){return NO_MSG_ERRO;}
			}
		}

		ForgeMaterial();
	}	
	else if(type==2)
	{
		int Eid[4]={0,3,4,5};

		for(int i=0; i<4; i++)
		{
			if(!m_Equip[ Eid[i] ])
			{return NO_MSG_ERRO;}
			else
			{
				if(!m_Equip[ Eid[i] ]->GetItemBaseAttribute())
				{return NO_MSG_ERRO;}

				if (m_Equip[ Eid[i] ]->BaseLevel <= 0 || m_Equip[ Eid[i] ]->BaseLevel > 5 || m_Equip[ Eid[i] ]->AppLevel <= 0 || m_Equip[ Eid[i] ]->AppLevel > 10 )
				{return NO_MSG_ERRO;}
			}
		}

		ForgeEquip();
	}
	else
	{
		//�ϳ����
		m_Player->AddDanger();
		sbase::LogException("Message type Exception ,Accounts : %s, Role: %s,[_MSG_EUQIPFORGE]", m_Player->GetAccounts(), m_Player->GetName() );
		return NO_MSG_ERRO;
	}

	return NO_MSG_ERRO;
}

void EquipForge::ForgeBase()//id
{
	EquipForgeBase* efb = ItemManager::Instance()->GetEquipForgeBase(m_Equip[0]->GetItemBaseAttribute()->ID);

	//�۳��ɱ�
	int Money=m_Player->GetMoney();

	if(!efb->Amoney.empty())
	{Money-=efb->Amoney[0];}

	m_Player->SetMoney(Money);

	char Ifbuf[128];
	_stprintf(Ifbuf,"�ɱ�:%d ��ǰ:%d",efb->Amoney,m_Player->GetMoney());
	//sbase::ConsoleWriteColorText( FOREGROUND_RED,Ifbuf );

	if(!efb)
	{ 
		return; 
	}

	//��ȡ3��b�౦ʯ��c�����˽��
	EquipForgeBase* efbA,*efbC,*efbB1,*efbB2,*efbB3;
	int ProyAdd[5]={0,0,0,0,0};

	//����ɹ��ʼӳ�
	if(m_Material[1])//�ı�ͷ�
	{
		if(m_Material[1]->GetItemBaseAttribute() != NULL )
		{
			efbC = ItemManager::Instance()->GetEquipForgeBase(m_Material[1]->GetItemBaseAttribute()->ID);
			if(!efbC)
			{ 
				return; 
			}
			ProyAdd[0]=efbC->MaterialProyAdd;
		}

	}
	if(m_Material[2])
	{
		if(m_Material[2]->GetItemBaseAttribute() != NULL )
		{
			efbB1 = ItemManager::Instance()->GetEquipForgeBase(m_Material[2]->GetItemBaseAttribute()->ID);
			if(!efbB1)
			{ 
				return; 
			}
			ProyAdd[1]=efbB1->MaterialProyAdd;
		}
	}
	if(m_Material[3])
	{
		if(m_Material[3]->GetItemBaseAttribute() != NULL )
		{
			efbB2 = ItemManager::Instance()->GetEquipForgeBase(m_Material[3]->GetItemBaseAttribute()->ID);
			if(!efbB2)
			{ 
		
				return; 
			}
			ProyAdd[2]=efbB2->MaterialProyAdd;
		}
	}
	if(m_Material[4])
	{
		if(m_Material[4]->GetItemBaseAttribute() != NULL )
		{
			efbB3 = ItemManager::Instance()->GetEquipForgeBase(m_Material[4]->GetItemBaseAttribute()->ID);
			if(!efbB3)
			{ 

				return; 
			}
			ProyAdd[3]=efbB3->MaterialProyAdd;
		}
	}

	if(m_Material[0])
	{
		if(m_Material[0]->GetItemBaseAttribute() != NULL )
		{
			efbA = ItemManager::Instance()->GetEquipForgeBase(m_Material[0]->GetItemBaseAttribute()->ID);
			if(!efbA)
			{ 
	
				return; 
			}
			ProyAdd[4]=efbA->MaterialProyAdd;
		}
	}

	int Modulus1 = 1,Modulus2 = 1,ForgeOk = 0;
	if(m_Material[0])
	{
		EquipForgeBase* efA = ItemManager::Instance()->GetEquipForgeBase(m_Material[0]->GetItemBaseAttribute()->ID);
		if(!efA)
		{ 
		
			return; 
		}
		if(efA->MaterialType == 1)
		{
			ForgeOk = efb->Probability + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2 + ProyAdd[4];//��ʯ�ɹ���+��
		}
		else if(efA->MaterialType == 2)
		{
			ForgeOk = efb->BaseProyAdd[m_Equip[0]->BaseLevel-1] + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2;//��ʯ�ɹ���+��
		}
		else if(efA->MaterialType == 3)
		{
			ForgeOk = efb->AppendProyAdd[m_Equip[0]->AppLevel-1] + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2;//��ʯ�ɹ���+��
		}
	}

	int rand = sbase::RandGet(100);

	_stprintf(Ifbuf,"�ɹ���:%d,%d",rand,ForgeOk);
	//sbase::ConsoleWriteColorText( FOREGROUND_RED,Ifbuf );

	if (rand < ForgeOk)
	{
		m_Equip[0]->AppLevel-=2;
		m_Equip[0]->BaseLevel--;

		if(m_Equip[0]->AppLevel<1){ m_Equip[0]->AppLevel = 1; }
		if(m_Equip[0]->BaseLevel<1){ m_Equip[0]->BaseLevel = 1; }

		//�ϳ���װ��id
		int Base = efb->NextID;

		//����ԭ��װ����������
		ItemData data = m_Equip[0]->GetItemData();
		data.Base = Base;

		ItemManager::Instance()->CreateItem(&data , m_Equip[0]);

		msg_equipforge.Success = true;
	}
	else
	{
	/*	m_Equip[0]->AppLevel-=2;
		m_Equip[0]->BaseLevel--;

		if(m_Equip[0]->AppLevel<1){ m_Equip[0]->AppLevel = 1; }
		if(m_Equip[0]->BaseLevel<1){ m_Equip[0]->BaseLevel = 1; }

		//�ϳ���װ��id
		int Base = efb->BadID;

		//����ԭ��װ����������
		ItemData data = m_Equip[0]->GetItemData();
		data.Base = Base;

		ItemManager::Instance()->CreateItem(&data , m_Equip[0]);*/

		//ʧ��
		msg_equipforge.Success = false;
	}

	//�Ѱ����Ʒ�����ڽ��н���
	if (m_Material[0]->m_Binding)
		m_Equip[0]->m_Binding = true;

	if (m_Equip[0]->AppLevel == 0)
		m_Equip[0]->AppLevel = 1;

	int NoPunish=0;
	if(m_Material[1] != NULL){NoPunish=1;}

	for(int i=0;i<6;i++)
	{
		if( m_Material[i] != NULL )
		{
			m_Material[i]->m_Overlap--;

			if (m_Material[i]->m_Overlap == 0)
				m_Material[i]->Clear();
			m_Material[i]=NULL;
		}
	}

	if(msg_equipforge.Success == false && !NoPunish )//ʧ�ܳͷ���װ����ʧ
	{
		//ʧ�ܺ�װ����ʧ
		//m_Equip[0]->m_Overlap--;
		//if (m_Equip[0]->m_Overlap == 0)
		//	m_Equip[0]->Clear();

		m_Equip[0]=NULL;
	}

	//������Ϣ
	msg_equipforge.Type=1;
	m_Player->s_World->SendMsgToClient(&msg_equipforge , m_Player->GetSocket());

	//if(msg_equipforge.Success){sbase::ConsoleWriteColorText( FOREGROUND_RED,"***������ID�ɹ�***" );}
	//else{sbase::ConsoleWriteColorText( FOREGROUND_RED,"***������IDʧ��***" );}
}

void EquipForge::ForgeBaseData()
{
	EquipForgeBase* efb = ItemManager::Instance()->GetEquipForgeBase(m_Equip[0]->GetItemBaseAttribute()->ID);

	int Money=m_Player->GetMoney();
	Money-=efb->Bmoney[m_Equip[0]->BaseLevel-1];
	m_Player->SetMoney(Money);

	char Ifbuf[128];
	_stprintf(Ifbuf,"�ɱ�:%d ��ǰ:%d",efb->Bmoney[m_Equip[0]->BaseLevel-1],m_Player->GetMoney());
	//sbase::ConsoleWriteColorText( FOREGROUND_RED,Ifbuf );

	if(!efb)
	{ 
		return; 
	}

	//��ȡ3��b�౦ʯ��c�����˽��
	EquipForgeBase* efbA,*efbC,*efbB1,*efbB2,*efbB3;
	int ProyAdd[5]={0,0,0,0,0};

	if(m_Material[1])//�ı�ͷ�
	{
		if(m_Material[1]->GetItemBaseAttribute() != NULL )
		{
			efbC = ItemManager::Instance()->GetEquipForgeBase(m_Material[1]->GetItemBaseAttribute()->ID);
			if(!efbC)
			{ 
		
				return; 
			}
			ProyAdd[0]=efbC->MaterialProyAdd;
		}
	}
	if(m_Material[2])
	{
		if(m_Material[2]->GetItemBaseAttribute() != NULL )
		{
			efbB1 = ItemManager::Instance()->GetEquipForgeBase(m_Material[2]->GetItemBaseAttribute()->ID);
			if(!efbB1)
			{ 

				return; 
			}
			ProyAdd[1]=efbB1->MaterialProyAdd;
		}
	}
	if(m_Material[3])
	{
		if(m_Material[3]->GetItemBaseAttribute() != NULL )
		{
			efbB2 = ItemManager::Instance()->GetEquipForgeBase(m_Material[3]->GetItemBaseAttribute()->ID);
			if(!efbB2)
			{ 
		
				return; 
			}
			ProyAdd[2]=efbB2->MaterialProyAdd;
		}
	}
	if(m_Material[4])
	{
		if(m_Material[4]->GetItemBaseAttribute() != NULL )
		{
			efbB3 = ItemManager::Instance()->GetEquipForgeBase(m_Material[4]->GetItemBaseAttribute()->ID);
			if(!efbB3)
			{ 

				return; 
			}
			ProyAdd[3]=efbB3->MaterialProyAdd;
		}
	}
	if(m_Material[0])
	{
		if(m_Material[0]->GetItemBaseAttribute() != NULL )
		{
			efbA = ItemManager::Instance()->GetEquipForgeBase(m_Material[0]->GetItemBaseAttribute()->ID);
			if(!efbA)
			{ 
		
				return; 
			}
			ProyAdd[4]=efbA->MaterialProyAdd;
		}
	}

	int Modulus1 = 1,Modulus2 = 1,ForgeOk = 0;
	if(m_Material[0])
	{
		EquipForgeBase* efA = ItemManager::Instance()->GetEquipForgeBase(m_Material[0]->GetItemBaseAttribute()->ID);
		if(!efA)
		{ 
			return; 
		}
		if(efA->MaterialType == 1)
		{
			ForgeOk = efb->Probability + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2 + ProyAdd[4];//��ʯ�ɹ���+��
		}
		else if(efA->MaterialType == 2)
		{
			ForgeOk = efb->BaseProyAdd[m_Equip[0]->BaseLevel-1] + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2 + ProyAdd[4];//��ʯ�ɹ���+��
		}
		else if(efA->MaterialType == 3)
		{
			ForgeOk = efb->AppendProyAdd[m_Equip[0]->AppLevel-1] + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2 + ProyAdd[4];//��ʯ�ɹ���+��
		}
	}

	int rand = sbase::RandGet(100);

	_stprintf(Ifbuf,"�ɹ���:%d,%d",rand,ForgeOk);
	//sbase::ConsoleWriteColorText( FOREGROUND_RED,Ifbuf );

	int NoPunish=0;
	if(m_Material[1] != NULL){NoPunish=1;}

	if (rand < ForgeOk)
	{
		//��������Ʒ��
		if( m_Equip[0]->BaseLevel<5 )
		{ 
			//���ռ���ʹ�û������Եȼ�+1
			//int rand = rand()%100;
			//if (rand < 100){}
			//ʧ�ܳͷ����������Եȼ�����Ϊ��ͼ�
			m_Equip[0]->BaseLevel++; 
		}
		msg_equipforge.Success = true;
	}
	else
	{
		//if(!NoPunish)
		//{m_Equip[0]->BaseLevel=1;}

		msg_equipforge.Success = false;
	}

	if (m_Material[0]->m_Binding)
		m_Equip[0]->m_Binding = true;

	for(int i=0;i<6;i++)
	{
		if( m_Material[i] != NULL )
		{
			m_Material[i]->m_Overlap--;

			if (m_Material[i]->m_Overlap == 0)
				m_Material[i]->Clear();
			m_Material[i]=NULL;
		}
	}

	//������Ϣ
	msg_equipforge.Type=1;
	m_Player->s_World->SendMsgToClient(&msg_equipforge , m_Player->GetSocket());

	//if(msg_equipforge.Success){sbase::ConsoleWriteColorText( FOREGROUND_RED,"***������base�ɹ�***" );}
	//else{sbase::ConsoleWriteColorText( FOREGROUND_RED,"***������baseʧ��***" );}
}

void EquipForge::ForgeAppend()
{
	EquipForgeBase* efb = ItemManager::Instance()->GetEquipForgeBase(m_Equip[0]->GetItemBaseAttribute()->ID);

	int Money=m_Player->GetMoney();
	Money-=efb->Cmoney[m_Equip[0]->AppLevel-1];
	m_Player->SetMoney(Money);

	char Ifbuf[128];
	_stprintf(Ifbuf,"�ɱ�:%d ��ǰ:%d",efb->Cmoney[m_Equip[0]->AppLevel-1],m_Player->GetMoney());
	//sbase::ConsoleWriteColorText( FOREGROUND_RED,Ifbuf );

	if(!efb)
	{ 
		return; 
	}

	//��ȡ3��b�౦ʯ��c�����˽��
	EquipForgeBase* efbA,*efbC,*efbB1,*efbB2,*efbB3;
	int ProyAdd[5]={0,0,0,0,0};

	if(m_Material[1])//�ı�ͷ�
	{
		if(m_Material[1]->GetItemBaseAttribute() != NULL )
		{
			efbC = ItemManager::Instance()->GetEquipForgeBase(m_Material[1]->GetItemBaseAttribute()->ID);
			if(!efbC)
			{ 
				return; 
			}
			ProyAdd[0]=efbC->MaterialProyAdd;
		}
	}
	if(m_Material[2])
	{
		if(m_Material[2]->GetItemBaseAttribute() != NULL )
		{
			efbB1 = ItemManager::Instance()->GetEquipForgeBase(m_Material[2]->GetItemBaseAttribute()->ID);
			if(!efbB1)
			{ 

				return; 
			}
			ProyAdd[1]=efbB1->MaterialProyAdd;
		}
	}
	if(m_Material[3])
	{
		if(m_Material[3]->GetItemBaseAttribute() != NULL )
		{
			efbB2 = ItemManager::Instance()->GetEquipForgeBase(m_Material[3]->GetItemBaseAttribute()->ID);
			if(!efbB2)
			{ 

				return; 
			}
			ProyAdd[2]=efbB2->MaterialProyAdd;
		}
	}
	if(m_Material[4])
	{
		if(m_Material[4]->GetItemBaseAttribute() != NULL )
		{
			efbB3 = ItemManager::Instance()->GetEquipForgeBase(m_Material[4]->GetItemBaseAttribute()->ID);
			if(!efbB3)
			{ 
	
				return; 
			}
			ProyAdd[3]=efbB3->MaterialProyAdd;
		}
	}
	if(m_Material[0])
	{
		if(m_Material[0]->GetItemBaseAttribute() != NULL )
		{
			efbA = ItemManager::Instance()->GetEquipForgeBase(m_Material[0]->GetItemBaseAttribute()->ID);
			if(!efbA)
			{ 

				return; 
			}
			ProyAdd[4]=efbA->MaterialProyAdd;
		}
	}

	int Modulus1 = 1,Modulus2 = 1,ForgeOk = 0;
	if(m_Material[0])
	{
		EquipForgeBase* efA = ItemManager::Instance()->GetEquipForgeBase(m_Material[0]->GetItemBaseAttribute()->ID);
		if(!efA)
		{ 

			return; 
		}
		if(efA->MaterialType == 1)
		{
			ForgeOk = efb->Probability + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2 + ProyAdd[4];//��ʯ�ɹ���+��
		}
		else if(efA->MaterialType == 2)
		{
			ForgeOk = efb->BaseProyAdd[m_Equip[0]->BaseLevel-1] + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2 + ProyAdd[4];//��ʯ�ɹ���+��
		}
		else if(efA->MaterialType == 3)
		{
			ForgeOk = efb->AppendProyAdd[m_Equip[0]->AppLevel-1] + ProyAdd[0] + ProyAdd[1] + ProyAdd[2] * Modulus1 + ProyAdd[3] * Modulus2 + ProyAdd[4];//��ʯ�ɹ���+��
		}
	}

	int rand = sbase::RandGet(100);

	_stprintf(Ifbuf,"�ɹ���:%d,%d",rand,ForgeOk);
	//sbase::ConsoleWriteColorText( FOREGROUND_RED,Ifbuf );

	int NoPunish=0;
	if(m_Material[1] != NULL){NoPunish=1;}

	if (rand < ForgeOk)
	{
		//�ɹ�
		//���ռ���ʹ�û������Եȼ�+1
		//int rand = rand()%100;
		//if (rand < 100){}
		//ʧ�ܳͷ����������Եȼ�����Ϊ��ͼ�
		m_Equip[0]->AppLevel++;

		msg_equipforge.Success = true;
	}
	else
	{
		//ʧ��
		//if(!NoPunish)
		//{m_Equip[0]->AppLevel = 1;}

		msg_equipforge.Success = false;
	}

	if (m_Material[0]->m_Binding)
		m_Equip[0]->m_Binding = true;

	for(int i=0;i<6;i++)
	{
		if( m_Material[i] != NULL )
		{
			m_Material[i]->m_Overlap--;

			if (m_Material[i]->m_Overlap == 0)
				m_Material[i]->Clear();
			m_Material[i]=NULL;
		}
	}

	//������Ϣ
	msg_equipforge.Type=1;
	m_Player->s_World->SendMsgToClient(&msg_equipforge , m_Player->GetSocket());
	
	//if(msg_equipforge.Success){sbase::ConsoleWriteColorText( FOREGROUND_RED,"***������app�ɹ�***" );}
	//else{sbase::ConsoleWriteColorText( FOREGROUND_RED,"***������appʧ��***" );}
}


void EquipForge::ForgeMaterial()
{
	int Binding=0;
	for(int i=0;i<6;i++)
	{
		if(m_Material[i])
		{
			if (m_Material[i]->m_Binding>0){ Binding=1; }
		}
	}

	Item m_TempMaterial=*m_Material[0];

	if(!m_TempMaterial.GetItemBaseAttribute())
	{		
		return;
	}

	EquipForgeBase* efb = ItemManager::Instance()->GetEquipForgeBase(m_TempMaterial.GetItemBaseAttribute()->ID);
	if(!efb)
	{ 
		return; 
	}

	//�ϳɳ��±�ʯ
	int Base = efb->NextID;//Ϊ0�Ͳ��ܺϳ�

	ItemData data = m_TempMaterial.GetItemData();

	data = m_TempMaterial.GetItemData();
	data.Base = Base;
	data.Overlap = 1;
	ItemManager::Instance()->CreateItem(&data , &m_TempMaterial);

	if(Binding > 0 ){m_TempMaterial.m_Binding=true;}

	m_Player->AddItem(&m_TempMaterial);

	if (m_TempMaterial.BaseLevel == 0)
	{ m_TempMaterial.BaseLevel = 1; }

	//m_Forge = &m_TempMaterial;

	for(int i=0;i<6;i++)
	{
		if( m_Material[i] != NULL )
		{
			//m_Material[i]->m_ItemState = Item::Idle;
			m_Material[i]->m_Overlap--;

			if (m_Material[i]->m_Overlap == 0)
				m_Material[i]->Clear();
			m_Material[i]=NULL;
		}
	}

	//������Ϣ
	msg_equipforge.Success = true;
	msg_equipforge.Type=2;
	m_Player->s_World->SendMsgToClient(&msg_equipforge , m_Player->GetSocket());

	//if(msg_equipforge.Success){sbase::ConsoleWriteColorText( FOREGROUND_RED,"***��ʯ�ϳɳɹ�***" );}
	//else{sbase::ConsoleWriteColorText( FOREGROUND_RED,"***��ʯ�ϳ�ʧ��***" );}
}

void EquipForge::ForgeEquip()
{
	EquipForgeBase* efb = ItemManager::Instance()->GetEquipForgeBase(m_Equip[0]->GetItemBaseAttribute()->ID);
	if(!efb)
	{ 
		return; 
	}
	ItemData data = m_Equip[0]->GetItemData();
	int Binding=0;
	if (m_Equip[0]->m_Binding){ Binding=0; }
 
	//�������Ը���	(G1+G2+G3+G4)/4
	//�����ϳɷ����װ���������Ը����ֱ�Ϊ:5��3��2��4;����װ����Ʒ��ϵ��Ϊ(5+3+2+4)/4��3.5������װ���ĸ������Ը�����50���ļ���Ϊ3����50���ļ���Ϊ4����
	int AppNum[4] = {0,0,0,0};
	int AppNumEnd = 0;
	ItemAppendAttribute *attribute = NULL;
	for (int i=0; i<MAX_EQUIPAPPEND_COUNT ; i++)
	{
		attribute = NULL;
		attribute = m_Equip[0]->GetItemAppendAttribute( i );
		if ( attribute != NULL )
		{
			AppNum[0] ++;
			attribute = NULL;
		}

		if( m_Equip[3] != NULL )
		{
			attribute = NULL;
			attribute = m_Equip[3]->GetItemAppendAttribute( i );
			if ( attribute != NULL )
			{
				AppNum[1] ++;
			}
		}
		else{return;}

		if( m_Equip[4] != NULL )
		{
			attribute = NULL;
			attribute = m_Equip[4]->GetItemAppendAttribute( i );
			if ( attribute != NULL )
			{
				AppNum[2] ++;
			}
		}
		else{return;}

		if( m_Equip[5] != NULL )
		{
			attribute = NULL;
			attribute = m_Equip[5]->GetItemAppendAttribute( i );
			if ( attribute != NULL )
			{
				AppNum[3] ++;
			}
		}else{return;}
	}

	float AppNumEndf =(AppNum[0] + AppNum[1] + AppNum[2] + AppNum[3] + 1 )*1.0f / 4;
	if( AppNumEndf > 4 ){ AppNumEndf = 4 ;}

	AppNumEnd = (AppNum[0] + AppNum[1] + AppNum[2] + AppNum[3] + 1 )/4;
	if( AppNumEnd > 4 ){ AppNumEndf = 4 ;}

	int Spare = (AppNumEndf - AppNumEnd)*10;

	int rand = sbase::RandGet(9);
	if(rand < Spare){ AppNumEnd++; }

	char Ifbuf[128];
	_stprintf(Ifbuf,"rand:%d < Spare:%d c������:(%d+%d+%d+%d)/4=%d rand:%d Spare:%d",rand,Spare,AppNum[0],AppNum[1],AppNum[2],AppNum[3],AppNumEnd,rand,Spare);

	m_Equip[0]->ClearAppendAttribute();

	//�ϳɳ��µ�װ����������
	ItemManager::Instance()->CreateItemAppend(m_Equip[0],AppNumEnd);

	//��װ����Ʒ��	(P1+P2+P3+P4)/4
	float TlvF =( m_Equip[0]->BaseLevel + m_Equip[3]->BaseLevel + m_Equip[4]->BaseLevel + m_Equip[5]->BaseLevel +1)*1.0f /4;
	int   TlvI = ( m_Equip[0]->BaseLevel + m_Equip[3]->BaseLevel + m_Equip[4]->BaseLevel + m_Equip[5]->BaseLevel +1)*1.0f /4;
	int   TlvSpare1 = (TlvF - TlvI)*10;
	int   Tlvrand1 = sbase::RandGet(9);
	if(Tlvrand1 < TlvSpare1){ TlvI++; }

	m_Equip[0]->BaseLevel = TlvI;

	TlvF =( m_Equip[0]->AppLevel + m_Equip[3]->AppLevel + m_Equip[4]->AppLevel + m_Equip[5]->AppLevel +1)*1.0f /4;
	TlvI = ( m_Equip[0]->AppLevel + m_Equip[3]->AppLevel + m_Equip[4]->AppLevel + m_Equip[5]->AppLevel +1)*1.0f /4;
	int   TlvSpare2 = (TlvF - TlvI)*10;
	int   Tlvrand2 = sbase::RandGet(9);
	if(Tlvrand2 < TlvSpare2){ TlvI++; }

	m_Equip[0]->AppLevel = TlvI;

	if(m_Equip[0]->BaseLevel < 1 ){ m_Equip[0]->BaseLevel = 1;}
	else if(m_Equip[0]->BaseLevel > 5 ){ m_Equip[0]->BaseLevel = 5;}

	if(m_Equip[0]->AppLevel < 1 ){ m_Equip[0]->AppLevel = 1;}
	else if(m_Equip[0]->AppLevel > 10 ){ m_Equip[0]->AppLevel = 10;}


	msg_equipforge.BaseLv=m_Equip[0]->BaseLevel;
	msg_equipforge.AppLv=m_Equip[0]->AppLevel;

	_stprintf(Ifbuf,"BaseLv:%d AppLv:%d Tlvrand1:%d<TlvSpare1:%d Tlvrand2:%d<TlvSpare2:%d",m_Equip[0]->BaseLevel,m_Equip[0]->AppLevel,Tlvrand1,TlvSpare1,Tlvrand2,TlvSpare2);

	//���ù���װ���Ͳ��ܽ���
	if (Binding>0)
	{
		m_Equip[0]->m_Binding = true;
	}

	data = m_Equip[0]->GetItemData();
	//ItemManager::Instance()->CreateItem(&data , m_Equip[0]);

	//���ϳɵ�ͼ��ŵ��ϳɽ��ͼλ��
	//m_Forge = m_Equip[0];
	m_Equip[0] = NULL;

	for(int i=0;i<6;i++)
	{
		if( m_Equip[i] != NULL )
		{
			m_Equip[i]->m_Overlap--;
			if (m_Equip[i]->m_Overlap == 0)
				m_Equip[i]->Clear();
			m_Equip[i]=NULL;
		}
	}

	//������Ϣ
	msg_equipforge.AppId[0] = data.Append[0];
	msg_equipforge.AppId[1] = data.Append[1];
	msg_equipforge.AppId[2] = data.Append[2];
	msg_equipforge.AppId[3] = data.Append[3];
	msg_equipforge.AppId[4] = data.Append[4];
	msg_equipforge.Success = true;
	msg_equipforge.Type=3;
	m_Player->s_World->SendMsgToClient(&msg_equipforge , m_Player->GetSocket());

	//if(msg_equipforge.Success){sbase::ConsoleWriteColorText( FOREGROUND_RED,"***װ���ϳɳɹ�***" );}
	//else{sbase::ConsoleWriteColorText( FOREGROUND_RED,"***װ���ϳ�ʧ��***" );}

	_stprintf(Ifbuf,"����Id:%d,%d,%d,%d,%d",data.Append[0],data.Append[1],data.Append[2],data.Append[3],data.Append[4]);


}
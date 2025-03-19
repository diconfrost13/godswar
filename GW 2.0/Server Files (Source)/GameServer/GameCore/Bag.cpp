#include "stdafx.h"
#include "Bag.h"
#include "Item.h"
#include "Storage.h"


Bag::Bag()
:	m_Active(false)
{
}

Bag::~Bag()
{
}

int Bag::UseQuestItem(int questid)
{
	if (!m_Active)
		return -1;

	for (int i = 0 ; i < MAX_BAG_GRID ; i++)
	{
		if (!m_Grids[i].IsClear() && !m_Grids[i].m_Lock)
		{
			if (m_Grids[i].GetItemBaseAttribute()->QuestID == questid)
			{
				if ((--m_Grids[i].m_Overlap) == 0)
					m_Grids[i].Clear();
				return i;
			}
		}
	}

	return -1;
}

int Bag::GetItemFreeOverlap(Item* item)
{
	if (!m_Active)
		return 0;

	int num = 0;

	for (int i = 0 ; i < MAX_BAG_GRID ; i++)
	{
		if (!m_Grids[i].IsClear() && !m_Grids[i].m_Lock)
		{
			if (m_Grids[i].GetItemBaseAttribute()->ID == item->GetItemBaseAttribute()->ID && m_Grids[i].m_Binding == item->m_Binding)
				if (m_Grids[i].GetItemBaseAttribute()->Overlap > m_Grids[i].m_Overlap)
				{
					num = m_Grids[i].GetItemBaseAttribute()->Overlap - m_Grids[i].m_Overlap;
				}
		}
	}

	return num;
}

void Bag::Clear()
{
	for (int i = 0 ; i < MAX_BAG_GRID ; i++)
		m_Grids[i].Clear();
}

Item* Bag::GetItem(int index)
{
	if (!m_Active)
		return NULL;

	if (index >= MAX_BAG_GRID || index < 0)
	{
		//外挂

		return NULL;
	}

	return &m_Grids[index];
}

Item* Bag::GetEmptyItem()
{
	if (!m_Active)
		return NULL;

	for (int i = 0 ; i < MAX_BAG_GRID ; i++)
	{
		if (m_Grids[i].IsClear())
			return &m_Grids[i];
	}

	return NULL;
}

bool Bag::GetActive() const
{
	return m_Active;
}

void Bag::SetActive(bool b)
{
	m_Active = b;
}

bool Bag::IsEmpty(int index)
{
#ifdef _DEBUG
	ASSERT(index < MAX_BAG_GRID);
#else
	if (index >= MAX_BAG_GRID || index < 0)
	{
		//外掛

		return false;
	}
#endif

	return m_Grids[index].IsClear();
}

bool Bag::Push(Item* p)
{
	if (p->IsClear())
		return false;

	if (!m_Active)
		return false;

	//如果是不重叠的,
	if (p->GetItemBaseAttribute()->Overlap == 1)
	{
		for (int i = 0 ; i < MAX_BAG_GRID ; i++)
		{
			if (m_Grids[i].IsClear())
			{
				//值复制,
				m_Grids[i] = *p;

				return true;
			}
		}

		return false;
	}

	//重叠的,只允许掉落个数是1的,
	for (int i = 0 ; i < MAX_BAG_GRID ; i++)
	{
		if (!m_Grids[i].IsClear())
		{
			if (m_Grids[i].GetItemBaseAttribute()->ID == p->GetItemBaseAttribute()->ID &&
				!m_Grids[i].m_Lock &&
				m_Grids[i].m_Binding == p->m_Binding)
				if (m_Grids[i].GetItemBaseAttribute()->Overlap > m_Grids[i].m_Overlap)
				{
					if (m_Grids[i].m_Overlap + p->m_Overlap > m_Grids[i].GetItemBaseAttribute()->Overlap)
					{
						p->m_Overlap = m_Grids[i].m_Overlap + p->m_Overlap - m_Grids[i].GetItemBaseAttribute()->Overlap;

						m_Grids[i].m_Overlap = m_Grids[i].GetItemBaseAttribute()->Overlap;

						continue;
					}
					else
						m_Grids[i].m_Overlap = m_Grids[i].m_Overlap + p->m_Overlap;

					return true;
				}
		}

	}

	for (int i = 0 ; i < MAX_BAG_GRID ; i++)
	{
		if (m_Grids[i].IsClear())
		{
			if (p->m_Overlap > p->GetItemBaseAttribute()->Overlap)
			{
				p->m_Overlap -= p->GetItemBaseAttribute()->Overlap;
				m_Grids[i] = *p;
				m_Grids[i].m_Overlap = p->GetItemBaseAttribute()->Overlap;
				continue;
			}
			else
			{
				//值复制,
				m_Grids[i] = *p;
			}

			return true;
		}
	}

	return false;
}

bool Bag::Push(Item* p , int index)
{
#ifdef _DEBUG
	if (index >= MAX_BAG_GRID || !p)
		ASSERT(0);
#else
	if (index >= MAX_BAG_GRID || !p || index < 0)
	{
		//外掛

		return false;
	}
#endif

	if (!m_Active)
		return false;

	//值复制,
	m_Grids[index] = *p;

	return true;
}

bool Bag::Erase(int index)
{
	if (!m_Active)
		return false;

#ifdef _DEBUG
	if (index >= MAX_BAG_GRID)
		ASSERT(0);
#else
	if (index >= MAX_BAG_GRID || index < 0)
	{
		//外掛

		return false;
	}
#endif

	if (!m_Active)
		return false;

	if (m_Grids[index].m_Lock)
		return false;

	m_Grids[index].Clear();

	return true;
}
//物品的互换，叠加，拆分
bool Bag::Move(Bag* other , int index , int otherindex/*,int overlay*/)
{
#ifdef _DEBUG
	if (index >= MAX_BAG_GRID || otherindex >= MAX_BAG_GRID || !other)
		ASSERT(0);
#else
	if (index >= MAX_BAG_GRID || otherindex >= MAX_BAG_GRID || !other ||
		index < 0 || otherindex < 0)
	{
		//外掛

		return false;
	}
#endif

	if (!m_Active)
		return false;


	if (other == this && index == otherindex)
		return false;

	if (!m_Grids[index].IsClear())
		if (m_Grids[index].m_Lock)
			return false;

	if (!other->m_Grids[otherindex].IsClear())
		if (other->m_Grids[otherindex].m_Lock)
			return false;

	if (!m_Grids[index].IsClear()
		&&!other->m_Grids[otherindex].IsClear())
	{
		//物品的叠加
		if (m_Grids[index].GetItemBaseAttribute()->ID == other->m_Grids[otherindex].GetItemBaseAttribute()->ID
			&& m_Grids[index].m_Binding == other->m_Grids[otherindex].m_Binding 
			&&m_Grids[index].GetItemBaseAttribute()->Overlap > 1
			&& other->m_Grids[otherindex].GetItemBaseAttribute()->Overlap > 1)
		{
			int allOverlay = m_Grids[index].m_Overlap + other->m_Grids[otherindex].m_Overlap;
			//合并为一个物品
			if( allOverlay <= m_Grids[index].GetItemBaseAttribute()->Overlap)
			{
				other->m_Grids[otherindex]=m_Grids[index];
				other->m_Grids[otherindex].m_Overlap=allOverlay;
				m_Grids[index].Clear();
			}
			//2个物品
			else
			{
				m_Grids[index].m_Overlap=allOverlay-m_Grids[index].GetItemBaseAttribute()->Overlap;
				other->m_Grids[otherindex]=m_Grids[index];
				other->m_Grids[otherindex].m_Overlap=m_Grids[index].GetItemBaseAttribute()->Overlap;
			}
		} 
		else
		{
			//物品位置的互换
			Item temp = m_Grids[index];
			m_Grids[index] = other->m_Grids[otherindex];
			other->m_Grids[otherindex] = temp;

		}
	}
	//物品位置的互换
	else
	{
		Item temp = m_Grids[index];
		m_Grids[index] = other->m_Grids[otherindex];
		other->m_Grids[otherindex] = temp;
	}

	return true;
}
//物品的拆分
bool Bag::Break(Bag* other , int index , int otherindex,int overlay)
{
#ifdef _DEBUG
	if (index >= MAX_BAG_GRID || otherindex >= MAX_BAG_GRID || !other)
		ASSERT(0);
#else
	if (index >= MAX_BAG_GRID || otherindex >= MAX_BAG_GRID || !other ||
		index < 0 || otherindex < 0)
	{
		//外掛

		return false;
	}
#endif

	if (!m_Active)
		return false;


	if (other == this && index == otherindex)
		return false;

	//if (!m_Grids[index].IsClear())
	//	if (m_Grids[index].m_Lock)
	//		return false;

	if (!other->m_Grids[otherindex].IsClear())
		//if (other->m_Grids[otherindex].m_Lock)
		return false;

	//物品的拆分tavia
	if ( overlay < m_Grids[index].m_Overlap && m_Grids[index].m_Overlap-overlay > 0)
	{	
		//判断目标格子是否被用了。如果被占有了，就不执行操作。tavia
		if (!other->m_Grids[otherindex].IsClear())
		{
			return false;

		}//endif 
		else
		{
			if (m_Grids[index].m_Lock)
			{
				m_Grids[index].m_Lock = false;
			}//endif
			m_Grids[index].m_Overlap-=overlay;
			other->m_Grids[otherindex]=m_Grids[index];
			other->m_Grids[otherindex].m_Overlap=overlay;

		}//endelse
	}
	else
	{
		//外掛
		return false;

	}


	return true;
}
//交换
bool Bag::Move(Storage* storage , int index , int storageindex)
{
	if (!m_Active)
		return false;

	if (index < 0 || index >= MAX_BAG_GRID)
		return false;

	if (storageindex < 0 || storageindex >= storage->GetActive())
		return false;

	if (m_Grids[index].IsClear())
		return false;

	if (m_Grids[index].m_Lock)
	{
		//ASSERT(0);
		return false;
	}

	Item item = *storage->GetItem(storageindex);
	storage->SetItem(&m_Grids[index] , storageindex);
	m_Grids[index] = item;

	return true;
}

//移动
bool Bag::MoveBag(Storage* storage , int index,int CurNum)
{
	if (!m_Active)
		return false;

	if (index < 0 || index >= MAX_BAG_GRID)
		return false;

	if (m_Grids[index].IsClear())
		return false;

	if (m_Grids[index].m_Lock)
		return false;

	if (storage->GetItemFreeOverlap(&m_Grids[index]) == 0)
		return false;

	int Full = 0;
	int CmpId = 0;
	for (int i = 0 ; i < CurNum; i++)
	{	
		if (storage->GetItem(i))
		{ 
			if( storage->GetItem(i)->GetItemBaseAttribute()!=NULL )
			{ 
				if(storage->GetItem(i)->GetItemBaseAttribute()->ID == m_Grids[index].GetItemBaseAttribute()->ID)
				{
					CmpId = 1; 
				}
				Full++;
			}
		}
	}

	if(Full == CurNum && !CmpId)
	{
		return false;
	}

	for (int i = 0 ; i < CurNum; i++)//MAX_STORAGE_GRID
	{
		if (!storage->GetItem(i))
			continue;

		if (storage->GetItem(i)->IsClear())
		{
			storage->SetItem(&m_Grids[index] , i);
			m_Grids[index].Clear();

			return true;
		}
		else if (storage->GetItem(i)->Push(&m_Grids[index]))
		{

			return true;
		}
	}

	return true;
}
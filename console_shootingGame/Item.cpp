#include "stdafx.h"
#include "Item.h"

CItem::CItem()
{

}
CItem::~CItem()
{

}

CItem::CItem(int i_nX, int i_nY)
{
	m_dX = i_nX;
	m_dY = i_nY;
}

void CItem::Initialize()
{

}
void CItem::Draw()
{
	MYDRAW(m_dX, m_dY, "бс");
}

void CItem::Update()
{
	//m_dY -= 0.1;
	if (!ColScreenToPoint({ m_dX, m_dY }))
	{
		m_IsAlive = false;
	}
}

int CItem::MsgProc()
{
	return -1;
}
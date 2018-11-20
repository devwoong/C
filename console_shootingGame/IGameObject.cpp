#include "stdafx.h"
#include "IGameObject.h"


IGameObject::IGameObject()
{
}


IGameObject::~IGameObject()
{
}

POINT IGameObject::GetPos()
{
	POINT retPos = { floor(m_dX), floor(m_dY) };
	return retPos;
}
RECT* IGameObject::GetColisionArea()
{
	return m_rtColisionArea;
}

int IGameObject::GetType()
{
	return m_nType;
}
int IGameObject::GetAreaSize()
{
	return m_nAreaSize;
}
bool IGameObject::IsAlive()
{
	return m_IsAlive;
}
void IGameObject::KillObject()
{
	m_IsAlive = false;
}
#include "stdafx.h"
#include "Pattern1.h"


CPattern1::CPattern1()
{
}


CPattern1::~CPattern1()
{
}
CPattern1::CPattern1(double* i_nX, double* i_nY, double i_dSpeed)
{
	m_dX = i_nX;
	m_dY = i_nY;
	m_dSpeed = i_dSpeed;
	m_dAngle = 45 * PI / 180;
	m_nShootTiming = 2000;
}

void CPattern1::Initialize()
{

}

int CPattern1::MsgProc()
{
	if (GetTickCount() - m_nShootTimeCurrent > m_nShootTiming)
	{
		m_nShootTimeCurrent = GetTickCount();
		return GAMEOBJECT_ENEMYBULLET1;
	}
	return -1;
}

void CPattern1::Update()
{
	*m_dX = *m_dX + (cos(m_dAngle) * m_dSpeed);
	*m_dY = *m_dY + (sin(m_dAngle) * m_dSpeed);
}
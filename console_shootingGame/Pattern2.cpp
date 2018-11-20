#include "stdafx.h"
#include "Pattern2.h"


CPattern2::CPattern2()
{
}


CPattern2::~CPattern2()
{
}

CPattern2::CPattern2(double* i_nX, double* i_nY, double i_dSpeed)
{
	m_dX = i_nX;
	m_dY = i_nY;
	m_dSpeed = i_dSpeed;
	m_dAngle = 0 * PI / 180;
	m_nShootTiming = 2000;
}

void CPattern2::Initialize()
{

}

int CPattern2::MsgProc()
{
	if (GetTickCount() - m_nShootTimeCurrent > m_nShootTiming)
	{
		m_nShootTimeCurrent = GetTickCount();
		return GAMEOBJECT_ENEMYBULLET2;
	}
	return -1;
}

void CPattern2::Update()
{
	*m_dX = *m_dX + (cos(m_dAngle) * m_dSpeed);
	*m_dY = *m_dY + (sin(m_dAngle) * m_dSpeed);
}
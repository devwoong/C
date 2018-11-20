#include "stdafx.h"
#include "Pattern3.h"


CPattern3::CPattern3()
{
}


CPattern3::~CPattern3()
{
}

CPattern3::CPattern3(double* i_nX, double* i_nY, double i_dSpeed)
{
	m_dX = i_nX;
	m_dY = i_nY;
	m_dSpeed = i_dSpeed;
	m_dAngle = 180 * PI / 180;
	m_nShootTiming = 2000;
}

void CPattern3::Initialize()
{

}

int CPattern3::MsgProc()
{
	if (GetTickCount() - m_nShootTimeCurrent > m_nShootTiming)
	{
		m_nShootTimeCurrent = GetTickCount();
		return GAMEOBJECT_ENEMYBULLET2;
	}
	return -1;
}

void CPattern3::Update()
{
	*m_dX = *m_dX + (cos(m_dAngle) * m_dSpeed);
	*m_dY = *m_dY + (sin(m_dAngle) * m_dSpeed);
}
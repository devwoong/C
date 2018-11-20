#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(int nX, int nY)
{
	m_ptPosition.x = nX;
	m_ptPosition.y = nY;
	m_dX = nX;
	m_dY = nY;
	m_IsAlive = true;
	this->Initialize();
}
void CPlayer::Initialize()
{
	m_dX = 50;
	m_dY = 50;
	m_IsAlive = true;
	m_nBulletNum = 1;
	m_nType = GAMEOBJECT_PLAYER;
}
void CPlayer::Draw()
{
	if ( m_IsAlive == true)
		MYDRAW(m_dX, m_dY, "¡ß");
}
void CPlayer::Update()
{

}
int CPlayer::MsgProc()
{
	if (kbhit())
	{
		if( GetAsyncKeyState(VK_UP) & 0x8000 )
		{
			m_dY -= 0.3;
			m_ptPosition.y -= 1;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_dY += 0.3;
			m_ptPosition.y += 1;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			m_dX -= 0.5;
			m_ptPosition.x -= 1;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			m_dX += 0.5;
			m_ptPosition.x += 1;
		}
		else if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			return GAMEOBJECT_PLAYERBULLET;
		}
		else if (GetAsyncKeyState('1') & 0x8000)
			this->Initialize();
		else if (GetAsyncKeyState('2') & 0x8000)
			this->BulletAdd();
		else if (GetAsyncKeyState('3') & 0x8000)
			m_nBulletNum = 1;
	}
	return -1;
}
int  CPlayer::GetBulletNum()
{
	return m_nBulletNum;
}
void CPlayer::BulletAdd()
{
	if (m_nBulletNum > 8) return;
	m_nBulletNum++;
}
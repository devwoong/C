#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{
	SAFE_DELETE(m_PatternObject);
}

CEnemy::CEnemy(int i_nX, int i_nY, int i_nType)
{
	srand((unsigned int)time(NULL));
	m_dX = i_nX;
	m_dY = i_nY;
	m_dSpeed = 0.1;
	this->CreatePattern(i_nType);
	m_IsAlive = true;
}

void CEnemy::Initialize()
{
}
void CEnemy::Draw()
{
	MYDRAW(m_dX, m_dY, "¡Ú");
}
void CEnemy::Update()
{
	if (!ColScreenToPoint({ m_dX, m_dY }))
	{
		m_IsAlive = false;
	}
	else
	{
		m_PatternObject->Update();
	}

}

int CEnemy::MsgProc()
{
	if (ColScreenToPoint({ m_dX, m_dY }))
	{
		if (m_IsAlive == false)
		{
			if( rand()%7 == 0 ) 
				return GAMEOBJECT_ITEM;
		}
		else
			return m_PatternObject->MsgProc();
	}
	return -1;
}

void CEnemy::CreatePattern(int i_nType)
{
	switch (i_nType)
	{
	case GAMEOBJECT_ENEMY1:
		m_PatternObject = new CPattern1(&m_dX, &m_dY, m_dSpeed);
		break;
	case GAMEOBJECT_ENEMY2:
		m_PatternObject = new CPattern2(&m_dX, &m_dY, m_dSpeed);
		break;
	case GAMEOBJECT_ENEMY3:
		m_PatternObject = new CPattern3(&m_dX, &m_dY, m_dSpeed);
		break;
	}
}
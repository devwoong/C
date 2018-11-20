#include "stdafx.h"
#include "GameObjectManager.h"


CGameObjectManager::CGameObjectManager()
{
}


CGameObjectManager::~CGameObjectManager()
{
	GameObjectIter iter = m_EnemyList.begin();
	GameObjectIter iterEnd = m_EnemyList.end();
	while (iter != iterEnd)
	{
		SAFE_DELETE((*iter));
		iter++;
	}
	m_EnemyList.clear();

	iter = m_PlayerBulletList.begin();
	iterEnd = m_PlayerBulletList.end();
	while (iter != iterEnd)
	{
		SAFE_DELETE((*iter));
		iter++;
	}
	m_PlayerBulletList.clear();

	iter = m_EnemyBulletList.begin();
	iterEnd = m_EnemyBulletList.end();
	while (iter != iterEnd)
	{
		SAFE_DELETE((*iter));
		iter++;
	}
	m_EnemyBulletList.clear();

	iter = m_ItemList.begin();
	iterEnd = m_ItemList.end();
	while (iter != iterEnd)
	{
		SAFE_DELETE((*iter));
		iter++;
	}
	m_EnemyBulletList.clear();
	SAFE_DELETE(m_Player);
}

void CGameObjectManager::Initialize()
{
	m_Player = new CPlayer(50,50);
	m_Player->Initialize();
}
void CGameObjectManager::Update()
{
	m_Player->Update();
	GameObjectIter iter = m_EnemyList.begin();
	GameObjectIter iterEnd = m_EnemyList.end();
	while (iter != iterEnd)
	{
		if ((*iter)->IsAlive() == false)
		{
			IGameObject* Remove = (*iter);
			iter++;
			m_EnemyList.remove(Remove);
			SAFE_DELETE(Remove);
			continue;
		}
		(*iter)->Update();
		int nMsg = (*iter)->MsgProc();
		if (nMsg != -1) 
			this->Factory(nMsg, (*iter)->GetPos().x, (*iter)->GetPos().y);
		iter++;
	}

	iter = m_PlayerBulletList.begin();
	iterEnd = m_PlayerBulletList.end();
	while (iter != iterEnd)
	{
		if ((*iter)->IsAlive() == false)
		{
			IGameObject* Remove = (*iter);
			iter++;
			m_PlayerBulletList.remove(Remove);
			SAFE_DELETE(Remove);
			continue;
		}
		(*iter)->Update();
		iter++;
	}
	iter = m_ItemList.begin();
	iterEnd = m_ItemList.end();
	while (iter != iterEnd)
	{
		if ((*iter)->IsAlive() == false)
		{
			IGameObject* Remove = (*iter);
			iter++;
			m_ItemList.remove(Remove);
			SAFE_DELETE(Remove);
			continue;
		}
		(*iter)->Update();
		iter++;
	}
	iter = m_EnemyBulletList.begin();
	iterEnd = m_EnemyBulletList.end();
	while (iter != iterEnd)
	{
		if ((*iter)->IsAlive() == false)
		{
			IGameObject* Remove = (*iter);
			iter++;
			m_EnemyBulletList.remove(Remove);
			SAFE_DELETE(Remove);
			continue;
		}
		(*iter)->Update();
		iter++;
	}

	iter = m_ItemList.begin();
	iterEnd = m_ItemList.end();
	while (iter != iterEnd)
	{
		if ((*iter)->IsAlive() == false)
		{
			IGameObject* Remove = (*iter);
			iter++;
			m_ItemList.remove(Remove);
			SAFE_DELETE(Remove);
			continue;
		}
		(*iter)->Update();
		iter++;
	}
	
	this->ColisionCheck();
}

void CGameObjectManager::ColisionCheck()
{
	GameObjectIter iterEnemy = m_EnemyList.begin();
	GameObjectIter iterEndEnemy = m_EnemyList.end();
	while (iterEnemy != iterEndEnemy)
	{
		GameObjectIter iterPlayerBullet = m_PlayerBulletList.begin();
		GameObjectIter iterEndPlayerBullet = m_PlayerBulletList.end();
		while (iterPlayerBullet != iterEndPlayerBullet)
		{
			if (ColPointToPoint((*iterPlayerBullet)->GetPos(), (*iterEnemy)->GetPos()))
			{
  				(*iterEnemy)->KillObject();
			}
			iterPlayerBullet++;
		}
		iterEnemy++;
	}
	GameObjectIter iterEnemyBullet = m_EnemyBulletList.begin();
	GameObjectIter iterEndEnemyBullet = m_EnemyBulletList.end();
	while (iterEnemyBullet != iterEndEnemyBullet)
	{
		if (ColPointToPoint((*iterEnemyBullet)->GetPos(), m_Player->GetPos()))
		{
 			(*iterEnemyBullet)->KillObject();
			m_Player->KillObject();
		}
		iterEnemyBullet++;
	}

	GameObjectIter iterItem = m_ItemList.begin();
	GameObjectIter iterItemEnd = m_ItemList.end();
	while (iterItem != iterItemEnd)
	{
		if (ColPointToPoint2((*iterItem)->GetPos(), m_Player->GetPos()))
		{
			m_Player->BulletAdd();
			(*iterItem)->KillObject();
		}
		iterItem++;
	}

}
void CGameObjectManager::Draw()
{
	GameObjectIter iter = m_EnemyList.begin();
	GameObjectIter iterEnd = m_EnemyList.end();
	while (iter != iterEnd)
	{
		(*iter)->Draw();
		iter++;
	}

	iter = m_PlayerBulletList.begin();
	iterEnd = m_PlayerBulletList.end();
	while (iter != iterEnd)
	{
		(*iter)->Draw();
		iter++;
	}

	iter = m_EnemyBulletList.begin();
	iterEnd = m_EnemyBulletList.end();
	while (iter != iterEnd)
	{
		(*iter)->Draw();
		iter++;
	}

	iter = m_ItemList.begin();
	iterEnd = m_ItemList.end();
	while (iter != iterEnd)
	{
		(*iter)->Draw();
		iter++;
	}
	m_Player->Draw();

}
int CGameObjectManager::Input()
{
	this->Factory(m_Player->MsgProc(), m_Player->GetPos().x, m_Player->GetPos().y);
	GameObjectIter iter = m_EnemyList.begin();
	GameObjectIter iterEnd = m_EnemyList.end();
	while (iter != iterEnd)
	{
		int nMsg = (*iter)->MsgProc();
		if (nMsg != -1)
			this->Factory(nMsg, (*iter)->GetPos().x, (*iter)->GetPos().y);
		iter++;
	}
	return 1;
}

bool CGameObjectManager::Factory(int i_nAddType, int i_nX, int i_nY, double i_dAngle)
{
	switch (i_nAddType)
	{
	case GAMEOBJECT_PLAYER:
		break;
	case GAMEOBJECT_ENEMY1:
		m_EnemyList.push_back(new CEnemy(i_nX, i_nY, i_nAddType) );
		break;
	case GAMEOBJECT_ENEMY2:
		m_EnemyList.push_back(new CEnemy(i_nX, i_nY, i_nAddType));
		break;
	case GAMEOBJECT_ENEMY3:
		m_EnemyList.push_back(new CEnemy(i_nX, i_nY, i_nAddType));
		break;
	case GAMEOBJECT_PLAYERBULLET:
		for( int i = 0 ; i<m_Player->GetBulletNum(); i++)
  			m_PlayerBulletList.push_back(new CBullet(i_nX + i, i_nY));
		break;
	case GAMEOBJECT_ENEMYBULLET1:
		m_EnemyBulletList.push_back(new CBullet(i_nX, i_nY, m_Player->GetPos().x, m_Player->GetPos().y));
		break;
	case GAMEOBJECT_ENEMYBULLET2:
		m_EnemyBulletList.push_back(new CBullet(i_nX, i_nY, -90));
		break;
	case GAMEOBJECT_ITEM:
		m_ItemList.push_back(new CItem(i_nX, i_nY));
		break;
	}
	return true;
}
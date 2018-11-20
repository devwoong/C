#pragma once
#include "Player.h"
#include "Enemy.h"
#include <list>
#include "Bullet.h"
#include "Item.h"
class CGameObjectManager
{
public:
	CGameObjectManager();
	~CGameObjectManager();
	void Initialize();
	void Update();
	void Draw();
	int Input();
	bool Factory( int i_nAddType, int i_nX, int i_nY, double i_dAngle = 0);
private:
	void ColisionCheck();
private:
	CPlayer* m_Player;
	list<IGameObject*> m_EnemyList;
	list<IGameObject*> m_PlayerList;
	list<IGameObject*> m_PlayerBulletList;
	list<IGameObject*> m_EnemyBulletList;
	list<IGameObject*> m_ItemList;
	typedef list<IGameObject*>::iterator GameObjectIter;

};


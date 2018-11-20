#pragma once
#include "IGameObject.h"
class CPlayer :
	public IGameObject
{
public:
	CPlayer();
	CPlayer(int nX, int nY);
	~CPlayer();
	void Initialize();
	void Draw();
	void Update();
	int MsgProc();
	void BulletAdd();
	int GetBulletNum();
private:
	int m_nBulletNum;
};


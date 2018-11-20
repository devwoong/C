#pragma once
#include "IGameStage.h"
#include "GameObjectManager.h"
class CStage2 :
	public IGameStage
{
public:
	CStage2();
	~CStage2();
	void Initialize();
	void Update();
	void Draw();
	int Input();

private:
	CGameObjectManager m_GameRule;
	DWORD m_CurrentTick;
	int m_nTime;
	bool m_IsPause;
};


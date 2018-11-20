#pragma once
#include "IGameStage.h"
#include "GameObjectManager.h"
#include "Stage2.h"
class CStage1 :
	public IGameStage
{
public:
	CStage1();
	~CStage1();
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


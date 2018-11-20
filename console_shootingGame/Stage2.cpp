#include "stdafx.h"
#include "Stage2.h"


CStage2::CStage2()
{
}


CStage2::~CStage2()
{
}

void CStage2::Initialize()
{
	m_IsPause = false;
	m_nTime = 0;
	m_GameRule.Initialize();
	m_GameRule.Factory(GAMEOBJECT_ENEMY1, 10, 0);
	m_GameRule.Factory(GAMEOBJECT_ENEMY1, 20, 0);
	m_GameRule.Factory(GAMEOBJECT_ENEMY1, 30, 0);
	m_GameRule.Factory(GAMEOBJECT_ENEMY1, 40, 0);
	m_GameRule.Factory(GAMEOBJECT_ENEMY1, 50, 0);
	m_GameRule.Factory(GAMEOBJECT_ENEMY1, 60, 0);
	m_GameRule.Factory(GAMEOBJECT_ENEMY1, 70, 0);
}
void CStage2::Update()
{
	if (m_IsPause == true)
	{
		MYDRAW(50, 15, "-----Clear-----");
		if (GetTickCount() - m_CurrentTick > 1000)
		{
			exit(0);
		}
		return;
	}
	m_GameRule.Update();
	if (GetTickCount() - m_CurrentTick > 5000)
	{
		m_GameRule.Factory(GAMEOBJECT_ENEMY1, 10, 0);
		m_GameRule.Factory(GAMEOBJECT_ENEMY2, 10, 10);
		m_GameRule.Factory(GAMEOBJECT_ENEMY3, 80, 20);
		m_GameRule.Factory(GAMEOBJECT_ENEMY1, 50, 0);
		m_CurrentTick = GetTickCount();
		m_nTime++;
	}
	if (m_nTime > 8)
	{
		m_IsPause = true;
	}
}
void CStage2::Draw()
{
	if (m_IsPause == true) return;
	m_GameRule.Draw();
}
int CStage2::Input()
{
	if (m_IsPause == true) return 1;
	m_GameRule.Input();
	return 1;
}
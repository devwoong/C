#include "stdafx.h"
#include "StageManager.h"


CStageManager::CStageManager()
{
	m_CurrentStage = NULL;
}


CStageManager::~CStageManager()
{
}

void CStageManager::ChangeStage(IGameStage* i_ChangeStage)
{
	if (m_CurrentStage != NULL)
	{
		SAFE_DELETE(m_CurrentStage);
	}
	m_CurrentStage = i_ChangeStage;
	m_CurrentStage->Initialize();
}
IGameStage* CStageManager::GetCurrentStage()
{
	if (m_CurrentStage == NULL)
	{
		// 에러 처리
		return NULL;
	}
	return m_CurrentStage;
}
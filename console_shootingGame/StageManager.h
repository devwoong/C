#pragma once
#include "CSingleTon.h"
#include "IGameStage.h"
class CStageManager : public CSinglton<CStageManager>
{
public:
	CStageManager();
	~CStageManager();
	void ChangeStage(IGameStage* i_ChangeStage);
	IGameStage* GetCurrentStage();


private:
	IGameStage* m_CurrentStage;
};


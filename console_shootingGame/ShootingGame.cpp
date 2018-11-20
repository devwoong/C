// ShootingGame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.

#include "stdafx.h"
#include "Stage1.h"
int _tmain()
{
	DWORD nCurrentTick = GetTickCount();


	system("mode con: cols=100 lines=80");
	CDoubleBuffer::GetInstance()->createBuffer();
	CStageManager::GetInstance()->ChangeStage(new CStage1);
	while (true)
	{
		if (GetTickCount() - nCurrentTick > 10) //  최초시간에서 이전 시간을 뺌
		{
			nCurrentTick = GetTickCount();
			CStageManager::GetInstance()->GetCurrentStage()->Input();
			CStageManager::GetInstance()->GetCurrentStage()->Update();

			CStageManager::GetInstance()->GetCurrentStage()->Draw();
			CDoubleBuffer::GetInstance()->flippingBuffer();
			CDoubleBuffer::GetInstance()->clearBuffer();
		}
	}
	CDoubleBuffer::GetInstance()->destroyBuffer();
	return 0;
}


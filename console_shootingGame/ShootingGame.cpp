// ShootingGame.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.

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
		if (GetTickCount() - nCurrentTick > 10) //  ���ʽð����� ���� �ð��� ��
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


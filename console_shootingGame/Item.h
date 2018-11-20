#pragma once
#include "IGameObject.h"

class CItem :public IGameObject
{
public:
	CItem();
	CItem(int i_nX, int i_nY);
	~CItem();
	void Initialize();
	void Draw();
	void Update();
	int MsgProc();
};
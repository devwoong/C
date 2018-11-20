#pragma once
#include "IGameObject.h"
#include "Pattern1.h"
#include "Pattern2.h"
#include "Pattern3.h"
#include <time.h>
class CEnemy :
	public IGameObject
{
public:
	CEnemy();
	CEnemy(int i_nX, int i_nY, int i_nType);
	~CEnemy();
	void Initialize();
	void Draw();
	void Update();
	int MsgProc();
private:
	CPattern* m_PatternObject;
private:
	void CreatePattern(int i_nType);
};


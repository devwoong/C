#pragma once
#include "Pattern.h"
class CPattern2 :
	public CPattern
{
public:
	CPattern2();
	CPattern2(double* i_nX, double* i_nY, double i_dSpeed);
	~CPattern2();
	void Initialize();
	int MsgProc();
	void Update();
};


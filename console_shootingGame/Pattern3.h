#pragma once
#include "Pattern.h"
class CPattern3 :
	public CPattern
{
public:
	CPattern3();
	CPattern3(double* i_nX, double* i_nY, double i_dSpeed);
	~CPattern3();
	void Initialize();
	int MsgProc();
	void Update();
};


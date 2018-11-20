#pragma once
#include "Pattern.h"
class CPattern1 
	: public CPattern
{
public:
	CPattern1();
	CPattern1(double* i_nX, double* i_nY, double i_dSpeed);
	~CPattern1();
	void Initialize();
	int MsgProc();
	void Update();
};


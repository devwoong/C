#pragma once
class CPattern
{
public:
	CPattern();
	virtual ~CPattern();
	virtual void Initialize() = 0;
	virtual int MsgProc() = 0;
	virtual void Update() = 0;

protected:
	double* m_dX;
	double* m_dY;
	double m_dSpeed;
	double m_dAngle; 
	DWORD m_nShootTiming;
	DWORD m_nShootTimeCurrent;
};


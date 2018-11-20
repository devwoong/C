#pragma once

class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();
	virtual void Initialize() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual int MsgProc() = 0;
	virtual POINT GetPos();
	virtual RECT* GetColisionArea();
	virtual int GetType();
	virtual int GetAreaSize();
	virtual bool IsAlive();
	virtual void KillObject();

protected:
	double m_dSpeed;
	bool m_IsAlive;
	int m_nType;
	int m_nAreaSize;
	double m_dX;
	double m_dY;
	RECT* m_rtColisionArea;
	POINT m_ptPosition;
};


#pragma once
#include "IGameObject.h"
class CBullet :
	public IGameObject
{
public:
	CBullet();
	CBullet(int i_nX, int i_nY, int i_nDestX, int i_nDestY);
	CBullet(int i_nX, int i_nY, double i_dAngle = 90);
	~CBullet();
	void Initialize();
	void Draw();
	void Update();
	int MsgProc();
private :
	double m_dAngle;
};


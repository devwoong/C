#pragma once

#define PI 3.141592
#define SCREEN_SIZE_WIDTH 100
#define SCREEN_SIZE_HEIGHT 48
#define MYDRAW(x,y,string) CDoubleBuffer::GetInstance()->writeBuffer(x, y, string)

enum
{
	GAMEOBJECT_PLAYER,
	GAMEOBJECT_ENEMY1,
	GAMEOBJECT_ENEMY2,
	GAMEOBJECT_ENEMY3,
	GAMEOBJECT_PLAYERBULLET,
	GAMEOBJECT_ENEMYBULLET1,
	GAMEOBJECT_ENEMYBULLET2,
	GAMEOBJECT_ENEMYBULLET3,
	GAMEOBJECT_ITEM,
};

#define SAFE_DELETE(p) if (p != NULL){ delete p; p = NULL; } 

static bool ColRectInRect()
{

}
static bool ColRectInPoint(RECT i_rtSource, POINT i_ptDest )
{
	if (i_rtSource.left <= i_ptDest.x && i_rtSource.right >= i_ptDest.x
		&& i_rtSource.top <= i_ptDest.y && i_rtSource.bottom >= i_ptDest.y)
		return true;
	return false;
}

static bool ColScreenToPoint(POINT i_ptCheck)
{
	return ColRectInPoint({ 0, 0, SCREEN_SIZE_WIDTH-2, SCREEN_SIZE_HEIGHT-2 }, i_ptCheck);
}

static bool ColPointToPoint(POINT i_ptSource, POINT i_ptDest )
{
	//return ColRectInPoint({ i_ptDest.x - 1, i_ptDest.y - 1, i_ptDest.x + 1, i_ptDest.y + 1 }, i_ptSource);
	return  (i_ptSource.x == i_ptDest.x && i_ptDest.y == i_ptSource.y);
}

static bool ColPointToPoint2(POINT i_ptSource, POINT i_ptDest)
{
	return ColRectInPoint({ i_ptDest.x - 1, i_ptDest.y - 1, i_ptDest.x + 1, i_ptDest.y + 1 }, i_ptSource);
}
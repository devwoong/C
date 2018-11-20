#pragma once
class IGameStage
{
public:
	IGameStage();
	virtual ~IGameStage();
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual int Input() = 0;
};


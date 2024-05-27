#pragma once
#include "Character.h"

class Monster : public Character
{
public:
	Monster();
	
	void Draw() override;

	virtual void Start(int x, int y, class GameSystem_InGame* InSystem_InGame);
	virtual void Update(int InSleepTime) override;
	virtual void Move() override;
	virtual void End() override;
	virtual void Drawclear() override;

	virtual void OnHitObject(class YommanObject* InHitObject) override;

	virtual YommanObjectType GetObjectType() { return YommanObjectType::Monster; }

protected:
	InputKey FindNextMoveDirection();

	InputKey* TempMoveTypeList;
};


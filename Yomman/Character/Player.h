#pragma once
#include "Character.h"
#include "../Yomman_Etc/YommanDefine.h"

class Player : public Character
{
public:
	Player();

	virtual void InputEvent(InputKey InKey) override;

	virtual void Draw() override;

	virtual void Drawclear() override;

	virtual void Move() override;

	virtual YommanObjectType GetObjectType() { return YommanObjectType::Player; }
	virtual void OnHitObject(class YommanObject* InHitObject) override;

	// 속도로 변경된 위치 보정
	bool AdjustedPos(Vector2D& InNextInputPos , Vector2D& OutNextAdjustedPos);

protected:
	InputKey Last_userinput;
};

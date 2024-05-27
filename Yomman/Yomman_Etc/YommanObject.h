#pragma once
#include <Windows.h>
#include <iostream>
#include "YommanDefine.h"


class YommanObject
{
public:
	virtual Vector2D GetObjectPos() { return Vector2D(0, 0); }

	virtual Vector2D GetObjectOffestPos() { return Vector2D(0, 0); }

	virtual void OnHitObject(YommanObject* InHitObject) {}

	virtual YommanObjectType GetObjectType() { return YommanObjectType::None; }
};


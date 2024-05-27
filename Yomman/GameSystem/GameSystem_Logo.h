#pragma once
#include "GameSystem_Base.h"

class GameSystem_Logo : public GameSystem_Base
{
public:
	GameSystem_Logo();
	GameSystemType GetGameSystemType() { return GameSystemType::Logo; }
	virtual void BeingPlay() override;
	virtual void InputEvent(InputKey InKey) override;
	virtual void End() override;

	int Menu_Draw();
	void InfoS();
	int x = 108;
	int y = 40;

};

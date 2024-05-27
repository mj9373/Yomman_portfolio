#pragma once
#include "../Item/Item.h"

class Coin : public ITEM
{
public:
	Coin();

	virtual void Draw() override;

	virtual void Drawclear() override;

	virtual ItemType GetItemType() { return ItemType::Coin; }
};


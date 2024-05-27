#pragma once
#include "../Item/Item.h"

class Fruit : public ITEM
{
public:
	Fruit();

	virtual void Draw() override;

	virtual void Drawclear() override;

	virtual ItemType GetItemType() { return ItemType::Fruit; }
};


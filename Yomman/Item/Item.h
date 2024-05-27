#pragma once
#include <Windows.h>
#include <iostream>
#include "../Yomman_Etc/YommanDefine.h"
#include "../Yomman_Etc/YommanObject.h"

using namespace std;

class ITEM : public YommanObject
{
public:
	ITEM();

	virtual void Start(int InX,int InY);

	virtual void Draw() {}
	virtual void Drawclear() {}

	virtual void OnHitObject(YommanObject* InHitObject) override;

	//. ��Ʈ�� 15x15�̹Ƿ� �׷����� ��ġ�� ���� ��� 
	virtual Vector2D GetObjectPos() { return Pos; }
	virtual Vector2D GetObjectOffsetPos() { return Drawoffset; }

	virtual YommanObjectType GetObjectType() { return YommanObjectType::Item; }
	virtual ItemType GetItemType() { return ItemType::None; }


	bool GetIsActive() { return IsActive; }
	int GetScore() { return grade; }

public:

	void TextColor(int font, int backGround);

	void PrintS(int count, int font, int background, bool IsEndl);

	void Gotoxy(int x, int y);

protected:
	Vector2D Pos;
	Vector2D Drawoffset;

	bool IsActive;
	int grade = 0;
};


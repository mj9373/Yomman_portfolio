#pragma once
#include "../Yomman_Etc/YommanDefine.h"
#include <Windows.h>
#include <iostream>
#include "../Yomman_Etc/YommanObject.h"

using namespace std;

// Yommanobject�� ����� �޴� ĳ���� Ŭ����
class Character : public YommanObject 
{
public:
	Character();

	// ĳ���� ��Ʈ�� �׸��� ���� �Լ�
	virtual void Draw() {}

	// ĳ���� ��Ʈ �ܻ��� ����� (�����) ���� �Լ�
	virtual void Drawclear() {}

	// ĳ���� �̵��� ���� ��ǲ �̺�Ʈ �Լ� 
	virtual void InputEvent(InputKey InKey) {}

	// ĳ���� ������ Ȥ�� �̺�Ʈ�� ���� ������Ʈ �Լ�
	virtual void Update(int InSleepTime);

	// Ŭ���� Start �� ������ ���� �Լ�
	virtual void Start(int x, int y , class GameSystem_InGame* InSystem_InGame);

	// �Ҹ��� ���� End �Լ�
	virtual void End();

	// �浹 ó���� ���� �Լ�
	virtual void OnHitObject(YommanObject* InHitObject) override {};

	virtual Vector2D GetObjectPos()override { return Pos; }
	virtual Vector2D GetObjectOffestPos()override { return Drawoffset; }

protected:

	void TextColor(int font, int backGround);

	void PrintS(int count, int font, int background, bool IsEndl);

	void Gotoxy(int x, int y);

	virtual void Move()
	{
	}

	Vector2D GetVectorFromInput(InputKey InInputkey);

protected:

	Vector2D Pos;
	Vector2D Clear;
	Vector2D Drawoffset;
	
	InputKey LastMoveDirection;

	class GameSystem_InGame* InGameSystem;


	int CharacterSpeed;
};



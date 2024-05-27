#pragma once
#include "../Yomman_Etc/YommanDefine.h"
#include <Windows.h>
#include <iostream>
#include "../Yomman_Etc/YommanObject.h"

using namespace std;

// Yommanobject의 상속을 받는 캐릭터 클래스
class Character : public YommanObject 
{
public:
	Character();

	// 캐릭터 도트를 그리기 위한 함수
	virtual void Draw() {}

	// 캐릭터 도트 잔상을 지우기 (덮어쓰기) 위한 함수
	virtual void Drawclear() {}

	// 캐릭터 이동을 위한 인풋 이벤트 함수 
	virtual void InputEvent(InputKey InKey) {}

	// 캐릭터 움직임 혹시 이벤트에 따른 업데이트 함수
	virtual void Update(int InSleepTime);

	// 클래스 Start 시 셋팅을 위한 함수
	virtual void Start(int x, int y , class GameSystem_InGame* InSystem_InGame);

	// 소멸을 위한 End 함수
	virtual void End();

	// 충돌 처리를 위한 함수
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



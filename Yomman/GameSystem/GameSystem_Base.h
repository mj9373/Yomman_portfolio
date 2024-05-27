#pragma once

#include "../Yomman_Etc/YommanDefine.h"

#include <string>
#include <iostream>
#include<Windows.h>
#include <stdio.h>
#include<time.h>
#include<conio.h>

using namespace std;

class GameSystem_Base
{
public:
	GameSystem_Base();

	//. 생성 시 호출
	virtual void Start(class GameSystemManager* Inmanager);
	
	//. 시스템 변경시 호출
	virtual void BeingPlay();

	//. 메인에서 매 슬립 다음 호출
	virtual void Update(int InSleepTime) 
	{
	}

	virtual void UpdateRander()
	{
	}

	//. 시스템 변경시 호출
	virtual void End() 
	{
	}
	//. 인풋에 따른 이벤트 
	virtual void InputEvent(InputKey InKey) 
	{
	};

	GameSystemType GetGameSystemType() { return GameSystemType::Max; }

	/* 각 시스템별 그려야 하는 출력 화면 */
	virtual void PrintScreen();

	void TextColor(int font, int backGround);

	void PrintS(int count, int font, int background, bool IsEndl);

	void Gotoxy(int x, int y);


protected:
	string ScrrenDotData;
	class GameSystemManager* Manager;

};

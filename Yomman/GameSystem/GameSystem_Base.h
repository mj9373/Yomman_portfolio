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

	//. ���� �� ȣ��
	virtual void Start(class GameSystemManager* Inmanager);
	
	//. �ý��� ����� ȣ��
	virtual void BeingPlay();

	//. ���ο��� �� ���� ���� ȣ��
	virtual void Update(int InSleepTime) 
	{
	}

	virtual void UpdateRander()
	{
	}

	//. �ý��� ����� ȣ��
	virtual void End() 
	{
	}
	//. ��ǲ�� ���� �̺�Ʈ 
	virtual void InputEvent(InputKey InKey) 
	{
	};

	GameSystemType GetGameSystemType() { return GameSystemType::Max; }

	/* �� �ý��ۺ� �׷��� �ϴ� ��� ȭ�� */
	virtual void PrintScreen();

	void TextColor(int font, int backGround);

	void PrintS(int count, int font, int background, bool IsEndl);

	void Gotoxy(int x, int y);


protected:
	string ScrrenDotData;
	class GameSystemManager* Manager;

};

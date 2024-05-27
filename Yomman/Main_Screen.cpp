#include "../Yomman/Yomman_Etc/YommanDefine.h"
#include "Manager/GameSystemManager.h"
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

/*
특이사항

로고 화면크기 및 폰트 크기
	system("mode con cols=230 lines=60");
	cfi.dwFontSize.X = 7;
	cfi.dwFontSize.Y = 14;

게임 실행(인게임) 화면크기 및 폰트 크기
	cfi.dwFontSize.X = 3;
	cfi.dwFontSize.Y = 6;
	system("mode con cols=570 lines=150");

Score 화면크기 및 폰트 크기
	system("mode con cols=230 lines=60");
	cfi.dwFontSize.X = 7;
	cfi.dwFontSize.Y = 14;

*/

InputKey KeyControl()
{
	InputKey CurrentInputKey = InputKey::None;

	if (GetAsyncKeyState(VK_LEFT) & 0x0001 ||
		GetAsyncKeyState(0x41) & 0x0001)
	{
		CurrentInputKey = InputKey::Left;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x0001 ||
		GetAsyncKeyState(0x44) & 0x0001)
	{
		CurrentInputKey = InputKey::Right;
	}

	if (GetAsyncKeyState(VK_UP) & 0x0001 ||
		GetAsyncKeyState(0x57) & 0x0001)
	{

		CurrentInputKey = InputKey::Up;
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x0001 ||
		GetAsyncKeyState(0x53) & 0x0001)
	{
		CurrentInputKey = InputKey::Down;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		CurrentInputKey = InputKey::SUBMIT;
	}

	return CurrentInputKey;
};


int main()
{
	PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);

	int SleepSpeed = 10;
    system("mode con cols=230 lines=60");
    HANDLE consonleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consonleHandle, &ConsoleCursor);


    GameSystemManager manager;
    manager.Start();
    manager.ChangeSystem(GameSystemType::Logo);

    while (true)
    {
        manager.OnInputEvent(KeyControl());

        manager.Update(SleepSpeed);
       
        manager.UpdateRander();

        Sleep(SleepSpeed);
    }

    
    return 0;
}
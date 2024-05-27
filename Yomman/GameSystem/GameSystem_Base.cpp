#include "GameSystem_Base.h"
#include "../Manager/GameSystemManager.h"



GameSystem_Base::GameSystem_Base()
{
	//생성자
	Manager = nullptr;


}

void GameSystem_Base::Start(GameSystemManager* Inmanager)
{
	Manager = Inmanager;
}


void GameSystem_Base::BeingPlay()
{

}


void GameSystem_Base::PrintScreen()
{
}

void GameSystem_Base::TextColor(int font, int backGround)
{
	int Color = font + backGround * 16;                           // * == 곱하기      // 16 콘솔 색상표
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);   // 콘솔 텍스트 지정
}

void GameSystem_Base::PrintS(int count, int font, int background, bool IsEndl)
{
	TextColor(font, background);
	for (int i = 0; i < count; i++)
	{
		std::cout << "ㅁ";
	}

	if (IsEndl == true)
	{
		std::cout << endl;
	}
}

//  BLACK 0 
// BLUE 1 
// GREEN 2
// CYAN 3 
// RED 4 
// MAGENTA 5  
// BROWN 6 
// LIGHTGRAY 7
// DARKGRAY 8
// LIGHTBLUE 9
// LIGHTGREEN 10
// LIGHTCYAN 11 
// LIGHTRED 12 
// LIGHTMAGENTA 13
// YELLOW 14 
// WHITE 15 

void GameSystem_Base::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);

}




#include "ITEM.h"

ITEM::ITEM()
{
	Pos = Vector2D(0, 0);
	Drawoffset = Vector2D(-14, -7);
	grade = 0;
	IsActive = true;
}

void ITEM::Start(int InX, int InY)
{
	Pos.X = InX;
	Pos.Y = InY;
}

void ITEM::OnHitObject(YommanObject* InHitObject)
{
	if (IsActive == false)
		return;

	if (InHitObject->GetObjectType() == YommanObjectType::Player)
	{

		IsActive = false;
		Drawclear();
	}
}


void ITEM::TextColor(int font, int backGround)
{
	int Color = font + backGround * 16;                           
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);   
}

void ITEM::PrintS(int count, int font, int background, bool IsEndl)
{
	TextColor(font, background);
	for (int i = 0; i < count; i++)
	{
		std::cout << "¤±";
	}

	if (IsEndl == true)
	{
		std::cout << endl;
	}
}

void ITEM::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

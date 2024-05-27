#include "Character.h"
#include "../GameSystem/GameSystem_InGame.h"

Character::Character()
{
	Pos = Vector2D(0, 0);
	Drawoffset = Vector2D(-14, -7);
	Clear = Vector2D(0, 0);
	InGameSystem = nullptr;

	LastMoveDirection = InputKey::None;

	//최초 한번은 실행

	CharacterSpeed = 1;
}

void Character::Update(int InSleepTime)
{
	Move();
}

void Character::Start(int x, int y, GameSystem_InGame* InSystem_InGame)
{
	Pos.X = x;
	Pos.Y = y;

	InGameSystem = InSystem_InGame;
}

void Character::End()
{
	InGameSystem = nullptr;
}

void Character::TextColor(int font, int backGround)
{
    int Color = font + backGround * 16;                           // * == 곱하기      // 16 콘솔 색상표
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);   // 콘솔 텍스트 지정
}

void Character::PrintS(int count, int font, int background, bool IsEndl)
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


void Character::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


Vector2D Character::GetVectorFromInput(InputKey InInputkey)
{
	Vector2D InputPos = Vector2D(0, 0);

	switch (InInputkey)
	{
	case InputKey::Up:
	{
		InputPos.Y = -1;
	}
	break;
	case InputKey::Down:
	{
		InputPos.Y = 1;
	}
	break;
	case InputKey::Left:
	{
		InputPos.X = -1;
	}
	break;
	case InputKey::Right:
	{
		InputPos.X = 1;
	}
	break;
	default:
		break;
	}

	return InputPos;
}



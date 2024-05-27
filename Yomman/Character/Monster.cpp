#include "Monster.h"
#include "../GameSystem/GameSystem_InGame.h"

Monster::Monster()
{
	TempMoveTypeList = nullptr;

	CharacterSpeed = 1;
}


void Monster::Draw()
{
	int x = Pos.X * 2 + Drawoffset.X;
	int y = Pos.Y + Drawoffset.Y;

	
	if (Pos.X < Clear.X || (Pos.X == Clear.X && Pos.Y == Clear.Y))
	{// ¿ÞÂÊ
		Gotoxy(x, y), PrintS(5, 0, 0, 0);
		PrintS(5, 11, 11, 0);
		PrintS(5, 0, 0, 1);

		Gotoxy(x, y+1), PrintS(3, 0, 0, 0);
		PrintS(9, 11, 11, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y+2),PrintS(2, 0, 0, 0);
		PrintS(11, 11, 11, 0);
		PrintS(2, 0, 0, 1);

		Gotoxy(x, y+3), PrintS(1, 0, 0, 0);
		PrintS(1, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(5, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y+4), PrintS(1, 0, 0, 0);
		PrintS(4, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(4, 15, 15, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y+5), PrintS(1, 0, 0, 0);
		PrintS(2, 8, 8, 0);
		PrintS(2, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(2, 8, 8, 0);
		PrintS(2, 15, 15, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y+6), PrintS(1, 11, 11, 0);
		PrintS(2, 8, 8, 0);
		PrintS(2, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(2, 8, 8, 0);
		PrintS(2, 15, 15, 0);
		PrintS(3, 11, 11, 1);

		Gotoxy(x, y+7), PrintS(2, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(5, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(4, 11, 11, 1);

		Gotoxy(x, y+8), PrintS(15, 11, 11, 1);

		Gotoxy(x, y+9), PrintS(15, 11, 11, 1);

		Gotoxy(x, y+10), PrintS(15, 11, 11, 1);

		Gotoxy(x, y+11), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 12), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 13), PrintS(2, 11, 11, 0);
		PrintS(1, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(1, 0, 0, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y + 14), PrintS(1, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(1, 11, 11, 1);
	}

	//¿À¸¥ÂÊ
	else if (Pos.X > Clear.X)
	{
		Gotoxy(x, y), PrintS(5, 0, 0, 0);
		PrintS(5, 11, 11, 0);
		PrintS(5, 0, 0, 1);

		Gotoxy(x, y + 1), PrintS(3, 0, 0, 0);
		PrintS(9, 11, 11, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y + 2), PrintS(2, 0, 0, 0);
		PrintS(11, 11, 11, 0);
		PrintS(2, 0, 0, 1);

		Gotoxy(x, y + 3), PrintS(1, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(5, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(1, 11, 11, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y + 4), PrintS(1, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(4, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(4, 15, 15, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y + 5), PrintS(1, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(2, 8, 8, 0);
		PrintS(3, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(2, 8, 8, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y + 6), PrintS(3, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(2, 8, 8, 0);
		PrintS(3, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(2, 8, 8, 0);
		PrintS(1, 11, 11, 1);

		Gotoxy(x, y + 7), PrintS(4, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(5, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y + 8), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 9), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 10), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 11), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 12), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 13), PrintS(2, 11, 11, 0);
		PrintS(1, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(1, 0, 0, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y + 14), PrintS(1, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(1, 11, 11, 1);
	}

	//¹Ø
	else if (Pos.Y > Clear.Y)
	{
		Gotoxy(x, y ), PrintS(5, 0, 0, 0);
		PrintS(5, 11, 11, 0);
		PrintS(5, 0, 0, 1);

		Gotoxy(x, y + 1), PrintS(3, 0, 0, 0);
		PrintS(9, 11, 11, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y + 2), PrintS(2, 0, 0, 0);
		PrintS(11, 11, 11, 0);
		PrintS(2, 0, 0, 1);

		Gotoxy(x, y + 3), PrintS(1, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(5, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(2, 11, 11, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y + 4), PrintS(1, 0, 0, 0);
		PrintS(1, 11, 11, 0);
		PrintS(4, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(4, 15, 15, 0);
		PrintS(1, 11, 11, 1);

		Gotoxy(x, y + 5), PrintS(1, 0, 0, 0);
		PrintS(1, 11, 11, 0);
		PrintS(4, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(4, 15, 15, 0);
		PrintS(1, 11, 11, 1);

		Gotoxy(x, y + 6), PrintS(2, 11, 11, 0);
		PrintS(1, 15, 15, 0);
		PrintS(2, 8, 8, 0);
		PrintS(1, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(1, 15, 15, 0);
		PrintS(2, 8, 8, 0);
		PrintS(1, 15, 15, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y + 7), PrintS(3, 11, 11, 0);
		PrintS(2, 8, 8, 0);
		PrintS(5, 11, 11, 0);
		PrintS(2, 8, 8, 0);
		PrintS(3, 11, 11, 1);

		Gotoxy(x, y + 8), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 9), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 10), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 11), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 12), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 13), PrintS(2, 11, 11, 0);
		PrintS(1, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(1, 0, 0, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y + 14), PrintS(1, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(1, 11, 11, 1);
	}


	else if (Pos.Y <  Clear.Y)
	{
		Gotoxy(x, y), PrintS(5, 0, 0, 0);
		PrintS(5, 11, 11, 0);
		PrintS(5, 0, 0, 1);

		Gotoxy(x, y + 1), PrintS(3, 0, 0, 0);
		PrintS(9, 11, 11, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y + 2), PrintS(2, 0, 0, 0);
		PrintS(11, 11, 11, 0);
		PrintS(2, 0, 0, 1);

		Gotoxy(x, y + 3), PrintS(1, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(2, 8, 8, 0);
		PrintS(5, 11, 11, 0);
		PrintS(2, 8, 8, 0);
		PrintS(2, 11, 11, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y + 4), PrintS(1, 0, 0, 0);
		PrintS(1, 11, 11, 0);
		PrintS(1, 15, 15, 0);
		PrintS(2, 8, 8, 0);
		PrintS(1, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(1, 15, 15, 0);
		PrintS(2, 8, 8, 0);
		PrintS(1, 15, 15, 0);
		PrintS(1, 11, 11, 1);

		Gotoxy(x, y + 5), PrintS(1, 0, 0, 0);
		PrintS(1, 11, 11, 0);
		PrintS(3, 15, 15, 0);
		PrintS(1, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(4, 15, 15, 0);
		PrintS(1, 11, 11, 1);

		Gotoxy(x, y + 6), PrintS(2, 11, 11, 0);
		PrintS(3, 15, 15, 0);
		PrintS(1, 15, 15, 0);
		PrintS(3, 11, 11, 0);
		PrintS(3, 15, 15, 0);
		PrintS(1, 15, 15, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y + 7), PrintS(3, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(5, 11, 11, 0);
		PrintS(2, 15, 15, 0);
		PrintS(3, 11, 11, 1);

		Gotoxy(x, y + 8), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 9), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 10), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 11), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 12), PrintS(15, 11, 11, 1);

		Gotoxy(x, y + 13), PrintS(2, 11, 11, 0);
		PrintS(1, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(3, 11, 11, 0);
		PrintS(1, 0, 0, 0);
		PrintS(2, 11, 11, 1);

		Gotoxy(x, y + 14), PrintS(1, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(2, 11, 11, 0);
		PrintS(3, 0, 0, 0);
		PrintS(1, 11, 11, 1);
	}

	
}

void Monster::Start(int x, int y, GameSystem_InGame* InSystem_InGame)
{
	Character::Start(x, y, InSystem_InGame);

	TempMoveTypeList = new InputKey[4];
	LastMoveDirection = FindNextMoveDirection();
}

void Monster::Update(int InSleepTime)
{
	if (InGameSystem != nullptr)
	{
		if (InGameSystem->GetMapData(Pos) == '8')
		{
			LastMoveDirection = FindNextMoveDirection();
		}
	}

	Character::Update(InSleepTime);
}

void Monster::Move()
{
	Clear = Pos;

	if (InGameSystem != nullptr)
	{
		 Vector2D NextMovePos = Pos + GetVectorFromInput(LastMoveDirection);
		if (InGameSystem->CheckMapLoad(NextMovePos) == true)
		{
			Pos = NextMovePos;
		}
	}
}

void Monster::End()
{
	Character::End();

	delete[] TempMoveTypeList;
}

void Monster::Drawclear()
{
	int x = Clear.X * 2 + Drawoffset.X;
	int y = Clear.Y + Drawoffset.Y;

	Gotoxy(x, y), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 1), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 2), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 3), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 4), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 5), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 6), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 7), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 8), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 9), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 10), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 11), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 12), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 13), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 14), PrintS(15, 0, 0, 1);
}

void Monster::OnHitObject(YommanObject* InHitObject)
{
	if (LastMoveDirection == InputKey::None)
		return;


	if (InHitObject->GetObjectType() == YommanObjectType::Monster)
	{
		switch (LastMoveDirection)
		{
		case InputKey::Up: LastMoveDirection = InputKey::Down; break;
		case InputKey::Down: LastMoveDirection = InputKey::Up; break;
		case InputKey::Left:LastMoveDirection = InputKey::Right; break;
		case InputKey::Right:LastMoveDirection = InputKey::Left; break;
		}
	}
	else if (InHitObject->GetObjectType() == YommanObjectType::Player)
	{
		
	}
}

InputKey Monster::FindNextMoveDirection()
{
	int CheckCount = 0;

	for (int i = 0; i < 4; i++)
	{
		TempMoveTypeList[i] = InputKey::None;
	}

	// Up
	if(LastMoveDirection != InputKey::Down)
	{
		Vector2D NexMovePos = Pos;
		NexMovePos.Y -= 1;

		if (InGameSystem->CheckMapLoad(NexMovePos) == true)
		{
			TempMoveTypeList[CheckCount] = InputKey::Up;
			++CheckCount;
		}
	}

	// Down
	if (LastMoveDirection != InputKey::Up)
	{
		Vector2D NexMovePos = Pos;
		NexMovePos.Y += 1;

		if (InGameSystem->CheckMapLoad(NexMovePos) == true)
		{
			TempMoveTypeList[CheckCount] = InputKey::Down;
			++CheckCount;
		}
	}

	// left
	if (LastMoveDirection != InputKey::Right)
	{
		Vector2D NexMovePos = Pos;
		NexMovePos.X -= 1;

		if (InGameSystem->CheckMapLoad(NexMovePos) == true)
		{
			TempMoveTypeList[CheckCount] = InputKey::Left;
			++CheckCount;
		}
	}

	// Right
	if (LastMoveDirection != InputKey::Left)
	{
		Vector2D NexMovePos = Pos;
		NexMovePos.X += 1;

		if (InGameSystem->CheckMapLoad(NexMovePos) == true)
		{
			TempMoveTypeList[CheckCount] = InputKey::Right;
			++CheckCount;
		}
	}

	if (CheckCount > 0)
	{
		int MoveIndex = rand() % CheckCount;
		return TempMoveTypeList[MoveIndex];
	}


	return InputKey::None;
}



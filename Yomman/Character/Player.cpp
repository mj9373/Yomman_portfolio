#include "Player.h"
#include "../GameSystem/GameSystem_InGame.h"
#include "../Item/Item.h"

Player::Player()
{
	Last_userinput = InputKey::None;
	CharacterSpeed = 2;
}

void Player::InputEvent(InputKey InKey)
{
	if (InKey == InputKey::SUBMIT || InKey == InputKey::None)
		return;

	Last_userinput = InKey;
}

void Player::Draw()
{
	int x = Pos.X * 2 + Drawoffset.X;
	int y = Pos.Y + Drawoffset.Y;

	if (Pos.X < Clear.X || (Pos.X == Clear.X && Pos.Y == Clear.Y))
	{
		Gotoxy(x, y), PrintS(5, 0, 0, 0);
		PrintS(5, 14, 14, 0);
		PrintS(5, 0, 0, 1);

		Gotoxy(x, y + 1), PrintS(4, 0, 0, 0);
		PrintS(8, 14, 14, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y + 2), PrintS(3, 0, 0, 0);
		PrintS(10, 14, 14, 0);
		PrintS(2, 0, 0, 1);

		Gotoxy(x, y + 3), PrintS(2, 0, 0, 0);
		PrintS(5, 14, 14, 0);
		PrintS(1, 8, 8, 0);
		PrintS(6, 14, 14, 1);

		Gotoxy(x, y + 4), PrintS(1, 0, 0, 0);
		PrintS(6, 14, 14, 0);
		PrintS(1, 8, 8, 0);
		PrintS(6, 14, 14, 1);

		Gotoxy(x, y + 5), PrintS(3, 0, 0, 0);
		PrintS(12, 14, 14, 1);

		Gotoxy(x, y + 6), PrintS(6, 0, 0, 0);
		PrintS(9, 14, 14, 1);

		Gotoxy(x, y + 7), PrintS(9, 0, 0, 0);
		PrintS(6, 14, 14, 1);

		Gotoxy(x, y + 8), PrintS(6, 0, 0, 0);
		PrintS(9, 14, 14, 1);

		Gotoxy(x, y + 9), PrintS(3, 0, 0, 0);
		PrintS(12, 14, 14, 1);

		Gotoxy(x, y + 10), PrintS(1, 0, 0, 0);
		PrintS(13, 14, 14, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y + 11), PrintS(2, 0, 0, 0);
		PrintS(12, 14, 14, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y + 12), PrintS(3, 0, 0, 0);
		PrintS(10, 14, 14, 0);
		PrintS(2, 0, 0, 1);

		Gotoxy(x, y + 13), PrintS(4, 0, 0, 0);
		PrintS(8, 14, 14, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y + 14), PrintS(5, 0, 0, 0);
		PrintS(5, 14, 14, 0);
		PrintS(5, 0, 0, 1);
	}

	else if (Pos.X > Clear.X)
	{
		Gotoxy(x, y), PrintS(5, 0, 0, 0);
		PrintS(5, 14, 14, 0);
		PrintS(5, 0, 0, 1);

		Gotoxy(x, y+1), PrintS(3, 0, 0, 0);
		PrintS(8, 14, 14, 0);
		PrintS(4, 0, 0, 1);

		Gotoxy(x, y+2), PrintS(2, 0, 0, 0);
		PrintS(10, 14, 14, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y+3), PrintS(1, 0, 0, 0);
		PrintS(6, 14, 14, 0);
		PrintS(1, 8, 8, 0);
		PrintS(5, 14, 14, 0);
		PrintS(2, 0, 0, 1);

		Gotoxy(x, y+4), PrintS(1, 0, 0, 0);
		PrintS(6, 14, 14, 0);
		PrintS(1, 8, 8, 0);
		PrintS(6, 14, 14, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y+5), PrintS(12, 14, 14, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y+6), PrintS(9, 14, 14, 0);
		PrintS(6, 0, 0, 1);

		Gotoxy(x, y+7), PrintS(6, 14, 14, 0);
		PrintS(9, 0, 0, 1);

		Gotoxy(x, y+8), PrintS(9, 14, 14, 0);
		PrintS(6, 0, 0, 1);

		Gotoxy(x, y+9), PrintS(12, 14, 14, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y+10), PrintS(1, 0, 0, 0);
		PrintS(13, 14, 14, 0);
		PrintS(1, 0, 0, 1);

		Gotoxy(x, y+11), PrintS(1, 0, 0, 0);
		PrintS(12, 14, 14, 0);
		PrintS(2, 0, 0, 1);

		Gotoxy(x, y+12), PrintS(2, 0, 0, 0);
		PrintS(10, 14, 14, 0);
		PrintS(3, 0, 0, 1);

		Gotoxy(x, y+13), PrintS(3, 0, 0, 0);
		PrintS(8, 14, 14, 0);
		PrintS(4, 0, 0, 1);

		Gotoxy(x, y+14), PrintS(5, 0, 0, 0);
		PrintS(5, 14, 14, 0);
		PrintS(5, 0, 0, 1);
	}
	
	
	else if (Pos.Y > Clear.Y)
	{
	Gotoxy(x, y), PrintS(5, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(5, 0, 0, 1);

	Gotoxy(x, y+1), PrintS(3, 0, 0, 0);
	PrintS(8, 14, 14, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y+2), PrintS(2, 0, 0, 0);
	PrintS(11, 14, 14, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y+3), PrintS(1, 0, 0, 0);
	PrintS(13, 14, 14, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y+4), PrintS(1, 0, 0, 0);
	PrintS(13, 14, 14, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y+5), PrintS(15, 14, 14, 1);

	Gotoxy(x, y+6), PrintS(7, 14, 14, 0);
	PrintS(1, 0, 0, 0);
	PrintS(7, 14, 14, 1);

	Gotoxy(x, y+7), PrintS(7, 14, 14, 0);
	PrintS(1, 0, 0, 0);
	PrintS(2, 14, 14, 0);
	PrintS(2, 8, 8, 0);
	PrintS(3, 14, 14, 1);

	Gotoxy(x, y+8), PrintS(7, 14, 14, 0);
	PrintS(1, 0, 0, 0);
	PrintS(7, 14, 14, 1);

	Gotoxy(x, y+9), PrintS(6, 14, 14, 0);
	PrintS(3, 0, 0, 0);
	PrintS(6, 14, 14, 1);

	Gotoxy(x, y+10), PrintS(1, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(3, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y+11), PrintS(2, 0, 0, 0);
	PrintS(4, 14, 14, 0);
	PrintS(3, 0, 0, 0);
	PrintS(4, 14, 14, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y+12), PrintS(3, 0, 0, 0);
	PrintS(2, 14, 14, 0);
	PrintS(5, 0, 0, 0);
	PrintS(2, 14, 14, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y+13), PrintS(4, 0, 0, 0);
	PrintS(1, 14, 14, 0);
	PrintS(5, 0, 0, 0);
	PrintS(1, 14, 14, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y+14), PrintS(15, 0, 0, 1);
	}

	else if (Pos.Y < Clear.Y)
	{
	Gotoxy(x, y), PrintS(15, 0, 0, 1);

	Gotoxy(x, y+1), PrintS(4, 0, 0, 0);
	PrintS(1, 14, 14, 0);
	PrintS(5, 0, 0, 0);
	PrintS(1, 14, 14, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y+2), PrintS(3, 0, 0, 0);
	PrintS(2, 14, 14, 0);
	PrintS(5, 0, 0, 0);
	PrintS(2, 14, 14, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y+3), PrintS(2, 0, 0, 0);
	PrintS(4, 14, 14, 0);
	PrintS(3, 0, 0, 0);
	PrintS(4, 14, 14, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y+4), PrintS(1, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(3, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y+5), PrintS(6, 14, 14, 0);
	PrintS(3, 0, 0, 0);
	PrintS(6, 14, 14, 1);

	Gotoxy(x, y+6), PrintS(7, 14, 14, 0);
	PrintS(1, 0, 0, 0);
	PrintS(7, 14, 14, 1);

	Gotoxy(x, y+7), PrintS(7, 14, 14, 0);
	PrintS(1, 0, 0, 0);
	PrintS(2, 14, 14, 0);
	PrintS(2, 8, 8, 0);
	PrintS(3, 14, 14, 1);

	Gotoxy(x, y+8), PrintS(7, 14, 14, 0);
	PrintS(1, 0, 0, 0);
	PrintS(7, 14, 14, 1);

	Gotoxy(x, y+9), PrintS(15, 14, 14, 1);

	Gotoxy(x, y+10), PrintS(1, 0, 0, 0);
	PrintS(13, 14, 14, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y+11), PrintS(1, 0, 0, 0);
	PrintS(13, 14, 14, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y+12), PrintS(2, 0, 0, 0);
	PrintS(11, 14, 14, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y+13), PrintS(3, 0, 0, 0);
	PrintS(8, 14, 14, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y+14), PrintS(5, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(5, 0, 0, 1);
	}

}

void Player::Drawclear()
{
	int x = Clear.X*2 + Drawoffset.X;
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

void Player::Move()
{
	Vector2D InputPos = Vector2D(0,0);

	Clear = Pos;

	InputPos = GetVectorFromInput(Last_userinput);

	if (InputPos.IsZero() == true)
		return;

	if (InGameSystem != nullptr)
	{
		Vector2D AbjustPos;
		if (AdjustedPos(InputPos, AbjustPos) == true)
		{
			Pos = AbjustPos;
			LastMoveDirection = Last_userinput;
		}
		else if(LastMoveDirection != InputKey::None)
		{
			InputPos = GetVectorFromInput(LastMoveDirection);
			Vector2D AbjustPos;
			if (AdjustedPos(InputPos, AbjustPos) == true)
			{
				Pos = AbjustPos;
			}
		}
	}
}

void Player::OnHitObject(YommanObject* InHitObject)
{
	if (InGameSystem == nullptr)
		return;

	if (InHitObject->GetObjectType() == YommanObjectType::Item)
	{
		if (ITEM* HitItem = static_cast<ITEM*>(InHitObject))
		{
			InGameSystem->AddScore(HitItem->GetScore());
			if (HitItem->GetItemType() == ItemType::Coin)
				InGameSystem->AddCoinCount();
		}
	}
	else if (InHitObject->GetObjectType() == YommanObjectType::Monster)
	{
		InGameSystem->SetGameEnd();
	}
}

bool Player::AdjustedPos(Vector2D& InNextInputPos, Vector2D& OutNextAdjustedPos)
{
	bool IsChangeDir = false;
	Vector2D TempPos = Vector2D(0, 0);

	switch (Last_userinput)
	{
	case InputKey::Up:
	case InputKey::Down:
	{
		if (LastMoveDirection == InputKey::Left || LastMoveDirection == InputKey::Right)
			IsChangeDir = true;
	}
	break;

	case InputKey::Left:
	case InputKey::Right:

	{
		if (LastMoveDirection == InputKey::Up || LastMoveDirection == InputKey::Down)
			IsChangeDir = true;
	}
	break;
	}

	if (LastMoveDirection == InputKey::None)
		IsChangeDir = false;


	if (IsChangeDir == false)
	{
		for (int i = 1; i <= CharacterSpeed; i++)
		{
			Vector2D NextPos = Pos + (InNextInputPos * i);
			if (InGameSystem->CheckMapLoad(NextPos) == true)
			{
				TempPos = NextPos;
			}
		}
	}
	else
	{
		Vector2D NextPos = Pos + (InNextInputPos * CharacterSpeed);
		if (InGameSystem->CheckMapLoad(NextPos) == true)
		{
			TempPos = NextPos;
		}
		else
		{
			Vector2D LastMovePos = GetVectorFromInput(LastMoveDirection);
	
			for (int i = 1; i <= CharacterSpeed; i++)
			{
				Vector2D DirectionPos = Pos + InNextInputPos * i + LastMovePos;

				if (InGameSystem->CheckMapLoad(DirectionPos) == true)
				{
					TempPos = Pos + LastMovePos;
				}
			}

		}
	}

	if (TempPos.IsZero() == false)
	{
		OutNextAdjustedPos = TempPos;
		return true;
	}

	return false;
}
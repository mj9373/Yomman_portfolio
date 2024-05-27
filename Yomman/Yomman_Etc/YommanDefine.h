#pragma once

enum class GameSystemType
{
	None = 0,
	Logo,
	InGame,
	Max,
};

enum class InputKey
{
	None = 0,
	Up,
	Down,
	Left,
	Right,
	SUBMIT,
	Max,
};

enum class MenuType
{
	None = 0,
	GamePlay,
	GameInfo,
	GameClose,
	Max,
};

enum class YommanObjectType
{
	None = 0,
	Player,
	Monster,
	Item,
	Max,
};

enum class ItemType
{
	None = 0,
	Fruit,
	Coin,
	Max,
};


struct Vector2D
{

public:
	Vector2D(int InX, int InY)
	{
		X = InX;
		Y = InY;
	}

	Vector2D() {}

	void SetVector(int InX, int InY)
	{
		X = InX;
		Y = InY;
	}

	int X = 0;
	int Y = 0;

	bool IsZero()
	{
		return X == 0 && Y == 0;
	}

	bool operator == (Vector2D& InVector)
	{
		return InVector.X == X && InVector.Y == Y;
	}
	void operator = (Vector2D InVector)
	{
		X = InVector.X;
		Y = InVector.Y;
	}

	Vector2D operator + (Vector2D InVector)
	{
		InVector.X += X;
		InVector.Y += Y;

		return InVector;
	}

	Vector2D operator * (int InValue)
	{
		X *= InValue;
		Y *= InValue;

		return Vector2D(X,Y);
	}
};
#include "Coin.h"

Coin::Coin()
{
	grade = 1;
}

void Coin::Draw()
{
	int x = Pos.X * 2 + Drawoffset.X;
	int y = Pos.Y + Drawoffset.Y;

	Gotoxy(x, y), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 1), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 2), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 3), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 4), PrintS(5, 0, 0, 0);
	PrintS(2, 4, 4, 0);
	PrintS(1, 0, 0, 0);
	PrintS(2, 4, 4, 0);
	PrintS(5, 0, 0, 1);

	Gotoxy(x, y + 5), PrintS(4, 0, 0, 0);
	PrintS(7, 4, 4, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y + 6), PrintS(4, 0, 0, 0);
	PrintS(1, 4, 4, 0);
	PrintS(1, 15, 15, 0);
	PrintS(5, 4, 4, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y + 7), PrintS(5, 0, 0, 0);
	PrintS(1, 4, 4, 0);
	PrintS(1, 15, 15, 0);
	PrintS(3, 4, 4, 0);
	PrintS(5, 0, 0, 1);

	Gotoxy(x, y + 8), PrintS(6, 0, 0, 0);
	PrintS(3, 4, 4, 0);
	PrintS(6, 0, 0, 1);

	Gotoxy(x, y + 9), PrintS(7, 0, 0, 0);
	PrintS(1, 4, 4, 0);
	PrintS(7, 0, 0, 1);

	Gotoxy(x, y + 10), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 11), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 12), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 13), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 14), PrintS(15, 0, 0, 1);

}

void Coin::Drawclear()
{
	int x = Pos.X * 2 + Drawoffset.X;
	int y = Pos.Y + Drawoffset.Y;

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

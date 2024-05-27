#include "Fruit.h"


Fruit::Fruit()
{
	grade = 20;
}

void Fruit::Draw()
{
	int x = Pos.X * 2 + Drawoffset.X;
	int y = Pos.Y + Drawoffset.Y;
	Gotoxy(x, y), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 1), PrintS(15, 0, 0, 1);

	Gotoxy(x, y + 2), PrintS(12, 0, 0, 0);
	PrintS(2, 10, 10, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y + 3), PrintS(10, 0, 0, 0);
	PrintS(4, 10, 10, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y + 4), PrintS(8, 0, 0, 0);
	PrintS(2, 10, 10, 0);
	PrintS(1, 0, 0, 0);
	PrintS(1, 10, 10, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y + 5), PrintS(7, 0, 0, 0);
	PrintS(1, 10, 10, 0);
	PrintS(3, 0, 0, 0);
	PrintS(1, 10, 10, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y + 6), PrintS(3, 0, 0, 0);
	PrintS(3, 12, 12, 0);
	PrintS(1, 10, 10, 0);
	PrintS(3, 0, 0, 0);
	PrintS(1, 10, 10, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y + 7), PrintS(2, 0, 0, 0);
	PrintS(3, 12, 12, 0);
	PrintS(1, 10, 10, 0);
	PrintS(2, 12, 12, 0);
	PrintS(1, 0, 0, 0);
	PrintS(1, 10, 10, 0);
	PrintS(5, 0, 0, 1);

	Gotoxy(x, y + 8), PrintS(2, 0, 0, 0);
	PrintS(5, 12, 12, 0);
	PrintS(1, 0, 0, 0);
	PrintS(1, 12, 12, 0);
	PrintS(1, 10, 10, 0);
	PrintS(2, 12, 12, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y + 9), PrintS(2, 0, 0, 0);
	PrintS(1, 12, 12, 0);
	PrintS(1, 15, 15, 0);
	PrintS(2, 12, 12, 0);
	PrintS(1, 0, 0, 0);
	PrintS(2, 12, 12, 0);
	PrintS(1, 10, 10, 0);
	PrintS(3, 12, 12, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y + 10), PrintS(2, 0, 0, 0);
	PrintS(2, 12, 12, 0);
	PrintS(1, 15, 15, 0);
	PrintS(1, 12, 12, 0);
	PrintS(1, 0, 0, 0);
	PrintS(6, 12, 12, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y + 11), PrintS(3, 0, 0, 0);
	PrintS(3, 12, 12, 0);
	PrintS(1, 0, 0, 0);
	PrintS(1, 12, 12, 0);
	PrintS(1, 15, 15, 0);
	PrintS(4, 12, 12, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y + 12), PrintS(7, 0, 0, 0);
	PrintS(2, 12, 12, 0);
	PrintS(1, 15, 15, 0);
	PrintS(3, 12, 12, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y + 13), PrintS(8, 0, 0, 0);
	PrintS(4, 12, 12, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y + 14), PrintS(15, 0, 0, 1);

}

void Fruit::Drawclear()
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

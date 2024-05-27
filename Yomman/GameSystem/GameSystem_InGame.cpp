#include "GameSystem_InGame.h"
#include "../Manager/GameSystemManager.h"
#include "../Character/Monster.h"
#include "../Character/Player.h"
#include "../Item/Item.h"
#include "../Item/Coin.h"
#include "../Item/Fruit.h"


GameSystem_InGame::GameSystem_InGame()
{
	GameCharacterList = nullptr;

	Score = 0;
	IsEnd = false;
	IsEndDirtmark = false;
	MaxCoinCount = 5;
}

void GameSystem_InGame::BeingPlay()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 3;
	cfi.dwFontSize.Y = 6;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, TEXT("Raster Fonts"));
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	system("mode con cols=570 lines=150");
	HANDLE consonleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consonleHandle, &ConsoleCursor);

	//. 맵 그리기
	MapDraw();

	//. 스코어 그리기
	UpdatePrintScore();

	//. 캐릭터
	{
		GameCharacterList = new Character* [4];

		//.3은 플레이어 위치
		Vector2D PlayerPos = Vector2D(0, 0);
		FindMapPos('3', PlayerPos, 1);

		Vector2D MonsterPosList[3] = { Vector2D(0, 0) , Vector2D(0, 0) , Vector2D(0, 0) };
		FindMapPos('4', MonsterPosList, 3);

		GameCharacterList[0] = new Player;
		GameCharacterList[1] = new Monster;
		GameCharacterList[2] = new Monster;
		GameCharacterList[3] = new Monster;

		GameCharacterList[0]->Start(PlayerPos.X, PlayerPos.Y, this);

		for (int i = 1; i < 4; i++)
		{
			int Index = i - 1;
			GameCharacterList[i]->Start(MonsterPosList[Index].X, MonsterPosList[Index].Y, this);
		}

	}

	// 아이템
	{
		GameItemList = new ITEM* [10];

		Vector2D CoinPosList[5] = { Vector2D(0, 0) , Vector2D(0, 0) };
		FindMapPos('k', CoinPosList, 5);

		Vector2D FruitPosList[5] = { Vector2D(0, 0) , Vector2D(0, 0) };
		FindMapPos('a', FruitPosList, 5);

		GameItemList[0] = new Fruit; 
		GameItemList[0]->Start(FruitPosList[0].X, FruitPosList[0].Y);
		GameItemList[1] = new Fruit;
		GameItemList[1]->Start(FruitPosList[1].X, FruitPosList[1].Y);
		GameItemList[2] = new Fruit;
		GameItemList[2]->Start(FruitPosList[2].X, FruitPosList[2].Y);
		GameItemList[3] = new Fruit;
		GameItemList[3]->Start(FruitPosList[3].X, FruitPosList[3].Y);
		GameItemList[4] = new Fruit;
		GameItemList[4]->Start(FruitPosList[4].X, FruitPosList[4].Y);
		GameItemList[5] = new Coin;
		GameItemList[5]->Start(CoinPosList[0].X, CoinPosList[0].Y);
		GameItemList[6] = new Coin;
		GameItemList[6]->Start(CoinPosList[1].X, CoinPosList[1].Y);
		GameItemList[7] = new Coin;
		GameItemList[7]->Start(CoinPosList[2].X, CoinPosList[2].Y);
		GameItemList[8] = new Coin;
		GameItemList[8]->Start(CoinPosList[3].X, CoinPosList[3].Y);
		GameItemList[9] = new Coin;
		GameItemList[9]->Start(CoinPosList[4].X, CoinPosList[4].Y);
		GameItemList[9] = new Coin;
		GameItemList[9]->Start(CoinPosList[4].X, CoinPosList[4].Y);
	}
} 

void GameSystem_InGame::MapDraw()
{
	system("cls");
	int h, w;
	for (h = 0; h < 97; h++)
	{
		
		for (w = 0; w < 286; w++)
		{		
			char temp = map[h][w];
			if (temp == '0' || temp == '8' || temp == 'a')
			{
				TextColor(0, 0);
				cout << "  ";
			}
			else if (temp == '1')
			{
				TextColor(15, 15);
				cout << "##";
			}
			else if (temp == '2' || temp == 'k')
			{
				TextColor(0, 0);
				cout << "ii";
			}
			else if (temp == '3')
			{
				TextColor(5, 0);
				cout << "##";
			}
			else if (temp == '4')
			{
				TextColor(9, 0);
				cout << "##";
			}
		} 

		cout << ("\n");
	}

	TextColor(15, 0);
}

void GameSystem_InGame::End()
{
	for (int i = 0; i < 4; i++)
	{//직접 배열 값에 접근을 해서 지운거고
		delete GameCharacterList[i];
	}//배열(리스트)를 지운거

	delete[] GameCharacterList;

	GameCharacterList = nullptr;
	Score = 0;
	CurretnCoinCount = 0;

	IsEnd = false;
	IsEndDirtmark = false;
}

void GameSystem_InGame::Update(int InSleepTime)
{
	if (IsEnd == true)
		return;

	for (int i = 0; i < 4; i++)
	{
		GameCharacterList[i]->Update(InSleepTime);
	}

	HitCheck();

	if (IsEndDirtmark == true)
		OnEndGame();
}

void GameSystem_InGame::InputEvent(InputKey InKey)
{
	GameCharacterList[0]->InputEvent(InKey);
}

void GameSystem_InGame::UpdateRander()
{
	if (IsEnd == true)
		return;

	for (int i = 0; i < 4; i++)
	{
		GameCharacterList[i]->Drawclear();
		GameCharacterList[i]->Draw();
	}

	for (int i = 0; i < 10; i++)
	{
		if (GameItemList[i]->GetIsActive() == true)
			GameItemList[i]->Draw();
	}

}

bool GameSystem_InGame::CheckMapLoad(Vector2D& InPos)
{
	if (InPos.X >= 286 || InPos.Y >= 97)
		return false;

	if (InPos.IsZero() == true)
		return false;

	char Temp = map[InPos.Y][InPos.X];

	//. 1은 벽 0은 빈공간  .. 캐릭터 스폰을 위한 3,4 사용
	if (Temp == '1')
		return false;

	if (Temp == '0')
		return false;

	return true;
}

char GameSystem_InGame::GetMapData(Vector2D& InPos)
{
	if (InPos.X >= 286 || InPos.Y >= 97)
		return false;

	return  map[InPos.Y][InPos.X];
}

void GameSystem_InGame::HitCheck()
{
	for (int i = 0; i < 3 ; i++)
	{
		for (int j = i; j < 4; j++)
		{
			// 세로 체크
			if (GameCharacterList[i]->GetObjectPos().X == GameCharacterList[j]->GetObjectPos().X)
			{
				int Distance = abs(GameCharacterList[i]->GetObjectPos().Y - GameCharacterList[j]->GetObjectPos().Y);

				if (Distance < 7) // 세로 Offset크기
				{
					GameCharacterList[i]->OnHitObject(GameCharacterList[j]);
					GameCharacterList[j]->OnHitObject(GameCharacterList[i]);
				}
			}
			// 가로 체크
			else  if (GameCharacterList[i]->GetObjectPos().Y == GameCharacterList[j]->GetObjectPos().Y)
			{
				int Distance = abs(GameCharacterList[i]->GetObjectPos().X - GameCharacterList[j]->GetObjectPos().X);

				if (Distance < 14) // 가로 Offset크기
				{
					GameCharacterList[i]->OnHitObject(GameCharacterList[j]);
					GameCharacterList[j]->OnHitObject(GameCharacterList[i]);
				}
			}
		}

		if (GameCharacterList[i]->GetObjectType() == YommanObjectType::Player)
		{
			for (int j = 0; j < 10; j++)
			{
				if (GameItemList[j]->GetIsActive() == true)
				{

					// 세로 체크
					if (GameCharacterList[i]->GetObjectPos().X == GameItemList[j]->GetObjectPos().X)
					{
						int Distance = abs(GameCharacterList[i]->GetObjectPos().Y - GameItemList[j]->GetObjectPos().Y);

						if (Distance < 7) // 세로 Offset크기
						{
							GameCharacterList[i]->OnHitObject(GameItemList[j]);
							GameItemList[j]->OnHitObject(GameCharacterList[i]);
						}
					}
					// 가로 체크
					else  if (GameCharacterList[i]->GetObjectPos().Y == GameItemList[j]->GetObjectPos().Y)
					{
						int Distance = abs(GameCharacterList[i]->GetObjectPos().X - GameItemList[j]->GetObjectPos().X);

						if (Distance < 14) // 가로 Offset크기
						{
							GameCharacterList[i]->OnHitObject(GameItemList[j]);
							GameItemList[j]->OnHitObject(GameCharacterList[i]);
						}
					}
				}
			}
		}
	}
}

void GameSystem_InGame::AddScore(int InScore)
{
	Score += InScore;

	UpdatePrintScore();
}

void GameSystem_InGame::AddCoinCount()
{
	++CurretnCoinCount;

	if (CurretnCoinCount >= MaxCoinCount)
		SetGameEnd();
}

void GameSystem_InGame::SetGameEnd()
{
	IsEndDirtmark = true;
}

void GameSystem_InGame::GameEndInfo()
{
	system("mode con cols=230 lines=60");
	HANDLE consonleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consonleHandle, &ConsoleCursor);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 7;
	cfi.dwFontSize.Y = 14;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, TEXT("Raster Fonts"));
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	int x = 80, y = 30;

	Gotoxy(x + 10, y - 17), PrintS(6, 15, 15, 0);
	PrintS(4, 0, 0, 0);
	PrintS(3, 14, 14, 0);
	PrintS(4, 0, 0, 0);
	PrintS(4, 15, 15, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x + 10, y - 16), PrintS(1, 15, 15, 0);
	PrintS(8, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(3, 0, 0, 0);
	PrintS(1, 15, 15, 0);
	PrintS(3, 0, 0, 0);
	PrintS(1, 15, 15, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x + 10, y - 15), PrintS(1, 15, 15, 0);
	PrintS(7, 0, 0, 0);
	PrintS(7, 14, 14, 0);
	PrintS(2, 0, 0, 0);
	PrintS(1, 15, 15, 0);
	PrintS(4, 0, 0, 0);
	PrintS(1, 15, 15, 1);

	Gotoxy(x + 10, y - 14), PrintS(6, 15, 15, 0);
	PrintS(2, 0, 0, 0);
	PrintS(3, 14, 14, 0);
	PrintS(1, 0, 0, 0);
	PrintS(3, 14, 14, 0);
	PrintS(2, 0, 0, 0);
	PrintS(1, 15, 15, 0);
	PrintS(4, 0, 0, 0);
	PrintS(1, 15, 15, 1);

	Gotoxy(x + 10, y - 13), PrintS(1, 15, 15, 0);
	PrintS(7, 0, 0, 0);
	PrintS(2, 14, 14, 0);
	PrintS(3, 0, 0, 0);
	PrintS(2, 14, 14, 0);
	PrintS(2, 0, 0, 0);
	PrintS(1, 15, 15, 0);
	PrintS(4, 0, 0, 0);
	PrintS(1, 15, 15, 1);

	Gotoxy(x + 10, y - 12), PrintS(1, 15, 15, 0);
	PrintS(7, 0, 0, 0);
	PrintS(1, 14, 14, 0);
	PrintS(5, 0, 0, 0);
	PrintS(1, 14, 14, 0);
	PrintS(2, 0, 0, 0);
	PrintS(1, 15, 15, 0);
	PrintS(3, 0, 0, 0);
	PrintS(1, 15, 15, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x + 10, y - 11), PrintS(6, 15, 15, 0);
	PrintS(2, 0, 0, 0);
	PrintS(1, 14, 14, 0);
	PrintS(5, 0, 0, 0);
	PrintS(1, 14, 14, 0);
	PrintS(2, 0, 0, 0);
	PrintS(4, 15, 15, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y), PrintS(5, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(5, 0, 0, 1);

	Gotoxy(x, y + 1), PrintS(3, 0, 0, 0);
	PrintS(8, 14, 14, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y + 2), PrintS(2, 0, 0, 0);
	PrintS(10, 14, 14, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y + 3), PrintS(1, 0, 0, 0);
	PrintS(6, 14, 14, 0);
	PrintS(1, 8, 8, 0);
	PrintS(5, 14, 14, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y + 4), PrintS(1, 0, 0, 0);
	PrintS(6, 14, 14, 0);
	PrintS(1, 8, 8, 0);
	PrintS(6, 14, 14, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y + 5), PrintS(12, 14, 14, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y + 6), PrintS(9, 14, 14, 0);
	PrintS(6, 0, 0, 1);

	Gotoxy(x, y + 7), PrintS(6, 14, 14, 0);
	PrintS(9, 0, 0, 1);

	Gotoxy(x, y + 8), PrintS(9, 14, 14, 0);
	PrintS(6, 0, 0, 1);

	Gotoxy(x, y + 9), PrintS(12, 14, 14, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y + 10), PrintS(1, 0, 0, 0);
	PrintS(13, 14, 14, 0);
	PrintS(1, 0, 0, 1);

	Gotoxy(x, y + 11), PrintS(1, 0, 0, 0);
	PrintS(12, 14, 14, 0);
	PrintS(2, 0, 0, 1);

	Gotoxy(x, y + 12), PrintS(2, 0, 0, 0);
	PrintS(10, 14, 14, 0);
	PrintS(3, 0, 0, 1);

	Gotoxy(x, y + 13), PrintS(3, 0, 0, 0);
	PrintS(8, 14, 14, 0);
	PrintS(4, 0, 0, 1);

	Gotoxy(x, y + 14), PrintS(5, 0, 0, 0);
	PrintS(5, 14, 14, 0);
	PrintS(5, 0, 0, 1);

	Gotoxy(x + 50, y + 7);
	TextColor(15, 0);
	cout << "Score ::  " << Score;
}

void GameSystem_InGame::OnEndGame()
{
	if (IsEnd == true)
		return;

	IsEnd = true;

	if (Manager != nullptr)
		GameEndInfo();
		Sleep(3000);
		Manager->ChangeSystem(GameSystemType::Logo);
}

void GameSystem_InGame::UpdatePrintScore()
{
	Gotoxy(286, 99);
	TextColor(15,0);
	cout << "Score ::  "<< Score;
}

bool GameSystem_InGame::FindMapPos(char InFindText, Vector2D& OutPos, int InSize)
{
	int FindCount = 0;

	for (int h = 0; h < 97; h++)
	{
		for (int w = 0; w < 286; w++)
		{
			if (map[h][w] == InFindText)
			{
				OutPos = Vector2D(w, h);
				return true;
			}
		}
	}

	return false;
}

bool GameSystem_InGame::FindMapPos(char InFindText, Vector2D* OutPos, int InSize)
{
	int Findcount = 0;

	if (OutPos != nullptr)
	{
		for (int h = 0; h < 97; h++)
		{
			for (int w = 0; w < 286; w++)
			{
				if (map[h][w] == InFindText)
				{
					*OutPos = Vector2D(w, h);
					OutPos++;

					++Findcount;

					if (Findcount == InSize)
						return true;
				}
			}
		}
	}




	return false;
}

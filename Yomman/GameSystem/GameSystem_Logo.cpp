#include "GameSystem_Logo.h"
#include "../Manager/GameSystemManager.h"



GameSystem_Logo::GameSystem_Logo()
{
	
}



void GameSystem_Logo::BeingPlay()
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

    system("cls");


    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);

    PrintS(24, 0, 0, 0);
    PrintS(8, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(8, 11, 11, 0);
    PrintS(6, 0, 0, 0);
    PrintS(6, 11, 11, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(10, 0, 0, 1);

    PrintS(28, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 0);
    PrintS(6, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(6, 11, 11, 0);
    PrintS(8, 0, 0, 1);

    PrintS(28, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(10, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(2, 0, 0, 0);
    PrintS(8, 11, 11, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 1);

    PrintS(28, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(10, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 1);

    PrintS(30, 0, 0, 0);
    PrintS(8, 11, 11, 0);
    PrintS(6, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(10, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 1);

    PrintS(30, 0, 0, 0);
    PrintS(8, 11, 11, 0);
    PrintS(6, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(10, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 1);

    PrintS(32, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(10, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 1);

    PrintS(32, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(10, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 1);

    PrintS(32, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(10, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 1);

    PrintS(32, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(14, 0, 0, 0);
    PrintS(6, 11, 11, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 11, 11, 0);
    PrintS(6, 0, 0, 1);

    PrintS(90, 0, 0, 1);
    PrintS(90, 0, 0, 1);

    PrintS(30, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(10, 0, 0, 0);
    PrintS(2, 12, 12, 0);
    PrintS(10, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(28, 0, 0, 0);
    PrintS(6, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(6, 12, 12, 0);
    PrintS(6, 0, 0, 0);
    PrintS(12, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(6, 12, 12, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(26, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(8, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(8, 12, 12, 0);
    PrintS(6, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(26, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(26, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(26, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(16, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(26, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(16, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(4, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(26, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(6, 0, 0, 0);
    PrintS(8, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(26, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(8, 0, 0, 0);
    PrintS(6, 12, 12, 0);
    PrintS(6, 0, 0, 1);

    PrintS(26, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(12, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(8, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(2, 0, 0, 0);
    PrintS(4, 12, 12, 0);
    PrintS(10, 0, 0, 0);
    PrintS(2, 12, 12, 0);
    PrintS(8, 0, 0, 1);

    Menu_Draw();
    

}


//keyControl���� ���� ���� ���������� �ٲپ� ����
void GameSystem_Logo::InputEvent(InputKey InKey)
{
        
        switch (InKey)
        {
            case InputKey::Up:
            {
                if (y > 40)
                {
                    Gotoxy(x - 2, y);
                    cout << " ";
                    Gotoxy(x - 2, --y);
                    cout << ">";
                }
                break;
            }
            case InputKey::Down:
            {
                if (y < 41)
                {
                    Gotoxy(x - 2, y);
                    cout << " ";
                    Gotoxy(x - 2, ++y);
                    cout << ">";
                }
                break;
            }

            case InputKey::SUBMIT:
            {
                
                 if (y == 40)
                {
                     (*Manager).ChangeSystem(GameSystemType::InGame);
                }
                 else if (y == 41)
                 {
                     InfoS();

                 }


            }

            default:
            break;
        }

}



void GameSystem_Logo::End()
{
    system("cls");
}





int GameSystem_Logo::Menu_Draw()
{
    TextColor(15, 0);
    int x = 108;
    int y = 40;

    Gotoxy(x - 2, y);
    cout << "> ���ӽ���";
    Gotoxy(x, y + 1);
    cout << "���۹��";


    return  0;
    

}


void GameSystem_Logo::InfoS()
{
    
    system("cls");
    int x = 100;
    int y = 20;
    TextColor(15, 0);

    Gotoxy(x, y);
    cout << " <���۹�>" << endl;
    Gotoxy(x, y + 2);
    cout << "�̵� : W, S, A, D, ��, ��, ��, ��" << endl;
    Gotoxy(x, y + 4);
    cout << "���� : �����̽���" << endl;
    Gotoxy(x, y + 6);
    cout << "3�� �� Ÿ��Ʋ ȭ������ ���ư��ϴ�." << endl;
 
    Sleep(3000);
    Manager->ChangeSystem(GameSystemType::Logo);

}


MenuType MenuChange()
{
    int y = 40;

    if (y == 40)
    {
        return MenuType::GamePlay;
    }

    else if (y == 41)
    {
        return MenuType::GameInfo;
    }

    else
    {
        return MenuType::None;
    }
};

   
// include
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <cwchar>
#include <iostream>
#include <graphics.h>

// varible
#define ll long long
#define db double
#define str string
#define chr char
#define ull unsigned ll
#define ld long double
#define Cls system("cls")

// repeat
#define lap(i, a, b) for (ll i = a; i <= b; i++)
#define rlap(i, a, b) for (ll i = a; i >= b; i--)
#define mlap(i, a, b, c) for (ll i = a; i <= b; i += c)

using namespace std;

bool setup_complete = false;
bool Complete, Result;

char word100 = 254;

int option = 1;
int board_size = 9;
int check_left;
int maxi, maxj;
char board[100][100];
char check[100][100];
int bomb;
int pos_x = 1, pos_y = 1;

void ingame();
int main();

bool first_time;
string name;
int win, lose;
void getdata()
{
    ifstream c;
    c.open("player.data");
    c >> first_time >> name >> win >> lose;
    c.close();
}
void syncdata()
{
    ofstream c;
    c.open("player.data");
    c << first_time << " " << name << " " << win << " " << lose << endl;
    c << "firsttime - name - win - lose";
    // firsttime - name - coins - exp - total - win - lose - scored
    c.close();
}

int game_difficulty_num = 0;
string game_difficulty[4] = {"Beginner", "Intermediate", "Expert", "Custom"};

int undis_color_num = 0;
string undis_color[5] = {
    "GREEN",
    "WHITE",
    "AQUA",
    "BLUE",
    "GRAY"

};

int warn_color_num = 0;
string warn_color[3] = {
    "YELLOW",
    "PURPLE",
    "PINK",
};

string ucolor_player = undis_color[undis_color_num];
string wcolor_player = warn_color[warn_color_num];

int timer = 120;

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetColor(string color)
{
    if (color == "WHITE")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 15);
    }
    else if (color == "GREEN")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 2);
    }
    else if (color == "YELLOW")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 6);
    }
    else if (color == "RED")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 12);
    }
    else if (color == "BLACK")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 0);
    }
    else if (color == "PINK")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 13);
    }
    else if (color == "BLUE")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 1);
    }
    else if (color == "AQUA")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 3);
    }
    else if (color == "GRAY")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 8);
    }
    else if (color == "PURPLE")
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 5);
    }
}
void PrintColorText(string s, string color)
{
    SetColor(color);
    cout << s;
    SetColor("WHITE");
}

void PrintColorBox(char s, string color)
{
    SetColor(color);
    cout << s;
    SetColor("WHITE");
}

void Game();
// fix lỗi first turn
bool first_turn = true;

// NEEDED
// đếm bom xung quanh 1 ô
int count_bomb_around(int i, int j)
{
    int count = 0;
    if (board[i - 1][j] == 'B')
        count++;
    if (board[i - 1][j - 1] == 'B')
        count++;
    if (board[i - 1][j + 1] == 'B')
        count++;
    if (board[i][j + 1] == 'B')
        count++;
    if (board[i][j - 1] == 'B')
        count++;
    if (board[i + 1][j - 1] == 'B')
        count++;
    if (board[i + 1][j] == 'B')
        count++;
    if (board[i + 1][j + 1] == 'B')
        count++;
    return count;
}
void Generate_Board()
{

    // undiscovered: U
    // discovered: D
    // bomb: B
    // warn W

    if (game_difficulty_num == 0)
    {
        bomb = 10;
        maxi = 9;
        maxj = 9;
        check_left = 10;
    }
    else if (game_difficulty_num == 1)
    {
        bomb = 40;
        maxi = 16;
        maxj = 16;
        check_left = 20;
    }
    else if (game_difficulty_num == 2)
    {
        bomb = 90;
        maxi = 16;
        maxj = 30;
        check_left = 100;
    }
    // ELSE IF ...

    lap(i, 1, maxi)
    {
        lap(j, 1, maxj)
        {
            board[i][j] = word100;
        }
    }
    // 9x9: 24 bomb
    // 16x16: 30 bomb

    // GENERATE BOMB
    int placed_bomb = 1, row, col, r;
    while (placed_bomb <= bomb)
    {
        int i = rand() % maxi + 1;
        int j = rand() % maxj + 1;
        if (board[i][j] != 'B' && count_bomb_around(i, j) <= 3)
        {
            board[i][j] = 'B';
            placed_bomb++;
        }
        // cout << "Times: " << placed_bomb << " Coord:" << i << " " << j << endl;
    }

    lap(i, 1, maxi)
    {
        lap(j, 1, maxj)
        {
            if (board[i][j] != 'B')
                board[i][j] = count_bomb_around(i, j) + 48;
        }
    }
}
void checkEmptyField(int i, int j)
{
    if (i >= 1 && j >= 1 && i <= maxi && j <= maxj)
    {
        if (board[i][j] == '0' && !check[i][j])
        {
            if (check[i][j] == 'W')
                check_left++;
            check[i][j] = 'T';
            checkEmptyField(i - 1, j - 1);
            checkEmptyField(i, j - 1);
            checkEmptyField(i + 1, j - 1);
            checkEmptyField(i - 1, j);
            checkEmptyField(i + 1, j);
            checkEmptyField(i - 1, j + 1);
            checkEmptyField(i, j + 1);
            checkEmptyField(i + 1, j + 1);
        }
        else
        {
            // cout << "\n Checked: " << i << " " << j << endl;
            if (check[i][j] == 'W')
                check_left++;
            check[i][j] = 'T';
        }
    }
}
void reset()
{
    pos_x = 1, pos_y = 1;
    Complete = false;
    first_turn = true;
    if (game_difficulty_num == 0)
    {
        bomb = 10;
        maxi = 9;
        maxj = 9;
        check_left = 10;
    }
    else if (game_difficulty_num == 1)
    {
        bomb = 40;
        maxi = 16;
        maxj = 16;
        check_left = 20;
    }
    else if (game_difficulty_num == 2)
    {
        bomb = 90;
        maxi = 16;
        maxj = 30;
        check_left = 100;
    }
    lap(i, 1, maxi)
    {
        lap(j, 1, maxj)
        {
            board[i][j] = false;
            check[i][j] = false;
        }
    }
}
void reset_keep()
{
    pos_x = 1, pos_y = 1;
    Complete = false;
    lap(i, 1, maxi)
    {
        lap(j, 1, maxj)
        {
            check[i][j] = false;
        }
    }
    if (game_difficulty_num == 0)
    {
        bomb = 10;
        maxi = 9;
        maxj = 9;
        check_left = 10;
    }
    else if (game_difficulty_num == 1)
    {
        bomb = 40;
        maxi = 16;
        maxj = 16;
        check_left = 20;
    }
    else if (game_difficulty_num == 2)
    {
        bomb = 90;
        maxi = 16;
        maxj = 30;
        check_left = 100;
    }
}
void number(int chuso, int sochuso)
{
    if (sochuso == 3)
    {
        if (chuso < 10)
            cout << "00" << chuso;
        else if (chuso < 100)
            cout << "0" << chuso;
        else
            cout << 100;
    }
    else if (sochuso == 2)
    {
        if (chuso < 10)
            cout << "0" << chuso;
        else
            cout << chuso;
    }
}
void CheckGetLost()
{
    if (board[pos_x][pos_y] != '0')
    {
        while (board[pos_x][pos_y] != '0')
        {
            reset();
            Generate_Board();
        }
    }
    first_turn = false;
}
// first time get bombed

void ShowBoard()
{
    // Cls; cout << "Clear Screen\n";
    //
    cout << "+----------------------------------------------------------------------+\n";
    if (game_difficulty_num == 0)
    {
        cout << "|       [Difficulty: Beginner]       [:)]        [Tick Left: ";
        number(check_left, 2);
        cout << "]       |\n";
    }
    else if (game_difficulty_num == 1)
    {
        cout << "|     [Difficulty: Intermediate]       [:)]        [Tick Left: ";
        number(check_left, 2);
        cout << "]     |\n";
    }
    else if (game_difficulty_num == 2)
    {
        cout << "|       [Difficulty: Expert]       [:)]        [Tick Left: ";
        number(check_left, 3);
        cout << "]        |\n";
    }
    cout << "+----------------------------------------------------------------------+\n";

    if (game_difficulty_num == 0)
        lap(t, 1, 3) cout << "|                                                                      |\n";
    lap(i, 1, maxi)
    {
        if (game_difficulty_num == 0)
            cout << "|                          ";
        else if (game_difficulty_num == 1)
            cout << "|                  ";
        else if (game_difficulty_num == 2)
            cout << "|     ";
        lap(j, 1, maxj)
        {
            if (i == pos_x && j == 1 && pos_y == j)
                cout << "|";
            else if (j == 1)
                cout << " ";
            if (check[i][j] == false)
                PrintColorBox(word100, ucolor_player);
            else if (check[i][j] == 'W')
                PrintColorBox(word100, wcolor_player);
            else if (check[i][j] == 'T')
            {
                if (board[i][j] == '0')
                    cout << " ";
                else if (board[i][j] == 'B')
                    PrintColorBox('*', "RED");
                else
                    PrintColorBox(board[i][j], "WHITE");
            }
            if ((i == pos_x && j == pos_y) || (i == pos_x && j + 1 == pos_y))
                cout << "|";
            else
                cout << " ";
        }
        if (game_difficulty_num == 0)
            cout << "                         |\n";
        else if (game_difficulty_num == 1)
            cout << "                   |\n";
        else if (game_difficulty_num == 2)
            cout << "    |\n";
    }
    if (game_difficulty_num == 0)
        lap(t, 1, 4) cout << "|                                                                      |\n";
    cout << "+----------------------------------------------------------------------+\n   [WASD/Arrow Key]: Control  | [E]: Tick | [Enter]: Click | [R] Reset";
}
void UserInput()
{
    int change = option;
    while (change == option)
    {
        if (GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP))
        { 
            if (pos_x != 1)
                pos_x--;
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN))
        {
            if (pos_x != maxi)
                pos_x++;
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT))
        {
            if (pos_y != maxj)
                pos_y++;
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT))
        {
            if (pos_y != 1)
            {
                pos_y--;
                // GetCurSorAddedForX(1);
            }
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState(VK_RETURN))
        {
            if (!check[pos_x][pos_y])
            {
                if (first_turn)
                {
                    CheckGetLost();
                }
                checkEmptyField(pos_x, pos_y);
                check[pos_x][pos_y] = 'T';
            }

            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState('E'))
        {
            if (!check[pos_x][pos_y] && check_left != 0)
            {
                check[pos_x][pos_y] = 'W';
                check_left--;
            }
            else if (check[pos_x][pos_y] == 'W')
            {
                check[pos_x][pos_y] = false;
                check_left++;
            }
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState('R'))
        {
            reset();
            gotoxy(0, 0);
            ingame();
        }
    }
    // Cls; cout << "Clear Screen\n";
}
void CheckResult()
{
    int TotalBoxRemove = maxi * maxj - bomb;
    int Correct = 0;
    lap(i, 1, maxi)
    {
        lap(j, 1, maxj)
        {
            if (check[i][j] == 'T' && board[i][j] != 'B')
                Correct++;
            if (check[i][j] == 'T' && board[i][j] == 'B')
            {
                Complete = true;
                return;
            }
        }
    }
    if (Correct == TotalBoxRemove)
    {
        Complete = true;
        Result = true;
        // cout << Correct << " " << TotalBoxRemove << " " << maxi << " " << maxj << " " << bomb << endl;
        Sleep(1000);
        return;
    }
}
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void ShowBoardFinal()
{
    if (!Result)
    {
        lose++;
        syncdata();
        // Cls; cout << "Clear Screen\n";
        //
        cout << "+----------------------------------------------------------------------+\n";
        if (game_difficulty_num == 0)
        {
            cout << "|       [Difficulty: Beginner]       [:(]        [Tick Left: ";
            number(check_left, 2);
            cout << "]       |\n";
        }
        else if (game_difficulty_num == 1)
        {
            cout << "|     [Difficulty: Intermediate]       [:(]        [Tick Left: ";
            number(check_left, 2);
            cout << "]     |\n";
        }
        else if (game_difficulty_num == 2)
        {
            cout << "|       [Difficulty: Expert]       [:(]        [Tick Left: ";
            number(check_left, 3);
            cout << "]        |\n";
        }
        cout << "+----------------------------------------------------------------------+\n";

        if (game_difficulty_num == 0)
            lap(t, 1, 3) cout << "|                                                                      |\n";
        lap(i, 1, maxi)
        {
            if (game_difficulty_num == 0)
                cout << "|                          ";
            else if (game_difficulty_num == 1)
                cout << "|                  ";
            else if (game_difficulty_num == 2)
                cout << "|     ";
            lap(j, 1, maxj)
            {
                if (j == 1)
                    cout << " ";
                if (board[i][j] == 'B')
                {
                    // PlaySound(TEXT("explode.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    PrintColorBox('*', "RED");
                }
                else if (check[i][j] == false)
                    PrintColorBox(word100, ucolor_player);
                else if (check[i][j] == 'W')
                    PrintColorBox(word100, wcolor_player);
                else if (board[i][j] == 'B')
                    PrintColorBox('*', "RED");
                else if (check[i][j] == 'T')
                {
                    if (board[i][j] == '0')
                        cout << " ";
                    else
                        PrintColorBox(board[i][j], "WHITE");
                }
                cout << " ";
            }
            if (game_difficulty_num == 0)
                cout << "                         |\n";
            else if (game_difficulty_num == 1)
                cout << "                   |\n";
            else if (game_difficulty_num == 2)
                cout << "    |\n";
        }
        if (game_difficulty_num == 0)
            lap(t, 1, 4) cout << "|                                                                      |\n";
        cout << "+----------------------------------------------------------------------+\n   [S] Show All | Replay: [1] Keep Setup [2] Reset All [3] Keep Board ";
    }
    else
    {
        win++;
        syncdata();
        // Cls; cout << "Clear Screen\n";
        //
        cout << "+----------------------------------------------------------------------+\n";
        if (game_difficulty_num == 0)
        {
            cout << "|       [Difficulty: Beginner]       [:D]        [Tick Left: ";
            number(check_left, 2);
            cout << "]       |\n";
        }
        else if (game_difficulty_num == 1)
        {
            cout << "|     [Difficulty: Intermediate]       [:D]        [Tick Left: ";
            number(check_left, 2);
            cout << "]     |\n";
        }
        else if (game_difficulty_num == 2)
        {
            cout << "|       [Difficulty: Expert]       [:D]        [Tick Left: ";
            number(check_left, 3);
            cout << "]        |\n";
        }
        cout << "+----------------------------------------------------------------------+\n";

        if (game_difficulty_num == 0)
            lap(t, 1, 3) cout << "|                                                                      |\n";
        lap(i, 1, maxi)
        {
            if (game_difficulty_num == 0)
                cout << "|                          ";
            else if (game_difficulty_num == 1)
                cout << "|                  ";
            else if (game_difficulty_num == 2)
                cout << "|     ";
            lap(j, 1, maxj)
            {
                if (j == 1)
                    cout << " ";
                if (board[i][j] == 'B')
                    PrintColorBox('*', "RED");
                else if (check[i][j] == false)
                    PrintColorBox(word100, ucolor_player);
                else if (check[i][j] == 'W')
                    PrintColorBox(word100, wcolor_player);
                else if (board[i][j] == 'B')
                    PrintColorBox('*', "RED");
                else if (check[i][j] == 'T')
                {
                    if (board[i][j] == '0')
                        cout << " ";
                    else
                        PrintColorBox(board[i][j], "WHITE");
                }
                cout << " ";
            }
            if (game_difficulty_num == 0)
                cout << "                         |\n";
            else if (game_difficulty_num == 1)
                cout << "                   |\n";
            else if (game_difficulty_num == 2)
                cout << "    |\n";
        }
        if (game_difficulty_num == 0)
            lap(t, 1, 4) cout << "|                                                                      |\n";
        cout << "+----------------------------------------------------------------------+\n   [S] Show All | Replay: [1] Keep Setup [2] Reset All [3] Keep Board ";
    }
}
void ShowBoardAll()
{
    if (!Result)
    {
        // Cls; cout << "Clear Screen\n";
        //
        cout << "+----------------------------------------------------------------------+\n";
        if (game_difficulty_num == 0)
        {
            cout << "|       [Difficulty: Beginner]       [:(]        [Tick Left: ";
            number(check_left, 2);
            cout << "]       |\n";
        }
        else if (game_difficulty_num == 1)
        {
            cout << "|     [Difficulty: Intermediate]       [:(]        [Tick Left: ";
            number(check_left, 2);
            cout << "]     |\n";
        }
        else if (game_difficulty_num == 2)
        {
            cout << "|       [Difficulty: Expert]       [:(]        [Tick Left: ";
            number(check_left, 3);
            cout << "]        |\n";
        }
        cout << "+----------------------------------------------------------------------+\n";

        if (game_difficulty_num == 0)
            lap(t, 1, 3) cout << "|                                                                      |\n";
        lap(i, 1, maxi)
        {
            if (game_difficulty_num == 0)
                cout << "|                          ";
            else if (game_difficulty_num == 1)
                cout << "|                  ";
            else if (game_difficulty_num == 2)
                cout << "|     ";
            lap(j, 1, maxj)
            {
                if (j == 1)
                    cout << " ";
                if (board[i][j] == 'B')
                    PrintColorBox('*', "RED");
                else if (board[i][j] == '0')
                    cout << " ";
                else
                    PrintColorBox(board[i][j], "WHITE");
                cout << " ";
            }
            if (game_difficulty_num == 0)
                cout << "                         |\n";
            else if (game_difficulty_num == 1)
                cout << "                   |\n";
            else if (game_difficulty_num == 2)
                cout << "    |\n";
        }
        if (game_difficulty_num == 0)
            lap(t, 1, 4) cout << "|                                                                      |\n";
        cout << "+----------------------------------------------------------------------+\n   [S] Show All | Replay: [1] Keep Setup [2] Reset All [3] Keep Board ";
    }
    else
    {
        // Cls; cout << "Clear Screen\n";
        //
        cout << "+----------------------------------------------------------------------+\n";
        if (game_difficulty_num == 0)
        {
            cout << "|       [Difficulty: Beginner]       [:D]        [Tick Left: ";
            number(check_left, 2);
            cout << "]       |\n";
        }
        else if (game_difficulty_num == 1)
        {
            cout << "|     [Difficulty: Intermediate]       [:D]        [Tick Left: ";
            number(check_left, 2);
            cout << "]     |\n";
        }
        else if (game_difficulty_num == 2)
        {
            cout << "|       [Difficulty: Expert]       [:D]        [Tick Left: ";
            number(check_left, 3);
            cout << "]        |\n";
        }
        cout << "+----------------------------------------------------------------------+\n";

        if (game_difficulty_num == 0)
            lap(t, 1, 3) cout << "|                                                                      |\n";
        lap(i, 1, maxi)
        {
            if (game_difficulty_num == 0)
                cout << "|                          ";
            else if (game_difficulty_num == 1)
                cout << "|                  ";
            else if (game_difficulty_num == 2)
                cout << "|     ";
            lap(j, 1, maxj)
            {
                if (j == 1)
                    cout << " ";
                if (board[i][j] == 'B')
                    PrintColorBox('*', "RED");
                else if (board[i][j] == '0')
                    cout << " ";
                else
                    PrintColorBox(board[i][j], "WHITE");
                cout << " ";
            }
            if (game_difficulty_num == 0)
                cout << "                         |\n";
            else if (game_difficulty_num == 1)
                cout << "                   |\n";
            else if (game_difficulty_num == 2)
                cout << "    |\n";
        }
        if (game_difficulty_num == 0)
            lap(t, 1, 4) cout << "|                                                                      |\n";
        cout << "+----------------------------------------------------------------------+\n   [S] Show All | Replay: [1] Keep Setup [2] Reset All [3] Keep Board ";
    }
}
void UserInputFinal()
{
    while (1)
    {
        if (GetAsyncKeyState('1'))
        {
            reset();
            gotoxy(0, 0);
            ingame();
        }
        else if (GetAsyncKeyState('2'))
        {
            reset();
            setup_complete = false;
            Cls;
            Game();
        }
        else if (GetAsyncKeyState('3'))
        {
            reset_keep();
            Cls;
            Game();
        }
        else if (GetAsyncKeyState('S'))
        {
            gotoxy(0, 0);
            ShowBoardAll();
        }
    }
    // Cls; cout << "Clear Screen\n";
}
void ingame()
{
    gotoxy(0, 0);
    ShowBoard();
    while (1)
    {
        hidecursor();
        gotoxy(0, 0);
        UserInput();
        ShowBoard();

        CheckResult();
        if (Complete)
            break;
    }
    if (!Result)
    {
        gotoxy(0, 0);
        ShowBoardFinal();
        while (1)
        {
            UserInputFinal();
        }
    }
    else
    {
        gotoxy(0, 0);
        ShowBoardFinal();
        while (1)
        {
            UserInputFinal();
        }
    }
}

// SETUP AREA
void UpdateGameOption()
{
    gotoxy(0, 0);
    cout << "\n\n           ______                        _____      __\n          / ____/___ _____ ___  ___     / ___/___  / /___  ______\n         / / __/ __ `/ __ `__ \\/ _ \\    \\__ \\/ _ \\/ __/ / / / __ \\\n        / /_/ / /_/ / / / / / /  __/   ___/ /  __/ /_/ /_/ / /_/ /\n        \\____/\\__,_/_/ /_/ /_/\\___/   /____/\\___/\\__/\\__,_/ .___/\n                                                         /_/\n";
    if (option == 1)
    {
        SetColor("GREEN");
        cout << "\n                     > Game Difficulty: " << game_difficulty[game_difficulty_num] << " <           \n";
        SetColor("WHITE");
    }
    else
    {
        cout << "\n                       Game Difficulty: " << game_difficulty[game_difficulty_num] << "             \n";
    }

    cout << "\n";

    if (option == 2)
    {
        SetColor("GREEN");
        cout << "                     > Undiscovered Color: " << undis_color[undis_color_num] << " <         \n";
        // SetColor("WHITE");
    }
    else
    {
        SetColor("WHITE");
        cout << "                       Undiscovered Color: " << undis_color[undis_color_num] << "            \n";
    }

    if (option == 3)
    {
        SetColor("GREEN");
        cout << "                     > Checked Color: " << warn_color[warn_color_num] << " <           \n";
        SetColor("WHITE");
    }
    else
    {
        SetColor("WHITE");
        cout << "                       Checked Color: " << warn_color[warn_color_num] << "         \n";
    }

    if (option == 4)
        PrintColorText("\n                        > Start a new game <", "GREEN");
    else
        cout << "\n                          Start a new game   ";

    if (option == 5)
        PrintColorText("\n                          > Back to menu <", "GREEN");
    else
        cout << "\n                            Back to menu  ";
        cout << "\n\n\n\n\nMinesweeper 1.0.2 Stable";

}
void UserInputSetup()
{
    while (1)
    {
        if (GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP))
        {
            if (option != 1)
                option--;
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN))
        {
            if (option != 5)
                option++;
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT))
        {
            if (option == 1 && game_difficulty_num != 2)
                game_difficulty_num++;
            else if (option == 2 && undis_color_num != 4)
                undis_color_num++;
            else if (option == 3 && warn_color_num != 2)
                warn_color_num++;
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT))
        {
            if (option == 1 && game_difficulty_num != 0)
                game_difficulty_num--;
            else if (option == 2 && undis_color_num != 0)
                undis_color_num--;
            else if (option == 3 && warn_color_num != 0)
                warn_color_num--;
            Sleep(timer);
            break;
        }
        else if (GetAsyncKeyState(VK_RETURN))
        {
            if (option == 4)
            {
                Sleep(timer);
                setup_complete = true;
                Generate_Board();
                Sleep(150);
                break;
            }
            if (option == 5)
                system("main_menu.exe");
            Sleep(timer);
        }
    }
}
void Game()
{
    system("title Minesweeper - Setup");
    while (!setup_complete)
    {
        UpdateGameOption();
        UserInputSetup();
    }
    Cls;
    ucolor_player = undis_color[undis_color_num];
    wcolor_player = warn_color[warn_color_num];
    system("title Minesweeper - Ingame");
    ingame();
}
int main()
{
    getdata();
    // REQUIPED
    resizeConsole(560, 380);
    hidecursor();
    srand(time(NULL));
    Cls;
    // SETUP
    Game();
}
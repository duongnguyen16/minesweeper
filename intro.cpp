#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
// varible
#define ll long long
#define db double
#define str string
#define chr char
#define ull unsigned ll
#define ld long double
#define Cls system("cls")

// repeat
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define mrep(i, a, b, c) for (ll i = a; i <= b; i += c)
using namespace std;

void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
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
int main()
{
    getdata();
    resizeConsole(560, 380);
    // PlaySound(TEXT("C:\\temp\\sound_test.wav"), NULL, SND_FILENAME);
    system("title Minesweeper - Starting ");
    str temp;
    hidecursor();
    Sleep(1000);
    cout << "\n\n\n\n\n\n\n                       Made by\n";
    gotoxy(0, 0);
    Sleep(1000);
    hidecursor();
    cout << "\n\n\n\n\n\n\n                       Made by\n";
    cout << "                         _____\n ";
    cout << "                       / ___/\n";
    cout << "                       / /__ \n";
    cout << "                       \\___/  \n";
    gotoxy(0, 0);
    Sleep(100);
    hidecursor();
    cout << "\n\n\n\n\n\n\n                       Made by\n";
    cout << "                         _____    __  \n ";
    cout << "                       / ___/ __/ /_ \n";
    cout << "                       / /__  /_  __/ \n";
    cout << "                       \\___/   /_/   \n";
    gotoxy(0, 0);
    Sleep(300);
    hidecursor();
    cout << "\n\n\n\n\n\n\n                       Made by\n";
    cout << "                         _____    __      __\n ";
    cout << "                       / ___/ __/ /_  __/ /_\n";
    cout << "                       / /__  /_  __/ /_  __/\n";
    cout << "                       \\___/   /_/     /_/   \n";
    gotoxy(0, 0);
    Sleep(700);
    hidecursor();
    cout << "\n\n\n\n\n\n\n                       Made by\n";
    cout << "                         _____    __      __\n ";
    cout << "                       / ___/ __/ /_  __/ /_\n";
    cout << "                       / /__  /_  __/ /_  __/\n";
    cout << "                       \\___/   /_/     /_/   \n";
    cout << "                                   with MinGW Complier\n";
    Sleep(1000);
    Sleep(700);
    Cls;
    rep(i, 1, 6)
    {
        gotoxy(0, 0);
        if (i == 1)
            SetColor("WHITE");
        else if (i == 2)
            SetColor("GREEN");
        else if (i == 3)
            SetColor("YELLOW");
        else if (i == 4)
            SetColor("CYAN");
        else if (i == 5)
            SetColor("RED");
        else if (i == 6)
            SetColor("WHITE");
        hidecursor();
        cout << "\n\n\n\n\n";
        cout << "          __  ____  \n         /  |/  (_)___  ___  ______      _____  ___  ____  ___  _____\n        / /|_/ / / __ \\/ _ \\/ ___/ | /| / / _ \\/ _ \\/ __ \\/ _ \\/ ___/\n       / /  / / / / / /  __(__  )| |/ |/ /  __/  __/ /_/ /  __/ / \n      /_/  /_/_/_/ /_/\\___/____/ |__/|__/\\___/\\___/ .___/\\___/_/ \n                                                 /_/                 \n";
        Sleep(200);
    }
    SetColor("WHITE");
    if (first_time)
    {
        Sleep(1000);
        cout << "\n\n             Enter your name (no backspace): ";
        cout << "\n\n\n\n\n\n\nMinesweeper 1.0.2 Stable";
        gotoxy(45,13);
        cin >> name;
        first_time = 0;
        syncdata();
        cout << endl;
    }
    else
    {
        Sleep(1000);
        cout << "\n\n                      Press [ENTER] to start game\n\n";
        cout << "\n\n\n\n\nMinesweeper 1.0.2 Stable";
    }
    while (1)
    {
        if (GetAsyncKeyState(VK_RETURN))
        {
            system("main_menu.exe");
            break;
        }
    }
}

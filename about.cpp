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

void ShowMore()
{
    hidecursor();
    gotoxy(0, 0);
    cout << "\n\n                _                 _   \n";
    cout << "          /\\   | |               | |  \n";
    cout << "         /  \\  | |__   ___  _   _| |_ \n";
    cout << "        / /\\ \\ | '_ \\ / _ \\| | | | __|\n";
    cout << "       / ____ \\| |_) | (_) | |_| | |_ \n";
    cout << "      /_/    \\_\\_.__/ \\___/ \\__,_|\\__|\n";
    cout << "\n";
    cout << "       Version: 1.0.2 - Stable (Console)\n";
    cout << "       Release Date: 12/11/2021\n";
    cout << "       Language: C++\n";
    cout << "       Complier: GNU GCC\n";
    cout << "       OS: Windows\n";
    cout << "\n       [Enter] Go Back\n";
}
void UserInput()
{
    while (1)
    {
        if (GetAsyncKeyState(VK_RETURN))
        {
            system("main_menu.exe");
        }
    }
}

int main()
{
    Cls;
    getdata();
    resizeConsole(580, 380);
    system("title Minesweeper - More Options - About");
    ShowMore();
    UserInput();
}

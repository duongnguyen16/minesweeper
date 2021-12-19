// Written by Duong 11 Tin

// include
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

int option = 1;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void PlayerChoose()
{
    if (option == 1)
        system("core.exe");
    else if (option == 2)
        system("info.exe");
    else if (option == 3)
        system("more.exe");
    else if (option == 4)
        system("credit.exe");
    else if (option == 5)
        system("close.exe");
    else
    {
        Cls;
        cout << " _   __" << endl;
        cout << "<_> / /" << endl;
        cout << " _ | | " << endl;
        cout << "<_>| | " << endl;
        cout << "    \\_\\" << endl;
        cout << "\nSomething that occured. Game will be restarted in some seconds...";
        Sleep(3000);
        system("run.exe");
    }
}
void SetColor(int num)
{
    if (num == 0)
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 15);
    }
    else if (num == 1)
    {
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hStdOut, 2);
    }
}

void PrintColorText(string s, int color)
{
    if (color == 1)
    {
        SetColor(1);
        cout << s;
        SetColor(0);
    }
    else
    {
        SetColor(0);
        cout << s;
    }
}

void UpdateMainMenu()
{
    SetColor(17);
    cout << "\n\n\n";
    cout << "          __  ____  \n         /  |/  (_)___  ___  ______      _____  ___  ____  ___  _____\n        / /|_/ / / __ \\/ _ \\/ ___/ | /| / / _ \\/ _ \\/ __ \\/ _ \\/ ___/\n       / /  / / / / / /  __(__  )| |/ |/ /  __/  __/ /_/ /  __/ / \n      /_/  /_/_/_/ /_/\\___/____/ |__/|__/\\___/\\___/ .___/\\___/_/ \n                                                 /_/                 \n";
    // cout << "    __  __   _ \n   |  \\/  | (_)  _ _    ___   ___ __ __ __  ___   ___   _ __   ___   _ _\n   | |\\/| | | | | ' \\  / -_) (_-< \\ V  V / / -_) / -_) | '_ \\ / -_) | '_|\n   |_|  |_| |_| |_||_| \\___| /__/  \\_/\\_/  \\___| \\___| | .__/ \\___| |_|\n                                                       |_|\n\n";
    if (option == 1)
        PrintColorText("\n                            > New Game ", 1);
    else
        PrintColorText("\n                              New Game ", 0);
    if (option == 2)
        PrintColorText("\n                            > Player Info ", 1);
    else
        PrintColorText("\n                              Player Info ", 0);
    if (option == 3)
        PrintColorText("\n                            > More Option ", 1);
    else
        PrintColorText("\n                              More Option ", 0);
    if (option == 4)
        PrintColorText("\n                            > Credit ", 1);
    else
        PrintColorText("\n                              Credit ", 0);
    if (option == 5)
        PrintColorText("\n                            > Exit ", 1);
    else
        PrintColorText("\n                              Exit ", 0);
    cout << "\n\n\n                Use A/W (or Arrow key) and [Enter] to select.\n";
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, 15);
    cout << "\n\nMinesweeper 1.0.2 Stable ";
}   
void UserInput()
{
    while (1)
    {
        if (GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP))
        {
            if (option != 1)
                option--;
            Sleep(150);
            break;
        }
        else if (GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN))
        {
            if (option != 5)
                option++;
            Sleep(150);
            break;
        }
        else if (GetAsyncKeyState(VK_RETURN))
        {
            Sleep(150);
            PlayerChoose();
        }
    }
}
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

int main()
{
    resizeConsole(560, 380);

    system("title Minesweeper - Main Menu");
    // random
    srand(time(NULL));
    hidecursor();
    // clear when come back to menu
    Cls;

    while (1)
    {
        gotoxy(0, 0);
        UpdateMainMenu();
        UserInput();
    }
}
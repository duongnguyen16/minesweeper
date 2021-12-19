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
int main();
int option = 1;
int show_menu = 1;
void PlayerChoose()
{
    if (option == 1)
    {
        system("cls");
        cout << "Reset player progress will ERASE player save file and WONT be RECOVERED\nDo you want to continue (Y/n)?\n> ";
        Sleep(2000);
        while (1)
        {
            if (GetAsyncKeyState('Y'))
            {
                system("cls");
                cout << "Reset may take some seconds. Please wait...";
                Sleep(5000);
                system("del player.data");
                system("copy player_reset.data player.data");
                Cls;
                str temp1;
                cout << "Reset Completed, please restart the game.";
                while(1) {
                    cin >> temp1;
                }
            }
            else
                main();
        }
    }
    else if (option == 2)
        system("main_menu.exe");
}


void ShowMore()
{
    hidecursor();
    gotoxy(0, 0);
    cout << "\n\n\n\n          __                _   \n         /__\\ ___  ___  ___| |_ \n        / \\/// _ \\/ __|/ _ \\ __|\n       / _  \\  __/\\__ \\  __/ |_ \n       \\/ \\_/\\___||___/\\___|\\__|\n\n";
    if (option == 1)
    {
        SetColor("GREEN");
        cout << "\n       > Reset Player Progress";
        SetColor("WHITE");
    }
    else
    {
        cout << "\n         Reset Player Progress";
    }
    cout << endl;
    if (option == 2)
    {
        SetColor("GREEN");
        cout << "\n       > Go Back ";
        SetColor("WHITE");
    }
    else
    {
        cout << "\n         Go Back";
    }
}
void UserInput()
{
    int change = option;
    while (change == option)
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
            if (option != 2)
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

int main()
{
    Cls;
    getdata();
    resizeConsole(560, 380);
    system("title Minesweeper - More Options - Reset");

    str temp;

    while (1)
    {
        ShowMore();
        UserInput();
    }
}

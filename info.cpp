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

// repeat
#define rep(i, a, b) for (ll i = a; i <= b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define mrep(i, a, b, c) for (ll i = a; i <= b; i += c)

using namespace std;

bool first_time;
string name;
double win, lose;
void getdata()
{
    ifstream c;
    c.open("player.data");
    c >> first_time >> name >> win >> lose;
    c.close();
}
void animate_string_faster(string s)
{
    int numstr = s.size() - 1;
    // for(int i = 0;i <= numstr/2;i++) swap (s[i],s[numstr-i]);
    for (int i = 0; i <= numstr; i++)
    {
        cout << s[i];
        Sleep(25);
    }
}

void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
int main()
{
    hidecursor();
    resizeConsole(560, 380);
    getdata();
    system("cls");
    system("title Minesweeper - Player Info");
    cout << "\n        ____  _                         ___        __ \n";
    cout << "       |  _ \\| | __ _ _   _  ___ _ __  |_ _|_ __  / _| ___  \n";
    cout << "       | |_) | |/ _` | | | |/ _ \\ '__|  | || '_ \\| |_ / _ \\ \n";
    cout << "       |  __/| | (_| | |_| |  __/ |     | || | | |  _| (_) |\n";
    cout << "       |_|   |_|\\__,_|\\__, |\\___|_|    |___|_| |_|_|  \\___/ \n";
    cout << "                     /___ /\n";
    double total = win + lose;
    int total_name_size = 15 + name.size();
    int win_percentage;
    if (total > 0)
        win_percentage = (win / total) * 100;
    else
        win_percentage = 100;
    if (win_percentage < 0)
        win_percentage = 0;
    str rank;
    if (win_percentage == 100 && total == 0) rank = "Undefined";
    else if (win_percentage == 100 ) rank = "Legendary";
    else if (win_percentage >= 75 ) rank = "Master";
    else if (win_percentage >= 50 ) rank = "Competently";
    else if (win_percentage >= 25 ) rank = "Intermediate";
    else rank = "Newbie";
    double score = win_percentage;
    cout << "\n";
    cout << fixed << setprecision(0);
    cout << "          Your Name: " << name << endl;
    cout << endl;
    cout << "          Have played: " << total << " matches" << endl;
    cout << "          Total Wins: " << win << " matches" <<endl;
    cout << "          Total Lose: " << lose << " matches\n\n";
    cout << "          Total Score: " << score << "/100 - " << rank << endl;
    cout << "\n          [Enter]: Return to main menu" << endl;
    cout << "          [ R ]: Reset player progress (More Option)" << endl;
    cout << "\n\n  * All player progress will be saved in future update.";
    while (1)
    {
        if (GetAsyncKeyState(VK_RETURN))
        {
            system("main_menu.exe");
            break;
        }
        else if (GetAsyncKeyState('R'))
        {
            system("reset.exe");
            break;
        }
    }
}

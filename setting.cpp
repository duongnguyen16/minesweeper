// Written by Duong 11 Tin

// include
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

//varible
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

// varible
char word100 = 254;

// appearance
int game_ui = 1, controller = 1;
char font_color = 'f', bg_color = '0';
void getdata_setting()
{
    ifstream c;
    c.open("setting.data");
    c >> game_ui >> controller >> font_color >> bg_color;
    c.close();
}
void apply_setting()
{
    string command = "color ";
    command = command + bg_color;
    command = command + font_color;
    const char *command2 = command.c_str();
    system(command2);
}
void syncdata_setting()
{
    ofstream c1;
    c1.open("setting.data");
    c1 << game_ui << " " << controller << " " << font_color << " " << bg_color << endl;
    c1 << "game ui - controller - font color - bg color";
    c1.close();
}
void animate_string_faster(string s)
{
    int numstr = s.size() - 1;
    //for(int i = 0;i <= numstr/2;i++) swap (s[i],s[numstr-i]);
    for (int i = 0; i <= numstr; i++)
    {
        cout << s[i];
        Sleep(25);
    }
}
bool first_time_animate = true;
int main()
{
    system("title Tic Tac Toe - Settings");
    system("cls");
    cout << endl;
    getdata_setting();
    apply_setting();
    if (first_time_animate)
    {
        animate_string_faster("| Game Setting");
        Sleep(1000);
    }
    else
        cout << "| Game Setting";
    first_time_animate = false;
    cout << "\n /1/ In game UI [";
    if (game_ui == 1)
        cout << "Number]";
    else
        cout << "Boxes]";
    cout << "\n /2/ Controller [";
    if (controller == 1)
        cout << "Number]";
    else
        cout << "Coord]";
    cout << "\n /3/ Reset";
    cout << "\n\n /0/ Back to main menu";
    cout << "\n\n> Your option: ";
    int option;
    cin >> option;
    system("cls");
    if (option == 0)
        system("main_menu.exe");
    else if (option == 1)
    {
        animate_string_faster("| In Game UI");
        cout << "\n\n";
        cout << "      1 2 3         " << word100 << " " << word100 << " " << word100 << endl;
        cout << "      4 5 6         " << word100 << " " << word100 << " " << word100 << endl;
        cout << "      7 8 9         " << word100 << " " << word100 << " " << word100 << endl;
        cout << "   [1] Number    [2] Boxes";
        if (game_ui == 1)
            cout << "\n      (now)                      ";
        else
            cout << "\n                    (now)          ";
        cout << "\n\n> Your option: ";
        cin >> game_ui;
        while (game_ui > 2 || game_ui < 0)
        {
            cout << "[!] Not Available. Please choose again:";
            cin >> game_ui;
        }
        syncdata_setting();
        main();
    }
    else if (option == 2)
    {
        animate_string_faster("| Controller");
        cout << "\n\n";
        cout << "      1 2 3         O - y" << endl;
        cout << "      4 5 6         |" << endl;
        cout << "      7 8 9         x " << endl;
        cout << "   [1] Number    [2] Coordinates";
        if (controller == 1)
            cout << "\n      (now)                      ";
        else
            cout << "\n                      (now)          ";
        cout << "\n\n> Your option: ";
        cin >> controller;
        while (controller > 2 || controller < 0)
        {
            cout << "[!] Not Available. Please choose again:";
            cin >> controller;
        }
        syncdata_setting();
        main();
    }
   
    else if (option == 3)
    {
        system("cls");
        animate_string_faster("| Reset");
        cout << endl;
        cout << "  /1/ Reset player progress" << endl;
        cout << "  /2/ Reset settings" << endl;
        cout << "  /3/ Something went wrong?" << endl;
        cout << "\n  /0/ Go back" << endl;
        cout << "\n> Your option: ";
        int reset;
        cin >> reset;
        if (reset == 0)
        {
            main();
        }
        else if (reset == 1)
        {
            system("cls");
            Sleep(500);
            cout << "Reset player progress will ERASE player save file and WONT be RECOVERED\nDo you want to continue (Type 'Yes' to continue)?\n> ";
            string user_option;
            cin >> user_option;
            if (user_option == "Yes")
            {
                system("cls");
                cout << "Reset may take some seconds. Please wait...";
                Sleep(5000);
                system("del player.data");
                system("copy player_reset.data player.data");
                system("cls");
                system("run.exe");
            }
        }
        else if (reset == 2)
        {
            system("cls");
            Sleep(500);
            cout << "Reset setting will erase setting file.\nDo you want to continue (Type 'Yes' to continue)?\n> ";
            string user_option_2;
            cin >> user_option_2;
            if (user_option_2 == "Yes")
            {
                system("cls");
                cout << "Reset may take some seconds. Please wait...";
                Sleep(5000);
                system("del setting.data");
                system("copy setting_reset.data setting.data");
                system("cls");
                system("main_menu.exe");
            }
        }
        else if (reset == 3)
        {
            system("cls");
            cout << "If the game is occured or something went wrong, you can contact the game developer.\nRestart game and back to menu in 5 seconds.";
            Sleep(5000);
            system("cls");
            system("main_menu.exe");
        }
        system("cls");
        syncdata_setting();
        main();
    }
    cout << "Wrong option.";
    Sleep(1000);
    main();
}
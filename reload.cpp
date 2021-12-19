#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
    while(1){
        system ("title Reloading Machine - Intro");
        system ("g++ intro.cpp -o ./run.exe");
        cout << "Intro reloaded!\n";
        system ("title Reloading Machine - Main Menu");
        system ("g++ main_menu.cpp -o ./main_menu.exe");
        cout << "Main Menu reloaded!\n";
        system ("title Reloading Machine - Core");
        system ("g++ Core.cpp -o ./core.exe");
        cout << "Core reloaded!\n";
        system ("title Reloading Machine - Setting");
        system ("g++ setting.cpp -o ./setting.exe");
        cout << "Setting reloaded!\n";
        system ("title Reloading Machine - Info");
        system ("g++ info.cpp -o ./info.exe");
        cout << "Info reloaded!\nType anything to restart: ";
        string temp;
        cin >> temp;
    }
} // namespace std
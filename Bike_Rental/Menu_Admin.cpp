#include "Menu_Admin.h"
#include "Menu_Glowne.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Start.h"
#include "Rejestracja.h"
#include "Logowanie.h"
#include "Logowanie_Pracownik.h"
#include "Wyswietl_Uzytkownikow.h"
#include "Wyswietl_Rezerwacje.h"
#include "Wyswietl_Reklamacje.h"
#include "Wyswietl_Rowery.h"
using namespace std;

void Menu_Admin()
{
    int x, y;
    cout << flush;
    system("PAUSE");
    system("cls");
    cout << ">>>>>>>>>>>>>>>>> MENU ADMINISTRATORA <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;

    cout << "Wybierz opcje: " << endl;
    cout << "1 -> Baza uzytkownikow " << endl;
    cout << "2 -> Baza rezerwacji" << endl;
    cout << "3 -> Baza reklamacji" << endl;
    cout << "4 -> Baza rowerow" << endl;
    cin >> x;
    cout << flush;
    system("PAUSE");
    system("cls");

    if (x == 1)
    {
        Wyswietl_Uzytkownikow();
        cout << endl << endl << "Wybierz opcje: " << endl;
        cout << "1 -> Powrot do Menu " << endl;
        cout << "2 -> Zamkniecie aplikacji " << endl;
        cin >> y;
        cout << flush;
        system("PAUSE");
        system("cls");
        if (y == 1)
            Menu_Admin();
        else if (y == 2)
            exit(0);
    }
    else if (x == 2)
    {
        Wyswietl_Rezerwacje();
        cout << endl << endl << "Wybierz opcje: " << endl;
        cout << "1 -> Powrot do Menu " << endl;
        cout << "2 -> Zamkniecie aplikacji " << endl;
        cin >> y;
        cout << flush;
        system("PAUSE");
        system("cls");
        if (y == 1)
            Menu_Admin();
        else if (y == 2)
            exit(0);
    }
    else if (x == 3)
    {
        Wyswietl_Reklamacje();
        cout << endl << endl << "Wybierz opcje: " << endl;
        cout << "1 -> Powrot do Menu " << endl;
        cout << "2 -> Zamkniecie aplikacji " << endl;
        cin >> y;
        cout << flush;
        system("PAUSE");
        system("cls");
        if (y == 1)
            Menu_Admin();
        else if (y == 2)
            exit(0);
    }
    else if (x == 4)
    {
        Wyswietl_Rowery();
        cout << endl << endl << "Wybierz opcje: " << endl;
        cout << "1 -> Powrot do Menu " << endl;
        cout << "2 -> Zamkniecie aplikacji " << endl;
        cin >> y;
        cout << flush;
        system("PAUSE");
        system("cls");
        if (y == 1)
            Menu_Admin();
        else if (y == 2)
            exit(0);
    }
    else
    {
        cout << "Wybierz 1, 2 lub 3 !" << endl;
        return;
    }
}

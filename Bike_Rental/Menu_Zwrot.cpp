#include "Menu_Zwrot.h"
#include "Menu_Rezerwacje.h"
#include "Rezerwuj.h"
#include "Modyfikuj_Id.h"
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
#include "Wypozyczenie.h"
#include "Wyswietl_Rowery.h"
#include "Modyfikuj_Id_R.h"
#include "Anuluj_Rezerwacje.h"
#include "Wyswietl_Moje_R.h"
#include "Zwrot.h"
#include "Reklamacja.h"
#include "Modyfikuj_Reklamacje.h"
using namespace std;



extern bool Udane_Wypozyczenie;
extern string login;
extern int id;



void Menu_Zwrot()
{
    int id;
    int x;
    int y = 0;
    cout << flush;
    system("PAUSE");
    system("cls");
    cout << ">>>>>>>>>>>>>>>>> MENU ZWROT <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;

    cout << "Wybierz opcje: " << endl;
    cout << "1 -> Zwroc rower " << endl;
    cout << "2 -> Zloz reklamacje" << endl;
    cin >> x;
    cout << flush;
    system("PAUSE");
    system("cls");

    if (x == 1)
    {
        Zwrot();
    }
    else if (x == 2)
    {
        Reklamacja(login);
    }
 
    else
    {
        cout << "Wybierz 1, 2 lub 3 !" << endl;
        return;
    }

    cout << endl << endl << "Wybierz opcje: " << endl;
    cout << "1 -> Powrot do Menu Glownego " << endl;
    cout << "2 -> Zamkniecie aplikacji " << endl;
    cin >> y;
    cout << flush;
    system("PAUSE");
    system("cls");
    if (y == 1)
        Menu_Glowne();
    else if (y == 2)
        exit(0);
}

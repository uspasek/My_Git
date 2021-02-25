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
using namespace std;



extern bool Udane_Wypozyczenie;
extern string login;



void Menu_Rezerwacje()
{

    int x;
    cout << flush;
    system("PAUSE");
    system("cls");
    cout << ">>>>>>>>>>>>>>>>> MENU RZERWACJE <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;

    cout << "Wybierz opcje: " << endl;
    cout << "1 -> Rezerwuj " << endl;
    cout << "2 -> Moje rezerwacje" << endl;
    cout << "3 -> Anuluj rezerwacje" << endl;
    cin >> x;
    cout << flush;
    system("PAUSE");
    system("cls");

    if (x == 1)
    {
       Rezerwuj();
    }
    else if (x == 2)
    {
        Wyswietl_Moje_R(login);
    }
    else if (x == 3)
    {
        Anuluj_Rezerwacje();
    }
    else
    {
        cout << "Wybierz 1, 2 lub 3 !" << endl;
        return;
    }
}
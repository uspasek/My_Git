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
#include "Rezerwuj.h"
#include "Menu_Rezerwacje.h"
#include "Zwrot.h"
#include "Menu_Zwrot.h"
using namespace std;

void Menu_Glowne()
{
    int x;
    cout << flush;
    system("PAUSE");
    system("cls");
    cout << ">>>>>>>>>>>>>>>>> MENU GLOWNE <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
  
    cout << "Wybierz opcje: " << endl;
    cout << "1 -> Wypozyczenie " << endl;
    cout << "2 -> Rezerwacje" << endl;
    cout << "3 -> Zwrot" << endl;
    cin >> x;
    cout << flush;
    system("PAUSE");
    system("cls");

    if (x == 1)
    {
        Wypozyczenie();
    }
    else if (x == 2)
    {
        Menu_Rezerwacje();
    }
    else if (x == 3)
    {
        Menu_Zwrot();
    }
    else
    {
        cout << "Wybierz 1, 2 lub 3 !" << endl;
        return;
    }
}

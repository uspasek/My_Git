#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Start.h"
#include "Rejestracja.h"
#include "Logowanie.h"
#include "Logowanie_Pracownik.h"
using namespace std;


void Start()
{
    int x;
    cout << ">>>>>>>>>>>>>>>>> Wypozyczalnia Rowerow <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
    cout << "W ofercie mamy: " << endl << "- rower miejski juz od 9 zl/h" << endl << "- rower gorski juz od 8 zl/h" << endl;
    cout << "- rower dzieciecy juz od 5 zl/h" << endl << endl;
    cout << "Zarejestruj sie, aby zobaczyc wiecej -->" << endl << endl << flush;
    system("PAUSE");
    system("cls");
    cout << "Wybierz opcje: " << endl;
    cout << "1 -> Zarejestruj sie " << endl;
    cout << "2 -> Zaloguj sie" << endl;
    cout << "3 -> Zaloguj sie jako Pracownik" << endl;
    cin >> x;
    cout << flush;
    system("PAUSE");
    system("cls");

    if (x == 1)
    {
        Rejestracja();
    }
    else if (x == 2)
    {
        Logowanie();
    }
    else if (x == 3)
    {
        Logowanie_Pracownik();
    }
    else
    {
        cout << "Wybierz 1, 2 lub 3 !" << endl;
        return;
    }
}

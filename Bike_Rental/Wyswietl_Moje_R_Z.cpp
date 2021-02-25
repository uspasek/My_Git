#include "Wyswietl_Moje_R_Z.h"
#include "Wyswietl_Moje_R.h"
#include "Wyswietl_Rowery.h"
#include "Wyswietl_Reklamacje.h"
#include "Wyswietl_Rezerwacje.h"
#include "Wyswietl_Uzytkownikow.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Start.h"
#include "Rejestracja.h"
#include "Logowanie.h"
#include "Logowanie_Pracownik.h"
#include "Menu_Rezerwacje.h"
using namespace std;

extern string login;

void Wyswietl_Moje_R_Z(string login)
{
    int y = 0;
    fstream plik;
    plik.open("rowery.txt");
    int rozmiar = 0;
    /* plik >> rozmiar;
     cout << rozmiar << endl;*/



    string** M = new string * [6];
    for (int i = 0; i < 9; i++)
        M[i] = new string[6];



    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            plik >> M[i][j];
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (M[i][5] == login)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << M[i][j] << " | ";
            }
            cout << endl;
        }
    }
}






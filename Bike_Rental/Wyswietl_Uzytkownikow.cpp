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
using namespace std;


void Wyswietl_Uzytkownikow()
{
    fstream plik;
    plik.open("uzytkownicy.txt");
    int rozmiar = 0;
    plik >> rozmiar;
    cout << rozmiar << endl;



    string** M = new string * [3];
    for (int i = 0; i < rozmiar; i++)
        M[i] = new string[3];



    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            plik >> M[i][j];
        }
    }

    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    plik.close();
}

#include "Inkrementacja_Reklamacja.h"
#include "Inkrementacja.h"
#include "Dodawanie.h"
#include "Rejestracja.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Start.h"
#include "Szukaj_Frazy.h"
using namespace std;

void Inkrementacja_Reklamacja()
{
    string wszystko_bez_pierwszej_linii;

    // odczyt...
    int rozmiar = 0;

    string wczytana_linia = to_string(rozmiar);

    ifstream plik_we("reklamacje.txt");
    getline(plik_we, wczytana_linia); // pierwsza linia zostanie "wyrzucona", jako niepotrzebna
    //cout << "rozmiar = " << wczytana_linia << endl;
    int x = stoi(wczytana_linia);
    //cout << "x = " << x << endl;

    // wczytanie pozosta³ych linii z pliku:
    while (getline(plik_we, wczytana_linia)) wszystko_bez_pierwszej_linii += "\n" + wczytana_linia;
    plik_we.close();


    x += 1;
    //cout << "x = " << x << endl;




    // zapis...
    ofstream plik_wy("reklamacje.txt", ios::trunc);
    wczytana_linia = to_string(x);
    //cout << "wczytana_linia = " << wczytana_linia << endl;
    plik_wy << wczytana_linia;
    plik_wy << wszystko_bez_pierwszej_linii;
    plik_wy.close();
}


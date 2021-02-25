#include "Modyfikuj_Reklamacje.h"
#include "Dodawanie.h"
#include "Rejestracja.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Start.h"
#include "Szukaj_Frazy.h"
#include "Inkrementacja.h"
#include "Inkrementacja_Reklamacja.h"
using namespace std;

extern int id;
extern string login;

void Modyfikuj_Reklamacje(int id, string login)
{
    string rozmiar;
    ifstream plik_we;
    plik_we.open("reklamacje.txt", ios::in | ios::out | ios::app);
    if (plik_we.good() == true)
    {
        plik_we >> rozmiar;
        plik_we.close();
    }

    int rozmiar_int = stoi(rozmiar);
    rozmiar_int += 1;


    string Pelne_dane;
    ofstream plik_wy;
    plik_wy.open("reklamacje.txt",ios::in | ios::out | ios::app);

    rozmiar += 1;
    rozmiar = to_string(rozmiar_int);
    string id_string = to_string(id);

    if (plik_wy.good() == true)
    {
        Pelne_dane = rozmiar + " " + login + " " + id_string + " " + "oczekujaca" ;
        plik_wy << "\n" << Pelne_dane;
        plik_we.close();
    }

    Inkrementacja_Reklamacja();
}


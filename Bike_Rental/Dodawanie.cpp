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
using namespace std;

void Dodawanie(string login, string haslo)
{
    string rozmiar;
    ifstream plik_we;
    plik_we.open("uzytkownicy.txt", ios::in | ios::out | ios::app);
    if (plik_we.good() == true)
    {
        plik_we >> rozmiar;
        //cout << "rozmiar: " << rozmiar << endl;
        plik_we.close();
    }
    //cout << "rozmiar: " << rozmiar << endl;

    int rozmiar_int = stoi(rozmiar);
    //cout << "rozmiar_int: " << rozmiar_int << endl;

    rozmiar_int += 1;

    //cout << "rozmiar_int: " << rozmiar_int << endl;

    string Pelne_dane;
    ofstream plik_wy;
    plik_wy.open("uzytkownicy.txt", ios::in | ios::out | ios::app);


    rozmiar = to_string(rozmiar_int);

    //cout << "rozmiar: " << rozmiar << endl;
    if (plik_wy.good() == true)
    {
        Pelne_dane = rozmiar + " " + login + " " + haslo;
        //cout << "Pelne dane " << Pelne_dane << endl;
        plik_wy << "\n" << Pelne_dane;
        plik_we.close();
    }

    Inkrementacja();
}

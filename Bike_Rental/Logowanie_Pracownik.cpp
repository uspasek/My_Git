#include "Logowanie_Pracownik.h"
#include "Logowanie.h"
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
#include "Szukaj_Haslo.h"
#include "Szukaj_Login.h"
#include "Menu_Admin.h"
#include "Wyswietl_Rowery.h"
#include "Wyswietl_Reklamacje.h"
using namespace std;

extern  bool Istnieje_Fraza;
extern  bool Istnieje_Haslo;

void Logowanie_Pracownik()
{
		string login, haslo;
		cout << ">>>>>>>>>>>>>>>>> LOGOWANIE DLA PRACOWNIKOW <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
		cout << "Podaj login: ";
		cin >> login;
		Szukaj_Login(login);
		while (Istnieje_Fraza != true)
		{
			cout << "Podany login nie istnieje" << endl;
			cout << "Podaj login: ";
			cin >> login;
			Szukaj_Login(login);
		}


		cout << "Podany login jest poprawny :) " << endl;
		cout << "Podaj haslo: ";
		cin >> haslo;
		Szukaj_Haslo(login, haslo);
		while (Istnieje_Haslo != true)
		{
			cout << "Podaj haslo: ";
			cin >> haslo;
			Szukaj_Haslo(login, haslo);
		}

		if (login == "admn")
		{
			cout << "Zalogowano jako Administrator" << endl;
			Menu_Admin();


		}
		else if (login == "serw")
		{
			cout << "Zalogowano jako Serwisant" << endl;
			cout << flush;
			system("PAUSE");
			system("cls");
			Wyswietl_Rowery();
			cout << endl << endl << "Nacisnij 1 aby zamknac aplikacje" << endl;
		}
		else if (login == "rekl")
		{
			cout << "Zalogowano jako Menadzer reklamacji" << endl;
			cout << flush;
			system("PAUSE");
			system("cls");
			Wyswietl_Reklamacje();
			cout << endl << endl << "Nacisnij 1 aby zamknac aplikacje" << endl;
		}

		//cout << "Logowanie zakonczone pomyslnie :)" << endl;
}

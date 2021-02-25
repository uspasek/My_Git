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
#include "Menu_Glowne.h"
using namespace std;

extern  bool Istnieje_Fraza;
extern  bool Istnieje_Haslo;
string login;

void Logowanie()
{
	string haslo;
	cout << ">>>>>>>>>>>>>>>>> LOGOWANIE <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
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
	cout << "Logowanie zakonczone pomyslnie :)" << endl;

	Menu_Glowne();
	
}

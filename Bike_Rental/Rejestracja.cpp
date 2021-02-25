#include "Rejestracja.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Start.h"
#include "Szukaj_Frazy.h"
#include "Dodawanie.h"
#include "Menu_Glowne.h"
using namespace std;

extern  bool Istnieje_Fraza;

void Rejestracja() 
{
	
	string login, haslo;
	int y = 0;
	cout << ">>>>>>>>>>>>>>>>> REJESTRACJA <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
	cout << "Podaj login: ";
	cin >> login;
	Szukaj_Frazy(login);
	while (Istnieje_Fraza == true)
	{
		cin >> login;
		Szukaj_Frazy(login);
	}
	cout << "Podany login jest poprawny :) " << endl;
	cout << "Podaj haslo, ktore zawiera dokladnie 4 znaki: ";
	cin >> haslo;
	
	while (haslo.size() != 4) //*.size() zwraca rozmiar std::string, czyli iloœæ znaków
	{
		cout << "Haslo niezgodne z wymaganiami systemu :/" << endl;
		cout << "Podaj haslo: ";
		cin >> haslo;
	}
	Dodawanie(login, haslo);
	cout << "Rejestracja zakonczona pomyslnie :)" << endl;
	
	cout << endl << endl << "Wybierz opcje: " << endl;
	cout << "1 -> Powrot do Menu Startowgo " << endl;
	cout << "2 -> Zamkniecie aplikacji " << endl;
	cin >> y;
	cout << flush;
	system("PAUSE");
	system("cls");
	if (y == 1)
		Start();
	else if (y == 2)
		exit(0);






}
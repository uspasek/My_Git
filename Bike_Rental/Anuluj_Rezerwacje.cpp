#include "Anuluj_Rezerwacje.h"
#include "Rezerwuj.h"
#include "Modyfikuj_Id.h"
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
#include "Wyswietl_Rowery.h"
#include "Modyfikuj_Id_R.h"
#include "Modyfikuj_Id_A.h"
#include "Menu_Rezerwacje.h"
#include "Wyswietl_Moje_R.h"
using namespace std;



extern bool Udane_Wypozyczenie;
extern string login;

void Anuluj_Rezerwacje()
{
	int id = 0;
	int y = 0;
	cout << flush;
	system("PAUSE");
	system("cls");
	cout << "Wybierz id roweru, ktory chcesz usunac z rezerwacji -> [ id, rodzaj, status, stan, cena, rezerwujacy]" << endl << endl;
	cout << "Baza rowerow:" << endl;
	Wyswietl_Moje_R(login);
	cin >> id;
	Modyfikuj_Id_A(id, login);
	while (Udane_Wypozyczenie != true)
	{
		cin >> id;
		Modyfikuj_Id_A(id, login);

	}

	cout << endl << endl << "Wybierz opcje: " << endl;
	cout << "1 -> Powrot do Menu Rezerwacji " << endl;
	cout << "2 -> Zamkniecie aplikacji " << endl;
	cin >> y;
	cout << flush;
	system("PAUSE");
	system("cls");
	if (y == 1)
		Menu_Rezerwacje();
	else if (y == 2)
		exit(0);
}



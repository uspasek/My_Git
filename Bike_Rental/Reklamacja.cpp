#include "Reklamacja.h"
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
#include "Modyfikuj_Reklamacje.h"
#include "Wyswietl_Moje_R.h"
#include "Menu_Zwrot.h"
#include "Wyswietl_Moje_R_Z.h"
using namespace std;



extern bool Udane_Wypozyczenie;
extern string login;
extern int id;

void Reklamacja( string login)
{
	int id;
	int y = 0;
	cout << flush;
	system("PAUSE");
	system("cls");
	cout << ">>>>>>>>>>>>>>>>> REKLAMACJE <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
	cout << "Wybierz id roweru odnosnie, ktorego chcesz zlozyc reklamacje  -> [ id, rodzaj, status, stan, cena, rezerwujacy]" << endl << endl;
	cout << "Baza rowerow:" << endl;
	Wyswietl_Moje_R_Z(login);
	cin >> id;
	Modyfikuj_Reklamacje(id, login);
	while (Udane_Wypozyczenie == true)
	{
		cin >> id;
		Modyfikuj_Reklamacje(id, login);

	}
	

	cout << endl << endl << "Wybierz opcje: " << endl;
	cout << "1 -> Powrot do Menu Zwrotu " << endl;
	cout << "2 -> Zamkniecie aplikacji " << endl;
	cin >> y;
	cout << flush;
	system("PAUSE");
	system("cls");
	if (y == 1)
		Menu_Zwrot();
	else if (y == 2)
		exit(0);
}



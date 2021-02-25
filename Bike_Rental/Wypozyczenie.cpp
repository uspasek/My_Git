#include "Wypozyczenie.h"
#include <cstdlib>
#include <string>
#include "Start.h"
#include "Szukaj_Frazy.h"
#include "Inkrementacja.h"
#include "Szukaj_Haslo.h"
#include "Szukaj_Login.h"
#include "Wyswietl_Rowery.h"
#include "Modyfikuj_Id.h"
#include "Menu_Glowne.h"

using namespace std;
extern bool Udane_Wypozyczenie;

void Wypozyczenie()
{
	int id = 0;
	int y = 0;
	cout << flush;
	system("PAUSE");
	system("cls");
	cout << ">>>>>>>>>>>>>>>>> WYPOZYCZENIE <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
	cout << "Wybierz id wolnego roweru, ktory chcesz wypozyczyc -> [ id, rodzaj, status, stan, cena, rezerwujacy]" << endl<<endl;
	cout << "Baza rowerow:" << endl;
	Wyswietl_Rowery();
	cin >> id;
	Modyfikuj_Id(id);
	while (Udane_Wypozyczenie != true)
	{
		cin >> id;
		Modyfikuj_Id(id);

	}
	cout << endl << endl << "Wybierz opcje: " << endl;
	cout << "1 -> Powrot do Menu Glownego " << endl;
	cout << "2 -> Zamkniecie aplikacji " << endl;
	cin >> y;
	cout << flush;
	system("PAUSE");
	system("cls");
	if (y == 1)
		Menu_Glowne();
	else if (y == 2)
		exit(0);
	
}


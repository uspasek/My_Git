#include "Zwrot.h"
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
#include "Wyswietl_Moje_R.h"
#include "Wyswietl_Moje_R_Z.h"
#include "Logowanie.h"
#include "Modyfikuj_Id_A.h"
#include "Modyfikuj_Id_Z.h"
#include "Menu_Zwrot.h"
using namespace std;

extern string login;
extern bool Udane_Wypozyczenie;

void Zwrot()
{
	
	int id = 0;
	int y = 0;
	cout << flush;
	system("PAUSE");
	system("cls");
	cout << ">>>>>>>>>>>>>>>>> ZWROT <<<<<<<<<<<<<<<<<<<" << endl << endl << endl;
	cout << "Wybierz id roweru, ktory chcesz oddac -> [ id, rodzaj, status, stan, cena, rezerwujacy]" << endl << endl;
	cout << "Baza rowerow:" << endl;
	Wyswietl_Moje_R_Z(login);
	cin >> id;
	Modyfikuj_Id_Z(id, login);
	while (Udane_Wypozyczenie != true)
	{
		cin >> id;
		Modyfikuj_Id_Z(id, login);

	}
	cout << "Pomyslnie dokonano oplaty :)" << endl;

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

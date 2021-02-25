#include <iostream>// ????????????????????????????????????/
#include<stdlib.h>
using namespace std;


class Uzytkownik
{
    string Imie;
    string Nazwisko;
    bool Zarejestrowany;
};

class NowyUzytkownik : public Uzytkownik 
{
public:
    string BazaLoginow[50];
    
    string login;
    string haslo;
    int i = 0;
    void Rejestracja()
    {
        cout << "Podaj login: ";
        cin >> login;
        while (i<50)
        {
            if (BazaLoginow[i] == login)
            {
                cout << "Podany login juz istnieje!" << endl;
                Rejestracja();
            }
            else if (BazaLoginow[i] != login)
                i++;
        }
        BazaLoginow[i + 1] = login;
        cout << endl << "Podaj haslo: ";
        cin >> haslo;
    }
};

class ZarejestrowanyUzytkownik : public Uzytkownik
{
    friend class Rezerwacja;
    friend class Finalizacja;

    string Login;
    string Haslo;
    string Email;
    int NumerTelefonu;

public:
    void Logowanie();
    void Wypo¿yczenie();
    void Zwrot();
    void Rezerwacja();
};

class Rezerwacja
{
    string InformacjeRezerwacji;

public:
    void Dodaj();
    void Anuluj();
    void SprawdzListeRezerwacji();
    void WybierzRodzaj();
};

class Finalizacja
{
public:
    void Zaplac();
    void ZglosUwagi();
};

class Platnosc  // bez klasy finalizacja nie mo¿na u¿yæ tek klasy
{
    bool status;
    string RodzajPlatnosci;
public:
    void PlatnoscKarta();
    void PlatnoscGotowka();
    void WyborMetodyPlatnosci();
};

class Reklamacja  // bez klasy finalizacja nie mo¿na u¿yæ tek klasy
{
    int NumerReklamacji;
    string Powod;
    bool Status;
};

class Rower
{
    bool Dostepny;
    string Rodzaj;
    int Id;
    double Cena;
    bool StanTechniczny;
};

class Miejski : Rower
{
    bool Koszyk;
};

class Gorski : Rower
{
    bool BieznikOpon;
};

class Dzieciecy : Rower
{
    bool DodatkoweKola;
};

class Pracownik
{
    string Imie;
    string Nazwisko;
    string Stanowisko;
};

class Serwisant :Pracownik
{
public:
    void Naprawa();
    void Konserwacja();
    void PrzegladTechniczny();
};

class DzialReklamacji :Pracownik
{
    Reklamacja ListaReklemacji[];
public:
    void Rozpatrywanie();
    void Uznanie();
    void Odrzucenie();
};

class Administrator :Pracownik
{
public:
    void KontrolaStrony();
};

void main()
{
    int x;
    cout << ">>>>>>>>>>>>>>>>> Wypozyczalnia Rowerow <<<<<<<<<<<<<<<<<<<" << endl<<endl<<endl ;
    cout << "W ofercie mamy: " << endl << "- rower miejski juz od 5.99 zl/h" << endl << "- rower gorski juz od 9.99 zl/h" << endl;
    cout << "- rower dzieciecy juz od 4.49 zl/h" << endl<<endl;
    cout << "Zarejestruj sie, aby zobaczyc wiecej -->" << endl <<endl<< flush;
    system("PAUSE");
    system("cls");
    cout << "Wybierz opcje: " << endl;
    cout << "1 -> Zarejestruj sie " << endl;
    cout << "2 -> Zaloguj sie" << endl;
    cin >> x;
    cout << flush;
    system("PAUSE");
    system("cls");

    if (x == 1)
    {
        NowyUzytkownik nowyUzytkownik1;
        nowyUzytkownik1.Rejestracja();
        
    }
    else if(x == 2)
    {
        //Logowanie();
    }
    else
    {
        cout << "Wybierz 1 lub 2!" << endl;
        return;
    }
  
}









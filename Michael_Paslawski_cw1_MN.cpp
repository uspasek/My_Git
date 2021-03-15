#include <iomanip>
#include <fstream>
#include <iostream>

int main(){

    //utworzenie dwoch dynamicznych tablic do przechowywania wyniku
    int x=500;

    double*tab1=new double[x];
    double*tab2=new double[x]; 
   
    //odczytywanie danych z pliku txt
    std::fstream wczytaj("plik.txt");
    //stworzenie zmiennej do licznika wezlow
    int licznik=0; 
    //klasyczny if do sprawdzenia poprawnosci otworzenego pliku
    if(wczytaj.is_open())
    {  
        //zapisanie wartosci ilosci wezlow do zmiennej licznik
        wczytaj>>licznik; 
        //przepisanie wartosci z pliku tekstowego do tablic przy uzyciu petli while
        int a=0;
        while(a<licznik)
        { 
            wczytaj>>tab1[a];
            wczytaj>>tab2[a];
            a++; //inkrementacja
        }
    } //zamkniecie pliku 
      wczytaj.close();
    //Wprowadzenie punktu interpolacji przez uzytkownika
    std::cout<<"Wprowadz punkt "<<std::endl;
    //wpisanie punktu do zmiennej
    double punkt;
    std::cin>>punkt; 
    //utworzenie zmiennej przechowujacej wynik
    double wynik=0.0;
    //Petla tworzaca sume wielomianu dla interpolacji 
    for(int i=0;i<licznik;i++)
    {
    double suma=1.0;
    //Petla liczaca
        for(int j=0;j<licznik;j++)
        {   
            if(j!=i)
            {   //obliczanie sumy
                suma=suma*(punkt-tab1[j])/(tab1[i]-tab1[j]);
            }
        } //obliczanie wyniku 
        wynik=wynik+(suma*tab2[i]); 
    }
    //Przedstawienie wyniku
    std::cout<< "Liczba wezlow -> "<<licznik<<std::endl;
    //Wyswietlenie danych wczytanych z pliku z inkrementacja numeru wezla
    for (int i=0;i<licznik;i++)
    {   
        std::cout<<"Wezel nr "<<i<<" -> ["<<tab1[i]<<", "<<tab2[i]<<"]"<<std::endl;
    }
    //wyswietlenie wyniku
    std::cout<<"\nPunkt interpolacji -> x = "<<std::setprecision(3)<<punkt<<" oraz f(x) -> "<<wynik<<std::endl<<std::endl;
 
    return 0;
}
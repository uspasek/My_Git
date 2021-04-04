#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

bool Macierz(double **f, int n, int b)
{
    //warunek, ktory konczy rekrusje danej funkcji
    if(b+1==n)
    { 
       return true; 
    }
    //zmienne dla maksymalnej wartosci i maksymalnego indeksu
    int maxI = b;
    double max = fabs(f[b][b]);
 
    //znajdywanie rzedu z maksymalna wartoscia 
    for(int i = b; i<n;i++)
    {
        if(fabs(f[i][b]>max))
        {
            maxI = i;
            max = f[i][b];
        }
    }
 
    if(maxI != b)
    { //jezeli pierwszy nie posiada najwiekszej wartosci to zamien rzedy
        for(int i=b; i<=n; i++)
        {
            swap(f[b][i],f[maxI][i]); 
        }
    }
 
    //zacznij od drugiego rzedu
    for(int i=b+1;i<n; i++)
    {   //mnoznik
        const double m = f[i][b]/f[b][b]; 
            //petla dla kolumny 
            for(int j=b; j <= n; j++)
            { 
            f[i][j] -= m*f[b][j]; 
        }
    }
    // wywolanie funkcji macierz jako rekursja 
    Macierz(f, n, ++b);
}
 
//funkcja do obliczen 
void oblicz(double **f, int s, double *wynik)
{
    s--; 
    
    for(int i = s; i>=0; i--)
    {
        double t = 0.0;
        for(int j = i; j < s; j++)
        {   // obliczanie tymczasowej sumy dla niepoliczomych wspolczynnikow
            t += wynik[j+1]*f[i][j+1]; 
        }    
        // zapisanie obliczne wynikow
        wynik[i] = (f[i][s+1] - t)/f[i][i]; // calculate result[i]
    }
}
//wyswietlanie wynikow
void wyswietl(double **f, int s, double *wynik)
{
    cout<<endl;
    cout<<"Macierz po transformacji: "<<endl;
 
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j<= s; j++)
        {
            if(j==s)
            {
                cout<<"-> ";
            }
            cout<<setprecision(2)<<f[i][j]<<"    ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Wyniki obliczen: "<<endl;
    for(int i = 0; i < s; i++)
    {
        cout<<setprecision(4)<<"x"<<i+1<<" = "<<wynik[i]<<endl;
    }
    cout<<endl;
}
 
void wyswietl_pierwotna(double **f, int s)
{       //wyswietlanie pierwotnej macierzy
        cout<<"Macierz pierwotna:"<<endl;
        
        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j<= s; j++)
            {
                if(j==s)
                {
                    cout<<"-> ";
                }
                cout<<setprecision(2)<<f[i][j]<<"    ";
            }
            cout<<endl;
        }
}
 void wyniki()
 {
    fstream wczytaj("RURL_dane2.txt");
    //licznik rownan 
    int licznik = 0; 
    
    if(wczytaj.is_open())
    {  
        //wczytaj liczbe rownan
        wczytaj >> licznik; 
        //macierz wspolczynnikow 
        double **f = new double*[licznik]; 
 
        for(int i = 0; i<=licznik; i++)
        { 
            f[i] = new double[licznik+1];
        }
 
        for(int i = 0; i<licznik; i++)
        { //wczytaj liczniki
            for(int j = 0; j<=licznik; j++)
            {
                wczytaj >> f[i][j];
            }
        }
        //wyswietl pierwotna macierz
        wyswietl_pierwotna(f, licznik);
        //jezeli dobrze obliczylo macierz
        if(Macierz(f, licznik, 0))
        { 
        //obliczanie wynikow
        double *wynik = new double[licznik]; 
        oblicz(f, licznik, wynik);
        //wyswietlanie 
        wyswietl(f, licznik, wynik);
        delete[] wynik;
        }
 
        delete[] f;
    }
 
    wczytaj.close();
 }
int main()
{
    wyniki();
    return 0;
}
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
using namespace std;

extern bool Istnieje_Fraza;
bool Udane_Wypozyczenie = false;

void Modyfikuj_Id(int id)
{
    Istnieje_Fraza = false;

   

    ifstream plik_we;
    plik_we.open("rowery.txt");
  



    string** M = new string * [6];
    for (int i = 0; i < 9; i++)
        M[i] = new string[6];



    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            plik_we >> M[i][j];
        }
    }


    plik_we.close();
   
    if (M[id-1][2] == "wolny")
    {
        M[id-1][2] = "wypozyczony";
        Udane_Wypozyczenie = true;
        cout << "Wypozyczenie roweru przebieglo pomyslnie :)"<<endl;
        //cout << "M[id-1][2] =  " << M[id-1][2] << endl;
    }
   else
    {
       // M[id-1][2] = "wolny";
        Udane_Wypozyczenie = false;
        cout << "Wybrany rower jest zajety, wybierz inny" << endl;
    }

   /* for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<< M[i][j]<< " ";
        }
        cout << endl;
    }*/

    ofstream plik_wy;
    plik_wy.open("rowery.txt", ios::trunc);

    if (plik_wy.good() == true)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                plik_wy << M[i][j]<<" " ;
            }
            plik_wy << "\n";
        }


        //plik_wy << "\n" << M[][];
        plik_wy.close();
    }

           
  
       
}


//
//9
//1 miejski wypozyczony sprawny 9
//2 gorski wolny sprawny 8
//3 dziedziecy wolny sprawny 5
//4 gorski wolny sprawny 8
//5 miejski wolny sprawny 9
//6 dziedziecy wypozyczony sprawny 5
//7 miejski wypozyczony sprawny 9
//8 gorski wolny zepsuty 8
//9 dziedziecy wolny zepsuty 5



//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main() {
//    string data;
//    string data_arr[5];
//    int usrinput;
//
//    ifstream asdf;
//    asdf.open("asd.txt");
//
//    for (int i = 0; i <= 4; i++) {
//        getline(asdf, data, '\n');
//        data_arr[i] = data;
//    }
//
//    asdf.close();
//
//    cout << "Enter a number: ";
//    cin >> usrinput;
//
//    for (int j = 1; j <= 5; j++) {
//        if (j == usrinput) {
//            data_arr[j - 1] = "8";
//        }
//    }
//
//    ofstream asdfx;
//    asdfx.open("asd.txt", ios::trunc);
//
//    for (int k = 0; k <= 4; k++) {
//        asdfx << data_arr[k] << "\n";
//    }
//
//    asdfx.close();
//
//    return 0;
//}
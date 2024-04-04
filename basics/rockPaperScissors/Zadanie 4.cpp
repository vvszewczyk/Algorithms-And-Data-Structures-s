#include <iostream>
#include <time.h>

using namespace std;

int licznik1 = 0;
int licznik2 = 0;
int liczba;
string typ;
string wyb;
string k;
string p;
string n;

int kpm()
{
    for (int i = 0; i <= licznik1 || i <= licznik2;)
    {
        cout << "Wybierz: kamien - k, papier - p, nozyce - n " << endl;
        cin >> wyb;

        srand(time(NULL));     
        liczba = rand() % 3 + 1;   //utworzenie pseudolosowego wyboru   
        cout <<"Komputer wybral: " << liczba << endl;

        switch (liczba)//utworzenie opcji mozliwych do wylosowania
        {
        case 1:
            typ = "k"; break;
        case 2:
            typ = "n"; break;
        case 3:
            typ = "p"; break;
        }


        if (wyb == typ)//warunek na remis
        {
            cout << "Remis!" << endl;
        }
        else if (((wyb == "k") && (typ == "n")) || ((wyb == "n") && (typ == "p")) || ((wyb == "p") && (typ == "k")))//warunek na wygrana
        {
            cout << "Wygrales!" << endl;
            cout << "wyb komputera: " << typ << endl;
            licznik1++;//zwiekszenie licznika puntkow uzytkownika

            if (licznik1 == 3)
            {
                cout << "Gratulacje! wygrales!" << endl; //punkty uzytkownika liczone do 3
                return 0;
            }
        }
        else
        {
            cout << "Przegrales!" << endl;
            cout << "wyb komputera: " << typ << endl;
            licznik2++; //zwiekszanie liczby punktow komputera

            if (licznik2 == 3)
            {
                cout << "Przegrales!" << endl;//punkty komputera liczone do 3
                return 0;
            }
        }
    }


}

int main()
{
    kpm();//wywolanie funkcji
    cout << endl;
    cout << endl;
    cout << "Twoj wynik: " << licznik1 << endl;                //
    cout << endl;                                              //wyswietlenie wynikow
    cout << "Wynik komputera: " << licznik2 << endl;           //
    return 0; 
}
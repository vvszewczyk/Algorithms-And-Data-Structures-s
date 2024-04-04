#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string zmienna;

int main()
{
    fstream plik("plik3.txt", ios::in);//wczytanie wartosci z pliku

    while (getline(plik, zmienna))//petla wykonujaca sie do momentu pobrania ostatniej linijki z pliku
        cout << zmienna<<endl;//wyswietlanie pobranej linijki

    plik.close();
}
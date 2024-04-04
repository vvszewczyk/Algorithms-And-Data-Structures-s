#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int liczba, wybor;
string wynik, string_liczba; 

string dziesietny_na_binarny(int dziesietnaF)
{
    string binarna; //stworzenie zmiennej przechowujacej odwrocona liczbe binarna
    while (dziesietnaF>0)
    {
        if (dziesietnaF % 2 == 1)//dodanie 1 do napisu jezeli reszta z dzielenia z dwoch jest rowna 1
            binarna += '1';
        else
            binarna += '0';//w przeciwnym wypadku dodanie 0 do napisu
        dziesietnaF /= 2;//podzielenie liczby na 2
    }

    string odwrocona = "";//stworzenie zmiennej ktora bedzie przechowywac faktyczny wynik

    for (int i=binarna.length(); i>=0; i--)//petla wykonujaca sie tyle razy ile znakow zawiera liczba binarna
    {
        odwrocona += binarna[i];//przypisanie do zmiennej wyniku
    }

    return odwrocona;//zwrocienie wyniku
}

string dziesietny_na_szesnastkowy(int dziesietnaF)
{
    string szesnastkowa; //stworzenie liczby ktora bedzie przechowywac odwrocona liczbe szesnastkowa
    while (dziesietnaF > 0)
    {
        int dzielnik = dziesietnaF % 16;//przypisanie do zmiennej reszty z dzielenia przez 16

        if (dzielnik > 9)//zamiana liczb od 10 do 15 na od A do F przy pomocy tablicy ASCII w przypadku reszty z dzielenia wiekszej od 9
            szesnastkowa += char(65 - 10 + dzielnik);
        else
            szesnastkowa += to_string(dzielnik);

        dziesietnaF /= 16;//podzielenie liczby przez 16
    }

        string odwrocona = "";//utworzenie zmiennej przechowujacej faktyczny wynik
        for (int i = szesnastkowa.length() - 1; i >= 0; i--)//odwrocenie liczby i zapisanie jej do faktycznego wyniku
            odwrocona += szesnastkowa[i];

        return odwrocona;//zwrocenie wyniku
    
}

int binarny_na_dziesietny(int liczbaF)
{
    int dziesietna = 0, wykladnik=0;
    while (liczbaF > 0)
    {
        dziesietna += pow(2, wykladnik) * (liczbaF % 10);//dodanie do zmiennej potegi liczby 2 w zaleznosci od wykladnika
            liczbaF /= 10;//podzielenie liczby przez 10
            wykladnik++;//zwiekszenie wykladnika po obrocie petli
    }
    return dziesietna;//zwrocenie liczby dziesietnej
}

string binarny_na_szesnastkowy(int liczbaF)
{
   return dziesietny_na_szesnastkowy(binarny_na_dziesietny(liczbaF));//uzycie poprzednich funkcji do zamiany na szesnastkowy (najpierw binarna na dziesietna, a potem dziesietna na szesnastkowa)

}

string osemkowy_na_binarny(string string_liczbaF)
{
    int dziesietna = strtol(string_liczbaF.c_str(), NULL, 8);//przypisanie do zmiennej wyniku funkcji konwertujacej liczbe z systemu osemkowego na dziesietny

    return dziesietny_na_binarny(dziesietna);//zwrocenie wyniku poprzez uzycie wczesniejszej funkcji zamieniajcej liczbe dziesietna na binarny
}

int szesnastkowy_na_dziesietny(string string_liczbaF)
{
    int dziesietna = strtol(string_liczbaF.c_str(), NULL, 16);//przypisanie do zmiennej wyniku funkcji konwertujacej liczbe z systemu szesnastkowego na dziesietny

    return dziesietna;//zwrocenie wyniku
}

string octalny_na_szesnastkowy(string string_liczbaF)
{
    int dziesietna = strtol(string_liczbaF.c_str(), NULL, 8);//przypisanie do zmiennej wyniku funkcji konwertujacej liczbe z systemu osemkowego na dziesietny
    return dziesietny_na_szesnastkowy(dziesietna);//zwrocenie wyniku poprzez uzycie wczesniejszej funkcji zamieniajcej liczbe dziesietna na szesnastkowy
}
int main()
{

    cout << "Wybierz konwersje: \n 1 - dziesietny na binarny \n 2 - dziesietny na heksadecymalny \n 3 - binarny na dziesietny \n 4 - binarny na szesnastkowy \n 5 - osemkowy na binarny \n 6 - szesnastkowy na dziesietny \n 7 - osemkowy na szesnastkowy \n Podanie innej wartosci spowoduje wyjscie z programu \n";
    cin >> wybor;

    switch (wybor)//wybor poszczegolnej konwersji poprzez wybor liczby od 1 do 7, w przypadku podania czegos innego - zakonczenie programu
    {
    case 1:
        cout << "Podaj liczbe w systemie dziesietnym: ";
        cin >> liczba;
        cout << "Podana liczba w systemie binarnym: "<< dziesietny_na_binarny(liczba);
        break;
    case 2:
        cout << "Podaj liczbe w systemie dziesietnym: ";
        cin >> liczba;
        cout <<"Podana liczba w systemie szesnastkowym: "<< dziesietny_na_szesnastkowy(liczba);
        break;
    case 3:
        cout << "Podaj liczbe w systemie binarnym: ";
        cin >> liczba;
        cout << "Podana liczba w systemie dziesietnym: " << binarny_na_dziesietny(liczba);
        break;
    case 4:
        cout << "Podaj liczbe w systemie binarnym: ";
        cin >> liczba;
        cout << "Podana liczba w systemie szesnastkowym: " << binarny_na_szesnastkowy(liczba);
        break;
    case 5:
        cout << "Podaj liczbe w systemie osemkowym: ";
        cin >> string_liczba;
        cout << "Podana liczba w systemie binarnym: " << osemkowy_na_binarny(string_liczba);
        break;
    case 6:
        cout << "Podaj liczbe w systemie szesnastkowym: ";
        cin >> string_liczba;
        cout << "Podana liczba w systemie dziesietnym: " << szesnastkowy_na_dziesietny(string_liczba);
        break;
    case 7:
        cout << "Podaj liczbe w systemie osemkowym: ";
        cin >> string_liczba;
        cout << "Podana liczba w systemie szesnastkowym: " << octalny_na_szesnastkowy(string_liczba);
    default:
        return 0;
    }
}
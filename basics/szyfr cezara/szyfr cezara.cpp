#include <iostream>
#include <string>
#include <fstream>

using namespace std;

fstream plik;
int wybor;
string wyraz, klucz; //utworzenie zmiennych przechowujacych wyraz i klucz
string alfabet_duze = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //utworzenie zmiennych napisow przechowujacych alfabet z malymi i duzymi literami
string alfabet_male = "abcdefghijklmnopqrstuvwxyz";

int pozycjaAlfabet(char znak)//funkcja sprawdzajaca pozycje w alfabecie
{
    for (int i = 0; i < alfabet_duze.length(); i++)
    {
        if (alfabet_duze[i] == znak || alfabet_male[i] == znak)
        {
            return i;
        }
    }
}

void szyfrujVinegar(string wyrazF, string kluczF)
{
    string wynik;
    for (int i = 0; i < wyrazF.length(); i++)
    {
        int modul = i % kluczF.length();//modulo w przypadku wyrazu dluzszego niz klucz
        int przem_pion = pozycjaAlfabet(klucz[modul]); //ustalenie pozycji w pionie
        int przem_poziom = pozycjaAlfabet(wyrazF[i]); //ustalenie pozycji w poziomie
        wynik += alfabet_duze[(przem_poziom + przem_pion) % alfabet_duze.length()];//zapisanie wyrazu zaszyfrowanego do zmiennej
    }

    plik << wynik;//zapidanie do pliku

}


int main()
{

    cout << "Wybierz rodzaj szyfrowania / deszyfrowania: \n 1 - Szyfrowanie Cezara \n 2 - Deszyfrowanie Cezara \n 3 - Szyfrowanie Vigenere'a \n 4 - Deszyfrowanie Vigenere'a\n ";
    cin >> wybor;//wybor szyfrowania
    
    switch (wybor)
    {
    case 1:
        plik.open("plik.txt", ios::out);
        cout << "\tSzyfrowanie Cezara\n";
        cout << "Podaj wyraz do zaszyfrowania: ";
        cin >> wyraz;
        for (int i = 0; i < wyraz.length(); i++)
        {
            wyraz[i] += 3;//przesuniecie w ascii o 3 miejsca
            plik << wyraz[i];//zapisanie do pliku

        }
        plik.close();
        break;
    case 2:
        plik.open("plik.txt", ios::in);
        cout << "\tDeszyfrowanie szyfru Cezara\n";
        
        getline(plik, wyraz);//odczytanie z pliku
        cout << "Podany wyraz do odszyfrowania: " << wyraz<<endl;
        for (int i = 0; i < wyraz.length(); i++)
        {
            wyraz[i] -= 3;//przesuniecie w ascii o 3 miejsca
            cout << wyraz[i];
        }
        plik.close();
        break;
    case 3:
        plik.open("plik.txt", ios::out);
        cout << "\tSzyfrowanie Vigenere'a\n";
        cout << "Podaj wyraz do zaszyfrowania: ";
        cin >> wyraz;
        cout << "Podaj slowo klucz: ";
        cin >> klucz;
        szyfrujVinegar(wyraz, klucz);//wywolanie funkcji
        plik.close();
        break;
    case 4:
        plik.open("plik.txt", ios::in);
        getline(plik, wyraz);//pobranie z pliku
        cout << "\tDeszyfrowanie Vigenere'a\n";//deszyfrowanie za pomoca ascii
        cout << "Podany wyraz do odszyfrowania: " << wyraz << endl;
        cout << "Podaj slowo klucz: ";
        cin >> klucz;//podanie klucza
        for (int i = 0; i < wyraz.length(); i++)
        {
            if (wyraz[i] == 32)
            {
                wyraz[i] == ' ';//przypadek kiedy w ascii jest spacja
            }
            else
            {
                int liczba = 0;//iterator klucza
                if (liczba > klucz.length())
                {
                    liczba = 0;
                }
                wyraz[i] = wyraz[i] - klucz[liczba];//pomniejszenie o klucz
                liczba++;

                if (wyraz[i] <= 0)
                {
                    wyraz[i] = wyraz[i] + 64 + 26;//zapisanie przy pomocy ascii
                }
                else
                    wyraz[i] = wyraz[i] + 64;
            }
        }
        cout << wyraz;
        plik.close();
        break;
    default:
        cout << "Podano bledna wartosc." << endl;

    }
}
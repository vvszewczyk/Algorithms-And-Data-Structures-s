#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string haslo, hasloPodane;
    fstream plik("plik2.txt", ios::in);

    if (!plik) 
    {
        cout << "Nie mozna otworzyc pliku." << endl;
        return 1;
    }

    plik >> haslo;
    plik.close();

    do 
    {
        cout << "Podaj haslo: ";
        cin >> hasloPodane;

        if (haslo != hasloPodane)
        {
            cout << "Podano bledne haslo. Sprobuj ponownie..." << endl;
        }
        else
        {
            cout << "Podano prawidlowe haslo." << endl;
        }
    } while (haslo != hasloPodane);

    return 0;
}

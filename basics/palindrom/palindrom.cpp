#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int i = 0, j=0, k=0; 
    time_t start, stop;  // definiowanie zmiennych
    double czas;
    string slowo, palindrom; 

    cout << "Podaj wyraz: ";
    cin >> slowo;  //wczytanie slowa do sprawdzenia
    start = clock();//poczatek odmierzania czasu
    for (i = slowo.length()-1; i >=0; i--)//petla wykonujaca sie tyle razy ile znakow zawiera slowo
    {
        palindrom += slowo[i];//przypisanie odwroconego slowa do innego zmiennej
    }

    cout << endl;

        if (palindrom[k] != slowo[k])//sprawdzenie czy elementy w tablicy sa takie same, jezeli nie to slowo nie jest palindromem
        {
            cout << "Podany wyraz nie jest palindromem." << endl;
            stop = clock();//koniec odmierzania czasu
            czas = (double)(stop - start) / CLOCKS_PER_SEC;//zapisanie czasu do zmiennej
            cout << "czas wykonania programu: " << czas << " s." << endl;
            return 0;
        }

    cout << "Podany wyraz jest palindromem." << endl;
    stop = clock();//koniec odmierzania czasu
    czas = (double)(stop - start) / CLOCKS_PER_SEC;//zapisanie czasu do zmiennej
    cout << "czas wykonania programu: " << czas << " s." << endl;
    return 0;
}

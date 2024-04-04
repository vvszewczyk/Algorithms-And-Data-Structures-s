#include <iostream>

using namespace std;

int ruchy, x, y;

int moves(int xF, int yF)
{
    int pozycjax = 0;
    int pozycjay = 0;
    int kierunek = 0;

    int* tab = new int[ruchy];//tablica przechowujaca wartosci wspolrzednych podanych przez uzytkownika


    for (int i = 0; i < ruchy; i++)//petla wykonujaca sie 'ruchy' razy
    {
        switch (kierunek++)//switch  zmieniajacy kierunek za kazdym obrotem petli
        {
        case 0:
        {
            cout << "Ruch "<<i+1 << " - Podaj ilosc jednostek w gore: ";
            cin >> tab[i];
            pozycjay += tab[i];//wzrost wspolrzednej y - ruch w gore
            break;
        };
        case 1:
        {
            cout << "Ruch "<<i+1 << " - Podaj ilosc jednostek w prawo: ";
            cin >> tab[i];
            pozycjax += tab[i];//wzrost wspolrzednej x - ruch w prawo
            break;
        };
        case 2:
        {
            cout << "Ruch "<<i+1 << " - Podaj ilosc jednostek w dol: ";
            cin >> tab[i];
            pozycjay -= tab[i];//zmniejszenie wspolrzednej y - ruch w dol
            break;
        }
        case 3:
        {
            cout << "Ruch " <<i+1<< " - Podaj ilosc jednostek w lewo: ";
            cin >> tab[i];
            pozycjax -= tab[i];//zmniejszenie pozycji x - ruch w lewo
            kierunek = 0;//powrot do pierwszego case w przypadku wiekszej niz 4 ilosci ruchow
            break;
        }
        }
    }

    cout << "Pozycja robocika po: " << ruchy << " ruchach wynosi: (" << pozycjax << ", " << pozycjay << ")";

    return 0;
}

int main()
{
    cout << "Podaj liczbe ruchow: " << endl;
    cin >> ruchy;//wprowadzenie liczby ruchow
    x = 0;
    y = 0;
    moves(x, y);//wywolanie funkcji

}

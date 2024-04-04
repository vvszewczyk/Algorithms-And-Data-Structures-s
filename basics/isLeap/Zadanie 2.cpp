#include <iostream>

using namespace std;

int liczbaU, rok, liczba1, liczba2, suma=0, l1, l2, l3, l4, l5;
float ilosc_liczb, licznik = 0, srednia;

int case0(int rokF)
{
    if (rokF % 4 == 0 && (rokF % 100 != 0 || rokF % 400 == 0))//sprawdzanie warunkow roku przestepnego
        cout << "Podany rok jest przestepny." << endl;
    else
        cout << "Podany rok nie jest przestepny" << endl;

    return 0;
};

int case1(int liczba1F, int liczba2F)
{
    for (int i = liczba1F; i < liczba2F-1; i++)
    {
        cout << i+1 << " ";

        if (i % 2 == 0)//if sprawdzajacy parzystosc liczb - jezeli prawda to dodaje do sumy
        {
            suma += i;
        }
    }

    return 0;
};

int case2(int l1, int l2, int l3, int l4, int l5)
{
    int max, min;
    
    max = l1; //przypisanie do zmiennej max pierwszej liczby
    if (max < l2) //sprawdzenie czy druga liczba jest wieksza od zmiennej max, jeżeli prawda to przypisuje wartości max liczbe2
        max = l2;
    if (max < l3) //sprawdzenie czy trzecia liczba jest wieksza od zmiennej max, jeżeli prawda to przypisuje wartości max liczbe3
        max = l3;
    if (max < l4) //sprawdzenie czy czwarta liczba jest wieksza od zmiennej max, jeżeli prawda to przypisuje wartości max liczbe4
        max = l4;
    if (max < l5) //sprawdzenie czy piąta liczba jest wieksza od zmiennej max, jeżeli prawda to przypisuje wartości max liczbe5
        max = l5;

    min = l1; //przypisanie do zmiennej min pierwszej liczby
    if (min > l2) //sprawdzenie czy druga liczba jest mniejsza od zmiennej min, jeżeli prawda to przypisuje wartości min liczbe2
        min = l2;
    if (min > l3) //sprawdzenie czy trzecia liczba jest mniejsza od zmiennej min, jeżeli prawda to przypisuje wartości min liczbe3
        min = l3;
    if (min > l4) //sprawdzenie czy czwarta liczba jest mniejsza od zmiennej min, jeżeli prawda to przypisuje wartości min liczbe4
        min = l4;
    if (min > l5) //sprawdzenie czy piąta liczba jest mniejsza od zmiennej min, jeżeli prawda to przypisuje wartości min liczbe5
        min = l5;

    cout << "Min: " << min<<endl;
    cout << "Max: " << max<<endl;

    return 0;
};

int case3(int ilosc_liczbF)
{
    int* tab = new int[ilosc_liczbF];//tablica przechowujaca liczby

    for(int i=0; i<ilosc_liczbF; i++)//petla wykonujaca sie tyle razy ile poda uzytkownik
    {
        cout << "Podaj " << i + 1 << " liczbe: ";
        cin >> tab[i];
        licznik += tab[i];//zliczanie liczb
    }
    srednia = licznik / ilosc_liczbF;//srednia

    for (int i = 0; i < srednia; i++)
    {
        cout << 0;//wyswietlanie zer
    }

    cout << "Srednia: " << srednia<<endl;

    return 0;
};

int case4()
{
    system("pause"); //wyjscie z programu
    return 0;
};

int main()
{

    cout << "Podaj liczbe z przedzialu od 0 do 4: " << endl;
    cin >> liczbaU;

    switch (liczbaU)
    {
    case 0:
    {
        cout << "Podaj rok: " << endl;
        cin >> rok;
        case0(rok);//wywolanie funkcji
    }
    break;
    case 1:
    {
        cout << "Podaj pierwsza liczbe: " << endl;
        cin >> liczba1;
        cout << "Podaj druga liczbe: " << endl;
        cin >> liczba2;
        case1(liczba1, liczba2);//wywolanie funkcji
        cout << "Suma: "<<suma;

    }
    break;
    case 2:
    {
        cout << "Podaj 1 liczbe: " << endl;
        cin >> l1; //wczytanie liczby1
        cout << "Podaj 2 liczbe: " << endl;
        cin >> l2; //wczytanie liczby2
        cout << "Podaj 3 liczbe: " << endl;
        cin >> l3; //wczytanie liczby3
        cout << "Podaj 4 liczbe: " << endl;
        cin >> l4; //wczytanie liczby4
        cout << "Podaj 5 liczbe: " << endl;
        cin >> l5; //wczytanie liczby5
        case2(l1, l2, l3, l4, l5);//wywolanie funkcji
    }
        break;
    case 3:
    {
        cout << "Podaj ilosc liczb: ";
        cin >> ilosc_liczb;
        case3(ilosc_liczb);//wywolanie funkcji
    }
        break;
    case 4:
        cout << "Program zostal zakonczony." << endl;
        case4();//wywolanie funkcji
        break;
    }
}
#include <iostream>
#include <time.h>

using namespace std;

clock_t start, stop;//utworzenie zmiennych ktore beda odmierzac czas
double czas;


// dla 1k elementow niektore algorytmy sortujace byly zbyt szybkie i pokazywaly 0s wiec zamienilem na 5k elementow
int* tab5k1 = new int[5000];
int* tab5k2 = new int[5000];  //utworzenie tablic dla 5k elementow
int* tab5k3 = new int[5000];
int* tab5k4 = new int[5000];

int* tab10k1 = new int[10000];
int* tab10k2 = new int[10000]; //utworzenie tablic dla 10k elementow
int* tab10k3 = new int[10000];
int* tab10k4 = new int[10000];

int* tab30k1 = new int[30000];
int* tab30k2 = new int[30000];
int* tab30k3 = new int[30000]; //utworzenie tablic dla 30k elementow
int* tab30k4 = new int[30000];

int* tab60k1 = new int[60000];
int* tab60k2 = new int[60000]; //utworzenie tablic dla 60k elementow
int* tab60k3 = new int[60000];
int* tab60k4 = new int[60000];

int* tab100k1 = new int[100000];
int* tab100k2 = new int[100000]; //utworzenie tablic dla 100k elementow
int* tab100k3 = new int[100000];
int* tab100k4 = new int[100000];




void sortowanie_babelkowe(int* tab, int n)//funkcja sortowania babelkowego
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= 1; j--)
        {
            if (tab[j] < tab[j - 1])
            {
                int bufor;
                bufor = tab[j - 1];
                tab[j - 1] = tab[j];
                tab[j] = bufor;
            }
        }
    }
}

void quicksort(int* tab, int poczatek, int koniec)//funkcja sortowania quicksort
{
    int v = tab[(poczatek + koniec) / 2];
    int i, j, x;
    i = poczatek;
    j = koniec;
    do
    {
        while (tab[i] < v)
            i++;
        while (tab[j] > v)
            j--;
        if (i <= j)
        {
            x = tab[i];
            tab[i] = tab[j];
            tab[j] = x;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > poczatek)quicksort(tab, poczatek, j);
    if (j < koniec)quicksort(tab, i, koniec);
}

void heapify(int* tab, int rozmiar, int i)//funkcja potrzeba do sortowania heapsortem
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < rozmiar && tab[l] > tab[largest])
        largest = l;
    if (r < rozmiar && tab[r] > tab[largest])
        largest = r;
    if (largest != i) {
        swap(tab[i], tab[largest]);
        heapify(tab, rozmiar, largest);
    }
}
void heapSort(int arr[], int n) //funkcja sortowania heapsort
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void selectionSort(int arr[], int n) //funkcja sortowania selectionsort
{
    int i, j, min_in;
    for (i = 0; i < n; i++)
    {
        min_in = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_in])
                min_in = j;
        swap(arr[i], arr[min_in]);
    }
}

int main()
{
    srand(time(NULL));




    //===================5K ELEMENTOW========================

    for (int i = 0; i < 5000; i++)//petla przypisujaca ta sama losowa wartosc do kazdej z czterech 5000 elementowych tablic
    {
        tab5k1[i] = rand() % 1000 + 1;
        tab5k2[i] = tab5k1[i];
        tab5k3[i] = tab5k1[i];
        tab5k4[i] = tab5k1[i];
    }

    start = clock(); //poczatek odmierzania czasu
    sortowanie_babelkowe(tab5k1, 5000); 
    stop = clock(); //koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC; //przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << "\tDla 5k elementow\n";
    cout << endl << "czas wykonywania sortowania babelkowego: " << czas << " s" << endl; //wyswietlenie czasu


    start = clock();//poczatek odmierzania czasu
    quicksort(tab5k2, 0, 5000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania quicksorta: " << czas << " s" << endl;//wyswietlenie czasu


    start = clock();//poczatek odmierzania czasu
    heapSort(tab5k3, 5000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania heapsorta: " << czas << " s" << endl;//wyswietlenie czasu


    start = clock();//poczatek odmierzania czasu
    selectionSort(tab5k1, 5000);
    stop = clock();//koniec odmierzania czasu
    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania selectionsorta: " << czas << " s" << endl;//wyswietlenie czasu
    
    
    

    //===================10K ELEMENTOW========================




    for (int i = 0; i < 10000; i++)
    {
        tab10k1[i] = rand() % 1000 + 1;
        tab10k2[i] = tab10k1[i];
        tab10k3[i] = tab10k1[i];
        tab10k4[i] = tab10k1[i];

    }

    start = clock();//poczatek odmierzania czasu
    sortowanie_babelkowe(tab10k1, 10000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << "\n\tDla 10k elementow\n";
    cout << endl << "czas wykonywania sortowania babelkowego: " << czas << " s" << endl;//wyswietlenie czasu



    start = clock();//poczatek odmierzania czasu
    quicksort(tab10k2, 0, 10000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania quicksorta: " << czas << " s" << endl;//wyswietlenie czasu


    start = clock();//poczatek odmierzania czasu
    heapSort(tab10k3, 10000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania heapsorta: " << czas << " s" << endl;//wyswietlenie czasu

    start = clock();//poczatek odmierzania czasu
    selectionSort(tab10k4, 10000);
    stop = clock();//koniec odmierzania czasu
    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania selectionsorta: " << czas << " s" << endl;//wyswietlenie czasu




    //===================30K ELEMENTOW========================

    
    for (int i = 0; i < 30000; i++)
    {
        tab30k1[i] = rand() % 1000 + 1;
        tab30k2[i] = tab30k1[i];
        tab30k3[i] = tab30k1[i];
        tab30k4[i] = tab30k1[i];
    }

    start = clock();//poczatek odmierzania czasu
    sortowanie_babelkowe(tab30k1, 30000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << "\n\tDla 30k elementow\n";
    cout << endl << "czas wykonywania sortowania babelkowego: " << czas << " s" << endl;//wyswietlenie czasu



    start = clock();//poczatek odmierzania czasu
    quicksort(tab30k2, 0, 30000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania quicksorta: " << czas << " s" << endl;//wyswietlenie czasu



    start = clock();//poczatek odmierzania czasu
    heapSort(tab30k3, 30000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania heapsorta: " << czas << " s" << endl;//wyswietlenie czasu

    start = clock();//poczatek odmierzania czasu
    selectionSort(tab30k4, 30000);
    stop = clock();//koniec odmierzania czasu
    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania selectionsorta: " << czas << " s" << endl;//wyswietlenie czasu




    //===================60K ELEMENTOW========================

    
    for (int i = 0; i < 60000; i++)
    {
        tab60k1[i] = rand() % 1000 + 1;
        tab60k2[i] = tab60k1[i];
        tab60k3[i] = tab60k1[i];
        tab60k4[i] = tab60k1[i];
    }

    start = clock();//poczatek odmierzania czasu
    sortowanie_babelkowe(tab60k1, 60000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << "\n\tDla 60k elementow\n";
    cout << endl << "czas wykonywania sortowania babelkowego: " << czas << " s" << endl;//wyswietlenie czasu



    start = clock();//poczatek odmierzania czasu
    quicksort(tab60k2, 0, 60000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania quicksorta: " << czas << " s" << endl;//wyswietlenie czasu



    start = clock();//poczatek odmierzania czasu
    heapSort(tab60k3, 60000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania heapsorta: " << czas << " s" << endl;//wyswietlenie czasu

    start = clock();//poczatek odmierzania czasu
    selectionSort(tab60k4, 60000);
    stop = clock();//koniec odmierzania czasu
    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania selectionsorta: " << czas << " s" << endl;//wyswietlenie czasu
    




    //===================100K ELEMENTOW========================


    for (int i = 0; i < 100000; i++)
    {
        tab100k1[i] = rand() % 1000 + 1;
        tab100k2[i] = tab100k1[i];
        tab100k3[i] = tab100k1[i];
        tab100k4[i] = tab100k1[i];
    }

    start = clock();//poczatek odmierzania czasu
    sortowanie_babelkowe(tab100k1, 100000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << "\n\tDla 100k elementow\n";
    cout << endl << "czas wykonywania sortowania babelkowego: " << czas << " s" << endl;//wyswietlenie czasu



    start = clock();//poczatek odmierzania czasu
    quicksort(tab100k2, 0, 100000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania quicksorta: " << czas << " s" << endl;//wyswietlenie czasu



    start = clock();//poczatek odmierzania czasu
    heapSort(tab100k3, 100000);
    stop = clock();//koniec odmierzania czasu

    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania heapsorta: " << czas << " s" << endl;//wyswietlenie czasu

    start = clock();//poczatek odmierzania czasu
    selectionSort(tab100k4, 100000);
    stop = clock();//koniec odmierzania czasu
    czas = (double)(stop - start) / CLOCKS_PER_SEC;//przypisanie roznicy zmiennych czasow - na tej podstawie zostaje wyliczony czas trwania algorytmu
    cout << endl << "czas wykonywania selectionsorta: " << czas << " s" << endl;//wyswietlenie czasu

}
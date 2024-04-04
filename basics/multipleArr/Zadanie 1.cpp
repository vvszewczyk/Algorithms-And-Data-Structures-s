#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream plik("plik.txt", ios::out);

    plik << "X\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10" << endl; //wczytanie pierwszego wiersza

    for (int i = 0; i <= 10; i++)
    {
        plik << i<<"\t";
        for (int j = 0; j <= 10; j++)
        {
            plik << i * j<<"\t"; //wypisanie wyniku mnozenia ze znakiem tabulacji
        }
        plik<<endl;
        
    }
    plik.close();
}
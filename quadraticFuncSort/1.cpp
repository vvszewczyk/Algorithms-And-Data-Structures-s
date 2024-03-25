#include <iostream>
#include <vector>

using namespace std;

double wartoscFunkcji(double A, double B, double C, double x) 
{
    return A * x * x + B * x + C;
}

void recursiveInsertionSort(vector<double>& arr, int n)
{
    if (n <= 1) 
    {
        return;
    }
    recursiveInsertionSort(arr, n - 1);
    double last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

void printArray(vector<double>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    double A = -1.0, B=2.7, C=3.14;

    vector<double> x = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    vector<double> wyniki;

    for (int i = 0; i < x.size(); i++)
    {
        wyniki.push_back(wartoscFunkcji(A, B, C, x[i]));
    }

    recursiveInsertionSort(wyniki, wyniki.size());

    printArray(wyniki, wyniki.size());

    return 0;
}
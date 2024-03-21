#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> iloczynTrzech(vector<int>& liczby)
{
    vector<int> posortowane(liczby);
    sort(posortowane.begin(), posortowane.end());

    vector<int> min{ posortowane[0], posortowane[1], posortowane[liczby.size() - 1]};
    vector<int> max{ posortowane[liczby.size() - 1], posortowane[liczby.size() - 2], posortowane[liczby.size() - 3] };

    int minIloczyn = min[0] * min[1] * min[2];
    int maxIloczyn = max[0] * max[1] * max[2];

    if (maxIloczyn > minIloczyn)
        return max;
    else
        return min;
}

int main()
{
    vector<int> liczby = {-9, 2, 3, 1, 0, -2, 5, 4,-12, 6, -6, -30, 10, 11, 2, 4, -16, 20};
    vector<int> wynik = iloczynTrzech(liczby);

    cout << "Trojka liczb o maksymalnym iloczynie:\n";
    for (int i=0; i<wynik.size(); i++)
        cout << wynik[i] << "\n";

    cout << "Iloczyn: " << wynik[0] * wynik[1] * wynik[2];
    return 0;
}







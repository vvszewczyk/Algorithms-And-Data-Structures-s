#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Butelka 
{
    int id;
    string kolor;
    int iloscWody;
};

vector<pair<Butelka, Butelka>> paraButelek(vector<Butelka> ButelkiPara) 
{
    unordered_map<int, vector<Butelka>> mapaWody;
    vector<pair<Butelka, Butelka>> pary;

    for (int i = 0; i < ButelkiPara.size(); i++)
    {
        mapaWody[ButelkiPara[i].iloscWody].push_back(ButelkiPara[i]);
    }

    for (auto rekord : mapaWody) 
    {
        vector<Butelka> grupaButelki = rekord.second;
        int rozmiarGrupy = grupaButelki.size();

        for (int i = 0; i < rozmiarGrupy; i += 2) 
        {
            pary.push_back(make_pair(grupaButelki[i], grupaButelki[i + 1]));
        }
    }
    return pary;
}

int main() 
{
    vector<Butelka> Butelki = 
    {
        {1, "niebieska", 777},
        {7, "czerwona", 222},
        {2, "czerwona", 666},
        {3, "niebieska", 666},
        {5, "niebieska", 999},
        {6, "czerwona", 777},
        {4, "czerwona", 999},
        {8, "niebieska", 222},
    };

    vector<pair<Butelka, Butelka>> sparowaneButelki = paraButelek(Butelki);

    cout << "Pary sparowanych butelek:\n";
    for (auto pair : sparowaneButelki) 
    {
        cout << "Niebieska: id=" << pair.first.id << ", ilosc wody=" << pair.first.iloscWody << "\n";
        cout << "Czerwona: id=" << pair.second.id << ", ilosc wody=" << pair.second.iloscWody << "\n\n";
    }

    return 0;
}
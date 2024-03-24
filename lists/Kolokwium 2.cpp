#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node
{
    string name;
    int year;
    string country;
    Node* next;

    Node(string name, int year, string country, Node* next = nullptr)
    {
        this->name = name;
        this->year = year;
        this->country = country;
        this->next = next;
    }
};

void push_front(Node*& head, Node*& data)
{
    Node* pomocniczy = head;
    head = data;
    data->next = pomocniczy;
}

void printAll(Node* head)
{
    Node* pomocnicza = head;
    while (pomocnicza)
    {
        cout << pomocnicza->name << " " << pomocnicza->year << " " << pomocnicza->country << "\n";
        pomocnicza = pomocnicza->next;
    }
}

Node* countryWinner(Node* head, string country)
{
    Node* pomocnicza = head;
    Node* nowaLista = nullptr;
    if (head)
    {
        while (pomocnicza)
        {
            if (pomocnicza->country == country)
            {
                Node* findWinner = new Node(pomocnicza->name, pomocnicza->year, pomocnicza->country);
                push_front(nowaLista, findWinner);
            }
            pomocnicza = pomocnicza->next;
        }
        return nowaLista;

    }
    else return nullptr;

}

string yearWinner(Node* head, int year)
{
    Node* pomocnicza = head;
    while (pomocnicza)
    {
        if (year == pomocnicza->year)
            return pomocnicza->name;
        pomocnicza = pomocnicza->next;
    }
    return "nie ma";
}

Node* yearWinners(Node* head, int year)
{
    Node* pomocnicza = head;
    Node* nowaLista = nullptr;
    while (pomocnicza)
    {
        if (year == pomocnicza->year)
        {
            Node* laureaci = new Node(pomocnicza->name, pomocnicza->year, pomocnicza->country);
            push_front(nowaLista, laureaci);


        }
        pomocnicza = pomocnicza->next;
    }
    return nowaLista;
}


int main()
{
    Node* head = nullptr;
    fstream plik("nobel.txt", ios::in);
    string line;
    while (getline(plik, line))
    {
        stringstream ss(line);
        string name;
        int year;
        string bufor;
        string country;

        getline(ss, name, ',');
        getline(ss, bufor, ' ');
        year = stoi(bufor);
        getline(ss, country);
        Node* noblista = new Node(name, year, country);

        push_front(head, noblista);
        //cout << name << " " << year << " " << country << "\n";
    }
    plik.close();

   //printAll(head);

   Node* nowaLista = countryWinner(head, "Polska");
   //printAll(nowaLista);

  // cout << yearWinner(head, 1910);
   Node* nowaLista2 = yearWinners(head, 1917);
   printAll(nowaLista2);

    return 0;
}

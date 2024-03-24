#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int id;
    string wykonawca;
    string nazwa;
    int rok;
    string autorzy;
    Node* next;

    Node(int id, string wykonawca, string nazwa, int rok, string autorzy, Node* next = nullptr)
    {
        this->id = id;
        this->wykonawca = wykonawca;
        this->nazwa = nazwa;
        this->rok = rok;
        this->autorzy = autorzy;
        this->next = next;
    }
};

struct NodeKopia
{
    string wykonawcaKopia;
    int iloscWystapien;
    NodeKopia* nextKopia;

    NodeKopia(string wykonawcaKopia, int iloscWystapien, NodeKopia* nextKopia = nullptr)
    {
        this->wykonawcaKopia = wykonawcaKopia;
        this->iloscWystapien = iloscWystapien;
        this->nextKopia = nextKopia;
    }
};


void push_front(Node*& head, Node*& data)
{
    Node* pomocniczy;
    pomocniczy = head;
    head = data;
    data->next = pomocniczy;
}




void push_frontKopia(NodeKopia *&head, NodeKopia *& data)
{
    NodeKopia* pomocniczy;
    pomocniczy = head;
    head = data;
    data->nextKopia = pomocniczy;
}

void printAll(Node* head)
{
    Node* pomocnicza = head;
    while (pomocnicza)
    {
        cout << pomocnicza->id << " " << pomocnicza->wykonawca << " " << pomocnicza->nazwa << " " << pomocnicza->rok << " " << pomocnicza->autorzy << endl;
        pomocnicza = pomocnicza->next;
    }
}

void printAllKopia(NodeKopia* head)
{
    NodeKopia* pomocnicza = head;
    while (pomocnicza)
    {
        cout << pomocnicza->wykonawcaKopia << " " << pomocnicza->iloscWystapien<<endl;
        pomocnicza = pomocnicza->nextKopia;
    }
}


NodeKopia* licznikWykonawcow(Node*& head)
{
    Node* pomocnicza= head;

    NodeKopia* nowaLista = nullptr;
    while (pomocnicza)
    {       

        NodeKopia* pomocnicza2= nowaLista; //pomocnicza2 przechowuje glowe dla nowej listy
        bool unikalny = true;
        while (pomocnicza2)
        {
            if (pomocnicza->wykonawca == pomocnicza2->wykonawcaKopia)
            {
                pomocnicza2->iloscWystapien++;
                unikalny = false;
                break;
            }
                pomocnicza2 = pomocnicza2->nextKopia;
        }
        if (unikalny)
        {
            NodeKopia* dodawanie = new NodeKopia(pomocnicza->wykonawca, 1);
            push_frontKopia(nowaLista, dodawanie);
        }
        pomocnicza = pomocnicza->next;


    }
    return nowaLista;
}



NodeKopia* multiObecnosc(NodeKopia*& head)
{
    NodeKopia* pomocnicza = head;
    NodeKopia* WYNIK = nullptr;
    while (pomocnicza)
    {
        if (pomocnicza->iloscWystapien > 1)
        {
            NodeKopia* dodawnik = new NodeKopia(pomocnicza->wykonawcaKopia, pomocnicza->iloscWystapien);
            push_frontKopia(WYNIK, dodawnik);
        }
        pomocnicza = pomocnicza->nextKopia;
    }
    return WYNIK;
}



bool autorWielokrotny(Node* head, int id)
{
    Node* pomocnicza = head;
    Node* pomocnicza2= nullptr;
    string autorPowtarzany;
    while (pomocnicza)
    {
        if (pomocnicza->id == id)
        {
            pomocnicza2 = pomocnicza;
        }
        pomocnicza = pomocnicza->next;
    }

    if (pomocnicza2)
    {
        stringstream autorzy2(pomocnicza2->autorzy);

        while (getline(autorzy2, autorPowtarzany, ','))
        {
            autorzy2.ignore();
            if (autorPowtarzany == pomocnicza2->wykonawca)
                return 1;
            else
                return 0;
        }
    }
    else return 0;


}

Node* yearSong(Node* head, int year)
{
    Node* pomocnicza = head;
    Node* nowaLista = nullptr;
    while (pomocnicza)
    {
        if (year == pomocnicza->rok)
        {
            Node* laureaci = new Node(pomocnicza->id, pomocnicza->wykonawca, pomocnicza->nazwa, pomocnicza->rok, pomocnicza->autorzy);
            push_front(nowaLista, laureaci);


        }
        pomocnicza = pomocnicza->next;
    }
    return nowaLista;
}


int main()
{
    Node* head = nullptr;
    fstream plik("utwory.txt", ios::in);
    string line;
    while (getline(plik, line))
    {
        stringstream ss(line);
        int id;
        string wykonawca;
        string nazwa;
        int rok;
        string autorzy;
        string bufor;
        getline(ss, bufor, ',');
        id = stoi(bufor);
        ss.ignore();
        getline(ss, wykonawca, ',');
        ss.ignore();
        getline(ss, nazwa, ',');
        ss.ignore();
        getline(ss, bufor, ',');
        rok = stoi(bufor);
        ss.ignore();
        getline(ss, autorzy);

        Node* piosenka = new Node(id, wykonawca, nazwa, rok, autorzy);
        push_front(head, piosenka);



        //cout << id << " " << wykonawca << " " << nazwa << " " << rok << " " << autorzy << endl;
    }
        //Node* nowaLista = yearSong(head, 1970);
        //printAll(nowaLista);
    //cout<<autorWielokrotny(head, 14);


    NodeKopia* nowaLista = licznikWykonawcow(head);
  
    nowaLista=multiObecnosc(nowaLista);
  printAllKopia(nowaLista);

    plik.close();
    return 0;
}

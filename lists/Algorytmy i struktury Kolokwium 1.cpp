#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Node
{
    string name;
    int start;
    int end;
    string partia;
    Node* next;

    Node(string name, string partia, int start, int end, Node* next = nullptr)
    {
        this->name = name;
        this->partia = partia;
        this->start = start;
        this->end = end;
        this->next = next;
    }
};

void push_front(Node*& head, Node *&data)
{
    Node* pomocniczy;
    pomocniczy = head;
    head = data;
    data->next = pomocniczy;
}

void push_back(Node *&head, Node *&data)
{
    //Node* newNode=nullptr;

    if (head)//jezeli glowa istnieje to to sie wykona
    {
        Node* tgt = head;//obiekt pomocniczny wskazujacy na glowe
        while (tgt->next)//przelatujemy przez cala liste i sprawdzamy czy next jest nullem
        {
            tgt = tgt->next;
        }
        tgt->next = data;//przypisanie do target next obiektu ktory chcemy umiescic
    }
    else
        head = data;//jezeli nie ma glowy to znaczy ze lista jest pusta i jest to zarowno 1 i ostatni element

}

Node* youngKing(Node*& head)//funkcja zwraca liste
{

  if (head)
    {

        int najmniejsza = head->end - head->start;

        Node* pomocnicza = head;
        Node* nowaLista = nullptr;

        while (pomocnicza)
        {
            int potencjalna = pomocnicza->end - pomocnicza->start;
            pomocnicza = pomocnicza->next;
            if (potencjalna < najmniejsza)
            {
                najmniejsza = potencjalna;

            }
        }
        pomocnicza = head;
        while (pomocnicza)
        {
            int rzad= pomocnicza->start - pomocnicza->end;
            if (rzad == najmniejsza)
            {
                Node* nowyPrezydent = new Node(pomocnicza->name, pomocnicza->partia, pomocnicza->start, pomocnicza->end);
                push_front(nowaLista, nowyPrezydent);
            }
            pomocnicza = pomocnicza->next;
        }
        return nowaLista;

    }
    else
        return nullptr;


}

void printAll(Node* head)
{
    Node* pomocnicza = head;
    while (pomocnicza)
    {
        cout << pomocnicza->name << " " << pomocnicza->partia << " " << pomocnicza->start << " " << pomocnicza->end<<endl;
        pomocnicza = pomocnicza->next;
    }
}

string choiceYourKing(Node* head, int year)
{
    Node* pomocnicza = head;
    while (pomocnicza)
    {
        if (year >= pomocnicza->start && year <= pomocnicza->start)
            return pomocnicza->name;
        pomocnicza = pomocnicza->next;
    }
    return "nie ma";
}

Node* partyChoice(Node*& head, string partia)
{
    if (head)
    {
        Node* pomocnicza = head;
        Node* nowaLista=nullptr;
        while (pomocnicza)
        {

            if (pomocnicza->partia == partia)
            {
                Node* szukanyPrezydent = new Node(pomocnicza->name, pomocnicza->partia, pomocnicza->start, pomocnicza->end);
                push_front(nowaLista, szukanyPrezydent);

            }
            pomocnicza = pomocnicza->next;
        }
        return nowaLista;
    }
    else return nullptr;

}


int main()
{
    Node* head = nullptr;
    fstream file("presidents.txt", ios::in);//otwarcie pliku
    string line; //do tej zmiennej zapisujemy strumien
    while (getline(file, line)) //zapisywanie do zmiennej line
    {
        stringstream ss(line); //zapisujemy line do strumienia ss
        string name; //name itp to zmienne do przechowywania danych
        string partia;
        string bufor;//bufor przechowuje rok po to zeby go potem zamienic na inta bo getline chce stringa
        int year1;
        int year2;

        getline(ss, name, ',');//pobranie wszystkiego do momentu napotkania ,
        getline(ss, bufor, '-');//pobranie wszystkiego do momentu napotkania -
        year1 = stoi(bufor);//zapisanie mniejszego roku do inta do zmiennej pomocniczej
        getline(ss, bufor, ' ');
        year2 = stoi(bufor);//zapisanie wiekszego roku do inta do zmiennej pomocniczej
        getline(ss, partia);

            //ss.ignore() sluzy do pominiecia znaku
        if (year1 < 1901)
        {
            Node* Prezydent = new Node(name, partia, year1, year2);//stworzenie projektu listy ktory bedzie wczytywal za pomoca konstruktora dane z pod tych zmiennych
            //push_front(head, Prezydent);
            //cout << name << " " << partia << " " << year1 << " " << year2<<"\n";//sprawdzenie czy dziala cout   
 
        }

    Node* nowaLista = new Node(name, partia, year1, year2);
    push_back(head, nowaLista);
           printAll(nowaLista);
    }

    //PO WCZYTANIU
 
  //  Node* nowaLista = youngKing(head);
   // Node* nowaLista2 = partyChoice(head, "Democratic");




 
   //cout<<choiceYourKing(head, 1869);
    file.close();
}
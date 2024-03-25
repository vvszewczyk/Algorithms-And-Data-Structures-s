#include <iostream>
#include <string>

using namespace std;



struct Node 
{
    string zawartosc;
    Node* rodzic;
    Node* lewySyn;
    Node* prawySyn;
};




Node* nowyNode(string zawartosc) 
{
    Node* newNode = new Node;
    newNode->zawartosc = zawartosc;
    newNode->lewySyn = NULL;
    newNode->prawySyn = NULL;
    newNode->rodzic = NULL;
    return newNode;
}




Node* dodajSlowo(Node* root, string zawartosc) 
{
    if (root == NULL)
        return nowyNode(zawartosc);
    if (zawartosc < root->zawartosc)
        root->lewySyn = dodajSlowo(root->lewySyn, zawartosc);
    else if (zawartosc > root->zawartosc)
        root->prawySyn = dodajSlowo(root->prawySyn, zawartosc);
    return root;
}




Node* wyszukiwanie(Node* root, string zawartosc) 
{
    if (root == NULL || root->zawartosc == zawartosc)
        return root;
    if (zawartosc < root->zawartosc)
        return wyszukiwanie(root->lewySyn, zawartosc);
    return wyszukiwanie(root->prawySyn, zawartosc);
}




//uzywana w usuwaniu
Node* minF(Node* root) 
{
    while (root->lewySyn)
        root = root->lewySyn;
    return root;
}




//uzywany przy edytowaniu
Node* usuwanie(Node* root, string zawartosc) 
{
    if (root == NULL)
        return root;
    if (zawartosc < root->zawartosc)
        root->lewySyn = usuwanie(root->lewySyn, zawartosc);
    else if (zawartosc > root->zawartosc)
        root->prawySyn = usuwanie(root->prawySyn, zawartosc);
    else 
    {
        if (root->lewySyn == NULL) 
        {
            Node* temp = root->prawySyn;
            delete root;
            return temp;
        }
        else if (root->prawySyn == NULL) 
        {
            Node* temp = root->lewySyn;
            delete root;
            return temp;
        }
        Node* temp = minF(root->prawySyn);
        root->zawartosc = temp->zawartosc;
        root->prawySyn = usuwanie(root->prawySyn, temp->zawartosc);
    }
    return root;
}



//wyswietlanie
void print(Node*& root) 
{
    if (root) 
    {
        print(root->lewySyn);
        cout << root->zawartosc << " ";
        print(root->prawySyn);
    }
}





void edytowanie(Node* root, string staraZawartosc, string nowaZawartosc) 
{
    usuwanie(root, staraZawartosc);
    dodajSlowo(root, nowaZawartosc);
}



Node* wyszukiwanieZaawansowane(Node* root, string zawartosc) 
{
    if (root == NULL)
        return NULL;
    if (zawartosc <= root->zawartosc && root->zawartosc.substr(0, zawartosc.length()) == zawartosc)
        return root;
    if (zawartosc > root->zawartosc)
        return wyszukiwanieZaawansowane(root->prawySyn, zawartosc);
    else {
        Node* result = wyszukiwanieZaawansowane(root->lewySyn, zawartosc);
        if (result == nullptr) {
            return wyszukiwanieZaawansowane(root->prawySyn, zawartosc);
        }
        else {
            return result;
        }
    }
}



void printZaawansowany(Node* node, string zawartosc) 
{
    Node* wynik = wyszukiwanieZaawansowane(node, zawartosc);

    if (wynik)
        cout <<wynik->zawartosc << endl;
    else
        cout << "Brak wyszukiwanych slow" << endl;
}



void usunDrzewo(Node* root)
{
    if (root == NULL) {
        return;
    }
    usunDrzewo(root->lewySyn);
    usunDrzewo(root->prawySyn);
    delete root;
}



int main()
{
    Node* root = NULL;



    // dodawanie elementów - ZADANIE 3
    root = dodajSlowo(root, "elf");
    root = dodajSlowo(root, "goblin");
    root = dodajSlowo(root, "ork");



    // wypisanie zawartości drzewa
    cout << "Zawartosc drzewa: ";
    print(root);
    cout << endl;
    cout << endl;



    // wyszukiwanie elementów w drzewie - ZADANIE 1
    cout << "Wyszukiwanie elementu w drzewie: ";
    if (wyszukiwanie(root, "ork"))
        cout << "znaleziono";
    else
        cout << "nie znaleziono" << endl;
    cout << endl;
    cout << endl;



    // wyszukiwanie zaawansowane - ZADANIE 2
    cout << "Wyszukiwanie zaawansowane: ";
    printZaawansowany(root, "gob");
    cout << endl;



    // edycja elementu w drzewie - ZADANIE 4
    edytowanie(root, "ork", "orczyca");
    cout << "Zawartosc drzewa po edycji: ";
    print(root);
    cout << endl;
    cout << endl;


    // usuwanie drzewa
    usunDrzewo(root);
};
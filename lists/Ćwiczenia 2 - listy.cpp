#include <iostream>

using namespace std;

class node 
{
public:
    int data;
    node* next = nullptr;
};


void push_front(node*& head, int new_data) 
{
    node* newNode = new node{};
    newNode->data = new_data;
    newNode->next = head;
    head = newNode;
}


void push_back(node*& head, int new_data) 
{
    node* newNode = new node{};
    newNode->data = new_data;
    newNode->next = nullptr;

    if (head == nullptr) 
    { 
        head = newNode;
    }
    else 
    {
        node* pom = head;
        while (pom->next) 
        {
            pom = pom->next;
        }
        pom->next = newNode;
    }
}


void show_Elements(node*& head) 
{
    node* pom = head;
    while (pom) 
    {
        cout << pom->data << " ";
        pom = pom->next;
    }
    cout << endl;
}


void push_by_id(node*& head, int new_data, int id) 
{
    node* newNode = new node{};
    newNode->data = new_data;

    if (id == 0 || head == nullptr) 
    {
        newNode->next = head;
        head = newNode;
    }
    else 
    {
        node* pom = head;
        int licznik = 0;
        while (licznik < id - 1 && pom->next) 
        {
            pom = pom->next;
            licznik++;
        }
        newNode->next = pom->next;
        pom->next = newNode;
    }
}


void drop_front(node*& head) 
{
    if (head != nullptr) 
    {
        node* pom = head;
        head = head->next;
        delete pom;
    }
}


void drop_back(node*& head) 
{
    if (head == nullptr) 
    {
        return;
    }

    if (head->next == nullptr) 
    { 
        delete head;
        head = nullptr;
    }
    else 
    {
        node* pom = head;
        while (pom->next->next) 
        {
            pom = pom->next;
        }
        delete pom->next;
        pom->next = nullptr;
    }
}


void drop_selected(node*& head, int target_data) 
{
    if (head == nullptr)
    {
        return;
    }

    if (head->data == target_data) 
    {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* prev = head;
    node* current = head->next;

    while (current && current->data != target_data) 
    {
        prev = current;
        current = current->next;
    }

    if (current) 
    {
        prev->next = current->next;
        delete current;
    }
}


int main() 
{
    node* head = nullptr;
    push_front(head, 5);
    push_back(head, 10);
    push_back(head, 102);
    push_back(head, 130);
    push_back(head, 1310);
    push_back(head, 101);
    push_by_id(head, 7, 1);
    show_Elements(head);

    drop_front(head);
    show_Elements(head);
    drop_back(head);
    show_Elements(head);
    drop_selected(head, 7);
    show_Elements(head);

    return 0;
}

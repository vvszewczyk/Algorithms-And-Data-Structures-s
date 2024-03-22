#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) 
    {
        this->data = data;
        this->next = next;
    }
};


void push(Node*& top, int data) 
{
    Node* newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}


void pop(Node*& top) 
{
    if (top == nullptr) 
    {
        cout << "Stos jest pusty." << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}


void printStack(Node* top) 
{
    while (top) 
    {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() 
{
    Node* top = nullptr;

    push(top, 1);
    push(top, 2);
    push(top, 3);
    push(top, 4);

    cout << "Stos po dodaniu elementów: ";
    printStack(top);

    pop(top);
    cout << "Stos po usunięciu elementu: ";
    printStack(top);

    return 0;
}

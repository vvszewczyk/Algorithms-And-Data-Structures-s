#include <iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node* next;

    Node(int data, int priority, Node* next = nullptr)
    {
        this->data = data;
        this->priority = priority;
        this->next = next;
    }
};

//do dodawania elementu do kolejki
void enqueue(Node*& head, int data, int priority)
{
    Node* newNode = new Node(data, priority);
    if (head == nullptr || head->priority > priority)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//do usuwania elementu z początku kolejki
void dequeue(Node*& head)
{
    if (head == nullptr)
    {
        cout << "Kolejka jest pusta." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void printQueue(Node* head)
{
    while (head)
    {
        cout << head->data << "(" << head->priority << ") ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    enqueue(head, 4, 1);
    enqueue(head, 5, 2);
    enqueue(head, 6, 0);
    enqueue(head, 7, 3);

    cout << "Kolejka po dodaniu elementów: ";
    printQueue(head);

    dequeue(head);
    cout << "Kolejka po usunięciu elementu: ";
    printQueue(head);

    return 0;
}

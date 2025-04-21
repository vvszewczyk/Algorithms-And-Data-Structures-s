#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::Node::Node(int val) : value(val), next(nullptr), prev(nullptr) {};

DoublyLinkedList::DoublyLinkedList() : head(nullptr) {};

DoublyLinkedList::~DoublyLinkedList()
{
    Node *curr = head;
    while (curr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
}

DoublyLinkedList::Node *DoublyLinkedList::getHead() const
{
    return this->head;
}

void DoublyLinkedList::pushFront(int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    else
    {
        Node *pom = head;
        newNode->next = pom;
        pom->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::pushBack(int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *curr = head;

    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;
}

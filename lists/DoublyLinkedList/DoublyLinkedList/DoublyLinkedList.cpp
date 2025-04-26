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

void DoublyLinkedList::print() const
{
    Node *curr = head;
    std::size_t index = 0;

    while (curr)
    {
        std::cout << "i: " << index++ << " value: " << curr->value << "\n";
    }
    std::cout << "\n";
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

void DoublyLinkedList::popFront()
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        Node *toDelete = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        delete toDelete;
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

void DoublyLinkedList::pushAtPosition(int val, std::size_t position)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    else
    {
        Node *curr = head;

        if (position == 0)
        {
            head = newNode;
            newNode->next = curr;
            curr->prev = newNode;
            return;
        }

        std::size_t index = 0;
        while (curr->next)
        {
            if (index == position - 1)
            {
                Node *pom = curr->next;
                curr->next = newNode;
                newNode->prev = curr;
                newNode->next = pom;
                pom->prev = newNode;
                return;
            }
            curr = curr->next;
            index++;
        }

        curr->next = newNode;
        newNode->prev = curr;
    }
}

void DoublyLinkedList::reverse()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    else
    {
        Node *curr = head;
        Node *prev = nullptr;

        while (curr)
        {
            Node *pom = curr->next;
            curr->next = prev;
            curr->prev = pom;
            prev = curr;
            curr = pom;
        }

        head = prev;
    }
}

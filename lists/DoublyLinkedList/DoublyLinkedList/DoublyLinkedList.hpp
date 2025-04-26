#pragma once
#include <cstddef>

class DoublyLinkedList
{
  public: // Node is public to allow access for testing
    class Node
    {
      public:
        int value;
        Node *next;
        Node *prev;

        Node(int val);
    };

  private:
    Node *head = nullptr;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    Node *getHead() const;
    void print() const;
    void pushFront(int val);
    void popFront();
    void pushBack(int val);
    void popBack();
    void pushAtPosition(int val, std::size_t position);
    void reverse();
};

#pragma once

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
    void pushFront(int val);
};

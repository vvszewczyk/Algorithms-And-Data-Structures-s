#include <iostream>

class Stack
{
  public: // Node is public to allow access for testing
    class Node
    {
      public:
        int value;
        Node *next;

        Node(int val);
    };

  private:
    Node *top = nullptr;

  public: // Methods
    Node *getTop();
    Stack();
    ~Stack();
    void push(int val);
    void pop();
    bool isEmpty() const;
    int peek() const;
    std::size_t size() const;
    void reverse();
    void sort();
};

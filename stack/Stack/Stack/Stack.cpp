#include "Stack.hpp"

Stack::Node::Node(int val) : value(val), next(nullptr) {};

Stack::Stack() : top(nullptr) {};

Stack::~Stack()
{
}

Stack::Node *Stack::getTop()
{
    return this->top;
}

void Stack::push(int val)
{
    Node *newNode = new Node(val);

    if (top == nullptr)
    {
        top = newNode;
        return;
    }

    newNode->next = top;
    top = newNode;
}

void Stack::pop()
{
    if (top == nullptr)
    {
        return;
    }

    Node *toPop = top;
    top = top->next;
    delete toPop;
}

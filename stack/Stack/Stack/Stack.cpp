#include "Stack.hpp"

Stack::Node::Node(int val) : value(val), next(nullptr) {};

Stack::Stack() : top(nullptr) {};

Stack::~Stack()
{
    while (top != nullptr)
    {
        Node *toDelete = top;
        top = top->next;
        delete toDelete;
    }
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
        throw std::logic_error("Cannot pop empty stack");
    }

    Node *toPop = top;
    top = top->next;
    delete toPop;
}

bool Stack::isEmpty() const
{
    return top == nullptr;
}

int Stack::peek() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }

    return this->top->value;
}

std::size_t Stack::size() const
{
    std::size_t counter = 0;
    Node *curr = top;
    while (curr)
    {
        ++counter;
        curr = curr->next;
    }

    return counter;
}

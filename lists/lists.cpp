#include <iostream>

class Node
{
  public:
    int value;
    Node *next;

    Node(int val) : value(val), next(nullptr) {};
};

void pushFront(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        return;
    }
}

void pushBack(Node *&head, int val)
{
    Node *curr = head;

    if (head == nullptr)
    {
        Node *newOne = new Node(val);
        head = newOne;
    }
    else
    {
        while (curr)
        {
            if (curr->next == nullptr)
            {
                Node *newOne = new Node(val);
                curr->next = newOne;
                break;
            }

            curr = curr->next;
        }
    }
}

void pushAtIndex(Node *&head, int data, std::size_t position)
{
    Node *curr = head;
    Node *newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    else
    {
        if (position == 0)
        {
            newNode->next = curr;
            head = newNode;
            return;
        }

        std::size_t i = 0;
        while (curr->next)
        {
            if (i == position - 1)
            {
                Node *bufor = curr->next;
                curr->next = newNode;
                newNode->next = bufor;
                return;
            }
            i++;
            curr = curr->next;
        }
        // Walked through all list -> position is bigger than list size -> add on the end
        curr->next = newNode;
    }
}

void dropFront(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
}

void dropBack(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    else
    {
        Node *curr = head;

        while (curr)
        {
            if (curr->next->next == nullptr)
            {
                Node *toDelete = curr->next;
                curr->next = nullptr;
                delete toDelete;
                return;
            }

            curr = curr->next;
        }
    }
}

void dropAtIndex(Node *&head, std::size_t position)
{
    // TODO
}

void printList(Node *&head)
{
    Node *curr = head;
    std::size_t index = 0;
    while (curr)
    {
        std::cout << "i: " << index++ << " value: " << curr->value << "\n";
        curr = curr->next;
    }

    std::cout << "\n";
}

int main()
{
    Node *head = nullptr;

    pushBack(head, 2);
    pushBack(head, 3);
    pushBack(head, 5);

    pushAtIndex(head, 10, 3);
    pushAtIndex(head, 11, 0);
    pushAtIndex(head, 1000, 32131);

    pushFront(head, 66);
    pushFront(head, 21);
    pushFront(head, 33);

    dropFront(head);
    dropBack(head);
    dropBack(head);

    printList(head);
}

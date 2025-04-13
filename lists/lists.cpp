#include <iostream>

class LinkedList
{
    class Node
    {
      public:
        int value;
        Node *next;

        Node(int val) : value(val), next(nullptr) {};
    };

    Node *head;

  public:
    LinkedList() : head(nullptr) {};

    ~LinkedList()
    {
        Node *curr = head;
        while (curr)
        {
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
    };

    void pushFront(int val)
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

    void pushBack(int val)
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

    void pushAtIndex(int data, std::size_t position)
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

    void dropFront()
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

    void dropBack()
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

    void dropAtIndex(std::size_t position)
    {
        if (head == nullptr)
        {
            return;
        }
        else if (position == 0)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
        }
        else
        {
            Node *curr = head;
            std::size_t i = 0;
            while (curr->next)
            {
                if (i == position - 1)
                {
                    Node *toDelete = curr->next;
                    if (curr->next->next)
                    {
                        curr->next = curr->next->next;
                    }
                    else
                    {
                        curr->next = nullptr;
                    }

                    delete toDelete;
                    return;
                }

                i++;
                curr = curr->next;
            }
            return;
        }
    }

    void reverse()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void printList() const
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
};

int main()
{
    LinkedList list;

    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(5);

    list.pushAtIndex(10, 3);
    list.pushAtIndex(11, 0);
    list.pushAtIndex(1000, 32131);

    list.pushFront(66);
    list.pushFront(21);
    list.pushFront(33);

    list.dropFront();
    list.dropBack();
    list.dropBack();

    list.dropAtIndex(2);

    list.printList();

    list.reverse();
    list.printList();
}

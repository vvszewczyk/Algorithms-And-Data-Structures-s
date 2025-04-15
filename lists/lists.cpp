#include <iostream>
#include <vector>

class LinkedList
{
  public:
    class Node
    {
      public:
        int value;
        Node *next;

        Node(int val) : value(val), next(nullptr) {};

        friend std::ostream &operator<<(std::ostream &os, const Node &data)
        {
            if (!&data)
            {
                os << "Unkown node.\n";
                return os;
            }

            os << "value: " << data.value;
            if (data.next)
            {
                os << " next: " << data.next->value << "\n";
            }
            else
            {
                os << " next: nullptr\n";
            }
            return os;
        }
    };

  private:
    Node *head;

  public:
    LinkedList() : head(nullptr) {};

    LinkedList(const LinkedList &) = delete;

    LinkedList &operator=(const LinkedList &) = delete;

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

    Node *getHead()
    {
        return this->head;
    }

    void setHead(Node *n)
    {
        this->head = n;
    }

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

    void pushSorted(int value)
    {
        Node *newNode = new Node(value);
        Node *curr = head;

        // Push front
        if (head == nullptr || head->value > value)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Push between elements
        while (curr->next)
        {
            if ((curr->value < value) && (curr->next->value > value))
            {
                Node *pom = curr->next;
                curr->next = newNode;
                newNode->next = pom;
                return;
            }
            else if ((curr->value == value) || (curr->next->value == value))
            {
                Node *pom = curr->next;
                curr->next = newNode;
                newNode->next = pom;
                return;
            }
            curr = curr->next;
        }

        // Push back if we went through the entire list without success
        curr->next = newNode;
        newNode->next = nullptr;
        return;
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

    void dropEveryOther()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            std::size_t counter = 0;
            Node *curr = head;

            while (curr && curr->next)
            {
                Node *toDelete = curr->next;
                curr->next = curr->next->next;
                delete toDelete;

                curr = curr->next;
            }
        }
    }

    void dropEveryOtherRecursive(Node *h)
    {
        if (h == nullptr || h->next == nullptr)
        {
            return;
        }

        Node *toDelete = h->next;
        h->next = h->next->next;
        delete toDelete;
        dropEveryOtherRecursive(h->next);
    }

    void reverse()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
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
    }

    Node *recursiveReverse(Node *h)
    {
        if (h == nullptr || h->next == nullptr)
        {
            return h;
        }

        Node *res = recursiveReverse(h->next);
        h->next->next = h;
        h->next = nullptr;
        return res;
    }

    Node *find(int val) const
    {
        Node *curr = head;

        while (curr)
        {
            if (curr->value == val)
            {
                return curr;
            }
            curr = curr->next;
        }

        return nullptr;
    }

    Node *findRecursive(Node *h, int val) const
    {
        if (h == nullptr)
        {
            return h;
        }
        else if (h->value == val)
        {
            return h;
        }

        return findRecursive(h->next, val);
    }

    std::vector<Node *> findAll(int val)
    {
        std::vector<Node *> result;

        if (head == nullptr)
        {
            return result;
        }

        Node *curr = head;

        while (curr)
        {
            if (curr->value == val)
            {
                result.push_back(curr);
            }
            curr = curr->next;
        }

        return result;
    }

    Node *merge(Node *secondHead)
    {
        if (head == nullptr)
        {
            head = secondHead;
            return head;
        }

        if (secondHead == nullptr)
        {
            return head;
        }

        Node *curr = head;

        while (curr->next)
        {
            curr = curr->next;
        }

        curr->next = secondHead;
        return head;
    }

    void doubleList()
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node *curr = head;
            while (curr)
            {
                Node *newNode = new Node(curr->value);
                Node *pom = curr->next;
                curr->next = newNode;
                newNode->next = pom;

                curr = curr->next->next;
            }
        }
    }

    void doubleListAtTheEnd()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *curr = head;
        std::size_t sizeOfList = 1; // 1 because we finish while loop when curr->next is false, not when curr is false

        while (curr->next)
        {
            sizeOfList++;
            curr = curr->next;
        }

        Node *duplicated = head;
        for (std::size_t i = 0; i < sizeOfList; ++i)
        {
            Node *newNode = new Node(duplicated->value);
            curr->next = newNode;
            newNode->next = nullptr;
            curr = curr->next;
            duplicated = duplicated->next;
        }
    }

    void swapAllElementsWithNextOne()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        else
        {
            Node *curr = head;
            Node *prev = nullptr;
            head = head->next; // Next element will be the first after swap

            while (curr && curr->next)
            {

                Node *pom = curr->next;
                Node *pomNext = curr->next->next;

                curr->next = pomNext;
                pom->next = curr;

                if (prev)
                {
                    prev->next = pom;
                }

                prev = curr; // before we move to the next element remember previous element
                curr = curr->next;
            }
        }
    }

    void swapElementBasedOnValue(int val)
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node *curr = head;
            Node *prev = nullptr;
            while (curr->value != val)
            {
                prev = curr;

                // Protection before missing value
                if (curr->next)
                {
                    curr = curr->next;
                }
                else
                {
                    return;
                }
            }

            if (curr && curr->next)
            {
                Node *tail = curr->next->next; // Rest of list after swapped element
                Node *toSwap = curr->next;     // Element to be swapped with
                toSwap->next = curr;
                curr->next = tail;

                if (prev)
                {
                    prev->next = toSwap;
                }
                else
                {
                    head = toSwap;
                }
            }
        }
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

    void printRecursive(Node *h, std::size_t index) const
    {
        if (h == nullptr)
        {
            std::cout << "\n";
            return;
        }

        std::cout << "i: " << index++ << " value: " << h->value << "\n";
        printRecursive(h->next, index);
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
    list.pushFront(2);
    list.pushFront(21);
    list.pushFront(33);
    list.pushFront(2);
    list.pushFront(2);
    list.pushFront(2);
    list.pushFront(2);

    list.dropFront();
    list.dropBack();
    list.dropBack();

    list.dropAtIndex(2);

    list.reverse();
    list.printRecursive(list.getHead(), 0);

    list.setHead(list.recursiveReverse(list.getHead()));
    list.printList();

    std::cout << *(list.findRecursive(list.getHead(), 62136));

    std::vector<LinkedList::Node *> res = list.findAll(2);

    for (auto &a : res)
    {
        std::cout << *a;
    }

    LinkedList sorted;
    sorted.pushBack(1);
    sorted.pushBack(3);
    sorted.pushBack(4);
    sorted.pushBack(7);

    sorted.printList();
    sorted.pushSorted(1);
    sorted.pushSorted(-5);
    sorted.pushSorted(6);
    sorted.pushSorted(10);
    sorted.printList();

    list.merge(sorted.getHead());
    sorted.setHead(nullptr);

    list.printList();
    list.dropEveryOther();
    list.printList();
    list.dropEveryOtherRecursive(list.getHead());
    list.printList();

    list.pushAtIndex(0, 1);
    list.printList();

    list.swapAllElementsWithNextOne();
    list.printList();

    list.swapElementBasedOnValue(213);
    list.printList();
}

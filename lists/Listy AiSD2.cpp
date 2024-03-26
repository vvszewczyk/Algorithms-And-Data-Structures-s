#include <iostream>

struct Node
{
    int value;
    Node* next;

    Node(int val, Node* nxt = nullptr)
    {
        this->value = val;
        this->next = nxt;
    }
};

// dodawanie na poczatku
void push_front(Node*& head, int val)
{
    Node* pom = new Node(val);
    pom->next = head;
    head = pom;
}


//dodawnie na koncu
void push_back(Node*& head, int val)
{
    Node* pom = new Node(val);
    if (head == nullptr)
        head = pom;
    else
    {
        Node* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = pom;
    }
}


//wyswietlanie elementow
void show_elements(Node*& head)
{
    while (head)
    {
        std::cout << head->value << ' ';
        head = head->next;
    }
}


//usuwanie elementu rekurencyjnie
void delete_element_rec(Node*& head, int val)
{
    if (head == nullptr)
        return;

    if (head->value == val)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    delete_element_rec(head->next, val);
}


//usuwanie elementu
void delete_element(Node*& head, int val)
{
    if (head == nullptr)
        return;
    else
    {
        Node* pom = head;
        Node* pom2 = head;
        while (pom && pom->value != val)
        {
            pom2 = pom;
            pom = pom->next;
        }
        if (pom == nullptr)
            return;
        else
        {
            pom2->next = pom->next;
            delete pom;
        }
    }

}

//==============================================================

//ZAD 1 usuwanie co 2 element
void delete_every_two(Node*& head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node* pom = head->next;
    head->next = pom->next;
    delete pom;

    delete_every_two(head->next);
}

//ZAD 2 dublowanie listy
void double_list(Node*& head)
{
    if (head == nullptr)
        return;

    Node* pom = head;
    while (pom)
    {
        Node* copy = new Node(pom->value);
        copy->next = pom->next;
        pom->next = copy;
        pom = copy->next;
    }
}

//ZAD 3 dublowanie listy na koncu
void double_list_v2(Node*& head)
{
    int counter = 0;

    if (head == nullptr)
        return;

    Node* pom = head;
    Node* pom2 = head;

    while (pom)
    {
        pom = pom->next;
        counter++;
    }

    for (int i = 0; i < counter; i++)
    {
        push_back(head, pom2->value);
        pom2 = pom2->next;
    }
}

//ZAD 4 srednia arytmetyczna ze wszystkich elementow
float avg(Node*& head)
{
    float sum = 0, counter = 0;
    Node* pom = head;

    while (pom)
    {
        sum += pom->value;
        counter++;
        pom = pom->next;
    }

    if (counter == 0)
        return 0;

    return sum / counter;
}

//ZAD 5 zamiana podanego elementu z jego nastepnikiem
void node_swap(Node*& head, int val)
{
    if (head == nullptr || head->next == nullptr)
        return;

    //jesli pierwsza liczba jest nasza szukana, zamieniamy go
    if (head->value == val)
    {
        Node* nodeToSwap = head;
        Node* nextNode = head->next;
        nodeToSwap->next = nextNode->next;
        nextNode->next = nodeToSwap;
        head = nextNode;
        return;
    }

    Node* pom = head;

    //szukamy pary w ktorej jest szukana wartosc
    while (pom->next && pom->next->next)
    {
        if (pom->next->value == val)
        {
            Node* nodeToSwap = pom->next;
            Node* nextNode = pom->next->next;
            nodeToSwap->next = nextNode->next;
            nextNode->next = nodeToSwap;
            pom->next = nextNode;
            return;
        }
        else
        {
            pom = pom->next;
        }
    }
}

//ZAD 6 Usuwanie elementow parzystych
void delete_if_even(Node*& head)
{
    while (head && head->value % 2 == 0)
    {
        Node* pom = head;
        head = head->next;
        delete pom;
    }

    Node* current = head;

    while (current && current->next)
    {
        if (current->next->value % 2 == 0)
        {
            Node* pom = current->next;
            current->next = pom->next;
            delete pom;
        }
        else
        {
            current = current->next;
        }
    }
}

//ZAD 7 zamiana el. z jego nastepnikiem
void swap(Node*& head)
{
    Node* q = new Node(0);
    q->next = head;
    head = q;
    Node* p = head;

    while (p->next && p->next->next)
    {
        Node* first = p->next;
        Node* second = p->next->next;
        first->next = second->next;
        second->next = first;
        p->next = second;
        p = first;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

//ZAD 8 odwrocenie listy i dopisanie jej do orginalu
void swap_reverse(Node*& head)
{
    Node* A = new Node(head->value);
    Node* pom = head;

    if (head == nullptr)
        return;

    while (pom->next)
    {
        push_front(A, pom->next->value);
        pom = pom->next;
    }

    pom->next = A;
}

//ZAD 9 łączenie dwóch posortowanych list w jedna
void merge(Node*& newNode, Node*& merge1, Node*& merge2)
{
    Node* pom1 = merge1;
    Node* pom2 = merge2;
    Node* last = nullptr;

    while (pom1 && pom2)
    {
        Node* pom3 = nullptr;
        if (pom1->value < pom2->value)
        {
            pom3 = pom1;
            pom1 = pom1->next;
        }
        else
        {
            pom3 = pom2;
            pom2 = pom2->next;
        }

        if (!newNode)
        {
            newNode = pom3;
            last = pom3;
        }
        else
        {
            last->next = pom3;
            last = pom3;
        }
    }

    if (pom1)
        last->next = pom1;
    else if (pom2)
        last->next = pom2;
    else return;
}

//ZAD 10.1 dzielenie listy "raz jeden raz drugi"
void split_every_second(Node*& head, Node*& newHead1, Node*& newHead2)
{
    if (head == nullptr)
        return;

    Node* pom = head;
    Node* last1 = nullptr;
    Node* last2 = nullptr;
    int switcher = 0;

    while (pom)
    {
        if (switcher % 2 == 0)
        {
            if (!newHead1)
            {
                newHead1 = pom;
                last1 = pom;
            }
            else
            {
                last1->next = pom;
                last1 = pom;
            }
        }
        else
        {
            if (!newHead2)
            {
                newHead2 = pom;
                last2 = pom;
            }
            else
            {
                last2->next = pom;
                last2 = pom;
            }
        }

        Node* next = pom->next;
        pom->next = nullptr;
        pom = next;
        switcher++;
    }
}

//ZAD 10.2 dzielenie listy w polowie
void split_in_half(Node*& head, Node*& newHead1, Node*& newHead2)
{
    if (head == nullptr) 
        return;

    int counter = 0;
    Node* pom = head;

    while (pom) 
    {
        counter++;
        pom = pom->next;
    }

    counter = counter / 2;

    //reset
    pom = head;

    Node* last = nullptr;
    for (int i = 0; i < counter; i++) 
    {
        if (!newHead1) 
        {
            newHead1 = pom;
            last = pom;
        }
        else 
        {
            last->next = pom;
            last = pom;
        }

        pom = pom->next;
    }

    //odlaczenie od reszty
    if (last)
        last->next = nullptr;

    newHead2 = pom;
}



int main()
{
    Node* head = nullptr;
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    push_back(head, 1);
    push_back(head, 8);
    push_back(head, 13);
    push_back(head, 54);
    push_back(head, -6);
    push_back(head, 7);
    push_back(head, 10);



    /*ZAD1*/ //delete_every_two(head);
    /*ZAD2*/ //double_list(head);
    /*ZAD3*/ //double_list_v2(head);
    /*ZAD4*/ //cout << "Srednia: " << avg(head) << "\n";
    /*ZAD5*/ //node_swap(head, 8);
    /*ZAD6*/ //delete_if_even(head);
    /*ZAD7*/ //swap(head);
    /*ZAD8*/ //swap_reverse(head);
    /*ZAD9*/ //merge(head, head1, head2);
    /*ZAD10.1*/ //split_every_second(head, head1, head2); show_elements(head1); cout << endl; show_elements(head2);
    /*ZAD10.2*/ //split_in_half(head, head1, head2); show_elements(head1); cout << endl; show_elements(head2);

    //show_elements(head);
}
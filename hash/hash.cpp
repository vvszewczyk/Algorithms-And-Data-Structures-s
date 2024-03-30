#include <iostream>
#include <cctype>


struct Node
{
    std::string value;
    Node* next;

    Node(std::string val, Node* next = nullptr)
    {
        this->value = val;
        this->next = next;
    }
};

void push_back(Node*& head, std::string val)
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

void print_element(Node* node)
{
    if (node)
    {
        std::cout << node->value << " -> ";
        print_element(node->next);
    }
    else
    {
        std::cout << "NULL\n";
    }
}

void printList(Node** list, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "\nLista " << i + 1 << ": ";
        print_element(list[i]);
    }
}

int hashed(std::string key)
{
    int sum = 1;
    for (char ch : key)
    {
        sum = (sum * 31 + tolower(ch)) % 13;
    }
    return sum;
}

void makeList(Node**& list, int size)
{
    list = new Node * [size];
    for (int i = 0; i < size; ++i)
        list[i] = nullptr;
}

int main()
{
    std::string names[] = { "Alicja", "Maciek", "Wojtek", "Tomek", "Piotrek",
                      "Rafał", "Gniewosz", "Przemek", "wacek", "mirek" };

    Node** list;
    makeList(list, 13);

    for (std::string name : names)
    {
        int hash = hashed(name);
        push_back(list[hash], name);
    }

    printList(list, 13);
}
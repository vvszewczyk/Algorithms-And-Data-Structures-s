#include <iostream>
#include <string>


struct Node_tree
{
    char znak;
    int czestosc;
    Node_tree* L = nullptr;
    Node_tree* P = nullptr;
};

struct Node_list
{
    Node_tree value;
    Node_list* next;

    Node_list(Node_tree val, Node_list* nxt = nullptr)
    {
        this->value = val;
        this->next = nxt;
    }

    int size()
    {
        Node_list* pom = this;
        int counter = 0;
        while (pom)
        {
            counter++;
            pom = pom->next;
        }

        return counter;
    }
};

void push_back(Node_list*& head, Node_tree val)
{
    Node_list* pom = new Node_list(val);
    if (head == nullptr)
        head = pom;
    else 
    {
        Node_list* current = head;
        while (current->next) 
        {
            current = current->next;
        }
        current->next = pom;
    }
}

void delete_element(Node_list*& head, Node_tree val)
{
    if (head == nullptr)
        return;
    else
    {
        Node_list* pom = head;
        Node_list* pom2 = head;
        while (pom && pom->value.znak != val.znak)
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

void create_node_list(int *tab, Node_list*& head, int charCounter, int nodeCounter) 
{
    for (int i = 0; i <= 255; i++) 
    {
        if (tab[i] > 0) 
        {
            Node_tree tree;
            tree.znak = i;
            tree.czestosc = tab[i];
            push_back(head, tree);
            nodeCounter++;
            if (nodeCounter == charCounter)
                break;
        }
    }
}

void insertion_sort(Node_list*& head, Node_tree newNode)
{
    Node_list* new_node = new Node_list(newNode);
    if (head == nullptr || newNode.czestosc < head->value.czestosc)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        Node_list* current = head;
        while (current->next && current->next->value.czestosc < newNode.czestosc)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void sort_list(Node_list*& head)
{
    Node_list* sorted = nullptr;
    Node_list* pom = head;
    while (pom)
    {
        insertion_sort(sorted, pom->value);
        pom = pom->next;
    }
    head = sorted;
}

int char_counter(std::string message, int* tab)
{
    int charCounter = 0;
    for (char i : message)
    {
        if (tab[i] == 0)
            charCounter++;//unikalny

        tab[i]++; //zwieksz wystapienie danego znaku
    }
    return charCounter;
}

void show_elements(Node_list*& head)
{
    Node_list* pom = head;
    while (pom)
    {
        std::cout << pom->value.znak << ": " << pom->value.czestosc << std::endl;
        pom = pom->next;
    }
}

bool contains(Node_tree* node, char ch) 
{
    if (node == nullptr) 
        return false;
    if (node->znak == ch) 
        return true;

    return contains(node->L, ch) || contains(node->P, ch);
}

std::string encode_message(Node_tree* root, std::string message)
{
    std::string encodedMessage = "";
    for (char ch : message)
    {
        Node_tree* pom = root;
        std::string code = "";

        while (pom)
        {
            if (pom->znak == ch)
            {
                break;
            }
            else if (pom->L && contains(pom->L, ch))
            {
                code += '0';
                pom = pom->L;
            }
            else if (pom->P && contains(pom->P, ch))
            {
                code += '1';
                pom = pom->P;
            }
        }
        encodedMessage += code;
    }
    return encodedMessage;
}

std::string decode_message(Node_tree* root, std::string message)
{
    Node_tree* pom = root;
    std::string decodedMessage = "";

        for (char ch : message)
        {
            if (ch == '0')
                pom = pom->L;
            else if (ch == '1')
                pom = pom->P;

            if (pom->znak != '\0' && pom->L == nullptr && pom->P == nullptr)
            { 
                decodedMessage += pom->znak;
                pom = root;
            }
        }
    return decodedMessage;
}

void build_huffmano(Node_list*& head) 
{
    while (head && head->next) 
    {
        Node_list* first = head;
        head = head->next;
        Node_list* second = head;
        head = head->next;

        Node_tree* compressed = new Node_tree();
        compressed->znak = '\0';
        compressed->czestosc = first->value.czestosc + second->value.czestosc;
        compressed->L = new Node_tree(first->value);
        compressed->P = new Node_tree(second->value);

        delete first;
        delete second;

        push_back(head, *compressed);
        sort_list(head);
    }
}

void print_huffmano(Node_list*& head, std::string message)
{
    if (head)
    {
        std::string encoded_message = encode_message(&(head->value), message);
        std::cout << "Niezakodowana wiadomość: " << message << std::endl<< std::endl;
        std::cout << "Zakodowana wiadomość: " << encoded_message << std::endl << std::endl;
        std::cout << "Odkodowana z powrotem: " << decode_message(&head->value, encode_message(&head->value, message)) << std::endl;
    }
}

int main()
{
    const std::string message = "DAAFDDGFDSESESFSFDDFADFDAFDAFDDFSFDSFDSFDSDXFDDFSFDFFDAFDFDXFDFDGFDGFDSDAAAASAADSASASASASASASASAAAAAAAAASASSAWASAAAAAASASASDADDSADSADSSAASAAAADSADSSDAAAAADSASADSAAAAAAAASDADSADSADSASASASSSAAAAASSADSASADSAAAAFDFESDSADSADDSADADSFFFDSDSDAAAAAA";
    int tab[256] = { 0 };
    
    int charCounter = char_counter(message, tab);

    /*
    cout << "Zliczenia kazdego znaku: \n";
    /*for (int i = 0; i < message.length(); i++)
    {
        char znak;
        znak = message[i];
        cout << znak << ": " << tab[znak] << endl;
    }
    for (char ch : message)
        cout << ch << ": " << tab[ch] << endl;
    */
    Node_list* head = nullptr;
    int nodeCounter = 0;
    create_node_list(tab, head, charCounter, nodeCounter);

    std::cout << "Wierzcholki przed sortowaniem: \n";
    show_elements(head);

    sort_list(head);
    //cout << "Posortowane wierzcholki: \n";
    //show_elements(head);

    build_huffmano(head);
    print_huffmano(head, message);
    

    return 0;
}

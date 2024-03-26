#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* P;
    Node* L;
    Node* R;
};

void insert_BST(Node*& root, int val, Node* parent = nullptr)
{
    if (root == nullptr)
    {
        root = new Node;
        root->value = val;
        root->R = nullptr;
        root->L = nullptr;
        root->P = parent;
    }
    else
    {
        if (val >= root->value)
        {
            insert_BST(root->R, val, root);
        }
        else
        {
            insert_BST(root->L, val, root);
        }
    }
}

void inorder(Node*& root)
{
    if (root)
    {
        inorder(root->L);
        cout << root->value << endl;
        inorder(root->R);
    }
}

Node* search_element(Node*& root, int val)
{
    if (root)
    {
        if (root->value == val)
            return root;
        else if (root->value > val)
            search_element(root->L, val);
        else
            search_element(root->R, val);
    }
    else
        return nullptr;
}

Node* min(Node *& root)
{
    Node* pom = root;

    while (pom->L)
        pom = pom->L;

    return pom;
}

Node* max(Node*& root)
{
    Node* pom = root;
    while (pom->R)
        pom = pom->R;
    return pom;
}

Node* poprzednik(Node*& root)
{
    if (root == nullptr)
        return nullptr;

    if (root->L)
        return max(root->L);
    else
    {
        Node* parent = root->P;
        // w gore
        while (parent && root == parent->L)
        {
            root = parent;
            parent = parent->P;
        }

        return parent;
    }
}

Node* nastepnik(Node*& root)
{
    if (root == nullptr)
        return nullptr;

    if (root->R)
        return min(root->R);
    else
    {
        Node* parent = root->P;
        //w gore
        while (parent && root == parent->R)
        {
            root = parent;
            parent = parent->P;
        }

        return parent;
    }
}

Node* remove_BST(Node* root, int val)
{
    if (root == nullptr)
        return root;

    if (root->value > val)
    {
        root->L = remove_BST(root->L, val);
        if (root->L)
            root->L->P = root;
        return root;
    }
    else if (root->value < val)
    {
        root->R = remove_BST(root->R, val);
        if (root->R)
            root->R->P = root;
        return root;
    }

    if (root->L==nullptr)
    {
        Node* pom = root->R;
        if (pom)
            pom->P = root->P;
        delete root;
        return pom;
    }
    else if (!root->R)
    {
        Node* pom = root->L;
        if (pom)
            pom->P = root->P;
        delete root;
        return pom;
    }
    else
    {
        Node* Nastepnik = nastepnik(root);

        if (Nastepnik->L == nullptr)
        {
            root->value = Nastepnik->value;
            root->R = remove_BST(root->R, Nastepnik->value);
            if (root->R)
                root->R->P = root;
        }

        return root;
    }
}

int main()
{
    Node* root = nullptr;


    insert_BST(root, 2);
    insert_BST(root, -4);
    insert_BST(root, 12);
    insert_BST(root, 7);
    insert_BST(root, 122);
    insert_BST(root, 11);
    insert_BST(root, 111);



      root=remove_BST(root, 2);
      root=remove_BST(root, -4);
      root=remove_BST(root, 12);


    inorder(root);
    //cout << endl;
    //Node* found = search_element(root, 21);

  //  Node* wynik=nastepnik(found);

    //if(wynik)
    //cout << wynik->value;

   /*

    if (found)
        cout << found->value;
    else
        cout << "nie ma";
        
        */
}

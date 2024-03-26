#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <ctime>



struct Node
{
    int value;
    Node* P;
    Node* L;
    Node* R;
    int height;
};

//wysokosc
int height(Node* root) 
{
    if (root == nullptr)
        return 0;
    return root->height;
}

//balans
int getBalance(Node* root)
{
    if (root == nullptr)
        return 0;
    return height(root->L) - height(root->R);
}

//LL rotation
Node* rightRotate(Node* A) 
{
    Node* Ap = A->P;
    Node* B = A->L;
    Node* Br = B->R;

    B->R = A;
    A->L = Br;

    B->P = A->P;
    A->P = B;
    if (Br) 
    Br->P = A;

    if (Ap)
    {
        if (Ap->L == A)
            Ap->L = B;
        else if (Ap->R == A)
            Ap->R = B;
    }

    A->height =1 + std::max(height(A->L), height(A->R));
    B->height =1 + std::max(height(B->L), height(B->R));


    return B;
}

//RR rotation
Node* LeftRotate(Node* A) 
{
    Node* Ap = A->P;
    Node* B = A->R;
    Node* Bl = B->L;

    B->L = A;
    A->R = Bl;

    B->P = A->P;
    A->P = B;
    if (Bl)
        Bl->P = A;

    if (Ap)
    {
        if (Ap->L == A)
            Ap->L = B;
        else if (Ap->R == A)
            Ap->R = B;
    }

    A->height = 1 + std::max(height(A->L), height(A->R));
    B->height = 1 + std::max(height(B->L), height(B->R));

    return B;
}

//info o wezle
void printNodeInfo(Node* node)
{
    if (node == nullptr)
    {
        std::cout << "Wezel pusty" << std::endl;
        return;
    }

    std::cout << "Wartosc wezła: " << node->value << std::endl;

    if (node->P)
        std::cout << "Rodzic: " << node->P->value << std::endl;
    else
        std::cout << "Brak rodzica" << std::endl;


    if (node->L)
        std::cout << "Lewe dziecko: " << node->L->value << std::endl;
    else
        std::cout << "Brak lewego dziecka" << std::endl;


    if (node->R)
        std::cout << "Prawe dziecko: " << node->R->value << std::endl;
    else
        std::cout << "Brak prawego dziecka" << std::endl;

    // Dodanie wyświetlania balansu
    std::cout << "BALANS: " << getBalance(node) << std::endl;
    std::cout << "WYOSKOSC: " << node->height << std::endl;

    std::cout << "\n\n" << std::endl;
}

//wyswietlanie calej struktury drzewa
void printTreeStructure(Node* root) 
{
    if (root == nullptr) 
    {
        std::cout << "Drzewo jest puste." << std::endl;
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        Node* node = q.front();
        q.pop();

        printNodeInfo(node);

        if (node->L) q.push(node->L);
        if (node->R) q.push(node->R);
    }
}

//wstawianie do bst z uwzglednieniem rodzicow
Node* insert_BST(Node*& root, int val, Node* P = nullptr)
{
    if (root == nullptr)
    {
        root = new Node;
        root->value = val;
        root->R = nullptr;
        root->L = nullptr;
        root->P = P;
        root->height = 1;

        return root;
    }
    else
    {
        if (val >= root->value)
        {
            return insert_BST(root->R, val, root);
        }
        else
        {
            return insert_BST(root->L, val, root);
        }
        root->height = 1 + std::max(height(root->L), height(root->R));
    }
}

//wstawianie avl
void insert_AVL(Node*& root, int val) 
{
    Node* pom = insert_BST(root, val)->P;

    // Balansowanie drzewa AVL
    while (pom) 
    {
        pom->height = 1 + std::max(height(pom->L), height(pom->R));

        int balance = getBalance(pom);
        int balance_L = getBalance(pom->L);
        int balance_R = getBalance(pom -> R);

        // LL
        if (balance > 1 && balance_L >= 0) 
        {
            if (pom == root)
                root = rightRotate(pom);
            else
                pom = rightRotate(pom);
        }

        // RR
        else if (balance < -1 && balance_R <= 0) 
        {
            if (pom == root)
                root = LeftRotate(pom);
            else
                pom = LeftRotate(pom);
        }

        // LR
        else if (balance > 1 && balance_L < 0) 
        {
            pom->L = LeftRotate(pom->L);
            if (pom == root)
                root = rightRotate(pom);
            else
                pom = rightRotate(pom);
        }

        // RL
        else if (balance < -1 && balance_R > 0) 
        {
            pom->R = rightRotate(pom->R);
            if (pom == root)
                root = LeftRotate(pom);
            else
                pom = LeftRotate(pom);
        }

        pom = pom->P;
    }
}

//minimum
Node* min(Node*& root)
{
    Node* pom = root;

    while (pom->L != nullptr)
        pom = pom->L;

    return pom;
}

//nastepnik
Node* nastepnik(Node*& root)
{
    if (root == nullptr)
        return nullptr;

    if (root->R)
        return min(root->R);
    else
    {
        Node* P = root->P;
        //w gore
        while (P && root == P->R)
        {
            root = P;
            P = P->P;
        }

        return P;
    }
}

//usuwanie z bst z uwzglednieniem rodzicow
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

    if (root->L == nullptr)
    {
        Node* pom = root->R;
        if (pom)
            pom->P = root->P;
        delete root;
        return pom;
    }
    else if (root->R==nullptr)
    {
        Node* pom = root->L;
        if (pom)
            pom->P = root->P;
        delete root;
        return pom;
    }
    else
    {
        Node* Nastepnik = nastepnik(root); //najmniejszy wezel w prawym poddrzewie
        root->value = Nastepnik->value;
        root->R = remove_BST(root->R, Nastepnik->value);
        if (root->R)
            root->R->P = root;

        return root;
    }
}

//usuwanie avl
Node* remove_AVL(Node*& root, int val) 
{
    root = remove_BST(root, val);

    Node* pom = root;
    while (pom)
    {
        pom->height = 1 + std::max(height(pom->L), height(pom->R));

        int balance = getBalance(pom);
        int balance_L = getBalance(pom->L);
        int balance_R = getBalance(pom->R);

        // LL
        if (balance > 1 && balance_L >= 0)
        {
            if (pom == root)
                root = rightRotate(pom);
            else
                pom = rightRotate(pom);
        }

        // RR
        else if (balance < -1 && balance_R <= 0)
        {
            if (pom == root)
                root = LeftRotate(pom);
            else
                pom = LeftRotate(pom);
        }

        // LR
        else if (balance > 1 && balance_L < 0)
        {
            pom->L = LeftRotate(pom->L);
            if (pom == root)
                root = rightRotate(pom);
            else
                pom = rightRotate(pom);
        }

        // RL
        else if (balance < -1 && balance_R > 0)
        {
            pom->R = rightRotate(pom->R);
            if (pom == root)
                root = LeftRotate(pom);
            else
                pom = LeftRotate(pom);
        }

        pom = pom->P;
    }
    return root;
}



int main()
{
    Node* root = nullptr;
   
    /*
    srand(time(NULL));

    for (int i = 0; i < 7; i++)
        insert_AVL(root, 0+( rand() % 101));
    */

    insert_AVL(root, 40);
    insert_AVL(root, 20);
    insert_AVL(root, 10);
    insert_AVL(root, 25);
    insert_AVL(root, 30);
    insert_AVL(root, 22);
    insert_AVL(root, 50);


    remove_AVL(root, 25);

    printTreeStructure(root);

    return 0;
}

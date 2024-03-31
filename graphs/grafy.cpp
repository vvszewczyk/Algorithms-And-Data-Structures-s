#include <iostream>
#include <fstream>

struct NodeNeighbour
{
    int wierzcholek, dlugosc;
    NodeNeighbour* next;
    NodeNeighbour(int w, int d) : wierzcholek(w), dlugosc(d), next(nullptr) {}
};

struct NodeEdge
{
    int start, end, length;
    NodeEdge* next;
    NodeEdge(int s = 0, int e = 0, int l = 0, NodeEdge* n = nullptr) : start(s), end(e), length(l), next(n) {};
};

int** readMatrix(int& size)
{
    std::ifstream file("graf.txt");
    if (!file.is_open())
    {
        std::cerr << "Nie mozna wczytac pliku";
        return nullptr;
    }

    file >> size;
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            file >> matrix[i][j];
        }
    }
    file.close();
    return matrix;
}

void push_back(NodeNeighbour*& head, int w, int d)
{
    NodeNeighbour* pom = new NodeNeighbour(w, d);
    if (head == nullptr)
        head = pom;
    else
    {
        NodeNeighbour* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = pom;
    }
}

void push_back(NodeEdge*& head, int s, int e, int l)
{
    NodeEdge* pom = new NodeEdge(s, e, l);
    if (head == nullptr)
        head = pom;
    else
    {
        NodeEdge* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = pom;
    }
}

int** createMatrixFromNeighbourList(NodeNeighbour** list, int size) 
{
    int** matrix = new int* [size];
    for (int i = 0; i < size; i++) 
    {
        matrix[i] = new int[size] {0};
        for (NodeNeighbour* current = list[i]; current; current = current->next) 
        {
            matrix[i][current->wierzcholek] = current->dlugosc;
        }
    }
    return matrix;
}

int** createMatrixFromEdgeList(NodeEdge* edgeList, int vertexCount) 
{
    int** matrix = new int* [vertexCount];

    for (int i = 0; i < vertexCount; i++) 
    {
        matrix[i] = new int[vertexCount] {0};
    }

    NodeEdge* current = edgeList;
    while (current) 
    {
        int start = current->start;
        int end = current->end;
        int length = current->length;

        matrix[start][end] = length;
        matrix[end][start] = length;

        current = current->next;
    }

    return matrix;
}

NodeNeighbour** createNeighbourListFromMatrix(int** matrix, int size)
{
    NodeNeighbour** list = new NodeNeighbour * [size];
    for (int i = 0; i < size; i++)
    {
        list[i] = nullptr;
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != 0)
            {
                push_back(list[i], j, matrix[i][j]);
            }
        }
    }
    return list;
}

NodeNeighbour** createNeighbourListFromEdgeList(NodeEdge* edgeList, int size)
{
    NodeNeighbour** neighbourList = new NodeNeighbour * [size] {0};

    NodeEdge* current = edgeList;
    while (current)
    {
        int start = current->start;
        int end = current->end;
        int length = current->length;

        push_back(neighbourList[start], end, length);
        push_back(neighbourList[end], start, length);

        current = current->next;
    }
    return neighbourList;
}

NodeEdge* createEdgeListFromMatrix(int** matrix, int size)
{
    NodeEdge* list = nullptr;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (matrix[i][j] != 0)
            {
                push_back(list, i, j, matrix[i][j]);
            }
        }
    }
    return list;
}

NodeEdge* createEdgeListFromNeighbourList(NodeNeighbour** neighbourList, int size) 
{
    NodeEdge* edgeList = nullptr;

    for (int i = 0; i < size; i++) 
    {
        NodeNeighbour* current = neighbourList[i];
        while (current) 
        {
            //sprawdzanie czy indeks aktualnego wierzcholka jest mniejszy niz indeks sasiada
            if (i < current->wierzcholek) //zapobieganie duplikatow np. z a do b i b do a
            {
                push_back(edgeList, i, current->wierzcholek, current->dlugosc);
            }
            current = current->next;
        }
    }
    return edgeList;
}


void printNeighbourList(NodeNeighbour** list, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "\nLN[" << i << "]->";
        NodeNeighbour* current = list[i];
        while (current != nullptr)
        {
            std::cout << current->wierzcholek << "/" << current->dlugosc << "->";
            current = current->next;
        }
        std::cout << "NULL";
    }
    std::cout << std::endl;
}

void printMatrix(int** matrix, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void printEdgeList(NodeEdge* list)
{
    NodeEdge* current = list;
    while (current != nullptr)
    {
        std::cout << current->start << "|" << current->end << "(" << current->length << ") -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}




int main() {
    int size;
    int** matrix = readMatrix(size);

    // MATRIX -> NEIGHBOUR LIST
    NodeNeighbour** listn1 = createNeighbourListFromMatrix(matrix, size);
    printNeighbourList(listn1, size);

    std::cout << "\n\n";

    // NEIGBOUR LIST -> MATRIX
    int** m2 = createMatrixFromNeighbourList(listn1, size);
    printMatrix(m2, size);

    std::cout << "\n\n";

    // MATRIX -> EDGE LIST
    NodeEdge* liste2 = createEdgeListFromMatrix(matrix, size);
    printEdgeList(liste2);

    // EDGE LIST -> NEIGHBOUR LIST
    NodeNeighbour** listn2 = createNeighbourListFromEdgeList(liste2, size);
    printNeighbourList(listn2, size);

    // EDGE LIST -> MATRIX
    int** m3 = createMatrixFromEdgeList(liste2, size);
    printMatrix(m3, size);

    // NEIGHBOUR LIST -> EDGE LIST
    NodeEdge* edgeListFromNeighbourList = createEdgeListFromNeighbourList(listn1, size);
    printEdgeList(edgeListFromNeighbourList);



}


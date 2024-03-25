#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

struct Node 
{
	string key;	//Klucz - szluzy do wyszukiwania np. przy studentu nr. albumu
	Node* parent;	//rodzic - wskaźnik na rodzica
	Node* left; //lewa strona drzewa - elementy mniejsze
	Node* right; //prawa strona drzewa - elementy wieksze lub równe
};


Node* newNode(string key) 
{
	Node* node = new Node;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->key = key;
	return node;
}

//Dodaje węzł do drzewa
Node* insert(Node* root, string key) 
{
	if (root == NULL) 
	{
		return newNode(key);
	}
	if (key < root->key) 
	{
		Node* left_child = insert(root->left, key);
		root->left = left_child;
		left_child->parent = root;
	}
	else if (key > root->key) 
	{
		Node* right_child = insert(root->right, key);
		root->right = right_child;
		right_child->parent = root;
	}
	return root;
}

//wyszukiwanie elementow o podanym kluczu
Node* search(Node* root, string key) 
{
	Node* current = root;
	while (current && current->key != key) 
	{
		if (key < current->key) 
		{
			current = current->left;
		}
		else 
		{
			current = current->right;
		}
	}
	return current;
}

//Usuwa całe drzewo
void deleteTree(Node* root) 
{
	if (root) 
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
}

//Uwuwa wezel o podanym kluczu
Node* remove(Node* root, string key) 
{
	if (root == NULL) 
	{
		return NULL;
	}
	if (key < root->key) 
	{
		root->left = remove(root->left, key);
	}
	else if (key > root->key) 
	{
		root->right = remove(root->right, key);
	}
	else 
	{
		if (root->left == NULL) 
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) 
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* temp = root->right;
		while (temp->left) 
		{
			temp = temp->left;
		}
		root->key = temp->key;
		root->right = remove(root->right, temp->key);
	}
	return root;
}

//wyswietlanie in-order
void inOrderPrint(Node* root) 
{
	if (root) 
	{
		inOrderPrint(root->left);
		cout << root->key << " ";
		inOrderPrint(root->right);
	}
}

//Sprawdzanie klucza slowanika
bool isValid(string word) {
	if (word.length() != 4) {
		return false;
	}
	for (int i = 0; i < 4; i++) {
		char c = word[i];
		if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'P') || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || (c >= 'Q' && c <= 'Z'))) {
			return false;
		}
		return true;
	}
	return true;
}

//Wyszukiwanie zaawansowane
Node* advancedSearch(Node* node, string prefix) 
{
	if (node == nullptr) 
	{
		return nullptr;
	}
	if (prefix <= node->key && node->key.substr(0, prefix.length()) == prefix) 
	{ //jezeli prefix jest takie jak key o rozmiarze prefix
		return node;
	}

	if (prefix > node->key) 
	{
		return advancedSearch(node->right, prefix);
	}
	else 
	{
		Node* result = advancedSearch(node->left, prefix);
		if (result == nullptr) 
		{
			return advancedSearch(node->right, prefix);
		}
		else 
		{
			return result;
		}
	}
}

//Wypisanie wyniku funkcji advancedSearch - jako pierwszy znaleziony
void advancedSearchAndPrint(Node* node, string prefix) 
{
	Node* result = advancedSearch(node, prefix);

	if (result == nullptr) 
	{
		cout << "Nie znaleziono pasujacych slow" << endl;
	}
	else 
	{
		cout << "Znaleziono slowo: " << result->key << endl;
	}
}

int main() 
{
	Node* root = nullptr;
	root = insert(root, "Q4#E");
	root = insert(root, "Q4#E2213");

	//Wyszukiwanie w slowniku
	string slowo, newWord, text;
	int task;

	while (true) 
	{
		//Wypisane drzewa in-order
		inOrderPrint(root);
		cout << endl;

		cout << "Co chcesz zrobic?\n1-szukaj slowa\n2-wyszukiwanie zaawanasowane\n3-dodaj slowo\n4-edytuj slowo" << endl;
		cin >> task;

		switch (task) 
		{
		case 1:
			cout << "Wybrales wyszukiwanie slowa w slowniku." << endl;

			cout << "Posze podac szukane slowo." << endl;
			cin >> slowo;

			if (search(root, slowo)) 
			{
				cout << "Podane slowo znajduje sie w slowniku." << endl;
			}
			else 
			{
				cout << "Podane slowo NIE znajduje sie w slowniku." << endl;
			}
			break;

		case 2:
			cout << "Wybrales opcje wyszukiwania zaawansowanego." << endl;
			cout << "Podaj tekst" << endl;
			cin >> text;

			advancedSearchAndPrint(root, text);

			break;
		case 3:
			cout << "Wybrales opcje dodania slowa" << endl;

			cout << "Podaj slowo" << endl;
			cin >> slowo;

			if (search(root, slowo)) 
			{
				cout << "Podane slowo znajduje sie w slowniku. Nie mozna dodac :,<" << endl;
			}
			else {
				if (isValid(slowo)) 
				{
					cout << "Slowo dodano pomyslnie." << endl;
					root = insert(root, slowo);
				}
				else
					cout << "Blednie wprowadzone slowo" << endl;
			}
			break;
		case 4:
			cout << "Wybrales opcje edycji slowa." << endl;
			cout << "Podaj slowo ktore chcesz edytowac" << endl;
			cin >> slowo;

			if (search(root, slowo)) 
			{
				cout << "Podaj nowe slowo" << endl;
				cin >> newWord;

				if (isValid(newWord) && newWord != slowo) 
				{
					root = remove(root, slowo);
					root = insert(root, newWord);
				}
				else 
				{
					cout << "Slowo nie spelania wymagan lub jest takie samo jak przed zmiana" << endl;
				}
			}
			else 
			{
				cout << "Takiego slowa nie ma." << endl;
			}

			break;
		default:
			cout << "Nie ma takiej opcji :<" << endl;
			return false;
			break;
		}
	}

	deleteTree(root);
	return 0;
}
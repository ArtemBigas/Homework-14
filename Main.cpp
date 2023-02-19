#pragma once
const int ALPHABET_SIZE = 26;
#include <iostream>
using namespace std;
// Структура узла дерева
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, если ключ является концом слова
	bool isEndOfWord;
};
TrieNode* getNewNode(void)
{
	// Выделяем память под новый узел
	struct TrieNode* pNode = new TrieNode;

	// устанавливаем флаг конца слова в false
	pNode->isEndOfWord = false;

	// инициализируем детей нулевым указателем
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
};
// Возвращает новый узел с пустыми детьми

void insert(struct TrieNode* root, string key)
{
	struct TrieNode* node = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!node->children[index])
			node->children[index] = getNewNode();

		node = node->children[index];
	}
	node->isEndOfWord = true;
};
// Возвращает true если ключ есть в дереве, иначе false
bool search(struct TrieNode* root, string key)
{
	TrieNode* node = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!node->children[index])
			return false;

		node = node->children[index];
	}
	return (node != nullptr && node->isEndOfWord);
};


int main() 
{ 
	string word;
	string keys[] = { "go","goad","goa","goal","goat","goatherd","gob","goblin","god","goddess","golf","gone" };
	string part;
	int n = sizeof(keys) / sizeof(keys[0]);//размер словаря

	struct TrieNode* root = getNewNode();
	
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);
	while (true) 
	{
		cout << "enter the word ";
		cin >> word;
			for (int j = 0; j < n; j++) {
				part = keys[j];
				int i = 0;
				while (i < word.length())
				{

					if (word[i] == part[i]) { i++; }
					else
					{
						part = "fail"; break;
					};
				};
				if (part == "fail") {}
				else
				{
					cout << part << endl;
				}

			};
		
	};
	

		return 0; };
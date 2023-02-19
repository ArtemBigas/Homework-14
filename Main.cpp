#pragma once
const int ALPHABET_SIZE = 26;
#include <iostream>
using namespace std;
// ��������� ���� ������
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, ���� ���� �������� ������ �����
	bool isEndOfWord;
};
TrieNode* getNewNode(void)
{
	// �������� ������ ��� ����� ����
	struct TrieNode* pNode = new TrieNode;

	// ������������� ���� ����� ����� � false
	pNode->isEndOfWord = false;

	// �������������� ����� ������� ����������
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = nullptr;

	return pNode;
};
// ���������� ����� ���� � ������� ������

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
// ���������� true ���� ���� ���� � ������, ����� false
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
	int n = sizeof(keys) / sizeof(keys[0]);//������ �������

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
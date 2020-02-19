#pragma once
#include <string>


using namespace std;

class BST
{
public:
	BST();
	~BST();

	void insert(string word);
	void remove(string word);
	int search(string word);
	void next(string word);
	void prev(string word);
	void parent(string word);
	void child(string word);
	void min();
	void max();
	void list();

private:
	struct node
	{
		string word;
		int count = 1;
		node* left = NULL;
		node* right = NULL;
		node* parent = NULL;
	};

	node* root = NULL;

	node* minimum(node* p);
	node* maximum(node* p);
	node* successor(node* p);
	void traverse(node* p, string& list);
};
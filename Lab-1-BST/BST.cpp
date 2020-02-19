#include <iostream>
#include "BST.h"

using namespace std;

BST::BST()
{
	root = NULL;
}

void BST::insert(string word)
{
	node* x = root;
	node* y = NULL;

	while (x != NULL)
	{
		y = x;

		if (x->word == word) {
			x->count += 1;
			return;
		}
		if (word < x->word)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	node* z = new node();
	z->word = word;

	if (y == NULL)
	{
		root = z;
	}
	else if (word < y->word)
	{
		z->parent = y;
		y->left = z;
	}
	else {
		z->parent = y;
		y->right = z;
	}
}

void BST::min()
{
	if (root != NULL)
	{
		cout << minimum(root)->word << "\n";
	}
	else
	{
		cout << "\n";
	}
}

//Tree - Minimum(x)
//1  while x.left ≠ nil
//2      x = x.left
//3  return x
BST::node* BST::minimum(node* p)
{
	while (p->left != NULL)
	{
		p = p->left;
	}
	return p;
}

//Tree - Maximum(x)
//1  while x.right ≠ nil
//2      x = x.right
//3  return x
BST::node* BST::maximum(node* p)
{
	while (p->right != NULL)
	{
		p = p->right;
	}
	return p;
}

//Tree-Successor(x)
//1	if x.right ≠ nil // If x has a right child
//2		then return Tree - Minimum(x.right)
//3	y = x.parent // x has no right child; go up
//4	while y ≠ nil and x == y.right
//5		x = y
//6		y = y.parent
//7	return y
BST::node* BST::successor(node* p)
{
	if (p->right != NULL)
	{
		return minimum(p->right);
	}
	node* y = p->parent;
	while (y != NULL && p == y->right)
	{
		p = y;
		y = y->parent;
	}
	return y;
}

void BST::list()
{
	if (root != NULL)
	{
		cout << "Set contains: ";
		// Declare an empty list string to be populated by comma-separated values.
		string list;

		// By default we assume the first item is number 1.
		int itemCount = 1;

		// Populate the list string with a list of comma-separated values of items and their
		// respective counts.
		traverse(root, list);

		// Parse the comma-separated string list of values into a readable print format,
		// where each item and its count are numbered from 0 to n items in the tree.
		for (int i = 0; i < list.length(); i++)
		{
			// Create the label that will be inserted in front of each item. Looks like ', (n) '
			// where n is the item's number.
			string label = ", (" + to_string(itemCount) + ") ";
			// Replace comma with ', (n) ' where n is the number of the item.
			if (list[i] == ',')
			{
				list.replace(i, 1, label);
				itemCount++; // Increments the item count for the label of the next item, so that it's '(n+1)'
			}
			else if (i == (list.length() - 1)) // At the last character of the list string?
			{
				// Remove the last character (an extraneous comma ',') from the list.
				list = list.substr(0, list.length() - label.length());
				itemCount++; // Increments the item count for the label of the next item, so that it's '(n+1)'
			}
			// Insert the first label at very the beginning of the comma-separated list
			// (This branch is necessary because there is no comma at the beginning of the list to replace,
			// and the label string must be trimmed to '(n) ' from original: ', (n) ').
			else if (i == 0)
			{
				// Trim the label to '(n) ', for the beginning of the list shouldn't start with a comma,
				// and insert the label at the very beginnning of the list string.
				list.insert(0, label.substr(2, label.length()));
				itemCount++; // Increments the item count for the label of the next item, so that it's '(n+1)'
			}
		}
		cout << list << "\n";
	}
	else
	{
		cout << "Set is empty \n";
	}
}

void BST::traverse(node* p, string& list, int itemCount)
{
	if (p->left != NULL)
		traverse(p->left, list, ++itemCount);
	list = list + p->word + " " + to_string(p->count) + ",";
	if (p->right != NULL)
		traverse(p->right, list, ++itemCount);
}

//Tree - Search(k)
//p = root			// p starts at the root, working its way down the tree
//while p  nil		// Continue until p becomes null
	//if p.key == k 		// If we found k, return p to tell where we found it
	//return p
	//if k < p.key		// If not found, then k belongs in either p’s left…
	//	p = p.left		// … or right subtree.
	//else			// Change p to shift our attention to the
	//p = p.right		// appropriate child of where p currently is
//return nil		// If we fell through the while loop, we either fell off a
//				// leaf before finding k (not here), or the tree was empty
//				// to begin with (not here).  Either way, return null
int BST::search(string word)
{
	node* p = root;
	while (p != NULL)
	{
		if (p->word == word)
		{
			return p->count;
		}
		if (word < p->word)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	return 0;
}
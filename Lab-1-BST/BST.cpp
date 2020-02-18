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
		traverse(root);
	}
}

void BST::traverse(node* p)
{
	if (p->left != NULL)
		traverse(p->left);
	cout << p->word << " ";
	if (p->right != NULL)
		traverse(p->right);
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
#include "BST.h"

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
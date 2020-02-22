#include <iostream>
#include "BST.h"

using namespace std;

string stringToLower(const string s) {
	string tmp = s;
	for (int i = 0; i < s.length(); i++)
		tmp[i] = tolower(s[i]);
	return tmp;
}

int main()
{
	string cmd;

	BST* bst = new BST();

	// Loop forever.  The loop's boolean expression must always be true to indefinitely loop.
	while (true) 
	{
		cin >> cmd;

		string command = stringToLower(cmd);

		if (command == "insert") 
		{
			string param;
			cin >> param;

			bst->insert(param);
		}
		else if (command == "delete")
		{
			string param;
			cin >> param;

			bst->remove(param);
		}
		else if (command == "list")
		{
			bst->list();
		}
		else if (command == "search") 
		{
			string param;
			cin >> param;

			bst->search(param);
		}
		else if (command == "child")
		{
			string param;
			cin >> param;

			bst->child(param);
		}
		else if (command == "parent")
		{
			string param;
			cin >> param;

			bst->parent(param);
		}
		else if (command == "next")
		{
			string param;
			cin >> param;

			bst->next(param);
		}
		else if (command == "prev")
		{
			string param;
			cin >> param;

			bst->prev(param);
		}
		else if  (command == "min")
		{
			bst->min();
		}
		else if (command == "max")
		{
			bst->max();
		}
		else if (command == "help")
		{
			string help = "insert <string>\ndelete <string>\nsearch <string>\n";
			help += "min\nmax\nprev <string>\nnext <string>\nlist\nparent <string>\n";
			help += "child <string>\nhelp\nquit\n";
			cout << "Available commands:\n" << help;
		}
		else if (command == "quit")
		{
			delete bst;
			return 0;
		}
		else
		{
			cout << "\n";
		}

	}
}


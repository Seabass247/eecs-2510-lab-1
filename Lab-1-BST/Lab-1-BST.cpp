#include <iostream>
#include "BST.h"

using namespace std;

// A helper function that converts every character in a string to their respective lowercase values,
// and therefore outputs the entire string in lowercase.
string stringToLower(const string s) {
	string tmp = s;
	for (int i = 0; i < s.length(); i++)
		tmp[i] = tolower(s[i]);
	return tmp;
}

// The entry point into this program.
int main()
{
	// An empty string to be used for consuming the program's input for commands.
	string cmd;

	// Create a new, empty binary search tree.
	BST* bst = new BST();

	// Loop forever.  The loop's boolean expression must always be true to indefinitely loop.
	while (true) 
	{
		// cmd contains the raw command string (first word only)
		cin >> cmd;

		// String command is the formatted lowercase version of the raw command string from cmd.
		// command is necessary to make case-insensitive comparisons, because command is guaranteed
		// lowercase and likewise the hardcoded strings it's being compared to are also lowercase.
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


// Sebastian Hamel
// EECS 2510 Non-Linear Data Structures
// 02/23/2020

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

	// The command handling logic will loop forever (the control expression is always true).
	// Gets a single word (command string) from the console.  Comparing the command string,
	// for commands with a parameter, get an additional string for the parameter, and pass
	// the parameter string in the BST's method call.
	while (true)
	{
		// Get a command string from the console.
		// cmd contains the raw command string (first word only).
		cin >> cmd;

		// String command is the formatted lowercase version of the raw command string from cmd.
		// command is necessary to make case-insensitive comparisons, because command is guaranteed
		// lowercase and likewise the hardcoded strings it's being compared to are also lowercase.
		string command = stringToLower(cmd);

		// If the command string is one of the several implemented commands, consume command
		// parameter string if necessary, and perform appropriate operation on the BST.
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
		else if (command == "min")
		{
			bst->min();
		}
		else if (command == "max")
		{
			bst->max();
		}
		else if (command == "help")
		{
			// Output a list of all the available commands and what format each command should be in.
			// Each 'command <param>' pair is printed on its own new line.
			string help = "insert <string>\ndelete <string>\nsearch <string>\n";
			help += "min\nmax\nprev <string>\nnext <string>\nlist\nparent <string>\n";
			help += "child <string>\nhelp\nquit\n";
			cout << "Available commands:\n" << help;
		}
		else if (command == "quit")
		{
			// Call the BST's destructor, which in turn deletes all of the nodes in the BST, and then
			// exit the program by returning 0 (assume everything went ok, thus code 0) in main.
			delete bst;
			return 0;
		}
		else
		{
			// If we got here, the user must have entered an invalid command. Do nothing.
		}
	}
}


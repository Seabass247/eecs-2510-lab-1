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
	cout << "Ready... \n";
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
		else if (command == "list")
		{
			bst->list();
		}
		else if (command == "search") 
		{
			string param;
			cin >> param;

			cout << param << " " << bst->search(param) << "\n";
		}
		else if  (command == "min")
		{
			bst->min();
		}
		else if (command == "max")
		{
			bst->max();
		}
		else
		{
			cout << command << "\n";
		}

	}
}


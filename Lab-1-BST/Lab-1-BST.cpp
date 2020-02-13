#include <iostream>

using namespace std;

string stringToLower(const string s) {
	string tmp = s;
	for (int i = 0; i < s.length(); i++)
		tmp[i] = tolower(s[i]);
	return tmp;
}

int main()
{
	cout << "hello world";
	string cmd;


	// Loop forever.  The loop's boolean expression must always be true to indefinitely loop.
	while (true) 
	{
		cin >> cmd;

		string command = stringToLower(cmd);

		if (command == "search")
		{
			string param;
			cin >> param;
			cout << command << " " << param << "\n";
		}
		else 
		{
			cout << command << "\n";
		}
	}
}


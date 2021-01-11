//program for the welcome function

#include <iostream>
#include <string>

using namespace std;


void tutorial()
{
	cout<<"hello!"<<endl; //logic test
}

int main()
{
	bool exit = false;
	while (!exit)
	{
		char playerinput;
		cout << "+----------------------------------------+" <<endl;
		cout << "|         Ultimate Tic Tac Toe           |" <<endl;
		cout << "+----------------------------------------+" <<endl;
		cout << "| Enter '1' to display the game Tutorial |" <<endl;
		cout << "| Enter '2' to play the game             |" <<endl;
		cout << "| Enter '3' to exit the game             |" <<endl;
		cout << "+----------------------------------------+" <<endl;

		cin >> playerinput;

		if (playerinput == '1')
		{
			tutorial();
		}
		else if (playerinput == '2')
		{

		}
		else if (playerinput == '3')
		{
			exit=true;
		}
		else
		{
			cout<< "Selection Invalid [Back to welcome screen]" <<endl;
		}
	}
	return 0;
}

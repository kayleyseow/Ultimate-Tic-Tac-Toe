// Program snippet for the welcome function
// By Tiffany Z.

#include <iostream>
#include <string>

using namespace std;

// Function Declarations:
void tutorial();
void exitwelcome();

void welcome()
{
	char playerinput;
  cout << " ----------------------------------------" <<endl;
  cout << "|	      Ultimate Tic Tac Toe	         |"<<endl;
  cout << " ----------------------------------------" <<endl;
  cout << "| Enter '1' to display the game Tutorial |" <<endl;
  cout << "| Enter '2' to play the game             |" <<endl;
  cout << "| Enter '3' to exit the game             |" <<endl;
  cout << " ----------------------------------------" <<endl;

	cin >> playerinput;

	if (playerinput == '1')
	{
		//calls the tutorial function
		tutorial();
	}
  else if (playerinput == '2')
	{

	}
  else if (playerinput == '3')
	{
		//calls exit function
		exitwelcome();
	}
   else
    cout<< "Selection Invalid [Back to welcome screen]" <<endl;
    welcome();
}

void tutorial(){

	cout<<"hello!"<<endl; //logic test
}

void exitwelcome(){

	char exitinput;
  cout<< "------------------------------------------" <<endl;
	cout<< "You have exited the game" <<endl;
	cout<< "Enter 'w' to go back to the welcome screen" <<endl;
  cout<< "------------------------------------------" <<endl;

	cin >> exitinput;
	if(exitinput == 'w'){
		welcome();
	}
  else
    cout<< "Selection Invalid [Back to Exit Screen]" <<endl;
    exitwelcome();
}

int main() {
	welcome();
}

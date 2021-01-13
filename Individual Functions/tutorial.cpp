// Program snippet for the tutorial function
// To be shown after the introduction snippet in main()
// Current code snippet is able to repeat the tutorial for as many times as the user needs, a way to check user input, a way to check to repeat the tutorial, and the tutorial itself.

#include <iostream>
#include <string>
//#include <locale> // for tolower in our big program; if we get an error for tolower(), uncomment this line
using namespace std;

// Function Declarations:
void tutorial();
void tutorialprint();

// The tutorial function is the main function, which repeats the calls to tutorialprint()
void tutorial()
{
	char tutorialanswer;
	cout << "Would you like to view the tutorial for Ultimate Tic Tac Toe? (Type \"Y\" for yes and \"N\" for no)\n";
	cin >> tutorialanswer;
	tutorialanswer = tolower(tutorialanswer); // The tolower() function is used in order to catch user input error
	// This while loop is to check user input -- if the user inputs something other than "y" or "n", user is asked to enter their input again
	while (tutorialanswer != 'n' && tutorialanswer != 'y')
	{
		cout << "Please type \"Y\" for yes and \"N\" for no)\n";
		cin >> tutorialanswer;
		tutorialanswer = tolower(tutorialanswer); // The tolower() function is used in order to catch user input error
	}
	// This while loop calls the tutorial itself -- as long as the user continues to respond with yes, the calls to tutorial will repeat
	while (tutorialanswer == 'y')
	{
		//calls the actual tutorial function (tutorialprint())
		tutorialprint();
		cout << "Would you like to view the tutorial for Ultimate Tic Tac Toe again? (Type \"Y\" for yes and \"N\" for no)\n";
		cin >> tutorialanswer;
		tutorialanswer = tolower(tutorialanswer); // The tolower() function is used in order to catch user input error
		// This while loop is to check user input -- if the user inputs something other than "y" or "n", user is asked to enter their input again
		while (tutorialanswer != 'n' && tutorialanswer != 'y')
		{
			cout << "Please type \"Y\" for yes and \"N\" for no)\n";
			cin >> tutorialanswer;
			tutorialanswer = tolower(tutorialanswer); // The tolower() function is used in order to catch user input error
		}
	}
}

// The tutorialprint function prints the tutorial itself -- interactive element is the requirement that the user press RETURN to move onto the next rule
void tutorialprint()
{
	// First Part (1/6)
	cout << "Each small 3 x 3 tic-tac-toe board is referred to as a local board, and the larger 3 x 3 board is \n";
	cout << "referred to as the global board. Local boards are separated by double lines. We have a \n";
	cout << "condensed global board(condensed board), which is printed below the global board. \n";
	cout << "Press RETURN to continue.\n";
	// The program is weird if cin.ignore() is not added, so that is why it is uncommented here
	cin.ignore();
	cin.get();

	// Second Part (2/6)
	cout << "The game starts with X playing wherever they want in any of the 81 empty spots. The global \n";
	cout << "board is labeled with numbers 1 - 81, which players type into the console to make their moves.\n";
	cout << "Press RETURN to continue.\n";
	//cin.ignore();
	cin.get();

	// Third Part (3/6)
	cout << "This move \"sends\" their opponent to its relative location. For example, if X played in the top right \n";
	cout << "square of their local board, then O needs to play their next move in the top right local board. O \n";
	cout << "can then play in any one of the nine available spots in that local board, each move sending X to \n";
	cout << "a different local board.\n";
	cout << "Press RETURN to continue.\n";
	//cin.ignore();
	cin.get();

	// Fourth Part (4/6)
	cout << "If a move is played so that it is to win a local board by the rules of normal tic-tac-toe, then the \n";
	cout << "entire local board is marked as a victory for the player in the condensed board at the bottom.\n";
	cout << "Press RETURN to continue.\n";
	//cin.ignore();
	cin.get();

	// Fifth Part (5/6)
	cout << "Once a local board is won by a player or it is filled completely, no more moves may be played in \n";
	cout << "that board.If a player is sent to such a board, then that player may play on any other board.\n";
	cout << "Press RETURN to continue.\n";
	//cin.ignore();
	cin.get();

	// Sixth Part (6/6)
	cout << "Game play ends when either a player wins the global board or there are no legal moves \n";
	cout << "remaining, in which case the game is a draw.\n";
	cout << "Press RETURN to continue.\n";
	//cin.ignore();
	cin.get();
}

int main() {
	tutorial();
	return 0;
}

// Program snippet for the introduction; to be put in main()
// This is a function by itself solely for organization purposes; we figured to have this entire chunk of text in main() would be painful
// By Kayley S.

#include <iostream>
#include <string>
using namespace std;

// Function Declaration:
void introduction();

//The introduction function is in the main function, and its only purpose is to print out the introduction text
void introduction()
{
	cout << "Have you heard of Tic Tac Toe? Tic Tac Toe is a game where two players, each taking an \"X\" or \n";
	cout << "\"O\", take turns marking spaces in a 3 by 3 grid. The player who succeeds in placing three of \n";
	cout << "their marks in a horizontal, vertical, or diagonal row is declared the winner. It is a solved game \n";
	cout << "with a forced draw assuming best play from both players. Here is how our version of Ultimate \n";
	cout << "Tic Tac Toe differs from the regular thing — instead of needing to win a 3 by 3 grid, Ultimate Tic \n";
	cout << "Tac Toe introduces a new 3 by 3 grid. However, this time, instead of filling in \"X\" and \"O\", the \n";
	cout << "spaces are filled up with a 3 by 3 grid(making it a 9 x 9 grid overall), which the players will need \n";
	cout << "to win before getting their \"X\" or \"O\" on the overarching board.\n";
}


int main() {
	introduction();
	return 0;
}

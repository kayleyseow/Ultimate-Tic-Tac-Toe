// Program snippet for the introduction; to be put in main
// This is a function by itself solely for organization purposes

#include <iostream>
#include <string>
using namespace std;

void introduction();

void introduction()
{
  cout << "Have you heard of Tic Tac Toe? Tic Tac Toe is a game where two players, each taking an \"X\" or \"O\", take turns marking spaces in a 3 by 3 grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is declared the winner. It is a solved game with a forced draw assuming best play from both players. Here's how our version of Ultimate Tic Tac Toe differs from the regular thing — instead of needing to win a 3 by 3 grid, Ultimate Tic Tac Toe introduces a new 3 by 3 grid. However, this time, instead of filling in \"X\" and \"O\", the spaces are filled up with a 3 by 3 grid (making it a 9 x 9 grid overall), which the players will need to win before getting their "X" or "O" on the overarching board.\n";
}


int main() {
	introduction();
}

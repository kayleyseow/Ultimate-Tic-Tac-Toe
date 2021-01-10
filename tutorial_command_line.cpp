// Program snippet for the tutorial
// to be shown after the welcome snippet
//Current code snippet is able to repeat the tutorial for as many times as the user needs. Features to add include the tutorial itself, and a better way to check to repeat the tutorial.

#include <iostream>
#include <string>
//#include <locale> // for locale, tolower in our big program if we get an error for tolower(), uncomment this line
using namespace std;

void tutorial();
void tutorialprint();

void tutorial()
{
	char tutorialanswer;
	cout << "Would you like to view the tutorial for Ultimate Tic Tac Toe? (Type \"Y\" for yes and \"N\" for no)\n";
	cin >> tutorialanswer;
	tutorialanswer = tolower(tutorialanswer);
	while (tutorialanswer == 'y')
	{
		//calls the actual tutorial function -- tutorial print
		tutorialprint();
		cout << "Would you like to view the tutorial for Ultimate Tic Tac Toe again? (Type \"Y\" for yes and \"N\" for no)\n";
		cin >> tutorialanswer;
		tutorialanswer = tolower(tutorialanswer);
	}
}

void tutorialprint()
{
	cout << "logic works, woohoo!\n";
	//will be based off of crystal's current code; currently writing this.
}

int main() {
	tutorial();
}

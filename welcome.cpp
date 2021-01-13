//program for the welcome function

#include <iostream>
#include <string>

#define PLAYERX				98
#define PLAYERO				99

using namespace std;


void tutorial();		// The tutorial function is the main function, handles interactive element.
void tutorialprint();	// The tutorialprint function prints the tutorial, is the static portion.
void printBoard(); 		// the function to draw the game board
void markPosition();	// Put value PLAYERX or PLAYERO to the position in the specified tic tac toe square
bool checkPosition();	//Check the position in the specified tic tac toe square, return false if spot is taken or is grid full. if spot has initial value, true.
bool checkGridFull();	// Check if all the legal spots are taken. Return "false" if there is more legal spots, otherwise return "true"
int checkwin();			// Checks for winner given whichTtt, returns winner if there is one, returns o if there is not.
int checkFinalWin();	// Same as checkwin, except for condensed board instead of whichTtt.
void formatGameRow();	// Format one line of string for the game board print - row; start with 1 (not 0)
void debug_print_steps();// Prints all the moves made. For debugging.
int game();

/*
 * The real game board, which has 9x9 grids.
 * Please note the special index arrangement!!:
 *		[0][0] [0][1] [0][2] | [1][0] [1][1] [1][2] | [2][0] [2][1] [2][2]
 *		[0][3] [0][4] [0][5] | [1][3] [1][4] [1][5] | [2][3] [2][4] [2][5]
 *		[0][6] [0][7] [0][8] | [1][6] [1][7] [1][8] | [2][6] [2][7] [2][8]
 *      ---------------------|----------------------|---------------------
 *		[3][0] [3][1] [0][2] | [4][0] [4][1] [4][2] | [5][0] [5][1] [5][2]
 *		[3][3] [3][4] [0][5] | [4][3] [4][4] [4][5] | [5][3] [5][4] [5][5]
 *		[3][6] [3][7] [0][8] | [4][6] [4][7] [4][8] | [5][6] [5][7] [5][8]
 *      ---------------------|----------------------|---------------------
 *		[6][0] [6][1] [6][2] | [7][0] [7][1] [7][2] | [8][0] [8][1] [8][2]
 *		[6][3] [6][4] [6][5] | [7][3] [7][4] [7][5] | [8][3] [8][4] [8][5]
 *		[6][6] [6][7] [6][8] | [7][6] [7][7] [7][8] | [8][6] [8][7] [8][8]
 *
 */
int  tttGrid[9][9];
/*
 * We will use one dimension array of 9 elements to represent tic tac toe:
 * the array index and tic tac toe board:
 *      [0] | [1] | [2]
 *      ----|-----|----
 *      [3] | [4] | [5]
 *      ----|-----|-----
 *      [6] | [7] | [8]
 */
int  condenseGrid[9];

int gameSteps[81];
int  thisTTTStart[9];



void tutorial()
{
	char tutorialanswer = 'y';
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


void markPosition(char player, int whichTtt, int position)
{
	/* make sure that player correct */
	if ((player != PLAYERX) && (player != PLAYERO))
		return;

	/* make sure that whichTtt and position is in range */
	if ( whichTtt < 0 || whichTtt > 8)
		return;
	if ( position < 0 || position > 8)
		return;

	tttGrid[whichTtt][position] = player;
}


bool checkPosition(int whichTtt, int position, int prevTtt, int prevPosition)
{
	int legal_ttt;

	/* If we already have a winner for this tic tac toe */
	if ((condenseGrid[whichTtt] == PLAYERX) || (condenseGrid[whichTtt] == PLAYERO))
	{
		return false;
	}

	/* If the chosen position is already taken, return false */
	if (tttGrid[whichTtt][position] == PLAYERX || tttGrid[whichTtt][position] == PLAYERO)
		return false;

	/* if this is the very first movement, return true */
	if (prevPosition < 0)
		return true;

	/* Now, based on the previous position to check if it is legal movement */
	legal_ttt = prevPosition;

	/* if the legal 3x3 grid already has winner, then the current postion can be at any 3x3 grid */
	if ( (condenseGrid[legal_ttt] == PLAYERX) || (condenseGrid[legal_ttt] == PLAYERO) )
		return true;
	else  /* current movement must be in the tttGrid[legal_ttt][], otherwise, return false */
	{
		if (whichTtt != legal_ttt)
			return false;
		else
			return true;
	}

	return false; /* doesn't matter what to return, it should never be here */
}


bool checkGridFull()
{
	int whichTtt, i;

	/* skip the tic tac toe squares that already have winner */
	for (whichTtt = 0; whichTtt < 9; whichTtt++)
	{
		if ( (condenseGrid[whichTtt] != PLAYERX) && (condenseGrid[whichTtt] != PLAYERO) )
		{
			for (i = 0; i < 9; i++)
			{
				if (tttGrid[whichTtt][i] == thisTTTStart[whichTtt] + i)
				{
					return false;
				}
			}
		}
	}
	return true;
}


int checkwin(int whichTtt)
{
	/* If we already have a winner for this tic tac toe */
	if ( (condenseGrid[whichTtt] == PLAYERX) || (condenseGrid[whichTtt] == PLAYERO) )
	{
		return 0;
	}

 	/*      [0] | [1] | [2]
 	 *      ----|-----|----
 	 *      [3] | [4] | [5]
     *      ----|-----|-----
 	 *      [6] | [7] | [8]
	 *      brute force all 8 possible win states.
	 */
	if (tttGrid[whichTtt][0] == tttGrid[whichTtt][1] && tttGrid[whichTtt][1] == tttGrid[whichTtt][2])        // row 1
		return tttGrid[whichTtt][0];
	else if (tttGrid[whichTtt][3] == tttGrid[whichTtt][4] && tttGrid[whichTtt][4] == tttGrid[whichTtt][5])   // row 2
		return tttGrid[whichTtt][3];
	else if (tttGrid[whichTtt][6] == tttGrid[whichTtt][7] && tttGrid[whichTtt][7] == tttGrid[whichTtt][8])   // row 3
		return tttGrid[whichTtt][6];
	else if (tttGrid[whichTtt][0] == tttGrid[whichTtt][3] && tttGrid[whichTtt][3] == tttGrid[whichTtt][6])   // col 1
		return tttGrid[whichTtt][0];
	else if (tttGrid[whichTtt][1] == tttGrid[whichTtt][4] && tttGrid[whichTtt][4] == tttGrid[whichTtt][7])   // col 2
		return tttGrid[whichTtt][1];
	else if (tttGrid[whichTtt][2] == tttGrid[whichTtt][5] && tttGrid[whichTtt][5] == tttGrid[whichTtt][8])   // col 3
		return tttGrid[whichTtt][2];
	else if (tttGrid[whichTtt][0] == tttGrid[whichTtt][4] && tttGrid[whichTtt][4] == tttGrid[whichTtt][8])   // diag 1
		return tttGrid[whichTtt][0];
	else if (tttGrid[whichTtt][2] == tttGrid[whichTtt][4] && tttGrid[whichTtt][4] == tttGrid[whichTtt][6])   // diag 2
		return tttGrid[whichTtt][2];
	else
		return 0;
}


int checkFinalWin()
{
 	/*      [0] | [1] | [2]
 	 *      ----|-----|----
 	 *      [3] | [4] | [5]
	 *      ----|-----|-----
 	 *      [6] | [7] | [8]
	 *      brute force all 8 possible win states.
	 */
	if (condenseGrid[0] == condenseGrid[1] && condenseGrid[1] == condenseGrid[2])        // row 1
    	return condenseGrid[0];
    else if (condenseGrid[3] == condenseGrid[4] && condenseGrid[4] == condenseGrid[5])   // row 2
    	return condenseGrid[3];
    else if (condenseGrid[6] == condenseGrid[7] && condenseGrid[7] == condenseGrid[8])   // row 3
    	return condenseGrid[6];
    else if (condenseGrid[0] == condenseGrid[3] && condenseGrid[3] == condenseGrid[6])   // col 1
    	return condenseGrid[0];
    else if (condenseGrid[1] == condenseGrid[4] && condenseGrid[4] == condenseGrid[7])   // col 2
    	return condenseGrid[1];
    else if (condenseGrid[2] == condenseGrid[5] && condenseGrid[5] == condenseGrid[8])   // col 3
    	return condenseGrid[2];
    else if (condenseGrid[0] == condenseGrid[4] && condenseGrid[4] == condenseGrid[8])   // diag 1
    	return condenseGrid[0];
    else if (condenseGrid[2] == condenseGrid[4] && condenseGrid[4] == condenseGrid[6])   // diag 2
    	return condenseGrid[2];
	else
		return 0;

}


void formatGameRow(int row, char buffer[])
{
	int i, j;
	int  gameGrid[9][9];

	/*
     *  tttGrid[][] index in game board:
	 *		[0][0] [0][1] [0][2] | [1][0] [1][1] [1][2] | [2][0] [2][1] [2][2]
	 *		[0][3] [0][4] [0][5] | [1][3] [1][4] [1][5] | [2][3] [2][4] [2][5]
	 *		[0][6] [0][7] [0][8] | [1][6] [1][7] [1][8] | [2][6] [2][7] [2][8]
     *      ---------------------|----------------------|---------------------
	 *		[3][0] [3][1] [0][2] | [4][0] [4][1] [4][2] | [5][0] [5][1] [5][2]
	 *		[3][3] [3][4] [0][5] | [4][3] [4][4] [4][5] | [5][3] [5][4] [5][5]
	 *		[3][6] [3][7] [0][8] | [4][6] [4][7] [4][8] | [5][6] [5][7] [5][8]
     *      ---------------------|----------------------|---------------------
	 *		[6][0] [6][1] [6][2] | [7][0] [7][1] [7][2] | [8][0] [8][1] [8][2]
	 *		[6][3] [6][4] [6][5] | [7][3] [7][4] [7][5] | [8][3] [8][4] [8][5]
	 *		[6][6] [6][7] [6][8] | [7][6] [7][7] [7][8] | [8][6] [8][7] [8][8]
     *
     *  gameGrid[][] index in game board:
	 *		[0][0] [0][1] [0][2] | [0][3] [0][4] [0][5] | [0][6] [0][7] [0][8]
	 *		[1][0] [1][1] [1][2] | [1][3] [1][4] [1][5] | [1][6] [1][7] [1][8]
	 *		[2][0] [2][1] [2][2] | [2][3] [2][4] [2][5] | [2][6] [2][7] [2][8]
     *      ---------------------|----------------------|---------------------
	 *		[3][0] [3][1] [3][2] | [3][3] [3][4] [3][5] | [3][6] [3][7] [3][8]
	 *		[4][0] [4][1] [4][2] | [4][3] [4][4] [4][5] | [4][6] [4][7] [4][8]
	 *		[5][0] [5][1] [5][2] | [5][3] [5][4] [5][5] | [5][6] [5][7] [5][8]
     *      ---------------------|----------------------|---------------------
	 *		[6][0] [6][1] [6][2] | [6][3] [6][4] [6][5] | [6][6] [6][7] [6][8]
	 *		[7][0] [7][1] [7][2] | [7][3] [7][4] [7][5] | [7][6] [7][7] [7][8]
	 *		[8][0] [8][1] [8][2] | [8][3] [8][4] [8][5] | [8][6] [8][7] [8][8]
	 *
   	 * To format a print line, we will use gameGrid[][]. So, first, we will map
     * the tttGrid[][] to gameGrid[][]
     */
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++) // one small 3x3 tic tac toe square
		{
			gameGrid[i][j] = tttGrid[3*(i /3) + (j / 3)][3*(i%3) + (j%3)];
		}
	}

	/* first the the line with default values: each value use two digits */
	sprintf (buffer,   "  %02d  |  %02d  |  %02d  ||  %02d  |  %02d  |  %02d  ||  %02d  |  %02d  |  %02d  \n",
		gameGrid[row-1][0], gameGrid[row-1][1], gameGrid[row-1][2],
		gameGrid[row-1][3], gameGrid[row-1][4], gameGrid[row-1][5],
		gameGrid[row-1][6], gameGrid[row-1][7], gameGrid[row-1][8]);

	/*
     * Then check to see if a spot is belong to PLAYERX or PLAYERO.
     * If do, then replace the two digits by " X" or " O"
     */
	for (i = 0; i < 9; i++)
	{
		if (gameGrid[row-1][i] == PLAYERX)
		{
			buffer[7*i + 2 + i/3] = ' ';
			buffer[7*i + 3 + i/3] = 'X';
		}
		else if (gameGrid[row-1][i] == PLAYERO)
		{
			buffer[7*i + 2 + i/3] = ' ';
			buffer[7*i + 3 + i/3] = 'O';
		}
	}
}


void debug_print_steps()
{
	int i;

	cout << "Game Steps: ";
	for (i = 0; i < 81; i++)
	{
		if (gameSteps[i] < 0)
		{
			cout << endl;
			return;
		}

		cout << gameSteps[i] << ",  ";

		if (i != 0 &&  (i % 10 == 0) )
			cout << endl;
	}

	return;
}


int game()
{
	int  i, j;
	int userSelection, whichTtt, position;
	string Selection;
	int prevSelection,prevTtt, prevPosition;
	char player;
	int  count = 0;
	bool gameOver = false;
	int  winner, tttWinner;
	string playerName[2] = {"Player X", "Player O"};

	/*
	 * initialize tttGrid:
     *
	 * the two dimensions index and game board relationship:
	 *		[0][0] [0][1] [0][2] | [1][0] [1][1] [1][2] | [2][0] [2][1] [2][2]
	 *		[0][3] [0][4] [0][5] | [1][3] [1][4] [1][5] | [2][3] [2][4] [2][5]
	 *		[0][6] [0][7] [0][8] | [1][6] [1][7] [1][8] | [2][6] [2][7] [2][8]
     *      ---------------------|----------------------|---------------------
	 *		[3][0] [3][1] [0][2] | [4][0] [4][1] [4][2] | [5][0] [5][1] [5][2]
	 *		[3][3] [3][4] [0][5] | [4][3] [4][4] [4][5] | [5][3] [5][4] [5][5]
	 *		[3][6] [3][7] [0][8] | [4][6] [4][7] [4][8] | [5][6] [5][7] [5][8]
     *      ---------------------|----------------------|---------------------
	 *		[6][0] [6][1] [6][2] | [7][0] [7][1] [7][2] | [8][0] [8][1] [8][2]
	 *		[6][3] [6][4] [6][5] | [7][3] [7][4] [7][5] | [8][3] [8][4] [8][5]
	 *		[6][6] [6][7] [6][8] | [7][6] [7][7] [7][8] | [8][6] [8][7] [8][8]
     *
     *  The board initialized values:
     *      01  02  03 | 10  11  12 | 19  20  21
     *      04  05  06 | 13  14  15 | 22  23  24
  	 *      07  08  09 | 16  17  18 | 25  26  27
     *     ------------|------------|-----------
     *      28  29  30 | 37  38  39 | 46  47  48
     *      31  32  33 | 40  41  42 | 49  50  51
     *      34  35  36 | 43  44  45 | 52  53  54
     *     ------------|------------|-----------
  	 *      55  56  57 | 64  65  66 | 73  74  75
     *      58  59  60 | 67  68  69 | 76  77  78
     *      61  62  63 | 70  71  72 | 79  80  81
     *
     * thisTTTStart[9] = {1, 10, 19, 28, 37, 46, 55, 64, 73};
	 *
     */
	count = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			count++;
			if (j == 0)
			{
				thisTTTStart[i] = count;
			}
			tttGrid[i][j] = count;
		}
	}

	/*
	 * condenseGrid[] index in board:
 	 *      [0] | [1] | [2]
 	 *      ----|-----|----
 	 *      [3] | [4] | [5]
 	 *      ----|-----|-----
 	 *      [6] | [7] | [8]
 	 */
	for (i = 0; i < 9; i++)
	{
		condenseGrid[i] = i + 1;
	}

	/* gameSteps is for debugging use, let's init it to -1 */
	for (i = 0; i < 81; i++)
	{
		gameSteps[i] = -1;
	}


	/*
	 * Play the game, till either one player wins or all the legal grids are taken
     */
	prevTtt = -1;
	prevPosition = -1;
	prevSelection = -1;
	count = 0;  // the total legal steps, start with 0
	while(gameOver == false)
	{
		printBoard();
		if ((count % 2) == 0)
			player = PLAYERX;
		else
			player = PLAYERO;

		cout << playerName[count % 2] << ", enter a number [last move: " << prevSelection << "]:  ";

		#if 0
		cin >> userSelection;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore ( 100 , '\n' );
            continue;
        }
        if (userSelection < 1 || userSelection > 81)
        {
            continue;
        }
		#else
		cin >> Selection;
		if (Selection == "Q" || Selection == "q")
		{
			exit(0);
		}
		userSelection = atoi(Selection.c_str());
		if (userSelection < 1 || userSelection > 81)
        {
            continue;
        }
		#endif

		whichTtt = (userSelection - 1) / 9;
		position = (userSelection - 1) % 9;

		if (checkPosition(whichTtt, position, prevTtt, prevPosition) == 1)
		{
			markPosition(player, whichTtt, position);
			prevSelection = userSelection;
			gameSteps[count] = userSelection;
			prevTtt = whichTtt;
			prevPosition = position;
			debug_print_steps();
		}
		else
		{
			cout<<"Invalid move [last move: " << prevSelection << "], press RETURN to continue ";
			count--;
			cin.ignore();
			cin.get();
		}
		tttWinner = checkwin(whichTtt);
		count++;

		/* process virtualGrid */
		if (tttWinner != 0)
		{
			condenseGrid[whichTtt] = tttWinner;
			winner = checkFinalWin();
			if (winner != 0)
			{
				gameOver = true;
			}
		}

		/* check grid full */
		if (checkGridFull())
		{
			gameOver = true;
		}
	}

	/*
	 * Draw the final result board, and annouce the result
     */
	printBoard();
	if(winner == PLAYERX)
		cout << "\n==>Congratulations! " << playerName[0] <<" WIN\n\n";
	else if(winner == PLAYERO)
		cout << "\n==>Congratulations! " << playerName[1] <<" WIN\n\n";
	else
		cout << "\n==>Game DRAW. Please play again.\n\n";
	debug_print_steps();
	cin.ignore();
	return 0;
}


void printBoard()
{
	int i;
	char vert[100];
	char horv[100];
	char rows[100];
	cout << "\n\tTic Tac Toe Plus Game\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)\n";
	cout << endl;

	sprintf (vert,   "      |      |      ||      |      |      ||      |      |      \n");
	sprintf (horv,   "______|______|______||______|______|______||______|______|______\n");

	for (i = 0; i < 9; i++)
	{
		cout << vert;
		formatGameRow(i+1, rows); // row start with 1
		cout << rows;
		if ( i < 8 && ((i + 1) % 3) == 0)
			cout << horv;

		if (i < 8)	cout << horv;
		else        cout << vert;
	}

    /* show virtual board result */
	cout << "\n  Virtual board result\n";
	sprintf (vert,   "      |      |      \n");
	sprintf (horv,   "______|______|______\n");

	sprintf (rows,   "      |      |      \n");
	for (i = 0; i < 3; i++)
		if (condenseGrid[i] == PLAYERX)
			rows[7*i + 3] = 'X';
		else if (condenseGrid[i] == PLAYERO)
			rows[7*i + 3] = 'O';
		else
			rows[7*i + 3] = '-';

	cout << vert;
	cout << rows;
	cout << horv;

	sprintf (rows,   "      |      |      \n");
	for (i = 0; i < 3; i++)
		if (condenseGrid[3 + i] == PLAYERX)
			rows[7*i + 3] = 'X';
		else if (condenseGrid[3 + i] == PLAYERO)
			rows[7*i + 3] = 'O';
		else
			rows[7*i + 3] = '-';
	cout << vert;
	cout << rows;
	cout << horv;

	sprintf (rows,   "      |      |      \n");
	for (i = 0; i < 3; i++)
		if (condenseGrid[6 + i] == PLAYERX)
			rows[7*i + 3] = 'X';
		else if (condenseGrid[6 + i] == PLAYERO)
			rows[7*i + 3] = 'O';
		else
			rows[7*i + 3] = '-';
	cout << vert;
	cout << rows;
	cout << vert;
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
			game();
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

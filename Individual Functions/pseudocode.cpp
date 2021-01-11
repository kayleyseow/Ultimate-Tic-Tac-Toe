// Pseudocode for our original planned layout of the Ultimate Tic Tac Toe program

int welcome()
{
    //buttons and stuff.
    //iftutorial， return1
    //if play, return 2
    //if exit, return 3
}


void tutorial ()
{
    //tutorial on how to play
}


winCheck (int board[9])
{
    //for large board
    //returns 0 if nobody won
    //returns 1 if X wins
    //returns 2 if O wins
}


int winCheck(int x)
{
    //for small board
    //returns 0, 1, or 2
    //decode intoX&O
    //put into other wincheck
}


int getPos(int oldb[9], int board[9])
{
    //returns 0-9 depending on the position- 0 if anywhere is okay, 1-9 for box positions.
    //finds the point that was changed last time
    int temp[9];
    temp[0] = board[0]-oldb[0];
    ...
    if (temp == [0,0,0,0,0,0,0,0,0]);
    //do we need a no change?
    //find the position to go to next
    //check if that's taken using winCheck
    {

    }
}

void draw (int board[9])
{
    //draw on the board
}


void winner (int board[])
{
    bool playagain;
    //prints a screen announcing winner, gives option to exit or play again
    if (playagain)
    {
        welcome();
    }
}


int main ()
{
    int oldb[9], board[9];
    int x = welcome();
    if(x == 1) tutorial();
    while(x == 2)
    {
        oldb[0-8] = 0;
        board[0-8] = 0;
        draw(board);
        while(winCheck(board)==0)
        {
            int p = getPos(oldb,board);
            oldb=board;
            board=inputX();
            draw(board);
            if(winCheck(board)==0)
            {
            p = getPos(oldb, board);
            oldb=board;
            board=inputO();
            draw(board);
            }
        }
        winner(board);
    }
    if(x==3) return 1;
}

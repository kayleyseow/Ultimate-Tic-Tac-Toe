void welcome(bool x)
{
    //buttons and stuff.
}


bool getPos(int oldb[9], int board[9])
{
    int temp[] = board[] - oldb[];
    if (temp[] == [0,0,0,0,0,0,0,0,0])
    {

    }
}

void draw (int board[9])
{

}


void winner (int board[])
{
    //prints a screen announcing winner, gives option to exit or play again
    if (playagain)
    {
        welcome(true)
    }
}


int main ()
{
    int oldb[9], board[9];
    welcome(false);
    if(tutorialButton is pressed) tutorial();
    if(newGame)
    {
        oldb = int[0,0,0,0,0,0,0,0,0];
        board = int[0,0,0,0,0,0,0,0,0];
        draw(board);
        while(!winCheck(board))
        {
            getPos(oldboard,board);
            oldboard=board;
            board=inputX();
            draw(board);
            if(!winCheck(board))
            {
            getPos(oldboard, board);
            oldboard=board;
            board=inputO();
            draw(board);
            }
        }
        winner(board);
    }
    if(exit) return 1;
}

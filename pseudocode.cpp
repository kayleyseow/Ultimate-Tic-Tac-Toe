int welcome(bool x)
{
    //if x==true, no tutorial
    //buttons and stuff.
    //iftutorial， return1
    //if play, return 2
    //if exit, return 3
}


void tutorial ()
{
    //tutorial on how to play
}


int getPos(int oldb[9], int board[9])
{
    int temp[9]
    temp[0] = board[0]-oldb[0];
    ...
    if (temp == [0,0,0,0,0,0,0,0,0]);
    {

    }
}

void draw (int board[9])
{
    //shit.
}


wincheck (int board[9])
{
    //returns 0 if nobody won
    //returns 1 if X wins
    //returns 2 if O wins
}


void winner (int board[])
{
    bool playagain;
    //prints a screen announcing winner, gives option to exit or play again
    if (playagain)
    {
        welcome(true);
    }
}


int main ()
{
    int oldb[9], board[9];
    int x = welcome(false);
    if(x == 1) tutorial();
    while(x == 2)
    {
        oldb[0-8] = 0;
        board[0-8] = 0;
        draw(board);
        while(winCheck(board)==0)
        {
            int p = getPos(oldboard,board);
            oldboard=board;
            board=inputX();
            draw(board);
            if(winCheck(board)==0)
            {
            getPos(oldboard, board);
            oldboard=board;
            board=inputO();
            draw(board);
            }
        }
        winner(board);
    }
    if(x==3) return 1;
}

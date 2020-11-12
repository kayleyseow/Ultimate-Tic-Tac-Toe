int main ()
{
    board, oldboard = int[9];
    print welcome;
    if(tutorialButton is pressed) tutorial();
    if(newGame)
    {
        board=[0,0,0,0,0,0,0,0,0];
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
bool getPos(int[]old, int[]new)
{
    temp
}

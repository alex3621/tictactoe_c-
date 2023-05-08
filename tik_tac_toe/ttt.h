#ifndef TTT_H
#define TTT_H
#include <iostream>

class Board
{
    int board[9];
    int winner;

public:
    Board();
    void resetBoard();
    void printBoard() const;
    int checkWinner(int player);
    void selectPosition(int player);
    void gameloop();
    void printWinner() const;
};

void startMessage();
// reset everything
void resetStats(int &winner, bool &playagain);
// while loop

// ask to play again
void playAgain(bool &playagain);

// print a separator
void printDottedLine();

#endif
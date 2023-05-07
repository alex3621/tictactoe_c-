#include <iostream>
#include "ttt.h"

int main()
{
    bool playAgainStatus;
    Board test;

    // game start message
    startMessage();
    do
    {
        test.resetBoard();
        // while loop
        test.gameloop();
        // ask to play again
        playAgain(playAgainStatus);
    } while (playAgainStatus);

    // game end message
}
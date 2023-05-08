#include <iostream>
#include "ttt.h"

// resets the board into empty state
Board::Board()
{
    resetBoard();
    winner = 0;
}

void Board::resetBoard()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = 0;
    }
}

void Board::printBoard() const
{
    for (int i = 1; i < 10; i++)
    {
        if (board[i - 1] == 0)
        {
            std::cout << "- ";
        }
        else if (board[i - 1] == 1)
        {
            std::cout << "O ";
        }
        else
        {
            std::cout << "X ";
        }
        if (i % 3 == 0)
        {
            std::cout << std::endl;
        }
    }
}

void startMessage()
{
    std::cout << "Welcome to Tic Tac Toe!" << std::endl;
    std::cout << "Positions:\n1 2 3\n4 5 6\n7 8 9" << std::endl;
}
// reset everything
void resetStats(int &winner, bool &playagain)
{
    winner = 0;
    playagain = false;
}
// while loop
void Board::gameloop()
{
    resetBoard();
    do
    {
        printDottedLine();
        printBoard();
        printDottedLine();
        selectPosition(1);
        printDottedLine();
        printBoard();
        printDottedLine();
        this->winner = checkWinner(1);
        if (winner)
        {
            printDottedLine();
            printWinner();
            printDottedLine();
        }
        else
        {
            printDottedLine();
            selectPosition(2);
            printDottedLine();
            this->winner = checkWinner(2);
            if (winner)
            {
                printDottedLine();
                printBoard();
                printDottedLine();
                printWinner();
                printDottedLine();
            }
        }
    } while (winner == 0);
}
// print winner
void Board::printWinner() const
{
    std::cout << std::endl;
    std::cout << "The winner is: player" << winner << std::endl
              << std::endl;
}

int Board::checkWinner(int player)
{
    int winner = 0;
    int increment = 1;
    for (int x = 0; x < 3; x++)
    {
        increment = 1;
        if (board[x] == player && board[x + increment] == player && board[x + (2 * increment)] == player)
        {
            winner = player;
            break;
        }
        increment = 3;
        if (board[x] == player && board[x + increment] == player && board[x + (2 * increment)] == player)
        {
            winner = player;
            break;
        }
    }
    if (!winner)
    {
        if (board[0] == player && board[4] == player && board[8] == player)
        {
            winner = player;
        }
        else if (board[2] == player && board[4] == player && board[6] == player)
        {
            winner = player;
        }
        else
        {
            ;
        }
    }
    return winner;
}
void Board::selectPosition(int player)
{
    int selection;
    bool pass = false;
    std::cout << "Player " << player << std::endl;
    std::cout << "Please enter your desired position: ";
    do
    {
        std::cin >> selection;
        if (board[selection - 1] == 0 && selection <= 9 && selection >= 1)
        {
            board[selection - 1] = player;
            pass = true;
        }
        else
        {
            std::cout << "Not a valid selection. Try Again: ";
        }
    } while (!pass);
}

// ask to play again
void playAgain(bool &playagain)
{
    int yesno;
    std::cout << "Do you wish to play again? Enter 0 for no and 1 for yes: ";
    std::cin >> yesno;
    do
    {
        if (yesno == 1)
        {
            playagain = 1;
        }
        else if (yesno == 0)
        {
            playagain = 0;
        }
        else
        {
            std::cout << "Not valid selection. Please try again: ";
        }
    } while (yesno != 1 && yesno != 0);
}

void printDottedLine()
{
    std::cout << "-----------------------------" << std::endl;
}
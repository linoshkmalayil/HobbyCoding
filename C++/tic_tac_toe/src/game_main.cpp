/*==============================================================================
FILE NAME: game_main.cpp
AUTHOR: LINOSH KURIAN MALAYIL
CREATED: 12 November 2023 07∶11∶55 PM
CONTAINS:
main function
==============================================================================*/

/*------------------------------------------------------------------------------
                            START: Includes
------------------------------------------------------------------------------*/
#include <iostream>
#include "ttt_logic/ttt_game.h"
/*------------------------------------------------------------------------------
                            END: Includes
------------------------------------------------------------------------------*/

/*******************************************************************************
                                START: main()
*******************************************************************************/
int main()
{
    std:: cout << "Hello World" << std::endl;

    char choice = 0;
    do
    {
        MARKS player_mark;

        char mark_choice  = 0;
        do
        {   // Repeat until X or O is received
            std::cout << "X or O?: ";
            std::cin >> mark_choice;
        } while(('X' != mark_choice) && ('x' != mark_choice) &&
                ('O' != mark_choice) && ('o' != mark_choice));

        switch (mark_choice)
        {   //Translate character to enum class entites
            case 'X' :
            case 'x' : player_mark = MARKS::X;
                       break;
            case 'O' :
            case 'o' : player_mark = MARKS::O;
                       break;
            default  : std::cout << "Shouldn't have reached here\n";
                       exit(127);
                       break;
        }

        TicTacToeGame Game = TicTacToeGame(player_mark);
        switch(Game.play_game())
        {   //Check game result
            case RESULT::WIN  : std::cout << "Player Won!\n";
                                break;
            case RESULT::LOSS : std::cout << "Player Lost!\n";
                                break;
            case RESULT::TIE  : std::cout << "Game Tie\n";
                                break;

            default           : std::cout << "Shouldn't have reached here\n";
                                exit(127);
                                break;
        }

        std::cout << "Play again?(Y/N): ";
        std::cin >> choice;

    } while(('Y' == choice) || ('y' == choice));
    // Runs as long as choice is 'Y'

    return 0;
}
/*******************************************************************************
                                END: main()
*******************************************************************************/

/*==============================================================================
                        END OF FILE game_main.cpp
==============================================================================*/
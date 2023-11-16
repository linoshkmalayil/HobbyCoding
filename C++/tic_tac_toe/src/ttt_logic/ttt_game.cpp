/*==============================================================================
FILE NAME: ttt_game.cpp
AUTHOR: LINOSH KURIAN MALAYIL
CREATED: 13 November 2023 07∶38∶20 PM
CONTAINS:
Definitions of the classes in ttt_game.h

NOTE: While accessing an std::array of std::array (2-D array), the index
      iteration works by accessing 'Column' first then 'Row'
==============================================================================*/

/*------------------------------------------------------------------------------
                            START: Includes
------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "../board_renderer/render_board.h"
#include "ttt_game.h"
/*------------------------------------------------------------------------------
                            END: Includes
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                            START: Defines
------------------------------------------------------------------------------*/
#define MIN_MOVES 3
#define MAX_MOVES 9
/*------------------------------------------------------------------------------
                              END: Defines
------------------------------------------------------------------------------*/

/*******************************************************************************
                    START: TicTacToeGame Constructor
*******************************************************************************/
TicTacToeGame::TicTacToeGame(MARKS const &p_mark):player_mark(p_mark)
{   /* Constructor to initialize the TicTacToeGame object.
       The constructor needs the player's marker to initialize
       the object. */

    // Starting seed for RNG
    srand((unsigned) time(NULL));

    // Start of game, total moves is 0
    total_moves = 0;

    // Setting player and opponent marks
    if(player_mark == MARKS::X)
    {
        opponent_mark = MARKS::O;
    }
    else
    {
        opponent_mark = MARKS::X;
    }

    // Setting the board as empty with N mark
    for(int i = 0; i < MAX_MARKS; i++)
    {
        game_board[i%DIMMENSIONS][i/DIMMENSIONS] = MARKS::N;
    }
}
/*******************************************************************************
                        END: TicTacToeGame Constructor
*******************************************************************************/

/*******************************************************************************
                    START: TicTacToeGame check_cell_empty()
*******************************************************************************/
bool TicTacToeGame::check_cell_empty(short const &row, short const &col)
{   /* Check if a cell is empty by seeing if it is N Mark */

    if(MARKS::N == game_board.at(col).at(row))
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*******************************************************************************
                    END: TicTacToeGame check_cell_empty()
*******************************************************************************/

/*******************************************************************************
                    START: TicTacToeGame player_move()
*******************************************************************************/
void TicTacToeGame::player_move()
{   /* Function to ask and perform player move */
    
    short row = -1, col = -1;
    
    while((row < 1) || (row > 3))
    {   // Invalid row
        std::cout << "Row: "; 
        std::cin >> row;
    }

    while((col < 1) || (col > 3))
    {   // Invalid column
        std::cout << "Column: ";
        std::cin >> col;
    }

    if(true == check_cell_empty(row - 1, col - 1))
    {   // Fill encase the cell is empty
        game_board[col-1][row-1] = player_mark;
    }
    else
    {   // Else redo the player input
        std::cout << "Position already filled!\n";
        player_move();
    }

    return;
}
/*******************************************************************************
                    START: TicTacToeGame player_move()
*******************************************************************************/

/*******************************************************************************
                    START: TicTacToeGame run_counter_player()
*******************************************************************************/
bool TicTacToeGame::run_counter_player()
{   /* Function to counter a player completion in case there is a chance
       that a player will make a completion or win 
       Returns true if a counter is found*/

    // ROW-1 Counter player Start
    if((game_board.at(0).at(0) == game_board.at(1).at(0)) && 
       (game_board.at(0).at(0) == player_mark) && 
       (true == check_cell_empty(0, 2)))
    {
        game_board[2][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(0) == game_board.at(2).at(0)) &&
            (game_board.at(1).at(0) == player_mark) && 
            (true == check_cell_empty(0, 0)))
    {
        game_board[0][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(0) == game_board.at(2).at(0)) &&
            (game_board.at(0).at(0) == player_mark) && 
            (true == check_cell_empty(0, 1)))
    {
        game_board[1][0] = opponent_mark;

        return true;
    }
    // ROW-1 Counter Player End

    // ROW-2 Counter Player Start
    else if((game_board.at(0).at(1) == game_board.at(1).at(1)) &&
            (game_board.at(0).at(1) == player_mark) && 
            (true == check_cell_empty(2, 2)))
    {
        game_board[2][1] = opponent_mark;
    }
    else if((game_board.at(1).at(1) == game_board.at(2).at(1)) &&
            (game_board.at(1).at(1) == player_mark) && 
            (true == check_cell_empty(1, 0)))
    {
        game_board[0][1] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(1) == game_board.at(2).at(1)) &&
            (game_board.at(0).at(1) == player_mark) && 
            (true == check_cell_empty(1, 1)))
    {
        game_board[1][1] = opponent_mark;

        return true;
    }
    // ROW-2 Counter Player End

    // ROW-3 Counter Player Start
    else if((game_board.at(0).at(2) == game_board.at(1).at(2)) &&
            (game_board.at(0).at(2) == player_mark) && 
            (true == check_cell_empty(2, 2)))
    {
        game_board[2][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(2) == game_board.at(2).at(2)) &&
            (game_board.at(1).at(2) == player_mark) && 
            (true == check_cell_empty(2, 0)))
    {
        game_board[0][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(2) == game_board.at(2).at(2)) &&
            (game_board.at(0).at(2) == player_mark) && 
            (true == check_cell_empty(2, 1)))
    {
        game_board[1][2] = opponent_mark;

        return true;
    }
    // ROW-3 Counter Player End

    // COLUMN-1 Counter Player Start
    else if((game_board.at(0).at(0) == game_board.at(0).at(1)) &&
            (game_board.at(0).at(0) == player_mark) && 
            (true == check_cell_empty(2, 0)))
    {
        game_board[0][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(1) == game_board.at(0).at(2)) &&
            (game_board.at(0).at(1) == player_mark) && 
            (true == check_cell_empty(0, 0)))
    {
        game_board[0][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(0) == game_board.at(0).at(2)) &&
            (game_board.at(0).at(0) == player_mark) && 
            (true == check_cell_empty(1, 0)))
    {
        game_board[0][1] = opponent_mark;

        return true;
    }
    // COLUMN-1 Counter Player End
    
    // COLUMN-2 Counter Player Start
    else if((game_board.at(1).at(0) == game_board.at(1).at(1)) &&
            (game_board.at(1).at(0) == player_mark) && 
            (true == check_cell_empty(2, 1)))
    {
        game_board[1][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(1) == game_board.at(1).at(2)) &&
            (game_board.at(1).at(1) == player_mark) &&
            (true == check_cell_empty(0, 1)))
    {
        game_board[1][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(0) == game_board.at(1).at(2)) &&
            (game_board.at(1).at(0) == player_mark) && 
            (true == check_cell_empty(1, 1)))
    {
        game_board[1][1] = opponent_mark;

        return true;
    }
    // COLUMN-2 Counter Player End

    // COLUMN-3 Counter Player Start
    else if((game_board.at(2).at(0) == game_board.at(2).at(1)) &&
            (game_board.at(2).at(0) == player_mark) && 
            (true == check_cell_empty(2, 2)))
    {
        game_board[2][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(2).at(1) == game_board.at(2).at(2)) &&
            (game_board.at(2).at(1) == player_mark) && 
            (true == check_cell_empty(0, 2)))
    {
        game_board[2][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(2).at(0) == game_board.at(2).at(2)) &&
            (game_board.at(2).at(0) == player_mark) && 
            (true == check_cell_empty(1, 2)))
    {
        game_board[2][1] = opponent_mark;

        return true;
    }
    // COLUMN-3 Counter Player End

    // DIAGONAL-1 Counter Player Start
    else if((game_board.at(0).at(0) == game_board.at(1).at(1)) &&
            (game_board.at(0).at(0) == player_mark) && 
            (true == check_cell_empty(2, 2)))
    {
        game_board[2][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(1) == game_board.at(2).at(2)) &&
            (game_board.at(1).at(1) == player_mark) && 
            (true == check_cell_empty(0, 0)))
    {
        game_board[0][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(0) == game_board.at(2).at(2)) &&
            (game_board.at(0).at(0) == player_mark) && 
            (true == check_cell_empty(1, 1)))
    {
        game_board[1][1] = opponent_mark;

        return true;
    }
    // DIAGONAL-1 Counter Player End

    // DIAGONAL-2 Counter Player Start
    else if((game_board.at(2).at(0) == game_board.at(1).at(1)) &&
            (game_board.at(2).at(0) == player_mark) && 
            (true == check_cell_empty(1, 0)))
    {
        game_board[0][1] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(1) == game_board.at(0).at(2)) &&
            (game_board.at(1).at(1) == player_mark) && 
            (true == check_cell_empty(0, 2)))
    {
        game_board[2][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(2).at(0) == game_board.at(0).at(2)) &&
            (game_board.at(2).at(0) == player_mark) && 
            (true == check_cell_empty(1, 1)))
    {
        game_board[1][1] = opponent_mark;

        return true;
    }
    // DIAGONAL-2 Counter Player End

    return false;
}
/*******************************************************************************
                    END: TicTacToeGame run_counter_player()
*******************************************************************************/

/*******************************************************************************
                START: TicTacToeGame run_opponent_sequence_fill()
*******************************************************************************/
bool TicTacToeGame::run_opponent_sequence_fill()
{   /* Function that predicts in case a completion is possible by opponent,
       then fills the cell to complete.
       Returns true if a completion is done */

    // ROW-1 Check Start
    if((game_board.at(0).at(0) == game_board.at(0).at(1)) && 
       (game_board.at(0).at(0) == opponent_mark) && 
       (true == check_cell_empty(2, 0)))
    {
        game_board[0][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(1) == game_board.at(0).at(2)) &&
            (game_board.at(0).at(1) == opponent_mark) && 
            (true == check_cell_empty(0, 0)))
    {
        game_board[0][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(0) == game_board.at(0).at(2)) &&
            (game_board.at(0).at(0) == opponent_mark) && 
            (true == check_cell_empty(1, 0)))
    {
        game_board[0][1] = opponent_mark;

        return true;
    }
    // ROW-1 Check End

    // ROW-2 Check Start
    else if((game_board.at(1).at(0) == game_board.at(1).at(1)) &&
            (game_board.at(1).at(0) == opponent_mark) && 
            (true == check_cell_empty(2, 1)))
    {
        game_board[1][2] = opponent_mark;
    }
    else if((game_board.at(1).at(1) == game_board.at(1).at(2)) &&
            (game_board.at(1).at(1) == opponent_mark) && 
            (true == check_cell_empty(0, 1)))
    {
        game_board[1][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(0) == game_board.at(1).at(2)) &&
            (game_board.at(1).at(0) == opponent_mark) && 
            (true == check_cell_empty(1, 1)))
    {
        game_board[1][1] = opponent_mark;

        return true;
    }
    // ROW-2 Check End

    // ROW-3 Check Start
    else if((game_board.at(2).at(0) == game_board.at(2).at(1)) &&
            (game_board.at(2).at(0) == opponent_mark) && 
            (true == check_cell_empty(2, 2)))
    {
        game_board[2][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(1) == game_board.at(2).at(2)) &&
            (game_board.at(1).at(1) == opponent_mark) && 
            (true == check_cell_empty(0, 2)))
    {
        game_board[2][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(0) == game_board.at(2).at(2)) &&
            (game_board.at(1).at(0) == opponent_mark) && 
            (true == check_cell_empty(1, 0)))
    {
        game_board[0][1] = opponent_mark;

        return true;
    }
    // ROW-3 Check End

    // COLUMN-1 Check Start
    else if((game_board.at(0).at(0) == game_board.at(1).at(0)) &&
            (game_board.at(0).at(0) == opponent_mark) && 
            (true == check_cell_empty(0, 2)))
    {
        game_board[2][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(0) == game_board.at(2).at(0)) &&
            (game_board.at(1).at(0) == opponent_mark) && 
            (true == check_cell_empty(0, 0)))
    {
        game_board[0][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(0) == game_board.at(2).at(0)) &&
            (game_board.at(0).at(0) == opponent_mark) && 
            (true == check_cell_empty(0, 1)))
    {
        game_board[1][0] = opponent_mark;

        return true;
    }
    // COLUMN-1 Check End
    
    // COLUMN-2 Check Start
    else if((game_board.at(0).at(1) == game_board.at(1).at(1)) &&
            (game_board.at(0).at(1) == opponent_mark) && 
            (true == check_cell_empty(1, 2)))
    {
        game_board[2][1] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(1) == game_board.at(2).at(1)) &&
            (game_board.at(1).at(1) == opponent_mark) &&
            (true == check_cell_empty(1, 0)))
    {
        game_board[0][1] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(1) == game_board.at(2).at(1)) &&
            (game_board.at(0).at(1) == opponent_mark) && 
            (true == check_cell_empty(1, 1)))
    {
        game_board[1][1] = opponent_mark;

        return true;
    }
    // COLUMN-2 Check End

    // COLUMN-3 Check Start
    else if((game_board.at(0).at(2) == game_board.at(1).at(2)) &&
            (game_board.at(0).at(2) == opponent_mark) && 
            (true == check_cell_empty(2, 2)))
    {
        game_board[2][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(2) == game_board.at(2).at(2)) &&
            (game_board.at(1).at(2) == opponent_mark) && 
            (true == check_cell_empty(2, 0)))
    {
        game_board[0][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(2) == game_board.at(2).at(2)) &&
            (game_board.at(0).at(2) == opponent_mark) && 
            (true == check_cell_empty(2, 1)))
    {
        game_board[1][2] = opponent_mark;

        return true;
    }
    // COLUMN-3 Check End

    // DIAGONAL-1 Check Start
    else if((game_board.at(0).at(0) == game_board.at(1).at(1)) &&
            (game_board.at(0).at(0) == opponent_mark) && 
            (true == check_cell_empty(2, 2)))
    {
        game_board[2][2] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(1) == game_board.at(2).at(2)) &&
            (game_board.at(1).at(1) == opponent_mark) && 
            (true == check_cell_empty(0, 0)))
    {
        game_board[0][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(0).at(0) == game_board.at(2).at(2)) &&
            (game_board.at(0).at(0) == opponent_mark) && 
            (true == check_cell_empty(1, 1)))
    {
        game_board[1][1] = opponent_mark;

        return true;
    }
    // DIAGONAL-1 Check End

    // DIAGONAL-2 Check Start
    else if((game_board.at(2).at(0) == game_board.at(1).at(1)) &&
            (game_board.at(2).at(0) == opponent_mark) && 
            (true == check_cell_empty(1, 0)))
    {
        game_board[0][1] = opponent_mark;

        return true;
    }
    else if((game_board.at(1).at(1) == game_board.at(0).at(2)) &&
            (game_board.at(1).at(1) == opponent_mark) && 
            (true == check_cell_empty(0, 2)))
    {
        game_board[2][0] = opponent_mark;

        return true;
    }
    else if((game_board.at(2).at(0) == game_board.at(0).at(2)) &&
            (game_board.at(2).at(0) == opponent_mark) && 
            (true == check_cell_empty(1, 1)))
    {
        game_board[1][1] = opponent_mark;

        return true;
    }
    // DIAGONAL-2 Check End

    return false;
}
/*******************************************************************************
                END: TicTacToeGame run_opponent_sequence_fill()
*******************************************************************************/

/*******************************************************************************
                    START: TicTacToeGame opponent_move()
*******************************************************************************/
void TicTacToeGame::opponent_move()
{   /* Function to perform opponent move
       First the opponent checks if it possible to counter the player,
       then tries to fill to complete sequence.
       If not, try to fill a cell randomly */

    if(true == run_opponent_sequence_fill())
    {   // Trying to fill the sequence for opponent
        ;
    }
    else if(true == run_counter_player())
    {   // Trying to counter the player
        ;
    }
    else if(total_moves < MAX_MARKS)
    {   // Or else fill a position randomly
        unsigned char row = rand() % 3;
        unsigned char col = rand() % 3;

        while(false == check_cell_empty(row, col))
        {   // In case the cell is already filled
            row = rand() % 3;
            col = rand() % 3;
            
        }

        game_board[col][row] = opponent_mark;
    }

    return;
}
/*******************************************************************************
                    END: TicTacToeGame opponent_move()
*******************************************************************************/

/*******************************************************************************
                    START: TicTacToeGame check_sequence()
*******************************************************************************/
SEQUENCE TicTacToeGame::check_sequence(MARKS const &player)
{   /* Check which row, column or diagonal has a completion with a mark 
       Returns the completion sequence if found, else returns NONE */

    if((game_board.at(0).at(0) == game_board.at(1).at(0)) && 
       (game_board.at(1).at(0) == game_board.at(2).at(0)) &&
       (game_board.at(0).at(0) == player))
    {
        return SEQUENCE::ROW1;
    }
    else if((game_board.at(0).at(1) == game_board.at(1).at(1)) && 
            (game_board.at(1).at(1) == game_board.at(2).at(1)) &&
            (game_board.at(0).at(1) == player))
    {
        return SEQUENCE::ROW2;
    }
    else if((game_board.at(0).at(2) == game_board.at(1).at(2)) && 
            (game_board.at(1).at(2) == game_board.at(2).at(2)) &&
            (game_board.at(0).at(2) == player))
    {
        return SEQUENCE::ROW3;
    }
    else if((game_board.at(0).at(0) == game_board.at(0).at(1)) && 
            (game_board.at(0).at(1) == game_board.at(0).at(2)) &&
            (game_board.at(0).at(0) == player))
    {
        return SEQUENCE::COLUMN1;
    }
    else if((game_board.at(1).at(0) == game_board.at(1).at(1)) && 
            (game_board.at(1).at(1) == game_board.at(1).at(2)) &&
            (game_board.at(1).at(0) == player))
    {
        return SEQUENCE::COLUMN2;
    }
    else if((game_board.at(2).at(0) == game_board.at(2).at(1)) && 
            (game_board.at(2).at(1) == game_board.at(2).at(2)) &&
            (game_board.at(2).at(0) == player))
    {
        return SEQUENCE::COLUMN3;
    }
    else if((game_board.at(0).at(0) == game_board.at(1).at(1)) && 
            (game_board.at(1).at(1) == game_board.at(2).at(2)) &&
            (game_board.at(0).at(0) == player))
    {
        return SEQUENCE::DIAGONAL1;
    }
    else if((game_board.at(0).at(2) == game_board.at(1).at(1)) && 
            (game_board.at(1).at(1) == game_board.at(2).at(0)) &&
            (game_board.at(0).at(2) == player))
    {
        return SEQUENCE::DIAGONAL2;
    }
    else
    {
        return SEQUENCE::NONE;
    }
}
/*******************************************************************************
                    END: TicTacToeGame check_sequence()
*******************************************************************************/

/*******************************************************************************
                START: TicTacToeGame display_winning_sequence()
*******************************************************************************/
void TicTacToeGame::display_winning_sequence(SEQUENCE const &winning_sequence)
{   /* Switch through the sequence data and 
       display which sequence resulted in the win */

    switch(winning_sequence)
    {
        case SEQUENCE::ROW1      : std::cout << "Row-1 Completion\n";
                                   break;
        case SEQUENCE::ROW2      : std::cout << "Row-2 Completion\n";
                                   break;
        case SEQUENCE::ROW3      : std::cout << "Row-3 Completion\n";
                                   break;
        case SEQUENCE::COLUMN1   : std::cout << "Column-1 Completion\n";
                                   break;
        case SEQUENCE::COLUMN2   : std::cout << "Column-2 Completion\n";
                                   break;
        case SEQUENCE::COLUMN3   : std::cout << "Column-3 Completion\n";
                                   break;
        case SEQUENCE::DIAGONAL1 : std::cout << "Diagonal-1 Completion\n";
                                   break;
        case SEQUENCE::DIAGONAL2 : std::cout << "Diagonal-2 Completion\n";
                                   break;
        default                  : std::cout << "Shouldn't have reached here\n";
                                   exit(127);
                                   break;
    }

}
/*******************************************************************************
                END: TicTacToeGame display_winning_sequence()
*******************************************************************************/

/*******************************************************************************
                START: TicTacToeGame get_game_render_data()
*******************************************************************************/
std::array<MARKS,MAX_MARKS> TicTacToeGame::get_game_render_data()
{   /* Function to generate data for rendering the board
       Returns a 1-D array with marks in the board in sequence */

    std::array<MARKS, MAX_MARKS> game_data_sequence;
    for(int i = 0; i < MAX_MARKS; i++)
    {
        game_data_sequence[i] = game_board.at(i%DIMMENSIONS).at(i/DIMMENSIONS);
    }

    return game_data_sequence;
}
/*******************************************************************************
                END: TicTacToeGame get_game_render_data()
*******************************************************************************/

/*******************************************************************************
                START: TicTacToeGame display_tictactoe_board()
*******************************************************************************/
void TicTacToeGame::display_tictactoe_board()
{   /* Function to complete the Tic-Tac-Toe board 
       The function generates a 1-D sequence of game data,
       then pass it to the renderer object and then
       the renderer object will generate a character sequence
       then render the board with the character sequence */

    std::array<MARKS,MAX_MARKS> seq_data = get_game_render_data();
    BoardRenderer renderer;
    std::array<char, MAX_MARKS> render_data 
                                = renderer.generate_char_marks(seq_data);
    renderer.render_board(render_data);

    return;
}
/*******************************************************************************
                END: TicTacToeGame display_tictactoe_board()
*******************************************************************************/

/*******************************************************************************
                    START: TicTacToeGame play_game()
*******************************************************************************/
RESULT TicTacToeGame::play_game()
{   /* Function to run the game mechanics
       Once the game is over, the function returns the result of game */

    while (total_moves < MAX_MARKS)
    {   //Run the game for max 9 moves

        //Increment moves for both player and opponent
        total_moves += 2;

        player_move();
        
        SEQUENCE result = check_sequence(player_mark);
        if(SEQUENCE::NONE != result)
        {   //In case the player won
            display_tictactoe_board();
            display_winning_sequence(result);
            
            return RESULT::WIN;
        }

        opponent_move();

        display_tictactoe_board();

        result = check_sequence(opponent_mark);
        if(SEQUENCE::NONE != result)
        {   // In case player lost
            display_winning_sequence(result);
            return RESULT::LOSS;
        }
    }
    
    //If the game finished without any wins, return a tie
    return RESULT::TIE;
}
/*******************************************************************************
                    END: TicTacToeGame play_game()
*******************************************************************************/

/*==============================================================================
                        END OF FILE ttt_game.cpp
==============================================================================*/

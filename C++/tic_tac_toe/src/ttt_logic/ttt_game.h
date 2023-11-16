/*==============================================================================
FILE NAME: ttt_game.h
AUTHOR: LINOSH KURIAN MALAYIL
CREATED: 13 November 2023 07∶36∶23 PM
CONTAINS:
Class prototype for Tic-Tac-Toe Game
==============================================================================*/
#ifndef TTT_GAME_H
#define TTT_GAME_H

/*------------------------------------------------------------------------------
                            START: Includes
------------------------------------------------------------------------------*/
#include <array>
#include "../states/states.h"
/*------------------------------------------------------------------------------
                            END: Includes
------------------------------------------------------------------------------*/

/*******************************************************************************
                        START: TicTacToeGame Class
*******************************************************************************/
class TicTacToeGame
{
        unsigned char total_moves;
        MARKS player_mark, opponent_mark;
        std::array<std::array<MARKS,DIMMENSIONS>,DIMMENSIONS> game_board;

        bool check_cell_empty(short const &, short const &);
        void player_move();
        bool run_counter_player();
        bool run_opponent_sequence_fill();
        void opponent_move();
        SEQUENCE check_sequence(MARKS const &player);
        void display_winning_sequence(SEQUENCE const &);
        std::array<MARKS,MAX_MARKS> get_game_render_data();
        void display_tictactoe_board();
    public:
        TicTacToeGame(MARKS const &);
        RESULT play_game();
};
/*******************************************************************************
                        END: TicTacToeGame Class
*******************************************************************************/

#endif
/*==============================================================================
                        END OF FILE ttt_game.h
==============================================================================*/

/*==============================================================================
FILE NAME: render_board.cpp
AUTHOR: LINOSH KURIAN MALAYIL
CREATED: 13 November 2023 07∶23∶03 PM
CONTAINS:
Class defintions for the Board Renderer Functions
==============================================================================*/

/*------------------------------------------------------------------------------
                            START: Includes
------------------------------------------------------------------------------*/
#include <iostream>
#include "render_board.h"
/*------------------------------------------------------------------------------
                            END: Includes
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
                            START: Defines
------------------------------------------------------------------------------*/
#define RENDER_ROW 5
#define RENDER_COL 5
#define RENDER_SIZE RENDER_ROW * RENDER_COL
#define ROW_DELIMIT 5
#define MARKPLACER_DIVIDE 2
/*------------------------------------------------------------------------------
                              END: Defines
------------------------------------------------------------------------------*/

/*******************************************************************************
                    START: BoardRenderer generate_char_marks()
*******************************************************************************/
std::array<char,MAX_MARKS> BoardRenderer::generate_char_marks
    (std::array<MARKS,MAX_MARKS> const &game_marks)
{   /* Function that generates a 1-D array of X,O characters for 
       display rendering to render 
       Returns an array filled with moves made in character form*/

    std::array<char,MAX_MARKS> render_marks;
    for(int i = 0; i< MAX_MARKS; i++)
    {
        switch(game_marks.at(i))
        {
            case MARKS::N : render_marks[i] = ' ';
                            break;
            case MARKS::X : render_marks[i] = 'X';
                            break;
            case MARKS::O : render_marks[i] = 'O';
                            break;
            default       : std::cout << "Shouldn't have reached here\n";
                            exit(127);
                            break; 
        }
    }

    return render_marks;
}
/*******************************************************************************
                    END: BoardRenderer generate_char_marks()
*******************************************************************************/

/*******************************************************************************
                    START: BoardRenderer render_board()
*******************************************************************************/
void BoardRenderer::render_board(std::array<char,MAX_MARKS> const &render_marks)
{   /* Function that displays the Tic-Tac-Toe board
       The function accepts the character array of moves and 
       writes them to STDIN */

    unsigned char marks_counter = 0;
    for(int i = 0; i < RENDER_SIZE; i++)
    {
        if ((i % ROW_DELIMIT) == 0)
        {
            std::cout << "\n";
        }
        if(((i >= ROW_DELIMIT) && (i <= (2*ROW_DELIMIT) - 1)) || 
           ((i >= 3 * ROW_DELIMIT) && (i <= (4*ROW_DELIMIT) - 1)))
        {   // Horizontal divide between rows
            std::cout << "-";
        }
        else if((i % MARKPLACER_DIVIDE) == 0)
        {   // Write the marks to STDIN
            std::cout << render_marks.at(marks_counter++);
        }
        else
        {   // Vertical divide between marks
            std::cout << "|";
        }
    }
    std::cout << std::endl;

    return;
}
/*******************************************************************************
                    END: BoardRenderer render_board()
*******************************************************************************/

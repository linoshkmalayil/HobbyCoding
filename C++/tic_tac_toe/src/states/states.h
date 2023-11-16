/*==============================================================================
FILE NAME: states.h
AUTHOR: LINOSH KURIAN MALAYIL
CREATED: 12 November 2023 11∶19∶28 PM
CONTAINS:
Defines and class enumerations for Tic-Tac-Toe Game
==============================================================================*/
#ifndef STATES_H
#define STATES_H

/*------------------------------------------------------------------------------
                            START: Defines
------------------------------------------------------------------------------*/
#define MAX_MARKS 9
#define DIMMENSIONS 3
/*------------------------------------------------------------------------------
                              END: Defines
------------------------------------------------------------------------------*/

/*******************************************************************************
                            START: enum classes
*******************************************************************************/
enum class MARKS{N, X, O};
enum class RESULT{WIN, LOSS, TIE, CONTINUE};
enum class SEQUENCE{ROW1, ROW2, ROW3,
                    COLUMN1, COLUMN2, COLUMN3,
                    DIAGONAL1, DIAGONAL2, NONE};
/*******************************************************************************
                            END: enum classes
*******************************************************************************/

#endif
/*==============================================================================
                        END OF FILE states.h
==============================================================================*/
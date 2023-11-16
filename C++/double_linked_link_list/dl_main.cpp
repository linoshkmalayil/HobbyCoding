/*==============================================================================
FILE NAME: dl_main.cpp
AUTHOR: LINOSH KURIAN MALAYIL
CREATED: 15 October 2023 08∶48∶17 PM
CONTAINS:
main function
==============================================================================*/

/*------------------------------------------------------------------------------
                            START: Includes
------------------------------------------------------------------------------*/
#include <iostream>
#include "dl_src/d_ll.h"
/*------------------------------------------------------------------------------
                            END: Includes
------------------------------------------------------------------------------*/

/*******************************************************************************
                                START: main()
*******************************************************************************/
int main()
{
    std::cout << "Double Linked List (Integer) Program\n";
    DoubleLinkedList<int> list;

    char choice = 'Y';
    do
    {
        short option;
        std::cout << "1) Add element\n"
                  << "2) Delete element\n"
                  << "3) Access specific element\n"
                  << "4) Display list\n"
                  << "Choice?: ";
        std::cin >> option;

        int value = 0;
        switch(option)
        {
            case 1  : std::cout << "Enter value: ";
                      std::cin >> value;
                      list.insert(value);
                      break;
            case 2  : std::cout << "Enter value: ";
                      std::cin >> value;
                      list.remove(value);
                      break;
            case 3  : std::cout << "Enter Index: ";
                      std::cin >> value;
                      value = (value < 0) ? 0 : value;
                      std::cout << list[value] << "\n";
                      break;
            case 4  : std::cout << "List: ";
                      list.display_list();
                      break;
            default : std::cout << "Invalid choice\n";
                      break;
        }

        std::cout << "Continue? (Y/N): ";
        std::cin >> choice; 
    } while (('Y' == choice) || ('y' == choice));
    
    return 0;
}
/*******************************************************************************
                                END: main()
*******************************************************************************/

/*==============================================================================
                        END OF FILE dl_main.cpp
==============================================================================*/

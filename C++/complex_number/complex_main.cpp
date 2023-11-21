#include <iostream>
#include "src/complex.h"

int main()
{
    std::cout << "Simple Complex Calculator \n";

    Complex C1, C2, result;

    char redo_choice = 'Y';
    do
    {
        std::cout << "1) Addition\n"
                  << "2) Subtraction\n"
                  << "3) Multiplication\n"
                  << "4) Division\n"
                  << "Choice: ";

        int choice = -1;
        while((4 < choice) || (1 > choice))
        {
            std::cin >> choice;
        }

        std::cout << "Enter C1: ";
        std::cin >> C1;
        std::cout << "Enter C2: ";
        std::cin >> C2;
        
        switch (choice)
        {
            case 1  : result = C1 + C2;
                      break;
            case 2  : result = C1 - C2;
                      break;
            case 3  : result = C1 * C2;
                      break;
            case 4  : result = C1 / C2;
                      break;
            default : std::cout << "Shouldn't have reached here\n";
                      break; 
        }
        std::cout << "C1: " << C1 << "\n";
        std::cout << "C2: " << C2 << "\n";
        std::cout << "Result (Rect): " << result 
                  << " Result (Polar): ";
        result.polar();
                  
        std::cout << "\nRedo? (Y/N): ";
        std::cin >> redo_choice;

    }while(('Y' == redo_choice) || ('y' == redo_choice));

    return 0;
}
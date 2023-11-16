#include <iostream>
#include <cstdlib>

enum class STATE{WIN, LOSS, TIE};
class Game
{   
        enum class CHOICES{ROCK, PAPER, SCISSOR};
            
        CHOICES opponent_move();
        CHOICES player_move();
        void display_choice(CHOICES &);

    public:
        Game()
        {
            srand((unsigned) time(NULL));
        }

        STATE play_game();
        
};

Game::CHOICES Game::opponent_move()
{
    unsigned char rng = 1 + (rand() % 3);
    
    switch(rng)
    {
        case 1 : return CHOICES::PAPER;
        case 2 : return CHOICES::ROCK;
        case 3 : return CHOICES::SCISSOR;
        default: throw new std::exception;
    }
}
        
Game::CHOICES Game::player_move()
{
    short choice;
    std::cout << "1) Rock\n"
                << "2) Paper\n"
                << "3) Scissor\n"
                << "Choice: ";

    std::cin >> choice;        
    
    if((choice < 1) || (choice > 3))
    {
        while((choice < 1) || (choice > 3))
        {
            std::cout << "Invalid choice! Choice: ";
            std::cin >> choice;
        }
    }

    switch(choice)
    {
        case 1 : return CHOICES::PAPER;
        case 2 : return CHOICES::ROCK;
        case 3 : return CHOICES::SCISSOR;
        default: throw new std::exception;
    }

}

void Game::display_choice(Game::CHOICES &choice)
{
    switch(choice)
    {
        case CHOICES::PAPER   : std::cout << "Paper";
                                break;
        case CHOICES::ROCK    : std::cout << "Rock";
                                break;
        case CHOICES::SCISSOR : std::cout << "Scissor";
                                break;
        default               : std::cout << "ERROR!";
                                break;
    }

    return;
}

STATE Game::play_game()
{
    CHOICES player_choice, opponent_choice;
    try{
        player_choice = player_move();
        opponent_choice = opponent_move();
    }
    catch(std::exception &)
    {
        std::cout << "Choice failed" << std::endl;
        exit(127);
    }

    std::cout << "Player Move: ";
    display_choice(player_choice);
    std::cout << "\tOpponent Move: ";
    display_choice(opponent_choice);
    std::cout << std::endl;

    if(player_choice == opponent_choice)
    {
        return STATE::TIE;
    }
    else if(((CHOICES::PAPER == player_choice) 
             && (CHOICES::ROCK == opponent_choice))
         || ((CHOICES::ROCK == player_choice)
             && (CHOICES::SCISSOR == opponent_choice))
         || ((CHOICES::SCISSOR == player_choice)
             && (CHOICES::PAPER == opponent_choice)))
    {
        return STATE::WIN;
    }
    else
    {
        return STATE::LOSS;
    }

}

int main()
{
    Game G1;

    char ch;
    do
    {
        STATE game_state = G1.play_game();

        if(STATE::WIN == game_state)
        {
            std::cout << "Player Won\n";
        }
        else if(STATE::LOSS == game_state)
        {
            std::cout << "player Lost\n";
        }
        else
        {
            std::cout << "Game Tie\n";
        }

        std::cout << "Play again? (Y/N): ";
        std::cin >> ch;

    } while ((ch == 'Y') || (ch == 'y'));
    
    return 0;
}
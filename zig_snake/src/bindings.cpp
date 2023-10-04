
#include "../../game.hpp"

extern "C" void PlayGame(void)
{
    SnakeGame::Game game;
    
    game.Run();
}
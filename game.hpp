
#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "snake.hpp"
#include "controler.hpp"

namespace SnakeGame
{

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:
    Board m_board;
    Snake m_snake;
    Controler m_controler;
    size_t m_score;

    static constexpr int FPS = 120;
    static constexpr int WINDOW_WIDTH = 800;
    static constexpr int WINDOW_HEIGHT = 600;
    static constexpr int CELL_SIZE = 20;
    static constexpr int BOARD_WIDTH = WINDOW_WIDTH / CELL_SIZE;
    static constexpr int BOARD_HEIGHT = WINDOW_HEIGHT / CELL_SIZE;

    void Update();
    void Draw();
};

}

#endif // GAME_HPP
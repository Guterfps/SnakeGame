
#ifndef GAME_HPP
#define GAME_HPP

#include <random>

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
    bool m_isGameOver{false};
    std::random_device m_rd;
    std::mt19937 m_gen;
    std::uniform_int_distribution<std::size_t> m_distribCols;
    std::uniform_int_distribution<std::size_t> m_distribRows;

    static constexpr int FPS = 120;
    static constexpr int WINDOW_WIDTH = 800;
    static constexpr int WINDOW_HEIGHT = 600;
    static constexpr int CELL_SIZE = 20;
    static constexpr int BOARD_WIDTH = WINDOW_WIDTH / CELL_SIZE;
    static constexpr int BOARD_HEIGHT = WINDOW_HEIGHT / CELL_SIZE;
    static constexpr double SNAKE_UPDATE_INTERVAL = 0.1;
    static constexpr double FOOD_UPDATE_INTERVAL = 2.5;

    void Update();
    void UpdateSnake();
    void UpdateFood();
    void Input();
    void Draw();
    void Restart();
    
};

}

#endif // GAME_HPP
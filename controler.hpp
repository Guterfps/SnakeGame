
#ifndef CONTROLER_HPP
#define CONTROLER_HPP

#include "snake.hpp"
#include "board.hpp"

namespace SnakeGame
{

class Controler
{

enum Direction : unsigned char {UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, NONE = 4};

public:
    explicit Controler(Board& board, Snake& snake);

    void HandleInput(Direction direction);

private:
    Board& m_board;
    Snake& m_snake;
};

}

#endif // CONTROLER_HPP
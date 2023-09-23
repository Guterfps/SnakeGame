
#ifndef CONTROLER_HPP
#define CONTROLER_HPP

#include "snake.hpp"
#include "board.hpp"

namespace SnakeGame
{

class Controler
{
public:
    enum Direction : unsigned int {UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3};
    
    explicit Controler(Board& board, Snake& snake);

    void HandleInput(int input);
    bool MoveSnake();
    Direction GetDirection() const;

private:
    Board& m_board;
    Snake& m_snake;
    Direction m_direction;
};

}

#endif // CONTROLER_HPP
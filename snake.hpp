
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <list> // std::list

#include "cell.hpp"

namespace SnakeGame
{

class Snake
{
public:
    Snake(std::size_t posX, std::size_t posY);

    bool Move(std::size_t posX, std::size_t posY);
    void Grow();

    const Cell& GetHead() const;
    const Cell& GetTail() const;

private:
    std::list<Cell> m_snake;

};

}

#endif // SNAKE_HPP
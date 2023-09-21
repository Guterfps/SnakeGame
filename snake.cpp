

#include "snake.hpp"

namespace SnakeGame
{

Snake::Snake(std::size_t posX, std::size_t posY) : 
            m_snake(1, Cell{posX, posY, Cell::Type::SNAKE})
{
}

const Cell& Snake::GetHead() const
{
    return m_snake.front();
}

const Cell& Snake::GetTail() const
{
    return m_snake.back();
}

} // namespace SnakeGame

#include <algorithm>

#include "snake.hpp"

namespace SnakeGame
{

Snake::Snake(const Cell& head) : 
            m_snake(1, Cell(head.GetPosX(), head.GetPosY(), 
                    head.GetSize(), Cell::Type::SNAKE))
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

bool Snake::Move(const Cell& toCell)
{
    auto it = std::find(m_snake.begin(), m_snake.end(), toCell);
    bool isValid = (it == m_snake.end());
    if (isValid)
    {
        m_snake.push_front(toCell);
        m_snake.pop_back();
    }

    return isValid;
}

void Snake::Grow(const Cell& addTail)
{
    m_snake.push_back(addTail);
}

void Snake::Reset(const Cell& head)
{
    m_snake.clear();
    m_snake.emplace_back(Cell(head.GetPosX(), head.GetPosY(), 
                        head.GetSize(), Cell::Type::SNAKE));
}

std::size_t Snake::GetLength() const
{
    return m_snake.size();
}

} // namespace SnakeGame
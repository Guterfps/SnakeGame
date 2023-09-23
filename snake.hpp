
#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <list> // std::list

#include "cell.hpp"

namespace SnakeGame
{

class Snake
{
public:
    Snake(const Cell& head);

    bool Move(const Cell& toCell);
    void Grow(const Cell& addTail);
    void Reset(const Cell& head);

    const Cell& GetHead() const;
    const Cell& GetTail() const;
    std::size_t GetLength() const;

private:
    std::list<Cell> m_snake;

};

}

#endif // SNAKE_HPP
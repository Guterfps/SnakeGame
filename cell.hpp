
#ifndef CELL_HPP
#define CELL_HPP

#include <cstddef> // size_t

namespace SnakeGame
{

struct Cell
{
    enum Type : unsigned char {EMPTY = 0, SNAKE = 1, FOOD = 2};

    explicit Cell(std::size_t posX = 0, std::size_t posY = 0, Type type = EMPTY) :
            m_posX(posX), m_posY(posY), m_type(type) {}

    void Draw() const;

    std::size_t m_posX;
    std::size_t m_posY;
    Type m_type;
};

}

#endif // CELL_HPP
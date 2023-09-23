
#ifndef CELL_HPP
#define CELL_HPP

#include <cstddef> // size_t

#include "raylib.h"

namespace SnakeGame
{

class Cell
{
public:
    enum Type : unsigned char {EMPTY = 0, SNAKE = 1, FOOD = 2};

    explicit Cell(std::size_t posX = 0, std::size_t posY = 0, 
                   std::size_t size = 1, Type type = EMPTY) :
            m_posX(posX), m_posY(posY), m_size(size), m_type(type) {}

    bool operator==(const Cell& other) const;

    void Draw() const;
    void SetType(Type type);
    void SetPos(std::size_t posX, std::size_t posY);
    
    std::size_t GetPosX() const;
    std::size_t GetPosY() const;
    std::size_t GetSize() const;
    Type GetType() const;

private:
    std::size_t m_posX;
    std::size_t m_posY;
    std::size_t m_size;
    Type m_type;
};

inline void Cell::Draw() const
{
    std::size_t x = m_posX * m_size;
    std::size_t y = m_posY * m_size;
    Color color = BLACK;

    switch (m_type)
    {
        case Cell::Type::EMPTY:
            color = BLACK;
            break;
        case Cell::Type::SNAKE:
            color = GREEN;
            break;
        case Cell::Type::FOOD:
            color = RED;
            break;
        default:
            break;
    }

    DrawRectangle(x, y, m_size, m_size, color);
}

inline void Cell::SetType(Type type)
{
    m_type = type;
}

inline void Cell::SetPos(std::size_t posX, std::size_t posY)
{
    m_posX = posX;
    m_posY = posY;
}

inline std::size_t Cell::GetPosX() const
{
    return m_posX;
}

inline std::size_t Cell::GetPosY() const
{
    return m_posY;
}

inline std::size_t Cell::GetSize() const
{
    return m_size;
}

inline Cell::Type Cell::GetType() const
{
    return m_type;
}

inline bool Cell::operator==(const Cell& other) const
{
    return ((m_posX == other.m_posX) & 
            (m_posY == other.m_posY) &
            (m_size == other.m_size) &
            (m_type == other.m_type));
}

}

#endif // CELL_HPP
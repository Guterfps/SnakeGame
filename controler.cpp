
#include "controler.hpp"

namespace SnakeGame
{

Controler::Controler(Board& board, Snake& snake) :
                m_board(board), m_snake(snake), m_direction(Direction::RIGHT)
{}

void Controler::HandleInput(int input)
{
    switch (input)
    {
        case KEY_UP:
            m_direction = Controler::Direction::UP;
            break;
        case KEY_DOWN:
            m_direction = Controler::Direction::DOWN;
            break;
        case KEY_LEFT:
            m_direction = Controler::Direction::LEFT;
            break;
        case KEY_RIGHT:
            m_direction = Controler::Direction::RIGHT;
            break;
        default:
            break;
    }
}

Controler::Direction Controler::GetDirection() const
{
    return m_direction;
}

bool Controler::MoveSnake()
{
    bool isValidMove = false;
    const Cell& head = m_snake.GetHead();
    std::size_t x = head.GetPosX();
    std::size_t y = head.GetPosY();

    switch (m_direction)
    {
        case UP:
            --y;
            break;
        case DOWN:
            ++y;
            break;
        case LEFT:
            --x;
            break;
        case RIGHT:
            ++x;
            break;
        default:
            break;
    }

    if ((x < m_board.GetCols()) & (y < m_board.GetRows()))
    {
        Cell nextHead(x, y, head.GetSize(), Cell::Type::SNAKE);
        isValidMove = m_snake.Move(nextHead);
    }

    return isValidMove;
}

} // namespace SnakeGame
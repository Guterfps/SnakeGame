
#include "controler.hpp"

namespace SnakeGame
{

Controler::Controler(Board& board, Snake& snake) :
                m_board(board), m_snake(snake), 
                m_direction(Direction::RIGHT), m_prevMove(Direction::RIGHT)
{}

void Controler::HandleInput()
{
    bool isRight = IsKeyPressed(KEY_RIGHT);
    bool isLeft = IsKeyPressed(KEY_LEFT);
    bool isUp = IsKeyPressed(KEY_UP);
    bool isDown = IsKeyPressed(KEY_DOWN);

    m_direction = static_cast<Direction>(
    Direction::RIGHT * isRight +
    Direction::LEFT * isLeft +
    Direction::UP * isUp +
    Direction::DOWN * isDown +
    m_direction * (!isRight & !isLeft & !isUp & !isDown));
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

    CheckValidDirection();

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

    m_prevMove = m_direction;

    return isValidMove;
}

void Controler::CheckValidDirection()
{
    if ((m_prevMove == UP) & (m_direction == DOWN))
    {
        m_direction = UP;
    }
    if ((m_prevMove == DOWN) & (m_direction == UP))
    {
        m_direction = DOWN;
    }
    if ((m_prevMove == LEFT) & (m_direction == RIGHT))
    {
        m_direction = LEFT;
    }
    if ((m_prevMove == RIGHT) & (m_direction == LEFT))
    {
        m_direction = RIGHT;
    }

}

} // namespace SnakeGame
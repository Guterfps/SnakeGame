
#include "controler.hpp"

namespace SnakeGame
{

Controler::Controler(Board& board, Snake& snake) :
                    m_board(board), m_snake(snake)
{}

} // namespace SnakeGame
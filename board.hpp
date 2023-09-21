
#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector> // std::vector

#include "cell.hpp"

namespace SnakeGame
{

class Board
{
public:
    explicit Board(std::size_t cols, std::size_t rows, std::size_t cellSize);

    void Draw() const;
    void Update(const Cell& cell, Cell::Type type);

private:
    std::size_t m_cellSize;
    std::size_t m_cols;
    std::size_t m_rows;
    std::vector<Cell> m_board;
};

}

#endif // BOARD_HPP
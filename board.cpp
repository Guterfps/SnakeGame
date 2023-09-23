
#include <algorithm>

#include "raylib.h"

#include "board.hpp"

namespace SnakeGame
{

Board::Board(std::size_t cols, std::size_t rows, std::size_t cellSize) : 
        m_cellSize(cellSize), 
        m_cols(cols), m_rows(rows),
        m_board(std::vector<Cell>(m_cols * m_rows))
{
    for (size_t i = 0; i < m_rows; ++i)
    {
        size_t row = i * cols;
        for (size_t j = 0; j < m_cols; ++j)
        {
            m_board[row + j] = Cell(j, i, m_cellSize, Cell::Type::EMPTY);
        }
    }
}

void Board::Draw() const
{
    for (const auto& cell : m_board)
    {
        cell.Draw();
    }
}

void Board::Update(const Cell& cell, Cell::Type type)
{
    m_board[cell.GetPosY() * m_cols + cell.GetPosX()].SetType(type);
}

void Board::Clear()
{
    std::for_each(m_board.begin(), m_board.end(), 
    [](Cell& cell)
    {
        cell.SetType(Cell::Type::EMPTY);
    });
}

std::size_t Board::GetCols() const
{
    return m_cols;
}

std::size_t Board::GetRows() const
{
    return m_rows;
}

const Cell& Board::GetCell(std::size_t col, std::size_t row) const
{
    return m_board[row * m_cols + col];
}

} // namespace SnakeGame

#include <iostream>

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
            m_board[row + j] = Cell(j, i, Cell::Type::EMPTY);
        }
    }
}

void Board::Draw() const
{
    for (const auto& cell : m_board)
    {
        std::size_t x = cell.m_posX * m_cellSize;
        std::size_t y = cell.m_posY * m_cellSize;

        switch (cell.m_type)
        {
            case Cell::Type::EMPTY:
                DrawRectangle(x, y, m_cellSize, m_cellSize, BLACK);
                break;
            case Cell::Type::SNAKE:
                DrawRectangle(x, y, m_cellSize, m_cellSize, GREEN);
                break;
            case Cell::Type::FOOD:
                DrawRectangle(x, y, m_cellSize, m_cellSize, RED);
                break;
            default:
                break;
        }
    }
}

void Board::Update(const Cell& cell, Cell::Type type)
{
    m_board[cell.m_posY * m_cols + cell.m_posX].m_type = type;
}

} // namespace SnakeGame
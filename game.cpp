
#include <stdexcept>

#include "raylib.h"

#include "game.hpp"

namespace SnakeGame
{

Game::Game() : m_board(BOARD_WIDTH, BOARD_HEIGHT, CELL_SIZE), 
                m_snake(BOARD_WIDTH >> 1, BOARD_HEIGHT >> 1), 
                m_controler(m_board, m_snake), m_score(0)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake Game");

    if (!IsWindowReady())
    {
        throw std::runtime_error("Window not ready");
    }
}

Game::~Game()
{
    CloseWindow();
}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
}

void Game::Update()
{
    const Cell& head = m_snake.GetHead();
    const Cell& tail = m_snake.GetTail();

    m_board.Update(tail, Cell::Type::EMPTY);
    m_board.Update(head, Cell::Type::SNAKE);
    m_board.Update(Cell(10, 10), Cell::Type::FOOD);
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    
    m_board.Draw();

    DrawText(TextFormat("FPS: %d", GetFPS()), 10, 30, 20, WHITE);
    EndDrawing();
}

} // namespace SnakeGame
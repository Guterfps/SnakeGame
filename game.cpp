
#include <stdexcept>
#include <chrono>
#include <random>

#include "raylib.h"

#include "game.hpp"

namespace SnakeGame
{

Game::Game() : m_board(BOARD_WIDTH, BOARD_HEIGHT, CELL_SIZE), 
                m_snake(Cell(BOARD_WIDTH >> 1, BOARD_HEIGHT >> 1, CELL_SIZE)), 
                m_controler(m_board, m_snake), m_score(0),
                m_rd(), m_gen(m_rd()), 
                m_distribCols(0, m_board.GetCols() - 1),
                m_distribRows(0, m_board.GetRows() - 1)
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
        Input();
        Update();
        Draw();
    }
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    
    m_board.Draw();

    DrawText(TextFormat("Score: %d", m_snake.GetLength() - 1), 10, 10, 20, WHITE);
    DrawText(TextFormat("FPS: %d", GetFPS()), WINDOW_WIDTH - 100, 10, 20, WHITE);
    if (m_isGameOver)
    {
        DrawText("GAME OVER", (WINDOW_WIDTH >> 1) - 100, 
                (WINDOW_HEIGHT >> 1) - 50, 40, WHITE);
        DrawText("Press SPACE to restart", (WINDOW_WIDTH >> 1) - 100, 
                (WINDOW_HEIGHT >> 1), 20, WHITE);
    }

    EndDrawing();
}

void Game::Update()
{
    static double lastSnakeUpdate = 0;
    static double lastFoodUpdate = 0;

    if (GetTime() - lastSnakeUpdate > SNAKE_UPDATE_INTERVAL)
    {
        UpdateSnake();
        lastSnakeUpdate = GetTime();
    }

    if (GetTime() - lastFoodUpdate > FOOD_UPDATE_INTERVAL)
    {
        UpdateFood();
        lastFoodUpdate = GetTime();
    }
}

void Game::Input()
{
    if (!m_isGameOver)
    {
        m_controler.HandleInput(GetKeyPressed());
    }
    else
    {
        if (KEY_SPACE == GetKeyPressed())
        {
            Restart();
        }
    }
}

void Game::UpdateSnake()
{
    Cell tail = m_snake.GetTail();

    if (m_controler.MoveSnake())
    {
        m_board.Update(tail, Cell::Type::EMPTY);
        
        const Cell& head = m_snake.GetHead();
        if (m_board.GetCell(head.GetPosX(), head.GetPosY()).GetType() == 
            Cell::Type::FOOD)
        {
            m_snake.Grow(tail);
            m_board.Update(tail, Cell::Type::SNAKE);
        }
        m_board.Update(head, Cell::Type::SNAKE);
    }
    else
    {
        m_isGameOver = true;
    }
}

void Game::UpdateFood()
{
    Cell food = m_board.GetCell(m_distribCols(m_gen), m_distribRows(m_gen));
    if (food.GetType() == Cell::Type::EMPTY)
    {
        m_board.Update(food, Cell::Type::FOOD);
    }
}

void Game::Restart()
{
    m_board.Clear();
    m_snake.Reset(Cell(m_distribCols(m_gen), m_distribRows(m_gen), CELL_SIZE));
    m_isGameOver = false;
}

} // namespace SnakeGame
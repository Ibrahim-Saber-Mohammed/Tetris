#include <raylib.h>
#include <random>
#include "Game.hpp"
#include "Blocks.cpp"

namespace T
{
    const std::vector<Block> GameBlocks = {LBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock(), JBlock()};

    Game::Game()
    {
        GameBlocks_ = GameBlocks;
        currentBlock_ = GetRandomBlock();
        nextBlock_ = GetRandomBlock();
    }
    Block Game::GetRandomBlock(void)
    {
        if (GameBlocks_.empty())
        {
            GameBlocks_ = GameBlocks;
        }
        int blockIndex = std::rand() % GameBlocks_.size();
        auto randomBlock = GameBlocks_[blockIndex];
        GameBlocks_.erase(GameBlocks_.begin() + blockIndex);
        return randomBlock;
    }
    void Game::LockBlock(void)
    {
        grid_.updateGrid(currentBlock_.GetBlockCellsPositions(), currentBlock_.getBlockId());
        currentBlock_ = nextBlock_;
        nextBlock_ = GetRandomBlock();
    }
    bool Game::IsBlockFits(void)
    {
        auto BlockCellPositions = currentBlock_.GetBlockCellsPositions();
        for(auto item : BlockCellPositions)
        {
            if(!grid_.IsCellEmpty(item.row_, item.col_))
            {
                return false;
            }
        }
        return true;
    }
    void Game::Draw()
    {
        grid_.Draw();
        currentBlock_.Draw();
    }
    void Game::HandleUserEvents()
    {
        int KeyPressed = GetKeyPressed();
        switch (KeyPressed)
        {
        case KEY_RIGHT:
        {
            MoveToRight();
        }
        break;
        case KEY_LEFT:
        {
            MoveToLeft();
        }
        break;
        case KEY_DOWN:
        {
            MoveDown();
        }
        break;
        case KEY_UP:
        {
            Rotate();
        }
        break;
        }
    }
    bool Game::IsBlockOutside(void)
    {
        auto BlockPoistions = currentBlock_.GetBlockCellsPositions();
        for (auto cellPos : BlockPoistions)
        {
            if (grid_.IsCellOutside(cellPos.row_, cellPos.col_))
            {
                return true;
            }
        }
        return false;
    }
    void Game::MoveToRight()
    {
        currentBlock_.Move(0, 1);
        if (IsBlockOutside() || !IsBlockFits())
        {
            currentBlock_.Move(0, -1);
        }
    }
    void Game::MoveToLeft()
    {
        currentBlock_.Move(0, -1);
        if (IsBlockOutside() || !IsBlockFits())
        {
            currentBlock_.Move(0, 1);
        }
    }
    void Game::MoveDown()
    {
        currentBlock_.Move(1, 0);
        if (IsBlockOutside() || !IsBlockFits())
        {
            currentBlock_.Move(-1, 0);
            LockBlock();
        }
    }
    void Game::Rotate()
    {
        currentBlock_.Rotate();
        if (IsBlockOutside() || !IsBlockFits())
        {
            currentBlock_.RotateBack();
        }
    }
}

namespace T
{

    Tetris::Tetris(int width, int height, const char *title) : width_{width}, height_{height}, title_{title} {}
    void Tetris::CreateWindow(int FramePerSecond)
    {
        InitWindow(width_, height_, title_.c_str());
        SetTargetFPS(FramePerSecond);
    }
    void Tetris::setBackGroundColor(const Color &color)
    {
        backGroundColor_ = color;
    }
    void Tetris::StartGame(void)
    {
        while (!WindowShouldClose())
        {
            BeginDrawing();
            grid_.Draw();
            ClearBackground(backGroundColor_);
            EndDrawing();
        }
    }
    Tetris::~Tetris()
    {
        CloseWindow();
    }
}
int main(int argc, char *argv[])
{
    constexpr int WIDTH = 300;
    constexpr int HEIGHT = 600;
    Color darkBlue = {44, 44, 127, 255};
    const char *GameTitle = "Tetris";
    constexpr int FPS{60};
    InitWindow(WIDTH, HEIGHT, GameTitle);
    SetTargetFPS(FPS);
    T::Game game;

    while (!WindowShouldClose())
    {
        game.HandleUserEvents();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    // Game::Tetris tetris(WIDTH, HEIGHT, GameTitle);
    // tetris.CreateWindow(FPS);
    // tetris.setBackGroundColor(darkBlue);

    // tetris.StartGame();
    return 0;
}
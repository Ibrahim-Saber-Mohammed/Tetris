#include <raylib.h>
#include <random>
#include "Game.hpp"
#include "Blocks.cpp"
#include "Colors.hpp"
namespace Tetris
{
    const std::vector<Block> GameBlocks = {LBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock(), JBlock()};
    Font font;
    Game::Game()
    {
        GameBlocks_ = GameBlocks;
        currentBlock_ = GetRandomBlock();
        nextBlock_ = GetRandomBlock();
        font = LoadFontEx("../Font/monogram.ttf", 64, 0, 0);
        socre_ = 0;
        gameOver_ = false;
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
        if (!IsBlockFits())
        {
            gameOver_ = true;
        }
        nextBlock_ = GetRandomBlock();
        auto completedRows = grid_.ClearFullRows();
        UpdateScore(completedRows, 0);
    }
    bool Game::IsBlockFits(void)
    {
        auto BlockCellPositions = currentBlock_.GetBlockCellsPositions();
        for (auto item : BlockCellPositions)
        {
            if (!grid_.IsCellEmpty(item.row_, item.col_))
            {
                return false;
            }
        }
        return true;
    }
    void Game::ResetGame(void)
    {
        grid_.InializeGrid();
        GameBlocks_ = GameBlocks;
        currentBlock_ = GetRandomBlock();
        nextBlock_ = GetRandomBlock();
        gameOver_ = false;
        socre_ = 0;
    }
    void Game::Draw()
    {
        DrawUserInfo();
        grid_.Draw();
        currentBlock_.Draw(11,11);
    }
    void Game::UpdateScore(int completedRows, int moveDownSteps)
    {
        switch (completedRows)
        {
        case 1:
        {
            socre_ += 100;
        }
        break;
        case 2:
        {
            socre_ += 300;
        }
        break;
        case 3:
        {
            socre_ += 500;
        }
        break;
        default:
            break;
        }
        socre_ += moveDownSteps;
    }
    void Game::DrawUserInfo(void)
    {
        char scoreText[10];
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (gameOver_)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);   // Score
        // Convert Score to string
        sprintf(scoreText, "%ld", socre_);
        auto scoreSize = MeasureTextEx(font, scoreText, 38, 2);
        // center the score text in the middle of Score Rectangle
        DrawTextEx(font, scoreText, {320+(170 - scoreSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue); // Next block area
        // center all the blocks in their area
        switch (nextBlock_.getBlockId())
        {
            case Tetris::BlockType::I_BLOCK:
            {
                nextBlock_.Draw(255, 290);
            }
            break;
            case Tetris::BlockType::O_BlOCk:
            {
                nextBlock_.Draw(255, 280);
            }
            break;
            default:
            {
                nextBlock_.Draw(270, 270);
            }
        }
    }
    void Game::HandleUserEvents()
    {
        int KeyPressed = GetKeyPressed();
        if (gameOver_ && KeyPressed != 0)
        {
            gameOver_ = false;
            ResetGame();
        }
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
            UpdateScore(0, 1);
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
        if (!gameOver_)
        {
            currentBlock_.Move(0, 1);
            if (IsBlockOutside() || !IsBlockFits())
            {
                currentBlock_.Move(0, -1);
            }
        }
    }
    void Game::MoveToLeft()
    {
        if (!gameOver_)
        {
            currentBlock_.Move(0, -1);
            if (IsBlockOutside() || !IsBlockFits())
            {
                currentBlock_.Move(0, 1);
            }
        }
    }
    void Game::MoveDown()
    {
        if (!gameOver_)
        {
            currentBlock_.Move(1, 0);
            if (IsBlockOutside() || !IsBlockFits())
            {
                currentBlock_.Move(-1, 0);
                LockBlock();
            }
        }
    }
    void Game::Rotate()
    {
        if (!gameOver_)
        {
            currentBlock_.Rotate();
            if (IsBlockOutside() || !IsBlockFits())
            {
                currentBlock_.RotateBack();
            }
        }
    }
}


double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
int main(int argc, char *argv[])
{
    constexpr double TIME_INTERVAL = 0.2;
    constexpr int WIDTH = 500;
    constexpr int HEIGHT = 620;
    const char *GameTitle = "Tetris";
    constexpr int FPS{60};
    InitWindow(WIDTH, HEIGHT, GameTitle);
    SetTargetFPS(FPS);
    Tetris::Game game;

    while (!WindowShouldClose())
    {
        game.HandleUserEvents();
        if (EventTriggered(TIME_INTERVAL))
        {
            game.MoveDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    return 0;
}
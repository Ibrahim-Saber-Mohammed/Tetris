#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <raylib.h>
#include <string>
#include "Grid.hpp"
#include "block.hpp"

namespace Tetris
{
    class Game{
        private:
        bool gameOver_{false};
        size_t socre_{0};
        Grid grid_{};
        Block currentBlock_;
        Block nextBlock_;
        std::vector<Block>Blocks;
        std::vector<Block>GameBlocks_;
        void MoveToRight(void);
        void MoveToLeft(void);
        void Rotate(void);
        bool IsBlockOutside(void);
        Block GetRandomBlock(void);
        void LockBlock(void);
        bool IsBlockFits(void);
        void ResetGame(void);
        void UpdateScore(int completedRows, int moveDownSteps);
        void DrawUserInfo(void);
    public:
        Game();
        void MoveDown(void);
        void Draw();
        void HandleUserEvents();
    };

}
#endif
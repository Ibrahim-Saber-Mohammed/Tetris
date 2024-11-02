#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <raylib.h>
#include <string>
#include "Grid.hpp"
#include "block.hpp"

namespace T
{
    class Game{
        private:
        Grid grid_{};
        Block currentBlock_;
        Block nextBlock_;
        std::vector<Block>Blocks;
        void MoveToRight(void);
        void MoveToLeft(void);
        void MoveDown(void);
        void Rotate(void);
        bool IsBlockOutside(void);
        std::vector<Block>GameBlocks_;
        Block GetRandomBlock(void);
        void LockBlock(void);
        bool IsBlockFits(void);

    public:
        Game();
        void Draw();
        void HandleUserEvents();

    };
    class Tetris
    {
        private:
        int width_{300};
        int height_{600};
        std::string title_ {""};
        Color backGroundColor_{};
        Grid grid_;
        Block block_;
        
    public:
    void CreateWindow(int FramePerSecond=60);
    void setBackGroundColor(const Color& color );
    Tetris(int width, int heihgt, const char* title);
    void StartGame(void);
    ~Tetris();
    };
}
#endif
#ifndef __GRID_HPP__
#define __GRID_HPP__
#include <iostream>
#include <vector>
#include <raylib.h>
#include "Colors.hpp"
#include "block.hpp"

namespace T{

    class Grid{
        private:
        int rows_{};
        int cols_{};
        int cellSize_{};
        std::vector<Color> gridCellsColors_;
        int grid_[20][10];

        public:
        Grid();
        void InializeGrid(void);
        void PrintGrid(void);
        void Draw(void);
        bool IsCellOutside(int row, int col);
        void updateGrid(const std::vector<Position> &tiles, BlockType BlockIdValue);
        bool IsCellEmpty(int row, int col);
        
    };
}
#endif
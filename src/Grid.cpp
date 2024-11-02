#include "Grid.hpp"

namespace T
{
    Grid::Grid() : rows_{20}, cols_{10}, cellSize_{30} { 
        this->InializeGrid();
        gridCellsColors_ = GetCellColors();
    }
    void Grid::InializeGrid(void)
    {
        for (size_t row{0}; row < rows_; row++)
        {
            for (size_t col{0}; col < cols_; col++)
            {
                grid_[row][col] = 0;
            }
        }
    }
    void Grid::PrintGrid(void)
    {
        for (size_t row{0}; row < rows_; row++)
        {
            for (size_t col{0}; col < cols_; col++)
            {
                std::cout << grid_[row][col] << " ";
            }
            std::cout << "\n";
        }
    }

    void Grid::Draw(void)
    {
        for (size_t row{}; row < rows_; row++)
        {
            for(size_t col{}; col < cols_; col++)
            {
                auto cellvalue = grid_[row][col];
                DrawRectangle((col * cellSize_) + 1 , (row * cellSize_) + 1, cellSize_ - 1 , cellSize_-1, gridCellsColors_[cellvalue]);
            }
        }
    }
    bool Grid::IsCellOutside(int row, int col)
    {
        if( row >= 0 && row < rows_ && col >= 0 && col < cols_)
        {
            return false;
        }
        else{
            return true;
        }
    }
    void Grid::updateGrid(const std::vector<Position> &tiles, BlockType BlockIdValue)
    {
        int l_blockId = static_cast<int>(BlockIdValue);
        for (auto tile : tiles)
        {
            grid_[tile.row_][tile.col_] = l_blockId;
        }
    }
    bool Grid::IsCellEmpty(int row, int col)
    {
        if(grid_[row][col] != 0)
        {
            return false;
        }
        return true;
    }
}
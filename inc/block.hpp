#ifndef __BLOCk_HPP__
#define __BLOCk_HPP__
#include <iostream>
#include <vector>
#include <map>
#include <raylib.h>
#include "Colors.hpp"

namespace Tetris
{
    struct Position
    {
        public:
        int row_{};
        int col_{};
        Position(int row, int col): row_{row}, col_{col} {}
    };
    enum class RotationStates
    {
        NO_ROTATE,
        ROTATE_90,
        ROTATE_180,
        ROTATE_270
    };
    enum class BlockType{
        L_BLOCK = 1,
        J_BLOCK,
        I_BLOCK,
        O_BlOCk,
        S_BLOCK,
        T_BLOCK,
        Z_BLOCK
    };
    class Block
    {
    private:
        std::vector<Color> blocksColors_{};
        int cellSize_{};
        RotationStates rotationState_{};
        int row_offset_{};
        int col_offset_{};
    protected:
        BlockType blockTypeId_{};
        std::map<RotationStates, std::vector<Position>> Blockcells_;
    public:
        Block(void);
        virtual void Draw(int offsetX, int offsetY);
        virtual void Move(int row, int col);
        std::vector<Position> GetBlockCellsPositions(void);
        virtual void Rotate(void);
        void RotateBack(void);
        bool IsBlockOutside(void);
        BlockType getBlockId(void);
        // virtual void undo_Rotate(void) = 0;
        // virtual void get_cell_positions(void) = 0;
        // virtual ~Block();
    };

   
}
#endif
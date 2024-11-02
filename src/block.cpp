#include "block.hpp"

namespace T
{

    Block::Block(void) : cellSize_{30}, rotationState_{RotationStates::NO_ROTATE}, row_offset_{0}, col_offset_{0}
    {
        blocksColors_ = GetCellColors();
    }
    void Block::Draw(void)
    {
        auto tiles = GetBlockCellsPositions();
        for (auto item : tiles)
        {
            DrawRectangle(
                (item.col_ * cellSize_) + 1,
                (item.row_ * cellSize_) + 1,
                (cellSize_ - 1),
                (cellSize_ - 1),
                blocksColors_[static_cast<int>(blockTypeId_)]);
        }
    }
    void Block::Move(int row, int col)
    {
        row_offset_ += row;
        col_offset_ += col;
    }
    std::vector<Position> Block::GetBlockCellsPositions(void) 
    {
        std::vector<Position> CurrentCellsPositions = Blockcells_[rotationState_];
        std::vector<Position> movedTiles;
        for (auto cell : CurrentCellsPositions)
        {
            movedTiles.emplace_back(row_offset_ + cell.row_, col_offset_ + cell.col_);
        }
        return movedTiles;
    }
    void Block::Rotate(void)
    {
        int newRotationState =  static_cast<int>(rotationState_) + 1;
        rotationState_ = static_cast<RotationStates>(newRotationState);
        if(rotationState_ > RotationStates::ROTATE_270)
        {
            rotationState_ = RotationStates::NO_ROTATE;
        }
    }
    void Block::RotateBack(void)
    {
        int newRotationState =  static_cast<int>(rotationState_) - 1;
        rotationState_ = static_cast<RotationStates>(newRotationState);
        if (rotationState_ < RotationStates::NO_ROTATE)
        {
            rotationState_ = RotationStates::ROTATE_270;
        }
    }
    BlockType Block::getBlockId(void)
    {
        return blockTypeId_;
    }
}
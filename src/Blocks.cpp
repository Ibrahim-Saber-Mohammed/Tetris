#include "block.hpp"
namespace T
{
    class LBlock : public Block
    {
    public:
        LBlock()
        {
            blockTypeId_ = BlockType::L_BLOCK;
            Blockcells_[RotationStates::NO_ROTATE] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
            Blockcells_[RotationStates::ROTATE_90] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
            Blockcells_[RotationStates::ROTATE_180] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
            Blockcells_[RotationStates::ROTATE_270] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
            Move(0,3);
        }
    };
    class IBlock : public Block
    {
    public:
        IBlock()
        {
            blockTypeId_ = BlockType::I_BLOCK;
            Blockcells_[RotationStates::NO_ROTATE] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
            Blockcells_[RotationStates::ROTATE_90] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
            Blockcells_[RotationStates::ROTATE_180] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
            Blockcells_[RotationStates::ROTATE_270] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
            Move(-1,3);
        }
    };
    class JBlock : public Block
    {
    public:
        JBlock()
        {
            blockTypeId_ = BlockType::J_BLOCK;
            Blockcells_[RotationStates::NO_ROTATE] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
            Blockcells_[RotationStates::ROTATE_90] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
            Blockcells_[RotationStates::ROTATE_180] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
            Blockcells_[RotationStates::ROTATE_270] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
            Move(0,3);
        }
    };
    class OBlock : public Block
    {
    public:
        OBlock()
        {
            blockTypeId_ = BlockType::O_BlOCk;
            Blockcells_[RotationStates::NO_ROTATE] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            Blockcells_[RotationStates::ROTATE_90] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            Blockcells_[RotationStates::ROTATE_180] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            Blockcells_[RotationStates::ROTATE_270] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            Move(0,4);
        }
    };
    class SBlock : public Block
    {
    public:
        SBlock()
        {
            blockTypeId_ = BlockType::S_BLOCK;
            Blockcells_[RotationStates::NO_ROTATE] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
            Blockcells_[RotationStates::ROTATE_90] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
            Blockcells_[RotationStates::ROTATE_180] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
            Blockcells_[RotationStates::ROTATE_270] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
            Move(0,3);
        }
    };

    class TBlock : public Block
    {
    public:
        TBlock()
        {
            blockTypeId_ = BlockType::T_BLOCK;
            Blockcells_[RotationStates::NO_ROTATE] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
            Blockcells_[RotationStates::ROTATE_90] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
            Blockcells_[RotationStates::ROTATE_180] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
            Blockcells_[RotationStates::ROTATE_270] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
            Move(0,3);
        }
    };
    class ZBlock : public Block
    {
    public:
        ZBlock()
        {
            blockTypeId_ = BlockType::Z_BLOCK;
            Blockcells_[RotationStates::NO_ROTATE] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
            Blockcells_[RotationStates::ROTATE_90] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
            Blockcells_[RotationStates::ROTATE_180] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
            Blockcells_[RotationStates::ROTATE_270] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
            Move(0,3);
        }
    };
}
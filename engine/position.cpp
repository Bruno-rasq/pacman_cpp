#include "../engine/position.hpp"

const std::unordered_map<Direction, Coord> Deltas = {
    {Direction::UP,     {-1, 0}},
    {Direction::RIGHT,  {0, 1}},
    {Direction::DOWN,   {1, 0}},
    {Direction::LEFT,   {0, -1}}
};
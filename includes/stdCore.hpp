#pragma once

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include <windows.h>


struct Coord_t { int32_t row, col; };

enum Direction { UP, DOWN, LEFT, RIGHT };

const std::unordered_map<Direction, Coord_t> DeltaDirections = {

    {Direction::UP, {-1, 0}}, 
    {Direction::DOWN, {1, 0}},
    {Direction::LEFT, {0, -1}}, 
    {Direction::RIGHT, {0, 1}},
};
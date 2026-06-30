#ifndef __POSITIONS__HPP__
#define __POSITIONS__HPP__

#include "../includes/__libs__.hpp"

enum Direction {UP, RIGHT, DOWN, LEFT, NONE};

struct Coord { int row, col; };

/* Direção - deslocamento XY */
extern const std::unordered_map<Direction, Coord> Deltas;

#endif
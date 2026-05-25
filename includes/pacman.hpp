#pragma once
#include "./config.hpp"
#include "./stdCore.hpp"

struct Pacman {

    Coord_t currentCoord;
    Direction currentDirection;

    Pacman();

    void ChangeDirections(Direction Dir);
    void UpdateCoord();

    Coord_t GetCoord();
    Direction GetDir();
};
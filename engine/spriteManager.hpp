#ifndef __SPRITEMANAGER__HPP__
#define __SPRITEMANAGER__HPP__

#include "../includes/__libs__.hpp"
#include "../engine/position.hpp"

struct Sprite {
    Coord coord;
    char icon;
    Sprite(Coord c, char icon);
};

#endif
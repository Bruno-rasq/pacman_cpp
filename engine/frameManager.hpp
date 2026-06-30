#ifndef __FRAMEMANAGER__HP__
#define __FRAMEMANAGER__HP__

#include "../includes/__libs__.hpp"
#include "../entities/maze.hpp" 
#include "../engine/spriteManager.hpp"
#include "../engine/position.hpp"

struct Frame {
    std::vector<std::string> frame_board = mazeObj;
    Frame();
    void render() const;
    void draw(Sprite& sprite);
    bool check_valid_coord(Coord& coord);
};

#endif
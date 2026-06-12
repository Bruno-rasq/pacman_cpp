#ifndef __FRAMEMANAGER__HP__
#define __FRAMEMANAGER__HP__

#include "../includes/__libs__.hpp"
#include "../includes/mazeModel.hpp"
#include "../engine/spriteManager.hpp"
#include "../engine/position.hpp"

struct Frame {

    const int8_t frame_width = 28;
    const int8_t frame_height = 30; 
    std::string frame_board = mazeModel;

    Frame();

    void render() const;
    void draw(Sprite& sprite);
    bool check_valid_coord(Coord& coord);
};

#endif
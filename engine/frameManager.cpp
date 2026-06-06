#include "./frameManager.hpp"

Frame::Frame(){};

void Frame::draw(Sprite& sprite){
    int8_t x = sprite.coord.x;
    int8_t y = sprite.coord.y;
    this->frame_board[x * (this->frame_width + 1) + y] = sprite.icon;
};

bool Frame::check_Wall(Coord& coord){
    int8_t x = coord.x;
    int8_t y = coord.y;
    return this->frame_board[x * (this->frame_width + 1) + y] != '#';
};

void Frame::render() const {
    std::cout << this->frame_board;
};
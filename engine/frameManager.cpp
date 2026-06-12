#include "./frameManager.hpp"

Frame::Frame(){};

void Frame::draw(Sprite& sprite){
    int8_t x = sprite.coord.x;
    int8_t y = sprite.coord.y;
    this->frame_board[x * (this->frame_width + 1) + y] = sprite.icon;
};

bool Frame::check_valid_coord(Coord& coord){
    int8_t x = coord.x;
    int8_t y = coord.y;

    // checa se a coordeana esta dentro dos limites od frame
    if(x >= 0 && x < this->frame_width && y >= 0 && y < this->frame_height)
        // checa se a coordeanda não é uma parede
        if(this->frame_board[x * (this->frame_width + 1) + y] != '#')
            return true;

    return false;
};

void Frame::render() const {
    std::cout << this->frame_board;
};
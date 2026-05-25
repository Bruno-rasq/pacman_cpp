#include "./frameManager.hpp"


Frame::Frame(const std::string& mazeContent){
    this->board = mazeContent;
    this->width = this->board.find('\n');
};


void Frame::Draw(int16_t x, int16_t y, char sprite){
    this->board[x * (this->width + 1) + y] = sprite;
};

bool Frame::checkWall(int16_t x, int16_t y){
    return this->board[x * (this->width + 1) + y] != '#';
};

void Frame::Render() const {
    std::cout << this->board;
};
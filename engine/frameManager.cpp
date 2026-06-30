#include "./frameManager.hpp"

Frame::Frame(){};

void Frame::draw(Sprite& sprite){
    int8_t row = sprite.coord.row;
    int8_t col = sprite.coord.col;
    this->frame_board[row][col] = sprite.icon;
    //this->frame_board[x * (this->frame_width + 1) + y] = sprite.icon;
};

bool Frame::check_valid_coord(Coord& coord){

    int row = coord.row;
    int col = coord.col;
    int width = this->frame_board[0].size();
    int heigth = this->frame_board.size();

    if(row >= 0 && row < width && col >= 0 && col < heigth)
        return this->frame_board[row][col] != '#';
    
    return false;
};

void Frame::render() const {
    std::ostringstream oss;
    for(const std::string& line : this->frame_board)
        oss << line << "\n";
    std::cout << oss.str();
};
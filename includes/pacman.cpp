#include "./pacman.hpp"

Pacman::Pacman(){

    this->currentDirection = Direction::LEFT;
    this->currentCoord = {CONFIG::INITIALPACMANROW, CONFIG::INITIALPACMANCOL};
};


void Pacman::ChangeDirections(Direction dir){
    this->currentDirection = dir;
};


void Pacman::UpdateCoord(){

    int32_t row = this->currentCoord.row;
    int32_t col = this->currentCoord.col;

    int32_t dx = DeltaDirections.at(this->currentDirection).row;
    int32_t dy = DeltaDirections.at(this->currentDirection).col;

    this->currentCoord = {row + dx, col + dy};
};

Coord_t Pacman::GetCoord(){
    return this->currentCoord;
};

Direction Pacman::GetDir(){
    return this->currentDirection;
};
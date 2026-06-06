#include "./pacman.hpp"

Pacman::Pacman(){};


// PRIVATE:
void Pacman::update_pacman_coord(Frame& frame){
    Coord delta = Deltas.at(this->pacman_direction);
    Coord new_coord = {
        this->pacman_coord.x + delta.x,
        this->pacman_coord.y + delta.y
    };

    if(frame.check_Wall(new_coord))
        this->pacman_coord = new_coord;
};

void Pacman::toggle_pacman_sprite(){
    // TODO
};


// PUBLIC: 
Pacman::Pacman(){};

Sprite Pacman::get_sprite() const {
    return {this->pacman_coord, this->pacman_sprite};
};

void Pacman::update_pacman_status(){
    // TODO
};

void Pacman::set_pacman_direction(Direction new_direction){
    this->pacman_direction = new_direction;
};
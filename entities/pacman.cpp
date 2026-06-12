#include "./pacman.hpp"

Pacman::Pacman(){};


// PRIVATE:
void Pacman::toggle_pacman_sprite(){
    this->toggle_face = !this->toggle_face;

    if(this->toggle_face){
        this->pacman_sprite = pacman_faces.at(this->pacman_direction);
        return;
    }
    this->pacman_sprite = pacman_face_toggle.at(this->pacman_direction);
};

// PUBLIC: 
Sprite Pacman::get_sprite() const {
    return {this->pacman_coord, this->pacman_sprite};
};

void Pacman::update_pacman_status(Frame& fr, Direction nd){

    Coord delta = Deltas.at(this->pacman_direction);

    if(nd != Direction::NONE) delta = Deltas.at(nd);

    Coord nc = {(int8_t)(this->pacman_coord.x + delta.x),
                (int8_t)(this->pacman_coord.y + delta.y)};

    if(fr.check_valid_coord(nc) && nd != Direction::NONE){
        this->pacman_coord = nc;
        this->pacman_direction = nd;
    }

    this->toggle_pacman_sprite();
};
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

    Coord nc = {this->pacman_coord.row + delta.row,
                this->pacman_coord.col + delta.col};

    // redireciona o pac quando ele atravessa uma das saidas laterais.
    if(nc.row == 14 && nc.col == 0) nc = {14, 28};
    if(nc.row == 14 && nc.col == 29) nc = {14, 0};

    if(fr.check_valid_coord(nc) && nd != Direction::NONE){
        this->pacman_coord = nc;
        this->pacman_direction = nd;
    }

    this->toggle_pacman_sprite();
};
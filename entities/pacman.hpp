#ifndef __PACMAN__HPP__
#define __PACMAN__HPP__

#include "../includes/__libs__.hpp"
#include "../engine/position.hpp"
#include "../engine/spriteManager.hpp"
#include "../engine/frameManager.hpp"


/** As faces devem mudar de acordo com oa direção que o pacman 
 *  estiver se movento, alem disso quero que ocile entre a face
 *  e um char '|', o que pode dar a sensação de abrir e fechar a
 *  boca.
*/
const std::unordered_map<Direction, char> pacman_faces = {
    {Direction::UP,    'v'},
    {Direction::DOWN,  '^'},
    {Direction::LEFT,  '>'},
    {Direction::RIGHT, '<'},
};

class Pacman {
    private: 
        Coord pacman_coord = {17, 13}; // coordenada inicial.
        Direction pacman_direction = Direction::LEFT;
        char pacman_sprite = pacman_faces.at(pacman_direction);
 
        void update_pacman_coord(Frame& frame);
        void toggle_pacman_sprite();
    
    public:
        Pacman();

        Sprite get_sprite() const; 
        void update_pacman_status();
        void set_pacman_direction(Direction new_direction);
};

#endif
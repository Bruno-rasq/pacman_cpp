#include "../includes/stdCore.hpp"
#include "../includes/pacman.hpp"
#include "../includes/keyboardManager.hpp"


void log_pacman_infos(Coord_t& coord, Direction& dir){

    std::cout <<  "X: " << coord.row << " - Y: " << coord.col << "\n";

    switch(dir){
        case 0: {std::cout << " direction: cima\n"; break; }
        case 1: {std::cout << " direction: baixo\n"; break; }
        case 2: {std::cout << " direction: esquerda\n"; break; }
        case 3: {std::cout << " direction: direita\n"; break; }
        default: { break; }
    }
}


/*
    Teste consiste em criar um pacman base, nas coordenadas iniciaise exibir 
    suas informações no terminal.
*/
void test_create_pacman(){

    Pacman pac;

    Coord_t coord = pac.GetCoord();
    Direction dir = pac.GetDir();

    log_pacman_infos(coord, dir);
}


/*
    Teste consiste em verificar se é possivel dar comandos ao pacman usando o keyboard
    o loop vai ler os comandos de entrada e executar um update das infos do pacman e então
    exibi-las no terminal.
*/
void test_can_control_pacman(){

    Pacman pac;
    KeyboardManager km;

    Coord_t coord = pac.GetCoord();
    Direction dir = pac.GetDir();

    log_pacman_infos(coord, dir);

    while(true){

        Sleep(CONFIG::TIMESLEEP);

        int key = km.KeyPressed();

        if(key == VK_ESCAPE) break;
    
        if(key == VK_UP) pac.ChangeDirections(Direction::UP);
        if(key == VK_DOWN) pac.ChangeDirections(Direction::DOWN);
        if(key == VK_LEFT) pac.ChangeDirections(Direction::LEFT);
        if(key == VK_RIGHT) pac.ChangeDirections(Direction::RIGHT);

        pac.UpdateCoord();

        Coord_t coord = pac.GetCoord();
        Direction dir = pac.GetDir();

        log_pacman_infos(coord, dir);
    }
}
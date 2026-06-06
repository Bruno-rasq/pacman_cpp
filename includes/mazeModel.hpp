#ifndef __MAZEMODEL_HPP__
#define __MAZEMODEL_HPP__

#include "../includes/__libs__.hpp"
#include "../engine/position.hpp"

/* coordenadas aonde devem-se desenhar as frutinhas que o pacman precisa pegar. */
extern const std::vector<Coord> mazeFruitCoordCells;

/* modelo do labirinto de pacman desenhado em ascii numa string 
   corrida, isso simplifica a forma de desenhar o labirinto e o
   modificar.**/
extern const std::string mazeModel;

#endif
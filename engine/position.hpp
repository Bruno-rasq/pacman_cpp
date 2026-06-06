#ifndef __POSITIONS__HPP__
#define __POSITIONS__HPP__

#include "../includes/__libs__.hpp"

enum Direction {UP, RIGHT, DOWN, LEFT};

struct Coord {
    int8_t x, y; // row: x  col: y
    bool operator==(const Coord& other) const;
};

/* para usar o Coord em um unordered_map como chaave de acessp.*/
struct CoordHash {
    size_t operator()(const Coord& node) const;
};

/* Direção - deslocamento XY */
extern const std::unordered_map<Direction, Coord> Deltas;

/* Estrutura Node - coordenada */
extern const std::unordered_map<char, Coord> Nodes;

/*
    Agrupa as coordenadas dos nodes de conexão de um respectivo node para as
    4 direções, caso não haja um node na determinada direção entao a coord deve
    ser -1 -1
*/
struct Conn { char up, down, left, right; };

/*
    Estrutura graph armazena os dados de cada node do mapa e seus adjacentes
    afim de criar um acesso rapido e estatico aos mesmos.
*/
extern const std::unordered_map<Coord, Conn, CoordHash> graph;


#endif
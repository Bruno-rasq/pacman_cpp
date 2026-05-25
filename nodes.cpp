#include <iostream>
#include <unordered_map>
#include <string>
#include <windows.h>

using namespace std;



/*
    Estrutura de uma coordenada
*/
struct Coord {
    int x, y;
    bool operator==(const Coord& other) const {
        return x == other.x && y == other.y;
    }
};


/* 
    para usar o Coord em um unordered_map como chaave de acessp.
*/
struct CoordHash {
    size_t operator()(const Coord& node) const {
        return hash<int>()(node.x) ^ (hash<int>()(node.y) << 1);
    }
};


/*
    Estrutura Node - coordenada
*/
const unordered_map<char, Coord> Nodes = {

    {'A', {1, 1}},   {'a', {20, 9}},  {'+', {14, 0}},
    {'B', {1, 6}},   {'b', {20, 12}}, {'-', {14, 27}},
    {'C', {1, 12}},  {'c', {20, 15}}, {'1', {14, 6}},
    {'D', {1, 15}},  {'d', {20, 18}}, {'2', {14, 9}},
    {'E', {1, 21}},  {'e', {20, 21}}, {'3', {14, 18}},
    {'F', {1, 26}},  {'f', {20, 26}}, {'4', {14, 21}},
    {'G', {5, 1}},   {'g', {23, 1}},  {'5', {17, 9}},
    {'H', {5, 6}},   {'h', {23, 3}},  {'6', {17, 13}},
    {'I', {5, 9}},   {'i', {23, 6}},  {'7', {17, 18}},
    {'J', {5, 12}},  {'j', {23, 9}},  {'8', {20, 1}},
    {'K', {5, 15}},  {'k', {23, 12}}, {'9', {20, 6}},
    {'L', {5, 18}},  {'l', {23, 15}}, {'@', {29, 1}},
    {'M', {5, 21}},  {'m', {23, 18}}, {'$', {29, 12}},
    {'N', {5, 26}},  {'n', {23, 21}}, {'&', {29, 15}},
    {'O', {8, 1}},   {'o', {23, 24}}, {'*', {29, 26}},
    {'P', {8, 6}},   {'p', {23, 26}},
    {'Q', {8, 9}},   {'q', {26, 1}},
    {'R', {8, 12}},  {'r', {26, 3}},
    {'S', {8, 15}},  {'s', {26, 6}},
    {'T', {8, 18}},  {'t', {26, 9}},
    {'U', {8, 21}},  {'u', {26, 12}},
    {'V', {8, 26}},  {'v', {26, 15}},
    {'W', {11, 9}},  {'w', {26, 18}},
    {'X', {11, 12}}, {'x', {26, 21}},
    {'Y', {11, 15}}, {'y', {26, 24}},
    {'Z', {11, 18}}, {'z', {26, 26}},
};


/*
    Agrupa as coordenadas dos nodes de conexão de um respectivo node para as
    4 direções, caso não haja um node na determinada direção entao a coord deve
    ser -1 -1
*/
struct Conn { char up, down, left, right; };


/*
    Deltas para atravessar de um node para seu adjacente.
*/
const unordered_map<int, Coord> Deltas = {
    {VK_UP, {-1, 0}}, {VK_DOWN, {1, 0}}, {VK_LEFT, {0, -1}}, {VK_RIGHT, {0, 1}}
};


/*
    Estrutura graph armazena os dados de cada node do mapa e seus adjacentes
    afim de criar um acesso rapido e estatico aos mesmos.
*/
const unordered_map<Coord, Conn, CoordHash> graph = {

    // coordenada -- up - down - left- right                    up - down - left- right
    {Nodes.at('A'), {'.',  'G',  '.',  'B'}},  {Nodes.at('a'), {'5',  '.',  '9',  'b'}},
    {Nodes.at('B'), {'.',  'H',  'A',  'C'}},  {Nodes.at('b'), {'.',  'k',  'a',  '.'}},
    {Nodes.at('C'), {'.',  'J',  'B',  '.'}},  {Nodes.at('c'), {'.',  'l',  '.',  'd'}},
    {Nodes.at('D'), {'.',  'K',  '.',  'E'}},  {Nodes.at('d'), {'7',  '.',  'c',  'e'}},
    {Nodes.at('E'), {'.',  'M',  'D',  'F'}},  {Nodes.at('e'), {'4',  'n',  'd',  'f'}},
    {Nodes.at('F'), {'.',  'N',  'E',  '.'}},  {Nodes.at('f'), {'.',  'p',  'e',  '.'}},
    {Nodes.at('G'), {'A',  'O',  '.',  'H'}},  {Nodes.at('g'), {'8',  '.',  '.',  'h'}},
    {Nodes.at('H'), {'B',  'P',  'G',  'I'}},  {Nodes.at('h'), {'.',  'r',  'g',  '.'}},
    {Nodes.at('I'), {'.',  'Q',  'H',  'J'}},  {Nodes.at('i'), {'9',  's',  '.',  'j'}},
    {Nodes.at('J'), {'C',  '.',  'I',  'K'}},  {Nodes.at('j'), {'.',  't',  'i',  'k'}},
    {Nodes.at('K'), {'D',  '.',  'J',  'L'}},  {Nodes.at('k'), {'b',  '.',  'j',  'l'}},
    {Nodes.at('L'), {'.',  'T',  'K',  'M'}},  {Nodes.at('l'), {'c',  '.',  'k',  'm'}},
    {Nodes.at('M'), {'E',  'U',  'L',  'N'}},  {Nodes.at('m'), {'.',  'w',  'l',  'n'}},
    {Nodes.at('N'), {'F',  'V',  'M',  '.'}},  {Nodes.at('n'), {'e',  'x',  'm',  '.'}},
    {Nodes.at('O'), {'G',  '.',  '.',  'P'}},  {Nodes.at('o'), {'.',  'y',  '.',  'p'}},
    {Nodes.at('P'), {'H',  '1',  'O',  '.'}},  {Nodes.at('p'), {'f',  '.',  'o',  '.'}},
    {Nodes.at('Q'), {'I',  '.',  '.',  'R'}},  {Nodes.at('q'), {'.',  '@',  '.',  'r'}},
    {Nodes.at('R'), {'.',  'X',  'Q',  '.'}},  {Nodes.at('r'), {'h',  '.',  'q',  's'}},
    {Nodes.at('S'), {'.',  'Y',  '.',  'T'}},  {Nodes.at('s'), {'i',  '.',  'r',  '.'}},
    {Nodes.at('T'), {'L',  '.',  'S',  '.'}},  {Nodes.at('t'), {'j',  '.',  '.',  'u'}},
    {Nodes.at('U'), {'M',  '4',  '.',  'V'}},  {Nodes.at('u'), {'.',  '$',  't',  '.'}},
    {Nodes.at('V'), {'N',  '.',  'U',  '.'}},  {Nodes.at('v'), {'.',  '&',  '.',  'w'}},
    {Nodes.at('W'), {'.',  '2',  '.',  'X'}},  {Nodes.at('w'), {'m',  '.',  'v',  '.'}},
    {Nodes.at('X'), {'R',  '.',  'W',  'Y'}},  {Nodes.at('x'), {'n',  '.',  '.',  'y'}},
    {Nodes.at('Y'), {'S',  '.',  'X',  'Z'}},  {Nodes.at('y'), {'o',  '.',  'x',  'z'}},
    {Nodes.at('Z'), {'.',  '3',  'Y',  '.'}},  {Nodes.at('z'), {'.',  '*',  'y',  '.'}},
    {Nodes.at('+'), {'.',  '.',  '.',  '1'}},  {Nodes.at('-'), {'.',  '.',  '4',  '.'}},
    {Nodes.at('@'), {'q',  '.',  '.',  '$'}},  {Nodes.at('$'), {'u',  '.',  '@',  '&'}},
    {Nodes.at('&'), {'v',  '.',  '$',  '*'}},  {Nodes.at('*'), {'z',  '.',  '&',  '.'}},
    {Nodes.at('1'), {'P',  '9',  '+',  '2'}},  {Nodes.at('2'), {'W',  '5',  '1',  '.'}},
    {Nodes.at('3'), {'Z',  '7',  '.',  '4'}},  {Nodes.at('4'), {'U',  'e',  '3',  '-'}},
    {Nodes.at('5'), {'2',  'a',  '.',  '6'}},  {Nodes.at('6'), {'.',  '.',  '5',  '7'}},
    {Nodes.at('7'), {'3',  'd',  '6',  '.'}},  {Nodes.at('8'), {'.',  'g',  '.',  '9'}},
    {Nodes.at('9'), {'1',  'i',  '8',  'a'}},
    
};




// //============== INCLUSOES PARA TESTE //==============

#include "./includes/keyboardManager.hpp"
#include "./includes/mazeModel.hpp"
#include "./includes/frameManager.hpp"


/**
 *  TASK:
 * 
 *  desenvolver um algoritmo que anime a travessia do pac de um 
 *  node atual para um node target.
 * 
*/

void log_maze(Coord& pac){
    Frame fr(mazeModel);
    fr.Draw(pac.x, pac.y, '@');
    fr.Render();
};


void setCurrentNode(
    char& currNode, Coord& currentPacCoord, Conn nodeConections, int direction){

    char nextNodeChar;
    if(direction == VK_UP) nextNodeChar = nodeConections.up;
    if(direction == VK_DOWN) nextNodeChar = nodeConections.down;
    if(direction == VK_LEFT) nextNodeChar = nodeConections.left;
    if(direction == VK_RIGHT) nextNodeChar = nodeConections.right;

    Coord nextNodeCoord = Nodes.at(nextNodeChar);

    if(nextNodeCoord.x == currentPacCoord.x && nextNodeCoord.y == currentPacCoord.y){
        currNode = nextNodeChar;

        if(currNode == '+'){
            currNode = '-';
            currentPacCoord = Nodes.at('-');
        }
        if(currNode == '-'){
            currNode = '+';
            currentPacCoord = Nodes.at('+');
        }
    }
}

bool checkValidMoviment(Conn nodeConections, int direction){
    
    if(nodeConections.up != '.' && direction == VK_UP) return true;
    if(nodeConections.down != '.' && direction == VK_DOWN) return true;
    if(nodeConections.left != '.' && direction == VK_LEFT) return true;
    if(nodeConections.right != '.' && direction == VK_RIGHT) return true;

    return false;
}

void updatePacCoord(char& currentNodechar, Coord& currentPacCoord, int direction){

    Coord nodeCoord = Nodes.at(currentNodechar);
    Conn currentNodeConections = graph.at(nodeCoord);

    if(checkValidMoviment(currentNodeConections, direction)){

        Coord delta = Deltas.at(direction);
        int x = currentPacCoord.x;
        int y = currentPacCoord.y;
        int dx = delta.x;
        int dy = delta.y;

        currentPacCoord = {x + dx, y + dy};

        setCurrentNode(currentNodechar, currentPacCoord, currentNodeConections, direction);
    }
}



int main() {

    KeyboardManager keyboardmanager;

    char currentNodeChar = '6';
    int currentDirectionMove = VK_RIGHT;

    Coord currentPacCoordinate = Nodes.at(currentNodeChar);

    log_maze(currentPacCoordinate);

    while(true){

        Sleep(150); // espere 0.1 segundos.

        int keypressed = keyboardmanager.KeyPressed();

        if(keypressed == VK_ESCAPE) break;
        if(keypressed != 0) currentDirectionMove = keypressed;

        system("cls");

        updatePacCoord(currentNodeChar, currentPacCoordinate, currentDirectionMove);

        log_maze(currentPacCoordinate);
        
    }

    system("cls");
    log_maze(currentPacCoordinate);

    return 0;
}
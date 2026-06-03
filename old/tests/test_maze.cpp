#include "../includes/stdCore.hpp"
#include "../includes/mazeModel.hpp"
#include "../includes/frameManager.hpp"

/*
    Teste Consiste em criar um frame alimentado com o modelo de labirinto
    e deve ser capaz de exibir no terminal o frame do labirinto.
*/
void test_create_frame_with_maze(){

    Frame testFrame(mazeModel);

    testFrame.Render();
};


/*
    Teste consiste em criar um frame alimentado com o modelo de labirinto,
    inserir as frutinhas em suas determinadas coordenadas no labirinto e 
    deve exibir o frame no terminal.
*/
void test_maze_can_draw_an_sprite(){

    Frame fr(mazeModel);

    for(Coord_t coord : mazeFruitCoordCells){
        fr.Draw(coord.row, coord.col, '.');
    }

    fr.Render();
};


int main(){

    // g++ tests/test_maze.cpp

    test_create_frame_with_maze();
    test_maze_can_draw_an_sprite();

    return 0;
}
/*

    Ideia era criar um sistema de tarefas por função.

    cada tarefa seria criada e validada em um momento x, essas etapas de verificação e demais
    seriam analisadas uma unica vez, depois disso o programa simplesmente executaria passos da
    tarefa ate conclui-la ou receber uma nova.

**/

#include "../engine/position.hpp"


#include <iostream>
#include <unordered_map>
#include <string>
#include <windows.h>

using namespace std;



void log_maze(Coord_t& pac){
    Frame fr(mazeModel);
    fr.Draw(pac.x, pac.y, '@');
    fr.Render();
};



// //============== INCLUSOES PARA TESTE //==============

#include "../old/includes/keyboardManager.hpp"
#include "../old/includes/mazeModel.hpp"
#include "../old/includes/frameManager.hpp"

void test_nodes_in_correct_positions(){

    Frame frame_maze(mazeModel);

    for(const auto& data: Nodes){
        char key = data.first;
        Coord coord = data.second;

        frame_maze.Draw(coord.x, coord.y, key);
    }

    frame_maze.Render();
}

//==============//==============//==============//==============

void log_maze(Coord& pac){
    Frame fr(mazeModel);
    fr.Draw(pac.x, pac.y, '@');
    fr.Render();
};


void log_node(char node){
    Coord currentnode = Nodes.at(node);
    Conn currentnodeConnections = graph.at(currentnode);

    cout << "Node atual: " << node << "  |   ";
    cout << "UP: " << currentnodeConnections.up << " ";
    cout << "DOWN: " << currentnodeConnections.down << " ";
    cout << "LEFT: " << currentnodeConnections.left << " ";
    cout << "RIGHT: " << currentnodeConnections.right << "\n";
}

void log(char node){
    // define a coordenada do pacman como a coordenada do node atual.
    Coord pac = Nodes.at(node);
    // recebe a coordenada do pacman e cria o frame do labirinto.
    log_maze(pac);

    log_node(node); // apenas log informações (removivel.)
}

char set_new_node(char currentNode, int key){

    Coord currentNodeCoord = Nodes.at(currentNode);
    Conn currentNodeConnections = graph.at(currentNodeCoord);


    if((key == VK_UP) && (currentNodeConnections.up != '.')) 
        return currentNodeConnections.up;

    if((key == VK_DOWN) && (currentNodeConnections.down != '.')) 
        return currentNodeConnections.down;

    if((key == VK_LEFT) && (currentNodeConnections.left != '.')) 
        return currentNodeConnections.left;

    if((key == VK_RIGHT) && (currentNodeConnections.right != '.')) 
        return currentNodeConnections.right;


    // casos especiais
    if((key == VK_LEFT) && currentNode == '+') return '-';
    if((key == VK_RIGHT) && currentNode == '-') return '+';


    return currentNode;

}




int main(){

    KeyboardManager km;
    char currentNode = '6';

    log(currentNode);

    while(true){

        Sleep(200); // espere 0.2 segundos.

        int key = km.KeyPressed();

        if(key == VK_ESCAPE) break;
        if(key == 0) continue;

        system("cls");
        char newNode = set_new_node(currentNode, key);
        currentNode = newNode;
        log(currentNode);

    }
    system("cls");
    log(currentNode);
    return 0; 
}
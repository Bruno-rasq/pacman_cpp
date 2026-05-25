#include "../includes/config.hpp"
#include "../includes/stdCore.hpp"
#include "../includes/keyboardManager.hpp"


/*
    Teste consiste em verificar se o jogador consegue efetuar comandos atraves
    do teclado do computador.

    comandos:
        set para cima
        set para baixo
        set para esquerda
        set para direita

    caso nenhum comando seja efetuado o loop deve continuar exibindo o ultimo
    comando dado.
*/
void test_keyboard(){

    KeyboardManager km;

    int keypressed = VK_LEFT;
    while(keypressed != VK_ESCAPE){
        Sleep(CONFIG::TIMESLEEP);

        if(keypressed == VK_UP) std::cout << "cima\n";
        if(keypressed == VK_DOWN) std::cout << "baixo\n";
        if(keypressed == VK_LEFT) std::cout << "esquerda\n";
        if(keypressed == VK_RIGHT) std::cout << "direita\n";


        int key = km.KeyPressed();
        if(key != 0) keypressed = key;
    }
}
#include "./includes/__libs__.hpp"
//#include "./engine/frameManager.hpp"
#include "./engine/keyboardManager.hpp"
#include "./engine/position.hpp"
#include "./engine/spriteManager.hpp"
#include "./entities/pacman.hpp"

/*
    compilar: g++ main.cpp includes/*.cpp engine/*.cpp entities/*.cpp
    -I include -I engine -I entities -o game.exe

    run: game.exe
*/

void render_frame(Sprite pcs){

    system("cls");
    Frame fr;
    fr.draw(pcs);
    fr.render();
}

void game_loop(){
    KeyboardManager km;
    Pacman pc = Pacman();
    Sprite pcs = pc.get_sprite();
    Direction pcd = Direction::LEFT;

    render_frame(pcs);

    int key = 0;

    while(true){

        Sleep(200);

        key = km.KeyPressed();

        if(key == VK_ESCAPE) break;

        switch(key){
            case VK_UP:     { pcd = Direction::UP;    break; }
            case VK_DOWN:   { pcd = Direction::DOWN;  break; }
            case VK_LEFT:   { pcd = Direction::LEFT;  break; }
            case VK_RIGHT:  { pcd = Direction::RIGHT; break; }
            default: break;
        }
        
        Frame fr;
        pc.update_pacman_status(fr, pcd);
        pcs = pc.get_sprite();
        render_frame(pcs);
    }

    render_frame(pcs);
}

int main(){
    game_loop();
    return 0;
}
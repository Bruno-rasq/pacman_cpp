#include "./engine/frameManager.hpp"

int main(){
    Frame fr = Frame();

    fr.draw(23, 1, 'v');
    fr.render();

    return 0;
}
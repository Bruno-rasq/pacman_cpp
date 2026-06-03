#include "./keyboardManager.hpp"

KeyboardManager::KeyboardManager(){};

int KeyboardManager::KeyPressed(){
    
    if((GetAsyncKeyState(VK_UP) & this->KEY_MSB_MASK) != 0) return VK_UP;
    if((GetAsyncKeyState(VK_DOWN) & this->KEY_MSB_MASK) != 0) return VK_DOWN;
    if((GetAsyncKeyState(VK_LEFT) & this->KEY_MSB_MASK) != 0) return VK_LEFT;
    if((GetAsyncKeyState(VK_RIGHT) & this->KEY_MSB_MASK) != 0) return VK_RIGHT;
    if((GetAsyncKeyState(VK_ESCAPE) & this->KEY_MSB_MASK) != 0) return VK_ESCAPE;

    return 0;
}
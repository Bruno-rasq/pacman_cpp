#ifndef __KEYBOARDMANAGER__HP__
#define __KEYBOARDMANAGER__HP__

#include "../includes/__libs__.hpp"
#include "../engine/position.hpp"

struct KeyboardManager {

    const int KEY_MSB_MASK = 0x8000;

    KeyboardManager();

    int KeyPressed();
};

#endif
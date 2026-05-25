#include "./stdCore.hpp"

struct KeyboardManager {

    const int KEY_MSB_MASK = 0x8000;

    KeyboardManager();

    int KeyPressed();
};
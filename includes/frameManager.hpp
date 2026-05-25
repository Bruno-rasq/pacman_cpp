#pragma once

#include "./stdCore.hpp"

struct Frame {

    int16_t width;
    std::string board;

    Frame(const std::string& mazeContent);

    void Draw(int16_t x, int16_t y, char sprite);
    bool checkWall(int16_t x, int16_t y);
    void Render() const;
};
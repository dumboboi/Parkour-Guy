#ifndef GENERAL_HPP
#define GENERAL_HPP
#include <vector>
#include <array>

constexpr unsigned short CELL_SIZE = 16;
constexpr unsigned short SCREEN_RESIZE = 2;
constexpr unsigned short SCREEN_HEIGHT= 300;
constexpr unsigned short SCREEN_WIDTH = 400;
constexpr float  FULL_SCREEN_WIDTH = SCREEN_WIDTH * SCREEN_RESIZE;
constexpr float FULL_SCREEN_HEIGHT = SCREEN_HEIGHT * SCREEN_RESIZE;
constexpr float MAX_VERTICAL_SPEED = 8;
constexpr float MIN_VERTICAL_SPEED = 1;
constexpr float Gravity = 0.25f;
#endif // GENERAL_HPP

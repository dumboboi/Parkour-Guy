#include "MapsManager.hpp"
#include <vector>
#include <General.hpp>
MapsManager::MapsManager()
{
}
sf::Vector2f MapsManager::getStartingPosition(unsigned short Level)
{
    sf::Vector2f PSP;
    switch(Level)
    {
    case 1:
    {
        PSP.x = CELL_SIZE*SCREEN_RESIZE-1;
        PSP.y = CELL_SIZE*SCREEN_RESIZE-1;
        break;
    }
    case 2:
    {
        PSP.x = (FULL_SCREEN_WIDTH - (CELL_SIZE * SCREEN_RESIZE * 2));
        PSP.y = (SCREEN_RESIZE * CELL_SIZE * 2)-25;
        break;
    }
    case 3:
    {
        PSP.x = SCREEN_RESIZE * CELL_SIZE * 4;
        PSP.y = SCREEN_RESIZE * CELL_SIZE * 3;
        break;
    }
    }
    return PSP;
}

std::vector<std::vector<int>> MapsManager::GetLevel(unsigned short Level)
{
    std::vector<std::vector<int>> lvl;
    switch(Level)
    {
    case 1:
    {
        lvl = lvl1;
        break;
    }
    case 2:
    {
        lvl = lvl2;
        break;
    }
    case 3:
    {
        lvl = lvl3;
        break;
    }
    }
    return lvl;
}

float MapsManager::getLevelSpeed(unsigned short Level)
{
    float speed;
    switch(Level)
    {
    case 1:
    {
        speed =0.7f ;
        break;
    }
    case 2:
    {
        speed = 0.3f ;
        break;
    }
    case 3:
        speed = 0.35f;
        break;
    }
    return speed;
}





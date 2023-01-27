#include <array>
#include <cmath>
#include <vector>
#include <General.hpp>
#include "Collider.hpp"

bool map_vertical_collision(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int> cellsVect)
{
    bool output = 0;

    //Getting the exact position.
    float cell_x = i_x / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);

    for (unsigned short a = 0; a < 4; a++)
    {
        float x = 0;
        float y = 0;

        switch (a)
        {
        case 0: //Top left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        case 1: //Top right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        case 2: //Bottom left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(ceil(cell_y));

            break;
        }
        case 3: //Bottom right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(ceil(cell_y));
        }
        }

        //Making sure that the position is inside the map.
        if (0 <= x && 1 <= y && y < FULL_SCREEN_HEIGHT  && x < FULL_SCREEN_WIDTH)
        {
            //checking if cells are collidable.
            for (int i = 0; i < cellsVect.size() ; i++)
            {
                if (v[y][x]== cellsVect[i])
                {
                    output = 1;
                }
            }

        }
    }

    return output;
}
bool map_horizontal_collision(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int> cellsVect)
{
    bool output = 0;

    //Getting the exact position.
    float cell_x = i_x / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);

    for (unsigned short a = 0; a < 2; a++)
    {
        float x = 0;
        float y = 0;

        switch (a)
        {
        case 0: //Top left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        case 1: //Top right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }

        }

        //Making sure that the position is inside the map.
        if (0 <= x && 1 <= y && y < FULL_SCREEN_HEIGHT  && x < FULL_SCREEN_WIDTH)
        {
            //checking if cells are collidable.
            for (int i = 0; i < cellsVect.size(); i ++)
            {
                if (v[y][x] == cellsVect[i])
                {
                    output = 1;
                }
            }
        }
    }

    return output;
}

bool vertical_collision_with_obstacles(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int> cellsVect)
{
    bool output = 0;

    //Getting the exact position.
    float cell_x = i_x / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);

    for (unsigned short a = 0; a < 4; a++)
    {
        float x = 0;
        float y = 0;

        switch (a)
        {
        case 0: //Top left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        case 1: //Top right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        case 2: //Bottom left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(ceil(cell_y));

            break;
        }
        case 3: //Bottom right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(ceil(cell_y));
        }
        }

        //Making sure that the position is inside the map.
        if (0 <= x && 1 <= y && y < FULL_SCREEN_HEIGHT  && x < FULL_SCREEN_WIDTH)
        {
            //checking if cells are collidable.
            for (auto &s:cellsVect)
            {
                if (v[y][x] == s)
                {
                    output = 1;
                }
            }
        }
    }

    return output;
}

bool collision_with_coins_treasures(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int>cellsVect)
{
    bool output = 0;

    //Getting the exact position.
    float cell_x = i_x / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);

    for (unsigned short a = 0; a < 2; a++)
    {
        float x = 0;
        float y = 0;

        switch (a)
        {

        case 0: //Top left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        case 1: //Top right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        }

        //Making sure that the position is inside the map.
        if (0 <= x && 1 <= y && y < FULL_SCREEN_HEIGHT  && x < FULL_SCREEN_WIDTH)
        {
            //checking if cells are collidable.
            for (auto &c:cellsVect)
            {
                if (v[y][x] == c)
                {
                    output = 1;
                }
            }
        }
    }

    return output;

}
bool collision_with_lava_roots(float i_x, float i_y, std::vector<std::vector<int>> v)
{
    bool output = 0;

    //Getting the exact position.
    float cell_x = i_x / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);

    for (unsigned short a = 0; a < 2; a++)
    {
        float x = 0;
        float y = 0;

        switch (a)
        {
        case 0: //Bottom left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(ceil(cell_y));

            break;
        }
        case 1: //Bottom right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(ceil(cell_y));
        }

        }

        //Making sure that the position is inside the map.
        if (0 <= x && 1 <= y && y < FULL_SCREEN_HEIGHT  && x < FULL_SCREEN_WIDTH)
        {
            //checking if cells are collidable.
            if (v[y][x] == 3 || v[y][x] == 11)
            {
                output = 1;
            }

        }
    }

    return output;

}

bool collision_with_doors_treasures(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int>cellsVect)
{
    bool output = 0;

    //Getting the exact position.
    float cell_x = i_x / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);

    for (unsigned short a = 0; a < 4; a++)
    {
        float x = 0;
        float y = 0;

        switch (a)
        {
        case 0: //Top left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        case 1: //Top right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(floor(cell_y));

            break;
        }
        case 2: //Bottom left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(ceil(cell_y));

            break;
        }
        case 3: //Bottom right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(ceil(cell_y));
        }
        }

        //Making sure that the position is inside the map.
        if (0 <= x && 1 <= y && y < FULL_SCREEN_HEIGHT  && x < FULL_SCREEN_WIDTH)
        {
            //checking if cells are collidable.
            for (auto &t:cellsVect)
            {
                if (v[y][x] == t)
                {
                    output = 1;
                }
            }

        }
    }

    return output;

}


bool collision_with_tools_boosts(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int> obj)
{
    bool output = 0;

    //Getting the exact position.
    float cell_x = i_x / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);
    float cell_y = i_y / static_cast<float>(CELL_SIZE * SCREEN_RESIZE);

    for (unsigned short a = 0; a < 2; a++)
    {
        float x = 0;
        float y = 0;

        switch (a)
        {
        case 0: //Bottom left cell
        {
            x = static_cast<short>(floor(cell_x));
            y = static_cast<short>(ceil(cell_y));

            break;
        }
        case 1: //Bottom right cell
        {
            x = static_cast<short>(ceil(cell_x));
            y = static_cast<short>(ceil(cell_y));
        }

        }

        //Making sure that the position is inside the map.
        if (0 <= x && 1 <= y && y < FULL_SCREEN_HEIGHT  && x < FULL_SCREEN_WIDTH)
        {
            //checking if cells are collidable.
            for(auto &o:obj)
            {
                if (v[y][x] == o)
                {
                    output = 1;
                }
            }
        }
    }

    return output;
}

bool collision_between_player_bats(float p_x,float p_y,float b_x,float b_y)
{
    bool output = 0;
    p_x+=CELL_SIZE;
    p_y+=CELL_SIZE;
    b_x+=CELL_SIZE;
    b_y+=CELL_SIZE;
    if (sqrt( pow( p_x - b_x,2) + pow( p_y - b_y,2))<=17.0f)
    {
        output = 1;
    }
    return output;
}

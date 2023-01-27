#pragma once
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

bool map_vertical_collision(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int> cellsVect);
bool map_horizontal_collision(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int> cellsVect);
bool vertical_collision_with_obstacles(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int> cellsVect);
bool collision_with_coins_treasures(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int>cellsVect);
bool collision_with_lava_roots(float i_x, float i_y, std::vector<std::vector<int>> v);
bool collision_with_doors_treasures(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int>cellsVect);
bool collision_with_tools_boosts(float i_x, float i_y, std::vector<std::vector<int>> v,std::vector<int> obj);

bool collision_between_player_bats(float p_x,float p_y,float b_x,float b_y);

#include <SFML/Graphics.hpp>
#include <Player.hpp>
#include <General.hpp>
#include <LoadTextures.hpp>
#include <vector>
#include <MapsManager.hpp>
#ifndef DRAWMAP_HPP
#define DRAWMAP_HPP


class DrawMap
{
    float x;
    float y;
    sf::Rect<float> src;
    sf::Rect<float> batsrc;
    MapsManager Mpman;

public:
    bool updatesLoaded;
    std::vector<std::vector<int>> Map;
    std::vector<sf::Sprite> Bats;
    std::vector<sf::Rect<float>> BatsPos;
    LoadTextures textLoad;
    DrawMap();
    void LoadMap(std::vector<std::vector<int>> lvlvect);
    short startingTime;
    void Update(unsigned short Level);
    void Draw(sf::RenderWindow& i_window);
    std::vector<sf::Rect<float>> getBatPos();
    void Load_Map_Entities(unsigned short Level);
    void Draw_Entities(sf::RenderWindow& i_window,unsigned short Level);
    void Updates_after_coin(unsigned short Level,std::vector<std::vector<int>>* Map);
    void ResetMap(unsigned short Level,std::vector<std::vector<int>>* Map);
    void RemoveEntities(unsigned short Level);
    std::vector<std::vector<int>>* getMap();

private:
    //Textures
    sf::Texture caveroot;
    sf::Texture darkstone;
    sf::Texture deepdarkstone;
    sf::Texture sandblock;
    sf::Texture caveblock;
    sf::Texture leavesblock;
    sf::Texture coin;
    sf::Texture portal;
    sf::Texture lowerLava;
    sf::Texture upperLava;
    sf::Texture heart;
    sf::Texture sword;
    sf::Texture battext;
    sf::Texture rank2battext;
    sf::Texture speedboost;
    sf::Texture caveleave;
    sf::Texture chest;
    //Sprites
    sf::Sprite caverootSp;
    sf::Sprite DarkStoneSp;
    sf::Sprite deepDarkStoneSp;
    sf::Sprite SandBlockSp;
    sf::Sprite CaveBlockSp;
    sf::Sprite LeavesBlockSp;
    sf::Sprite coinSp;
    sf::Sprite portalSp;
    sf::Sprite lowerLavaSp;
    sf::Sprite upperLavaSp;
    sf::Sprite heartSp;
    sf::Sprite swordSp;
    sf::Sprite batSp;
    sf::Sprite rank2batSp;
    sf::Sprite speedboostSp;
    sf::Sprite caveleaveSp;
    sf::Sprite chestSp;
    //variables
    float batflyingspeed = 0.3f;
    float updatingtimer;
    bool flyright;
    bool rank2flyright;

};
#endif // DRAWMAP_HPP

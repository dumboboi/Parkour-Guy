#include <array>
#include <chrono>
#include <cmath>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundFileReader.hpp>
#include <SFML/Audio/Music.hpp>
//--------------------------//
#include "General.hpp"
#include "Player.hpp"
#include "DrawMap.hpp"
#include <LoadTextures.hpp>
#include <MapsManager.hpp>
#include <wallpaperManager.hpp>
int main()
{
    unsigned short Level = 1;
    constexpr std::chrono::microseconds FRAME_DURATION(16667);
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previous_time;
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH,SCREEN_RESIZE * SCREEN_HEIGHT ), "Parkour guy");
    window.setKeyRepeatEnabled(false);
    // Loading classes
    Player player;
    DrawMap Map;
    LoadTextures textLoader;
    MapsManager Mapper;
    wallpaperManager WallManager;
    bool finishedLevel = 0;
    bool failedLevel = 0;
    while (1 == window.isOpen())
    {

        std::chrono::microseconds delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time);

        lag+= delta_time;
        while (FRAME_DURATION <= lag)
        {
            lag-=FRAME_DURATION;

            while (1 == window.pollEvent(event))
            {
                switch(event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                }
            }
            window.clear();
            player.update(Map.getMap(),&finishedLevel,&Level,&failedLevel,Map.getBatPos());
            std::vector<std::vector<int>> *Map1 = Map.getMap();
            Map.Update(Level);
            WallManager.DrawWallpaper(window);
            Map.Draw_Entities(window,Level);
            Map.Draw(window);
            player.draw(window);
            //died 3 times in a level
            if (failedLevel == 1)
            {
                Map.updatesLoaded = 0;
                WallManager.updateWallpaper(Level);
                Map.RemoveEntities(Level);
                Map.LoadMap(Mapper.GetLevel(Level));
                Map.Load_Map_Entities(Level);
                Map.startingTime = 600;
                player.invincible = 1;
                player.tookCoin = failedLevel = 0;

            }
            //finished level
            if (finishedLevel == 1)
            {
                Map.updatesLoaded = 0;
                Level++;
                WallManager.updateWallpaper(Level);
                Map.RemoveEntities(Level);
                Map.LoadMap(Mapper.GetLevel(Level));
                Map.Load_Map_Entities(Level);
                Map.startingTime = 600;
                player.invincible = 1;
                player.reset(Mapper.getStartingPosition(Level));
                player.tookCoin = finishedLevel = 0;
            }
            window.display();
        }
    }
    return EXIT_SUCCESS;
}

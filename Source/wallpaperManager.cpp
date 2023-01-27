#include "wallpaperManager.hpp"

wallpaperManager::wallpaperManager()
{
    src.top = src.left = 0;
    src.height = src.width = 1;
    WallSprite=TextLoader.load_texture("resources/lvl1skybg.png",WallText);
}

void wallpaperManager::updateWallpaper(unsigned short Level)
{
    switch (Level)
    {
    case 1:
    {
        WallSprite = TextLoader.load_texture("resources/lvl1skybg.png",WallText);
        break;
    }
    case 2:
    {
        WallSprite = TextLoader.load_texture("resources/cave.jpg",WallText);
        break;
    }
    case 3:
    {
        WallSprite = TextLoader.load_texture("resources/cave2.png",WallText);
        break;
    }

    }
}


void wallpaperManager::DrawWallpaper(sf::RenderWindow& i_window)
{
    TextLoader.draw_texture(i_window,WallSprite,src);
}

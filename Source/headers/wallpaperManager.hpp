#ifndef WALLPAPERMANAGER_HPP
#define WALLPAPERMANAGER_HPP
#include <LoadTextures.hpp>

class wallpaperManager
{
    LoadTextures TextLoader;
    sf::Sprite WallSprite;
    sf::Texture WallText;
    sf::Rect<float> src;
public:
    wallpaperManager();

    void updateWallpaper(unsigned short Level);
    void DrawWallpaper(sf::RenderWindow& i_window);

protected:

private:
};

#endif // WALLPAPERMANAGER_HPP

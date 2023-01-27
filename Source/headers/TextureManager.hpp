#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include <LoadTextures.hpp>


class TextureManager
{
    float x;
    float y;
    LoadTextures textLoader;
    sf::Texture texture;
    public:
        TextureManager();
        void drawTexture(sf::RenderWindow& i_window);
};

#endif // TEXTUREMANAGER_HPP

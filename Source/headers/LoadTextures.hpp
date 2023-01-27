#ifndef LOADTEXTURES_HPP
#define LOADTEXTURES_HPP
#include <SFML/Graphics.hpp>

class LoadTextures
{
    sf::Sprite sprite;
public:
    LoadTextures();
    sf::Sprite load_texture(std::string,sf::Texture& texture);
    void draw_texture(sf::RenderWindow& i_window,sf::Sprite& cell_sprite,sf::Rect<float>src);
};

#endif // LOADTEXTURES_HPP

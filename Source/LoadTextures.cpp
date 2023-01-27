#include "LoadTextures.hpp"
#include "General.hpp"
#include <cmath>
LoadTextures::LoadTextures()
{
    //ctor
}


sf::Sprite LoadTextures::load_texture(std::string Cell,sf::Texture& texture)
{
    texture.loadFromFile(Cell);
    sprite.setTexture(texture);
    return sprite;
}

void LoadTextures::draw_texture(sf::RenderWindow& i_window,sf::Sprite& cell_sprite,sf::Rect<float> src)
{
    cell_sprite.setPosition(round(src.left),round(src.top));
    cell_sprite.setScale(src.width, src.height);
    i_window.draw(cell_sprite);

}

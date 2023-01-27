#include <SFML/Graphics.hpp>
#include <TextureManager.hpp>
#include <General.hpp>
TextureManager::TextureManager():
x(100),
y(100)
{
    //loadTexture(textureName);

}


void TextureManager::drawTexture(sf::RenderWindow& i_window)
{
    sf::Sprite sprite;sprite.setTexture(texture);
    sprite.setPosition(x,y);
    i_window.draw(sprite);

}

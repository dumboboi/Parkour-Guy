#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <SFML/Graphics.hpp>
#include <LoadTextures.hpp>

class Animation
{
    LoadTextures Loader;
public:
    Animation();
    void standing_animation(sf::Rect<float> *playerSrc,float y,float *standinanimtimer);
    void walking_animation(sf::Sprite& sprite,sf::Texture& texture,float *walkanimationtimer,char playerStandingView);
};

#endif // ANIMATION_HPP

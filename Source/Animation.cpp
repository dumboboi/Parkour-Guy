#include "Animation.hpp"

Animation::Animation()
{
    //ctor
}


void Animation::standing_animation(sf::Rect<float> *playerSrc,float y,float *standinanimtimer)
{
    if((*standinanimtimer)>=100)
    {
        (*playerSrc).top = y;
        (*standinanimtimer)--;
    }
    else
    {
        (*playerSrc).top -=2;
        (*standinanimtimer)--;
    }
    if((*standinanimtimer)<=0)
    {
        (*standinanimtimer) = 300;
    }
}

void Animation::walking_animation(sf::Sprite& sprite,sf::Texture& texture,float *walkanimationtimer,char playerStandingView)
{
    if((*walkanimationtimer) >= 133.3f)
    {
        if(playerStandingView == 'R')
        {
            sprite = Loader.load_texture("resources/walkanim3.png",texture);
        }
        else
        {
            sprite = Loader.load_texture("resources/walkanim3Left.png",texture);
        }
        (*walkanimationtimer)--;
    }
    else if((*walkanimationtimer) >= 66.6f)
    {
        if(playerStandingView == 'R')
        {
            sprite = Loader.load_texture("resources/walkanim2.png",texture);
        }
        else
        {
            sprite = Loader.load_texture("resources/walkanim2Left.png",texture);
        }
        (*walkanimationtimer)--;
    }
    else if((*walkanimationtimer)>= 0.0f)
    {
        if(playerStandingView == 'R')
        {
            sprite=Loader.load_texture("resources/walkanim1.png",texture);
        }
        else
        {
            sprite=Loader.load_texture("resources/walkanim1Left.png",texture);
        }
        (*walkanimationtimer)--;
    }
    if((*walkanimationtimer)<0)
    {
        (*walkanimationtimer) = 200;
    }
}

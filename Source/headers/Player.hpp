#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <DrawMap.hpp>
#include <Collider.hpp>
#include <MapsManager.hpp>
#include <Animation.hpp>
class Player
{
    LoadTextures Loader;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Rect<float> playerSrc;
    int jumpTimer;
    float vertical_speed;
    float JUMP_SPEED = -0.6;
    float horizontal_speed;
    short jumping_time ;
    short jumpingCountdown;
    bool isJumping;
    bool walking;
    bool OnGround;
    char playerStandingView;
    DrawMap MapUpdater;
    MapsManager Mapman;
    Animation animation;
public:
    bool invincible;
    bool tookCoin;
    sf::Rect<float>heartsrc;
    float PLAYER_SPEED ;
    float x;
    float PreviousX;
    float PreviousY;
    float y;
    Player();
    unsigned short heartscnt = 3;
    std::vector<sf::Sprite> heartsVect;
    void draw(sf::RenderWindow& i_window);
    void update(std::vector<std::vector<int>> *Map,bool* finishedLevel,unsigned short* Level,bool *failedLevel,std::vector<sf::Rect<float>> batsPos);
    void reset(sf::Vector2f ResetPosition);
    sf::Vector2f getPlayerPos();

private:

    sf::Texture heartText;
    sf::Texture damagedheartText;
    sf::Sprite damagedheartSp;
    sf::Sprite heartSp;

    sf::Vector2f checkPoint;
    bool canMove;
    bool speedboost;
    bool swordman;
    unsigned short invincible_timer;
    float speedboostTimer;
    float coincollectingTimer;
    float walkanimationtimer;
    float standinanimtimer;

};

#endif // PLAYER_HPP

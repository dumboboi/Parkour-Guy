#include <array>
#include <iostream>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>
//-----------------------------
#include "General.hpp"
#include "Player.hpp"
#include "DrawMap.hpp"
#include "Collider.hpp"
Player::Player():
    x(CELL_SIZE*SCREEN_RESIZE-1),
    y(CELL_SIZE*SCREEN_RESIZE-1),
    playerStandingView('L'),
    vertical_speed(0),
    PLAYER_SPEED(Mapman.getLevelSpeed(1)),
    horizontal_speed(0),
    jumping_time(164),
    invincible_timer(200),
    speedboostTimer(600),
    jumpingCountdown(300),
    coincollectingTimer(200),
    standinanimtimer(300),
    invincible(0),
    walking(0),
    canMove(1),
    checkPoint(-1,-1),
    isJumping(0),
    speedboost(0),
    OnGround(0),
    swordman(0),
    tookCoin(0),
    walkanimationtimer(300)
{
    heartSp = Loader.load_texture("resources/fullheart.png",heartText);
    damagedheartSp = Loader.load_texture("resources/damagedHeart.png",damagedheartText);
    heartSp.setScale(1,1);
    //inserting hearts
    for (int i = 0; i < 3 ; i++)
    {
        heartsVect.push_back(heartSp);
    }
    damagedheartSp.setScale(1,1);
    //inserting damaged hears
    for (int i = 0; i < 3 ; i++)
    {
        heartsVect.push_back(damagedheartSp);
    }
    texture.loadFromFile("resources/Idleplayer.png");
    tookCoin = 0;
    playerSrc.left = x ;
    playerSrc.top = y;
    playerSrc.width = 1;
    playerSrc.height = 1;
}

void Player::draw(sf::RenderWindow& i_window)
{
    playerSrc.left = x;
    playerSrc.top = y;
    if (OnGround == 1)
    {
        if (playerStandingView == 'R' )
        {
            if(walking == 0)
            {
                if(swordman)
                {
                    sprite= Loader.load_texture("resources/Idleplayerholdingsword.png",texture);
                }
                else
                {
                    sprite= Loader.load_texture("resources/Idleplayer.png",texture);
                }
                animation.standing_animation(&playerSrc,y,&standinanimtimer);
            }
            else
            {
                animation.walking_animation(sprite,texture,&walkanimationtimer,playerStandingView);
            }
        }
        else if (playerStandingView == 'L')
        {
            if(walking == 0)
            {
                if(swordman)
                {
                    sprite= Loader.load_texture("resources/IdleplayerholdingswordLeft.png",texture);
                }
                else
                {
                    sprite= Loader.load_texture("resources/playerLeft.png",texture);
                }
                if(standinanimtimer>=100)
                {
                    playerSrc.top = y;
                    standinanimtimer--;
                }
                else
                {
                    playerSrc.top -= 2;
                    standinanimtimer--;
                }
                if(standinanimtimer<=0)
                {
                    standinanimtimer = 300;
                }
            }
            else
            {
                animation.walking_animation(sprite,texture,&walkanimationtimer,playerStandingView);
            }
        }
    }
    else
    {
        if (playerStandingView == 'L')
        {
            if(swordman)
            {
                sprite=Loader.load_texture("resources/swordmanJumpLeft.png",texture);

            }
            else
            {
                sprite=Loader.load_texture("resources/playerJumpLeft.png",texture);
            }
        }
        else if (playerStandingView == 'R')
            if(swordman)
            {
                sprite=Loader.load_texture("resources/swordmanJump.png",texture);

            }
            else
            {
                sprite=Loader.load_texture("resources/playerJump.png",texture);
            }
    }
    Loader.draw_texture(i_window,sprite,playerSrc);
    heartsVect[0].setPosition(round(x)-10,y-CELL_SIZE*SCREEN_RESIZE);
    heartsVect[1].setPosition(x + 6,y-CELL_SIZE*SCREEN_RESIZE);
    heartsVect[2].setPosition(x+22,y-CELL_SIZE*SCREEN_RESIZE);
    //inserting damaged hears
    heartsVect[3].setPosition(round(x)-10,y-CELL_SIZE*SCREEN_RESIZE);
    heartsVect[4].setPosition(x + 6,y-CELL_SIZE*SCREEN_RESIZE);
    heartsVect[5].setPosition(x+22,y-CELL_SIZE*SCREEN_RESIZE);

    if(heartscnt==3)
    {
        i_window.draw(heartsVect[0]);
        i_window.draw(heartsVect[1]);
        i_window.draw(heartsVect[2]);
    }
    else if(heartscnt == 2 )
    {
        i_window.draw(heartsVect[3]);
        i_window.draw(heartsVect[1]);
        i_window.draw(heartsVect[2]);
    }
    else
    {
        i_window.draw(heartsVect[3]);
        i_window.draw(heartsVect[4]);
        i_window.draw(heartsVect[2]);
    }
}




void Player::update(std::vector<std::vector<int>> *Map,bool* finishedLevel,unsigned short* Level,bool *failedLevel,std::vector<sf::Rect<float>> batsPos)
{


    //check for level(updates/teleportations/...)
    switch(*Level)
    {
    case 1:
    {
        //Teleport_block
        if ((x>=FULL_SCREEN_WIDTH-35) && ((y>=SCREEN_RESIZE * CELL_SIZE*4)&&(y<=SCREEN_RESIZE * CELL_SIZE *6)))
        {
            x = CELL_SIZE * SCREEN_RESIZE + 1.5f;
            y = FULL_SCREEN_HEIGHT - 58;
        }
        //Teleport_back
        if((x <= CELL_SIZE * SCREEN_RESIZE -29) && (y >= CELL_SIZE * SCREEN_RESIZE *16)&&(y<= CELL_SIZE * SCREEN_RESIZE*18))
        {
            x = FULL_SCREEN_WIDTH - 65;
            y = (SCREEN_RESIZE * CELL_SIZE * 5) - 0.2f;
        }

        //---
        //finished level
        if (tookCoin ==  1 && x <= CELL_SIZE * SCREEN_RESIZE -29 && y >= CELL_SIZE * SCREEN_RESIZE *11&&y<= CELL_SIZE * SCREEN_RESIZE*13)
        {
            *finishedLevel = 1;
            PLAYER_SPEED = Mapman.getLevelSpeed(*Level+1);
            tookCoin = 0;
            checkPoint.x = -1;
            checkPoint.y = -1;
        }
        break;
    }
    case 2:
    {
        if (tookCoin ==  1 && (x >= FULL_SCREEN_WIDTH -80) && y >=SCREEN_RESIZE * CELL_SIZE&& y <= (SCREEN_RESIZE * CELL_SIZE * 2))
        {
            *finishedLevel = 1;
            PLAYER_SPEED = Mapman.getLevelSpeed(*Level+1);
            tookCoin = 0;
            checkPoint.x = -1;
            checkPoint.y = -1;
        }
        //getting checkpoints
        if(y>= FULL_SCREEN_HEIGHT / 2 && tookCoin == 1)
        {
            checkPoint.x = (FULL_SCREEN_WIDTH / 2) +15;
            checkPoint.y = (FULL_SCREEN_HEIGHT - (SCREEN_RESIZE * CELL_SIZE * 3)) - 30;
        }

        else if(y>= FULL_SCREEN_HEIGHT / 2)
        {
            checkPoint.x = SCREEN_RESIZE * CELL_SIZE ;
            checkPoint.y = FULL_SCREEN_HEIGHT /2 - (CELL_SIZE * SCREEN_RESIZE * 3);
        }

        break;
    }
    case 3:
    {
        //finished level3
        if (tookCoin ==  1 && (x >= FULL_SCREEN_WIDTH -80) && y >=SCREEN_RESIZE * CELL_SIZE&& y <= (SCREEN_RESIZE * CELL_SIZE * 2))
        {
            *finishedLevel = 1;
            PLAYER_SPEED = Mapman.getLevelSpeed(1);
            tookCoin = 0;
            *Level = 0;
        }
        //collision with boots / SPEED BOOST
        if(tookCoin == 0 && collision_with_tools_boosts(x,y,*Map, {14}) == 1 )
        {
            (*Map)[6][1] = 0;
            speedboost = 1;
            PLAYER_SPEED += 0.1f;

        }
        //------------//
        //test collision with bats
        for (int i = 0; i < batsPos.size(); i++)
        {
            if (collision_between_player_bats(x,y,batsPos[i].left,batsPos[i].top)==1 && invincible == 0)
            {
                heartscnt--;
                if (checkPoint.x == -1)
                {
                    reset(Mapman.getStartingPosition(*Level));
                }
                else
                {
                    reset(checkPoint);
                }
                MapUpdater.ResetMap(*Level,Map);
                invincible = 1;
                swordman = 0;
                (*Map)[2][12] = 13;
            }
        }
        //check if took a sword
        if (collision_with_tools_boosts(x,y,*Map, {13}) == 1)
        {
            (*Map)[2][12] = 0;
            swordman = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) == 1)
        {
            (*Map)[6][1] = 14;
        }
        //open chest
        if ( collision_with_doors_treasures(x,y,*Map, {16})==1 &&  sf::Keyboard::isKeyPressed(sf::Keyboard::Space)==1 && swordman == 1)
        {
            (*Map)[6][16] =  8;
            swordman = 0;
        }
        //getting checkpoints
        if(x>= CELL_SIZE * SCREEN_RESIZE * 12)
        {
            checkPoint.x = CELL_SIZE * SCREEN_RESIZE * 12;
            checkPoint.y = CELL_SIZE * SCREEN_RESIZE * 2;
        }

        break;
    }
    }
    //collision with coins
    if (collision_with_coins_treasures(x,y,*Map, {8}) && tookCoin == 0)
    {
        coincollectingTimer--;
        if(coincollectingTimer==0)
        {
            MapUpdater.Updates_after_coin(*Level,Map);
            tookCoin = 1;
            coincollectingTimer = 200;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == 1 || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == 1 )
    {
        walking = 1;
    }
    else
    {
        walking = 0;
    }


    if(heartscnt == 0)
    {
        *failedLevel = 1;
        (*Level)--;
        MapUpdater.ResetMap(*Level,Map);
        reset(Mapman.getStartingPosition(*Level));
        PLAYER_SPEED = Mapman.getLevelSpeed(*Level);
        heartscnt = 3;
        canMove = 0;
        checkPoint.x = -1;
        checkPoint.y = -1;
        swordman = 0;
        return;
    }
    if(collision_with_doors_treasures(x,y,*Map, {5}))
    {
        x = Mapman.getStartingPosition(*Level).x;
    }
    PreviousX  = x;
    PreviousY  = y;
    if (1 ==  sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && canMove == 1)
    {
        x = std::max<float>(0,x-PLAYER_SPEED);
        horizontal_speed = PLAYER_SPEED;
        playerStandingView = 'L';
    }
    else
    {
        horizontal_speed = 0;
    }
    if(1 ==  sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& canMove == 1)
    {
        playerStandingView = 'R';
        x = std::min<float>(x + PLAYER_SPEED,FULL_SCREEN_WIDTH - 20);
    }
    else
    {
        horizontal_speed = 0;
    }
    //Jumping
    if (jumping_time<=0 && jumpingCountdown <=0)
    {
        isJumping = 0;
        jumping_time = 164;
        jumpingCountdown = 300;
    }
    if (isJumping == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == 1 && OnGround == 1)
    {
        isJumping = 1;
        vertical_speed = 0;
    }
    else
    {
        vertical_speed = std::min<float>(Gravity + vertical_speed, MIN_VERTICAL_SPEED);

    }

    if (isJumping == 1)
    {
        if (jumping_time>=0)
        {
            y+=JUMP_SPEED;
            jumping_time--;
        }
        else
        {
            y+=vertical_speed;

        }
        jumpingCountdown--;
    }
    else
    {
        y+=vertical_speed;
    }
    //-----
    //Speed boost
    if (speedboost == 1 && speedboostTimer>0)
    {
        speedboostTimer--;
    }
    if (speedboostTimer == 0)
    {
        speedboost = 0;
        speedboostTimer = 600;
        PLAYER_SPEED = Mapman.getLevelSpeed(*Level);
    }
    //collision checking:
    //collision for ground
    if (map_vertical_collision(x,y+vertical_speed,*Map, {1, 2, 4,  5,  6, 10, 12}) == 1)
    {
        vertical_speed = 0;
        OnGround = 1;
    }
    else
    {
        vertical_speed = std::min<float>(Gravity + vertical_speed, MAX_VERTICAL_SPEED);
        OnGround = 0;
    }
    //collision for walls on the left and the right
    if (map_horizontal_collision(x +0.7f,y,*Map, {1,2,4,5,6,10,12}) == 1 || map_horizontal_collision(x -0.7,y,*Map, {1,2,4,5,6,10,12}) == 1)
    {

        x = PreviousX;
    }
    //collision for the ceiling
    if (map_vertical_collision(x,y-0.7f,*Map, {1, 2, 4,  5,  6, 10, 12})==1)
    {
        y = PreviousY;
    }
    //checking collision for walls mid air
    if(vertical_collision_with_obstacles(x + 0.7f, y,*Map, { 4,12}) == 1)
    {
        horizontal_speed = 0;
        x--;

    }
    if(vertical_collision_with_obstacles(x - 0.7f, y,*Map, { 4,12}) == 1)
    {
        horizontal_speed = 0;
        x++;
    }
    if (y<=CELL_SIZE * SCREEN_RESIZE-2)
    {
        y = PreviousY;
    }
    //collision with lava_roots
    if (collision_with_lava_roots(x,y,*Map) == 1)
    {
        MapUpdater.ResetMap(*Level,Map);
        tookCoin = 0;
        invincible = 1;
        swordman = 0;
        heartscnt--;
        if (checkPoint.x == -1)
        {
            reset(Mapman.getStartingPosition(*Level));
        }
        else
        {
            reset(checkPoint);
        }
    }
    //players gets invincible after dying to a bat for a second == unable to move
    if(invincible_timer>0 && invincible == 1)
    {
        invincible_timer--;
    }
    if(invincible_timer == 0)
    {
        invincible = 0;
        invincible_timer = 200;
    }

    if (invincible == 1)
    {
        canMove = 0;
    }
    else
    {
        canMove = 1;
    }


}
void Player::reset(sf::Vector2f ResetPosition)
{
    x = ResetPosition.x;
    y = ResetPosition.y;
}

sf::Vector2f Player::getPlayerPos()
{
    sf::Vector2f pos;
    pos.x = x;
    pos.y = y;
    return pos;
}

#include <DrawMap.hpp>
#include <LoadTextures.hpp>
#include <General.hpp>
#include <MapsManager.hpp>


DrawMap::DrawMap():
    x(0),
    y(0),
    startingTime(300),
    updatesLoaded(0),
    rank2flyright(0),
    updatingtimer(600)
{
    caverootSp = textLoad.load_texture("resources/roots.png",caveroot);
    DarkStoneSp = textLoad.load_texture("resources/darkStoneBlock.png",darkstone);
    deepDarkStoneSp = textLoad.load_texture("resources/deepdarkStoneBlock.png",deepdarkstone);
    SandBlockSp = textLoad.load_texture("resources/sandBlock.png",sandblock);
    CaveBlockSp = textLoad.load_texture("resources/caveBlock.png",caveblock);
    LeavesBlockSp = textLoad.load_texture("resources/leavesBlock.png",leavesblock);
    coinSp = textLoad.load_texture("resources/coin.png",coin);
    portalSp = textLoad.load_texture("resources/portalBlock.png",portal);
    lowerLavaSp = textLoad.load_texture("resources/lowerLava.png",lowerLava);
    upperLavaSp = textLoad.load_texture("resources/upperLava.png",upperLava);
    swordSp = textLoad.load_texture("resources/sword.png",sword);
    batSp = textLoad.load_texture("resources/bat.png",battext);
    rank2batSp = textLoad.load_texture("resources/bat.png",rank2battext);
    speedboostSp = textLoad.load_texture("resources/speedboost.png",speedboost);
    caveleaveSp = textLoad.load_texture("resources/caveleaves.png",caveleave);
    chestSp = textLoad.load_texture("resources/chest.png",chest);
    LoadMap(Mpman.lvl1);
    src.left = src.top = 0;
    src.width = src.height = batsrc .width = batsrc.height = 1 ;


}
void DrawMap::LoadMap(std::vector<std::vector<int>> lvlvect)
{
    Map.clear();
    for (int row = 0; row < 19; row++)
    {
        std::vector<int> tempCells;
        for (int coll = 0; coll < 25; coll++)
        {
            tempCells.push_back(lvlvect[row][coll]);
        }
        Map.push_back(tempCells);
    }

}

void DrawMap::RemoveEntities(unsigned short Level)
{
    switch(Level)
    {
    case 1:
    {
        break;
    }
    case 2:
    {
        break;
    }
    case 3:
    {
        Bats.clear();
        BatsPos.clear();
    }
    }
}


void DrawMap::Update(unsigned short Level)
{
    if(startingTime>0)
    {
        startingTime--;
    }
    if (startingTime<=0 && !updatesLoaded)
    {
        switch(Level)
        {
        case 1:
        {
            Map[1][2] = 0;
            Map[2][2] = 0;
            break;
        }
        case 2:
        {
            Map[1][22] = 0;
            Map[2][22] = 0;
            break;
        }
        case 3:
        {
            Map[1][3] = 0;
            Map[1][4] = 0;
            Map[1][5] = 0;
            Map[2][3] = 0;
            Map[3][3] = 0;
            Map[4][3] = 0;
            Map[4][3] = 0;
            Map[2][5] = 0;
            Map[3][5] = 0;
            Map[4][5] = 0;
            Map[4][5] = 0;
            break;
        }
        }
        updatesLoaded = 1;
    }
    switch(Level)
    {
    case 3:
    {
        if (updatingtimer==600)
        {
            Map[15][4] = 12;
            Map[13][17] = 12;
            Map[12][21] = 0 ;
            Map[10][23] = 12;
        }
        else if(updatingtimer == 0)
        {
            Map[15][4] =0;
            Map[13][17] = 0;
            Map[12][21] = 12;
            Map[10][23] = 0;

        }
        if (updatingtimer> -800)
        {
            updatingtimer--;
        }
        if (updatingtimer <= -800)
        {
            updatingtimer = 600;
        }


    }

    }
}

void DrawMap::Load_Map_Entities(unsigned short Level)
{
    switch(Level)
    {
    case 3:
    {
        for (int i = 0 ; i < 4; i++)
        {
            Bats.push_back(batSp);
        }
        batsrc.left = (SCREEN_RESIZE * CELL_SIZE * 6) +3;
        batsrc.top = ((SCREEN_RESIZE * CELL_SIZE) +3);
        BatsPos.push_back(batsrc);
        batsrc.top = ((SCREEN_RESIZE * CELL_SIZE) +7) *5 ;
        BatsPos.push_back(batsrc);
        batsrc.left = (SCREEN_RESIZE * CELL_SIZE * 11) +3;
        batsrc.top = ((SCREEN_RESIZE * CELL_SIZE) +3)*10;
        BatsPos.push_back(batsrc);
        batsrc.top = ((SCREEN_RESIZE * CELL_SIZE) +3)*3 - 11;
        BatsPos.push_back(batsrc);
        break;
    }
    }
}

void DrawMap::Draw_Entities(sf::RenderWindow& i_window,unsigned short Level)
{
    switch(Level)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
    {
        for (int i = 0; i < 2; i++)
        {
            if (BatsPos[i].left>=(SCREEN_RESIZE * CELL_SIZE * 6) +3)
            {
                flyright = false;
                Bats[i] = textLoad.load_texture("resources/bat.png",battext);
            }
            else if (BatsPos[i].left <= SCREEN_RESIZE  * CELL_SIZE-3)
            {
                flyright = true;
                Bats[i] = textLoad.load_texture("resources/batflyingright.png",battext);

            }
            if (flyright == 0)
            {
                BatsPos[i].left-=batflyingspeed;
            }
            else
            {
                BatsPos[i].left+=batflyingspeed;
            }
            textLoad.draw_texture(i_window,Bats[i],BatsPos[i]);
        }
        //rank2 bats
        for (int i = 2 ; i < 4; i++)
        {
            if (BatsPos[i].left>=(SCREEN_RESIZE * CELL_SIZE * 11) +3)
            {
                rank2flyright = 0;
                Bats[i] = textLoad.load_texture("resources/bat.png",rank2battext);
            }
            else if (BatsPos[i].left <= (SCREEN_RESIZE  * CELL_SIZE+3) * 7)
            {
                rank2flyright = 1;
                Bats[i]= textLoad.load_texture("resources/batflyingright.png",rank2battext);

            }
            if (rank2flyright == 0)
            {
                BatsPos[i].left-=batflyingspeed*0.5f;
            }
            else
            {
                BatsPos[i].left+=batflyingspeed*0.5f;
            }
            textLoad.draw_texture(i_window,Bats[i],BatsPos[i]);

        }
        break;
    }
    }

}

void DrawMap::Draw(sf::RenderWindow& i_window)
{
    int type = 0;
    for (int row = 0; row < 19; row++)
    {
        for (int coll = 0; coll < 25 ; coll++)
        {
            src.left = coll*CELL_SIZE * SCREEN_RESIZE;
            src.top = row *CELL_SIZE * SCREEN_RESIZE;
            type = Map[row][coll];
            switch(type)
            {
            case 3:
            {
                textLoad.draw_texture(i_window,caverootSp,src);
                break;
            }
            case 4:
            {
                textLoad.draw_texture(i_window,DarkStoneSp,src);
                break;
            }
            case 5:
            {
                textLoad.draw_texture(i_window,SandBlockSp,src);
                break;
            }
            case 6:
            {
                textLoad.draw_texture(i_window,CaveBlockSp,src);
                break;
            }
            case 7:
            {
                textLoad.draw_texture(i_window,LeavesBlockSp,src);
                break;
            }
            case 8:
            {
                textLoad.draw_texture(i_window,coinSp,src);
                break;
            }
            case 9:
            {
                textLoad.draw_texture(i_window,portalSp,src);
                break;
            }
            case 10:
            {
                textLoad.draw_texture(i_window,lowerLavaSp,src);
                break;
            }
            case 11:
            {
                textLoad.draw_texture(i_window,upperLavaSp,src);
                break;
            }
            case 12:
            {
                textLoad.draw_texture(i_window,deepDarkStoneSp,src);
                break;
            }
            case 13:
            {
                textLoad.draw_texture(i_window,swordSp,src);
                break;
            }
            case 14:
            {
                textLoad.draw_texture(i_window,speedboostSp,src);
                break;
            }
            case 15:
            {
                textLoad.draw_texture(i_window,caveleaveSp,src);
                break;
            }
            case 16:
            {
                textLoad.draw_texture(i_window,chestSp,src);
                break;
            }
            }

        }
    }
}

void DrawMap::Updates_after_coin(unsigned short Level,std::vector<std::vector<int>>* Maplevel)
{
    switch(Level)
    {
    case 1:
    {
        (*Maplevel)[16][12] = 0;
        (*Maplevel)[12][0] = 9;
        (*Maplevel)[11][0] = 9;
        break;
    }
    case 2:
    {
        (*Maplevel)[15][23] = 0 ;
        (*Maplevel)[1][23] = 9;
        (*Maplevel)[2][23] = 9;
        (*Maplevel)[8][4] = 4;
        (*Maplevel)[7][7] = 4;
        (*Maplevel)[4][5] = 0;
        (*Maplevel)[5][5] = 0;
        (*Maplevel)[7][5] = 0;
        (*Maplevel)[5][4] = 0;
        (*Maplevel)[5][7] = 0;
        (*Maplevel)[5][8] = 0;
        (*Maplevel)[6][6] = 0;
        break;
    }
    case 3:
    {
        (*Maplevel)[6][16]=0;
        (*Maplevel)[1][23]=9;
        (*Maplevel)[2][23]=9;
        break;
    }
    }
}
void DrawMap::ResetMap(unsigned short Level,std::vector<std::vector<int>>* Maplevel)
{
    switch(Level)
    {
    case 1:
    {
        (*Maplevel)[17][12] = 8;
        (*Maplevel)[11][0] = 4;
        (*Maplevel)[12][0] = 4;
        (*Maplevel)[1][2] = 5;
        (*Maplevel)[2][2] = 5;
        break;
    }
    case 2:
    {
        (*Maplevel)[1][23] = 0;
        (*Maplevel)[2][23] = 0;
        (*Maplevel)[15][23] = 8;
        (*Maplevel)[8][4] = 0;
        (*Maplevel)[7][7] = 0;
        (*Maplevel)[5][5] = 3;
        (*Maplevel)[5][4] = 3;
        (*Maplevel)[7][5] = 3;
        (*Maplevel)[5][7] = 3;
        (*Maplevel)[5][8] = 3;
        (*Maplevel)[6][6] = 3;
        break;
    }
    case 3:
    {
        (*Maplevel)[2][12] = 13;
        (*Maplevel)[6][1] = 14;
        (*Maplevel)[6][16] = 16;
        (*Maplevel)[1][23]=0;
        (*Maplevel)[2][23]=0;
        break;
    }
    }
}

std::vector<std::vector<int>>* DrawMap::getMap()
{
    return &Map;
}

std::vector<sf::Rect<float>> DrawMap::getBatPos()
{
    return BatsPos;
}


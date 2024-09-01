#pragma once
#include"SnakeTile.h"
#include<vector>
#include"Position.h"
const int MOVING_SPEED = 5;
const int SNAKE_TILE_WIDTH= 10;
const int SNAKE_TILE_HEIGHT= 10;
class Snake
{
public:
    bool IS_VERTICAL=true;
    bool IS_HORIZONTAL=false;
    Snake()
    {   
        Head= SnakeTile(400,400,SNAKE_TILE_WIDTH,SNAKE_TILE_HEIGHT,nullptr);
        SnakeTiles.push_back(SnakeTile(400,Head.getY()+SNAKE_TILE_HEIGHT,SNAKE_TILE_WIDTH,SNAKE_TILE_HEIGHT,NULL));
        SnakeTiles.push_back(SnakeTile(400,SnakeTiles[0].getY()+SNAKE_TILE_HEIGHT,SNAKE_TILE_WIDTH,SNAKE_TILE_HEIGHT,NULL));
        SnakeTiles.push_back(SnakeTile(400,SnakeTiles[1].getY()+SNAKE_TILE_HEIGHT,SNAKE_TILE_WIDTH,SNAKE_TILE_HEIGHT,NULL));
        SnakeTiles.push_back(SnakeTile(400,SnakeTiles[2].getY()+SNAKE_TILE_HEIGHT,SNAKE_TILE_WIDTH,SNAKE_TILE_HEIGHT,NULL));
    }
    std::vector<SnakeTile> getSnakeTiles()
    {
        return SnakeTiles;
    }
    void HandleInput(SDL_Event event)
    {
        if(event.type == SDL_KEYDOWN)
        { 
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
                    if(IS_VERTICAL)
                    {
                        IS_HORIZONTAL=true;
                        IS_VERTICAL=false;
                        Head.setAxis(-1,0);
                        addTwists();
                    } 
                    break;
                case SDLK_d:
                    if(IS_VERTICAL)
                    {
                        IS_HORIZONTAL=true;
                        IS_VERTICAL=false;
                        Head.setAxis(1,0);
                        addTwists();
                    }
                    break;
                case SDLK_w:
                    if(IS_HORIZONTAL)
                    {
                        IS_HORIZONTAL=false;
                        IS_VERTICAL=true;
                        Head.setAxis(0,-1);
                        addTwists();
                    }
                    break;
                case SDLK_s:
                    if(IS_HORIZONTAL)
                    {
                        IS_HORIZONTAL=false;
                        IS_VERTICAL=true;
                        Head.setAxis(0,1);
                        addTwists();
                    }
                    break;
            }    
        }
    }
    void addTwists()
    {
        Twists.push_back(TwistPosition(Head.getX(),Head.getY(),Head.getHorizontalAxis(),Head.getVerticalAxis()));
    }
    void render(SDL_Renderer*renderer)
    {
        SDL_SetRenderDrawColor(renderer,255,0,0,0);
        SDL_RenderFillRect(renderer,&Head.getCollision());
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        for(int i=0;i<SnakeTiles.size();i++)
        {
            SDL_RenderFillRect(renderer, &SnakeTiles[i].getCollision());
        }
    }
    void Update()
    {
        Head.changeX(MOVING_SPEED*Head.getHorizontalAxis());
        Head.changeY(MOVING_SPEED*Head.getVerticalAxis());
        for(int i=0;i<SnakeTiles.size();i++)
        {
            SnakeTiles[i].changeX(MOVING_SPEED*SnakeTiles[i].getHorizontalAxis());
            SnakeTiles[i].changeY(MOVING_SPEED*SnakeTiles[i].getVerticalAxis());
            if(!Twists.empty())
            {
                if(SnakeTiles[i].getX() == Twists[0].x && SnakeTiles[i].getY() == Twists[0].y)
                {
                    SnakeTiles[i].setAxis(Twists[0].Horizontal,Twists[0].Vertical);
                    if(i== SnakeTiles.size()-1)Twists.erase(Twists.begin());
                }
            }
        }
    }
    SnakeTile getHead()
    {
        return Head;
    }
private:
    std::vector<SnakeTile> SnakeTiles;
    std::vector<TwistPosition>Twists;
    SnakeTile Head;
};
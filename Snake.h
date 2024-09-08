#pragma once
#include"SnakeTile.h"
#include<vector>
#include"Position.h"
const int MOVING_SPEED = 10;
const int SNAKE_TILE_WIDTH= 10;
const int SNAKE_TILE_HEIGHT= 10;
class Snake
{
public:
    bool IS_HORIZONTAL=false;
    Snake()
    {   
        Head= SnakeTile(600,350,SNAKE_TILE_WIDTH,SNAKE_TILE_HEIGHT,nullptr);
        SnakeTiles.push_back(SnakeTile(Head.getX(),Head.getY(),SNAKE_TILE_WIDTH,SNAKE_TILE_HEIGHT,nullptr));
        for(int i=1;i<3;i++)
        {
            SnakeTiles.push_back(SnakeTile(SnakeTiles[i-1].getX(),SnakeTiles[i-1].getY(),SNAKE_TILE_HEIGHT,SNAKE_TILE_WIDTH,nullptr));
        }
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
                    if(!IS_HORIZONTAL)
                    {
                        IS_HORIZONTAL=true;
                        Head.setAxis(-1,0);
                    }
                    break;
                case SDLK_d:
                    if(!IS_HORIZONTAL)
                    {
                        IS_HORIZONTAL=true;
                        Head.setAxis(1,0);
                    }
                    break;
                case SDLK_w:
                    if(IS_HORIZONTAL)
                    {
                        IS_HORIZONTAL=false;
                        Head.setAxis(0,-1);
                    }
                    break;
                case SDLK_s:
                    if(IS_HORIZONTAL)
                    {
                        IS_HORIZONTAL=false;
                        Head.setAxis(0,1);
                    }
                    break;
            }    
        }
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
        for(int i=SnakeTiles.size()-1;i>=0;i--)
        {
            if(i==0)
            {
                SnakeTiles[i].setPos(Head.getX(),Head.getY());
            }
            else
            {
                SnakeTiles[i].setPos(SnakeTiles[i-1].getX(),SnakeTiles[i-1].getY());
            }
        }
        Head.changeX(MOVING_SPEED*Head.getHorizontalAxis());
        Head.changeY(MOVING_SPEED*Head.getVerticalAxis());
    }
    SnakeTile getHead()
    {
        return Head;
    }
private:
    std::vector<SnakeTile> SnakeTiles;
    SnakeTile Head;
};
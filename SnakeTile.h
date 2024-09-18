#ifndef SNAKE_TILE_H
#define SNAKE_TILE_H
#pragma once
#include<SDL.h>
class SnakeTile
{
public:
    SnakeTile(int pX,int pY,int W,int H,SDL_Texture*tex)
    {
        Collision.x=pX;
        Collision.y=pY;
        Collision.w=W;Collision.h=H;
        Horizontal=0;
        Vertical=-1;
    }
    SnakeTile()
    {

    }
    SDL_Rect& getCollision()
    {
        return Collision;
    }
    void changeX(int x)
    {
        Collision.x+=x;
        if(Collision.x >= 1200) Collision.x=0;
        else if(Collision.x <= 0) Collision.x=1200;
    }
    void changeY(int x)
    {
        Collision.y+= x;
        if(Collision.y >= 700 ) Collision.y=0;
        else if (Collision.y <= 0) Collision.y=700;
    }
    int getX() 
    {
        return Collision.x;
    }
    int getY() 
    {
        return Collision.y;
    }
    void setPos(int x,int y)
    {
        Collision.x=x;
        Collision.y=y;
    }
    int getHorizontalAxis()
    {
        return Horizontal;
    }
    int getVerticalAxis()
    {
        return Vertical;
    }
    void setAxis( int horizontal, int vertical)
    {
        this->Horizontal=horizontal;
        this->Vertical=vertical;
    }
    SDL_Texture*getTex() {return snakeTex;}; 
private:
    SDL_Rect Collision;
    int Horizontal;
    int Vertical;
    SDL_Texture* snakeTex;
};
#endif
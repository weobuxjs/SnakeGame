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
        preHorizontal=0;
        preVertical =-1;
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
        if(Collision.x > 1199) Collision.x=1;
        else if(Collision.x < 1) Collision.x=1199;
    }
    void changeY(int x)
    {
        Collision.y+= x;
        if(Collision.y > 699 ) Collision.y=1;
        else if (Collision.y < 1) Collision.y=699;
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
    int getPreHorizontalAxis()
    {
        return preHorizontal;
    }
    int getPreVerticalAxis()
    {
        return preVertical;
    }
    void swap()
    {
        preVertical = Vertical;
        preHorizontal = Horizontal;
    }
    void setAxis( int horizontal, int vertical)
    {
        preHorizontal = Horizontal;
        preVertical =Vertical;
        Horizontal=horizontal;
        Vertical=vertical;
    }
    SDL_Texture*getTex() {return snakeTex;}; 
private:
    SDL_Rect Collision;
    int Horizontal;
    int Vertical;
    int preHorizontal;
    int preVertical;
    SDL_Texture* snakeTex;
};
#endif
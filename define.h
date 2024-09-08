#pragma once 
#include<SDL.h>
#include"Snake.h"
#include"Food.h"
#include<iostream>
#include<cstdlib>
#include"FPScounter.h"
SDL_Window*window= SDL_CreateWindow("SNAKE GAME",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1200,700,SDL_WINDOW_SHOWN);
SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
SDL_Event event;
bool isRunning=true;
Snake mainSnake;
Food mainFood(rand()%1200 , rand() %700, 7,7,nullptr);
FPScounter mainCounter(SDL_GetTicks());
bool CheckCollsion(SDL_Rect a, SDL_Rect b)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    if( bottomA <= topB )
    {
        return false;
    }
    if( topA >= bottomB )
    {
        return false;
    }
    if( rightA <= leftB )
    {
        return false;
    }
    if( leftA >= rightB )
    {
        return false;
    }
    return true;
}
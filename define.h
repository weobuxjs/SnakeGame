#pragma once 
#include<SDL.h>
#include"Snake.h"
#include"Food.h"
#include<iostream>
#include<cstdlib>
SDL_Window*window= SDL_CreateWindow("SNAKE GAME",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1200,700,SDL_WINDOW_SHOWN);
SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
SDL_Event event;
bool isRunning=true;
Snake mainSnake;
Food mainFood(rand()%1200 , rand() %700, 7,7,nullptr);

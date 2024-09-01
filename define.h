#pragma once 
#include<SDL.h>
#include"Snake.h"
#include<iostream>
SDL_Window*window= SDL_CreateWindow("SNAKE GAME",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,800,800,SDL_WINDOW_SHOWN);
SDL_Renderer*renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
SDL_Event event;
bool isRunning=true;
Snake mainSnake;

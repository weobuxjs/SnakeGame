#ifndef GAME_H
#define GAME_H
#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"Snake.h"
#include"FPScounter.h"
#include"Food.h"
class Game
{
public:
    Game();
    bool CheckCollsion(SDL_Rect a, SDL_Rect b);
    void Update();
    void Render();
    void HandleInput();
    void ClearScreen();
    bool &getIsRunning();
    void quit();
    SDL_Event &getEvent(){return event;};
private:
    SDL_Window*window;
    SDL_Renderer*renderer;
    SDL_Event event;
    Snake mainSnake;
    FPScounter mainCounter;
    Food mainFood;
    Mix_Music* eatSound;
    bool isRunning;
};
#endif 
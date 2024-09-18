// #include "define.h"
#include"Game.h"
using namespace std;
int SDL_main(int argc, char*argv[])
{
    if((SDL_Init(SDL_INIT_EVERYTHING)< 0) || (Mix_OpenAudio(44100,AUDIO_S16SYS,2,2048)<0) || (TTF_Init() < 0))
    {
        printf("Error: %s",SDL_GetError());
        return 0;
    }
    Game mainGame;
    // Mix_Music*test=Mix_LoadMUS("assets/eatSound.mp3");
    // while(isRunning==true)
    // {
    //     while(SDL_PollEvent(&event))
    //     {
    //         if(event.type == SDL_QUIT) 
    //         {
    //             isRunning=false;
    //         }
    //          mainSnake.HandleInput(event);
    //     }
    //     SDL_SetRenderDrawColor(renderer,0,0,0,0);
    //     SDL_RenderClear(renderer);
    //     mainSnake.Update();
    //     mainSnake.render(renderer);
    //     if(CheckCollsion(mainSnake.getHead().getCollision(),mainFood.getCollision()))
    //     {
    //         Mix_PlayMusic(test,1);
    //         mainFood.getEaten();
    //         mainSnake.addTiles();
    //     }
    //     mainFood.render(renderer);
    //     SDL_RenderPresent(renderer);
    //     mainCounter.update();
    //     cout<<mainCounter.fps<<'\r';
    //     if(SDL_GetTicks() - mainCounter.time >= 1000 ) mainCounter.reset();
    // }
    while(mainGame.getIsRunning())
    {
        while(SDL_PollEvent(&mainGame.getEvent()))
        {
            if(mainGame.getEvent().type == SDL_QUIT)
            {
                mainGame.quit();
            }
            mainGame.HandleInput();
        }
        mainGame.ClearScreen();
        mainGame.Update();
        mainGame.Render();
    }
    SDL_Quit();
    return 0;
}
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
        SDL_Delay(16);
    }
    SDL_Quit();
    return 0;
}
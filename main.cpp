#include "define.h"
using namespace std;
int main(int argc, char*argv[])
{
    if(SDL_Init(SDL_INIT_GAMECONTROLLER)< 0)
    {
        cerr<<"Error: "<<SDL_GetError()<<endl;
        return 0;
    }
    if(Mix_OpenAudio(44100,AUDIO_S16SYS,2,2048)<0)
    {
        cerr<<"Error: "<<SDL_GetError()<<endl;
    }
    Mix_Music*test=Mix_LoadMUS("assets/eatSound.mp3");
    while(isRunning==true)
    {

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) 
            {
                isRunning=false;
            }
             mainSnake.HandleInput(event);
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,0);
        SDL_RenderClear(renderer);
        mainSnake.Update();
        mainSnake.render(renderer);
        if(CheckCollsion(mainSnake.getHead().getCollision(),mainFood.getCollision()))
        {
            Mix_PlayMusic(test,1);
            mainFood.getEaten();
            mainSnake.addTiles();
        }
        mainFood.render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(19);
        mainCounter.update();
        if(SDL_GetTicks() - mainCounter.time >= 1000 )mainCounter.reset();
    }
    SDL_Quit();
    return 0;
}
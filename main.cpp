#include "define.h"
using namespace std;
int main(int argc, char*argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
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
            mainFood.getEaten();
            mainSnake.addTiles();
        }
        mainFood.render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(19);
        mainCounter.update();
        cout<<mainCounter.fps<<endl;
        if(SDL_GetTicks() - mainCounter.time >= 1000 )mainCounter.reset();
    }
    SDL_Quit();
    return 0;
}
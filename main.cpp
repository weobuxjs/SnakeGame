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
        mainFood.render(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(19);
    }
    SDL_Quit();
    return 0;
}
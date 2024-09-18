#include"Game.h"
Game::Game()
{
    window= SDL_CreateWindow("SNAKE GAME",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1200,700,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    mainFood= Food(rand()%1200 , rand() %700, 7,7,nullptr);
    eatSound=Mix_LoadMUS("assets/eatSound.mp3");
    isRunning = true;
}
void Game::ClearScreen()
{
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
}
bool Game::CheckCollsion(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    if( bottomA <= topB ) return false;
    if( topA >= bottomB ) return false;
    if( rightA <= leftB ) return false;
    if( leftA >= rightB ) return false;
    return true;
}
void Game::HandleInput()
{
    mainSnake.HandleInput(event);
}
bool &Game::getIsRunning()
{
    return isRunning;
}
void Game::Update()
{
    mainSnake.Update();
    if(CheckCollsion(mainSnake.getHead().getCollision(), mainFood.getCollision()))
    {
        mainFood.getEaten();
        mainSnake.addTiles();
        Mix_PlayMusic(eatSound,1);
    }     
}
void Game::Render()
{
    mainSnake.render(renderer);
    mainFood.render(renderer);
    SDL_RenderPresent(renderer);
    mainCounter.update();
    if(SDL_GetTicks() - mainCounter.time >= 1000 )
    {
        mainCounter.reset();
    }
    printf("%f\r",mainCounter.fps);
}
void Game::quit()
{
    isRunning = false;
}
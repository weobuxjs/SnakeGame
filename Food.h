#include<SDL.h>
class Food
{
public:
    Food(int pX,int pY,int w,int h, SDL_Texture*tex)
    {
        Collision.x=pX;
        Collision.y=pY;
        Collision.w=w;
        Collision.h=h;
        tex=Tex;
        lastTick=0;
    }
    SDL_Rect& getCollision()
    {
        return Collision;
    }
    SDL_Texture*getTex()
    {
        return Tex;
    }
    void isEaten()
    {
        Collision.x = rand()%1200;
        Collision.y = rand()% 700;
    }
    bool IsOnCoolDown()
    {
        return SDL_GetTicks()- lastTick <600;
    }
    void render(SDL_Renderer*renderer)
    {
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        if(!IsOnCoolDown()) 
        {
            SDL_RenderFillRect(renderer,&Collision);
            times++;
            if(times == 50 )
            {
                times=0;
                lastTick=SDL_GetTicks();
            }
        }
    }
private:
    SDL_Rect Collision;
    SDL_Texture*Tex;
    int lastTick;
    int times=0;
};
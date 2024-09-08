#include<SDL.h>
struct FPScounter
{
    double time;
    double frame=0;
    double fps;
    FPScounter(int t)
    {
        time = t;
    }
    void reset()
    {
        frame=0;
        time=SDL_GetTicks();
    }
    void update()
    {
        frame++;
        fps= double(frame/((SDL_GetTicks()- time)/1000.f));
    }
};
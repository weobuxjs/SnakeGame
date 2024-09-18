#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H
#include<SDL.h>
struct FPScounter
{
    double time,fps;
    unsigned long long frame;
    FPScounter()
    {
        frame=0;
        time= SDL_GetTicks();
    }
    void reset()
    {
        frame = 0;
        time =SDL_GetTicks();
    }
    void update()
    {
        frame++;
        fps= frame/((SDL_GetTicks()- time) /1000);
    }
};
#endif
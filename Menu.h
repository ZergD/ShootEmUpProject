#pragma once
#include "State.h"
#include "SDL.h"
#include "Image.h"

class Menu : public State
{
public:
    Menu(ShootEmUp*);
    ~Menu(void);
    virtual void start();
    virtual void stop();
protected:
    ShootEmUp* shootEmUp;
    Image * image;
    SDL_Surface* img;
};


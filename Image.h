#pragma once
#include "DisplayObject.h"
#include "EngineManager.h"
#include "GraphicEngine.h"
#include "SDL.h"
#include "SDL_image.h"

class EngineManager;

class Image : public DisplayObject {


public:
    Image(EngineManager*,SDL_Surface*);
    Image(EngineManager*,SDL_Surface*, int, int);
    ~Image(void);

    void display();


protected:
    EngineManager* engineManager;
    SDL_Surface* sdl_surface;
    int positionX, positionY;
};

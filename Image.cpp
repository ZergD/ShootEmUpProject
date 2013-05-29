#include "Image.h"


Image::Image(EngineManager* engineManagerP,SDL_Surface* img){
    engineManager = engineManagerP;
    sdl_surface = img;
    engineManager->GetGraphicEngine()->addObject(this);
    positionX = 0, positionY = 0;
}

Image::Image(EngineManager* engineManagerP,SDL_Surface* img, int X, int Y){
    engineManager = engineManagerP;
    sdl_surface = img;
    engineManager->GetGraphicEngine()->addObject(this);
    positionX = X;
    positionY = Y;
}

Image::~Image(void){
    engineManager->GetGraphicEngine()->removeObject(this);
}

void Image::display(){
    engineManager->GetGraphicEngine()->displayImage(sdl_surface, positionX, positionY);
}

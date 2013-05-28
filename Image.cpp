#include "Image.h"


Image::Image(EngineManager* engineManagerP,SDL_Surface* img){
    engineManager = engineManagerP;
    sdl_surface = img;
    engineManager->GetGraphicEngine()->addObject(this);
}

Image::~Image(void){
    engineManager->GetGraphicEngine()->removeObject(this);
}

void Image::display(){
    engineManager->GetGraphicEngine()->displayImage(sdl_surface, 0, 0);
}

#include "Curseur.h"
#include "EngineManager.h"
#include "ShootEmUp.h"
#include "StateManager.h"

//SDL_Surface *image3 =NULL;
int Curseur::difficulty=7;


Curseur::Curseur(EngineManager* engineManagerP) {
/*  positionX = 60; positionY = 100;
    pas = 50;
*/
    engineManager = engineManagerP;
    moveCursorLeft = false;
    moveCursorRight = false;
    moveCursorDown = false;
    moveCursorUp = false;
    pressEnter = false;
    pressSpaceBar = false;
    pressEscape = false;
    engineManager->GetGraphicEngine()->addObject(this);
    engineManager->GetStateEngine()->addComputeObject(this);
    engineManager->GetInputEngine()->addInputObject(this);
    ligneNum=0;

/*    image3 = SDL_LoadBMP("Images/curseurTRANSPARENT.bmp");
    SDL_SetColorKey(image3, SDL_SRCCOLORKEY, SDL_MapRGB(image3->format, 0, 0, 255)); //on gere la transparence du curseur
    //le curseur a le fond de son image colorier en bleu 0, 0, 255. Cette fonction rend le bleu invisible
*/
}


Curseur::~Curseur(void)
{
    engineManager->GetGraphicEngine()->removeObject(this);
	engineManager->GetStateEngine()->removeComputeObject(this);
    engineManager->GetInputEngine()->removeInputObject(this);
    SDL_FreeSurface(image3);
}

void Curseur::process(SDL_Event event) {
    /* switch pour savoir quelle touche est appuyée */
    switch (event.key.keysym.sym)
    {
        case SDLK_LEFT :
        moveCursorLeft = event.type == SDL_KEYDOWN;
                break;
        case SDLK_RIGHT :
        moveCursorRight = event.type == SDL_KEYDOWN;
                break;
        case SDLK_UP :
            moveCursorUp = event.type == SDL_KEYDOWN;
            break;
        case SDLK_DOWN :
            moveCursorDown = event.type == SDL_KEYDOWN;
            break;
        case SDLK_KP_ENTER :
            pressEnter = event.type == SDL_KEYDOWN;
            break;
        case SDLK_SPACE :
            pressSpaceBar = event.type == SDL_KEYDOWN;
            break;
        case SDLK_BACKSPACE :
            pressEscape = event.type == SDL_KEYDOWN;
            break;

    }
}

void Curseur::compute() {
/*    if(moveCursorLeft) {
        engineManager->getPuissance4()->getStateManager()->setNxtMenu(StateManager::StateType::OPTION_MENU);
    }
    if(moveCursorRight) {
        engineManager->getPuissance4()->getStateManager()->setNxtMenu(StateManager::StateType::GENERAL_MENU);
    }*/

    if(moveCursorUp){
       ligneNum = (ligneNum - 1)%4;
       if(ligneNum == -1){
           ligneNum = 3;
       }
       positionY = ligneNum * 100 + 100;
    }

    if(moveCursorDown){
       ligneNum = (ligneNum + 1)%4;
       positionY = ligneNum * 100 + 100;
    }

}

void Curseur::display() {
    engineManager->GetGraphicEngine()->displayImage(image3, positionX, positionY);
}
int Curseur::getX(){
    return positionX;
}

int Curseur::getY(){
    return positionY;
}

bool Curseur::getPressSpaceBar() {
    return pressSpaceBar;
}




































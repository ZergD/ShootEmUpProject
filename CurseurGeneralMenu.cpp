#include "CurseurGeneralMenu.h"
#include "EngineManager.h"
#include "ShootEmUp.h"
#include "StateManager.h"

CurseurGeneralMenu::CurseurGeneralMenu(EngineManager* engineManagerP) : Curseur(engineManagerP){
    positionX = 60; positionY = 100;
    pas = 50;
    image3 = SDL_LoadBMP("Images/curseurgoku.bmp");
    SDL_SetColorKey(image3, SDL_SRCCOLORKEY, SDL_MapRGB(image3->format, 0, 0, 255)); //on gere la transparence du curseur
    //le curseur a le fond de son image colorier en bleu 0, 0, 255. Cette fonction rend le bleu invisible
}


CurseurGeneralMenu::~CurseurGeneralMenu(void)
{

}

void CurseurGeneralMenu::compute() {
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
/*    if(ligneNum == 0 && pressSpaceBar) {
		engineManager->getShootEmUp()->getStateManager()->setNxtMenu(StateManager::StateType::SELECT_GAME_MODE);
    }

    if(ligneNum == 1 && pressSpaceBar) {
        engineManager->getShootEmUp()->getStateManager()->setNxtMenu(StateManager::StateType::OPTION_MENU);
    }

    if(ligneNum == 2 && pressSpaceBar) {
        engineManager->getShootEmUp()->getStateManager()->setNxtMenu(StateManager::StateType::RULES_MENU);
    }
*/
    if(ligneNum == 3 && pressSpaceBar){
        engineManager->GetInputEngine()->setDisplay(false);
    }

}

void CurseurGeneralMenu::display() {
     engineManager->GetGraphicEngine()->displayImage(image3, positionX, positionY);
}






































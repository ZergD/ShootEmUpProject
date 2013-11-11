#include "ShootEmUp.h"
#include "Menu.h"

Menu::Menu(ShootEmUp* shootEmUpP)
{
    shootEmUp = shootEmUpP;
    img = NULL;
    image = NULL;
}


Menu::~Menu(void)
{
    SDL_FreeSurface(img);
}

void Menu::start() {
    //curseur = new CurseurGeneralMenu(puissance4->getEngineManager());
    image = new Image(shootEmUp->getEngineManager(), img);

}
void Menu::stop() {
    //delete curseur;
    delete image;
}

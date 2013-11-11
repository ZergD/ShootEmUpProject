#pragma once
#include "Menu.h"

class ShootEmUp;

class GameState : public Menu
{
public:
    GameState(ShootEmUp*,int);
    ~GameState(void);

    void start();
    void stop();
    //CloseApplicationObject* cao;

private:

    //Token * token;
    //SDL_Surface *tkn; // sdl surface pour le token
    //Grid * grid;
    //SDL_Surface *grd; // sdl surface pour la grille
    //bool whosTurn;
    //int turnNumber;
    //int gameModeChoice;
    //CurseurGameState * curseurGS;
    //bool spaceBar;
    //Event *event

};


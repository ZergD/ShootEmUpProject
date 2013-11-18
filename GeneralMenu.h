#pragma once
#include "Menu.h"
#include "CurseurGeneralMenu.h"

class Puissance4;

class GeneralMenu : public Menu
{
public:
    GeneralMenu(ShootEmUp*);
    ~GeneralMenu(void);
	CurseurGeneralMenu* curseur;

    void start();
    void stop();

protected:
    CurseurGeneralMenu* curseur_GM;
};


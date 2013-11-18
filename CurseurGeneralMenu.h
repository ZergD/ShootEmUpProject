#pragma once
#include "Curseur.h"

class EngineManager;

class CurseurGeneralMenu : public Curseur
{
public:
    CurseurGeneralMenu(EngineManager*);
    ~CurseurGeneralMenu(void);

    virtual void compute();
    virtual void display();
};


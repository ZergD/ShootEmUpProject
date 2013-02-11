#pragma once
#include "SpaceShip.h"

class EngineManager;

class EnemySpaceShip : public SpaceShip
{
public:
    EnemySpaceShip(EngineManager*);
    ~EnemySpaceShip(void);

    //Methodes
    void display();
    void compute();
};


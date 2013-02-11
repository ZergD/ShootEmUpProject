#pragma once
#include "ComputeObject.h"
#include "DisplayObject.h"
#include <time.h>

class EngineManager;

class SpaceShip : public ComputeObject, public DisplayObject
{
protected:
    int positionX, positionY;	
    time_t lastShootTime;
	EngineManager* engineManager;
public:

    SpaceShip(EngineManager*);
    virtual ~ SpaceShip(void);

    	//Methodes
	bool youCanShoot(); //implementer ici ds Spaceship.cpp

	int getPositionX(); //
	int getPositionY();// pareil

	void setPositionX(int X); //
	void setPositionY(int Y);//

};
 //   inline SpaceShip::~SpaceShip() {};
#pragma once
#include "ComputeObject.h"
#include "DisplayObject.h"
#include <time.h>
#include "SDL_image.h"
#include "SDL.h"

class EngineManager;

class SpaceShip : public ComputeObject, public DisplayObject
{
protected:
    int positionX, positionY;	
    time_t lastShootTime;
	EngineManager* engineManager;
    SDL_Surface *image;
public:

    SpaceShip(EngineManager*);
    virtual ~ SpaceShip(void);

    	//Methodes
	bool youCanShoot(); //implementer ici ds Spaceship.cpp

	int getPositionX(); //
	int getPositionY();// pareil

	void setPositionX(int X); //
	void setPositionY(int Y);//
    virtual void display() = 0;

};
 //   inline SpaceShip::~SpaceShip() {};
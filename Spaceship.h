#pragma once

#include "DisplayObject.h"
#include "ComputeObject.h"
#include "time.h"

class EngineManager;

class SpaceShip : public DisplayObject, public ComputeObject
{
	int positionX, positionY;
	time_t start;
	EngineManager* engineManager;
public:
	//Constructeurs
	SpaceShip(EngineManager*, int X, int Y);
	SpaceShip(EngineManager*);
	
	//Destructeur
	~SpaceShip(void);

	//Methodes
	bool youCanShoot();
	void move(int dx, int dy);
	void displaySingularShip();
	void display();
	void compute();

	int getPositionX();
	int getPositionY();

	void setPositionX(int X);
	void setPositionY(int Y);
};


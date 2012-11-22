#pragma once

#include "DisplayObject.h"
#include "ComputeObject.h"

class EngineManager;

class SpaceShip : public DisplayObject, public ComputeObject
{
	int positionX, positionY;
	EngineManager* engineManager;
public:
	//Constructeurs
	SpaceShip(void);
	SpaceShip(int X, int Y);
	SpaceShip(EngineManager*);
	
	//Destructeur
	~SpaceShip(void);

	//Methodes
	void move(int dx, int dy);
	void displaySingularShip();
	void display();
	void compute();

	int getPositionX();
	int getPositionY();

	void setPositionX(int X);
	void setPositionY(int Y);
};


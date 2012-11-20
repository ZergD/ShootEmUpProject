#pragma once

#include "DisplayObject.h"

class EngineManager;

class SpaceShip : public DisplayObject
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

	int getPositionX();
	int getPositionY();

	void setPositionX(int X);
	void setPositionY(int Y);
};


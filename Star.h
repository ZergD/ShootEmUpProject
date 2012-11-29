#pragma once
#include "DisplayObject.h"
#include "ComputeObject.h"

class EngineManager;

class Star : public DisplayObject, public ComputeObject
{
	int positionX, positionY, size;
	EngineManager* engineManager;
public:
	//Constructeurs
	Star(void);
	Star(int X, int Y);
	Star(EngineManager*, int, int, int);
	
	//Destructeur
	~Star(void);

	//Methodes
	void move(int dx, int dy);
	void display();
	void compute();

	int getPositionX();
	int getPositionY();

	void setPositionX(int X);
	void setPositionY(int Y);
};
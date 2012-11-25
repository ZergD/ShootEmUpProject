#pragma once
#include "DisplayObject.h"
#include "ComputeObject.h"

class EngineManager;

class Shot : public DisplayObject, public ComputeObject
{
	int positionX, positionY, longueur;
	EngineManager* engineManager;
public:
	//Constructeurs
	Shot(void);
	Shot(int X, int Y);
	Shot(EngineManager*, int, int);
	
	//Destructeur
	~Shot(void);

	//Methodes
	void move(int dx, int dy);
	void display();
	void compute();

	int getPositionX();
	int getPositionY();

	void setPositionX(int X);
	void setPositionY(int Y);
};
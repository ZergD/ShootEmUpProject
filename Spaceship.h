#pragma once

#include "DisplayObject.h"
#include "ComputeObject.h"
#include "time.h"

class EngineManager;
class ObjectProto;

class SpaceShip : public DisplayObject, public ComputeObject {

	static const int VITESSE = 10;

	int positionX, positionY;
	time_t lastShootTime;
	EngineManager* engineManager;

public:

	//Constructeurs
	SpaceShip(EngineManager*, ObjectProto proto);
	
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


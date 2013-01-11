#pragma once

#include "ControlObject.h"
#include "Spaceship.h"

class EngineManager;

class ControlledSpaceShip : public SpaceShip, ControlObject {

public:

	//Constructeurs
	ControlledSpaceShip(EngineManager* engineManager);
	
	//Destructeur
	~ControlledSpaceShip(void);

	//Methodes
	void control();

};
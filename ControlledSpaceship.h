#pragma once

#include "ControlObject.h"
#include "Spaceship.h"

class EngineManager;
class ObjectProto;

class ControlledSpaceShip : public SpaceShip, ControlObject {

public:

	//Constructeurs
	ControlledSpaceShip(EngineManager* engineManager, ObjectProto objectProto);
	
	//Destructeur
	~ControlledSpaceShip(void);

	//Methodes
	void control();

};
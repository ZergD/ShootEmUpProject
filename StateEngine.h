#pragma once
#include <list>

#include "Engine.h"
#include "ComputeObject.h"
#include "Spaceship.h"

class EngineManager;


class StateEngine : public Engine
{
	SpaceShip* spaceShip;
	EngineManager* engineManager;
	std::list<ComputeObject*> computeObjectList;
public:
	StateEngine(void);
	StateEngine(EngineManager*);
	~StateEngine(void);
	void process();
	void display();
	
	void addComputeObject(ComputeObject*);
	void removeComputeObject(ComputeObject*);
};


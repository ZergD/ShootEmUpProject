#pragma once
#include "SpaceShip.h"
#include "Engine.h"
#include <list>
#include "ComputeObject.h"

class EngineManager;


class StateEngine : public Engine
{
	SpaceShip* spaceShip;
	EngineManager* engineManager;
	list<ComputeObject*> computeObjectList;
public:
	StateEngine(void);
	StateEngine(EngineManager*);
	~StateEngine(void);
	void process();
	void display();
	
	void addComputeObject(ComputeObject*);
};


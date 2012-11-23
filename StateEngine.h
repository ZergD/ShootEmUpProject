#pragma once
#include <list>

#include "Engine.h"
#include "ComputeObject.h"
#include "SpaceShip.h"

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
};


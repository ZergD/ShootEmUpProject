#pragma once
#include <list>

#include "Engine.h"
#include "ComputeObject.h"
//#include "PlayerSpaceShip.h"

class EngineManager;

class StateEngine : public Engine
{
	//PlayerSpaceShip* PlayerSpaceShip;
	EngineManager* engineManager;
	std::list<ComputeObject*> computeObjectList;
public:
	StateEngine(void);
	StateEngine(EngineManager*);
	~StateEngine(void);
	void process();
	
	void addComputeObject(ComputeObject*);
	void removeComputeObject(ComputeObject*);
};


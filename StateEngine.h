#pragma once
#include "SpaceShip.h"
#include "Engine.h"

class EngineManager;

class StateEngine : public Engine
{
	SpaceShip* spaceShip;
	EngineManager* engineManager;
public:
	StateEngine(void);
	StateEngine(EngineManager*);
	~StateEngine(void);
	void process();
	void display();
};


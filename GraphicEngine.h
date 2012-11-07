#pragma once
#include "Engine.h"
#include "SpaceShip.h"
#include "graphics.h"

class EngineManager;

class GraphicEngine : public Engine
{
	EngineManager* engineManager;
public:
	GraphicEngine(void);
	GraphicEngine(EngineManager*);
	~GraphicEngine(void);
	void process();
};


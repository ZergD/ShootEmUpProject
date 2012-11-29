#pragma once
#include <list>
#include "Engine.h"
#include "StateEngine.h"
#include "InputEngine.h"
#include <iostream>
#include "GraphicEngine.h"
#include "ParticleEngine.h"

using namespace std;

class EngineManager
{
	InputEngine* inputEngine;
	//SpaceShip*spaceShip;
	StateEngine* stateEngine;
	GraphicEngine* graphicEngine;
	ParticleEngine* particleEngine;
	list<Engine*> engineList;
public:
	EngineManager(void);
	~EngineManager(void);

	void start();
	InputEngine* GetInputEngine();
	StateEngine* GetStateEngine();
	GraphicEngine* GetGraphicEngine();
	SpaceShip* GetSpaceShip();
};


#pragma once
#include <list>
#include <iostream>
#include "Engine.h"
#include "StateEngine.h"
#include "InputEngine.h"
#include "GraphicEngine.h"
#include "ParticleEngine.h"

#include "PlayerSpaceShip.h"
#include "EnemySpaceShip.h"

class EngineManager {

	InputEngine* inputEngine;
	StateEngine* stateEngine;
	GraphicEngine* graphicEngine;
	ParticleEngine* particleEngine;
    PlayerSpaceShip* playerSpaceShip;	
	std::list<Engine*> engineList;

public:

	EngineManager(void);
	~EngineManager(void);

	void start();

	InputEngine* GetInputEngine();
	StateEngine* GetStateEngine();
	GraphicEngine* GetGraphicEngine();
	ParticleEngine* GetParticleEngine();
    PlayerSpaceShip* GetPlayerSpaceShip();

};


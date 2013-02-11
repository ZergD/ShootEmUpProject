#pragma once
#include <list>
#include <iostream>
#include "Engine.h"
#include "StateEngine.h"
#include "InputEngine.h"
#include "GraphicEngine.h"
#include "NetworkEngine.h"
#include "ParticleEngine.h"

#include "PlayerSpaceShip.h"
#include "EnemySpaceShip.h"

class EngineManager {

	InputEngine* inputEngine;
	StateEngine* stateEngine;
	GraphicEngine* graphicEngine;
	NetworkEngine* networkEngine;
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
	NetworkEngine* GetNetworkEngine();
	ParticleEngine* GetParticleEngine();
    PlayerSpaceShip* GetPlayerSpaceShip();

};


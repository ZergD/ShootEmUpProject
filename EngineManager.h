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

class ShootEmUp;

class EngineManager {

	ShootEmUp* shootEmUp;
	InputEngine* inputEngine;
	StateEngine* stateEngine;
	GraphicEngine* graphicEngine;
	ParticleEngine* particleEngine;
    PlayerSpaceShip* playerSpaceShip;	
	std::list<Engine*> engineList;
	
public:

	EngineManager(void);
	EngineManager(ShootEmUp*);
	~EngineManager(void);

	void start();

	InputEngine* GetInputEngine();
	StateEngine* GetStateEngine();
	GraphicEngine* GetGraphicEngine();
	ParticleEngine* GetParticleEngine();
    PlayerSpaceShip* GetPlayerSpaceShip();
	ShootEmUp* getShootEmUp();

};


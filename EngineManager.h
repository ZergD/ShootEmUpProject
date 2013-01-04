#pragma once
#include <list>
#include <iostream>
#include "Engine.h"
#include "StateEngine.h"
#include "InputEngine.h"
#include "GraphicEngine.h"
#include "NetworkEngine.h"

class EngineManager {

	InputEngine* inputEngine;
	StateEngine* stateEngine;
	GraphicEngine* graphicEngine;
	NetworkEngine* networkEngine;
	
	std::list<Engine*> engineList;

public:

	EngineManager(void);
	~EngineManager(void);

	void start();

	InputEngine* GetInputEngine();
	StateEngine* GetStateEngine();
	GraphicEngine* GetGraphicEngine();
	NetworkEngine* GetNetworkEngine();

};


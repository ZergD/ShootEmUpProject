#pragma once
#include "EngineManager.h"
#include "StateManager.h"

class ShootEmUp
{
public:
	ShootEmUp(void);
	~ShootEmUp(void);

	void launch();
	EngineManager* getEngineManager();
	StateManager* getStateManager();

private:
	EngineManager* engineManager;
	StateManager* stateManager;
};


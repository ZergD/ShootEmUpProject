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
	SDL_Event getSDL_Event();

private:
	EngineManager* engineManager;
	StateManager* stateManager;
	SDL_Event event;
};


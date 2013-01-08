#pragma once
#include "SDL.h"
#include "Engine.h"

using namespace std;

class EngineManager;

class InputEngine : public Engine {

	SDL_Event event;
	EngineManager* engineManager;
	
	bool display;
	int movementX;
	int movementY;
	bool shoot;
	
public:

	InputEngine(EngineManager*);
	~InputEngine(void);
	
	void process();

	bool isDisplay();
	int getMovementX();
	int getMovementY();
	bool isShoot();

};


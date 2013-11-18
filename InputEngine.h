#pragma once
#include "SDL.h"
#include "Engine.h"
#include "InputObject.h"
#include <list>

using namespace std;

class EngineManager;

class InputEngine : public Engine
{

	bool display;
	//SDL_Event event;
	bool toucheAppuyeeSpaceBar;
	EngineManager* engineManager;
	std::list<InputObject*>inputObjectList;
public:
	InputEngine(void);
	InputEngine(EngineManager*);
	~InputEngine(void);
	
	bool GetToucheAppuyeeSpaceBar();
	bool GetDisplay();
	void setDisplay(bool);
	SDL_Event getSDL_Event();

	void addInputObject(InputObject*);
    void removeInputObject(InputObject*);

	void process();
};


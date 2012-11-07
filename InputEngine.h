#pragma once
#include "SDL.h"
#include "Engine.h"

using namespace std;

class EngineManager;

class InputEngine : public Engine
{
	int display;
	SDL_Event event;
	bool toucheAppuyeeUp;
	bool toucheAppuyeeDown;
	bool toucheAppuyeeLeft;
	bool toucheAppuyeeRight;
	EngineManager* engineManager;
public:
	InputEngine(void);
	InputEngine(EngineManager*);
	~InputEngine(void);
	
	bool GetToucheAppuyeeUp();
	bool GetToucheAppuyeeDown();
	bool GetToucheAppuyeeLeft();
	bool GetToucheAppuyeeRight();
	int GetDisplay();

	void process();

	void SetToucheAppuyeeUp(bool);
	void SetToucheAppuyeeDown(bool);
	void SetToucheAppuyeeLeft(bool);
	void SetToucheAppuyeeRight(bool);
};


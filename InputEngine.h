#pragma once
#include "SDL.h"
#include "Engine.h"

using namespace std;

class EngineManager;

class InputEngine : public Engine
{
	bool display;
	SDL_Event event;
	bool toucheAppuyeeUp;
	bool toucheAppuyeeDown;
	bool toucheAppuyeeLeft;
	bool toucheAppuyeeRight;
	bool toucheAppuyeeSpaceBar;
	EngineManager* engineManager;
public:
	InputEngine(void);
	InputEngine(EngineManager*);
	~InputEngine(void);
	
	bool GetToucheAppuyeeUp();
	bool GetToucheAppuyeeDown();
	bool GetToucheAppuyeeLeft();
	bool GetToucheAppuyeeRight();
	bool GetToucheAppuyeeSpaceBar();
	bool GetDisplay();

	void process();

	void SetToucheAppuyeeUp(bool);
	void SetToucheAppuyeeDown(bool);
	void SetToucheAppuyeeLeft(bool);
	void SetToucheAppuyeeRight(bool);
};


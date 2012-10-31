#pragma once
#include "SDL.h"

class Input
{
	int display;
	SDL_Event event;
	bool toucheAppuyeeUp;
	bool toucheAppuyeeDown;
	bool toucheAppuyeeLeft;
	bool toucheAppuyeeRight;
public:
	Input(void);
	~Input(void);
	void keyboardInputManager();
	bool GetToucheAppuyeeUp();
	bool GetToucheAppuyeeDown();
	bool GetToucheAppuyeeLeft();
	bool GetToucheAppuyeeRight();
	int GetDisplay();

	void SetToucheAppuyeeUp(bool);
	void SetToucheAppuyeeDown(bool);
	void SetToucheAppuyeeLeft(bool);
	void SetToucheAppuyeeRight(bool);
};


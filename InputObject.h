#pragma once
#include "SDL.h"

class InputObject
{
public:

	virtual ~InputObject(void);
	virtual void process(SDL_Event) = 0;
};
inline InputObject::~InputObject() {};

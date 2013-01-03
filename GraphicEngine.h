#pragma once
#include "Engine.h"
#include "DisplayObject.h"
#include "Spaceship.h"
#include "graphics.h"
#include <list>

using namespace std;

class EngineManager;

class GraphicEngine : public Engine
{
	EngineManager* engineManager;
	list<DisplayObject*> displayObjectList;
public:
	GraphicEngine(void);
	GraphicEngine(EngineManager*);
	~GraphicEngine(void);
	void process();
	void display();

	void addObject(DisplayObject*);
	void removeObject(DisplayObject*);
};


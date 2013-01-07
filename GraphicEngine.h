#pragma once
#include "Engine.h"
#include "DisplayObject.h"
#include "Spaceship.h"
#include <list>

using namespace std;

class EngineManager;

class GraphicEngine : public Engine {
	
	EngineManager* engineManager;
	list<DisplayObject*> displayObjectList;

	Uint8 backgroundColor;

public:

	GraphicEngine(EngineManager*);
	~GraphicEngine(void);

	void process();
	void display();

	void addObject(DisplayObject*);
	void removeObject(DisplayObject*);

};


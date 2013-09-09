#pragma once
#include "Engine.h"
#include "DisplayObject.h"
#include <list>
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

class EngineManager;
class Image;

class GraphicEngine : public Engine {
private:	
	EngineManager* engineManager;
	list<DisplayObject*> displayObjectList;
    int height, width;
    SDL_Surface* screen;
    SDL_Surface* background;
    Image* img;
    bool backgroundFirstIteration;

public:

	GraphicEngine(EngineManager*);
	~GraphicEngine(void);

	void process();
	void display();

	void addObject(DisplayObject*);
	void removeObject(DisplayObject*);
    void displayImage(SDL_Surface*, int, int);
    void loadBackground();
	int getHeight();
	int getWidth();
};
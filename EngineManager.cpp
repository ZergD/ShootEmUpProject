#include <windows.h>

#include "EngineManager.h"
#include "Spaceship.h"

using namespace std;

EngineManager::EngineManager(void)
{
	inputEngine = new InputEngine(this);
	stateEngine = new StateEngine(this);
	graphicEngine = new GraphicEngine(this);
	particleEngine = new ParticleEngine(this);
	engineList.push_front(inputEngine);
	engineList.push_back(stateEngine);
	engineList.push_back(graphicEngine);
	engineList.push_back(particleEngine);
	new SpaceShip(this);
}

EngineManager::~EngineManager(void)
{
	
}

void EngineManager::start() {
	init_graphics();
	while(inputEngine->GetDisplay()) {
		for (list<Engine*>::iterator it = engineList.begin(); it != engineList.end(); it++) {
			(*it)->process();
		}
		Sleep(10);
	}
}

//Getters
InputEngine* EngineManager::GetInputEngine() {
	return inputEngine;
}

StateEngine* EngineManager::GetStateEngine() {
	return stateEngine;
}

GraphicEngine* EngineManager::GetGraphicEngine() {
	return graphicEngine;
}
/*
SpaceShip* EngineManager::GetSpaceShip() {
	return spaceShip;
}*/

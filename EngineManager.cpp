#include "EngineManager.h"

using namespace std;

EngineManager::EngineManager(void)
{
	inputEngine = new InputEngine(this);
	stateEngine = new StateEngine(this);
	graphicEngine = new GraphicEngine(this);
	engineList.push_front(inputEngine);
	engineList.push_back(stateEngine);
	engineList.push_back(graphicEngine);
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

// faire une methode process avec le while (qui peu bien etre le start() )

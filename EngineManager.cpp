#include <boost/thread/thread.hpp>

#include "EngineManager.h"
#include "Spaceship.h"

EngineManager::EngineManager(void) {
	inputEngine = new InputEngine(this);
	stateEngine = new StateEngine(this);
	graphicEngine = new GraphicEngine(this);
	networkEngine = new NetworkEngine(this);

	engineList.push_front(inputEngine);
	engineList.push_front(networkEngine);
	engineList.push_back(stateEngine);
	engineList.push_back(graphicEngine);
	
	//particleEngine = new ParticleEngine(this);
	new SpaceShip(this);
}

EngineManager::~EngineManager(void) {
	
}

void EngineManager::start() {
	while(inputEngine->isDisplay()) {
		for (std::list<Engine*>::iterator it = engineList.begin(); it != engineList.end(); it++) {
			(*it)->process();
		}
		
		boost::this_thread::sleep(boost::posix_time::milliseconds(10));
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

NetworkEngine* EngineManager::GetNetworkEngine() {
	return networkEngine;
}

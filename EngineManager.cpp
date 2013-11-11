#include <boost/thread/thread.hpp>

#include "EngineManager.h"


EngineManager::EngineManager(ShootEmUp* shootemupP) {
	shootEmUp = shootemupP;
	inputEngine = new InputEngine(this);
	stateEngine = new StateEngine(this);
	graphicEngine = new GraphicEngine(this);
	//particleEngine = new ParticleEngine(this);
	//engineList.push_front(particleEngine);
	engineList.push_back(inputEngine);
	engineList.push_back(stateEngine);
	engineList.push_back(graphicEngine);
	//playerSpaceShip = new PlayerSpaceShip(this);
    //new EnemySpaceShip(this);
}

EngineManager::~EngineManager(void) {
	
}

void EngineManager::start() {
	//while(inputEngine->GetDisplay()) {
		for (std::list<Engine*>::iterator it = engineList.begin(); it != engineList.end(); it++) {
			(*it)->process();
		}		
		//boost::this_thread::sleep(boost::posix_time::milliseconds(20));
        //20
	//}
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

ParticleEngine* EngineManager::GetParticleEngine() {
	return particleEngine;
}

PlayerSpaceShip* EngineManager::GetPlayerSpaceShip() {
    return playerSpaceShip;
}

ShootEmUp* EngineManager::getShootEmUp(){
	return shootEmUp;
}
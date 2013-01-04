#include "NetworkEngine.h"
#include "EngineManager.h"

NetworkEngine::NetworkEngine(EngineManager* EngineManagerP) {
	engineManager = EngineManagerP;
}


NetworkEngine::~NetworkEngine(void) {
}

void NetworkEngine::addObject(NetworkObject* networkObject){
	networkObjectMap.insert(std::pair<std::string, NetworkObject*>(networkObject->getId(), networkObject));
}

void NetworkEngine::removeObject(NetworkObject* networkObject) {
	networkObjectMap.erase(networkObject->getId());
}

void NetworkEngine::process() {

}

void NetworkEngine::display() {
	
}

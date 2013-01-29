#include "NetworkEngine.h"
#include "EngineManager.h"

NetworkEngine::NetworkEngine(EngineManager* EngineManagerP)
	: socket(io_service) {
	engineManager = EngineManagerP;

	boost::asio::ip::tcp::resolver resolver(io_service);
    boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), "localhost", "9999");
    boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);
    //~ boost::asio::connect(socket, iterator);
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

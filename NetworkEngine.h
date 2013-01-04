#pragma once

#include <map>
#include "Engine.h"
#include "NetworkObject.h"

class EngineManager;

class NetworkEngine : public Engine {

	EngineManager* engineManager;
	std::map<std::string, NetworkObject*> networkObjectMap;

public:

	NetworkEngine(EngineManager*);
	~NetworkEngine(void);

	void process();
	void display();

	void addObject(NetworkObject*);
	void removeObject(NetworkObject*);

};


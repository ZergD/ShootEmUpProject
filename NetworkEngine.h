#pragma once

#include <map>

#include <boost/asio.hpp>

#include "Engine.h"
#include "NetworkObject.h"

class EngineManager;

class NetworkEngine : public Engine {

	EngineManager* engineManager;
	std::map<std::string, NetworkObject*> networkObjectMap;

	boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket;

public:

	NetworkEngine(EngineManager*);
	~NetworkEngine(void);

	void process();
	void display();

	void addObject(NetworkObject*);
	void removeObject(NetworkObject*);

};


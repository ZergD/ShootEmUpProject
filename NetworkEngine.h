#pragma once

#include <map>
#include <queue>

#include <boost/asio.hpp>

#include "Engine.h"
#include "NetworkObject.h"

class EngineManager;
class UpstreamMessageProto;
class DownstreamMessageProto;

class NetworkEngine : public Engine {

    enum { MESSAGE_LENGHT_FIELD_SIZE = sizeof(int) };

	EngineManager* engineManager;
	std::map<std::string, NetworkObject*> networkObjectMap;
	std::queue<UpstreamMessageProto*> messageQueue;

	boost::asio::io_service io_service;
    boost::asio::ip::tcp::socket socket;

public:

	NetworkEngine(EngineManager*);
	~NetworkEngine(void);

	void process();
	void processHeader(const boost::system::error_code& error, size_t bytes_transferred);

	void addObject(NetworkObject*);
	void removeObject(NetworkObject*);

private:

	void sendMessage(DownstreamMessageProto*);

};


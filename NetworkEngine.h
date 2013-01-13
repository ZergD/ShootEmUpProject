#pragma once

#include <map>
#include <queue>

//#define BOOST_ASIO_ENABLE_HANDLER_TRACKING
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
	void processConnect(const boost::system::error_code& error);
	void processHeader(const boost::system::error_code& error);
	void processBody(const boost::system::error_code& error, std::size_t bytes_transferred);

	void addObject(NetworkObject*);
	void removeObject(NetworkObject*);

private:

	struct NetworkMessage {
		char lengthFieldBuffer[MESSAGE_LENGHT_FIELD_SIZE];
		char* bodyBuffer;
	} networkMessage;

	void sendMessage(DownstreamMessageProto*);

};


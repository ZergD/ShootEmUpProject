#include <boost/lexical_cast.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

#include "NetworkEngine.h"
#include "EngineManager.h"

#include "Proto/Server/DownstreamMessage.pb.h"
#include "Proto/Server/UpstreamMessage.pb.h"

NetworkEngine::NetworkEngine(EngineManager* EngineManagerP)
	: socket(io_service) {
	engineManager = EngineManagerP;

	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), "localhost", "9999");
	boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

	boost::asio::async_connect(socket, iterator, boost::bind(&NetworkEngine::processConnect, this, boost::asio::placeholders::error));
	
	boost::thread t(boost::bind(&boost::asio::io_service::run, &io_service));
}

NetworkEngine::~NetworkEngine(void) {
	socket.close();
}

void NetworkEngine::addObject(NetworkObject* networkObject) {
	networkObjectMap.insert(std::pair<std::string, NetworkObject*>(networkObject->getId(), networkObject));
}

void NetworkEngine::removeObject(NetworkObject* networkObject) {
	networkObjectMap.erase(networkObject->getId());
}

void NetworkEngine::process() {
	// TODO move to a Player domain object
	if (engineManager->GetInputEngine()->getLogAsPlayer() > 0) {
		// Authenticate Send message
		DownstreamMessageProto authenticateMessage;
		authenticateMessage.set_type(DownstreamMessageProto::AUTHENTICATE);
		authenticateMessage.set_data(boost::lexical_cast<string>(engineManager->GetInputEngine()->getLogAsPlayer()));
		sendMessage(&authenticateMessage);
		engineManager->GetInputEngine()->resetLogAsPlayer();
	}

	while (!messageQueue.empty()) {
		UpstreamMessageProto* message = messageQueue.front();
		switch (message->type()) {
		case UpstreamMessageProto_Type_AUTHENTICATED:
				new SpaceShip(engineManager);
			break;
		}
		messageQueue.pop();
	}
}

void NetworkEngine::processConnect(const boost::system::error_code& error) {
	if (!error) {
		boost::asio::async_read(socket, boost::asio::buffer(networkMessage.lengthFieldBuffer, MESSAGE_LENGHT_FIELD_SIZE),
			boost::bind(&NetworkEngine::processHeader, this, boost::asio::placeholders::error));
	}
}

void NetworkEngine::processHeader(const boost::system::error_code& error) {
	if (!error) {
		int bodyLength = 0;
		bodyLength = (bodyLength << 8) + networkMessage.lengthFieldBuffer[0];
		bodyLength = (bodyLength << 8) + networkMessage.lengthFieldBuffer[1];
		bodyLength = (bodyLength << 8) + networkMessage.lengthFieldBuffer[2];
		bodyLength = (bodyLength << 8) + networkMessage.lengthFieldBuffer[3];
		
		networkMessage.bodyBuffer = new char[bodyLength];
		boost::asio::async_read(socket, boost::asio::buffer(networkMessage.bodyBuffer, bodyLength), 
			boost::bind(&NetworkEngine::processBody, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}
}

void NetworkEngine::processBody(const boost::system::error_code& error, std::size_t bytes_transferred) {
	if (!error) {
		UpstreamMessageProto upstreamMessageProto;
		upstreamMessageProto.ParseFromArray(networkMessage.bodyBuffer, bytes_transferred);
		delete[] networkMessage.bodyBuffer;
		messageQueue.push(&upstreamMessageProto);

		boost::asio::async_read(socket, boost::asio::buffer(networkMessage.lengthFieldBuffer, MESSAGE_LENGHT_FIELD_SIZE),
			boost::bind(&NetworkEngine::processHeader, this, boost::asio::placeholders::error));
	}
}

void NetworkEngine::sendMessage(DownstreamMessageProto* message) {
	boost::asio::streambuf b;
	std::ostream os(&b);

	int size = message->ByteSize();
	unsigned char bytes[4];
	bytes[0] = (size >> 24) & 0xFF;
	bytes[1] = (size >> 16) & 0xFF;
	bytes[2] = (size >> 8) & 0xFF;
	bytes[3] = size & 0xFF;

	os.write(reinterpret_cast<const char*>(bytes), sizeof(int));
	message->SerializeToOstream(&os);
	boost::asio::write(socket, b);
}

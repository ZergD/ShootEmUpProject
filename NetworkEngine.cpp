#include <boost/lexical_cast.hpp>
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
    boost::asio::connect(socket, iterator);

    char lengthFieldBuffer[MESSAGE_LENGHT_FIELD_SIZE];
    boost::asio::async_read(socket, boost::asio::buffer(lengthFieldBuffer), boost::asio::transfer_exactly(MESSAGE_LENGHT_FIELD_SIZE),
        boost::bind(&NetworkEngine::processHeader, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

NetworkEngine::~NetworkEngine(void) {
}

void NetworkEngine::addObject(NetworkObject* networkObject) {
	networkObjectMap.insert(std::pair<std::string, NetworkObject*>(networkObject->getId(), networkObject));
}

void NetworkEngine::removeObject(NetworkObject* networkObject) {
	networkObjectMap.erase(networkObject->getId());
}

void NetworkEngine::process() {
	if (engineManager->GetInputEngine()->getLogAsPlayer() > 0) {
    	// Authenticate Send message
	    DownstreamMessageProto authenticateMessage;
	    authenticateMessage.set_type(DownstreamMessageProto::AUTHENTICATE);
	    authenticateMessage.set_data(boost::lexical_cast<string>(engineManager->GetInputEngine()->getLogAsPlayer()));
	    sendMessage(&authenticateMessage);
    	engineManager->GetInputEngine()->resetLogAsPlayer();
	}
}

void NetworkEngine::processHeader(const boost::system::error_code& error, std::size_t bytes_transferred) {
    printf("received");
	if (!error) {
		printf("received");
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

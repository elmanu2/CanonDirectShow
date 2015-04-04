#include "canonserver.h"
#include "logger.h"
#include "helper.h"
#include "osc/OscReceivedElements.h"
#include "osc/OscException.h"

CanonServer::CanonServer(void)
{
	orderToTakePhoto = false;
}

CanonServer::~CanonServer(void)
{
}

void CanonServer::ProcessMessage(const osc::ReceivedMessage& m, 
	const IpEndpointName& remoteEndpoint )
{
	client_ = remoteEndpoint;
	char client[128];
	client_.AddressAndPortAsString(client);
	LOG_INFO("Receive incoming connection from " + std::string(client));
	try {
		// argument stream, and argument iterator, used in different
		// examples below.
		osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
		osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();

		if( std::strcmp( m.AddressPattern(), "/CanonClient" ) == 0 ){

			// example #1:
			// parse an expected format using the argument stream interface:
			const char *a1;
			args >> a1 >> osc::EndMessage;

			orderToTakePhoto = true;
			LOG_INFO("received '/CanonClient' message with arguments: " + std::string(a1) );

		}
		else{
			LOG_INFO("unrecognised address pattern: "
				+ std::string(m.AddressPattern()) );
		}

	}catch( osc::Exception& e ){
		LOG_ERROR("error while parsing message: "
			+ std::string(m.AddressPattern()) + ": " + e.what() );
	}
}    

IpEndpointName CanonServer::getClient()
{
	return client_;
}

bool CanonServer::getOrderToTakePhoto()
{
	return orderToTakePhoto;
}

void CanonServer::setOrderToTakePhoto(bool state)
{
	orderToTakePhoto = state;
}


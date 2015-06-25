#include "canonclient.h"
#include "logger.h"
#include "helper.h"
#include "osc/OscReceivedElements.h"
#include "osc/OscException.h"


CanonClient::CanonClient(void)
{

}

CanonClient::~CanonClient(void)
{
}

void CanonClient::ProcessMessage(const osc::ReceivedMessage& m, 
	const IpEndpointName& remoteEndpoint )
{
	char client[128];
	remoteEndpoint.AddressAndPortAsString(client);
	LOG_INFO("Receive incoming connection from " + std::string(client));

	try {
		// argument stream, and argument iterator, used in different
		// examples below.
		osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
		osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();

		if( std::strcmp( m.AddressPattern(), "/CanonServer" ) == 0 ){

			// example #1:
			// parse an expected format using the argument stream interface:
			const char *a1;
			args >> a1 >> osc::EndMessage;

			LOG_INFO("received '/CanonServer' message with arguments: " + std::string(a1) );
			exit(0);

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


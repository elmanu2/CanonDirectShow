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
	try {
		// argument stream, and argument iterator, used in different
		// examples below.
		osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
		osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();

		if( std::strcmp( m.AddressPattern(), "/test1" ) == 0 ){

			// example #1:
			// parse an expected format using the argument stream interface:
			const char *a1;
			args >> a1 >> osc::EndMessage;

			LOG_INFO("received '/test1' message with arguments: " + std::string(a1) );

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


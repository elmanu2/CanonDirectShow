#include "osc/OscOutboundPacketStream.h"

#include "ip/UdpSocket.h"
#include "ip/IpEndpointName.h"

#include "logger.h"
#include "helper.h"

#include "canonclient.h"

#define IP_MTU_SIZE 1536

CanonClient* _client;

void sendMessage(IpEndpointName host_)
{
	
    char buffer[IP_MTU_SIZE];
    osc::OutboundPacketStream p( buffer, IP_MTU_SIZE );
	UdpTransmitSocket socket( host_ );

    p.Clear();
    p << osc::BeginMessage( "/CanonClient" )
            << "hello" << osc::EndMessage;
    socket.Send( p.Data(), p.Size() );

}

int main(int argc, char* argv[])
{
	int clientReceiveingPort = 5001; 

    if( argc >= 2 && std::strcmp( argv[1], "-h" ) == 0 ){
        LOG_INFO("usage: OscSendTests [hostname [port]]");
        return 0;
    }

    const char *hostName = "localhost";
    int port = 5000;
    
    if( argc >= 2 )
        hostName = argv[1];

    if( argc >= 3 )
        port = std::atoi( argv[2] );


	IpEndpointName host( hostName, port );

	char hostIpAddress[ IpEndpointName::ADDRESS_STRING_LENGTH ];
	host.AddressAsString( hostIpAddress );

    LOG_INFO("sending test messages to " + std::string(hostName) 
		+ " (" + hostIpAddress + ") on port " + Helper::toString(port) + "...");

    sendMessage( host );


    CanonClient listener;
	UdpListeningReceiveSocket s(
            IpEndpointName( IpEndpointName::ANY_ADDRESS, clientReceiveingPort ),
            &listener );

	LOG_INFO("listening for input on port " + Helper::toString(clientReceiveingPort) + "...");
	
	s.Run();

	LOG_INFO("finishing.");

}
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
    p << osc::BeginMessage( "/test1" )
            << "hello" << osc::EndMessage;
    socket.Send( p.Data(), p.Size() );

    LOG_INFO("NOTE: sending /test1 message with too few arguments\n"\
                    "(expect an exception if receiving with OscReceiveTest)");

	SocketReceiveMultiplexer s = SocketReceiveMultiplexer();
	_client = new CanonClient();
	s.AttachSocketListener(&socket, _client);
	s.Run();
	//TODO make the server send a message
}

int main(int argc, char* argv[])
{
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


}
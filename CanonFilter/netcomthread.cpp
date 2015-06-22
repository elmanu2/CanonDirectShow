#include "netcomthread.h"
#include "helper.h"
#include "logger.h"

#define IP_MTU_SIZE 1536

NetComThread::NetComThread(void)	
{
	//_receiveSocket = new UdpListeningReceiveSocket(
 //           IpEndpointName( IpEndpointName::ANY_ADDRESS, 4999 ),
 //           &_server );

	//_transmitSocket = new UdpTransmitSocket(IpEndpointName("localhost", 5001));

	//
	//LOG_INFO("listening for input on port " + Helper::toString(4999) + "...");
}

NetComThread::~NetComThread(void)
{
	//delete _receiveSocket;
}

void NetComThread::run()
{
	//LOG_INFO("run network communication thread");
	//_receiveSocket->Run();
}

void NetComThread::stop()
{
	//LOG_INFO("stop network communication thread");
	//_receiveSocket->Break();
}

CanonServer* NetComThread::getCanonServer()
{
	return &_server;
}

void NetComThread::closeCamera()
{
	//char buffer[IP_MTU_SIZE];
 //   osc::OutboundPacketStream p( buffer, IP_MTU_SIZE );
	//
 //   p.Clear();
 //   p << osc::BeginMessage( "/CanonServer" )
 //           << "close camera" << osc::EndMessage;
	//sendMessage( p);
}

void NetComThread::photoTaked()
{
	//_server.setOrderToTakePhoto(false);

	//char buffer[IP_MTU_SIZE];
 //   osc::OutboundPacketStream p( buffer, IP_MTU_SIZE );
	//
 //   p.Clear();
 //   p << osc::BeginMessage( "/CanonServer" )
 //           << "photo taked"<< osc::EndMessage;
	//sendMessage( p);
}


void NetComThread::sendMessage(const osc::OutboundPacketStream& data)
{
	//_transmitSocket->Send(data.Data(), data.Size());
}




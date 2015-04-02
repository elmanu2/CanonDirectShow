#include "netcomthread.h"
#include "helper.h"
#include "logger.h"

NetComThread::NetComThread(void)	
{
	_socket = new UdpListeningReceiveSocket(
            IpEndpointName( IpEndpointName::ANY_ADDRESS, 5000 ),
            &_server );

	LOG_INFO("listening for input on port " + Helper::toString(5000) + "...");
}

NetComThread::~NetComThread(void)
{
	delete _socket;
}

void NetComThread::run()
{
	LOG_INFO("run network communication thread");
	_socket->Run();
}

void NetComThread::stop()
{
	LOG_INFO("stop network communication thread");
	_socket->Break();
}



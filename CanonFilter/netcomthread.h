#pragma once
#include "thread.h"
#include "canonserver.h"
#include <string>
#include "ip/UdpSocket.h"
#include "osc/OscOutboundPacketStream.h"

class NetComThread :
	public Thread
{
public:
	NetComThread(void);

	virtual ~NetComThread(void);

	virtual void run();

	void stop();

	void closeCamera();

	void photoTaked();

	void sendMessage(const osc::OutboundPacketStream& data);

	CanonServer* getCanonServer();

private :
		CanonServer _server;
		UdpListeningReceiveSocket* _receiveSocket;
		UdpTransmitSocket*		   _transmitSocket;

};


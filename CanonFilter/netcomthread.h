#pragma once
#include "thread.h"
#include "canonserver.h"

class NetComThread :
	public Thread
{
public:
	NetComThread(void);

	virtual ~NetComThread(void);

	virtual void run();

	void stop();

private :
		CanonServer _server;
		UdpListeningReceiveSocket* _socket;
};


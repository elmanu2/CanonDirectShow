#ifndef CANONSERVER
#define CANONSERVER

#include "osc/OscReceivedElements.h"

#include "ip/UdpSocket.h"
#include "osc/OscPacketListener.h"

class CanonServer : public osc::OscPacketListener
{
public:
	CanonServer(void);

	virtual ~CanonServer(void);

protected :

	virtual void ProcessMessage(const osc::ReceivedMessage& m, 
							    const IpEndpointName& remoteEndpoint );
};

#endif


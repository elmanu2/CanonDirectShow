#ifndef CANONCLIENT
#define CANONCLIENT

#include "osc/OscReceivedElements.h"

#include "ip/UdpSocket.h"
#include "osc/OscPacketListener.h"

class CanonClient : public osc::OscPacketListener
{
public:
	CanonClient(void);

	virtual ~CanonClient(void);

protected :

	virtual void ProcessMessage(const osc::ReceivedMessage& m, 
							    const IpEndpointName& remoteEndpoint );
};

#endif


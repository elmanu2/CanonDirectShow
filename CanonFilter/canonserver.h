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

	IpEndpointName getClient();

	bool getOrderToTakePhoto();

	void setOrderToTakePhoto(bool state);
protected :

	virtual void ProcessMessage(const osc::ReceivedMessage& m, 
							    const IpEndpointName& remoteEndpoint );

	IpEndpointName client_;

	bool orderToTakePhoto;
};

#endif


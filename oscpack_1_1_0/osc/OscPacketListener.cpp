
#include "OscPacketListener.h"


namespace osc{


	void OscPacketListener::ProcessBundle( const osc::ReceivedBundle& b, 
		const IpEndpointName& remoteEndpoint )
	{
		// ignore bundle time tag for now

		for( ReceivedBundle::const_iterator i = b.ElementsBegin(); 
			i != b.ElementsEnd(); ++i ){
				if( i->IsBundle() )
					ProcessBundle( ReceivedBundle(*i), remoteEndpoint );
				else
					ProcessMessage( ReceivedMessage(*i), remoteEndpoint );
		}
	}


	void OscPacketListener::ProcessPacket( const char *data, int size, 
		const IpEndpointName& remoteEndpoint )
	{
		osc::ReceivedPacket p( data, size );
		if( p.IsBundle() )
			ProcessBundle( ReceivedBundle(p), remoteEndpoint );
		else
			ProcessMessage( ReceivedMessage(p), remoteEndpoint );
	}


} // namespace osc



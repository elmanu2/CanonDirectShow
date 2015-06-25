#include "CameraObserver.h"
#include "Observer.h"
#include "CameraEvent.h"
#include "logger.h"

CameraObserver::CameraObserver(void)
{
}


CameraObserver::~CameraObserver(void)
{
}


void CameraObserver::update(Observable* from, CameraEvent *e)
{
	LOG_INFO("Camera observer notified : " + e->getEvent());
}
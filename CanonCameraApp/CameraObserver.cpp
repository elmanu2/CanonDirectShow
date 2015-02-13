#include "CameraObserver.h"
#include "Observer.h"
#include "CameraEvent.h"
#include <iostream>

CameraObserver::CameraObserver(void)
{
}


CameraObserver::~CameraObserver(void)
{
}


void CameraObserver::update(Observable* from, CameraEvent *e)
{
	std::cout<<"update : "<<e->getEvent()<<std::endl;
}
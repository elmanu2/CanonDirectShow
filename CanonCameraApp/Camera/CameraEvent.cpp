#include "CameraEvent.h"


const std::string CameraEvent::getEvent() const
{
    return _event;
}

void* CameraEvent::getArg() const
{
    return _arg;
}

CameraEvent::CameraEvent(std::string event,void* arg=0)
    :
      _event(event),
      _arg(arg) {}



#include "CanonDict.h"
#include "EDSDKTypes.h"

CanonDict* CanonDict::_instance = NULL;

std::map<unsigned long, std::string> CanonDict::_objectEventDict;

std::map<unsigned long, std::string> CanonDict::_propEventDict;

std::map<unsigned long, std::string> CanonDict::_stateEventDict;

CanonDict* CanonDict::getInstance()
{
    if(_instance == NULL)
    {
        return _instance = new CanonDict();
    }
    else
    {
        return _instance;
    }
}

CanonDict::CanonDict(void)
{
    _objectEventDict[kEdsObjectEvent_All] = "ObjectEvent-All";
    _objectEventDict[kEdsObjectEvent_VolumeInfoChanged] = "ObjectEvent-VolumeInfoChanged";
    _objectEventDict[kEdsObjectEvent_VolumeUpdateItems] = "ObjectEvent-VolumeUpdateItems";
    _objectEventDict[kEdsObjectEvent_DirItemCreated] = "ObjectEvent-DirItemCreated";
    _objectEventDict[kEdsObjectEvent_DirItemRemoved] = "ObjectEvent-DirItemRemoved";
    _objectEventDict[kEdsObjectEvent_DirItemInfoChanged] = "ObjectEvent-DirItemInfoChanged";
    _objectEventDict[kEdsObjectEvent_DirItemContentChanged] = "ObjectEvent-DirItemContentChanged";
    _objectEventDict[kEdsObjectEvent_DirItemRequestTransfer] = "ObjectEvent-DirItemRequestTransfer";
    _objectEventDict[kEdsObjectEvent_DirItemRequestTransferDT] = "ObjectEvent-DirItemRequestTransferDT";
    _objectEventDict[kEdsObjectEvent_DirItemCancelTransferDT] = "ObjectEvent-DirItemCancelTransferDT";
    _objectEventDict[kEdsObjectEvent_VolumeAdded] = "ObjectEvent-VolumeAdded";
    _objectEventDict[kEdsObjectEvent_VolumeRemoved] = "ObjectEvent-VolumeRemoved";

    _propEventDict[kEdsPropertyEvent_All] = "PropertyEvent-All";
    _propEventDict[kEdsPropertyEvent_PropertyChanged] = "PropertyEvent-PropertyChanged";
    _propEventDict[kEdsPropertyEvent_PropertyDescChanged] = "PropertyEvent-PropertyDescChanged";

    _stateEventDict[kEdsStateEvent_All] = "StateEvent-All";
    _stateEventDict[kEdsStateEvent_Shutdown] = "StateEvent-Shutdown";
    _stateEventDict[kEdsStateEvent_JobStatusChanged] = "StateEvent-JobStatusChanged";
    _stateEventDict[kEdsStateEvent_WillSoonShutDown] = "StateEvent-WillSoonShutdown";
    _stateEventDict[kEdsStateEvent_ShutDownTimerUpdate] = "StateEvent-ShutDownTimerUpdate";
    _stateEventDict[kEdsStateEvent_CaptureError] = "StateEvent-CaptureError";
    _stateEventDict[kEdsStateEvent_InternalError] = "StateEvent-InternalError";
    _stateEventDict[kEdsStateEvent_AfResult] = "StateEvent-AfResult";
    _stateEventDict[kEdsStateEvent_BulbExposureTime] = "StateEvent-BulbExposureTime";

}


CanonDict::~CanonDict(void)
{
}

std::string CanonDict::ObjectEventToString(unsigned long objEvent_)
{
    return _objectEventDict[objEvent_];
}

std::string CanonDict::PropertyEventToString(unsigned long objEvent_)
{
    return _propEventDict[objEvent_];
}

std::string CanonDict::StateEventToString(unsigned long objEvent_)
{
    return _stateEventDict[objEvent_];
}


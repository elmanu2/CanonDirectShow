#include "canoncamera.h"
#include "stdlib.h"
#include <cassert>
#include <iostream>
//#include "CameraController.h"
#include "CameraModel.h"
#include "CameraModelLegacy.h"
#include "CameraEventListener.h"
#include "OpenSessionCommand.h"
#include "CloseSessionCommand.h"
#include "CameraObserver.h"
#include "StartEvfCommand.h"
#include "EndEvfCommand.h"
#include "DownloadEvfCommand.h"

CanonCamera::CanonCamera(void)
{
	_isInitialized = false;
}


CanonCamera::~CanonCamera(void)
{
}

bool CanonCamera::Initialize()
{
    EdsError error;
    EdsCameraListRef cameraListRef = NULL;
    EdsCameraRef camera;
    EdsUInt32 count = 0;

    error = EdsInitializeSDK();
    if(error == EDS_ERR_OK)
    {
        cout<<"EDSDK initialized successfully"<<endl;
    }
    else
    {
		return false;
	}

    error = EdsGetCameraList(&cameraListRef);
    cout<<"EDSDK Get Camera List successfully"<<endl;

    // Get number of cameras
    if(error == EDS_ERR_OK)
    {
        error = EdsGetChildCount(cameraListRef, &count);
        cout<<"Found "<<count<<" camera(s)"<<endl;

        if(count == 0)
        {
            error = EDS_ERR_DEVICE_NOT_FOUND;
            return false;
        }
    }
    // Get first camera retrieved
    if(error == EDS_ERR_OK)
    {
        error = EdsGetChildAtIndex(cameraListRef , 0 , &camera);
    }

    //Create CameraController
    _camController = new CameraController();

    _camModel = new CameraModel(camera);
    _camModel->addObserver(new CameraObserver());

    _camController->setCameraModel(_camModel);

    _openSessionCmd = new OpenSessionCommand(_camModel);
    _closeSessionCmd = new CloseSessionCommand(_camModel);
	_propEvfModeCmd = new GetPropertyCommand(_camModel, kEdsPropID_Evf_Mode);
	_propEvfOutputDeviceCmd = new GetPropertyCommand(_camModel, kEdsPropID_Evf_OutputDevice);
    _startLiveViewCmd = new StartEvfCommand(_camModel);
	_stopLiveViewCmd = new EndEvfCommand(_camModel);
	_downloadEvfCmd = new DownloadEvfCommand(_camModel);
    

    //Set Property Event Handler
    if(error == EDS_ERR_OK)
    {
        error = EdsSetPropertyEventHandler( camera, kEdsPropertyEvent_All, CameraEventListener::handlePropertyEvent , (EdsVoid *)_camController);
    }

    //Set Object Event Handler
    if(error == EDS_ERR_OK)
    {
        error = EdsSetObjectEventHandler( camera, kEdsObjectEvent_All, CameraEventListener::handleObjectEvent , (EdsVoid *)_camController);
    }

    //Set State Event Handler
    if(error == EDS_ERR_OK)
    {
        error = EdsSetCameraStateEventHandler( camera, kEdsStateEvent_All, CameraEventListener::handleStateEvent , (EdsVoid *)_camController);
    }

    _isInitialized = _openSessionCmd->execute();

    return _isInitialized;
}

bool CanonCamera::Close()
{

	if(_isInitialized)
	{
		_closeSessionCmd->execute();
	}

    EdsError error;
    error = EdsTerminateSDK();
    if(error != EDS_ERR_OK)
    {
        cout<<"Fail to terminate EDSDK"<<endl;
    }
    else
    {
        cout<<"EDSDK terminated successfully"<<endl;
    }
    return true;
}

bool CanonCamera::StartLiveView()
{
	if(!IsInitialized())
	{
		return _isInitialized;
	}
	_propEvfModeCmd->execute();
	_propEvfOutputDeviceCmd->execute();
	bool res = _startLiveViewCmd->execute();
	_propEvfOutputDeviceCmd->execute();
	return res;
}

bool CanonCamera::StopLiveView()
{
	if(!IsInitialized())
	{
		return _isInitialized;
	}
	bool res = _stopLiveViewCmd->execute();
	return res;
}

bool CanonCamera::DownloadLiveViewPic()
{
	if(!IsInitialized())
	{
		return _isInitialized;
	}
	return _downloadEvfCmd->execute();
}

bool CanonCamera::IsInitialized()const
{
	return _isInitialized;
}


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

CanonCamera::CanonCamera(void)
{
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
        cout<<"EDSDK initilized successfully"<<endl;
    }
    else
    {
        CliProcessor::myExit();
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
            CliProcessor::myExit();
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

    bool res = _openSessionCmd->execute();

    return true;
}

bool CanonCamera::Close()
{
    _closeSessionCmd->execute();

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
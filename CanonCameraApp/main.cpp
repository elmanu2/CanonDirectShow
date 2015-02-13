#include "stdlib.h"
#include <cassert>
#include <iostream>
//#include "CameraController.h"
#include "CameraModel.h"
#include "CameraModelLegacy.h"
#include "CameraEventListener.h"

#include "OpenSessionCommand.h"

#include "CameraObserver.h"

#include "MessageLoop.h"

using namespace std;





void main()
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
        Processor::myExit();
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
            Processor::myExit();
        }
    }
    // Get first camera retrieved
    if(error == EDS_ERR_OK)
    {
        error = EdsGetChildAtIndex(cameraListRef , 0 , &camera);
        assert(error == EDS_ERR_OK);
    }

    //Create CameraController
    CameraController* _controller = new CameraController();

    CameraModel* cameraModele = new CameraModel(camera);
    cameraModele->addObserver(new CameraObserver());

    _controller->setCameraModel(cameraModele);

    OpenSessionCommand* _openSessionCmd = new OpenSessionCommand(cameraModele);
    CloseSessionCommand* _closeSessionCmd = new CloseSessionCommand(cameraModele);


    //Set Property Event Handler
    if(error == EDS_ERR_OK)
    {
        error = EdsSetPropertyEventHandler( camera, kEdsPropertyEvent_All, CameraEventListener::handlePropertyEvent , (EdsVoid *)_controller);
    }

    //Set Object Event Handler
    if(error == EDS_ERR_OK)
    {
        error = EdsSetObjectEventHandler( camera, kEdsObjectEvent_All, CameraEventListener::handleObjectEvent , (EdsVoid *)_controller);
    }

    //Set State Event Handler
    if(error == EDS_ERR_OK)
    {
        error = EdsSetCameraStateEventHandler( camera, kEdsStateEvent_All, CameraEventListener::handleStateEvent , (EdsVoid *)_controller);
    }

    bool res = _openSessionCmd->execute();

    Processor cli(cameraModele);
    cli.setCloseCommand(_closeSessionCmd);
    cli.setCamListRef(&cameraListRef);
    cli.start();


    MSG msg;
    while(GetMessage(&msg, NULL, NULL, NULL))
    {        
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }






}
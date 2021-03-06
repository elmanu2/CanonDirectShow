#include "stdlib.h"
#include <cassert>
#include <iostream>
#include "CameraModel.h"
#include "CameraModelLegacy.h"
#include "CameraEventListener.h"

#include "OpenSessionCommand.h"
#include "CloseSessionCommand.h"

#include "CameraObserver.h"
#include "CanonDict.h"

#include "logger.h"
#include "helper.h"
#include "environment.h"

using namespace std;


void main()
{
    Logger* logger = Logger::getInstance();
    logger->setLevel(Logger::eLevelDebug);
    logger->setLogDirectory(environment::getUserTempDir()+ "/wistiti");
    logger->addPrefixLogFile("CanonCameraApp-");
    logger->createLogFile();

	environment::logEnvironment();

    EdsError error;
    EdsCameraListRef cameraListRef = NULL;
    EdsCameraRef camera;
    EdsUInt32 count = 0;

    error = EdsInitializeSDK();
    LOG_EDSDK_ERROR_IF_NOTOK(error);

    if(error == EDS_ERR_OK)
    {
        LOG_INFO("EDSDK initilized successfully");
    }
    else
    {
        CliProcessor::myExit();
    }

    error = EdsGetCameraList(&cameraListRef);
    LOG_EDSDK_ERROR_IF_NOTOK(error);

    
    // Get number of cameras
    if(error == EDS_ERR_OK)
    {
        LOG_INFO("EDSDK Get Camera List successfully");
        error = EdsGetChildCount(cameraListRef, &count);
        LOG_EDSDK_ERROR_IF_NOTOK(error);
		LOG_INFO("Found " + Helper::toString((int)count) +" camera(s)");

        if(count == 0)
        {
            error = EDS_ERR_DEVICE_NOT_FOUND;
            LOG_EDSDK_ERROR_IF_NOTOK(error);
            CliProcessor::myExit();
            return;
        }
    }
    // Get first camera retrieved
    if(error == EDS_ERR_OK)
    {
        error = EdsGetChildAtIndex(cameraListRef , 0 , &camera);
        LOG_EDSDK_ERROR_IF_NOTOK(error);
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
        LOG_EDSDK_ERROR_IF_NOTOK(error);
    }

    //Set Object Event Handler
    if(error == EDS_ERR_OK)
    {
        error = EdsSetObjectEventHandler( camera, kEdsObjectEvent_All, CameraEventListener::handleObjectEvent , (EdsVoid *)_controller);
        LOG_EDSDK_ERROR_IF_NOTOK(error);
    }

    //Set State Event Handler
    if(error == EDS_ERR_OK)
    {
        error = EdsSetCameraStateEventHandler( camera, kEdsStateEvent_All, CameraEventListener::handleStateEvent , (EdsVoid *)_controller);
        LOG_EDSDK_ERROR_IF_NOTOK(error);
    }

    bool res = _openSessionCmd->execute();

    CliProcessor cli(cameraModele);
    cli.setCloseCommand(_closeSessionCmd);
    cli.setCamListRef(&cameraListRef);
    cli.start();
    Sleep(1000);

    while(cli.isActive())
    {
        Sleep(10);
        if(cli.isActive())
        {
            //Must be called periodically, so that EDSDK callbacks will
            //be called
            error = EdsGetEvent();
            LOG_EDSDK_ERROR_IF_NOTOK(error);
        }
        if(error != EDS_ERR_OK)
        {
            LOG_EDSDK_ERROR_IF_NOTOK(error);
            cout<<endl;
        }
    }

    system("Pause");
}
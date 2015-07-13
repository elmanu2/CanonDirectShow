#include "stdlib.h"
#include <cassert>
#include <iostream>
#include "CameraModel.h"
#include "CameraModelLegacy.h"
#include "CameraEventListener.h"

#include "OpenSessionCommand.h"
#include "CloseSessionCommand.h"

#include "logger.h"
#include "helper.h"
#include "environment.h"

using namespace std;

void test(CameraModel* pModel)
{
    
    GetPropertyCommand* _propProductName = new GetPropertyCommand(pModel, kEdsPropID_ProductName);
    GetPropertyCommand* _propBatteryLvlCmd = new GetPropertyCommand(pModel, kEdsPropID_BatteryLevel);
    GetPropertyCommand* _propBatteryQuaCmd = new GetPropertyCommand(pModel, kEdsPropID_BatteryQuality);
    GetPropertyCommand* _propAEModeCmd = new GetPropertyCommand(pModel, kEdsPropID_AEMode);
    GetPropertyCommand* _propAvCmd = new GetPropertyCommand(pModel, kEdsPropID_Av);
    GetPropertyCommand* _propTvCmd = new GetPropertyCommand(pModel, kEdsPropID_Tv);
    GetPropertyCommand* _propIsoCmd = new GetPropertyCommand(pModel, kEdsPropID_ISOSpeed);
    GetPropertyCommand* _propMeteringModeCmd = new GetPropertyCommand(pModel, kEdsPropID_MeteringMode);
    GetPropertyCommand* _propExposureCompCmd = new GetPropertyCommand(pModel, kEdsPropID_ExposureCompensation);
    GetPropertyCommand* _propImageQualityCmd = new GetPropertyCommand(pModel, kEdsPropID_ImageQuality);
    GetPropertyCommand* _propEvfModeCmd = new GetPropertyCommand(pModel, kEdsPropID_Evf_Mode);
    GetPropertyCommand* _propEvfOutputDeviceCmd = new GetPropertyCommand(pModel, kEdsPropID_Evf_OutputDevice);
    GetPropertyCommand* _propDoFPreviewCmd = new GetPropertyCommand(pModel, kEdsPropID_Evf_DepthOfFieldPreview);
    GetPropertyCommand* _propEvfZoomCmd = new GetPropertyCommand(pModel, kEdsPropID_Evf_Zoom);
    GetPropertyCommand* _propEvfZoomPosCmd = new GetPropertyCommand(pModel, kEdsPropID_Evf_ZoomPosition);
    GetPropertyCommand* _propEvfZoomRectCmd = new GetPropertyCommand(pModel, kEdsPropID_Evf_ZoomRect);
    GetPropertyCommand* _propEvfAFCmd = new GetPropertyCommand(pModel, kEdsPropID_Evf_AFMode);
    GetPropertyCommand* _propFocusInfoCmd = new GetPropertyCommand(pModel, kEdsPropID_FocusInfo);
    
    _propProductName->execute();
    _propBatteryLvlCmd->execute();
    _propBatteryQuaCmd->execute();
    _propAEModeCmd->execute();
    _propAvCmd->execute();
    _propTvCmd->execute();
    _propIsoCmd->execute();
    _propMeteringModeCmd->execute(); 
    _propExposureCompCmd->execute(); 
    _propImageQualityCmd->execute(); 
    _propEvfModeCmd->execute();
    _propEvfOutputDeviceCmd->execute();
    _propDoFPreviewCmd->execute();
    _propEvfZoomCmd->execute();
    _propEvfZoomPosCmd->execute();
    _propEvfZoomRectCmd->execute();
    _propEvfAFCmd->execute();
    _propFocusInfoCmd->execute();

    EdsPoint zoomPosition;
    EdsRect zoomRect;
    EdsFocusInfo focusInfo;
    CanonDict* cdict = CanonDict::getInstance();
    LOG_DEBUG("Product name             : " + (std::string)pModel->getModelName());
    LOG_DEBUG("Battery level            : " + Helper::toString((int)pModel->getBatteryLevel()));
    LOG_DEBUG("Battery quality          : " + Helper::toString((int)pModel->getBatteryQuality()));
    LOG_DEBUG("AE mode                  : " + cdict->PropValueToString(kEdsPropID_AEMode, pModel->getAEMode()));
    LOG_DEBUG("Av                       : " + cdict->PropValueToString(kEdsPropID_Av, pModel->getAv()));
    LOG_DEBUG("Tv                       : " + Helper::toString((int)pModel->getTv()));
    LOG_DEBUG("Iso                      : " + cdict->PropValueToString(kEdsPropID_ISOSpeed, pModel->getIso()));
    LOG_DEBUG("Metering mode            : " + Helper::toString((int)pModel->getMeteringMode()));
    LOG_DEBUG("Exposure compensation    : " + Helper::toString((int)pModel->getExposureCompensation()));
    LOG_DEBUG("Image quality            : " + Helper::toString((int)pModel->getImageQuality()));
    LOG_DEBUG("Evf mode                 : " + Helper::toString((int)pModel->getEvfMode()));
    LOG_DEBUG("Evf output device        : " + Helper::toString((int)pModel->getEvfOutputDevice()));
    LOG_DEBUG("Evf zoom                 : " + Helper::toString((int)pModel->getEvfZoom()));
    zoomPosition = pModel->getEvfZoomPosition();
    zoomRect    = pModel->getEvfZoomRect();
    focusInfo   = pModel->getFocusInfo();

    delete _propProductName;
    delete _propBatteryLvlCmd;
    delete _propAEModeCmd;
    delete _propAvCmd;
    delete _propTvCmd;
    delete _propIsoCmd;
    delete _propMeteringModeCmd;
    delete _propExposureCompCmd;
    delete _propImageQualityCmd;
    delete _propEvfModeCmd;
    delete _propEvfOutputDeviceCmd;
    delete _propDoFPreviewCmd;
    delete _propEvfZoomCmd;
    delete _propEvfZoomPosCmd;
    delete _propEvfZoomRectCmd;
    delete _propEvfAFCmd;
    delete _propFocusInfoCmd;

}

void main()
{
	environment::logEnvironment();

    EdsError error;
    EdsCameraListRef cameraListRef = NULL;
    EdsCameraRef camera;
    EdsUInt32 count = 0;

    error = EdsInitializeSDK();
    if(error == EDS_ERR_OK)
    {
        LOG_INFO("EDSDK initilized successfully");
    }
    else
    {
        CliProcessor::myExit();
    }

    error = EdsGetCameraList(&cameraListRef);
    LOG_INFO("EDSDK Get Camera List successfully");

    // Get number of cameras
    if(error == EDS_ERR_OK)
    {
        error = EdsGetChildCount(cameraListRef, &count);
		LOG_INFO("Found " + Helper::toString((int)count) +" camera(s)");

        if(count == 0)
        {
            error = EDS_ERR_DEVICE_NOT_FOUND;
            CliProcessor::myExit();
            return;
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

    test(cameraModele);
    _closeSessionCmd->execute();
    

    system("Pause");
}
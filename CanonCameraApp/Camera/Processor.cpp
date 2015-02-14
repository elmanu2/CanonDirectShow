#include "Processor.h"
#include "TakePictureCommand.h"
#include "GetPropertyCommand.h"
#include <iostream>

using namespace std;

void Processor::myExit()
{
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

    system("PAUSE");
    exit(-1);
}


void Processor::setCamListRef(EdsCameraListRef* camListRef_)
{
    _camListRef = camListRef_;
}

int Processor::promptUser() const
{
    int userChoice;

    cout<<"0 - quit program"<<endl;
    cout<<"1 - take photo"<<endl;
    cout<<"2 - get product name"<<endl;
    cout<<"3 - get battery level info"<<endl;
    fscanf(stdin,"%d",&userChoice);

    return userChoice;
}

bool Processor::mainUser() 
{
    bool res;
    TakePictureCommand* _takePicCmd = new TakePictureCommand(_cameraModele);
    GetPropertyCommand* _propProductCmd = new GetPropertyCommand(_cameraModele, kEdsPropID_ProductName);
    
    int userChoice = -1;
    while(userChoice != 0)
    {
        userChoice = promptUser();
        switch(userChoice)
        {
        case 0:
            {
                break;
            }
        case 1:
            {
                res = _takePicCmd->execute();
                break;
            }
        case 2:
            {
                res = _propProductCmd->execute();
                //res &= _propBatteryLvlCmd->execute();
                //res &= _propAEModeCmd->execute();
                //res &= _propAvCmd->execute();
                //res &= _propTvCmd->execute();
                //res &= _propIsoCmd->execute();
                //res &= _propMeteringModeCmd->execute();
                //res &= _propExposureCompCmd->execute();
                //res &= _propImageQualityCmd->execute();
                //res &= _propEvfModeCmd->execute();
                //res &= _propEvfOutputDeviceCmd->execute();
                //res &= _propDoFPreviewCmd->execute();
                //res &= _propEvfZoomCmd->execute();
                //res &= _propEvfZoomPosCmd->execute();
                //res &= _propEvfZoomRectCmd->execute();
                //res &= _propEvfAFCmd->execute();
                //res &= _propFocusInfoCmd->execute();

                cout<<"Camera model : "<<_cameraModele->getModelName()<<endl;
                break;
            }
        case 3 :
            {
                //res = _propBatteryLvlCmd->execute();
                cout<<"Battery level : "<<endl;
                break;
            }
        }
    }
    //GetPropertyCommand* _propBatteryLvlCmd = new GetPropertyCommand(cameraModele, kEdsPropID_BatteryLevel);
    //GetPropertyCommand* _propAEModeCmd = new GetPropertyCommand(cameraModele, kEdsPropID_AEMode);
    //GetPropertyCommand* _propAvCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Av);
    //GetPropertyCommand* _propTvCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Tv);
    //GetPropertyCommand* _propIsoCmd = new GetPropertyCommand(cameraModele, kEdsPropID_ISOSpeed);
    //GetPropertyCommand* _propMeteringModeCmd = new GetPropertyCommand(cameraModele, kEdsPropID_MeteringMode);
    //GetPropertyCommand* _propExposureCompCmd = new GetPropertyCommand(cameraModele, kEdsPropID_ExposureCompensation);
    //GetPropertyCommand* _propImageQualityCmd = new GetPropertyCommand(cameraModele, kEdsPropID_ImageQuality);
    //GetPropertyCommand* _propEvfModeCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Evf_Mode);
    //GetPropertyCommand* _propEvfOutputDeviceCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Evf_OutputDevice);
    //GetPropertyCommand* _propDoFPreviewCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Evf_DepthOfFieldPreview);
    //GetPropertyCommand* _propEvfZoomCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Evf_Zoom);
    //GetPropertyCommand* _propEvfZoomPosCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Evf_ZoomPosition);
    //GetPropertyCommand* _propEvfZoomRectCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Evf_ZoomRect);
    //GetPropertyCommand* _propEvfAFCmd = new GetPropertyCommand(cameraModele, kEdsPropID_Evf_AFMode);
    //GetPropertyCommand* _propFocusInfoCmd = new GetPropertyCommand(cameraModele, kEdsPropID_FocusInfo);

    res = _closeCommand->execute();
    if(res == true)

    // Release camera list
    if(_camListRef != NULL)
    {
        EdsRelease(*_camListRef);
        _camListRef = NULL;
    }

    myExit();

    return true;
}   

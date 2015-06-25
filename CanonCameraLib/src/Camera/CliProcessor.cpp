#include "CliProcessor.h"
#include "TakePictureCommand.h"
#include "GetPropertyCommand.h"
#include "StartEvfCommand.h"
#include "DownloadEvfCommand.h"
#include "EndEvfCommand.h"
#include <iostream>
#include "logger.h"

using namespace std;

CliProcessor::CliProcessor(CameraModel* camModel_): _running(false), _closeCommand(0)
{ 
    _cameraModele = camModel_;
}

CliProcessor::CliProcessor(): _running(false), _closeCommand(0)
{ 
}

CliProcessor::~CliProcessor()
{
    clear();
}


void CliProcessor::enqueue(Command* command)
{
    _syncObject.lock();
    _queue.push_back(command);
    _syncObject.notify();	
    _syncObject.unlock();
}



void CliProcessor::stop()
{
    _syncObject.lock();
    _running = false;
    _syncObject.unlock();
    //resume();
}  


void CliProcessor::clear() 
{
    _syncObject.lock();

    std::deque<Command*>::iterator it = _queue.begin();
    while (it != _queue.end())
    {
        delete (*it);
        ++it;
    }
    _queue.clear();

    _syncObject.unlock();
}


Command* CliProcessor::take()
{

    Command* command = NULL;

    _syncObject.lock();

    // Que stands by between emptiness.
    while (_queue.empty() && _running)
    {
        _syncObject.wait(10);
    }

    if (_running)
    {
        command = _queue.front();
        _queue.pop_front();
    }

    _syncObject.unlock();

    return command;
}


bool CliProcessor::isEmpty()
{
    _syncObject.lock();
    bool ret = _queue.empty();
    _syncObject.unlock();

    return ret;
}



void CliProcessor::myExit()
{
    EdsError error;
    error = EdsTerminateSDK();
    if(error != EDS_ERR_OK)
    {
        LOG_ERROR("Fail to terminate EDSDK");
    }
    else
    {
        LOG_INFO("EDSDK terminated successfully");
    }
    system("PAUSE");
    //exit(-1);
}


void CliProcessor::setCamListRef(EdsCameraListRef* camListRef_)
{
    _camListRef = camListRef_;
}

int CliProcessor::promptUser() const
{
    int userChoice;

    cout<<"0 - quit program"<<endl;
    cout<<"1 - take photo"<<endl;
    cout<<"2 - get product name"<<endl;
    cout<<"3 - get battery level info"<<endl;
    cout<<"4 - start live view"<<endl;
    cout<<"5 - download live view"<<endl;
    cout<<"6 - stop liveview"<<endl;
    fscanf(stdin,"%d",&userChoice);

    return userChoice;
}

bool CliProcessor::mainUser() 
{
    bool res = true;
    TakePictureCommand* _takePicCmd = new TakePictureCommand(_cameraModele);
    GetPropertyCommand* _propProductCmd = new GetPropertyCommand(_cameraModele, kEdsPropID_ProductName);
    GetPropertyCommand* _propEvfModeCmd = new GetPropertyCommand(_cameraModele, kEdsPropID_Evf_Mode);
    GetPropertyCommand* _propEvfOutputDeviceCmd = new GetPropertyCommand(_cameraModele, kEdsPropID_Evf_OutputDevice);
    StartEvfCommand* _startLiveViewCmd = new StartEvfCommand(_cameraModele);
    DownloadEvfCommand* _downloadEvfCmd = new DownloadEvfCommand(_cameraModele);
    EndEvfCommand* _stopLiveViewCmd = new EndEvfCommand(_cameraModele);

    int userChoice = -1;
    while(userChoice != 0)
    {
        userChoice = promptUser();
        switch(userChoice)
        {
        case 0:
            {
                res = false;
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
        case 4 :
            {
                cout<<"Start liveview"<<endl;
                _propEvfModeCmd->execute();
                _propEvfOutputDeviceCmd->execute();
                res = _startLiveViewCmd->execute();
                res &= _propEvfOutputDeviceCmd->execute();

                break;
            }
        case 5 :
            {
                cout<<"Download liveview picture"<<endl;
                res = _downloadEvfCmd->execute();
				res = _downloadEvfCmd->releaseImage();
                break;
            }
        case 6 :
            {
                cout<<"Download liveview picture"<<endl;
                res = _stopLiveViewCmd->execute();
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


    if(res == false)
    {
        bool resCmd = _closeCommand->execute();
        // Release camera list
        if(_camListRef != NULL)
        {
            EdsRelease(*_camListRef);
            _camListRef = NULL;
        }

        myExit();
    }

    return res;
}

void CliProcessor::run()
{
    //When using the SDK from another thread in Windows, 
    // you must initialize the COM library by calling CoInitialize 
    CoInitializeEx( NULL, COINIT_MULTITHREADED );

    _running = true;
    while (_running)
    {
        _running = mainUser();
        //Sleep(1);

        Command* command = take();
        if(command != NULL)
        {
            bool complete = command->execute();

            if(complete == false)
            {
                //If commands that were issued fail ( because of DeviceBusy or other reasons )
                // and retry is required , note that some cameras may become unstable if multiple 
                // commands are issued in succession without an intervening interval.
                //Thus, leave an interval of about 500 ms before commands are reissued.
                Sleep(500);
                enqueue(command);
            }
            else
            {
                delete command;
            }
        }
    }

    // Clear queue
    clear();

    // Command of end
    if(_closeCommand != NULL)
    {
        _closeCommand->execute();
        delete _closeCommand;
        _closeCommand = NULL;
    }

    CoUninitialize();

}

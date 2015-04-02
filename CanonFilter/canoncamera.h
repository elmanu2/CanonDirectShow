#pragma once

#include "DownloadEvfCommand.h"

#include "netcomthread.h"

class CameraController;
class CameraModel;
class OpenSessionCommand;
class CloseSessionCommand;
class GetPropertyCommand;
class StartEvfCommand;
class EndEvfCommand;
class DownloadEvfCommand;
class TakePictureCommand;
class Observer;

class CanonCamera
{
public:
    CanonCamera(void);

    virtual ~CanonCamera(void);

    bool Initialize();

    bool Close();

	void AddObserver(Observer* observer_);

	bool StartLiveView();

	bool StopLiveView();

	bool DownloadLiveViewPic(EVF_DATASET* &dataset_);

	bool ReleaseLiveViewPic();

	bool TakePicture();

	bool IsInitialized()const;

protected:

	bool _isInitialized;

    CameraController* _camController;

    CameraModel* _camModel;

    OpenSessionCommand* _openSessionCmd;
    
    CloseSessionCommand* _closeSessionCmd;

	GetPropertyCommand* _propEvfModeCmd;

	GetPropertyCommand* _propEvfOutputDeviceCmd;

    StartEvfCommand* _startLiveViewCmd;

	EndEvfCommand* _stopLiveViewCmd;

	DownloadEvfCommand* _downloadEvfCmd;
  
	TakePictureCommand* _takePictureCmd;

	NetComThread _netComThread;


};


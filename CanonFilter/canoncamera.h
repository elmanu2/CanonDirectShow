#pragma once

#include "DownloadEvfCommand.h"

class CameraController;
class CameraModel;
class OpenSessionCommand;
class CloseSessionCommand;
class GetPropertyCommand;
class StartEvfCommand;
class EndEvfCommand;
class DownloadEvfCommand;

class CanonCamera
{
public:
    CanonCamera(void);

    virtual ~CanonCamera(void);

    bool Initialize();

    bool Close();

	bool StartLiveView();

	bool StopLiveView();

	bool DownloadLiveViewPic(EVF_DATASET* &dataset_);

	bool ReleaseLiveViewPic();

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
  

};


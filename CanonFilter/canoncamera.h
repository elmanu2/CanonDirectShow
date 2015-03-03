#pragma once

class CameraController;
class CameraModel;
class OpenSessionCommand;
class CloseSessionCommand;

class CanonCamera
{
public:
    CanonCamera(void);

    virtual ~CanonCamera(void);

    bool Initialize();

    bool Close();

protected:

    CameraController* _camController;

    CameraModel* _camModel;

    OpenSessionCommand* _openSessionCmd;
    
    CloseSessionCommand* _closeSessionCmd;



};


/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : TakePictureCommand.h	                                          *
*                                                                             *
*   Description: This is the Sample code to show the usage of EDSDK.          *
*                                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*   Written and developed by Camera Design Dept.53                            *
*   Copyright Canon Inc. 2006 All Rights Reserved                             *
*                                                                             *
*******************************************************************************/

#pragma once

#include "Command.h"
#include "CameraEvent.h"
#include "EDSDK.h"

class TakePictureCommand : public Command
{

public:
	TakePictureCommand(CameraModel *model) : Command(model){}


	// Execute command	
	virtual bool execute()
	{
		EdsError err = EDS_ERR_OK;
		bool	 locked = false;
		
		// For cameras earlier than the 30D , the UI must be locked before commands are reissued
		if( _model->isLegacy())
		{
			err = EdsSendStatusCommand(_model->getCameraObject(), kEdsCameraStatusCommand_UILock, 0);
		
			if(err == EDS_ERR_OK)
			{
				locked = true;
			}		
		}

        //Preservation ahead is set to PC
			if(err == EDS_ERR_OK)
			{
				EdsUInt32 saveTo = kEdsSaveTo_Host;
				err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_SaveTo, 0, sizeof(saveTo) , &saveTo);
			}
		
		//Taking a picture
		err = EdsSendCommand(_model->getCameraObject(), kEdsCameraCommand_TakePicture, 0);

		//It releases it when locked
		if(locked)
		{
			err = EdsSendStatusCommand(_model->getCameraObject(), kEdsCameraStatusCommand_UIUnLock, 0);
		}

		//Notification of error
		if(err != EDS_ERR_OK)
		{
			// It retries it at device busy
			if(err == EDS_ERR_DEVICE_BUSY)
			{
				CameraEvent e("DeviceBusy");
				_model->notifyObservers(&e);
				return true;
			}
			
			CameraEvent e("error", &err); 
			_model->notifyObservers(&e);
		}

		return true;
	}


};
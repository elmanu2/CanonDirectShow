/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : EndEvfCommand.h												  *
*                                                                             *
*   Description: This is the Sample code to show the usage of EDSDK.          *
*                                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*   Written and developed by Camera Design Dept.53                            *
*   Copyright Canon Inc. 2006-2008 All Rights Reserved                        *
*                                                                             *
*******************************************************************************/

#pragma once

#ifdef CANCAMBUILDDLL
#define CANCAMEXPORT  __declspec( dllexport ) 
#else
#define CANCAMEXPORT  __declspec( dllimport ) 
#endif

#include "Command.h"
#include "CameraEvent.h"
#include "EDSDK.h"
#include "logger.h"




class CANCAMEXPORT EndEvfCommand : public Command
{

public:
	EndEvfCommand(CameraModel *model) : Command(model){}


    // Execute command	
	virtual EdsError execute()
	{
		EdsError err = EDS_ERR_OK;

         LOG_INFO("End live view command...");

		// Get the current output device.
		EdsUInt32 device = _model->getEvfOutputDevice();

		// Do nothing if the remote live view has already ended.
		if((device & kEdsEvfOutputDevice_PC) == 0)
		{
			return true;
		}


		// Get depth of field status.
		EdsUInt32 depthOfFieldPreview = _model->getEvfDepthOfFieldPreview();
	
		// Release depth of field in case of depth of field status.
		if (depthOfFieldPreview != 0)
		{
			depthOfFieldPreview = 0;
			err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_Evf_DepthOfFieldPreview, 0, sizeof(depthOfFieldPreview), &depthOfFieldPreview);
            LOG_EDSDK_ERROR_IF_NOTOK(err);

			// Standby because commands are not accepted for awhile when the depth of field has been released.
			if (err == EDS_ERR_OK)
			{
				Sleep(500);
			}
		}

			
		// Change the output device.
		if (err == EDS_ERR_OK)
		{
			device &= ~kEdsEvfOutputDevice_PC;
			err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_Evf_OutputDevice, 0, sizeof(device), &device);
            LOG_EDSDK_ERROR_IF_NOTOK(err);
		}

		//Notification of error
		if(err != EDS_ERR_OK)
		{
            LOG_ERROR("End live view command failed");

			// It retries it at device busy
			if(err == EDS_ERR_DEVICE_BUSY)
			{
				CameraEvent e("DeviceBusy");
				_model->notifyObservers(&e);
				return false;
			}

			CameraEvent e("error", &err);
			_model->notifyObservers(&e);

			// Retry until successful.
			return false;
		}
          else
        {
            LOG_INFO("End live view command succeeded");
        }

		return true;
	}

};
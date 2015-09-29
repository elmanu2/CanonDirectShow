/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : StartEvfCommand.h												  *
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
#include "CanonDict.h"


class CANCAMEXPORT StartEvfCommand : public Command
{

public:
	StartEvfCommand(CameraModel *model) : Command(model){}

    // Execute command	
	virtual EdsError execute()
	{
		EdsError err = EDS_ERR_OK;

        LOG_INFO("Start live view command...");
		/// Change settings because live view cannot be started
		/// when camera settings are set to gdo not perform live view.h
		EdsUInt32 evfMode = _model->getEvfMode();
		
		if(evfMode == 0)
		{
			evfMode = 1;

			// Set to the camera.
			err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_Evf_Mode, 0, sizeof(evfMode), &evfMode);
            LOG_EDSDK_ERROR_IF_NOTOK(err);
		}
			

		if( err == EDS_ERR_OK)
		{
			// Get the current output device.
			EdsUInt32 device = _model->getEvfOutputDevice();
			
			// Set the PC as the current output device.
			device |= kEdsEvfOutputDevice_PC;

			// Set to the camera.
			err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_Evf_OutputDevice, 0, sizeof(device), &device);
		    LOG_EDSDK_ERROR_IF_NOTOK(err);
        }

		//Notification of error
		if(err != EDS_ERR_OK)
		{
            LOG_ERROR("Start live view command failed");
        
			// It doesn't retry it at device busy
			if(err == EDS_ERR_DEVICE_BUSY)
			{
				CameraEvent e("DeviceBusy");
				_model->notifyObservers(&e);
				return false;
			}

			CameraEvent e("error", &err);
			_model->notifyObservers(&e);
		}
        else
        {
            LOG_INFO("Start live view command succeeded");
        }

		return true;
	}

};
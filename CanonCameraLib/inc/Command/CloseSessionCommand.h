/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : CloseSessionCommand.h	                                          *
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


class CANCAMEXPORT CloseSessionCommand : public Command
{

public:
	CloseSessionCommand(CameraModel *model) : Command(model){}


	//Execute command	
	virtual EdsError execute()
	{
		EdsError err = EDS_ERR_OK;
	
        LOG_INFO("Close session command starts...");
		//The communication with the camera is ended
		err = EdsCloseSession(_model->getCameraObject());
        if(err == EDS_ERR_OK)
        {
            LOG_INFO("Close session command succeeded");
        }
        else
        {
            LOG_ERROR("Close session command failed");
        }

		//Notification of error
		if(err != EDS_ERR_OK)
		{
			CameraEvent e("error", &err);
			_model->notifyObservers(&e);
		}

		return true;
	}

};
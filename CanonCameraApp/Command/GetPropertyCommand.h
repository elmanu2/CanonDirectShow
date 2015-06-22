/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : GetPropertyCommand.h	                                          *
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

#include "Command.h"
#include "CameraEvent.h"
#include "EDSDK.h"

class GetPropertyCommand : public Command
{
private:
	EdsPropertyID _propertyID;


public:
	GetPropertyCommand(CameraModel *model, EdsPropertyID propertyID)
		:_propertyID(propertyID), Command(model){}


	// Execute command  	
	virtual bool execute()
	{
		EdsError err = EDS_ERR_OK;
		bool	 locked = false;
		
        LOG_INFO("Get Property command starts...");

		// For cameras earlier than the 30D , the UI must be locked before commands are reissued
		if( _model->isLegacy())
		{
			err = EdsSendStatusCommand(_model->getCameraObject(), kEdsCameraStatusCommand_UILock, 0);
			if(err == EDS_ERR_OK)
			{
				locked = true;
			}
		}		
		
		//Get property value
		if(err == EDS_ERR_OK)
		{
			err = getProperty(_propertyID);
		}

		//It releases it when locked
		if(locked)
		{
			EdsSendStatusCommand(_model->getCameraObject(), kEdsCameraStatusCommand_UIUnLock, 0);
		}


		//Notification of error
		if(err != EDS_ERR_OK)
		{
			// It retries it at device busy
			if((err & EDS_ERRORID_MASK) == EDS_ERR_DEVICE_BUSY )
			{
				CameraEvent e("DeviceBusy");
				_model->notifyObservers(&e);
				return false;
			}

			CameraEvent e("error", &err);
			_model->notifyObservers(&e);
		}

		return true;	
	
	}

private:
	EdsError getProperty(EdsPropertyID propertyID)
	{
		EdsError err = EDS_ERR_OK;
		EdsDataType	dataType = kEdsDataType_Unknown;
		EdsUInt32   dataSize = 0;


		if(propertyID == kEdsPropID_Unknown)
		{
			//If unknown is returned for the property ID , the required property must be retrieved again
			if(err == EDS_ERR_OK) err = getProperty(kEdsPropID_AEModeSelect);
			if(err == EDS_ERR_OK) err = getProperty(kEdsPropID_Tv);
			if(err == EDS_ERR_OK) err = getProperty(kEdsPropID_Av);
			if(err == EDS_ERR_OK) err = getProperty(kEdsPropID_ISOSpeed);
			if(err == EDS_ERR_OK) err = getProperty(kEdsPropID_MeteringMode);
			if(err == EDS_ERR_OK) err = getProperty(kEdsPropID_ExposureCompensation);
			if(err == EDS_ERR_OK) err = getProperty(kEdsPropID_ImageQuality);
			
			return err;
		}
	
		//Acquisition of the property size
		if(err == EDS_ERR_OK)
		{
			err = EdsGetPropertySize( _model->getCameraObject(),
									  propertyID,
									  0,
									  &dataType,
									  &dataSize );
		}

		if(err == EDS_ERR_OK)
		{
			
			if(dataType == kEdsDataType_UInt32)
			{
				EdsUInt32 data;

				//Acquisition of the property
				err = EdsGetPropertyData( _model->getCameraObject(),
										propertyID,
										0,
										dataSize,
										&data );

				//Acquired property value is set
				if(err == EDS_ERR_OK)
				{
					_model->setPropertyUInt32(propertyID, data);
				}
			}
			
			if(dataType == kEdsDataType_String)
			{
				
				EdsChar str[EDS_MAX_NAME];
				//Acquisition of the property
				err = EdsGetPropertyData( _model->getCameraObject(),
										propertyID,
										0,
										dataSize,
										str );

				//Acquired property value is set
				if(err == EDS_ERR_OK)
				{
					_model->setPropertyString(propertyID, str);
				}			
			}
			if(dataType == kEdsDataType_FocusInfo)
			{
				EdsFocusInfo focusInfo;
				//Acquisition of the property
				err = EdsGetPropertyData( _model->getCameraObject(),
										propertyID,
										0,
										dataSize,
										&focusInfo );

				//Acquired property value is set
				if(err == EDS_ERR_OK)
				{
					_model->setFocusInfo(focusInfo);
				}		
			}
		}


		//Update notification
		if(err == EDS_ERR_OK)
		{
			CameraEvent e("PropertyChanged", &propertyID);
			_model->notifyObservers(&e);
		}

		return err;
	}

};
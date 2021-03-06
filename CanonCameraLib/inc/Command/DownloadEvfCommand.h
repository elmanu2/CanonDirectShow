/******************************************************************************
	*                                                                             *
	*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
	*      NAME : DownloadEvfCommand.h	                                          *
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
#include "CanonDict.h"


	typedef struct _EVF_DATASET 
{
	EdsStreamRef	stream; // JPEG stream.
	EdsUInt32		zoom;
	EdsRect			zoomRect;
	EdsPoint		imagePosition;
	EdsUInt32		histogram[256 * 4]; //(YRGB) YRGBYRGBYRGBYRGB....
	EdsSize			sizeJpegLarge;
	EdsUInt32		dataLength;
}EVF_DATASET;


class CANCAMEXPORT DownloadEvfCommand : public Command
{
protected :
	EVF_DATASET dataSet;

	EdsError err;
	EdsEvfImageRef evfImage;
	EdsStreamRef stream;
	EdsUInt32 bufferSize;


public:
	DownloadEvfCommand(CameraModel *model) : Command(model){}

	// Execute command	
	virtual EdsError execute()
	{

		evfImage = NULL;
		stream = NULL;
		bufferSize = 2 * 1024 * 1024;
		err = EDS_ERR_OK;

		// Exit unless during live view.
		if ((_model->getEvfOutputDevice() & kEdsEvfOutputDevice_PC) == 0)
		{
			return true;
		}

		// Create memory stream.
		err = EdsCreateMemoryStream(0, &stream);
        LOG_EDSDK_ERROR_IF_NOTOK(err);

		// When creating to a file.
		//err = EdsCreateFileStream("D:\\liveview.jpg", kEdsFileCreateDisposition_CreateAlways, kEdsAccess_ReadWrite, &stream);



		// Create EvfImageRef.
		if (err == EDS_ERR_OK)
		{
			err = EdsCreateEvfImageRef(stream, &evfImage);
            LOG_EDSDK_ERROR_IF_NOTOK(err);
		}

		// Download live view image data.
		if (err == EDS_ERR_OK)
		{
			err = EdsDownloadEvfImage(_model->getCameraObject(), evfImage);
            LOG_EDSDK_ERROR_IF_NOTOK(err);
		}

		// Get meta data for live view image data.
		if (err == EDS_ERR_OK)
		{
			dataSet.stream = stream;

			// Get magnification ratio (x1, x5, or x10).
			err = EdsGetPropertyData(evfImage, kEdsPropID_Evf_Zoom, 0, sizeof(dataSet.zoom),  &dataSet.zoom);
            LOG_EDSDK_ERROR_IF_NOTOK(err);

			// Get position of image data. (when enlarging)
			// Upper left coordinate using JPEG Large size as a reference.
			err = EdsGetPropertyData(evfImage, kEdsPropID_Evf_ImagePosition, 0, sizeof(dataSet.imagePosition), &dataSet.imagePosition);
            LOG_EDSDK_ERROR_IF_NOTOK(err);

			// Get histogram (RGBY).
			//err = EdsGetPropertyData(evfImage, kEdsPropID_Evf_Histogram, 0, sizeof(dataSet.histogram), dataSet.histogram);
            //LOG_EDSDK_ERROR_IF_NOTOK(err);

			// Get rectangle of the focus border.
			err = EdsGetPropertyData(evfImage, kEdsPropID_Evf_ZoomRect, 0, sizeof(dataSet.zoomRect), &dataSet.zoomRect);
            LOG_EDSDK_ERROR_IF_NOTOK(err);

			// Get the size as a reference of the coordinates of rectangle of the focus border.
			err = EdsGetPropertyData(evfImage, kEdsPropID_Evf_CoordinateSystem, 0, sizeof(dataSet.sizeJpegLarge), &dataSet.sizeJpegLarge);
            LOG_EDSDK_ERROR_IF_NOTOK(err);

			err = EdsGetLength(stream, &(dataSet.dataLength));
            LOG_EDSDK_ERROR_IF_NOTOK(err);

			// Set to model.
			_model->setEvfZoom(dataSet.zoom);
			_model->setEvfZoomPosition(dataSet.zoomRect.point);
			_model->setEvfZoomRect(dataSet.zoomRect);

			// Live view image transfer complete notification.
			if (err == EDS_ERR_OK)
			{
				CameraEvent e("EvfDataChanged", &dataSet);
				_model->notifyObservers(&e);		
			}
		}
		return err;
	}

	bool getDataset(EVF_DATASET* &dataset_)
	{
		dataset_ = &dataSet;
		return true;
	}

	bool releaseImage()
	{
		if(dataSet.stream != NULL)
		{
			EdsRelease(dataSet.stream);
			dataSet.stream = NULL;
		}

		if(evfImage != NULL)
		{
			EdsRelease(evfImage);
			evfImage = NULL;
		}

		//Notification of error
		if(err != EDS_ERR_OK)
		{

			// Retry getting image data if EDS_ERR_OBJECT_NOTREADY is returned
			// when the image data is not ready yet.
			if(err == EDS_ERR_OBJECT_NOTREADY)
			{
				return false;
			}

			// It retries it at device busy
			if(err == EDS_ERR_DEVICE_BUSY)
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


};
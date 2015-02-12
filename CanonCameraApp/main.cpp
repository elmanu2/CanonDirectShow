#include "stdlib.h"
#include <cassert>
#include <iostream>
#include "CameraController.h"
#include "CameraModel.h"
#include "CameraModelLegacy.h"

#include "OpenSessionCommand.h"s

#include "CameraObserver.h"

using namespace std;


int promptUser()
{
	int userChoice;

	cout<<"0 - quit program"<<endl;
	cout<<"1 - take photo"<<endl;
	cout<<"2 - get product name"<<endl;
	cout<<"3 - get battery level info"<<endl;
	fscanf(stdout,"%d",&userChoice);

	return userChoice;
}
void main()
{
	EdsError error;
	EdsCameraListRef cameraListRef = NULL;
	EdsCameraRef camera;
	EdsUInt32 count = 0;
	
	error = EdsInitializeSDK();
	assert(error == EDS_ERR_OK);
	cout<<"EDSDK initilized successfully"<<endl;

	error = EdsGetCameraList(&cameraListRef);
	cout<<"EDSDK Get Camera List successfully"<<endl;

	// Get number of cameras
	if(error == EDS_ERR_OK)
	{
		error = EdsGetChildCount(cameraListRef, &count);
		assert(error == EDS_ERR_OK);
		assert(count != 0);
		cout<<"Found "<<count<<" camera(s)"<<endl;

		if(count == 0)
		{
			error = EDS_ERR_DEVICE_NOT_FOUND;
		}
	}
	// Get first camera retrieved
	if(error == EDS_ERR_OK)
	{
		error = EdsGetChildAtIndex(cameraListRef , 0 , &camera);
		assert(error == EDS_ERR_OK);
	}

			//Create CameraController
	CameraController* _controller = new CameraController();

	CameraModel* cameraModele = new CameraModel(camera);
	cameraModele->addObserver(new CameraObserver());

	_controller->setCameraModel(cameraModele);

	TakePictureCommand* _takePicCmd = new TakePictureCommand(cameraModele);
	OpenSessionCommand* _openSessionCmd = new OpenSessionCommand(cameraModele);
	CloseSessionCommand* _closeSessionCmd = new CloseSessionCommand(cameraModele);
	GetPropertyCommand* _propProductCmd = new GetPropertyCommand(cameraModele, kEdsPropID_ProductName);
	GetPropertyCommand* _propBatteryLvlCmd = new GetPropertyCommand(cameraModele, kEdsPropID_BatteryLevel);
	bool res = _openSessionCmd->execute();

	int userChoice;
	while(userChoice != 0)
	{
		promptUser();
		switch(userChoice)
		{
		case 0:
			{
			}
		case 1:
			{
				res = _takePicCmd->execute();
			}
		case 2:
			{
				res = _propProductCmd->execute();
			}
		case 3 :
			{
				res = _propBatteryLvlCmd->execute();
			}
		}
	}
	
	res = _closeSessionCmd->execute();
	assert(res == true);

	// Release camera list
	if(cameraListRef != NULL)
	{
		EdsRelease(cameraListRef);
		cameraListRef = NULL;
	}
	error = EdsTerminateSDK();
	cout<<"EDSDK terminated successfully"<<endl;

	system("PAUSE");
}
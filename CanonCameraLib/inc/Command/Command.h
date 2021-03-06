/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : Command.h	                                                      *
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

#include  "CameraModel.h"

class CANCAMEXPORT Command {

protected:
	// Camera Model
	CameraModel* _model;

public:
	Command(CameraModel *model) : _model(model) {}

	CameraModel* getCameraModel(){return _model;}

	// Execute command	
	virtual EdsError execute() = 0;
};


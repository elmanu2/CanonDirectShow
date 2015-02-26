/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : CameraController.h	                                          *
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

#include "EDSDK.h"
#include "CameraModel.h"
#include "CliProcessor.h"

#include "ActionListener.h"
#include "ActionEvent.h"


class CameraModel;
class Command;

class CameraController : public ActionListener
{

protected:
    // Camera model
    CameraModel* _model;

    // Command processing
    CliProcessor _CliProcessor;

public:
    // Constructor
    CameraController();

    // Destoracta
    virtual ~CameraController();

    void setCameraModel(CameraModel* model);

    //Execution beginning
    void run();

public:

    void actionPerformed(const ActionEvent& event);

protected:
    //The command is received
    void StoreAsync( Command *command );


};

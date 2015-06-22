/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : CliProcessor.h	                                                  *
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

#include <deque>
#include "Thread.h"
#include "Synchronized.h"
#include "Command.h"


class CameraModel;

class CANCAMEXPORT CliProcessor : public Thread 
{

protected:
    // Whether it is executing it or not?
    bool _running;
    // Que
    std::deque<Command*>  _queue;

    // Command when ending
    Command*	_closeCommand;

    CameraModel* _cameraModele;

    EdsCameraListRef* _camListRef;
    // Synchronized Object
    Synchronized _syncObject;


public:
    // Constructor  
    CliProcessor(CameraModel* camModel_);

    CliProcessor();

    // Destructeur
    virtual ~CliProcessor();

    // Set command when ending
    void setCloseCommand(Command* closeCommand){_closeCommand = closeCommand;}

    void setCamListRef(EdsCameraListRef* camListRef_);

    int promptUser() const;

    bool mainUser() ;

    static void myExit();

    /*
    void enqueue(Command* command)
    {
    _syncObject.lock();
    _queue.push_back(command);
    _syncObject.unlock();
    resume();	
    }*/


    void enqueue(Command* command);

    void stop();

    void clear();

protected:
    virtual void run();

    //The command is taken out of the que

    /*
    Command* take()
    {

    Command* command = NULL;

    // Que stands by between emptiness.
    while (true)
    {
    _syncObject.lock();
    bool empty = _queue.empty();
    _syncObject.unlock();

    if(empty == false)break;

    suspend();

    if(_running == false)
    {
    return NULL;
    }
    }

    _syncObject.lock();

    command = _queue.front();
    _queue.pop_front();

    _syncObject.unlock();

    return command;
    }*/


    Command* take();

    bool isEmpty();
};



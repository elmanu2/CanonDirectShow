#pragma once
#include "observer.h"

class Observable;
class CameraEvent;

class CameraObserver : public Observer
{
public:
	CameraObserver(void);

	virtual ~CameraObserver(void);

	virtual void update(Observable* from, CameraEvent *e);
};


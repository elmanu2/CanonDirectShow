#pragma once

#ifdef CANCAMBUILDDLL
#define CANCAMEXPORT  __declspec( dllexport ) 
#else
#define CANCAMEXPORT  __declspec( dllimport ) 
#endif

#include <vector>
#include <algorithm>

#include "ActionEvent.h"
#include "ActionListener.h" 


class CANCAMEXPORT ActionSource {
private:
	std::vector<ActionListener*> _listeners;
	std::string _command;

public:
	void addActionListener(ActionListener* listener)
	{
		if ( std::find(_listeners.begin(), _listeners.end(), listener) == _listeners.end() )
		{
			_listeners.push_back(listener);
		}
	}

	void setActionCommand(std::string command){ _command = command; }
	
	void fireEvent(void* arg = 0)
	{
		std::vector<ActionListener*>::iterator i = _listeners.begin();
		
		ActionEvent event(_command, arg);
		
		while ( i != _listeners.end() )
		{
			(*i++)->actionPerformed(event);
		}
	}
	
	void fireEvent(LPCTSTR command, void* arg = 0)
	{
		std::vector<ActionListener*>::iterator i = _listeners.begin();
		
		ActionEvent event(command, arg);
		
		while ( i != _listeners.end() )
		{
			(*i++)->actionPerformed(event);
		}
	}

	ActionSource() : _listeners(0){}
	virtual ~ActionSource(){}
};
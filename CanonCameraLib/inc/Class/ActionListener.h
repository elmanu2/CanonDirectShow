#pragma once

#ifdef CANCAMBUILDDLL
#define CANCAMEXPORT  __declspec( dllexport ) 
#else
#define CANCAMEXPORT  __declspec( dllimport ) 
#endif

class ActionEvent;
class CANCAMEXPORT ActionListener{
	public:
	virtual void actionPerformed(const ActionEvent& event) =0;
};
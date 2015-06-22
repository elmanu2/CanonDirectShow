#pragma once

#ifdef CANCAMBUILDDLL
#define CANCAMEXPORT  __declspec( dllexport ) 
#else
#define CANCAMEXPORT  __declspec( dllimport ) 
#endif

#include <map>
#include <string>

class CANCAMEXPORT CanonDict
{
public:

    //get the singleton
    static CanonDict* getInstance();
    
    //Destructor
    virtual ~CanonDict(void);

    //transform object event id into string
    std::string ObjectEventToString(unsigned long objEvent_);

    //transform property event id into string
    std::string PropertyEventToString(unsigned long propEvent_);

    //transform state event id into string
    std::string StateEventToString(unsigned long propEvent_);

    //transform property id into string
    std::string PropIdToString(unsigned long propEvent_);

    //transform property id into string
    std::string ErrToString(unsigned long propEvent_);


protected :
    //object event map
    std::map<unsigned long, std::string> _objectEventDict;

    //property event map
    std::map<unsigned long, std::string> _propEventDict;

    //state event map
    std::map<unsigned long, std::string> _stateEventDict;

    //property map
    std::map<unsigned long, std::string> _propIdDict;

    std::map<unsigned long, std::string> _errorDict;

    //The unique instance
    static CanonDict* _instance;

    //protected constructor
    CanonDict(void);
    
};


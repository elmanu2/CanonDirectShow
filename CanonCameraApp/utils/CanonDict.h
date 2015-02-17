#pragma once
#include <map>
#include <string>

class CanonDict
{
public:

    //get the singleton
    static CanonDict* getInstance();
    
    //Destructor
    virtual ~CanonDict(void);

    //transform object event id into string
    static std::string ObjectEventToString(unsigned long objEvent_);

    //transform property event id into string
    static std::string PropertyEventToString(unsigned long propEvent_);

    //transform state event id into string
    static std::string StateEventToString(unsigned long propEvent_);

    //transform property id into string
    static std::string PropIdToString(unsigned long propEvent_);

    //transform property id into string
    static std::string ErrToString(unsigned long propEvent_);


protected :
    //object event map
    static std::map<unsigned long, std::string> _objectEventDict;

    //property event map
    static std::map<unsigned long, std::string> _propEventDict;

    //state event map
    static std::map<unsigned long, std::string> _stateEventDict;

    //property map
    static std::map<unsigned long, std::string> _propIdDict;

    static std::map<unsigned long, std::string> _errorDict;

    //The unique instance
    static CanonDict* _instance;

    //protected constructor
    CanonDict(void);
    
};


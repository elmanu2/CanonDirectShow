#pragma once
#include <map>
#include <string>

class CanonDict
{
public:

    static CanonDict* getInstance();
    
    virtual ~CanonDict(void);

    static std::string ObjectEventToString(unsigned long objEvent_);

    static std::string PropertyEventToString(unsigned long propEvent_);

    static std::string StateEventToString(unsigned long propEvent_);


    //static std::string

protected :
    static std::map<unsigned long, std::string> _objectEventDict;

    static std::map<unsigned long, std::string> _propEventDict;

    static std::map<unsigned long, std::string> _stateEventDict;

    static CanonDict* _instance;

    CanonDict(void);
    


};


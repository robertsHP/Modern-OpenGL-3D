#ifndef DEBUG_H
#define DEBUG_H

#include <string>

#define _CODELOC_ __PRETTY_FUNCTION__

namespace Engine::Debug {
    extern std::string logText;

    void print (std::string txt);
//    void print (char *txt);
    void println (std::string txt);
//    void println (char *txt);
    void log (const std::string type, const std::string message, const std::string codeLoc = __PRETTY_FUNCTION__);
    void saveLog ();
    std::string getMessageType (const unsigned messageType);
}

#endif // DEBUG_H

#include "Debug.h"

#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>

namespace Engine::Debug {
    std::string logText;

    void print (std::string txt) {
        std::cout << txt;
    }
//    void print (char *txt) {
//        std::cout << txt;
//    }
    void println (std::string txt) {
        std::cout << txt << std::endl;
    }
//    void println (char *txt) {
//        std::cout << txt << std::endl;
//    }
    void log (const std::string type, const std::string message, const std::string codeLoc) {
       std::time_t currentTime;
       std::tm *localTime;
       std::stringstream stream;

       currentTime = std::time(0);
       localTime = localtime(&currentTime);
       stream << localTime->tm_mday << '.' << localTime->tm_mon << '.' << localTime->tm_year << '|'
              << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec << '|'
              << type << '|';
       if(codeLoc != "")
           stream << codeLoc << '|';
       stream << message;
       std::cout << stream.str() << std::endl;
       Debug::logText += stream.str();
    }
    void saveLog () {
        std::time_t currentTime;
        std::tm *localTime;
        std::ofstream out;
        std::string finName;
        std::stringstream stream;

        currentTime = std::time(0);
        localTime = localtime(&currentTime);
        stream << localTime->tm_mday << '-' << localTime->tm_mon << '-' << localTime->tm_year << '-'
               << localTime->tm_hour << '-' << localTime->tm_min << '-' << localTime->tm_sec;
        finName = "CrashLog" + stream.str() + ".txt";
        out.open(finName);
        out << Debug::logText;
        out.close();
    }
}

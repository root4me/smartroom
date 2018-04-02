#ifndef _JSONHANDLER_h
#define _JSONHANDLER_h

#include <Arduino.h>



class JSONHandler {
private:

public:
String alive();
String lightSensor(int value);
String registerdevice (String name, String server);
};

#endif

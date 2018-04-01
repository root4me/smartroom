
#include <Arduino.h>
#include <JSONHandler.h>
#include <ArduinoJson.h> // Install ArduinoJson library https://arduinojson.org/

String JSONHandler::alive()
{

        StaticJsonBuffer<50> jsonBuffer;
        String retval;

        JsonObject& root = jsonBuffer.createObject();
        root["status"] = "alive";

        root.prettyPrintTo(Serial);
        root.printTo(retval);

        return retval;

}

String JSONHandler::registerdevice (String name, String server)
{
        StaticJsonBuffer<JSON_OBJECT_SIZE(7) + 130 > jsonBuffer;
        String retval;

        JsonObject& root = jsonBuffer.createObject();

        root["name"] = name;
        root["ip"] = server;
        root["type"] = "lamp";
        root["on"] = "/" + name + "/on";
        root["off"] = "/" + name + "/off";
        root["config"] = "/" + name + "config";
        root["status"] = "/";

        root.printTo(retval);

        return retval;

}

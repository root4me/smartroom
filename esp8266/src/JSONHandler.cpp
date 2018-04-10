
#include <Arduino.h>
#include <JSONHandler.h>
#include <ArduinoJson.h> // Install ArduinoJson library https://arduinojson.org/

#include <Lamp.h>

String JSONHandler::alive()
{

        StaticJsonBuffer<50> jsonBuffer;
        String retval;

        JsonObject &root = jsonBuffer.createObject();
        root["status"] = "alive";

        root.prettyPrintTo(Serial);
        root.printTo(retval);

        return retval;
}

String JSONHandler::registerdevice(String name, String server)
{
        StaticJsonBuffer<JSON_OBJECT_SIZE(7) + 130> jsonBuffer;
        String retval;

        JsonObject &root = jsonBuffer.createObject();

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

String JSONHandler::lightSensor(int value)
{
        const size_t bufferSize = JSON_OBJECT_SIZE(2);
        DynamicJsonBuffer jsonBuffer(bufferSize);

        String retval;

        JsonObject &root = jsonBuffer.createObject();
        root["sensor"] = "lightSensor";
        root["value"] = value;

        root.printTo(retval);

        return retval;
}

String JSONHandler::lampStatus(Lamp& floorLamp)
{
        StaticJsonBuffer<50> jsonBuffer;
        String retval;

        JsonObject& root = jsonBuffer.createObject();
        if (floorLamp.isSwitchedOn())
        {
                root["status"] = "on";
        }
        else
        {
                root["status"] = "off";
        }

        root.printTo(retval);

        return retval;

}
#include <Arduino.h>
#include <JSONHandler.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

// Update SSID and password before uploading to device
const char *SSID = "SSID";
const char *PASSWORD = "PASSWORD";

ESP8266WebServer server(80);
JSONHandler jsonHandler;

void handleroot();

void setup()
{

    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
        digitalWrite(LED_BUILTIN, HIGH);
    }

    server.on("/", handleroot);
    server.begin();

    Serial.println(WiFi.localIP().toString());
    Serial.println((String)WiFi.localIP());
}

void loop()
{
    server.handleClient();
}

void handleroot()
{

    server.send(200, "text/plain", jsonHandler.alive());
}
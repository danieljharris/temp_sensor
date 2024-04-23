#ifndef ServerRest_h
#define ServerRest_h

#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include <Temperature.h>

#define HTTP_REST_PORT 8080

class Server_Rest {
public:
    ~Server_Rest();
    void begin(Temperature* temp);
    void handle();

private:
    ESP8266WebServer server;

    // Rest Endpoints
    void endpointAll();
    void endpointTemprature();
    void endpointHumidity();
    void endpointHeatIndex();

    Temperature* temp;
};

#endif
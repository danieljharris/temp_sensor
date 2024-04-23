#include "ServerRest.h"

Server_Rest::~Server_Rest() { server.stop(); }

void Server_Rest::begin(Temperature* temp) {
    // Serial.println("Starting REST server...");

    server.on("/", HTTP_GET, [this](){endpointAll();});
    server.on("/temp", HTTP_GET, [this](){endpointTemprature();});
    server.on("/humidity", HTTP_GET, [this](){endpointHumidity();});
    server.on("/heatIndex", HTTP_GET, [this](){endpointHeatIndex();});

    server.begin(HTTP_REST_PORT);

    this->temp = temp;
}

void Server_Rest::handle() { server.handleClient(); }

// curl http://192.168.0.91:8080/ -X GET
void Server_Rest::endpointAll() {
    // Serial.println("Endpoint: /");

    server.send(200, "application/json",
        "{\"temperature\":" + String(temp->getTemperature()) +
        ",\"humidity\":" + String(temp->getHumidity()) +
        ",\"heatIndex\":" + String(temp->getHeatIndex()) +
    "}");
}

// curl http://192.168.0.91:8080/temp -X GET
void Server_Rest::endpointTemprature() {
    server.send(200, "application/json", "{\"temperature\":" + String(temp->getTemperature()) + "}");
}

// curl http://192.168.0.91:8080/humidity -X GET
void Server_Rest::endpointHumidity() {
    server.send(200, "application/json", "{\"humidity\":" + String(temp->getHumidity()) + "}");
}

// curl http://192.168.0.91:8080/heatIndex -X GET
void Server_Rest::endpointHeatIndex() {
    server.send(200, "application/json", "{\"heatIndex\":" + String(temp->getHeatIndex()) + "}");
}
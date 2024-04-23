#include <Arduino.h>
#include "OTA.h"
#include "Network.h"
#include "ServerRest.h"

Server_Rest server = Server_Rest();
Temperature temp = Temperature();

void hw_wdt_disable() {*((volatile uint32_t*) 0x60000900) &= ~(1);}
void hw_wdt_enable() {*((volatile uint32_t*) 0x60000900) |= 1;}

void setup() {
    hw_wdt_disable();

    Serial.begin(115200);
    Serial.println("\n\nStarting...");

    Serial.println("Starting network...");
    Network("IOOFPMNEAKIO", "KZe8#wUkBsK$");
    
    Serial.println("Starting OTA...");
    OTA("Heating");

    Serial.println("Starting server...");
    server.begin(&temp);

    Serial.println("Temperature sensor started!");
}

void loop() {
    ArduinoOTA.handle();
    server.handle();
    delay(2);
}
#ifndef Temperature_h
#define Temperature_h

// #include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
static DHT dht(DHTPIN, DHTTYPE);

class Temperature {
public:
    Temperature();
    float getTemperature();
    float getHumidity();
    float getHeatIndex();
};

#endif
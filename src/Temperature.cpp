#include "Temperature.h"

Temperature::Temperature() {
    dht.begin();
}

float Temperature::getTemperature() {
    return dht.readTemperature() - 7.3;
}

float Temperature::getHumidity() {
    return dht.readHumidity();
}

float Temperature::getHeatIndex() {
    return dht.computeHeatIndex(dht.readTemperature(), dht.readHumidity(), false);
}
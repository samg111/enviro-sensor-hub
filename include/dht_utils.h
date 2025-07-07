#ifndef DHT_UTILS_H
#define DHT_UTILS_H

#include <Arduino.h>
#include <DHT.h>

struct DhtData{
    float humidity;
    float temperatureF;
    float temperatureC;
};

DhtData readTempAndHumidity(DHT &dht);

#endif
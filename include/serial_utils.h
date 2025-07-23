#ifndef INCLUDE_SERIAL_UTILS_H_
#define INCLUDE_SERIAL_UTILS_H_

#include <Arduino.h>
#include "dht_utils.h"

void printSensorData(const DhtData& data);
void printSensorError();
void printLightLevel(int lightLevel);

#endif  // INCLUDE_SERIAL_UTILS_H_

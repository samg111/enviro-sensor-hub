#ifndef SERIAL_UTILS_H
#define SERIAL_UTILS_H

#include <Arduino.h>
#include "dht_utils.h"

void printSensorData(const DhtData& data);
void printSensorError();

#endif
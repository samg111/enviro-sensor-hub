#ifndef BUZZER_UTILS_H
#define BUZZER_UTILS_H

#include <Arduino.h>

void checkTempThreshold(uint8_t buzzerPin, float temperatureF, float temperatureThreshold);

#endif
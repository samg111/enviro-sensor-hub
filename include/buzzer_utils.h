#ifndef INCLUDE_BUZZER_UTILS_H_
#define INCLUDE_BUZZER_UTILS_H_

#include <Arduino.h>

void checkTempThreshold(uint8_t buzzerPin, float temperatureF, float temperatureThreshold);

#endif  // INCLUDE_BUZZER_UTILS_H_

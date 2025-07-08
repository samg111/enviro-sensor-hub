#ifndef INCLUDE_DISPLAY_UTILS_H_
#define INCLUDE_DISPLAY_UTILS_H_

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>

void initLcdDisplay(LiquidCrystal *lcd);
void displaySensorData(LiquidCrystal *lcd, float temperatureF, float humidity);
void displaySensorError(LiquidCrystal *lcd);

#endif  // INCLUDE_DISPLAY_UTILS_H_

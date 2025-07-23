#ifndef INCLUDE_DISPLAY_UTILS_H_
#define INCLUDE_DISPLAY_UTILS_H_

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>

void initLcdDisplay(LiquidCrystal *lcd, int BACKLIGHT_TRANSISTOR_PIN);
void displaySensorData(LiquidCrystal *lcd, float temperatureF, float humidity);
void displaySensorError(LiquidCrystal *lcd);
void changeLcdBacklight(int lightLevel, int BACKLIGHT_TRANSISTOR_PIN);

#endif  // INCLUDE_DISPLAY_UTILS_H_

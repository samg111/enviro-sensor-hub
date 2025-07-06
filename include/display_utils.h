#ifndef DISPLAY_UTILS_H
#define DISPLAY_UTILS_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>

void initLcdDisplay(LiquidCrystal &lcd);
void displaySensorData(LiquidCrystal &lcd, float temperatureF, float humidity);
void displaySensorError(LiquidCrystal &lcd);

#endif
#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>
#include "display_utils.h"
#include "buzzer_utils.h"
#include "dht_utils.h"
#include "serial_utils.h"

#define DHTPIN 3
#define DHTTYPE DHT11

#define BUZZER_PIN 13

// globals
float temperatureThreshold = 85.0;

// lcd display: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

// dht11 temp and humidity sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  initLcdDisplay(&lcd);
}

void loop() {
  DhtData dhtData = readTempAndHumidity(&dht);
  if (isnan(dhtData.humidity) || isnan(dhtData.temperatureF)) {
    printSensorError();
    displaySensorError(&lcd);
    return;
  }
  displaySensorData(&lcd, dhtData.temperatureF, dhtData.humidity);
  printSensorData(dhtData);
  checkTempThreshold(BUZZER_PIN, dhtData.temperatureF, temperatureThreshold);
  delay(5000);
}

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
#define LDR_PIN A0
#define BACKLIGHT_TRANSISTOR_PIN 9

// globals
float temperatureThreshold = 85.0;

// lcd display: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

// dht11 temp and humidity sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(BACKLIGHT_TRANSISTOR_PIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  // analogWrite(BACKLIGHT_TRANSISTOR_PIN, 255);
  initLcdDisplay(&lcd, BACKLIGHT_TRANSISTOR_PIN);
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

  int ldrValue = analogRead(LDR_PIN);
  int lightLevel = map(ldrValue, 0, 1023, 0, 255);

  printLightLevel(lightLevel);
  changeLcdBacklight(lightLevel, BACKLIGHT_TRANSISTOR_PIN);
  // Serial.print("Light level: ");
  // Serial.println(lightLevel);
  // analogWrite(BACKLIGHT_TRANSISTOR_PIN, lightLevel);

  checkTempThreshold(BUZZER_PIN, dhtData.temperatureF, temperatureThreshold);
  delay(5000);
}

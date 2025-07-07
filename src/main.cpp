#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>
#include "display_utils.h"
#include "buzzer_utils.h"

#define DHTPIN 3    
#define DHTTYPE DHT11 

#define BUZZER_PIN 13

// lcd display: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

// dht11 temp and humidity sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  initLcdDisplay(lcd);
}

void loop() {
  float temperatureThreshold = 90.0;
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = temperatureC * 9.0 / 5.0 + 32.0;

  if (isnan(humidity) || isnan(temperatureF)) {
    Serial.println("Failed to read from DHT sensor");
    displaySensorError(lcd);
    return;
  }
  Serial.println("Temperature: " + String(temperatureF, 1) + " °F  |  Humidity: " + String(humidity, 1) + " %");
  displaySensorData(lcd, temperatureF, humidity);
  checkTempThreshold(BUZZER_PIN, temperatureF, temperatureThreshold);
  // if (tempuratureF > temperatureThreshold){
  //   digitalWrite(BUZZER_PIN, HIGH);
  // } else {
  //   digitalWrite(BUZZER_PIN, LOW);
  // }
  delay(5000);
}
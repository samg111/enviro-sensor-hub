#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>
#include "display_utils.h"

#define DHTPIN 3    
#define DHTTYPE DHT11 

// lcd display: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

// dht11 temp and humidity sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();
  // lcd.print("Hello, world!");

  initLcdDisplay(lcd);
}

void loop() {
  float humidity = dht.readHumidity();
  float celsius = dht.readTemperature();
  float fahrenheit = celsius * 9.0 / 5.0 + 32.0;

  if (isnan(humidity) || isnan(fahrenheit)) {
    Serial.println("Failed to read from DHT sensor");
    lcd.clear();
    lcd.print("Sensor error");
    return;
  }

  Serial.println("Temperature: " + String(fahrenheit, 1) + " °F  |  Humidity: " + String(humidity, 1) + " %");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: " + String(fahrenheit, 1) + (char)223 + "F");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + String(humidity, 1) + "%");
  delay(5000);
}
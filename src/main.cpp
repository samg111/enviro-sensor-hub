#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 3    
#define DHTTYPE DHT11 

// lcd display: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);

// dht11 temp and humidity sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();
  lcd.print("Hello, world!");
}

void loop() {
  delay(5000);

  float humidity = dht.readHumidity();
  float celsius = dht.readTemperature();
  float fahrenheit = celsius * 9.0 / 5.0 + 32.0;

  if (isnan(humidity) || isnan(fahrenheit)) {
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(fahrenheit);
  Serial.print(" °F  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
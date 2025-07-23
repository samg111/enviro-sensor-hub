#include "display_utils.h"

void initLcdDisplay(LiquidCrystal *lcd, int BACKLIGHT_TRANSISTOR_PIN) {
    lcd->begin(16, 2);
    analogWrite(BACKLIGHT_TRANSISTOR_PIN, 255);
    lcd->print("Initializing");
    delay(3000);
    lcd->clear();
}

void displaySensorData(LiquidCrystal *lcd, float temperatureF, float humidity) {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Temp: " + String(temperatureF, 1) + static_cast<char>(223) + "F");
    lcd->setCursor(0, 1);
    lcd->print("Humidity: " + String(humidity, 1) + "%");
}

void displaySensorError(LiquidCrystal *lcd) {
    lcd->clear();
    lcd->print("Sensor error");
}

void changeLcdBacklight(int lightLevel, int BACKLIGHT_TRANSISTOR_PIN) {
    analogWrite(BACKLIGHT_TRANSISTOR_PIN, lightLevel);
}

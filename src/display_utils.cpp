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
    lcd->print("Temp: ");
    lcd->print(String(temperatureF, 1));
    lcd->print(static_cast<char>(223));
    lcd->print("F");
    lcd->setCursor(0, 1);
    lcd->print("Humidity: ");
    lcd->print(String(humidity, 1));
    lcd->print("%");
}

void displaySensorError(LiquidCrystal *lcd) {
    lcd->clear();
    lcd->print("Sensor error");
}

void changeLcdBacklight(int lightLevel, int BACKLIGHT_TRANSISTOR_PIN) {
    analogWrite(BACKLIGHT_TRANSISTOR_PIN, lightLevel);
}

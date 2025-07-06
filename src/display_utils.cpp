#include "display_utils.h"

void initLcdDisplay(LiquidCrystal &lcd){
    lcd.begin(16, 2);
    lcd.print("Initializing");
    delay(3000);
    lcd.clear();
}

void displaySensorData(LiquidCrystal &lcd, float temperatureF, float humidity){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: " + String(temperatureF, 1) + (char)223 + "F");
    lcd.setCursor(0, 1);
    lcd.print("Humidity: " + String(humidity, 1) + "%");
}
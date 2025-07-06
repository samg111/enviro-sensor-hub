#include "display_utils.h"

void initLcdDisplay(LiquidCrystal &lcd){
    lcd.begin(16, 2);
    lcd.print("Initializing");
    delay(3000);
    lcd.clear();
}


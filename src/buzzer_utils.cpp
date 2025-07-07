#include "buzzer_utils.h"

void checkTempThreshold(uint8_t buzzerPin, float temperatureF, float temperatureThreshold){
    if (temperatureF > temperatureThreshold){
        digitalWrite(buzzerPin, HIGH);
    } else {
        digitalWrite(buzzerPin, LOW);
    }
}
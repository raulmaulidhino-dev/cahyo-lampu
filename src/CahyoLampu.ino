#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int outsideLdrPin = A0;
const int insideLdrPin = A2;

const int outsideLedPins[] = {3, 5, 6, 9};
const int insideLedPins[] = {10, 11};

LiquidCrystal_I2C lcd(0x27, 16, 2);

int mapLDRtoLED(int ldrValue) {
  return round((float)ldrValue * 255 / 1023);
}

int getLdrValue(int ldrPin) {
  return analogRead(ldrPin);
}

int getLEDBrightness(int ledValue) {
  return map(ledValue, 0, 255, 0, 100);
}

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
}

void loop() {
  // Check Brightness Inside
  int insideLdrValue = getLdrValue(insideLdrPin);
  int insideLedValue = mapLDRtoLED(insideLdrValue);

  int insideLedCounts = sizeof(insideLedPins) / sizeof(insideLedPins[0]);

  for (int i = 0; i < insideLedCounts; i++) {
    analogWrite(insideLedPins[i], insideLedValue);
  }

  // Check Brightness Outside
  int outsideLdrValue = analogRead(outsideLdrPin);
  int outsideLedValue = mapLDRtoLED(outsideLdrValue);

  int outsideLedCounts = sizeof(outsideLedPins) / sizeof(outsideLedPins[0]);

  for (int i = 0; i < outsideLedCounts; i++) {
    analogWrite(outsideLedPins[i], outsideLedValue);
  }

  // Show Inside LEDs Brightness
  lcd.setCursor(0, 0);
  int insideLedBrightness = getLEDBrightness(insideLedValue);
  lcd.print("Inside :" + String(insideLedBrightness) + "%");

  // Show Outside LEDs Brightness
  lcd.setCursor(0, 1);
  int outsideLedBrightness = getLEDBrightness(outsideLedValue);
  lcd.print("Outside :" + String(outsideLedBrightness) + "%");

  delay(200);
}
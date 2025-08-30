#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27 (sometimes 0x3F)

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
}

void loop() {
  static unsigned long prevMillis = 0;
  static int seconds = 0;

  if (millis() - prevMillis >= 1000) {
    prevMillis = millis();
    seconds++;
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(seconds);
    lcd.print("s   "); // Extra spaces clear old digits
  }
}

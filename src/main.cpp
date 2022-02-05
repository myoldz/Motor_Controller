#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define LCD I2C address
const int i2c_addr = 0x27;

#define POT_PIN A3


LiquidCrystal_I2C lcd(i2c_addr, 20, 4);

void setup() {
  Serial.begin(9600);
  /*
  Serial.println("Scanning I2C bus for LCD");
  byte count = 0;
  Wire.begin();
  for( byte i = 8; i < 120; i++ ) {
    Wire.beginTransmission(i);
    if(Wire.endTransmission() == 0) {
      Serial.print("Found address: ");
      Serial.print(i, DEC);
      Serial.print(" (0x");
      Serial.print(i, HEX);
      Serial.println(")");
      count++;
      delay(1);
    }
  }
  Serial.println("Done.");
  Serial.print("Found ");
  Serial.print(count, DEC);
  Serial.println(" device(s).");
  */

  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello");
  lcd.setCursor(2,1);
  lcd.print("Arduino!");
}

void loop() {
  // put your main code here, to run repeatedly:
}

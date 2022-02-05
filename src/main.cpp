#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


const int i2c_addr = 0x27;    //LCD I2C address

#define POT_PIN A3

// Global variables
long potValNew = 0.0;
long potValOld = 0.0;


// Initialize stuff
LiquidCrystal_I2C lcd(i2c_addr, 16, 2);

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();
}

void loop() {
  potValNew = analogRead(POT_PIN);
  if(potValNew > potValOld * 1.05 || potValNew < potValOld * 0.95){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pot vlaue > ");
    lcd.print(potValNew);
   }

  delay(1000);
  
}

void i2cList(){
  
  // Use this code to find the address of the I2C devices attached

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
}


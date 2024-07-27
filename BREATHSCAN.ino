#include <LiquidCrystal_I2C.h>
#include "pitches.h"

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

const int smokeSensor = 4;
#define BUZZER_PIN  18 // ESP32 pin GPIO18 connected to piezo buzzer

int melody[] = {NOTE_B0};
int noteDurations[] = {2};

void setup() {
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  Serial.begin(9600);

  // initialize buzzer
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int digitalNumber = analogRead(smokeSensor); // Generates a digital number from 0 to 4095
  Serial.println(digitalNumber); 
  
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Reading: ");
  lcd.print(digitalNumber);
  delay(500);

  if (digitalNumber > 2000) {
    // if smoke level exceeds threshold, sound the buzzer and show warning
    for (int thisNote = 0; thisNote < 3; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(BUZZER_PIN, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 0.5;
      delay(pauseBetweenNotes);
      noTone(BUZZER_PIN);
    }
    
    // set cursor to first column, second row
    lcd.setCursor(0, 1);
    lcd.print("TIDAK AMAN");
  } else {
    // if smoke level is safe, clear the second row
    lcd.setCursor(0, 1);
    lcd.print("AMAN");
  }

  delay(500);
  lcd.clear();
}

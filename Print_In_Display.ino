#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: "Mine is 16x2 matrix" 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, Everyone!");
}

void loop() {
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.print("I'm Jyoti Raul");
}

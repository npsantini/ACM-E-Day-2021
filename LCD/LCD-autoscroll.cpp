/*
  LiquidCrystal Library - Hello World (with scrolling)

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints a scrolling "Hello World!" 
 to the LCD.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD GND pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 16 Apr 2021
 by Tyler Burkett

 This example code is in the public domain.

 To learn more about the LuquidCrystal library, go to:
 https://www.arduino.cc/en/Reference/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// create the message we want to print out
String message = "hello, world!";

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  
  // set the cursor to (0,0) aka the top left
  lcd.setCursor(0, 0);

  // print message one character at a time
  for (int i = 0; i < message.length(); i++) {
  	lcd.print(message[i]);
  	delay(500);
  }

  // set the cursor to (16,1) aka the bottom right
  lcd.setCursor(16, 1);

  // set the display to automatically scroll:
  lcd.autoscroll();

  // print message one character at a time
  for (int i = 0; i < message.length(); i++) {
  	lcd.print(message[i]);
  	delay(500);
  }

  // turn off automatic scrolling
  lcd.noAutoscroll();

  // clear screen for the next loop:
  lcd.clear();
}
 

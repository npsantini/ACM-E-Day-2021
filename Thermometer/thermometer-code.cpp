// Library needed to work with servo motors
#include <Servo.h>

// Initialize the Temperature variable
int Temperature = 0;

// Create a servo object
Servo servo_7;

void setup() {
  // Attach pin 7 to the servo object
  servo_7.attach(7, 500, 2500);
  
  // Set pin A2 to accept input
  pinMode(A2, INPUT);
}

void loop(){
  // Initialize servo position to 0
  servo_7.write(0);
  
  // Set the temperature to a modified value of A2 to degrees celsius
  // This formula was provided by the sensor in tinkercad
  Temperature = -40 + 0.488155 * (analogRead(A2) - 20);
  
  // If temperature is cold in degrees Celcius
  if (Temperature < 35) {
    // Move servo 145 degrees
    servo_7.write(145);
  }
  // If temperature is normal in degrees Celcius
  if (Temperature >= 35 && Temperature < 38) {
    // Move servo 90 degrees
    servo_7.write(90);
  }
  // If temperature is fever in degrees Celcius
  if (Temperature >= 38) {
    // Move servo 40 degrees
    servo_7.write(40);
  }
  
  // Delay a little bit to improve simulation performance
  delay(10);
}

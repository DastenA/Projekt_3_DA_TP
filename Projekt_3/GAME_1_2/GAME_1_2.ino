// Define the pins for the RGB LED
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

const int green_button = 6;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

int buttonState = 0;  // variable for reading the pushbutton status

unsigned long startTime;
const unsigned long duration = 20000; // duration for the LED 

void setup() {
  // Set the RGB LED pins as output
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(green_button, INPUT);
  

  // Initialize start time
  startTime = millis();
    Serial.begin(9600);
}

void loop() {
  updatecolor();
  updatebutton();
}

void updatecolor() {  // Check if the time duration has not yet elapsed
  if (millis() - startTime < duration) {
    // Generate a random number (0-2) to represent the color
    int color = 0 + rand()% 4 + 1;

    // Set RGB values based on the selected color
    switch (color) {
      case 0: // Red
        analogWrite(RED_PIN, 255);
        analogWrite(GREEN_PIN, 0);
        analogWrite(BLUE_PIN, 0);
        Serial.println(" - RED"); // Prints out " - RED"
            Serial.println (color);

        break;
        
      case 1: // Green
        analogWrite(RED_PIN, 0);
        analogWrite(GREEN_PIN, 255);
        analogWrite(BLUE_PIN, 0);
        Serial.println(" - GREEN"); // Prints out " - GREEN" 
        break;
        
      case 2: // Blue
        analogWrite(RED_PIN, 0);
        analogWrite(GREEN_PIN, 0);
        analogWrite(BLUE_PIN, 255);
        Serial.println(" - BLUE"); // Prints out " - BLUE" REVERSED

        break;
      case 3: // Yellow (combination of red and green)
       analogWrite(RED_PIN, 255);
       analogWrite(GREEN_PIN, 255);
       analogWrite(BLUE_PIN, 0);
       Serial.println(" - YELLOW"); // Prints out " - YELLOW"
       break; 
    }

    // Delay for a short period before changing color again
    delay(800); // Adjust the delay time as needed
  } 
  else {
    // Turn off the RGB LED
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
  }}

  void updatebutton()
  {
  // read the state of the pushbutton value:
  buttonState = digitalRead(green_button);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

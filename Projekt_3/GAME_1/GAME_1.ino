// Define the pins for the RGB LED
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

void setup() {
  // Set the RGB LED pins as output
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  // Generate a random number (0-3) to represent the color
  int color = random(4);

  // Set RGB values based on the selected color
  switch (color) {
    case 0: // Red
      analogWrite(RED_PIN, 255);
      analogWrite(GREEN_PIN, 0);
      analogWrite(BLUE_PIN, 0);
      break;
    case 1: // Green
      analogWrite(RED_PIN, 0);
      analogWrite(GREEN_PIN, 255);
      analogWrite(BLUE_PIN, 0);
      break;
    case 2: // Blue
      analogWrite(RED_PIN, 0);
      analogWrite(GREEN_PIN, 0);
      analogWrite(BLUE_PIN, 255);
      break;
    case 3: // Yellow (combination of red and green)
      analogWrite(RED_PIN, 255);
      analogWrite(GREEN_PIN, 255);
      analogWrite(BLUE_PIN, 0);
      break;
  }

  // Delay for a short period before changing color again
  delay(500); // Adjust the delay time as needed
}
 

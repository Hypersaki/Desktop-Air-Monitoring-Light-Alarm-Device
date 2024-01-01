// Define the touch sensor pin
const int touchSensorPin = 2;  // Change this to the pin you've connected the sensor to
const int ledPin = LED_BUILTIN;  // Most Arduino boards have a built-in LED on pin 13

void setup() {
  pinMode(touchSensorPin, INPUT); // Initialize the touch sensor pin as an input
  pinMode(ledPin, OUTPUT); // Initialize the LED pin as an output
  Serial.begin(9600); // Start serial communication at 9600 baud
}

void loop() {
  int sensorValue = digitalRead(touchSensorPin); // Read the sensor value
  
  // Check if the sensor is touched
  if (sensorValue == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Sensor touched"); // Print message to serial monitor
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
    Serial.println("Sensor not touched"); // Print message to serial monitor
  }

  delay(100); // Short delay for debounce
}

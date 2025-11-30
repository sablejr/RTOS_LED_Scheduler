// RTOS-style LED Task Scheduler Demo
// Author: Marc Dugas

// LED pins
const int led1 = 8; // green light
const int led2 = 9; // blue light
const int led3 = 10; // red light

// Timing variables
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

// Intervals for tasks
const long interval1 = 500;   // LED1 blink 500ms
const long interval2 = 20;    // LED2 fade using PWM
const long interval3 = 1000;  // LED3 counter print

// LED2 brightness
int brightness = 0;
int fadeAmount = 5;

// Counter for LED3
int counter = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  unsigned long currentMillis = millis();

  // Task 1: LED1 blink
  if(currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    digitalWrite(led1, !digitalRead(led1)); // toggle LED1
  }

  // Task 2: LED2 fade
  if(currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    analogWrite(led2, brightness);
    brightness += fadeAmount;
    if(brightness <= 0 || brightness >= 255) fadeAmount = -fadeAmount;
  }

  // Task 3: LED3 counter print
  if(currentMillis - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis;
    counter++;
    digitalWrite(led3, counter % 2); // blink LED3 every second
    Serial.print("Counter: ");
    Serial.println(counter);
  }
}

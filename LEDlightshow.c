int led1Pin = 10;  // the pin for the first LED
int led2Pin = 11;  // the pin for the second LED
int led3Pin = 12;  // the pin for the third LED

void setup() {
  pinMode(led1Pin, OUTPUT);  // set the first LED pin as an output
  pinMode(led2Pin, OUTPUT);  // set the second LED pin as an output
  pinMode(led3Pin, OUTPUT);  // set the third LED pin as an output
}

void loop() {
  // set random brightness levels for each LED
  int led1Brightness = random(0, 100);
  int led2Brightness = random(0, 100);
  int led3Brightness = random(0, 100);
  
  // turn on each LED with its respective brightness level
  analogWrite(led1Pin, led1Brightness);
  analogWrite(led2Pin, led2Brightness);
  analogWrite(led3Pin, led3Brightness);
  
  // wait for a random amount of time before turning the LEDs off
  delay(random(50, 500));
  
  // turn off all the LEDs
  analogWrite(led1Pin, 0);
  analogWrite(led2Pin, 0);
  analogWrite(led3Pin, 0);
  
  // wait for a random amount of time before starting the loop again
  delay(random(50, 500));
}

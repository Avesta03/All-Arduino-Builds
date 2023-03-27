int ledPin1 = 10;  // the pin for the first LED
int ledPin2 = 11;  // the pin for the second LED
int ledPin3 = 12;  // the pin for the third LED

void setup() {
  pinMode(ledPin1, OUTPUT);  // set the first LED pin as an output
  pinMode(ledPin2, OUTPUT);  // set the second LED pin as an output
  pinMode(ledPin3, OUTPUT);  // set the third LED pin as an output
}

void loop() {
  // loop from 0 to 150 and back down to 0
  for (int i = 0; i <= 150; i++) {
    analogWrite(ledPin1, i);  // set the brightness of the first LED
    analogWrite(ledPin2, i);  // set the brightness of the second LED
    analogWrite(ledPin3, i);  // set the brightness of the third LED
    delay(10);  // wait a little bit before continuing the loop
  }
  
  for (int i = 150; i >= 0; i--) {
    analogWrite(ledPin1, i);  // set the brightness of the first LED
    analogWrite(ledPin2, i);  // set the brightness of the second LED
    analogWrite(ledPin3, i);  // set the brightness of the third LED
    delay(10);  // wait a little bit before continuing the loop
  }
}

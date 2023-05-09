//// Arduino Libraries ////

/// Random Numbers

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int number = random(1, 7);
    Serial.println(number);
    delay(500);
}

// The output above isn't really random numbers (but pseudo-random as they have a *random distribution* - i.e. if you ran this and collected 1M numbers, you'd probably have approx the same number of ones, etc)

// You can add more randomness/become less predictable through randomSeed (which essentially seeds the random number generator and gives it a starting point for the sequence):

void setup()
{
    Serial.begin(9600);
    randomSeed(analogRead(0));
}

void loop()
{
    int number = random(1, 7);
    Serial.println(number);
    delay(500);
}

// For better random no. generation, you'd need hardware random number generators which are sometimes based on random occurences, like cosmic ray events.

/// Math Functions

/ abs(-12) // |-12| = 12 

/ constrain(8, 1, 10) // Returns 8. This func constrains a number to stop it from exceeding a range (number to constrain, start of range, end of range of allowed numbers)

/ map(x, 0, 1023, 0, 5000) // Maps a number in one range into another range (number to map, from range I, from range II, to/destination range I, to range II)

/ max(10, 11) // returns 11 (larger of 2 args)
/ min(10, 11) // returns 10 (smaller of 2 args)

/ pow(2, 5) // returns 32 (intuitive)
/ sqrt(16) // guess

/ sin() cos() tan() // not often used in Arduino, but exist

/ log(10) // log

/// Bit Manipulation
// int variables mostly actually comprise of 16 bits (which can be excessive if you're just trying to store simple true/false values)

int x = 0x8c; // C has a special syntax for using hex numbers - you can assign a hex value to an int like this

int x = 0b10001100 // the binary of the above hex

// Arduino standard library has functions that let you manipulate the 16 bits with an int individually:

int x = 0b10001100;
int bit = bitRead(x, 0); // bitRead function returns the value of a particular bit in an int, so here would assign value 0 to the var 'bit'

// Note how in the second arg, the bit position starts at 0 and goes up to 15. It starts with the least significant bit, so the rightmost bit is bit 0, then to the left is 1, etc

int x = 0b10;
bitWrite(x, 0, 1); // counterpart of bitRead - takes three numbers (num to manipulate, bit position, bit value)

/// Advanced I/O (useful little functions which make input/output tasks easier)

// Generating Tones (tone func allows you to gen a square-wave signal on 1 of the digital output pins - this is usually done to generate an audible tone with a buzzer/loudspeaker)

void setup()
{
}

void loop() {}

// Usually 2 or 3 args - (pin number on which the tone is to be generated, freq of tone in Hz, duration of tone [optional final argument, indefinite if left blank])
// You can stop a tone that is playing using the function noTone - which only requires 1 arg - the pin on which the tone is playing.

/// Feeding Shift Registers 
/* When we don't have enough pins, like when driving a large number of LEDs, a common technique is to use a shift register chip.
   This chip reads data 1 bit at a time, then when it has enough, latches all bits onto a set of outputs (1 per bit) */
/* There's a handy function for this called shiftOut, which takes four arguments:
    - The number of the pin on which the bit to be sent will appear.
    - The number of the pin to be used as a clock pin, which toggles every time a bit is sent.
    - A flag to det whether the bits will be sent starting with the least or most significant bit, known as constants MSBFIRST or LSBFIRST. 
    - The byte of data to be sent. */

/// Interrupts (as Arduinos can only really do one thing at once, interrupts are the closest thing to enjoying lots of threads of execution)
/* Pins D2 and D3 can have interrupts attached to them, wherein these pins act as inputs that if pins receive a signal in a specified way, 
   Arduino's processor will suspend whatever it was doing and run a function attached to that interrupt. */

// Here we blink an LED, but then change blink period when an interrupt is received. 
// This is simulated by connecting a wire between D2 [for UNO, see what equiv is for Mega] and GND, and using the internal pull-up resistor to keep the interrupt high most of the time.

const int interruptPin = 2;
const int ledPin = 13;
int period = 500;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(0, goFast, FALLING); // Very important line in the setup function of this sketch (pin 2 = 0; pin 3 = 1; etc)
}

void loop()
{
    digitalWrite(ledPin, HIGH);
    delay(period);
    digitalWrite(ledPin, LOW);
    delay(period);
}

void goFast()
{
    period = 100;
}

/* The next arg is the name of the function that's to be called after an interrupt, and the final argument is a constant that will be either CHANGE, RISING, or FALLING.
   - If the interrupt mode is CHANGE, then either a RISING from - to 1 or a FALLING from 1 to 0 will both trigger an interrupt.
   You can disable interrupts using the func noInterrupts, which stops all interrupts from both interrupt channels. */
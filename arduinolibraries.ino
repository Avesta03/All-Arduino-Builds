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

// Note how in the second arg, the bit position starts at 0 and goes up to 15. It starts with the least singificant bit, so the rightmost bit is bit 0, then to the left is 1, etc

int x = 0b10;
bitWrite(x, 0, 1); // counterpart of bitRead - takes three numbers (num to manipulate, bit position, bit value)


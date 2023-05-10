//// Data Storage (how to hang on to data even after board has power off/is reset) ////

/// Storing Data in Flash Memory

// To store data in flash memory, you have to include the PROGMEM library as follows:

#include <avr/pgmspace.h> // This tells the compiler to use the pgmspace library for this sketch.

PROGMEM const char letters[26] [maxLen] = { // PROGMEM keyword here indicates that data structure is to be stored in flash, and you can only store constants like this. 
    ".-", "-...", "-.-.", "-..", ".",
    "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", ".-.",
    "...", "-", "..-", "...-", ".--",
    "-..-", "-.--", "--.."

};

// Data structure can't be changed once in the flash, hence the usage of const above. Size of array also has to be specified as 26 letters by maxLen (minus 1) dots and dashes.

void loop()
{
    char ch;
    if (Serial.available() > 0)
    {
        ch = Serial.read();
        if (ch >= 'a' && ch <= 'z') // Using >= and <= to compare characters as each char is actually represented by a number (its ASCII code)
        {
            memcpy_P(&sequence, letters[ch - 'a'], maxLen);
            flashSequence(sequence); // Here we pass through a string of dots and dashes.
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            memcpy_P(&sequence, letters[ch - 'A'], maxLen);
            flashSequence(sequence);
        }
        else if (ch >= '0' && ch <= '9')
        {
            memcpy_P(&sequence, letters[ch - '0'], maxLen);
            flashSequence(sequence);
        }
        else if (ch == ' ')
        {
            delay(dotDelay * 4); // this is the gap between words
        }
    }
}

// Here ^^ we are now storing everything internally in flash, in a way that can only be accessed by the special func memcpy_P to modify the data inside the sequence character array.
// The & char before sequence allows memcypy_P to modify the data inside the sequence character array.

// Your code to get the code string for a Morse letter from the array also has to be modified to look like this:

strcpy_P(buffer, (char*)pgm_read_word(&(letters[ch - 'a'])));

// This uses a buffer var into which PROGMEM string is copied, so it can be used as a regular char array. This needs defining as a global variable:

char buffer[6];

// Such approach works only if data is constant - i.e. data is unchanged while the sketch is running.

// If you have indiv. strings that're formatted for messages to be displayed on SM, you can enclose the string in F():
Serial.println(F("Goodbye World")); // This string will be stored in flash memory, rather than use up RAM.

/// EEPROM (however, is intended for storing persistent data that CAN be changed)
// EEPROM (Electrically Erasable Read-Only Memory) is designed to remember its contents for many years, and isn't actually read-only.

#include <EEPROM.h>

int addr = 0;
char ch;

void setup()
{
    Serial.begin(9600);
    ch = EEPROM.read(addr);
}

void loop()
{
    if (Serial.available() > 0)
    {
        ch = Serial.read();
        EEPROM.write(0, ch); // EEPROm.write takes two args (address [memory loc in EEPROM, should be between 0-1023], data to write to that location, which must be a single byte)
        Serial.println(ch);
    }
    Serial.println(ch);
    delay(1000);
}

// Here we can enter a single-digit letter code into the SM, the sketch then remembers the digit and repeatedly writes it out on the SM.

// Storing an int in EEPROM

int x = 1234;
EEPROM.write(0, highByte(x)); // highByte and lowByte are useful for separating ints into two bytes.
EEPROM.write(1, lowByte(x));

// Here we are storing a two-byte int in locations 0 and 1 of EEPROM. Now, to read the int back out of EEPROM, you must read 2B from the EEPROM and reconstruct the int:

byte high = EEPROM.read(0);
byte low = EEPROM.read(1);
int x = (high << 8) + low; // << operator is a bit shift operator that moves the eight high bytes to the top of the int and then adds in the low byte.







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
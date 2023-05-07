// Morse Code Translator Using LEDs


// Building the Data Structures
char* letters[] = {
    ".-", "-...", "-.-.", ".",
    "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", ".-.",
    "...", "-", "..-", "...-", ".--",
    "-..-", "-.--", "--.."
};

// Above we have an array of string literals!

char* numbers[] = {
    "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."
};

// Defining a couple of global vars (one for delay period for a dot and one to define which pin the LD is attached to)
const int dotDelay = 200;
const int ledPin = 11;

void setup()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

// Implementing the loop function

void loop()
{
    char ch;
    if (Serial.available() > 0)
    {
        ch = Serial.read();
        if (ch >= 'a' && ch <= 'z') // Using >= and <= to compare characters as each char is actually represented by a number (its ASCII code)
        {
            flashSequence(letters[ch - 'a']); // Here we pass through a string of dots and dashes.
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            flashSequence(letters[ch - 'A']);
        }
        else if (ch >= '0' && ch <= '9')
        {
            flashSequence(numbers[ch - '0']);
        }
        else if (ch == ' ')
        {
            delay(dotDelay * 4); // this is the gap between words
        }
    }
}

/* The algorithm for the function is:
   If it's a letter, flash it using the letters array/
   If it's a number, flash it using the numbers array.
   If it's a space, flash four times the dot delay. */


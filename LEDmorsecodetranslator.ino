// Morse Code Translator Using LEDs

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
{}
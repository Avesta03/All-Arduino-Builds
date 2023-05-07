/// Arrays and Strings ///

int durations[] = {200, 200, 200, 500, 500, 500, 200, 200, 200};

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 9; i++)
    {
        Serial.println(durations[i]);
    }
}

void loop() {}

/* Above we create an array and print out all its values to the Serial Monitor.
   You can get the first element of an array like this: durations[0] (#trivial) */

// See LEDmorsecodeSOsbasic.ino for proj on this section

// String Arrays

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("Hello");
    delay(1000);
}

// A string is a sequence of characters and a way you can get Arduino to deal with text. Above sends 'Hello' to the SM once per second.

// String Literals (enclosed in double quotation marks) are actually an array of the type `char`.
/* `char` is similar to `int` in that it's a number, but that number is between 0 and 127 and represents one char like a letter or number or punctuation mark,
    or special character like a tab or line feed. These number codes for letters use ASCII codes. The aforementioned 'Hello' is thus actually an array of characters.
    Note that at the end of a string literal there's a special null character (\0) which indicates the end of the string. */

// String Variables (similar to array vars but they have a useful shorthand method for defining their initial values)

char name[] = "Hello";

// This defines an array of chars and initialises it to the word "Hello." and this will also add a final null value (ASCII 0) to mark the end of the string.

char *name = "Hello"; // This is more common than the aforementioned and equivalent, and the * indicates a pointer i.e. the name point sot the first char element of the char array
 
// You can rewrite the previous sketch to use a variable as well as a string constant:

char message[] = "Hello";

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println(message);
    delay(1000);
}




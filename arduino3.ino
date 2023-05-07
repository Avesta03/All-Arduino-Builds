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

////

// Serial Communication with an Arduino goes like: Computer to {Arduino: USB to Serial {to Microprocessor: UART to Buffer}}
// The USB is converted from USB signal levels and protocol to something the microcontroller on the Arduino board can use.
/* This conversion happens in a special-purpose chip on the Arduino board. The data is then received by a part of the microcontroller called the 
   Universal Asynchronous Receiver/Transmitter (UART) which then places the data it receives into a buffer. */
// The buffer is a special area of memory (128 bytes) that can hold data that is removed as soon as it is read. You can think of it like an email inbox.
// The function Serial.available() checks to see whether you "have mail" and returns the number of bytes of data in the buffer that are waiting for you to read.
// If there aren't any messages to be read, then the function will return a 0.
/* This is why the if statement in LEDmorsecodetranslator.ino checks to see that there are more than 0 bytes available to be read, and if there are,
   then the first thing the statement does i sread the next available char, using the function Serial.read(), which then gets assigned to the local var `ch` */

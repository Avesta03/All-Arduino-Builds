int ledPin = 10;
int delayPeriod = 100;

void setup()
{
    pinMode(ledPin, OUTPUT); 
}

void loop()
{
    digitalWrite(ledPin, HIGH);  // LED turns on
    delay(delayPeriod); // delay occurs
    digitalWrite(ledPin, LOW); // LED turns off
    delay(delayPeriod); // delay occurs

    digitalWrite(ledPin, HIGH);  // LED turns on
    delay(delayPeriod); // delay occurs
    digitalWrite(ledPin, LOW); // LED turns off
    delay(delayPeriod); // delay occurs

    digitalWrite(ledPin, HIGH);  // LED turns on
    delay(delayPeriod); // delay occurs
    digitalWrite(ledPin, LOW); // LED turns off
    delay(delayPeriod); // delay occurs
    // Continue to repeat the above another 17 times

    delay(3000);
}

// OR, a simpler method (through a 'for' loop):

int ledPin = 10;
int ledPin = 11;
int delayPeriod = 100;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 20; i ++)
    {
        digitalWrite(ledPin, HIGH)
        delay(delayPeriod);
        digitalWrite(ledPin, LOW);
        delay(delayPeriod);
    }
    delay(3000);
}

// Downside of loops are that they take a long time - particularly in longer pieces of code (here we're just flashing a LED so it's quick). To improve the efficiency:

int ledPin = 10;
int delayPeriod = 100;
int count = 0;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod);
    digitalWrite(ledPin, LOW);
    delay(delayPeriod);
    count ++; 
    if (count == 20)
    {
        count = 0;
        delay(3000);
    }
}

// You can also use a while command in place of the for command

int i = 0;
while (i < 20)
{
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod);
    digitalWrite(ledPin, LOW);
    delay(delayPeriod);
    i ++; 
}

/// Functions ///

const int ledPin = 10;
const int delayPeriod = 250;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 20; i ++)
    {
        flash();
    }
    delay(3000);
}

void flash() // Calling a function 'flash'
{
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod);
    digitalWrite(ledPin, LOW);
    delay(delayPeriod);
}

/// Parameters ///

const int ledPin = 10;
const int delayPeriod = 250;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    flash(20, delayPeriod);
    delay(3000);
}

void flash(int numFlashes, int d)
{
    for (int i = 0; i < numFlashes; i++)
    {
        digitalWrite(ledPin, HIGH);
        delay(d);
        digitalWrite(ledPin, LOW);
        delay(d);
    }
}

// The loop function now only has two lines in it and most of the work has been moved to the flash function (which now also is supplied with two arguments in parentheses)
// We have to declare the type of variable in the parameters (here they are both int) and are in fact defining new variables.
// But these variables (numFlashes and d) can only be used within the flash function.
// Only info needed from outside the function is to which pin the LED is attached.

// Global, Local, and Static Variables 

int x = 15;
void indicate(int x)
{
    flash(x, 10);
}

// The above does not result in a compilation error but has the issue of two variables called x which can each have different values. 
// The x on the first line is called a global variable (as it can be used anywhere in the program including inside any functions)
// The local x inside the variable, however, has priority and so you cannot use the global variable x initially.
// You can also define variables that aren't parameters but are just for use within a function, and these are called LOCAL variables. e.g:

void indicate(int x)
{
    int timesToFlash = x * 2;
    flash(timesToFlash, 10);
}

// The local variables (timesToFlash) will only exist while the function is running, and disappears when the function has finished its last command.

// Static variables also exist and initialise the variable only the first time the function is run.

const int ledPin = 10;
const int delayPeriod = 250;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    static int count = 0;
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod);
    digitalWrite(ledPin, LOW);
    delay(delayPeriod);
    count ++;
    if (count == 20)
    {
        count = 0;
        delay(3000)
    }
}


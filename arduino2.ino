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

// Downside of loops are that they take a long time - particularly in longer pieces of code (here we're just flashing a LED so it's quick)


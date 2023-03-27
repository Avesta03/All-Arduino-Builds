// Using 'if' statements

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
    delayPeriod = delayPeriod + 100; // adds 100 to the delayPeriod
    if (delayPeriod > 3000) // if delayPeriod > 3000, get set back to 100
    {
        delayPeriod = 100;
    }
}
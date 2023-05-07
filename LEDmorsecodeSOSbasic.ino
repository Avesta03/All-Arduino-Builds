const int ledPin = 11;

int durations[] = {200, 200, 200, 500, 500, 500, 200, 200, 200};

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    for (int i = 0; i < 9; i++)
    {
        flash(durations[i]);
    }
    delay(1000);
}

void flash(int delayPeriod)
{
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod);
    digitalWrite(ledPin, LOW);
    delay(delayPeriod);
}


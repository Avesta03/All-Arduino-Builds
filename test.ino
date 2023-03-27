// Print Numbers Test
void setup()
{
    Serial.begin(9600);
    Serial.println(1234);
}
void loop()
{}

// Arithmetic Test
void setup()
{
    Serial.begin(19600);
    int a = 1;
    int b = 2;
    int c = a + b;
    Serial.println(c);
}
void loop()
{ }

// Celsius-Fahrenheit Converter

void setup()
{
    Serial.begin(9600);
    int degC;
    degC = 20;
    int degF;
    degF = degC * 9 / 5 + 32;
    Serial.println(degF);
}
void loop()
{ }
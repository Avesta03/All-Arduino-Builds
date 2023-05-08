/// Inputs & Outputs

// You can measure digital output voltages with a multimeter, which we do not have.

const int outPin = 3;

void setup()
{
    pinMode(outPin, OUTPUT); // pinMode should be used for every pin that you're using so that ARduino can config the electronic sconnected to that pin to either be input or output
    Serial.begin(9600);
    Serial.println("Enter 1 or 0");
}

void loop()
{
    if (Serial.available() > 0)
    {
        char ch = Serial.read();
        if (ch == '1')
        {
            digitalWrite(outPin, HIGH);
        }
        else if (ch == '0')
        {
            digitalWrite(outPin, LOW);
        }
    }
}

// RIP

// Digital Inputs (most common use of these is to detect when a switch has been closed)
// If the voltage at the input is < 2.5V (halfway to 5V), it will be 0 (off), and if above 2.5V, it will be 1 (on)

const int inputPin = 5;

void setup()
{
    pinMode(inputPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int reading = digitalRead(inputPin);
    Serial.println(reading);
    delay(1000);
}

// As with using an output, you need to tell the Arduino in the setup that you're going to use a pin as an input.
// You then get the value of a digital input using the digitalRead function, which returns either 0 or 1.

// Pull-Up Resistors

/* Upload code above, then input wire into pin 52, then touch the other end and see SM... and start picking up electrical interference
   as a human antenna - otherwise put that other end into 5V and see the text change to ones. Put it into GND and get zeros!! */


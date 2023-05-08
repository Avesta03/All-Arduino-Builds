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

/// Pull-Up Resistors

/* Upload code above, then input wire into pin 52, then touch the other end and see SM... and start picking up electrical interference
   as a human antenna - otherwise put that other end into 5V and see the text change to ones. Put it into GND and get zeros!! */

// Internal Pull-Up Resistors

// Fortunately the Arduino has software-configurable pull-up resistors built into the digital pins, which by default are turned off.

const int inputPin = 5;

void setup()
{
    pinMode(inputPin, INPUT_PULLUP); // Pull-Up resistor is enabled
    Serial.begin(9600);
}

void loop()
{
    int reading = digitalRead(inputPin);
    Serial.println(reading);
    delay(1000);
}

// Debouncing

// When you press a button, the metal contacts in the button bounce. This happens very quickly (e.g. ~200ms) and modern buttons may not even visibly bounce, if at all.

const int inputPin = 52;
const int ledPin = 10;

void setup()
{
    pinMode(ledPin, OUTPUT); // Pull-Up resistor is enabled
    pinMode(inputPin, INPUT_PULLUP);
}

void loop()
{
    int switchOpen = digitalRead(inputPin);
    digitalWrite(ledPin, ! switchOpen); // ! = `not` operator
}

// Now using the wire (D5 + GND) as a switch

const int inputPin = 52;
const int ledPin = 10;
int ledValue = LOW;

void setup()
{
    pinMode(ledPin, OUTPUT); // Pull-Up resistor is enabled
    pinMode(inputPin, INPUT_PULLUP);
}

void loop()
{
    if (digitalRead(inputPin) == LOW)
    {
        ledValue = ! ledValue;
        digitalWrite(ledPin, ledValue);
        // to tackle bouncing, simply add a delay: delay(500); - this will ensure bouncing will have subsided within the 500ms, making toggling more reliable
    }
}

// You can also install a Bounce library to make LED toggling more reliable (but I can't find the library...)

// Analog Outputs (can be tested using a multimeter, which we don't yet have - we will return to this later)

const int outputPin = 3;

void setup()
{
    pinMode(outputPin, OUTPUT);
    Serial.begin(9600);
    Serial.println("Enter Volts 0 to 5");
}

void loop()
{
    if (Serial.available() > 0)
    {
        float volts = Serial.parseFloat();
        int pwmValue = volts * 255.0 / 5.0;
        analogWrite(outputPin, pwmValue); // You can set the value of the output with the analogWrite function
    }
}

// PWM = Pulse Width Modulations which refer to the means of controlling amount of power at output (which is done by rapidly turning the output on and off)
// By controlling variables like brightness using PWM and varying the avg amount of time that the LED is on, you achieve much more linear control of the brightness

// Analog Input (analog inputs give you a value between 0 and 1023 depending ont he voltage at the analog input pin)

const int analogPin = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int reading = analogRead(analogPin); // program reads the analog input using this function
    float voltage = reading / 204.6;
    Serial.print("Reading="); // 
    Serial.print(reading);
    Serial.print("\t\tVolts="); // \t = one tab stop (so the numbers line up)
    Serial.println(voltage);
    delay(500);
}

// A0 to GND; A0 to 5V. Produce results on SM from 0 to 1023.
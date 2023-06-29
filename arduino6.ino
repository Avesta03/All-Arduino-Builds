//// Displays ////

/// Alphanumeric LCD Displays

// The LCD module that we use is an Arduino shield that can just be plugged on top of the board.

// See USBmessageboard.ino for project using LCDs

/// OLED Graphic Displays (Organic LED)
// They're bright and crisp displays and are replacing LD displays in consumer appliances and often use an interface bus called I2C
// Use ftm jumper wires; connect GND on display to GND on Arduino; VCC on display to 5V on Arduino; SCL on display to SCL pin of Arduino; SDA on to SDA.

// I2C is a serial bus standard commonly used to connect sensors and displays to microcontrollers like Arduinos. It uses a data pin (SDA) and clock pin (SCK) to communicate with the microcontroller,
// by sending one serial data 1 bit at a time.

/// Let's create a sketch that counts in seconds up to 9999 then resets to 0 using an OLED.
// Note: before uploading to Arduino, you need to find out the I2C address of the display, which will be a hexadec number (usually 0x3c for cheap eBay OLEDs).

#include <SPI.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(4); // pick an unused pin - this is if your display does not have a reset pin

// Initialise a display variable!

void setup() // Initialises the display 
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // Might have to change the I2C address to a different value
    display.setTextSize(4); // Large font size
    display.setTextColor(WHITE); // anything but black will display in the LED colour!
}

void loop() // Here we clear the display, draw a round-cornered rectangle, set cursor position, and print value of count
{
    static int count = 0;
    display.clearDisplay();
    display.drawRoundRect(0, 0, 127, 63, 8, WHITE);
    display.setCursor(20, 20);
    display.print(count);
    display.display(); // The display will not actually be updated until the command display.display() is run. The variable count is then incremented and there's a delay of 1s.
    count ++;
    if (count > 9999)
    {
        count = 0;
    }
    delay(1000);
}

// AdaFruit GFX library provides all sorts of fancy drawing routines that can be used with the display 
// https://learn.adafruit.com/adafruit-gfx-graphics-library


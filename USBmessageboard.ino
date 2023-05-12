#include <LiquidCrystal.h>

// lcd(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(5, 9, 3, 10, 11, 12);
int numRows = 2;
int numCols = 16;

void setup()
{
    Serial.begin(9600);
    lcd.begin(numRows, numCols);
    lcd.clear(); // clears the display of any text
    lcd.setCursor(0, 0);
    lcd.print("Hello");
    lcd.setCursor(0, 1);
    lcd.print("Xander.");
}

void loop()
{
    if (Serial.available() > 0)
    {
        char ch = Serial.read();
        if (ch == '#')
        {
            lcd.clear();
        }
        else if (ch == '/')
        {
            // new line
            lcd.setCursor(0, 1);
        }
        else
        {
            lcd.write(ch);
        }
    }
}
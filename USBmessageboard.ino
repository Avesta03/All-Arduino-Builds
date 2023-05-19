#include <LiquidCrystal.h>

// lcd(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(5, 9, 3, 10, 11, 12);
int numRows = 2;
int numCols = 16;

void setup() // Starting serial comms so the SM can send commands/initialise the LCD library with the dims of the display being used
{
    Serial.begin(9600);
    lcd.begin(numRows, numCols);
    lcd.clear(); // clears the display of any text
    lcd.setCursor(0, 0);
    lcd.print("Hello");
    lcd.setCursor(0, 1); // move cursor to next line
    lcd.print("Xander."); 
}

void loop() // Most action happens here - which checks for any incoming chars from the SM, dealing with chars one at a time.
{
    if (Serial.available() > 0)
    {
        char ch = Serial.read();
        if (ch == '#') // If char is `#`, then whole sketch is cleared
        {
            lcd.clear();
        }
        else if (ch == '/') // If char is `/`, sketch moves to the second line.
        {
            // new line
            lcd.setCursor(0, 1);
        }
        else // Otherwise, sketch simply displays char at the current cursor position using write (which is like print, but only prints a single char instead of a string of chars)
        {
            lcd.write(ch);
        }
    }
}

// Requires MTF wires.
// RS = 8 = Register Select (set to 1 or 0 depending on whether Arduino is sending data for characters or instructions like making the cursor flash)
// E = 9 = Enable (this is toggled to tell LCD controller chip that the data on the following 4 pins is ready to be read)
// Data 4 = 4 
// Data 5 = 5
// Data 6 = 6
// Data 7 = 7 = These four pins are used to transfer data (LCD controller chip used by the shield can use 8 bit or 4 bit data. Shield above uses 4, hence 4-7 not 0-7)

// e.g. input: #Hello/Xander

/// Other LCD Library functions
// home = same as setCursor(0, 0) - moving cursor to the top left
// cursor - displays a cursor
// noCursor - specifies not to display a cursor
// blink - makes the cursor blink
// noBlink - stops the cursor from blinking
// noDisplay - turns off the display without removing the content
// display - turns the display back on after noDisplay
// scrollDisplayLeft - moves all the text on the display one char position to the left
// scrollDisplayRight - moves all the text on the display one char position to the right
// autoscroll - activates a mode in which, as new chars are added at the cursor, the existing text is pushed in the direction by the functions leftToRight and rightToLeft
// noAutoscroll - turns autoscroll mode off
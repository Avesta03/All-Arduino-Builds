//// IoT Programming
// Need specialised Arduinos or shields to provide network capabilities for local network and internet - we now have this and will make notes.

/// HTTP (Hypertext Transport Protocol) is how Web browsers communicate with a Web server.
// When you go to a page using a browser, it sends a request to the server host with a request, and the server processes it as soon as soon as it's received. 

/// Arduino as a Web Server (let's send a web req to the Arduino and view the results in a browser)

// simple server example

#include <SPI.h>
#include <Ethernet.h>

// MAC address just has to be unique. This should work.
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

Ethernetserver server(80);

void setup() // Initialise the Ethernet library using hte mac address that we set earlier
{
    Serial.begin(9600);
    Ethernet.begin(mac);
    server.begin();
    Serial.print("Server started on: ");
    Serial.println(Ethernet.localIP());
} // Once connection has been established and our network has been allocated an IP address, that's displayed in the SM. 

void loop() // Responsible for servicing any requests that come to the Webs erver from a browser.
{
    // listening for incoming clients
    EthernetClient client = server.available(); // If a request is waiting for a response, then calling server.available will return a client (which is an object)
    if (client)
    {
        while (client.connected()) // Determine whether it's connected to the Web server by calling `client.connected`
        {
            // send a standard http response header
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println();

            // send the body
            client.println("<html><body>");
            client.println("<h1>Arduino Server</h1>");
            client.print("<p>A0=");
            client.print(analogRead(0));
            client.println("</p>");
            client.print("<p>millis="); // Number of milliseconds since the Arduino was last reset
            client.println("</p>");
            client.println("</body></html>");
            client.stop(); // Tells the browser that the message is complete, and the browser then displays the page
        }
        delay(1);
    }
}

/// Web-controlled Arduinos
// Now we'll use an Ethernet shield which allows us to turn the pins D3 to D7 on and off using a Web form.

// Unlike the previous simple server example, we're going to find a way to pass the pin settings to the Arduino, which is a method called 'posting data', and is part of the HTTP standard.
// For this to work, you have to build the posting mechanism into the HTML so that the Arduino returns HTML to the browser, which renders a form.
// Such a form has a selection of On and Off for each pin and an Update button that will send the pin settings to the Arduino.
// When the Update button is pressed, a second req is sent to the Arduino, which will be just like the first req but will this time contain req parameters that contain the values of the pins!

// NOTE: NEED TO IMPLEMENT THIS WITH ACQUIRED ESP8266 INTO ARDUINO BOARD.

#include <SPI.h>
#include <Ethernet.h>

// MAC address just has to be unique. This should work
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // EDIT TO FIT ESP8266?

EthernetServer server(80);

int numPins = 5;
int pins[] = {3, 4, 5, 6, 7};
int pinState[] = {0, 0, 0, 0, 0};
char line1[100];

void setup()
{
  for (int i = 0; i < numPins; i++)
  {
     pinMode(pins[i], OUTPUT);
  }
  Serial.begin(9600);
  Ethernet.begin(mac);
  server.begin();
  Serial.print("Server started on: ");
  Serial.println(Ethernet.localIP());
}

void loop()
{
  EthernetClient client = server.available();
  if (client) 
  {
    while (client.connected()) 
    {
      readHeader(client); // Here we read the first line of the header.
      if (! pageNameIs("/"))
      {
        client.stop();  
        return;
      }
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();

      // send the body
      client.println("<html><body>");
      client.println("<h1>Output Pins</h1>");
      client.println("<form method='GET'>");  
      setValuesFromParams(); // Before writing HTML for each of the pins, we call this func to read each of the request parameters and set the appropriate values in the pinStates array.
      setPinStates(); // This array is then used to set the value of the pin outputs...
      for (int i = 0; i < numPins; i++)
      {
         writeHTMLforPin(client, i); // before this func is called for each of the pins, which generates a selection list for each pin, and builds this list part by part.
      }
      client.println("<input type='submit' value='Update'/>");
      client.println("</form>");
      client.println("</body></html>");

      client.stop();            
    }
  }
}

void writeHTMLforPin(EthernetClient client, int i)
{
  client.print("<p>D");
  client.print(pins[i]);  
  client.print(" <select name='");
  client.print(i);
  client.println("'>");
  client.print("<option value='0'");
  if (pinState[i] == 0) // The `if` statements ensure that the appropriate options are selected.
  {
    client.print(" selected");
  }
  client.println(">Off</option>");
  client.print("<option value='1'");
  if (pinState[i] == 1)
  {
    client.print(" selected");
  }
  client.println(">On</option>");
  client.println("</select></p>");  
}

void setPinStates()
{
  for (int i = 0; i < numPins; i++)
  {
     digitalWrite(pins[i], pinState[i]);
  }
}

void setValuesFromParams()
{
  for (int i = 0; i < numPins; i++)
  {
    pinState[i] = valueOfParam(i + '0');
  }
}

void readHeader(EthernetClient client)
{
  // read first line of header
  char ch;
  int i = 0;
  while (ch != '\n')
  {
    if (client.available())
    {
      ch = client.read();
      line1[i] = ch;
      i ++;
    }
  }
  line1[i] = '\0'; 
  Serial.println(line1);
}

boolean pageNameIs(char* name)
{
   // page name starts at char pos 4
   // ends with space
   int i = 4;
   char ch = line1[i];
   while (ch != ' ' && ch != '\n' && ch != '?')
   {
     if (name[i-4] != line1[i])
     {
       return false;
     }
     i++;
     ch = line1[i];
   }
   return true;
}

int valueOfParam(char param)
{
  for (int i = 0; i < strlen(line1); i++)
  {
    if (line1[i] == param && line1[i+1] == '=')
    {
      return (line1[i+2] - '0');
    }
  }
  return 0;
}

// Here we use two arrays to control the pins, where `pins` just specifies which pins are to be used and `pinState` array holds the state of each pin - either 0 or 1.
// It's necessary to read the header coming from the browser in order to get this information coming from the browser form about which pins should be on/off.
// The functions readHeader, pageNameIs, and valueOfParam are useful general purpose funcs that you can make use of in other sketches!! :D 

// Note to self: could attach LEDs/relays to the pins to control things!
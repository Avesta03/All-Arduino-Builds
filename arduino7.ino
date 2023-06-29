//// IoT Programming
// Need specialised Arduinos or shields to provide network capabilities for local network and internet - don't have this but will make notes.

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
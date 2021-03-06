/*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 4 Sep 2010
 by Tom Igoe
 
 */

#include <SPI.h>

// Need to include GorillaBuilderz WizFi Ethernet libraries
#include <Transport.h>
#include <WizFi210.h>
#include <GBEthernet.h>
// Needed to read the GBIMAC, so you don't have to provide a MAC address....
#include <GBIMAC.h>

// NOTE: With GorillaBuilderz shield we have a a GBIMAC identifier you can use!
GBIMAC macReader(3);
byte mac[MAC_LENGTH];

IPAddress ip(192,168,1, 177);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup()
{
  // start the serial library:
  Serial.begin(115200);
  
  Serial.println("GorillaBuilderz Arduino WebServer for WiFi Shield");
  Serial.println("Initialising modem and ataching to network...");
  
  // NOTE: If you need to redefine the IO to your wifi shield call this BEFORE you execute any Ethernet* methods
  // WizFi210::create(A1, 2, 5, 6);
  
  // Set the network name
  Ethernet.ssid("BatPhone");
  // Initialise secure network passphrase
  Ethernet.passphrase("password");  

  // Read in the GBIMAC address
  macReader.read(mac);

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
}

void loop()
{
  /*
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();

          // output the value of each analog input pin
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(analogRead(analogChannel));
            client.println("<br />");
          }
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
  }
*/
  Serial.println("In Loop");
  delay(1000);
}

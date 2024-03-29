
/*
  Web client
 
 This sketch connects to a website (http://www.google.com)
 using a WiFi shield.
 
 This example is written for a network using WPA encryption. For 
 WEP or WPA, change the Wifi.begin() call accordingly.
 
 This example is written for a network using WPA encryption. For 
 WEP or WPA, change the Wifi.begin() call accordingly.
 
 Circuit:
 * WiFi shield attached
 
 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe
 */


#include <SPI.h>
#include <WiFi.h>

char ssid[] = "itpsandbox"; //  your network SSID (name) 
char pass[] = "NYU+s0a!+P?";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;  // your network key Index number (needed only for WEP)

int inByte = 0; 

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(166,78,61,139);  //RACKSPACE

// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
int port = 12002;
WiFiClient client;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
  //  while (!Serial) {
  //    ; // wait for serial port to connect. Needed for Leonardo only
  //  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(3000);
  } 
  Serial.println("Connected to wifi");
  printWifiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, port)) {
    Serial.println("connected to server");
    client.println("A");
    Serial.println("reading..");
    inByte = client.read();
    Serial.println(inByte);
    client.flush();  
    
  }
}  


void loop() {                    
  // if there are incoming bytes available 
  // from the server, read them and print them:
 while (client.connected()) {
  //  Serial.println("still connected");
    if (client.available()) {
//   Serial.println("reading..");
    char c = client.read();
 // if (!c == '-1'){  
    Serial.print  (c);
  }
  // }
 }
    //  Serial.println(c);
    //  client.flush();
    //  if(millis() %1000 < 3){
    //   client.write("1234");
    //   }


    // client.flush();  




  

  // if the server's disconnected, stop the client:
  // if (!client.connected()) {
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();
    client.flush();
    // do nothing forevermore:
    while(true);
  }
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}








/**
 * Simple Write. 
 * 
 * Check if the mouse is over a rectangle and writes the status to the serial port. 
 * This example works with the Wiring / Arduino program that follows below.
 */

   import oscP5.*;
import netP5.*;
import processing.net.*;
  import processing.serial.*;
  OscP5 oscP5;
  NetAddress keepon;

//Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port
int port = 12002;
String host = "166.78.61.139";
Client c;
String data;

void setup() 
{
  oscP5 = new OscP5(this,12000);
   keepon = new NetAddress("166.78.61.139",12002);
  size(200, 200);
  
   OscMessage rotmsg = new OscMessage("/rotate");
  //  rotmsg.add(128);
    OscMessage bfmsg = new OscMessage("/bf");
  
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
 // String portName = Serial.list()[0];
 // myPort = new Serial(this, portName, 9600);
 
 
 background(50);
  fill(200);
  c = new Client(this, host,port); // Connect to server on port 80
 // c.write("GET / HTTP/1.0\r\n"); // Use the HTTP "GET" command to ask for a Web page
 // c.write(data);
 
 
}

void draw() {
  background(255);
//  if (mouseOverRect() == true) {  // If mouse is over square,
   if (keyPressed) {
    if (key == 'h' || key == 'H'){
    fill(204);                    // change color and
    c.write(3);              // send an H to indicate mouse is over square
  } 
  else if (key == 'l' || key == 'L') {                        // If mouse is not over square,
    fill(0);                      // change color and
    c.write(2);              // send an L otherwise
  }
  rect(50, 50, 100, 100);         // Draw a square
}

}



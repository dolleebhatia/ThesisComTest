ThesisComTest
=============

This is skeletal working demo of processing controlling arduino through node.js on a remote server.

Flow of data looks like this : 

Processing--->Node.js<---Arduino 

Node.js is on a remote server. To run it locally change IP address to 127.0.0.1. Processing will push data to node.js using port 12001 and arduino pings for data using a Wi-FI shield on port 12002.
There's probably a cleaner way to write node.js, I'm using this modified node.js from Chris Kairalla's course Redial. https://github.com/itp-redial 



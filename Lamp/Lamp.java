import processing.serial.*;

import java.net.*;
import java.io.*;
import java.util.*;

String feed = "http://makezine.com/feed/";

int interval = 5 * 60 * 1000;	// retrieve feed every five minutes
int lastTime;			// the last time we fetched the content

int love = 0;
int peace = 0;
int arduino = 0;

int light = 0;			// light level measured by the lamp

Serial port;
color c;
String cs;

String buffer = "";		// accumulates characters coming from Arduino

PFont font;

void setup() {
	size(640, 480);
	frameRate(10);		// we don't need fast updates
	
	font = createFont("Helvetica", 24);
	fill(255);
	textFont(font, 32);

	// IMPORTANT NOTE
	// The first serial port retrieved by Serial.list()
	// should be your Arduino. If not, uncomment the next
	// line by deleting the // before it, and re-run the sketch
	// to see a list of serial ports. Then, change the 0 in between
	// [ and ] to the number of the port that your Arduino is connected to.
	//
	// println(Serial.list());
	
	String arduinoPort = Serial.list()[0];
	port = new Serial(this, arduinoPort, 9600);	// connect to Arduino
	
	lastTime = millis();
	fetchData();
}

void draw() {
	background( c );

	int n = (lastTime + interval - millis()) / 1000;

	// Build a colour based on the 3 values
	c = color(peace, love, arduino);
	cs = "#" + hex(c, 6);			// prepare a string to be sent to Arduino
	
	text("Arduino Networked Lamp", 10, 40);
	text("Reading feed:", 10, 100);
	text(feed, 10, 140);

	text("Next feed update in " + n + " seconds", 10, 450);
	text("peace", 10, 200);
	text(" " + peace, 130, 200);
	rect(200, 172, peace, 28);

	text("love", 10, 240);
	text(" " + love, 130, 240);
	rect(200, 212, love, 28);

	text("arduino", 10, 280);
	text(" " + arduino, 130, 280);
	rect(200, 252, arduino, 28);

	// write the colour string to the screen
	text("sending", 10, 340);
	text(cs, 200, 340);

	text("light level", 10, 380);
	rect(200, 352, light / 10.23, 28);	// this turns 1023 into 100
	
	if (n <= 0) {
		fetchData();
		lastTime = millis();
	}

	port.write(cs);				// send data to Arduino
	
	if (port.available() > 0) {		// check if there is data waiting
		int inByte = port.read();	// read one byte
		if (inByte != 10) {		// if byte is not newline
			buffer = buffer + char(inByte);	// just add it to the buffer
		} else {
			// newline reached, let's process the data
			if (buffer.length() > 1) {	// make sure there is enough data
				// chop off the last character, it's a carriage return
				// (a carriage return is the character at the end of a line of text)
				// turn the buffer from the string into an integer
				light = int(buffer);

				// clean the buffer for the next read cycle
				buffer = "";

				// We're likely falling behind in taking readings
				// from Arduino. So let's clear the backlog of
				// incoming sensor readings so the next reading 
				// is up-to-date
				port.clear();
			}
		}

	}
	
}

void fetchData() {
	// we use these strings to parse the feed
	String data;
	String chunk;

	// zero the counters
	love = 0;
	peace = 0;
	arduino = 0;

	try {
		URL url = new URL(feed);	// An object to represent the URL

		// prepare a connection
		URLConnection conn = url.openConnection();
		conn.connect();					// now connect to the website

		// this is a bit of virtual plumbing as we connect
		// the data coming from the connection to a buffered
		// reader that reads the data one line at a time.
		BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));

		// read each line from the feed
		while ( (data = in.readLine()) != null) {
			StringTokenizer st = new StringTokenizer(data, "\"<>,.()[] ");	// break it down

			while (st.hasMoreTokens()) {
				// each chunk of data is made lowercase
				chunk = st.nextToken().toLowerCase();

				if (chunk.indexOf("love") >= 0)
					love++;
				if (chunk.indexOf("peace") >= 0)
					peace++;
				if (chunk.indexOf("arduino") >= 0)
					arduino++;

			}
		}

		// set 64 to be the maximum number of references we care about
		if (peace > 64)		peace = 64;
		if (love > 64)		love = 64;
		if (arduino > 64)	arduino = 64;

		// multiply by 4 so that the max is 255
		peace = peace * 4;
		love = love * 4;
		arduino = arduino * 4;


	} catch (Exception exception) {
		exception.printStackTrace();
		System.out.println("Error: " + exception.getMessage());
	}
}

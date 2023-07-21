#include <Arduino.h>

#include "hardware.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ArduinoJson.h>

#include <textProtocol.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


DynamicJsonDocument jsonBuffer(1024);

void display_show( const float fVcc, const float fVsys, const float fCurrent, String msg){

	display.clearDisplay();
	display.setTextColor(WHITE);


	display.setTextSize(2);
	display.setCursor(0,0);
	display.print(F("B:"));
	display.print(fVcc);
	display.print(F("V"));

	display.setCursor(0,16);
	display.print(F("S:"));
	display.print(fVsys);
	display.print(F("V"));

	display.setCursor(0,32);
	display.print(F("I:"));
	display.print(fCurrent);
	display.print(F("A"));

	display.setTextSize(1);
	display.setCursor(0,55);
	display.print(msg);
	// display.print(F("Voyager NCC-74656"));
	display.display();	
}

void setup( void ){

	pinMode(LED1, OUTPUT);
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display_show(0.0, 0.0, 0.0, "Voyager NCC-74656");

	Serial.begin(115200);
	Serial.setTimeout(0);
	while(!Serial);
}

void loop( void ){

	if(Serial.available() > 1){
		digitalWrite(LED1, HIGH);

		delay(100);
		String sData = Serial.readString();
		sData.trim();
		
		if( !deserializeJson(jsonBuffer, sData) ){

			float fVcc	= jsonBuffer["vcc"];
			float fVsys	= jsonBuffer["vsys"];
			float fCurrent	= jsonBuffer["current"];
			String msg	= jsonBuffer["msg"];
			msg.trim();

			display_show(fVcc, fVsys, fCurrent, msg);
			
		}
		digitalWrite(LED1, LOW);
	}

	delay(1);
}




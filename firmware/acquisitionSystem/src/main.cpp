
#include <Arduino.h>
#include <ArduinoJson.h>

#include <textProtocol.h>
#include <disp.h>

#include "hardware.h"



DynamicJsonDocument jsonBuffer(1024);


void setup( void ){

	pinMode(LED1, OUTPUT);

	display_vSetup();

	Serial.begin(115200);
	Serial.setTimeout(0);
	while(!Serial);

	pinMode(PIN_OUT1, OUTPUT);
	pinMode(PIN_OUT2, OUTPUT);
	pinMode(PIN_OUT3, OUTPUT);
	pinMode(PIN_OUT4, OUTPUT);
	pinMode(PIN_OUT5, OUTPUT);
	pinMode(PIN_OUT6, OUTPUT);
	pinMode(PIN_OUT7, OUTPUT);
	pinMode(PIN_OUT8, OUTPUT);


	digitalWrite(PIN_OUT1, LOW);
	digitalWrite(PIN_OUT2, LOW);
	digitalWrite(PIN_OUT3, LOW);
	digitalWrite(PIN_OUT4, LOW);
	digitalWrite(PIN_OUT5, LOW);
	digitalWrite(PIN_OUT6, LOW);
	digitalWrite(PIN_OUT7, LOW);
	digitalWrite(PIN_OUT8, LOW);

	pinMode(0, INPUT);
	

}

void loop( void ){

	if(Serial.available() > 1){
		digitalWrite(LED1, HIGH);

		delay(100);

		String sData = Serial.readString();
		sData.trim();
		
		if( !deserializeJson(jsonBuffer, sData) ){

			float fVcc	= jsonBuffer[ "vcc"	];
			float fVsys	= jsonBuffer[ "vsys"	];
			float fCurrent	= jsonBuffer[ "current"	];
			String msg	= jsonBuffer[ "msg"	];
			msg.trim();

			display_vShow(fVcc, fVsys, fCurrent, msg);
			

			digitalWrite( PIN_OUT1, (bool) jsonBuffer[ "d2" ] );
			digitalWrite( PIN_OUT2, (bool) jsonBuffer[ "d3" ] );
			digitalWrite( PIN_OUT3, (bool) jsonBuffer[ "d4" ] );
			digitalWrite( PIN_OUT4, (bool) jsonBuffer[ "d5" ] );
			digitalWrite( PIN_OUT5, (bool) jsonBuffer[ "d6" ] );
			digitalWrite( PIN_OUT6, (bool) jsonBuffer[ "d7" ] );
			digitalWrite( PIN_OUT7, (bool) jsonBuffer[ "d8" ] );
			digitalWrite( PIN_OUT8, (bool) jsonBuffer[ "d9" ] );

		}
		digitalWrite(LED1, LOW);
	}

	delay(1);
}




#include <Arduino.h>

#include "hardware.h"



void setup( void ){
	pinMode(LED1, OUTPUT);
	pinMode(LDS_PIN_MOTOR, OUTPUT);
	pinMode(LDS_PIN_POWER, OUTPUT);

	digitalWrite(LDS_PIN_MOTOR, HIGH);
	digitalWrite(LDS_PIN_POWER, HIGH);
}

void loop( void ){

	digitalWrite(LED1, HIGH);
	delay( 200 );
	digitalWrite(LED1, LOW);
	delay( 200 );
}




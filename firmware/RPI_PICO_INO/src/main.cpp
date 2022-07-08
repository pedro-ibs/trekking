
#include <Arduino.h>
#include <hardware.h>


void setup( void ) {
	pinMode(LED, OUTPUT);
	Serial1.begin(115200);
}

void loop( void ) {
	digitalWrite(LED, HIGH);
	delay(1000);
	digitalWrite(LED, LOW);
	delay(1000);
}
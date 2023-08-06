/**
 * main.cpp
 *
 *  @date Created at:	06/08/2023 16:38:31
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
 *
 *   Copyright (C) Pedro Igor B. S 2021
 * -------------------------------------------------------------------
 *
 *   Licença: GNU GPL 2
 * -------------------------------------------------------------------
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; version 2 of the
 *   License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 * -------------------------------------------------------------------
 * #######################################################################
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>
#include <Arduino_LSM9DS1.h>
#include <Event.h>
#include <Timer.h>



#include <textProtocol.h>
#include <disp.h>
#include "hardware.h"
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define SAMPLE_RATE		( 200 )
#define BUFFER_SIZE		( 300 )
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
DynamicJsonDocument	jsonBufferInput( BUFFER_SIZE );
DynamicJsonDocument	jsonBufferOutput( BUFFER_SIZE );

static String msg			= "PPP5CM";
static float fVcc			= 0.00;
static float fVsys			= 0.00;
static float fCurrent			= 0.00;
static unsigned long ulSampleRate	= 0;		
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
void app_vShowTelemetry( void );
void app_vUpdatePin( void );
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

void setup( void ){

	pinMode(LED1, OUTPUT);

	display_vSetup();

	IMU.begin();

	Serial.begin( 115200 );
	Serial.setTimeout( 0 );

	while(!Serial) delay( 300 );


	pinMode( PIN_OUT1, OUTPUT );
	pinMode( PIN_OUT2, OUTPUT );
	pinMode( PIN_OUT3, OUTPUT );
	pinMode( PIN_OUT4, OUTPUT );
	pinMode( PIN_OUT5, OUTPUT );
	pinMode( PIN_OUT6, OUTPUT );
	pinMode( PIN_OUT7, OUTPUT );
	pinMode( PIN_OUT8, OUTPUT );

	digitalWrite( PIN_OUT1, LOW );
	digitalWrite( PIN_OUT2, LOW );
	digitalWrite( PIN_OUT3, LOW );
	digitalWrite( PIN_OUT4, LOW );
	digitalWrite( PIN_OUT5, LOW );
	digitalWrite( PIN_OUT6, LOW );
	digitalWrite( PIN_OUT7, LOW );
	digitalWrite( PIN_OUT8, LOW );

	msg.reserve( BUFFER_SIZE );

	serializeJson(jsonBufferOutput, Serial);

}

void loop( void ){

	bool bReadData = false;
	String sData;


	while ( Serial.available() ) {
		digitalWrite(LED1, HIGH);

		bReadData = true;

		char cBuffer = Serial.read();
		sData.concat( cBuffer );

		delay( 1 );
	}

	if ( bReadData ){

		sData.trim();

		if( !deserializeJson(jsonBufferInput, sData) ){
			app_vShowTelemetry();
			app_vUpdatePin();
		}
	}

	digitalWrite(LED1, LOW);

	while ( millis() > ulSampleRate ) {
  		
		ulSampleRate = millis() + SAMPLE_RATE;

		float ax = 0.00;
		float ay = 0.00;
		float az = 0.00;

		float gx = 0.00;
		float gy = 0.00;
		float gz = 0.00;

		float mx = 0.00;
		float my = 0.00;
		float mz = 0.00;

		if (IMU.accelerationAvailable()) {

			IMU.readAcceleration(ax, ay, az);

			jsonBufferOutput["accelerometer"]["x"]		= mx;
			jsonBufferOutput["accelerometer"]["y"]		= my;
			jsonBufferOutput["accelerometer"]["z"]		= mz;
			jsonBufferOutput["accelerometer"]["t"]		= millis();

		}

		if( IMU.gyroscopeAvailable() ){

			IMU.readGyroscope(gx, gy, gz);

			jsonBufferOutput["gyroscope"]["x"]		= gx;
			jsonBufferOutput["gyroscope"]["y"]		= gy;
			jsonBufferOutput["gyroscope"]["z"]		= gz;
			jsonBufferOutput["gyroscope"]["t"]		= millis();
		}
		
		if( IMU.magneticFieldAvailable() ){

			IMU.readMagneticField(mx, my, mz);

			jsonBufferOutput["magneticFiel"]["x"]		= mx;
			jsonBufferOutput["magneticFiel"]["y"]		= my;
			jsonBufferOutput["magneticFiel"]["z"]		= mz;
			jsonBufferOutput["magneticFiel"]["t"]		= millis();
		}
		
		serializeJson(jsonBufferOutput, Serial);
	}
	
	

}


/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

void app_vShowTelemetry( void ){

	if( jsonBufferInput.containsKey( "vcc" ) ){
		fVcc = (float)jsonBufferInput[ "vcc" ];
	}

	if( jsonBufferInput.containsKey( "vsys" ) ){
		fVsys = (float)jsonBufferInput[ "vsys" ];
	}

	if( jsonBufferInput.containsKey( "current" ) ){
		fCurrent = (float)jsonBufferInput[ "current" ];
	}

	if( jsonBufferInput.containsKey( "msg" ) ){
		String m = jsonBufferInput[ "msg" ];
		m.trim();
		msg = m;
	} 


	display_vShow(fVcc, fVsys, fCurrent, msg);
}


void app_vUpdatePin( void ){
	if( jsonBufferInput.containsKey( "d2" ) ) digitalWrite( PIN_OUT1, ( bool ) jsonBufferInput[ "d2" ] );
	if( jsonBufferInput.containsKey( "d3" ) ) digitalWrite( PIN_OUT2, ( bool ) jsonBufferInput[ "d3" ] );
	if( jsonBufferInput.containsKey( "d4" ) ) digitalWrite( PIN_OUT3, ( bool ) jsonBufferInput[ "d4" ] );
	if( jsonBufferInput.containsKey( "d5" ) ) digitalWrite( PIN_OUT4, ( bool ) jsonBufferInput[ "d5" ] );
	if( jsonBufferInput.containsKey( "d6" ) ) digitalWrite( PIN_OUT5, ( bool ) jsonBufferInput[ "d6" ] );
	if( jsonBufferInput.containsKey( "d7" ) ) digitalWrite( PIN_OUT6, ( bool ) jsonBufferInput[ "d7" ] );
	if( jsonBufferInput.containsKey( "d8" ) ) digitalWrite( PIN_OUT7, ( bool ) jsonBufferInput[ "d8" ] );
	if( jsonBufferInput.containsKey( "d9" ) ) digitalWrite( PIN_OUT7, ( bool ) jsonBufferInput[ "d9" ] );
}


/**
 * disp.cpp
 *
 *  @date Created at:	25/07/2023 22:49:35
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
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
#include "disp.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define SCREEN_WIDTH		128	// OLED display width, in pixels
#define SCREEN_HEIGHT		64	// OLED display height, in pixels
#define OLED_RESET		-1	// Reset pin # (or -1 if sharing Arduino reset pin)
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/



void display_vSetup( void ){
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display_vShow(0.0, 0.0, 0.0, "Voyager NCC-74656");

	delay(1000);
}



void display_vShow( const float fVcc, const float fVsys, const float fCurrent, String msg){

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
	display.display();	
}



/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/

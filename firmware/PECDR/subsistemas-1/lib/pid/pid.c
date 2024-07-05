/**
 * pid.c
 *
 *  @date Created at:	05/12/2022 23:50:55
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
 *
 * TODO: documentation or resume or Abstract
 *
 */



/* Includes ----------------------------------------------------------------------------------------------------------------------------------------------*/
#include "pid.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"
/* Setings -----------------------------------------------------------------------------------------------------------------------------------------------*/
#define TO_SECONDS( MS ) ( ( MS ) / 1000.0)
/* Function prototype ------------------------------------------------------------------------------------------------------------------------------------*/
float pid_fCore( pid *pxPid, float xDeltaTime );
/* Setup -------------------------------------------------------------------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------------------------------------------------------------------------*/

float pid_fRun( pid *pxPid ){
	float xDeltaTime = TO_SECONDS( time_us_32() - pxPid->xLastTime );
	pxPid->xLastTime = time_us_32();
	return pid_fCore( pxPid, xDeltaTime );
}



/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*########################################################################################################################################################*/
/*-------------------------------------------------------------------- Local Functions -------------------------------------------------------------------*/
/*########################################################################################################################################################*/


float pid_fCore( pid *pxPid, float xDeltaTime ){
	pxPid->fError = pxPid->fSetPoint - pxPid->fInput;

	// proportional
	pxPid->fP = pxPid->fError * pxPid->fKp;

	// integra
	pxPid->fI += (pxPid->fError * pxPid->fKi) * xDeltaTime;

	// derived
	pxPid->fD = (pxPid->fLastInput - pxPid->fInput)  * pxPid->fKd * xDeltaTime;
	pxPid->fLastInput = pxPid->fInput;

	pxPid->fOutput = pxPid->fP + pxPid->fI + pxPid->fD;

	return pxPid->fOutput;
}
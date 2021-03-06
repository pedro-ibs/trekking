/**
 * gprs.h
 *
 *  @date Created at:	16/06/2022 11:50:01
 *	@author:	Pedro Igor B. S.
 *	@email:		pedro.igor.ifsp@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * #######################################################################
 *
 * TODO: Licence
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

/* Includes ---------------------------------------------------------------------------------------------------------------------------------------------*/
#include <zephyr.h>



#ifndef gprs_H_
#define gprs_H_

/* settings ----------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definition --------------------------------------------------------------------------------------------------------------------------------------------*/

void gprs_vSetup(void);

void gprs_vDisable(void);
void gprs_vEnable(void);
void gprs_vReset(void);


#endif /* gprs_h_H_ */

/**
 * protocol.h
 *
 *  @date Created at:	11/03/2021 12:45:55
 *	@author:	Pedro Igor B. S.
 *	@email:		pibscontato@gmail.com
 * 	GitHub:		https://github.com/pedro-ibs
 * 	tabSize:	8
 *
 * ###################################################################
 * 
 *   Copyright (C) Pedro Igor B. S 2019
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
 * 
 * ###################################################################
 *
 * Essa biblioteca foi desenvolvida para trabalhar com protocolos de
 * texto geralmente utilizados em comunicações serias como RS232
 * 
 * Com ela é possível traduzir e trabalhar com diversos tipos de 
 * protocolos e textos padronizados como CSV
 *
 */

/* Includes ------------------------------------------------------------------*/
#include <stddef.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <zephyr.h>


#ifndef protocol_H_
#define protocol_H_



/* macro ---------------------------------------------------------------------*/
#define TOKENS 		{',', ':', '=', ';', '&', '\n', '\r', '$', 0x00}

/* Definition ----------------------------------------------------------------*/

bool textp_bFindString( const char *pcFindAt, const char *pcFindThis);
bool textp_bIsToken(const char pcTok);
bool textp_bIsHexNum(const char *pcStr);
bool textp_bIsDecNum(const char *pcStr);
bool textp_bIsCaractere(const char *pcStr);
bool textp_bGetLabelInfo(const char *pcStr, const char *pcLabel, const uint16_t cuArg , char *pcBff);
bool textp_bGetValueInCSV(const char *pcLine, const size_t cuWhere, char *pcSaveTo);
bool textp_bGetValueInStr(const char *pcStr, const size_t cuWhere, const char div, char *pcSaveTo);

uint8_t *textp_puCleanBlk(uint8_t *puBlk, uint16_t uLen);

char *textp_pcCleanStr(char *pcStr);
char *textp_pcZeroLeft(char *pcStr, const size_t cuSizeWithZeros);
char *textp_pcCharLeft(char *pcStr, const size_t cuSizeWithZeros, char cChar);
char *textp_pcRmChr( char *pcStr, const char ccRemoveChar );
char *textp_pcCharToChar(char *pcStr, const char ccFind, const char ccReplaceTo);
char *textp_pcToUpperCase(char *pcStr);
char *textp_pcStrcpy(const char *pcStr, char *pcCopyTo,  uint8_t cuInit, uint8_t cuEnd);


bool textp_bCheckStringSize(const char *pcString, const size_t uMaxSize);
bool textp_bCheckStringValid(const char *pcString, const size_t uMaxSize, const char *pcIgnoreValue);

#endif /* protocol_H_ */
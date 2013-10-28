#ifndef			_LIB_CARD_MANAGER_OPER_LIB_
#define			_LIB_CARD_MANAGER_OPER_LIB_		1

#if defined(_LIB)
#define			LIB_CARD_MANAGER_EXP
#define			LIB_CARD_MANAGER_EXP_(_type)		_type
#else
#define			LIB_CARD_MANAGER_EXP				__declspec(dllexport)
#define			LIB_CARD_MANAGER_EXP_(_type)		__declspec(dllexport) _type
#endif /**< defined(_LIB)*/
/**
 * @ include files
 * @{
 */
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include "XK3118K9D.h"
/** }@ */

#define         AWARD_MOTHER_CARD       8001
#define         WATCH_MOTHER_CARD       8002
#define         USER_BLANK_CARD         8003

#ifdef	__cplusplus
extern "C" {
#endif /**< defined(__cplusplus)*/
/**
 * @func group
 * {
 */
LIB_CARD_MANAGER_EXP_(long) LongToConverseHexStr(long nData, char *pszOut);
LIB_CARD_MANAGER_EXP_(long) ConverseHexStrToLong(char *pszData, int nLen);

LIB_CARD_MANAGER_EXP_(void) StrXor(BYTE* SouStr, int iLen, BYTE* DesStr);\
LIB_CARD_MANAGER_EXP_(void) UnsignedCharXor(unsigned char* SouStr, int iLen, unsigned char* DesStr);
// LIB_CARD_MANAGER_EXP_(long) HexStrToLong(char *SouStr, int iLen);

// Ansic string to byte string eg. "0000" --> "303030"
LIB_CARD_MANAGER_EXP_(void) AnsiStrToByteStr(const char *pszAnsiIn, 
							unsigned char *pszByteStrOut, unsigned int nLen);
// Bytes to Ansi String eg: 0X30 0X55 --> "3055"
LIB_CARD_MANAGER_EXP_(void) BytesToStr(unsigned char * pszBits, unsigned int nBitLen, 
				unsigned char * pszOutStr, unsigned int nSize);
// Ansi String to Bytes String eg: "3055" --> 0X30 0X55
LIB_CARD_MANAGER_EXP_(void) StrToBytes(unsigned char * pszStr,  
				unsigned char * pszOutBytes, unsigned int nSize);
LIB_CARD_MANAGER_EXP_(void) StrNot(BYTE* SouStr, int iLen, BYTE* DesStr);
LIB_CARD_MANAGER_EXP_(void) Loadmeter2Str(stLoadMeter* pLoadMeter, unsigned char* pDesStr ,unsigned int nSize);
LIB_CARD_MANAGER_EXP_(void) ReceiveStr2Loadmeter(unsigned char* pSourceStr ,unsigned int nSize,stLoadMeter* pLoadMeter);
#ifdef __cplusplus
}
#endif /**< defined(__cplusplus) */

#endif /**< _LIB_CARD_MANAGER_OPER_LIB_*/

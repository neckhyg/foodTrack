#include "StdAfx.h"
#include "StringOper.h"

#include <math.h>
#define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )

// get char hign 8 bits eg. '0' return '3'
unsigned char HignBitToChar(unsigned char szChar)
{
	unsigned char szH4 = (unsigned char)(szChar >> 4 & 0X0F);

	if (szH4 >= 0 && szH4 <= 9)
	{
		return (unsigned char)(szH4 + 0X30);
	}
	else if (szH4 >= 'A' && szH4 <= 'F')
	{
		return (unsigned char)(szH4 - 0X0A + 'A');
	}
	else if (szH4 >= 0X0A && szH4 <= 0X0F)
	{
		return (unsigned char)(szH4 - 0X0A + 'A');
	}
	else 
	{
		return (unsigned char)'0';
	}
}
// get char low 8 bits eg. '0' return '3'
unsigned char LowBitToChar(unsigned char szChar)
{
	unsigned char szL4 = (unsigned char)(szChar & 0X0F);

	if (szL4 >= 0 && szL4 <= 9)
	{
		return (unsigned char)(szL4 + 0X30);
	}
	else if (szL4 >= 0X0A && szL4 <= 0X0F)
	{
		return (unsigned char)(szL4 - 0X0A + 'A');
	}
	else if (szL4 >= 'A' && szL4 <= 'F')
	{
		return (unsigned char)(szL4 - 0X0A + 'A');
	}
	else 
	{
		return '0';
	}
}
unsigned char CharToBit(unsigned char szChar)
{
	unsigned char szBit = 0X00;

	if (szChar >= 0X30 && szChar <= 0X39)
	{
		szBit = (unsigned char)(szChar - 0X30);
	}
	else if (szChar >= 0X41 && szChar <= 0X5A)
	{
		szBit = (unsigned char)(szChar - 0X41 + 0X0A);
	}
	else if (szChar >= 0X61 && szChar <= 0X7A)
	{
		szBit = (unsigned char)(szChar - 0X61 + 0X0A);
	}

	return szBit;
}
unsigned char GetOneBit(unsigned char szH8, unsigned char szL8)
{
	unsigned char szBit = 0X00;

	szBit = (unsigned char)CharToBit((unsigned char)(szH8)) << 4 | CharToBit((unsigned char)szL8);
	return szBit;
}
unsigned char BitToChar(unsigned char szBit)
{
	if (szBit >= 0X00 && szBit <= 0X09)
	{
		return (unsigned char)(0X30 | szBit);
	}
	else if (szBit >= 0X0A && szBit <= 0X0F)
	{
		return (unsigned char)(0X41 + szBit - 0X0A);
	}
	else 
	{
		return (unsigned char)(0X30);
	}
}
// Bytes to Ansi String eg: 0X30 0X55 --> "3055"
LIB_CARD_MANAGER_EXP_(void)  BytesToStr(unsigned char * pszBits, unsigned int nBitLen, 
				unsigned char * pszOutStr, unsigned int nSize)
{
	unsigned int nCur = 0;
	unsigned char *pszPos = pszOutStr;
	if (NULL == pszOutStr || nBitLen * 2 > nSize)
	{
		return ;
	}

	for (nCur = 0; nCur < nBitLen; nCur++)
	{
		*pszPos++ = BitToChar((unsigned char)((pszBits[nCur] & 0XF0) >> 4));
		*pszPos++ = BitToChar((unsigned char)((pszBits[nCur] & 0X0F)));
	}
	*pszPos = '\0';
}
// Ansic string to byte string eg. "0000" --> "303030"
LIB_CARD_MANAGER_EXP_(void) AnsiStrToByteStr(const char *pszAnsiIn, 
							unsigned char *pszByteStrOut, unsigned int nLen)
{
	char *pszPos = (char *)pszAnsiIn;
	unsigned int nCur = 0;
	unsigned char szTemp = ' ';
	memset(pszByteStrOut, 0, nLen);
	if (NULL == pszAnsiIn)
	{
		return;
	}
	for (;;)
	{
		szTemp = *pszPos++;
		if (szTemp == '\0')
		{
			break;
		}
		if (nCur >= nLen)
		{
			break;
		}
		
		pszByteStrOut[nCur++] = HignBitToChar(szTemp);
		pszByteStrOut[nCur++] = LowBitToChar(szTemp);
	}
	for (;;)
	{
		if (nCur >= nLen)
		{
			break;
		}
		
		pszByteStrOut[nCur++] = '0';
		pszByteStrOut[nCur++] = '0';
	}
}
// Ansi String to Bytes String eg: "3055" --> 0X30 0X55
LIB_CARD_MANAGER_EXP_(void) StrToBytes(unsigned char * pszStr,  
				unsigned char * pszOutBytes, unsigned int nSize)
{
	unsigned int nComLen = 0;
	int nCur = 0;
	unsigned char szCmdAPDU[512] = {0};
	unsigned char szCmd = 0;

	memset(pszOutBytes, 0, nSize);
	if (NULL == pszStr || '\0' == pszStr[0])
	{
		return;
	}
	nComLen = strlen((const char *)pszStr);
	if (nComLen % 2 != 0 && nComLen < 2)
	{
		return;
	}
	nComLen = 0;
	for (nCur = 0; pszStr[nCur] != '\0'; nCur += 2)
	{
		szCmd = GetOneBit(pszStr[nCur + 0], pszStr[nCur + 1]);;
		szCmdAPDU[nComLen++] = szCmd;
	}
	memcpy(pszOutBytes, szCmdAPDU, MIN(nComLen, nSize));
}
LIB_CARD_MANAGER_EXP_(long) HexStrToLong(char *SouStr, int iLen)
{
	int i;
	long ret = 0;
    BYTE temp;
	
	for (i=0; i<iLen; i++)
    {
        if      (SouStr[i] >= 0x61 && SouStr[i] <= 0x66)
            temp = SouStr[i] - 0x57;
        else if (SouStr[i] >= 0x41 && SouStr[i] <= 0x46)
            temp = SouStr[i] - 0x37;
        else if (SouStr[i] >= 0x30 && SouStr[i] <= 0x39)
            temp = SouStr[i] - 0x30;

		ret = ret + (long)(temp * powf(16,iLen-i-1));
    }    
	return ret;
}

void HexStrToBytes(BYTE *SouStr, int Len, BYTE *DesByte)
{

	int i ;
	BYTE HighByte, LowByte;
  
	for (i = 0; i < Len; i += 2)
	{
		HighByte = SouStr[i];
		LowByte  = SouStr[i + 1];

        if  (HighByte >= 0x61 && HighByte <= 0x66)
            HighByte -= 0x57;
        else if (HighByte >= 0x41 && HighByte <= 0x46)
            HighByte -= 0x37;
        else if (HighByte >= 0x30 && HighByte <= 0x39)
            HighByte -= 0x30;
        
        if  (LowByte >= 0x61 && LowByte <= 0x66)
            LowByte -= 0x57;
        else if (LowByte >= 0x41 && LowByte <= 0x46)
            LowByte -= 0x37;
        else if (LowByte >= 0x30 && LowByte <= 0x39)
            LowByte -= 0x30;
	
		DesByte[i / 2] = (HighByte << 4) | LowByte;
	}
}

void BytesToHexStr(BYTE *SouByte, int Len, BYTE *DesStr)
{

	int i;
	BYTE HighByte, LowByte;
	
	for (i = 0; i < Len; i++)
	{
		HighByte = SouByte[i] >> 4;
		LowByte  = SouByte[i] & 0x0f ;
	    
		HighByte += 0x30;
		if (HighByte > 0x39) DesStr[i * 2] = HighByte + 0x07;
		else DesStr[i * 2] = HighByte;

		LowByte += 0x30;
		if (LowByte > 0x39) DesStr[i * 2 + 1] = LowByte + 0x07;
		else DesStr[i * 2 + 1] = LowByte;
	}
}


void strRevHexString(char *SouStr, int iLen, char *DesStr)
{
	int		i, j;

	if ( iLen % 2 != 0 ) exit(0);

	for (i=iLen-2, j=0; i>=0 ; i-=2,j+=2)
	{
		memcpy(&DesStr[j],&SouStr[i],2);
	}
}

LIB_CARD_MANAGER_EXP_(void) StrXor(BYTE* SouStr, int iLen, BYTE* DesStr)
{
	int i;
	BYTE temp=0;
	BYTE temp1[255];
	
	if ( iLen % 2 != 0 ) exit(0);

	HexStrToBytes(SouStr, iLen, temp1);
	for (i=0; i<iLen/2; i++) temp = temp ^ temp1[i];
	BytesToHexStr( &temp, 1, DesStr );
}

LIB_CARD_MANAGER_EXP_(long) LongToConverseHexStr(long nData, char *pszOut)
{
	long nTemp = nData;
	char szLongTemp[5] = {0};
	if (NULL == pszOut)
	{
		return -1;
	}
	memset(pszOut, 0, 8);
	memcpy(szLongTemp, &nTemp, 4);
	BytesToStr((unsigned char *)szLongTemp, 4, (unsigned char *)pszOut, 8);
	return 0;
}


LIB_CARD_MANAGER_EXP_(long) ConverseHexStrToLong(char *pszData, int nLen)
{
	long nTemp = 0;
	char szLongTemp[5] = {0};

	if (NULL == pszData || 8 != nLen)
	{
		return -1;
	}
	StrToBytes((unsigned char *)pszData, (unsigned char *)szLongTemp, 5);
	nTemp = *((long *)&szLongTemp);
	return nTemp;
}
LIB_CARD_MANAGER_EXP_(void) StrNot(BYTE* SouStr, int iLen, BYTE* DesStr)
{
	int i;
	BYTE temp1[255];
	
	if ( iLen % 2 != 0 ) exit(0);

	HexStrToBytes(SouStr, iLen, temp1);
	for(i=0;i<iLen / 2; i++ ) temp1[i]=~temp1[i];
	BytesToHexStr( &temp1[0], iLen/2, DesStr );
}

LIB_CARD_MANAGER_EXP_(void) UnsignedCharXor(unsigned char* SouStr, int iLen, unsigned char* DesStr){

	int i;
	unsigned char temp=0;
//	unsigned char temp1[255];

	if ( iLen < 2 ) exit(0);

	temp = SouStr[0];
	//HexStrToBytes(SouStr, iLen, temp1);
	for (i=1; i<iLen; i++) temp = temp ^ SouStr[i];
	BytesToHexStr((BYTE*) &temp, 1, (BYTE*)DesStr );
}
LIB_CARD_MANAGER_EXP_(void) Loadmeter2Str(stLoadMeter* pLoadMeter, unsigned char* pDesStr ,unsigned int nSize){

	unsigned char buf[256];
	unsigned int nCur = 0;
	int len , i = 0 , j = 0 ;
	unsigned char *pszPos = pDesStr;

	if (NULL == pDesStr ){
		return ;
	}

	memset((void*)&buf,0,256);

	buf[0] = pLoadMeter->cmdStart;
	buf[1] = pLoadMeter->address;
	buf[2] = pLoadMeter->cmd ;
	len = 3;
	if(!pLoadMeter->bCmd){
		for ( i = 0 ; i < 8; i++){

			buf[len++] = pLoadMeter->data[i];
			//len++;
		}
		
	}
	for ( j = 0 ; j < 2; j++){

		buf[len++] = pLoadMeter->checkNum[j];
		//len++;
	}

	
	buf[len++] = pLoadMeter->cmdEnd ;
	
	BytesToStr(buf,len,pDesStr,nSize);

	
}

LIB_CARD_MANAGER_EXP_(void) ReceiveStr2Loadmeter(unsigned char* pSourceStr ,unsigned int nSize,stLoadMeter* pLoadMeter){


	unsigned char *pSour = pSourceStr;
	stLoadMeter *pszDes = pLoadMeter ;


	if (NULL == pSourceStr || nSize < WEIGHT0_CMD_RETURN_LEN){
		return ;
	}
	if ( *pSourceStr != 0x02 && *(pSourceStr+WEIGHT0_CMD_RETURN_LEN-1) != 0x03){
		return ;
	}

	//memset((void*)&buf,0,256);

    pszDes->cmdStart = *pSour ;
	pSour++;
	pszDes->address = *pSour ;
	pSour++;
	pszDes->cmd = *pSour ;
	
	for ( int i = 0 ; i < 8; i++){
		pLoadMeter->data[i] = *pSour++ ;			
		}

	
	for (int  j = 0 ; j < 2; j++){

		pLoadMeter->checkNum[j] = *pSour++ ;
		
	}


	 pLoadMeter->cmdEnd = *pSour;

	 pLoadMeter->bCmd = FALSE ;


//	BytesToStr(buf,len,pDesStr,nSize);


}
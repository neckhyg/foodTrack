#ifndef		__XK3118K9D_H_
#define		__XK3118K9D_H_
/*
  �ذ�ָ��:
-----------------------------------------------------------------------------------------
 ��X�ֽ�:   1		2				3			4		5		       6
-----------------------------------------------------------------------------------------
 ����:     02	 ��ַ���(A~Z)   ����(A~H)   �������λ ���У���λ	   03
-----------------------------------------------------------------------------------------
�ذ���������:
-----------------------------------------------------------------------------------------
��X�ֽ�:   1		2				3			4		5~11	12			 13        14
-----------------------------------------------------------------------------------------
����:     02	 ��ַ���(A~Z)   ����(A~H)     ����λ    ����λ �������λ ���У���λ	03
-----------------------------------------------------------------------------------------
*/
#define		START_CMD    02
#define		TAKEHAND_CMD  A   
#define		WEIGHT0_CMD   B   
#define		WEIGHT1_CMD   C  
#define		WEIGHT2_CMD   D   
#define		CAR_NO_CMD   E   
#define		CARGO_NO_CMD   F  
#define		CLEAR_ALL_CMD   G   
#define		SET_ZERO_CMD   H   
#define		END_CMD      03

#define		TAKEHAND_CMD_RETURN_LEN      4
#define		WEIGHT0_CMD_RETURN_LEN       14	

typedef struct  loadometer{
	unsigned char cmdStart;
	unsigned char address;
	unsigned char cmd;
	unsigned char data[8];
	unsigned char checkNum[2];
	unsigned char cmdEnd;
	BOOL          bCmd;
} stLoadMeter; 
#endif
#ifndef		__XK3118K9D_H_
#define		__XK3118K9D_H_
/*
  地磅指令:
-----------------------------------------------------------------------------------------
 第X字节:   1		2				3			4		5		       6
-----------------------------------------------------------------------------------------
 内容:     02	 地址编号(A~Z)   命令(A~H)   异或检验高位 异或校验低位	   03
-----------------------------------------------------------------------------------------
地磅返回数据:
-----------------------------------------------------------------------------------------
第X字节:   1		2				3			4		5~11	12			 13        14
-----------------------------------------------------------------------------------------
内容:     02	 地址编号(A~Z)   命令(A~H)     符号位    数据位 异或检验高位 异或校验低位	03
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
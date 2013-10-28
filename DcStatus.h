typedef dc_SHORT dc_STATUS;

#define	DC_OK					((dc_STATUS)(-00))
#define DCERR_UNKNOWN			((dc_STATUS)(-01))
#define	DCERR_COMMUNICATION		((dc_STATUS)(-16))
#define	DCERR_TIMEOUT			((dc_STATUS)(-17))
#define	DCERR_OPENCOMM			((dc_STATUS)(-32))
#define	DCERR_GETCOMMSTATE		((dc_STATUS)(-33))
#define	DCERR_SETCOMMSTATE		((dc_STATUS)(-34))
#define	DCERR_CLOSECOMM			((dc_STATUS)(-35))
#define	DCERR_COMMEXIST			((dc_STATUS)(-36))
#define	DCERR_FORMAT			((dc_STATUS)(-48))
#define	DCERR_DATAFORMAT		((dc_STATUS)(-49))
#define	DCERR_DATALENGTH		((dc_STATUS)(-50))
#define	DCERR_READ				((dc_STATUS)(-64))
#define	DCERR_WRITE				((dc_STATUS)(-65))
#define	DCERR_NOT_RECEIVE		((dc_STATUS)(-66))
#define	DCERR_LESS				((dc_STATUS)(-80))
#define DCERR_CPUXOR			((dc_STATUS)(-81))

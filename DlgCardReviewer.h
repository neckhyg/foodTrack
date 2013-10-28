#pragma once
#include "SerialPort.h"
#include "afxwin.h"
#include "XK3118K9D.h"

// CDlgCardReviewer 对话框

class CDlgCardReviewer : public CDialog
{
	DECLARE_DYNAMIC(CDlgCardReviewer)

protected:
	HICON			m_hIcon;
	CEdit		    m_EditWeight;
	CEdit			m_Edit;
	CSerialPort		m_Ports;
	CString			m_strReceived[4];
	CFont           m_font; 
	CBrush          m_brush;
	stLoadMeter     m_loadMeter[2];
	
	unsigned long   m_cardsnr;
public:
	HANDLE          m_icdev;
	void InitializeLoadMeter();

public:
	CDlgCardReviewer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgCardReviewer();

// 对话框数据
	enum { IDD = IDD_CARDREVIEWER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnreadweight();
	afx_msg LONG OnCommunication(UINT, LONG);
	afx_msg LONG OnCTSDetected(UINT, LONG);
	virtual BOOL OnInitDialog();
//	CListBox m_WeightListBox;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClicked65535();
	void CloseReaderCom(void);
	BOOL InitReaderParam(void);
	BOOL LoadReaderKey(unsigned char* key);
	BOOL ReaderAuthentic(int sector, int mode);
	BOOL WriteBlock(int sector, int block, unsigned char* pData);
	BOOL ReadBlock(int sector, int block, unsigned char* pData);
	BOOL ConnectReader(void);
	BOOL CloseReaderCom(int port);
	int CreatMakeCardThread(void);
	void CleanCardInfo(void);
	BOOL Findcard(unsigned long *pSnr);
	void ShowCardInfo(void);
	void ReadCardContent(void);
	afx_msg void  OnBUTTONReadCard();
};

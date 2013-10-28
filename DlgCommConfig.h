#pragma once


// CDlgCommConfig 对话框

class CDlgCommConfig : public CDialog
{
	DECLARE_DYNAMIC(CDlgCommConfig)

public:
	CDlgCommConfig(CWnd* pParent = NULL);   // 标准构造函数
	CDlgCommConfig(CWnd* pParent, DCB dcb);
	virtual ~CDlgCommConfig();
	CString	m_strBaudRate;
	CString	m_strDataBits;
	CString	m_strParity;
	CString	m_strStopBits;
	BOOL	m_CommBreakDetected;
	BOOL	m_CommCTSDetected;
	BOOL	m_CommDSRDetected;
	BOOL	m_CommERRDetected;
	BOOL	m_CommRingDetected;
	BOOL	m_CommRLSDDetected;
	BOOL	m_CommRxchar;
	BOOL	m_CommRxcharFlag;
	BOOL	m_CommTXEmpty;
	CString	m_strSendBuffer;
// 对话框数据
	enum { IDD = IDD_CONFIGDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	DCB		m_dcb;
};

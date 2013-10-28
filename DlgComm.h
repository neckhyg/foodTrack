#pragma once

#include "SerialPort.h"

// CDlgComm 对话框

class CDlgComm : public CDialog
{
	DECLARE_DYNAMIC(CDlgComm)

public:
	CDlgComm(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgComm();

// 对话框数据
	enum { IDD = IDD_COMMTEST_DIALOG };
protected:
	HICON			m_hIcon;
	CListBox		m_ListBox[4];
	CEdit			m_Edit[4];
	CSerialPort		m_Ports[4];
	CString			m_strReceived[4];
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedConfigbutton1();
	afx_msg LONG OnCommunication(UINT, LONG);
	afx_msg LONG OnCTSDetected(UINT, LONG);
	virtual BOOL OnInitDialog();
};

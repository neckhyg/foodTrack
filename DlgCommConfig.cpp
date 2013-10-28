// DlgCommConfig.cpp : 实现文件
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgCommConfig.h"
#include "afxdialogex.h"


// CDlgCommConfig 对话框

IMPLEMENT_DYNAMIC(CDlgCommConfig, CDialog)

CDlgCommConfig::CDlgCommConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCommConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConfigDlg)
	m_strBaudRate = _T("");
	m_strDataBits = _T("");
	m_strParity = _T("");
	m_strStopBits = _T("");
	m_CommBreakDetected = FALSE;
	m_CommCTSDetected = FALSE;
	m_CommDSRDetected = FALSE;
	m_CommERRDetected = FALSE;
	m_CommRingDetected = FALSE;
	m_CommRLSDDetected = FALSE;
	m_CommRxchar = TRUE;
	m_CommRxcharFlag = FALSE;
	m_CommTXEmpty = FALSE;
	m_strSendBuffer = _T("");
	//}}AFX_DATA_INIT
}
CDlgCommConfig::CDlgCommConfig(CWnd* pParent, DCB dcb)
	: CDialog(CDlgCommConfig::IDD, pParent)
{
	m_dcb = dcb;
}
CDlgCommConfig::~CDlgCommConfig()
{
}

void CDlgCommConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
//{{AFX_DATA_MAP(CConfigDlg)
	DDX_CBString(pDX, IDC_BAUDRATECOMBO, m_strBaudRate);
	DDX_CBString(pDX, IDC_DATABITSCOMBO, m_strDataBits);
	DDX_CBString(pDX, IDC_PARITYCOMBO, m_strParity);
	DDX_CBString(pDX, IDC_STOPBITSCOMBO, m_strStopBits);
	DDX_Check(pDX, IDC_CHECK1, m_CommBreakDetected);
	DDX_Check(pDX, IDC_CHECK2, m_CommCTSDetected);
	DDX_Check(pDX, IDC_CHECK3, m_CommDSRDetected);
	DDX_Check(pDX, IDC_CHECK4, m_CommERRDetected);
	DDX_Check(pDX, IDC_CHECK5, m_CommRingDetected);
	DDX_Check(pDX, IDC_CHECK6, m_CommRLSDDetected);
	DDX_Check(pDX, IDC_CHECK7, m_CommRxchar);
	DDX_Check(pDX, IDC_CHECK8, m_CommRxcharFlag);
	DDX_Check(pDX, IDC_CHECK9, m_CommTXEmpty);
	DDX_CBString(pDX, IDC_SENDBUFFERCOMBO, m_strSendBuffer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCommConfig, CDialog)
END_MESSAGE_MAP()


// CDlgCommConfig 消息处理程序


BOOL CDlgCommConfig::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString strTemp;
	strTemp.Format("%d", m_dcb.BaudRate);
	((CComboBox*)GetDlgItem(IDC_BAUDRATECOMBO))->SelectString(0, strTemp);

	((CComboBox*)GetDlgItem(IDC_PARITYCOMBO))->SetCurSel(m_dcb.Parity);

	((CComboBox*)GetDlgItem(IDC_STOPBITSCOMBO))->SetCurSel(m_dcb.StopBits);

	strTemp.Format("%d", m_dcb.ByteSize);
	((CComboBox*)GetDlgItem(IDC_DATABITSCOMBO))->SelectString(0, strTemp);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

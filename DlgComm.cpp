// DlgComm.cpp : 实现文件
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgComm.h"
#include "afxdialogex.h"
#include "DlgCommConfig.h"

// CDlgComm 对话框

IMPLEMENT_DYNAMIC(CDlgComm, CDialog)

CDlgComm::CDlgComm(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgComm::IDD, pParent)
{

}

CDlgComm::~CDlgComm()
{
}

void CDlgComm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgComm, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgComm::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CONFIGBUTTON1, &CDlgComm::OnBnClickedConfigbutton1)
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommunication)
	ON_MESSAGE(WM_COMM_CTS_DETECTED, OnCTSDetected)
END_MESSAGE_MAP()


// CDlgComm 消息处理程序


void CDlgComm::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	char buf[100];
	memset(&buf, 0, sizeof(buf));
	GetDlgItemText(ID_EDIT1, buf, sizeof(buf));
	if (strcmp("NOT FOUND", buf) == 0)
		return;

	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
		buf[strlen(buf)] = 13;
	m_Ports[0].WriteToPort(buf);	
}


void CDlgComm::OnBnClickedConfigbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgCommConfig* dlg = new CDlgCommConfig(this, m_Ports[0].GetDCB());
	dlg->m_strSendBuffer.Format("%d", m_Ports[0].GetWriteBufferSize());
	
	DWORD dwCommEvents = m_Ports[0].GetCommEvents();
	dlg->m_CommBreakDetected = (dwCommEvents & EV_BREAK) > 0 ? TRUE : FALSE;
	dlg->m_CommCTSDetected   = (dwCommEvents & EV_CTS) > 0 ? TRUE : FALSE;
	dlg->m_CommDSRDetected   = (dwCommEvents & EV_DSR) > 0 ? TRUE : FALSE;
	dlg->m_CommERRDetected   = (dwCommEvents & EV_ERR) > 0 ? TRUE : FALSE;
	dlg->m_CommRingDetected  = (dwCommEvents & EV_RING) > 0 ? TRUE : FALSE;
	dlg->m_CommRLSDDetected  = (dwCommEvents & EV_RLSD) > 0 ? TRUE : FALSE;
	dlg->m_CommRxchar        = (dwCommEvents & EV_RXCHAR) > 0 ? TRUE : FALSE;
	dlg->m_CommRxcharFlag    = (dwCommEvents & EV_RXFLAG) > 0 ? TRUE : FALSE;
	dlg->m_CommTXEmpty       = (dwCommEvents & EV_TXEMPTY) > 0 ? TRUE : FALSE;

	if (dlg->DoModal() == IDOK)
	{
		DWORD dwCommEvents = 0;
		if (dlg->m_CommBreakDetected)
			dwCommEvents |= EV_BREAK;
		if (dlg->m_CommCTSDetected)
			dwCommEvents |= EV_CTS;
		if (dlg->m_CommDSRDetected)
			dwCommEvents |= EV_DSR;
		if (dlg->m_CommERRDetected)
			dwCommEvents |= EV_ERR;
		if (dlg->m_CommRingDetected)
			dwCommEvents |= EV_RING;
		if (dlg->m_CommRLSDDetected)
			dwCommEvents |= EV_RLSD;
		if (dlg->m_CommRxchar)
			dwCommEvents |= EV_RXCHAR;
		if (dlg->m_CommRxcharFlag)
			dwCommEvents |= EV_RXFLAG;
		if (dlg->m_CommTXEmpty)
			dwCommEvents |= EV_TXEMPTY;

		m_Ports[0].InitPort(this, 10, 
			atoi(dlg->m_strBaudRate),
			dlg->m_strParity[0],
			atoi(dlg->m_strDataBits),
			atoi(dlg->m_strStopBits),
			dwCommEvents,
			atoi(dlg->m_strSendBuffer));

		m_Ports[0].StartMonitoring();
	}
	
	delete dlg;
}


BOOL CDlgComm::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_ListBox[0].SubclassDlgItem(ID_LIST1, this);
	m_ListBox[1].SubclassDlgItem(ID_LIST2, this);
	m_ListBox[2].SubclassDlgItem(ID_LIST3, this);
	m_ListBox[3].SubclassDlgItem(ID_LIST4, this);

	m_Edit[0].SubclassDlgItem(ID_EDIT1, this);
	m_Edit[1].SubclassDlgItem(ID_EDIT2, this);
	m_Edit[2].SubclassDlgItem(ID_EDIT3, this);
	m_Edit[3].SubclassDlgItem(ID_EDIT4, this);

	// init the ports
	for (int i = 9; i < 10; i++)
	{
		if (m_Ports[i-9].InitPort(this, i + 1, i == 9 ? 9600 : 19200,'N',8,1))
			m_Ports[i-9].StartMonitoring();
		else
		{
			// port not found
			m_Edit[i-9].SetWindowText("NOT FOUND");
			m_Edit[i-9].EnableWindow(FALSE);
			m_ListBox[i-9].EnableWindow(FALSE);
		}
			
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
LONG CDlgComm::OnCommunication(WPARAM ch, LPARAM port)
{
	if (port <= 9 || port > 14)
		return -1;

	if (ch == 13 && ((CButton*)GetDlgItem(IDC_CHECK5 + port - 10))->GetCheck())
	{
		m_ListBox[port-10].AddString(m_strReceived[port-10]);
		m_ListBox[port-10].SetSel(m_ListBox[port-10].GetCount()-1, TRUE);
		(m_strReceived[port-10]).Empty();
	}
	else if (((CButton*)GetDlgItem(IDC_CHECK5 + port - 10))->GetCheck())
		m_strReceived[port-10] += (char)ch;
	else
	{
		CString string;
		 char  weightValue[128];
		memset(weightValue,0,128);
		
		memcpy(weightValue,(char*)(ch+4),7);
		
		//string += (char*)ch;
		double dWeight = atof(weightValue);
		dWeight /=10;
		string.Format("%.1f",dWeight);
		//string += (char*)weightValue;
		m_ListBox[port-10].AddString(string);
		m_ListBox[port-10].SetSel(m_ListBox[port-10].GetCount()-1, TRUE);
	}

	return 0;
}

LONG CDlgComm::OnCTSDetected(WPARAM, LPARAM port)
{
	if (port < 10 || port > 14)
		return -1;

/*	CString string;
	string = "Clear To Send";
	m_ListBox[port-10].AddString(string);
	m_ListBox[port-10].SetSel(m_ListBox[port-10].GetCount()-1, TRUE);
	*/
	return 0;
}
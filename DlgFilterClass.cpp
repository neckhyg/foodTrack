// DlgFilterClass.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgFilterClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgFilterClass dialog


CDlgFilterClass::CDlgFilterClass(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFilterClass::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgFilterClass)
	m_tmStart = CTime::GetCurrentTime();
	m_tmEnd = CTime::GetCurrentTime();
	m_sAutoNo = _T("");
	m_sTeacher = _T("");
	//}}AFX_DATA_INIT
}


void CDlgFilterClass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgFilterClass)
	DDX_Control(pDX, IDOK, m_btnOk);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tmStart);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_tmEnd);
	DDX_Text(pDX, IDC_EDIT1, m_sAutoNo);
	DDX_Text(pDX, IDC_EDIT2, m_sTeacher);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgFilterClass, CDialog)
	//{{AFX_MSG_MAP(CDlgFilterClass)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgFilterClass message handlers

void CDlgFilterClass::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();

	if(GetFocus()==&m_btnOk)
		CDialog::OnOK();
	else if(GetFocus()==&m_btnCancel)
		CDialog::OnCancel();
	else 
	{
		CWnd *pWnd = this->GetNextDlgTabItem(GetFocus());
		if(pWnd)
			pWnd->SetFocus();
	}
	//CDialog::OnOK();
}


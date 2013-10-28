// DlgFindStudent.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgFindStudent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgFindStudent dialog


CDlgFindStudent::CDlgFindStudent(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFindStudent::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgFindStudent)
	m_sName = _T("");
	//}}AFX_DATA_INIT
}


void CDlgFindStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgFindStudent)
	DDX_Text(pDX, IDC_EDIT1, m_sName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgFindStudent, CDialog)
	//{{AFX_MSG_MAP(CDlgFindStudent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgFindStudent message handlers

void CDlgFindStudent::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CDialog::OnOK();
}

// DlgStudentInfor.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgStudentInfor.h"
#include "Student.h"
#include "foodTrackDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgStudentInfor dialog


CDlgStudentInfor::CDlgStudentInfor(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgStudentInfor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgStudentInfor)
	m_tmEnd = CTime::GetCurrentTime();
	m_tmExamField = CTime::GetCurrentTime();
	m_tmExamRoad = CTime::GetCurrentTime();
	m_tmUpAuto = CTime::GetCurrentTime();
	//}}AFX_DATA_INIT
	m_pStu = NULL;
}


void CDlgStudentInfor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgStudentInfor)
	DDX_Control(pDX, IDC_COMBO1, m_cbxExamType);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_END, m_tmEnd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_EXAMFIELD, m_tmExamField);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_EXAMROAD, m_tmExamRoad);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_UPAUTO, m_tmUpAuto);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgStudentInfor, CDialog)
	//{{AFX_MSG_MAP(CDlgStudentInfor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgStudentInfor message handlers

BOOL CDlgStudentInfor::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	pApp->m_pDoc->FillItemsToComboBox(&m_cbxExamType,&pApp->m_pDoc->m_arrExamType);

	if(m_pStu)
	{
		for(int i=0;i<m_cbxExamType.GetCount();i++)
		{
			if((int)m_cbxExamType.GetItemData(i)==m_pStu->m_nExamTypeID)
			{
				m_cbxExamType.SetCurSel(i);
				break;
			}
		}
		this->m_tmEnd = m_pStu->m_tmEnd;
		this->m_tmExamField = m_pStu->m_tmExamField;
		this->m_tmExamRoad = m_pStu->m_tmExamRoad;
		this->m_tmUpAuto = m_pStu->m_tmUpAuto;
		UpdateData(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgStudentInfor::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_pStu)
	{
		m_pStu->m_nExamTypeID = (int)m_cbxExamType.GetItemData(m_cbxExamType.GetCurSel());
		m_pStu->m_tmEnd = this->m_tmEnd;
		m_pStu->m_tmExamField = this->m_tmExamField;
		m_pStu->m_tmExamRoad = this->m_tmExamRoad;
		m_pStu->m_tmUpAuto = this->m_tmUpAuto;
	}
	CDialog::OnOK();
}

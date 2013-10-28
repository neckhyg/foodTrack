// DlgSelectStudent.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgSelectStudent.h"
#include "foodTrackDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSelectStudent dialog


CDlgSelectStudent::CDlgSelectStudent(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSelectStudent::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSelectStudent)
	m_sName = _T("");
	//}}AFX_DATA_INIT
	m_pStudent = NULL;
}


void CDlgSelectStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSelectStudent)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, ID_BUTTON_SELECT, m_btnSelect);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_cbxSex);
	DDX_Text(pDX, IDC_EDIT1, m_sName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSelectStudent, CDialog)
	//{{AFX_MSG_MAP(CDlgSelectStudent)
	ON_BN_CLICKED(ID_BUTTON_SELECT, OnButtonSelect)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSelectStudent message handlers

CStudent* CDlgSelectStudent::SelectStudent()
{
	this->DoModal();
	//if(DoModal()==IDOK)
	//	return m_pStudent;
	//return NULL;
	return m_pStudent;
}

void CDlgSelectStudent::OnOK() 
{
	// TODO: Add extra validation here
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	CString s;
	
	if(GetFocus()==&m_btnSelect)
		OnButtonSelect();
	else if(GetFocus()==&m_btnCancel)
		CDialog::OnCancel();
	else 
	{
		if(m_cbxSex.GetCurSel()>=0)
			m_cbxSex.GetWindowText(s);
		UpdateData();
		m_sName.TrimLeft();
		pApp->m_pDoc->FillStudentsToListctrl(&m_list,s,m_sName);  
	}
	//CDialog::OnOK();
}

void CDlgSelectStudent::OnButtonSelect() 
{
	// TODO: Add your control notification handler code here
	long ID = 0;
	int i,iState;
	int nItemSelected=m_list.GetSelectedCount();//��ѡ������
	int nItemCount=m_list.GetItemCount();//��������
	if(nItemSelected<1) return;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	for(i=nItemCount-1;i>=0;i--)
	{
		iState=m_list.GetItemState(i,LVIS_SELECTED);
		if(iState!=0) 
		{
			ID=m_list.GetItemData(i);
			m_pStudent = (CStudent*)pApp->m_pDoc->GetItemByID(&pApp->m_pDoc->m_arrStudent,ID);
			if(m_pStudent)
				CDialog::OnOK();
		}
	}
}

BOOL CDlgSelectStudent::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	LONG lStyle;
	lStyle=GetWindowLong(m_list.GetSafeHwnd(),GWL_STYLE);//��ȡ��ǰ��������
	lStyle&=~LVS_TYPEMASK; //�����ʾ��ʽλ
	lStyle|=LVS_REPORT; //������ʾ��ʽ
	SetWindowLong(m_list.GetSafeHwnd(),GWL_STYLE,lStyle);//���ô�������
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	pApp->m_pDoc->FillStudentsToListctrl(&m_list,_T(""),_T("")); 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSelectStudent::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	CString s;
	if(m_cbxSex.GetCurSel()>=0)
		m_cbxSex.GetWindowText(s);
	UpdateData();
	m_sName.TrimLeft();
	pApp->m_pDoc->FillStudentsToListctrl(&m_list,s,m_sName);  
}

 
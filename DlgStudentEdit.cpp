// DlgStudentEdit.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgStudentEdit.h"
#include "foodTrackDoc.h"
#include "RstStudent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgStudentEdit dialog


CDlgStudentEdit::CDlgStudentEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgStudentEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgStudentEdit)
	m_sAddress = _T("");
	m_sAutoNo = _T("");
	m_sName = _T("");
	m_sRemark = _T("");
	m_sSN = _T("");
	m_sTel = _T("");
	m_tmDate = CTime::GetCurrentTime();
	//}}AFX_DATA_INIT
	m_nOldID = 0;
}


void CDlgStudentEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgStudentEdit)
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, ID_BUTTON_SAVE, m_btnSave);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_cbxType);
	DDX_Control(pDX, IDC_COMBO_SEX, m_cbxSex);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tmDate);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_sAddress);
	DDX_Text(pDX, IDC_EDIT_AUTONO, m_sAutoNo);
	DDX_Text(pDX, IDC_EDIT_NAME, m_sName);
	DDX_Text(pDX, IDC_EDIT_REMARK, m_sRemark);
	DDX_Text(pDX, IDC_EDIT_SN, m_sSN);
	DDV_MaxChars(pDX, m_sSN, 18);
	DDX_Text(pDX, IDC_EDIT_TEL, m_sTel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgStudentEdit, CDialog)
	//{{AFX_MSG_MAP(CDlgStudentEdit)
	ON_BN_CLICKED(ID_BUTTON_SAVE, OnButtonSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgStudentEdit message handlers

BOOL CDlgStudentEdit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	pApp->m_pDoc->FillItemsToComboBox(&m_cbxType,&pApp->m_pDoc->m_arrStudentType);
	m_cbxSex.InsertString(0,"男");
	m_cbxSex.InsertString(1,"女");
	m_cbxSex.SetCurSel(0);
	CStudent *pStu=NULL;
	int i=0;
	CString s;
	if(m_nOldID>0)
	{
		pStu = (CStudent*)pApp->m_pDoc->GetItemByID(&pApp->m_pDoc->m_arrStudent,m_nOldID);
		if(pStu)
		{
			this->m_sAddress = pStu->m_F_Address;
			this->m_sAutoNo = pStu->m_F_AutoNo;
			this->m_sName = pStu->m_F_ItemName;
			this->m_sRemark = pStu->m_F_Remark;
			this->m_sSN = pStu->m_F_SN;
			this->m_sTel = pStu->m_F_Tel;
			for(i=0;i<m_cbxSex.GetCount();i++)
			{
				m_cbxSex.GetWindowText(s);
				if(s.Compare(pStu->m_F_Sex)==0)
				{
					m_cbxSex.SetCurSel(i);
					break;
				}
			}
			for(i=0;i<m_cbxType.GetCount();i++)
			{
				if((long)m_cbxType.GetItemData(i)==pStu->m_F_TypeID)
				{
					m_cbxType.SetCurSel(i);
					break;
				}
			}
			UpdateData(false);
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgStudentEdit::OnOK() 
{

	CWnd *pWnd = this->GetNextDlgTabItem(GetFocus());
	if(GetFocus()==&m_btnSave)
		OnButtonSave();
	else if(GetFocus()==&m_btnCancel)
		CDialog::OnCancel();
	else
		pWnd->SetFocus();

}

void CDlgStudentEdit::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	BOOL bTrans=false;
	UpdateData();
	this->m_sName.TrimLeft();
	CWnd *pWnd;
	if(m_sName.IsEmpty())
	{
		AfxMessageBox("名称必须填写!");
		pWnd = GetDlgItem(IDC_EDIT_NAME);
		if(pWnd)
			pWnd->SetFocus();
		return;
	}
	if(m_cbxSex.GetCurSel()<0)
	{
		AfxMessageBox("性别必须选择!");
		return;
	}
	if(m_cbxType.GetCurSel()<0)
	{
		AfxMessageBox("类别必须选择!");
		return;
	}
	if(MessageBox("你确实要保存该学员吗?","重要提示",MB_ICONQUESTION | MB_YESNO ) == IDNO)
		return;
	CRstStudent rs;
	CString s;
	try
	{
		if(m_nOldID<=0)
			m_nOldID = pApp->GetCurMaxKeyID("T_Student",true);
		rs.m_strFilter.Format("F_ID=%d",m_nOldID);
		rs.Open();
		if(rs.GetRecordCount()<=0)
			rs.AddNew();
		else
			rs.Edit();
		rs.m_F_Address = this->m_sAddress;
		rs.m_F_AutoNo = this->m_sAutoNo;
		rs.m_F_Date = this->m_tmDate;
		rs.m_F_ID = m_nOldID;
		rs.m_F_Name = this->m_sName;
		rs.m_F_Remark = this->m_sRemark;
		m_cbxSex.GetWindowText(s); 
		rs.m_F_Sex = s;
		rs.m_F_SN = this->m_sSN;
		rs.m_F_Tel = this->m_sTel;
		rs.m_F_TypeID = (long)m_cbxType.GetItemData(m_cbxType.GetCurSel());
		rs.Update();
		rs.Close();
		CStudent *pStu=(CStudent*)pApp->m_pDoc->GetItemByID(&pApp->m_pDoc->m_arrStudent,m_nOldID);
		if(pStu==NULL)
		{
			pStu = new CStudent;
			pApp->m_pDoc->m_arrStudent.Add(pStu);
		}
		pStu->m_F_Address = this->m_sAddress;
		pStu->m_F_AutoNo = this->m_sAutoNo;
		pStu->m_F_Date = this->m_tmDate;
		pStu->m_F_ID = m_nOldID;
		pStu->m_F_ItemName = this->m_sName;
		pStu->m_F_Remark = this->m_sRemark;
		pStu->m_F_Sex = s;
		pStu->m_F_SN = this->m_sSN;
		pStu->m_F_Tel = this->m_sTel;
		pStu->m_F_TypeID = (long)m_cbxType.GetItemData(m_cbxType.GetCurSel());

	}
	catch(CDBException e)
	{
		if(bTrans)
			pApp->m_db.Rollback();
		e.ReportError();
	}
	m_nOldID = 0;
	m_sAddress = _T("");
	m_sAutoNo = _T("");
	m_sName = _T("");
	m_sRemark = _T("");
	m_sSN = _T("");
	m_sTel = _T("");
	UpdateData(false);
	pWnd = GetDlgItem(IDC_EDIT_NAME);
	if(pWnd)
		pWnd->SetFocus();
}


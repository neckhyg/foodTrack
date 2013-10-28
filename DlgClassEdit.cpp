// DlgClassEdit.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgClassEdit.h"
#include "DlgSelectStudent.h"
#include "foodTrackDoc.h"
#include "DlgStudentInfor.h"
#include "RstClass.h"
#include "RstClassList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgClassEdit dialog


CDlgClassEdit::CDlgClassEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgClassEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgClassEdit)
	m_tmDate = CTime::GetCurrentTime();
	m_sAutoNo = _T("");
	m_sTeacher = _T("");
	m_sRemark = _T("");
	//}}AFX_DATA_INIT
	m_nOldID = 0;
}


void CDlgClassEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgClassEdit)
	DDX_Control(pDX, IDC_BUTTON_MODIFYSTUDENT, m_btnModify);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, ID_BUTTON_SAVE, m_btnSave);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_cbxNoon);
	DDX_Control(pDX, IDC_BUTTON_REMOVESTUDENT, m_btnRemoveStudent);
	DDX_Control(pDX, IDC_BUTTON_ADDSTUDENT, m_btnAddStudent);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tmDate);
	DDX_Text(pDX, IDC_EDIT_AUTONO, m_sAutoNo);
	DDX_Text(pDX, IDC_EDIT_TEACHER, m_sTeacher);
	DDX_Text(pDX, IDC_EDIT_REMARK, m_sRemark);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgClassEdit, CDialog)
	//{{AFX_MSG_MAP(CDlgClassEdit)
	ON_BN_CLICKED(IDC_BUTTON_ADDSTUDENT, OnButtonAddstudent)
	ON_BN_CLICKED(IDC_BUTTON_REMOVESTUDENT, OnButtonRemovestudent)
	ON_BN_CLICKED(IDC_BUTTON_MODIFYSTUDENT, OnButtonModifystudent)
	ON_BN_CLICKED(ID_BUTTON_SAVE, OnButtonSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgClassEdit message handlers

BOOL CDlgClassEdit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	LONG lStyle;
	lStyle=GetWindowLong(m_list.GetSafeHwnd(),GWL_STYLE);//获取当前窗口类型
	lStyle&=~LVS_TYPEMASK; //清除显示方式位
	lStyle|=LVS_REPORT; //设置显示方式
	SetWindowLong(m_list.GetSafeHwnd(),GWL_STYLE,lStyle);//设置窗口类型
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	if(m_cbxNoon.GetCount()>0)
		m_cbxNoon.SetCurSel(0);

	CListCtrl *pListCtrl = &m_list;
	pListCtrl->DeleteAllItems();
	while(pListCtrl->DeleteColumn(0)){}
	pListCtrl->InsertColumn(0,"姓名",LVCFMT_LEFT,50,-1);
	pListCtrl->InsertColumn(1,"性别",LVCFMT_LEFT,40,-1);
	pListCtrl->InsertColumn(2,"电话",LVCFMT_LEFT,90,-1);
	pListCtrl->InsertColumn(3,"上车时间",LVCFMT_LEFT,70,-1);
	pListCtrl->InsertColumn(4,"场考时间",LVCFMT_LEFT,70,-1);
	pListCtrl->InsertColumn(5,"路考时间",LVCFMT_LEFT,70,-1);
	pListCtrl->InsertColumn(6,"考试类型",LVCFMT_LEFT,70,-1);
	pListCtrl->InsertColumn(7,"发证日期",LVCFMT_LEFT,70,-1);

	CRstClass rsBill;
	CRstClassList rsSub;
	CStudent *pStu;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	if(m_nOldID>0)
	{//读取老的记录
		rsBill.m_strFilter.Format("F_ID=%d",m_nOldID);
		rsBill.Open();
		if(rsBill.GetRecordCount()>0)
		{
			this->m_sAutoNo = rsBill.m_F_AutoNo;
			this->m_sRemark = rsBill.m_F_Remark;
			this->m_sTeacher = rsBill.m_F_Teacher;
			this->m_tmDate = rsBill.m_F_Date;
		}
		rsBill.Close();
		rsSub.m_strFilter.Format("F_ClassID=%d",m_nOldID);
		rsSub.Open();
		while(!rsSub.IsEOF())
		{
			pStu = (CStudent*)pApp->m_pDoc->GetItemByID(&pApp->m_pDoc->m_arrStudent,rsSub.m_F_StudentID);
			if(pStu)
			{
				pStu->m_nExamTypeID = rsSub.m_F_ExamTypeID;
				pStu->m_tmEnd = rsSub.m_F_DateEnd;
				pStu->m_tmExamField = rsSub.m_F_DateField;
				pStu->m_tmExamRoad = rsSub.m_F_DateRoad;
				pStu->m_tmUpAuto = rsSub.m_F_DateUpAuto;
				
				m_arrStudent.Add(pStu);
			}
			rsSub.MoveNext();
		}
		rsSub.Close();
		FillStudents();
		UpdateData(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgClassEdit::OnButtonAddstudent() 
{

	CDlgSelectStudent dlg;
	CStudent *pStu=dlg.SelectStudent();
	if(pStu)
	{
		if(GetStudentByID(pStu->m_F_ID)==NULL)
		{
			m_arrStudent.Add(pStu);
		}
		FillStudents();
	}
}

CStudent* CDlgClassEdit::GetStudentByID(long nID)
{
	for(int i=0;i<m_arrStudent.GetSize();i++)
	{
		if(m_arrStudent[i]->m_F_ID == nID)
			return m_arrStudent[i];
	}
	return NULL;
}

int CDlgClassEdit::FillStudents()
{
	CListCtrl *pListCtrl = &m_list;
	pListCtrl->DeleteAllItems();
	
	LV_ITEM lvitem;
	CStudent *pStu;
	CItem *pItem;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	CString sTmp;
	int i=0,iPos=0;
	for(i = 0;i<m_arrStudent.GetSize();i++)
	{
		lvitem.mask = LVIF_TEXT|LVIF_IMAGE|LVIF_PARAM;
		lvitem.iItem = pListCtrl->GetItemCount();
		lvitem.iSubItem = 0;
		sTmp.Format("%d",pListCtrl->GetItemCount()+1);
		lvitem.pszText = sTmp.GetBuffer(MAX_PATH) ;
		lvitem.iImage = 0;
		pStu = m_arrStudent.GetAt(i);
		if(pStu)
		{
			////0,"姓名/性别/电话/上车时间/场考时间/路考时间/考试类型/发证日期
			iPos = pListCtrl->InsertItem(&lvitem);
			pListCtrl->SetItemText(iPos,0,pStu->m_F_ItemName);
			pListCtrl->SetItemText(iPos,1,pStu->m_F_Sex);
			pListCtrl->SetItemText(iPos,2,pStu->m_F_Tel); 
			if(pStu->m_tmUpAuto>0)
			{
				sTmp.Format("%d-%d-%d",pStu->m_tmUpAuto.GetYear(),pStu->m_tmUpAuto.GetMonth(),pStu->m_tmUpAuto.GetDay());
				pListCtrl->SetItemText(iPos,3,sTmp);
			}
			if(pStu->m_tmExamField>0)
			{
				sTmp.Format("%d-%d-%d",pStu->m_tmExamField.GetYear(),pStu->m_tmExamField.GetMonth(),pStu->m_tmExamField.GetDay());
				pListCtrl->SetItemText(iPos,4,sTmp);
			}
			if(pStu->m_tmExamRoad>0)
			{
				sTmp.Format("%d-%d-%d",pStu->m_tmExamRoad.GetYear(),pStu->m_tmExamRoad.GetMonth(),pStu->m_tmExamRoad.GetDay());
				pListCtrl->SetItemText(iPos,5,sTmp);
			}
			pItem = pApp->m_pDoc->GetItemByID(&pApp->m_pDoc->m_arrExamType,pStu->m_nExamTypeID);
			if(pItem)
				pListCtrl->SetItemText(iPos,6,pItem->m_F_ItemName);
			if(pStu->m_tmEnd>0)
			{
				sTmp.Format("%d-%d-%d",pStu->m_tmEnd.GetYear(),pStu->m_tmEnd.GetMonth(),pStu->m_tmEnd.GetDay());
				pListCtrl->SetItemText(iPos,7,sTmp);
			}
			pListCtrl->SetItemData(iPos,pStu->m_F_ID);
		}
	}
	return pListCtrl->GetItemCount();
}

void CDlgClassEdit::OnButtonRemovestudent() 
{
	// TODO: Add your control notification handler code here
	long ID = 0;
	int i,iState;
	int nItemSelected=m_list.GetSelectedCount();//所选表项数
	int nItemCount=m_list.GetItemCount();//表项总数
	if(nItemSelected<1) return;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	CStudent *pStu;
	for(i=nItemCount-1;i>=0;i--)
	{
		iState=m_list.GetItemState(i,LVIS_SELECTED);
		if(iState!=0) 
		{
			ID=m_list.GetItemData(i);
			pStu = GetStudentByID(ID);
			if(pStu)
			{
				if(MessageBox("你确实要移除该学员吗?","重要提示",MB_ICONQUESTION | MB_YESNO ) == IDNO)
					return;
				RemoveStudentByID(ID);
				FillStudents();
			}
		}
	}
}

void CDlgClassEdit::RemoveStudentByID(long ID)
{
	for(int i=0;i<m_arrStudent.GetSize();i++)
	{
		if(m_arrStudent[i]->m_F_ID == ID)
		{
			m_arrStudent.RemoveAt(i); 
			return;
		}
	}
}

void CDlgClassEdit::OnButtonModifystudent() 
{
	// TODO: Add your control notification handler code here
	CDlgStudentInfor dlg;
	long ID = 0;
	int i,iState;
	int nItemSelected=m_list.GetSelectedCount();//所选表项数
	int nItemCount=m_list.GetItemCount();//表项总数
	if(nItemSelected<1) return;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	CStudent *pStu;
	for(i=nItemCount-1;i>=0;i--)
	{
		iState=m_list.GetItemState(i,LVIS_SELECTED);
		if(iState!=0) 
		{
			ID=m_list.GetItemData(i);
			pStu = GetStudentByID(ID);
			if(pStu)
			{
				dlg.m_pStu = pStu;
				if(dlg.DoModal()==IDOK)
					FillStudents();
			}
		}
	}
}

void CDlgClassEdit::OnOK() 
{
	// TODO: Add extra validation here
	CWnd *pWnd;
	if(GetFocus()==&m_btnSave)
		OnButtonSave();
	else if(GetFocus()==&m_btnCancel)
		OnCancel();
	else if(GetFocus()==&m_btnAddStudent)
		OnButtonAddstudent();
	else if(GetFocus()==&m_btnRemoveStudent)
		OnButtonRemovestudent();
	else if(GetFocus()==&m_btnModify)
		OnButtonModifystudent();
	else
	{
		pWnd = this->GetNextDlgTabItem(GetFocus());
		if(pWnd)
			pWnd->SetFocus();
	}

	//CDialog::OnOK();
}

void CDlgClassEdit::OnButtonSave() 
{
	// TODO: Add your control notification handler code here
	if(MessageBox("你确实要保存该班次吗?","重要提示",MB_ICONQUESTION | MB_YESNO ) == IDNO)
		return;
	UpdateData();
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	BOOL bTrans = false;
	CRstClass rsBill;
	CRstClassList rsSub;
	CString sql;
	CStudent *pStu;
	try
	{
		pApp->m_db.BeginTrans();
		bTrans = true;
		{
			if(m_nOldID<=0)
				m_nOldID = pApp->GetCurMaxKeyID("T_Class",true);
			rsBill.m_strFilter.Format("F_ID=%d",m_nOldID);
			rsBill.Open();
			if(rsBill.GetRecordCount()>0)
				rsBill.Edit();
			else
				rsBill.AddNew();
			rsBill.m_F_AutoNo = this->m_sAutoNo;
			rsBill.m_F_Date = this->m_tmDate;
			rsBill.m_F_ID = m_nOldID;
			rsBill.m_F_Noon = (int)m_cbxNoon.GetItemData(m_cbxNoon.GetCurSel());
			rsBill.m_F_Remark = this->m_sRemark;
			rsBill.m_F_Teacher = this->m_sTeacher;
			rsBill.Update();
			rsBill.Close();
			sql.Format("Delete From T_ClassList Where F_ClassID=%d",m_nOldID);
			pApp->m_db.ExecuteSQL(sql);
			rsSub.m_strFilter.Format("F_ClassID = %d",m_nOldID);
			rsSub.Open();
			//保存明细记录
			for(int i=0;i<m_arrStudent.GetSize();i++)
			{
				pStu = m_arrStudent[i];
				rsSub.AddNew();
				rsSub.m_F_ClassID = m_nOldID;
				rsSub.m_F_DateEnd = pStu->m_tmEnd;
				rsSub.m_F_DateField = pStu->m_tmExamField;
				rsSub.m_F_DateRoad = pStu->m_tmExamRoad;
				rsSub.m_F_DateUpAuto = pStu->m_tmUpAuto;
				rsSub.m_F_ExamTypeID = pStu->m_nExamTypeID;
				rsSub.m_F_ID = pApp->GetCurMaxKeyID("T_ClassList",true);
				rsSub.m_F_StudentID = pStu->m_F_ID;
				rsSub.Update();
			}
			rsSub.Close();
		}
		pApp->m_db.CommitTrans();
		bTrans = false;
	}
	catch(CDBException e)
	{
		if(bTrans)
			pApp->m_db.Rollback();
		e.ReportError();
		e.Delete();
	}
	m_sAutoNo = _T("");
	m_sTeacher = _T("");
	m_sRemark = _T("");
	m_nOldID = 0;
	m_arrStudent.RemoveAll();
	FillStudents();
	UpdateData(false);
}


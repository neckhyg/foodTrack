// CfoodTrackListView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "foodTrack.h"
#include "CfoodTrackListView.h"

#include "foodTrackDoc.h"
#include "foodTrackView.h"
#include "DlgStudentEdit.h"
#include "DlgClassEdit.h"
#include "DlgFilterClass.h"
#include "DlgFindStudent.h"



// CfoodTrackListView

IMPLEMENT_DYNCREATE(CfoodTrackListView, CListView)


CfoodTrackListView::CfoodTrackListView()
{
	m_pDlgComm = NULL;
	m_pDlgCardReviewer = NULL;
}

CfoodTrackListView::~CfoodTrackListView()
{
	if( m_pDlgComm != NULL)
	delete m_pDlgComm;

	m_pDlgComm = NULL;

	if( m_pDlgCardReviewer != NULL)
		delete m_pDlgCardReviewer;

	m_pDlgCardReviewer = NULL;

}

BEGIN_MESSAGE_MAP(CfoodTrackListView, CListView)
	//{{AFX_MSG_MAP(CfoodTrackListView)
	ON_COMMAND(ID_DATA_STUDENT, OnDataStudent)
	ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
	ON_UPDATE_COMMAND_UI(ID_DATA_STUDENT, OnUpdateDataStudent)
	ON_COMMAND(ID_DATA_CLASS, OnDataClass)
	ON_UPDATE_COMMAND_UI(ID_DATA_CLASS, OnUpdateDataClass)
	ON_COMMAND(ID_EDIT_ADDNEW, OnEditAddnew)
	ON_COMMAND(ID_EDIT_MODIFY, OnEditModify)
	ON_COMMAND(ID_EDIT_DELETE, OnEditDelete)
	ON_COMMAND(ID_EDIT_SEARCH, OnEditSearch)
	ON_COMMAND(ID_VIEW_CLEARDATA, OnViewCleardata)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
	ON_COMMAND(ID_DATA_WEIGHT, &CfoodTrackListView::OnDataWeight)
END_MESSAGE_MAP()


// CfoodTrackListView ���

#ifdef _DEBUG
void CfoodTrackListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CfoodTrackListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CfoodTrackListView ��Ϣ�������
BOOL CfoodTrackListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CfoodTrackListView drawing

void CfoodTrackListView::OnDraw(CDC* pDC)
{
	CfoodTrackDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CfoodTrackListView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
	LONG lStyle;
	lStyle=GetWindowLong(this->GetListCtrl().GetSafeHwnd(),GWL_STYLE);//��ȡ��ǰ��������
	lStyle&=~LVS_TYPEMASK; //�����ʾ��ʽλ
	lStyle|=LVS_REPORT; //������ʾ��ʽ
	SetWindowLong(this->GetListCtrl().GetSafeHwnd(),GWL_STYLE,lStyle);//���ô�������
	this->GetListCtrl().SetExtendedStyle(LVS_EX_FULLROWSELECT);

	OnDataStudent();
}

/////////////////////////////////////////////////////////////////////////////
// CfoodTrackListView printing

BOOL CfoodTrackListView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CfoodTrackListView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CfoodTrackListView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CfoodTrackListView diagnostics

#ifdef _DEBUG
/*void CfoodTrackListView::AssertValid() const
{
	CListView::AssertValid();
}

void CfoodTrackListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
*/
CfoodTrackDoc* CfoodTrackListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CfoodTrackDoc)));
	return (CfoodTrackDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CfoodTrackListView message handlers

void CfoodTrackListView::OnDataStudent() 
{
	// TODO: Add your command handler code here
	m_nDataType = dtStudent;
	OnViewRefresh();
}

void CfoodTrackListView::OnViewRefresh() 
{
	// TODO: Add your command handler code here
	CListCtrl *pListCtrl;
	pListCtrl = &this->GetListCtrl(); 
	pListCtrl->DeleteAllItems();
	while(pListCtrl->DeleteColumn(0)){}

	//LV_ITEM lvitem;
	CStudent *pStu;
	CItem *pItem;
	CString sTmp;
	CClass *pClass;
	int i=0,iPos=0,j=0;
	CfoodTrackDoc *pDoc=this->GetDocument();
	switch(m_nDataType)
	{
	case dtStudent:
		pDoc->FillStudentsToListctrl(pListCtrl,_T(""),_T("")); 
		break;
	case dtClass:
		pListCtrl->InsertColumn(0,"*",LVCFMT_LEFT,30,-1);
		pListCtrl->InsertColumn(1,"����",LVCFMT_LEFT,80,-1);
		pListCtrl->InsertColumn(2,"ʱ��",LVCFMT_LEFT,40,-1);
		pListCtrl->InsertColumn(3,"����",LVCFMT_LEFT,80,-1);
		pListCtrl->InsertColumn(4,"����",LVCFMT_LEFT,50,-1);
		pListCtrl->InsertColumn(5,"����",LVCFMT_LEFT,50,-1);
		pListCtrl->InsertColumn(6,"�Ա�",LVCFMT_LEFT,40,-1);
		pListCtrl->InsertColumn(7,"���֤",LVCFMT_LEFT,100,-1);
		pListCtrl->InsertColumn(8,"��ϵ��ַ",LVCFMT_LEFT,110,-1);
		pListCtrl->InsertColumn(9,"�绰",LVCFMT_LEFT,80,-1);		
		pListCtrl->InsertColumn(10,"�ϳ�ʱ��",LVCFMT_LEFT,70,-1);
		pListCtrl->InsertColumn(11,"����ʱ��",LVCFMT_LEFT,70,-1);
		pListCtrl->InsertColumn(12,"·��ʱ��",LVCFMT_LEFT,70,-1);
		pListCtrl->InsertColumn(13,"��������",LVCFMT_LEFT,70,-1);
		pListCtrl->InsertColumn(14,"��֤����",LVCFMT_LEFT,70,-1);
		if(pDoc->ReadClasss(0,0,_T(""),_T(""))<=0)
			return;
		for(i=0;i<pDoc->m_arrClass.GetSize();i++)
		{   pClass = pDoc->m_arrClass[i]; 
			for(j=0;j<pClass->m_arrStudent.GetSize();j++)
			{
				pStu = pClass->m_arrStudent[j];
				sTmp.Format("%d",pListCtrl->GetItemCount()+1);
				iPos = pListCtrl->InsertItem(pListCtrl->GetItemCount(),sTmp,0);
				sTmp.Format("%d-%d-%d",pClass->m_F_Date.GetYear(),pClass->m_F_Date.GetMonth(),pClass->m_F_Date.GetDay());
				pListCtrl->SetItemText(iPos,1,sTmp);
				if(pClass->m_F_NoonID==0)
					sTmp = "����";
				else
					sTmp = "����";
				pListCtrl->SetItemText(iPos,2,sTmp);
				pListCtrl->SetItemText(iPos,3,pClass->m_F_AutoNo);
				pListCtrl->SetItemText(iPos,4,pClass->m_F_Teacher);
				pListCtrl->SetItemText(iPos,5,pStu->m_F_ItemName);
				pListCtrl->SetItemText(iPos,6,pStu->m_F_Sex);
				pListCtrl->SetItemText(iPos,7,pStu->m_F_SN);
				pListCtrl->SetItemText(iPos,8,pStu->m_F_Address);
				pListCtrl->SetItemText(iPos,9,pStu->m_F_Tel);
			//*/����/ʱ��/����/����/����/�Ա�/���֤/��ϵ��ַ/�绰/�ϳ�ʱ��
			//����ʱ��/·��ʱ��/��������/��֤����
				if(pStu->m_tmUpAuto>0)
				{	
					sTmp.Format("%d-%d-%d",pStu->m_tmUpAuto.GetYear(),pStu->m_tmUpAuto.GetMonth(),pStu->m_tmUpAuto.GetDay());
					pListCtrl->SetItemText(iPos,10,sTmp);
				}
				if(pStu->m_tmExamField>0)
				{
					sTmp.Format("%d-%d-%d",pStu->m_tmExamField.GetYear(),pStu->m_tmExamField.GetMonth(),pStu->m_tmExamField.GetDay());
					pListCtrl->SetItemText(iPos,11,sTmp);
				}
				if(pStu->m_tmExamRoad>0)
				{
					sTmp.Format("%d-%d-%d",pStu->m_tmExamRoad.GetYear(),pStu->m_tmExamRoad.GetMonth(),pStu->m_tmExamRoad.GetDay());
					pListCtrl->SetItemText(iPos,12,sTmp);
				}
				pItem = pDoc->GetItemByID(&pDoc->m_arrExamType,pStu->m_nExamTypeID); 
				if(pItem)
					pListCtrl->SetItemText(iPos,13,pItem->m_F_ItemName); 
				if(pStu->m_tmEnd>0)
				{
					sTmp.Format("%d-%d-%d",pStu->m_tmEnd.GetYear(),pStu->m_tmEnd.GetMonth(),pStu->m_tmEnd.GetDay());
					pListCtrl->SetItemText(iPos,14,sTmp);
				}
				pListCtrl->SetItemData(iPos,pClass->m_F_ID);
			}
		}
		break;
	default:
		break;
	}
}

void CfoodTrackListView::OnUpdateDataStudent(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
	pCmdUI->SetCheck(m_nDataType == dtStudent);
}

void CfoodTrackListView::OnDataClass() 
{
	// TODO: Add your command handler code here
	m_nDataType = dtClass;
	OnViewRefresh();
}

void CfoodTrackListView::OnUpdateDataClass(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable();
	pCmdUI->SetCheck(m_nDataType == dtClass);
}

void CfoodTrackListView::OnEditAddnew() 
{
	// TODO: Add your command handler code here
	CDlgStudentEdit dlg;
	CDlgClassEdit dlg2;
	switch(m_nDataType)
	{
	case dtStudent:
		if(dlg.DoModal()==IDOK)
			OnViewRefresh();
		break;
	case dtClass:
		if(dlg2.DoModal()==IDOK)
			OnViewRefresh();
		break;
	}
}

void CfoodTrackListView::OnEditModify() 
{
	// TODO: Add your command handler code here
	CDlgStudentEdit dlg;
	CDlgClassEdit dlg2;
	int i,iState,ID;
	int nItemSelected = this->GetListCtrl().GetSelectedCount();//��ѡ������
	int nItemCount = this->GetListCtrl().GetItemCount();//��������
	for(i=0;i<=nItemCount;i++)
	{
		iState=this->GetListCtrl().GetItemState(i,LVIS_SELECTED);
		if(iState!=0) 
		{
			ID = this->GetListCtrl().GetItemData(i);
			switch(this->m_nDataType)
			{
			case dtStudent:
				dlg.m_nOldID = ID;
				if(dlg.DoModal()==IDOK)
					OnViewRefresh(); 
				break;
			case dtClass:
				dlg2.m_nOldID = ID;
				if(dlg2.DoModal()==IDOK)
					OnViewRefresh();
				break;
			}
		}
	}
}

void CfoodTrackListView::OnEditDelete() 
{
	// TODO: Add your command handler code here
	long ID = 0;
	int i,iState;
	int nItemSelected=this->GetListCtrl().GetSelectedCount();//��ѡ������
	int nItemCount=this->GetListCtrl().GetItemCount();//��������
	if(nItemSelected<1) return;
	if (IDYES!=MessageBox(_T("��ȷʵҪɾ����Щ��¼��?"),_T("��Ҫ��ʾ"),MB_YESNO|MB_ICONQUESTION))
		return;
	for(i=nItemCount-1;i>=0;i--)
	{
		iState=this->GetListCtrl().GetItemState(i,LVIS_SELECTED);
		if(iState!=0) 
		{
			ID=this->GetListCtrl().GetItemData(i);
			if(KillItemByID(ID))
				this->GetListCtrl().DeleteItem(i);
		}
	}
}

BOOL CfoodTrackListView::KillItemByID(int ID)
{
	CString sql;
	CStudent *pStu=NULL;
	CClass *pClass=NULL;
	CfoodTrackApp *pApp = (CfoodTrackApp*)AfxGetApp(); 
	int i=0;
	switch(m_nDataType)
	{
	case dtStudent:
		sql.Format("Delete From T_Student Where F_ID=%d",ID);
		pApp->m_db.ExecuteSQL(sql);
		for(i=0;i<pApp->m_pDoc->m_arrStudent.GetSize();i++)
		{
			pStu = pApp->m_pDoc->m_arrStudent.GetAt(i);
			if(pStu)
			{
				if(pStu->m_F_ID == ID)
				{
					delete pStu;
					pApp->m_pDoc->m_arrStudent.RemoveAt(i);
					break;
				}
			}
		}
		return true;
		break;
	default:
		sql.Format("Delete From T_Class Where F_ID = %d",ID);
		pApp->m_db.ExecuteSQL(sql);
		return true;
		break;
	}
	return false;
}

void CfoodTrackListView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	OnViewRefresh();
}

void CfoodTrackListView::OnEditSearch() 
{
	// TODO: Add your command handler code here
	
	switch(m_nDataType)
	{
	case dtClass:
		FilterClass();
		break;
	case dtStudent:
		FindStudent();
		break;
	}
}

void CfoodTrackListView::FilterClass()
{
	CDlgFilterClass dlg;
	if(dlg.DoModal()==IDCANCEL)
		return;
	CListCtrl *pListCtrl;
	pListCtrl = &this->GetListCtrl(); 
	pListCtrl->DeleteAllItems();
	while(pListCtrl->DeleteColumn(0)){}
	
	//LV_ITEM lvitem;
	CStudent *pStu;
	CItem *pItem;
	CString sTmp;
	CClass *pClass;
	int i=0,iPos=0,j=0;
	CfoodTrackDoc *pDoc=this->GetDocument();
	
	pListCtrl->InsertColumn(0,"*",LVCFMT_LEFT,30,-1);
	pListCtrl->InsertColumn(1,"����",LVCFMT_LEFT,80,-1);
	pListCtrl->InsertColumn(2,"ʱ��",LVCFMT_LEFT,40,-1);
	pListCtrl->InsertColumn(3,"����",LVCFMT_LEFT,80,-1);
	pListCtrl->InsertColumn(4,"����",LVCFMT_LEFT,50,-1);
	pListCtrl->InsertColumn(5,"����",LVCFMT_LEFT,50,-1);
	pListCtrl->InsertColumn(6,"�Ա�",LVCFMT_LEFT,40,-1);
	pListCtrl->InsertColumn(7,"���֤",LVCFMT_LEFT,100,-1);
	pListCtrl->InsertColumn(8,"��ϵ��ַ",LVCFMT_LEFT,110,-1);
	pListCtrl->InsertColumn(9,"�绰",LVCFMT_LEFT,80,-1);		
	pListCtrl->InsertColumn(10,"�ϳ�ʱ��",LVCFMT_LEFT,70,-1);
	pListCtrl->InsertColumn(11,"����ʱ��",LVCFMT_LEFT,70,-1);
	pListCtrl->InsertColumn(12,"·��ʱ��",LVCFMT_LEFT,70,-1);
	pListCtrl->InsertColumn(13,"��������",LVCFMT_LEFT,70,-1);
	pListCtrl->InsertColumn(14,"��֤����",LVCFMT_LEFT,70,-1);
	if(pDoc->ReadClasss(dlg.m_tmStart,dlg.m_tmEnd,dlg.m_sAutoNo,dlg.m_sTeacher)<=0)
		return;
	for(i=0;i<pDoc->m_arrClass.GetSize();i++)
	{   pClass = pDoc->m_arrClass[i]; 
	for(j=0;j<pClass->m_arrStudent.GetSize();j++)
	{
		pStu = pClass->m_arrStudent[j];
		sTmp.Format("%d",pListCtrl->GetItemCount()+1);
		iPos = pListCtrl->InsertItem(pListCtrl->GetItemCount(),sTmp,0);
		sTmp.Format("%d-%d-%d",pClass->m_F_Date.GetYear(),pClass->m_F_Date.GetMonth(),pClass->m_F_Date.GetDay());
		pListCtrl->SetItemText(iPos,1,sTmp);
		if(pClass->m_F_NoonID==0)
			sTmp = "����";
		else
			sTmp = "����";
		pListCtrl->SetItemText(iPos,2,sTmp);
		pListCtrl->SetItemText(iPos,3,pClass->m_F_AutoNo);
		pListCtrl->SetItemText(iPos,4,pClass->m_F_Teacher);
		pListCtrl->SetItemText(iPos,5,pStu->m_F_ItemName);
		pListCtrl->SetItemText(iPos,6,pStu->m_F_Sex);
		pListCtrl->SetItemText(iPos,7,pStu->m_F_SN);
		pListCtrl->SetItemText(iPos,8,pStu->m_F_Address);
		pListCtrl->SetItemText(iPos,9,pStu->m_F_Tel);
		//*/����/ʱ��/����/����/����/�Ա�/���֤/��ϵ��ַ/�绰/�ϳ�ʱ��
		//����ʱ��/·��ʱ��/��������/��֤����
		if(pStu->m_tmUpAuto>0)
		{	
			sTmp.Format("%d-%d-%d",pStu->m_tmUpAuto.GetYear(),pStu->m_tmUpAuto.GetMonth(),pStu->m_tmUpAuto.GetDay());
			pListCtrl->SetItemText(iPos,10,sTmp);
		}
		if(pStu->m_tmExamField>0)
		{
			sTmp.Format("%d-%d-%d",pStu->m_tmExamField.GetYear(),pStu->m_tmExamField.GetMonth(),pStu->m_tmExamField.GetDay());
			pListCtrl->SetItemText(iPos,11,sTmp);
		}
		if(pStu->m_tmExamRoad>0)
		{
			sTmp.Format("%d-%d-%d",pStu->m_tmExamRoad.GetYear(),pStu->m_tmExamRoad.GetMonth(),pStu->m_tmExamRoad.GetDay());
			pListCtrl->SetItemText(iPos,12,sTmp);
		}
		pItem = pDoc->GetItemByID(&pDoc->m_arrExamType,pStu->m_nExamTypeID); 
		if(pItem)
			pListCtrl->SetItemText(iPos,13,pItem->m_F_ItemName); 
		if(pStu->m_tmEnd>0)
		{
			sTmp.Format("%d-%d-%d",pStu->m_tmEnd.GetYear(),pStu->m_tmEnd.GetMonth(),pStu->m_tmEnd.GetDay());
			pListCtrl->SetItemText(iPos,14,sTmp);
		}
		pListCtrl->SetItemData(iPos,pClass->m_F_ID);
	}
	}
	
}

void CfoodTrackListView::FindStudent()
{
	CDlgFindStudent dlg;
	if(dlg.DoModal()==IDCANCEL)
		return;
	int i;
	CListCtrl *pList=&this->GetListCtrl();
	CString sName=_T("");
	for(i=0;i<pList->GetItemCount();i++)
	{
		sName = pList->GetItemText(i,1);
		if(sName.Find(dlg.m_sName,0)>=0)
		{
			pList->SetItemState(i,LVIS_SELECTED,LVIS_SELECTED);
		}
		else
			pList->SetItemState(i,~LVIS_SELECTED,LVIS_SELECTED);
	}
}

void CfoodTrackListView::OnViewCleardata() 
{
	// TODO: Add your command handler code here
	if(MessageBox("��ȷʵҪ�������������?\n����������ݺ�,���򽫻��Զ��˳�!","��Ҫ��ʾ",MB_ICONQUESTION | MB_YESNO ) == IDNO)
		return;
	BOOL bTrans = false;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	CString sql;
	try
	{
		pApp->m_db.BeginTrans();
		bTrans = true;
		{
			//pApp->m_db.ExecuteSQL("Delete From T_Class");
			//pApp->m_db.ExecuteSQL("Delete From T_Student");
			TRACE("��ʼ������\n");
		}
		pApp->m_db.CommitTrans(); 
		bTrans = false;
	}
	catch(CDBException e)
	{
		if(bTrans)
			pApp->m_db.Rollback();
		e.ReportError();
	}
	pApp->GetMainWnd()->SendMessage(WM_CLOSE);
}

void CfoodTrackListView::OnDataWeight()
{
	// TODO: �ڴ���������������
/*	CDlgComm dlg;
	if(dlg.DoModal()==IDCANCEL)
		return;
	if( m_pDlgComm == NULL)
	   m_pDlgComm = new CDlgComm();

	if(m_pDlgComm->DoModal()==IDCANCEL)
		return;
*/
	if(!m_pDlgCardReviewer)
		m_pDlgCardReviewer = new CDlgCardReviewer();

	if(m_pDlgCardReviewer->DoModal()==IDCANCEL)
		return;
}

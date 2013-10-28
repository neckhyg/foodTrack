
// foodTrackDoc.cpp : CfoodTrackDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "foodTrack.h"
#endif

#include "RstStudent.h"
#include "RstStudentType.h"
#include "RstExamType.h"
#include "Class.h"
#include "RstClass.h"
#include "RstClassList.h"
#include "foodTrackSet.h"
#include "foodTrackDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CfoodTrackDoc

IMPLEMENT_DYNCREATE(CfoodTrackDoc, CDocument)

BEGIN_MESSAGE_MAP(CfoodTrackDoc, CDocument)
END_MESSAGE_MAP()


// CfoodTrackDoc 构造/析构

CfoodTrackDoc::CfoodTrackDoc()
{
	// TODO: 在此添加一次性构造代码

}

CfoodTrackDoc::~CfoodTrackDoc()
{
}

BOOL CfoodTrackDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	pApp->m_pDoc = this;

	ReadInitData();
	return TRUE;
}




// CfoodTrackDoc 序列化

void CfoodTrackDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CfoodTrackDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CfoodTrackDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CfoodTrackDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CfoodTrackDoc 诊断

#ifdef _DEBUG
void CfoodTrackDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CfoodTrackDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG



// CfoodTrackDoc 命令
void CfoodTrackDoc::ReadInitData()
{
	BeginWaitCursor();

	CItem *pItem;
	// 学员类型记录集对象
	CRstStudentType rsSt;
	// 打开记录集
	rsSt.Open();
	while(!rsSt.IsEOF())
	{
		pItem = new CItem;
		pItem->m_F_ID = rsSt.m_F_ID;
		pItem->m_F_ItemName = rsSt.m_F_ItemName;
		m_arrStudentType.Add(pItem);
		// 把当前记录集设置到下一个记录
		rsSt.MoveNext();
	}
	rsSt.Close();
	// 考试类型记录集对象
	CRstExamType rsExam;
	rsExam.Open();
	while(!rsExam.IsEOF())
	{
		pItem = new CItem;
		pItem->m_F_ID = rsExam.m_F_ID;
		pItem->m_F_ItemName = rsExam.m_F_ItemName; 
		m_arrExamType.Add(pItem);
		rsExam.MoveNext();
	}
	rsExam.Close();
	
	CStudent *pStu;
	// 学员信息记录集对象
	CRstStudent rsStudent;
	rsStudent.Open();
	while(!rsStudent.IsEOF())
	{
		pStu = new CStudent;
		pStu->m_F_ID = rsStudent.m_F_ID;
		pStu->m_F_Address = rsStudent.m_F_Address;
		pStu->m_F_AutoNo = rsStudent.m_F_AutoNo;
		pStu->m_F_Date = rsStudent.m_F_Date;
		pStu->m_F_ItemName = rsStudent.m_F_Name;
		pStu->m_F_Sex = rsStudent.m_F_Sex;
		pStu->m_F_SN = rsStudent.m_F_SN;
		pStu->m_F_Tel = rsStudent.m_F_Tel;
		pStu->m_F_TypeID = rsStudent.m_F_TypeID;
		pStu->m_F_Remark = rsStudent.m_F_Remark;
		m_arrStudent.Add(pStu);
		rsStudent.MoveNext();
	}
	rsStudent.Close();

	EndWaitCursor();
}

CItem* CfoodTrackDoc::GetItemByID(CObArray *pArr, long nID)
{
	ASSERT(pArr);
	CItem *pItem=NULL;
	for(int i=0;i<pArr->GetSize();i++)
	{
		pItem = (CItem*)pArr->GetAt(i);
		if(pItem->m_F_ID == nID)
			return pItem;
	}
	return NULL;
}

int CfoodTrackDoc::FillItemsToComboBox(CComboBox *pcbo, CObArray *pArr)
{
	ASSERT(pArr);
	pcbo->ResetContent();
	int iPos=0;
	CItem *pItem;
	for(int i= 0;i<pArr->GetSize();i++)
	{
		pItem = (CItem*)pArr->GetAt(i);
		if(pItem)
		{
			iPos = pcbo->InsertString(pcbo->GetCount(),pItem->m_F_ItemName);
			pcbo->SetItemData(iPos,pItem->m_F_ID);
		}
	}
	if(pcbo->GetCount()>0)
		pcbo->SetCurSel(0);
	return pcbo->GetCount();
}

void CfoodTrackDoc::FreeAllData()
{
	CItem *pItem;
	CStudent *pStu;
	for(int i=0;i<m_arrExamType.GetSize();i++)
	{
		pItem = m_arrExamType.GetAt(i);
		delete pItem;
	}
	m_arrExamType.RemoveAll();
	for(i=0;i<m_arrStudentType.GetSize();i++)
	{
		pItem = m_arrStudentType.GetAt(i);
		delete pItem;
	}
	m_arrStudentType.RemoveAll();
	for(i=0;i<m_arrStudent.GetSize();i++)
	{
		pStu = m_arrStudent.GetAt(i);
		delete pStu;
	}
	m_arrStudent.RemoveAll();
	FreeAllClass();
}

int CfoodTrackDoc::FillStudentsToListctrl(CListCtrl *pListCtrl, CString sSex, CString sName)
{
	ASSERT(pListCtrl);
	pListCtrl->DeleteAllItems();
	while(pListCtrl->DeleteColumn(0)){}
	LV_ITEM lvitem;
	CStudent *pStu;
	CItem *pItem;
	CString sTmp;
	int i=0,iPos=0;
	pListCtrl->InsertColumn(0,"*",LVCFMT_LEFT,30,-1);
	pListCtrl->InsertColumn(1,"姓名",LVCFMT_LEFT,80,-1);
	pListCtrl->InsertColumn(2,"性别",LVCFMT_LEFT,50,-1);
	pListCtrl->InsertColumn(3,"身份证",LVCFMT_LEFT,130,-1);
	pListCtrl->InsertColumn(4,"联系地址",LVCFMT_LEFT,150,-1);
	pListCtrl->InsertColumn(5,"电话",LVCFMT_LEFT,100,-1);
	pListCtrl->InsertColumn(6,"日期",LVCFMT_LEFT,80,-1);
	pListCtrl->InsertColumn(7,"车号",LVCFMT_LEFT,80,-1);
	pListCtrl->InsertColumn(8,"类别",LVCFMT_LEFT,80,-1);
	pListCtrl->InsertColumn(9,"备注",LVCFMT_LEFT,200,-1);
	BOOL bShow=false;
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
			bShow = true;
			if(!sSex.IsEmpty())
			{
				bShow = (pStu->m_F_Sex.Compare(sSex)==0);
			}
			if(!sName.IsEmpty())
			{
				bShow = (pStu->m_F_ItemName.Find(sName,0)>=0);
			}
			//*/姓名/性别/身份证/联系地址/电话/日期/车号/类别/备注
			if(bShow)
			{
				iPos = pListCtrl->InsertItem(&lvitem);
				pListCtrl->SetItemText(iPos,1,pStu->m_F_ItemName);
				pListCtrl->SetItemText(iPos,2,pStu->m_F_Sex);
				pListCtrl->SetItemText(iPos,3,pStu->m_F_SN);
				pListCtrl->SetItemText(iPos,4,pStu->m_F_Address);
				pListCtrl->SetItemText(iPos,5,pStu->m_F_Tel);
				sTmp.Format("%d-%d-%d",pStu->m_F_Date.GetYear(),pStu->m_F_Date.GetMonth(),pStu->m_F_Date.GetDay());
				pListCtrl->SetItemText(iPos,6,sTmp);
				pListCtrl->SetItemText(iPos,7,pStu->m_F_AutoNo);
				pItem = GetItemByID(&m_arrStudentType,pStu->m_F_TypeID);  
				if(pItem)
					pListCtrl->SetItemText(iPos,8,pItem->m_F_ItemName);
				pListCtrl->SetItemText(iPos,9,pStu->m_F_Remark);
				pListCtrl->SetItemData(iPos,pStu->m_F_ID);
			}
		}
	}
	return pListCtrl->GetItemCount();
}

int CfoodTrackDoc::ReadClasss(CTime tmStart, CTime tmEnd,CString sAutoNo,CString sTeacher)
{
	FreeAllClass();
	CRstClass rsBill;
	CClass *pClass;
	if(sAutoNo.IsEmpty())
		sAutoNo = '%';
	if(sTeacher.IsEmpty())
		sTeacher = '%';
	if(tmStart>0 && tmEnd>0)
	{
		rsBill.m_strFilter.Format("F_Date>=#%d-%d-%d# And F_Date<=#%d-%d-%d# And F_AutoNo Like '%s' And F_Teacher Like '%s'",
			tmStart.GetYear(),tmStart.GetMonth(),tmStart.GetDay(),
			tmEnd.GetYear(),tmEnd.GetMonth(),tmEnd.GetDay(),
			sAutoNo,sTeacher);
	}
	else
		rsBill.m_strFilter.Format("F_AutoNo Like '%s' And F_Teacher Like '%s'",sAutoNo,sTeacher);
	rsBill.m_strSort = "F_Date,F_Noon";
	rsBill.Open();
	while(!rsBill.IsEOF())
	{
		pClass = new CClass;
		pClass->m_F_AutoNo = rsBill.m_F_AutoNo;
		pClass->m_F_Date = rsBill.m_F_Date;
		pClass->m_F_ID = rsBill.m_F_ID;
		pClass->m_F_NoonID = rsBill.m_F_Noon;
		pClass->m_F_Remark = rsBill.m_F_Remark;
		pClass->m_F_Teacher = rsBill.m_F_Teacher;
		m_arrClass.Add(pClass);
		rsBill.MoveNext();
	}
	rsBill.Close();
	//明细
	CRstClassList rsSub;
	CStudent *pStu,*pStu1;
	rsSub.m_strSort = "F_ClassID,F_ID";
	rsSub.Open();
	while(!rsSub.IsEOF())
	{
		pClass = (CClass*)GetItemByID(&m_arrClass,rsSub.m_F_ClassID);
		if(pClass)
		{
			pStu1 = (CStudent*)GetItemByID(&m_arrStudent,rsSub.m_F_StudentID);
			if(pStu1)
			{
				pStu = new CStudent;
				pStu->m_F_Address = pStu1->m_F_Address;
				pStu->m_F_AutoNo = pStu1->m_F_AutoNo;
				pStu->m_F_Date = pStu1->m_F_Date;
				pStu->m_F_ID = pStu1->m_F_ID;
				pStu->m_F_ItemName = pStu1->m_F_ItemName;
				pStu->m_F_Remark = pStu1->m_F_Remark;
				pStu->m_F_Sex = pStu1->m_F_Sex;
				pStu->m_F_SN = pStu1->m_F_SN;
				pStu->m_F_Tel = pStu1->m_F_Tel;
				pStu->m_F_TypeID = pStu1->m_F_TypeID;

				pStu->m_nExamTypeID = rsSub.m_F_ExamTypeID;
				pStu->m_tmEnd = rsSub.m_F_DateEnd;
				pStu->m_tmExamField = rsSub.m_F_DateField;
				pStu->m_tmExamRoad = rsSub.m_F_DateRoad;
				pStu->m_tmUpAuto = rsSub.m_F_DateUpAuto;
				
				pClass->m_arrStudent.Add(pStu);
			}
		}
		rsSub.MoveNext();
	}
	rsSub.Close();

	return m_arrClass.GetSize();
}

void CfoodTrackDoc::FreeAllClass()
{
	for(int i=0;i<m_arrClass.GetSize();i++)
	{
		delete m_arrClass[i];
	}
	m_arrClass.RemoveAll();
}
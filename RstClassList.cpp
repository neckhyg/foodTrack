// RstClassList.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "RstClassList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRstClassList

IMPLEMENT_DYNAMIC(CRstClassList, CRecordset)

CRstClassList::CRstClassList(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRstClassList)
	m_F_ID = 0;
	m_F_ClassID = 0;
	m_F_StudentID = 0;
	m_F_ExamTypeID = 0;
	m_F_DateUpAuto = 0;
	m_F_DateField = 0;
	m_F_DateRoad = 0;
	m_F_DateEnd = 0;
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	this->m_pDatabase = &pApp->m_db; 
	m_nDefaultType = pApp->m_nOpenType;
}


CString CRstClassList::GetDefaultConnect()
{
	return _T("ODBC;DSN=localserver");
}

CString CRstClassList::GetDefaultSQL()
{
	return _T("[T_ClassList]");
}

void CRstClassList::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRstClassList)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[F_ID]"), m_F_ID);
	RFX_Long(pFX, _T("[F_ClassID]"), m_F_ClassID);
	RFX_Long(pFX, _T("[F_StudentID]"), m_F_StudentID);
	RFX_Long(pFX, _T("[F_ExamTypeID]"), m_F_ExamTypeID);
	RFX_Date(pFX, _T("[F_DateUpAuto]"), m_F_DateUpAuto);
	RFX_Date(pFX, _T("[F_DateField]"), m_F_DateField);
	RFX_Date(pFX, _T("[F_DateRoad]"), m_F_DateRoad);
	RFX_Date(pFX, _T("[F_DateEnd]"), m_F_DateEnd);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRstClassList diagnostics

#ifdef _DEBUG
void CRstClassList::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRstClassList::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

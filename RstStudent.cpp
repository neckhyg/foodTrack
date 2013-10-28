// RstStudent.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "RstStudent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRstStudent

IMPLEMENT_DYNAMIC(CRstStudent, CRecordset)

CRstStudent::CRstStudent(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRstStudent)
	m_F_ID = 0;
	m_F_Name = _T("");
	m_F_Sex = _T("");
	m_F_SN = _T("");
	m_F_Address = _T("");
	m_F_Tel = _T("");
	m_F_AutoNo = _T("");
	m_F_TypeID = 0;
	m_F_Remark = _T("");
	m_F_Date = 0;
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	this->m_pDatabase = &pApp->m_db; 
	m_nDefaultType = pApp->m_nOpenType;
}


CString CRstStudent::GetDefaultConnect()
{
	return _T("ODBC;DSN=localserver");
}

CString CRstStudent::GetDefaultSQL()
{
	return _T("[T_Student]");
}

void CRstStudent::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRstStudent)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[F_ID]"), m_F_ID);
	RFX_Text(pFX, _T("[F_Name]"), m_F_Name);
	RFX_Text(pFX, _T("[F_Sex]"), m_F_Sex);
	RFX_Text(pFX, _T("[F_SN]"), m_F_SN);
	RFX_Text(pFX, _T("[F_Address]"), m_F_Address);
	RFX_Text(pFX, _T("[F_Tel]"), m_F_Tel);
	RFX_Date(pFX, _T("[F_Date]"), m_F_Date);
	RFX_Text(pFX, _T("[F_AutoNo]"), m_F_AutoNo);
	RFX_Long(pFX, _T("[F_TypeID]"), m_F_TypeID);
	RFX_Text(pFX, _T("[F_Remark]"), m_F_Remark);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRstStudent diagnostics

#ifdef _DEBUG
void CRstStudent::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRstStudent::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

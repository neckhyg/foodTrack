// RstClass.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "RstClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRstClass

IMPLEMENT_DYNAMIC(CRstClass, CRecordset)

CRstClass::CRstClass(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRstClass)
	m_F_ID = 0;
	m_F_AutoNo = _T("");
	m_F_Teacher = _T("");
	m_F_Noon = 0;
	m_F_Remark = _T("");
	m_F_Date = 0;
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	this->m_pDatabase = &pApp->m_db; 
	m_nDefaultType = pApp->m_nOpenType;
}


CString CRstClass::GetDefaultConnect()
{
	return _T("ODBC;DSN=localserver");
}

CString CRstClass::GetDefaultSQL()
{
	return _T("[T_Class]");
}

void CRstClass::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRstClass)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[F_ID]"), m_F_ID);
	RFX_Text(pFX, _T("[F_AutoNo]"), m_F_AutoNo);
	RFX_Text(pFX, _T("[F_Teacher]"), m_F_Teacher);
	RFX_Date(pFX, _T("[F_Date]"), m_F_Date);
	RFX_Long(pFX, _T("[F_Noon]"), m_F_Noon);
	RFX_Text(pFX, _T("[F_Remark]"), m_F_Remark);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRstClass diagnostics

#ifdef _DEBUG
void CRstClass::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRstClass::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

// RstExamType.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "RstExamType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRstExamType

IMPLEMENT_DYNAMIC(CRstExamType, CRecordset)

CRstExamType::CRstExamType(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRstExamType)
	m_F_ID = 0;
	m_F_ItemName = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	this->m_pDatabase = &pApp->m_db; 
	m_nDefaultType = pApp->m_nOpenType;
}


CString CRstExamType::GetDefaultConnect()
{
	return _T("ODBC;DSN=localserver");
}

CString CRstExamType::GetDefaultSQL()
{
	return _T("[T_iExamType]");
}

void CRstExamType::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRstExamType)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[F_ID]"), m_F_ID);
	RFX_Text(pFX, _T("[F_ItemName]"), m_F_ItemName);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRstExamType diagnostics

#ifdef _DEBUG
void CRstExamType::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRstExamType::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

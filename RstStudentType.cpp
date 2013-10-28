// RstStudentType.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "RstStudentType.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRstStudentType

IMPLEMENT_DYNAMIC(CRstStudentType, CRecordset)

CRstStudentType::CRstStudentType(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRstStudentType)
	m_F_ID = 0;
	m_F_ItemName = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	this->m_pDatabase = &pApp->m_db; 
	m_nDefaultType = pApp->m_nOpenType;
}


CString CRstStudentType::GetDefaultConnect()
{
	return _T("ODBC;DSN=localserver");
}

CString CRstStudentType::GetDefaultSQL()
{
	return _T("[T_iStudentType]");
}

void CRstStudentType::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRstStudentType)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[F_ID]"), m_F_ID);
	RFX_Text(pFX, _T("[F_ItemName]"), m_F_ItemName);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRstStudentType diagnostics

#ifdef _DEBUG
void CRstStudentType::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRstStudentType::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

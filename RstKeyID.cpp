// RstKeyID.cpp : implementation file
//

#include "stdafx.h"
#include "foodTrack.h"
#include "RstKeyID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRstKeyID

IMPLEMENT_DYNAMIC(CRstKeyID, CRecordset)

CRstKeyID::CRstKeyID(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRstKeyID)
	m_F_CurMaxID = 0;
	m_F_TableName = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	CfoodTrackApp *pApp=(CfoodTrackApp*)AfxGetApp();
	this->m_pDatabase = &pApp->m_db; 
	m_nDefaultType = pApp->m_nOpenType;
}


CString CRstKeyID::GetDefaultConnect()
{
	return _T("ODBC;DSN=localserver");
}

CString CRstKeyID::GetDefaultSQL()
{
	return _T("T_KeyID");
}

void CRstKeyID::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRstKeyID)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[F_CurMaxID]"), m_F_CurMaxID);
	RFX_Text(pFX, _T("[F_TableName]"), m_F_TableName);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRstKeyID diagnostics

#ifdef _DEBUG
void CRstKeyID::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRstKeyID::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

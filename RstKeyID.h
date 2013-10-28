#if !defined(AFX_RSTKEYID_H__EB2F7C00_1952_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_RSTKEYID_H__EB2F7C00_1952_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RstKeyID.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRstKeyID recordset

class CRstKeyID : public CRecordset
{
public:
	CRstKeyID(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRstKeyID)

// Field/Param Data
	//{{AFX_FIELD(CRstKeyID, CRecordset)
	long	m_F_CurMaxID;
	CString	m_F_TableName;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRstKeyID)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSTKEYID_H__EB2F7C00_1952_11D8_8C25_000AEB143A3A__INCLUDED_)

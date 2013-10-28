#if !defined(AFX_RSTEXAMTYPE_H__D2236A57_193F_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_RSTEXAMTYPE_H__D2236A57_193F_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RstExamType.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRstExamType recordset

class CRstExamType : public CRecordset
{
public:
	CRstExamType(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRstExamType)

// Field/Param Data
	//{{AFX_FIELD(CRstExamType, CRecordset)
	long	m_F_ID;
	CString	m_F_ItemName;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRstExamType)
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

#endif // !defined(AFX_RSTEXAMTYPE_H__D2236A57_193F_11D8_8C25_000AEB143A3A__INCLUDED_)

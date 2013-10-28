#if !defined(AFX_RSTSTUDENTTYPE_H__D2236A58_193F_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_RSTSTUDENTTYPE_H__D2236A58_193F_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RstStudentType.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRstStudentType recordset

class CRstStudentType : public CRecordset
{
public:
	CRstStudentType(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRstStudentType)

// Field/Param Data
	//{{AFX_FIELD(CRstStudentType, CRecordset)
	long	m_F_ID;
	CString	m_F_ItemName;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRstStudentType)
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

#endif // !defined(AFX_RSTSTUDENTTYPE_H__D2236A58_193F_11D8_8C25_000AEB143A3A__INCLUDED_)

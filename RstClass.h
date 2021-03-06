#if !defined(AFX_RSTCLASS_H__BF972AC0_19C0_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_RSTCLASS_H__BF972AC0_19C0_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RstClass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRstClass recordset

class CRstClass : public CRecordset
{
public:
	CRstClass(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRstClass)

// Field/Param Data
	//{{AFX_FIELD(CRstClass, CRecordset)
	long	m_F_ID;
	CString	m_F_AutoNo;
	CString	m_F_Teacher;
	CTime	m_F_Date;
	long	m_F_Noon;
	CString	m_F_Remark;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRstClass)
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

#endif // !defined(AFX_RSTCLASS_H__BF972AC0_19C0_11D8_8C25_000AEB143A3A__INCLUDED_)

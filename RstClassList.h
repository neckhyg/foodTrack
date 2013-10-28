#if !defined(AFX_RSTCLASSLIST_H__BF972AC1_19C0_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_RSTCLASSLIST_H__BF972AC1_19C0_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RstClassList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRstClassList recordset

class CRstClassList : public CRecordset
{
public:
	CRstClassList(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRstClassList)

// Field/Param Data
	//{{AFX_FIELD(CRstClassList, CRecordset)
	long	m_F_ID;
	long	m_F_ClassID;
	long	m_F_StudentID;
	long	m_F_ExamTypeID;
	CTime	m_F_DateUpAuto;
	CTime	m_F_DateField;
	CTime	m_F_DateRoad;
	CTime	m_F_DateEnd;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRstClassList)
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

#endif // !defined(AFX_RSTCLASSLIST_H__BF972AC1_19C0_11D8_8C25_000AEB143A3A__INCLUDED_)

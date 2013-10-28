#if !defined(AFX_RSTSTUDENT_H__D2236A54_193F_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_RSTSTUDENT_H__D2236A54_193F_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RstStudent.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRstStudent recordset

class CRstStudent : public CRecordset
{
public:
	CRstStudent(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRstStudent)

// Field/Param Data
	//{{AFX_FIELD(CRstStudent, CRecordset)
	long	m_F_ID;
	CString	m_F_Name;
	CString	m_F_Sex;
	CString	m_F_SN;
	CString	m_F_Address;
	CString	m_F_Tel;
	CTime	m_F_Date;
	CString	m_F_AutoNo;
	long	m_F_TypeID;
	CString	m_F_Remark;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRstStudent)
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

#endif // !defined(AFX_RSTSTUDENT_H__D2236A54_193F_11D8_8C25_000AEB143A3A__INCLUDED_)

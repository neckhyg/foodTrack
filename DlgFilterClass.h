#if !defined(AFX_DLGFILTERCLASS_H__8D97D0E0_1A12_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_DLGFILTERCLASS_H__8D97D0E0_1A12_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgFilterClass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFilterClass dialog

class CDlgFilterClass : public CDialog
{
// Construction
public:
	CDlgFilterClass(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgFilterClass)
	enum { IDD = IDD_DIALOG_FILTERCLASS };
	CButton	m_btnOk;
	CButton	m_btnCancel;
	CTime	m_tmStart;
	CTime	m_tmEnd;
	CString	m_sAutoNo;
	CString	m_sTeacher;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFilterClass)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgFilterClass)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFILTERCLASS_H__8D97D0E0_1A12_11D8_8C25_000AEB143A3A__INCLUDED_)

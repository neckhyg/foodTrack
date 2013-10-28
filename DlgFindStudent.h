#if !defined(AFX_DLGFINDSTUDENT_H__8D97D0E1_1A12_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_DLGFINDSTUDENT_H__8D97D0E1_1A12_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgFindStudent.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgFindStudent dialog

class CDlgFindStudent : public CDialog
{
// Construction
public:
	CDlgFindStudent(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgFindStudent)
	enum { IDD = IDD_DIALOG_FINDSTUDENT };
	CString	m_sName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgFindStudent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgFindStudent)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFINDSTUDENT_H__8D97D0E1_1A12_11D8_8C25_000AEB143A3A__INCLUDED_)

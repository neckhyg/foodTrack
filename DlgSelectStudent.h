#if !defined(AFX_DLGSELECTSTUDENT_H__31FD4180_1962_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_DLGSELECTSTUDENT_H__31FD4180_1962_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSelectStudent.h : header file
//
#include "Student.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgSelectStudent dialog

class CDlgSelectStudent : public CDialog
{
// Construction
public:
	
	CStudent* m_pStudent;
	CStudent* SelectStudent();
	CDlgSelectStudent(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSelectStudent)
	enum { IDD = IDD_DIALOG_SELECTSTUDENT };
	CButton	m_btnCancel;
	CButton	m_btnSelect;
	CListCtrl	m_list;
	CComboBox	m_cbxSex;
	CString	m_sName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSelectStudent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSelectStudent)
	virtual void OnOK();
	afx_msg void OnButtonSelect();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSELECTSTUDENT_H__31FD4180_1962_11D8_8C25_000AEB143A3A__INCLUDED_)

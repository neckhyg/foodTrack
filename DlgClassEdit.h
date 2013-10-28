#if !defined(AFX_DLGCLASSEDIT_H__3521F360_195D_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_DLGCLASSEDIT_H__3521F360_195D_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgClassEdit.h : header file
//
#include "Student.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgClassEdit dialog

class CDlgClassEdit : public CDialog
{
// Construction
public: 
	long m_nOldID;
	void RemoveStudentByID(long ID);
	int FillStudents();
	CStudent* GetStudentByID(long nID);
	CDlgClassEdit(CWnd* pParent = NULL);   // standard constructor
	CTypedPtrArray <CObArray,CStudent*> m_arrStudent;

// Dialog Data
	//{{AFX_DATA(CDlgClassEdit)
	enum { IDD = IDD_DIALOG_CLASSEDIT };
	CButton	m_btnModify;
	CButton	m_btnCancel;
	CButton	m_btnSave;
	CListCtrl	m_list;
	CComboBox	m_cbxNoon;
	CButton	m_btnRemoveStudent;
	CButton	m_btnAddStudent;
	CTime	m_tmDate;
	CString	m_sAutoNo;
	CString	m_sTeacher;
	CString	m_sRemark;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgClassEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgClassEdit)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAddstudent();
	afx_msg void OnButtonRemovestudent();
	afx_msg void OnButtonModifystudent();
	virtual void OnOK();
	afx_msg void OnButtonSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCLASSEDIT_H__3521F360_195D_11D8_8C25_000AEB143A3A__INCLUDED_)

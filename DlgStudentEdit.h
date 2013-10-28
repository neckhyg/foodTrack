#if !defined(AFX_DLGSTUDENTEDIT_H__D2236A59_193F_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_DLGSTUDENTEDIT_H__D2236A59_193F_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgStudentEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgStudentEdit dialog

class CDlgStudentEdit : public CDialog
{
// Construction
public:
	long m_nOldID;
	CDlgStudentEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgStudentEdit)
	enum { IDD = IDD_DIALOG_STUDENTEDIT };
	CButton	m_btnCancel;
	CButton	m_btnSave;
	CComboBox	m_cbxType;
	CComboBox	m_cbxSex;
	CTime	m_tmDate;
	CString	m_sAddress;
	CString	m_sAutoNo;
	CString	m_sName;
	CString	m_sRemark;
	CString	m_sSN;
	CString	m_sTel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgStudentEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgStudentEdit)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSTUDENTEDIT_H__D2236A59_193F_11D8_8C25_000AEB143A3A__INCLUDED_)

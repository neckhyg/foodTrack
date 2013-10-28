#if !defined(AFX_DLGSTUDENTINFOR_H__3FD382E0_19B9_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_DLGSTUDENTINFOR_H__3FD382E0_19B9_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgStudentInfor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgStudentInfor dialog
class CStudent;
class CDlgStudentInfor : public CDialog
{
// Construction
public:
	CStudent* m_pStu;
	CDlgStudentInfor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgStudentInfor)
	enum { IDD = IDD_DIALOG_STUDENTINFOR };
	CComboBox	m_cbxExamType;
	CTime	m_tmEnd;
	CTime	m_tmExamField;
	CTime	m_tmExamRoad;
	CTime	m_tmUpAuto;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgStudentInfor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgStudentInfor)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSTUDENTINFOR_H__3FD382E0_19B9_11D8_8C25_000AEB143A3A__INCLUDED_)

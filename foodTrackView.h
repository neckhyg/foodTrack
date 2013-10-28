// AutoStuMisView.h : interface of the CAutoStuMisView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOSTUMISVIEW_H__D2236A4C_193F_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_AUTOSTUMISVIEW_H__D2236A4C_193F_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CfoodTrackView : public CListView
{
protected: // create from serialization only
	CfoodTrackView();
	DECLARE_DYNCREATE(CfoodTrackView)

// Attributes
public:
	CfoodTrackDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CfoodTrackView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	void FindStudent();
	void FilterClass();
	BOOL KillItemByID(int ID);
	int m_nDataType;
	virtual ~CfoodTrackView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAutoStuMisView)
	afx_msg void OnDataStudent();
	afx_msg void OnViewRefresh();
	afx_msg void OnUpdateDataStudent(CCmdUI* pCmdUI);
	afx_msg void OnDataClass();
	afx_msg void OnUpdateDataClass(CCmdUI* pCmdUI);
	afx_msg void OnEditAddnew();
	afx_msg void OnEditModify();
	afx_msg void OnEditDelete();
	afx_msg void OnEditSearch();
	afx_msg void OnViewCleardata();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AutoStuMisView.cpp
inline CfoodTrackDoc* CfoodTrackView::GetDocument()
   { return (CfoodTrackDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOSTUMISVIEW_H__D2236A4C_193F_11D8_8C25_000AEB143A3A__INCLUDED_)

#pragma once
#include "DlgComm.h"
#include "DlgCardReviewer.h"

// CfoodTrackListView 视图

class CfoodTrackListView : public CListView
{
	DECLARE_DYNCREATE(CfoodTrackListView)

protected:
	CfoodTrackListView();           // 动态创建所使用的受保护的构造函数
	virtual ~CfoodTrackListView();
// Attributes
public:
	CfoodTrackDoc* GetDocument();
// Implementation
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
public:
	void FindStudent();
	void FilterClass();
	BOOL KillItemByID(int ID);
	int m_nDataType;
	CDlgComm* m_pDlgComm;
	CDlgCardReviewer *m_pDlgCardReviewer;
public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	//{{AFX_MSG(CfoodTrackView)
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
public:
	afx_msg void OnDataWeight();
};

#ifndef _DEBUG  // debug version in foodTrackView.cpp
inline CfoodTrackDoc* CfoodTrackListView::GetDocument()
   { return (CfoodTrackDoc*)m_pDocument; }
#endif

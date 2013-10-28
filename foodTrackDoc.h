
// foodTrackDoc.h : CfoodTrackDoc ��Ľӿ�
//


#pragma once
#include "foodTrackSet.h"
#include "Item.h"
#include "Student.h"
#include "Class.h"



class CfoodTrackDoc : public CDocument
{
protected: // �������л�����
	CfoodTrackDoc();
	DECLARE_DYNCREATE(CfoodTrackDoc)
// Attributes
public:
	CTypedPtrArray <CObArray,CItem*> m_arrExamType;
	CTypedPtrArray <CObArray,CItem*> m_arrStudentType;
	CTypedPtrArray <CObArray,CStudent*> m_arrStudent;
	CTypedPtrArray <CObArray,CClass*> m_arrClass;
// ����
public:
	//CfoodTrackSet m_foodTrackSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	void FreeAllClass();
	int ReadClasss(CTime tmStart, CTime tmEnd,CString sAutoNo,CString sTeacher);
	int FillStudentsToListctrl(CListCtrl *pListCtrl,CString sSex,CString sName);
	void FreeAllData();
	int FillItemsToComboBox(CComboBox *pcbo,CObArray *pArr);
	CItem* GetItemByID(CObArray *pArr,long nID);
	void ReadInitData();
	virtual ~CfoodTrackDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

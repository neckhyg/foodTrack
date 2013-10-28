
// foodTrackDoc.h : CfoodTrackDoc 类的接口
//


#pragma once
#include "foodTrackSet.h"
#include "Item.h"
#include "Student.h"
#include "Class.h"



class CfoodTrackDoc : public CDocument
{
protected: // 仅从序列化创建
	CfoodTrackDoc();
	DECLARE_DYNCREATE(CfoodTrackDoc)
// Attributes
public:
	CTypedPtrArray <CObArray,CItem*> m_arrExamType;
	CTypedPtrArray <CObArray,CItem*> m_arrStudentType;
	CTypedPtrArray <CObArray,CStudent*> m_arrStudent;
	CTypedPtrArray <CObArray,CClass*> m_arrClass;
// 特性
public:
	//CfoodTrackSet m_foodTrackSet;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
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

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

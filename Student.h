// Student.h: interface for the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__D2236A56_193F_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_STUDENT_H__D2236A56_193F_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Item.h"

class CItem;
class CStudent  : public CItem
{
public:
	CStudent();
	virtual ~CStudent();
	CString m_F_Sex;
	CString m_F_SN;
	CString m_F_Address;
	CString m_F_Tel;
	CTime m_F_Date;
	CString m_F_AutoNo;
	long m_F_TypeID;

	CTime m_tmUpAuto;		//上车时间
	CTime m_tmExamField;	//场考时间
	CTime m_tmExamRoad;		//路考时间
	int m_nExamTypeID;		//考试类型
	CTime m_tmEnd;			//发证日期

};

#endif // !defined(AFX_STUDENT_H__D2236A56_193F_11D8_8C25_000AEB143A3A__INCLUDED_)

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

	CTime m_tmUpAuto;		//�ϳ�ʱ��
	CTime m_tmExamField;	//����ʱ��
	CTime m_tmExamRoad;		//·��ʱ��
	int m_nExamTypeID;		//��������
	CTime m_tmEnd;			//��֤����

};

#endif // !defined(AFX_STUDENT_H__D2236A56_193F_11D8_8C25_000AEB143A3A__INCLUDED_)

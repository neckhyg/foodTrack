// Class.h: interface for the CClass class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLASS_H__BF972AC2_19C0_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_CLASS_H__BF972AC2_19C0_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Item.h"

class CStudent;
class CClass : public CItem
{
public:
	CClass();
	virtual ~CClass();

	CString m_F_AutoNo;
	CString m_F_Teacher;
	CTime m_F_Date;
	int m_F_NoonID;
	CString m_F_Remark;

	CTypedPtrArray <CObArray,CStudent*> m_arrStudent;

};

#endif // !defined(AFX_CLASS_H__BF972AC2_19C0_11D8_8C25_000AEB143A3A__INCLUDED_)

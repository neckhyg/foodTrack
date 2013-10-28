// Item.h: interface for the CItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEM_H__D2236A55_193F_11D8_8C25_000AEB143A3A__INCLUDED_)
#define AFX_ITEM_H__D2236A55_193F_11D8_8C25_000AEB143A3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CItem  : public CObject
{
public:
	CItem();
	virtual ~CItem();
	long m_F_ID;
	CString m_F_ItemName;
	CString m_F_Remark;

};

#endif // !defined(AFX_ITEM_H__D2236A55_193F_11D8_8C25_000AEB143A3A__INCLUDED_)


// foodTrackSet.cpp : CfoodTrackSet 类的实现
//

#include "stdafx.h"
#include "foodTrack.h"
#include "foodTrackSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfoodTrackSet 实现

// 代码生成在 2013年10月14日星期一, 10:39

IMPLEMENT_DYNAMIC(CfoodTrackSet, CRecordset)

CfoodTrackSet::CfoodTrackSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_F_ID = 0;
	m_F_Name = "";
	m_F_Sex = "";
	m_F_SN = "";
	m_F_Address = "";
	m_F_Tel = "";
	m_F_Date;
	m_F_AutoNo = "";
	m_F_TypeID = 0;
	m_F_Remark = "";
	m_nFields = 10;
	m_nDefaultType = dynaset;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CfoodTrackSet::GetDefaultConnect()
{
	return _T("DSN=automis;UID=sa;PWD=123456;WSID=EAZYTEC-HEYG;DATABASE=automis");
}

CString CfoodTrackSet::GetDefaultSQL()
{
	return _T("[dbo].[T_Student]");
}

void CfoodTrackSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[F_ID]"), m_F_ID);
	RFX_Text(pFX, _T("[F_Name]"), m_F_Name);
	RFX_Text(pFX, _T("[F_Sex]"), m_F_Sex);
	RFX_Text(pFX, _T("[F_SN]"), m_F_SN);
	RFX_Text(pFX, _T("[F_Address]"), m_F_Address);
	RFX_Text(pFX, _T("[F_Tel]"), m_F_Tel);
	RFX_Date(pFX, _T("[F_Date]"), m_F_Date);
	RFX_Text(pFX, _T("[F_AutoNo]"), m_F_AutoNo);
	RFX_Long(pFX, _T("[F_TypeID]"), m_F_TypeID);
	RFX_Text(pFX, _T("[F_Remark]"), m_F_Remark);

}
/////////////////////////////////////////////////////////////////////////////
// CfoodTrackSet 诊断

#ifdef _DEBUG
void CfoodTrackSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CfoodTrackSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


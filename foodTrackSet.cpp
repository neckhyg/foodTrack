
// foodTrackSet.cpp : CfoodTrackSet ���ʵ��
//

#include "stdafx.h"
#include "foodTrack.h"
#include "foodTrackSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfoodTrackSet ʵ��

// ���������� 2013��10��14������һ, 10:39

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
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
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
// CfoodTrackSet ���

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



// foodTrackSet.h: CfoodTrackSet ��Ľӿ�
//


#pragma once

// ���������� 2013��10��14������һ, 10:39

class CfoodTrackSet : public CRecordset
{
public:
	CfoodTrackSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CfoodTrackSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_F_ID;
	CStringA	m_F_Name;
	CStringA	m_F_Sex;
	CStringA	m_F_SN;
	CStringA	m_F_Address;
	CStringA	m_F_Tel;
	CTime	m_F_Date;
	CStringA	m_F_AutoNo;
	long	m_F_TypeID;
	CStringA	m_F_Remark;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


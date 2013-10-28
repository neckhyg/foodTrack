
// foodTrack.h : foodTrack Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

enum OpenType
	{
		dynaset,        // uses SQLExtendedFetch, keyset driven cursor
		snapshot,       // uses SQLExtendedFetch, static cursor
		forwardOnly,    // uses SQLFetch
		dynamic         // uses SQLExtendedFetch, dynamic cursor
	};
enum DataType
{
	dtStudent,
	dtClass
};
// CfoodTrackApp:
// �йش����ʵ�֣������ foodTrack.cpp
//
class CfoodTrackDoc;
class CfoodTrackApp : public CWinAppEx
{
public:
	long GetCurMaxKeyID(CString sTableName, BOOL bUpdateNow);
	CfoodTrackDoc * m_pDoc;
	CString GetStrFromMyIni(CString sAppName, CString sKey, CString sDefault);
	int m_nDBType;
	CString m_sPassword;
	CString m_sUID;
	CString m_sDBN;
	CString m_sDBServer;
	char m_chrCommChar;
	char m_chrDateSplit;
	int m_nOpenType;
	CString m_sSystemSetupFile;
	CString m_sAppPath;
	CDatabase m_db;
	BOOLEAN InitializeDataBase(void);
public:
	CfoodTrackApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

};

extern CfoodTrackApp theApp;

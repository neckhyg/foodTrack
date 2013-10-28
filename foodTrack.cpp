
// foodTrack.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "foodTrack.h"
#include "MainFrm.h"

#include "foodTrackSet.h"
#include "foodTrackDoc.h"
#include "CfoodTrackListView.h"
#include "RstKeyID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CfoodTrackApp

BEGIN_MESSAGE_MAP(CfoodTrackApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CfoodTrackApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CfoodTrackApp ����

CfoodTrackApp::CfoodTrackApp()
{
	m_bHiColorIcons = TRUE;

	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���:
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("foodTrack.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CfoodTrackApp ����

CfoodTrackApp theApp;


// CfoodTrackApp ��ʼ��

BOOL CfoodTrackApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)

	InitializeDataBase();

/*	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);
*/
	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CfoodTrackDoc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(CfoodTrackListView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// ������׼ shell ���DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand ֮����
	return TRUE;
}

int CfoodTrackApp::ExitInstance()
{
	//TODO: �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CfoodTrackApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CfoodTrackApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CfoodTrackApp �Զ������/���淽��

void CfoodTrackApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CfoodTrackApp::LoadCustomState()
{
}

void CfoodTrackApp::SaveCustomState()
{
}

// CfoodTrackApp ��Ϣ�������



CString CfoodTrackApp::GetStrFromMyIni(CString sAppName, CString sKey, CString sDefault)
{
	char ss[MAX_PATH]; 
	DWORD dwLen=GetPrivateProfileString(sAppName,sKey,
		_T(""),
		ss,
		MAX_PATH,
		m_sSystemSetupFile);
	CString sR(ss);
	sR.TrimLeft();
	sR.TrimRight();
	return sR;

}
long CfoodTrackApp::GetCurMaxKeyID(CString sTableName, BOOL bUpdateNow)
{
	CRstKeyID rst;
	long ID=1;
	CString sql;
	rst.m_strFilter.Format(_T("F_TableName='%s'"),sTableName);
	rst.Open();
	if(rst.GetRecordCount()>0)
	{
        ID = rst.m_F_CurMaxID;
        if(bUpdateNow)
		{
            rst.Edit();
            rst.m_F_CurMaxID = ID + 1;
            rst.Update();
        }
    }
	else
	{
        rst.AddNew();
        rst.m_F_TableName = sTableName;
        rst.m_F_CurMaxID = ID + 1;
        rst.Update();
    }
    rst.Close();
	return ID;
}
BOOLEAN CfoodTrackApp::InitializeDataBase(void)
{
	//��ȡ����������·��,����sPath��
	GetModuleFileName(NULL,m_sAppPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	m_sAppPath.ReleaseBuffer ();
    int nPos;
	nPos=m_sAppPath.ReverseFind ('\\');
	m_sAppPath=m_sAppPath.Left(nPos);
	m_sSystemSetupFile = m_sAppPath + "\\HyConfig.dat";
	
	try
	{
		if(!m_db.IsOpen())
		{
			//��ȡʹ�õ����ݿ�����
			m_nDBType = atoi(GetStrFromMyIni("NetWork","DBDriver","1"));
			
			m_sDBServer = GetStrFromMyIni("NetWork","DBServer",m_sDBServer);
			m_sDBN = GetStrFromMyIni("NetWork","DBN",m_sDBN);
			m_sUID = GetStrFromMyIni("NetWork","UID",m_sUID);
			m_sPassword = GetStrFromMyIni("NetWork","PSW",m_sPassword);

			CString strCon;			
			switch(m_nDBType)
			{
			case 0://Access
				strCon.Format("DSN=MS Access 97 Database;DBQ=%s;DefaultDir=%s;DriverId=281;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=administrator;",
					m_sDBN,
					m_sAppPath);
				m_nOpenType = dynaset;
				m_chrDateSplit = '#';
				m_chrCommChar = '*';
				break;
			case 1://SQL SERVER 7.0
				strCon.Format("PROVIDER=MSDASQL;driver={SQL Server};server=%s;uid=sa;pwd=123456;database=%s;",
					m_sDBServer,
					m_sDBN);
				m_nOpenType = dynamic;
				m_chrDateSplit = '\'';
				m_chrCommChar = '%';
				break;
			case 2:
				strCon.Format("DSN=MS Access Database;DBQ=%s;DefaultDir=%s;DriverId=281;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=administrator;",
					m_sDBN,
					m_sAppPath);
				m_nOpenType = dynaset;
				m_chrDateSplit = '#';
				m_chrCommChar = '*';
				break;
			default:
				return false;
			}
			m_db.OpenEx(strCon,CDatabase::noOdbcDialog);				
		}
	}
	catch(CDBException e)
	{
		e.ReportError();
		e.Delete();
	}
}

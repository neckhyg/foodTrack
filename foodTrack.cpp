
// foodTrack.cpp : 定义应用程序的类行为。
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
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CfoodTrackApp 构造

CfoodTrackApp::CfoodTrackApp()
{
	m_bHiColorIcons = TRUE;

	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则:
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("foodTrack.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CfoodTrackApp 对象

CfoodTrackApp theApp;


// CfoodTrackApp 初始化

BOOL CfoodTrackApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)

	InitializeDataBase();

/*	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);
*/
	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CfoodTrackDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CfoodTrackListView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// 分析标准 shell 命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand 之后发生
	return TRUE;
}

int CfoodTrackApp::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CfoodTrackApp 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// 用于运行对话框的应用程序命令
void CfoodTrackApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CfoodTrackApp 自定义加载/保存方法

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

// CfoodTrackApp 消息处理程序



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
	//获取主程序所在路径,存在sPath中
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
			//读取使用的数据库类型
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

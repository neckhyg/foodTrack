// DlgCardReviewer.cpp : 实现文件
//

#include "stdafx.h"
#include "foodTrack.h"
#include "DlgCardReviewer.h"
#include "afxdialogex.h"
#include "StringOper.h"

#include "dcrf32.h"
#include "General.h"
#include <windows.h> 

#pragma comment(lib, "dcrf32.lib");
// CDlgCardReviewer 对话框

IMPLEMENT_DYNAMIC(CDlgCardReviewer, CDialog)

CDlgCardReviewer::CDlgCardReviewer(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCardReviewer::IDD, pParent)
{

}

CDlgCardReviewer::~CDlgCardReviewer()
{
}

void CDlgCardReviewer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST_Weight, m_WeightListBox);
}


BEGIN_MESSAGE_MAP(CDlgCardReviewer, CDialog)
	ON_BN_CLICKED(IDC_BTNReadWeight, &CDlgCardReviewer::OnBnClickedBtnreadweight)
	ON_MESSAGE(WM_COMM_RXCHAR, OnCommunication)
	ON_MESSAGE(WM_COMM_CTS_DETECTED, OnCTSDetected)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTNReadCard, &CDlgCardReviewer::OnBUTTONReadCard)
END_MESSAGE_MAP()


// CDlgCardReviewer 消息处理程序


void CDlgCardReviewer::OnBnClickedBtnreadweight()
{
	// TODO: 在此添加控件通知处理程序代码
	char cmdStr[] = "024142303303";
	char buf[100];
	memset(&buf, 0, sizeof(buf));
	/*GetDlgItemText(ID_EDIT1, buf, sizeof(buf));
	if (strcmp("NOT FOUND", buf) == 0)
		return;

	if (((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
		buf[strlen(buf)] = 13;
		*/
	Loadmeter2Str(&m_loadMeter[0],(unsigned char *)&buf,100);
//	m_Ports.WriteToPort(cmdStr);	
	m_Ports.WriteToPort(buf);
}

void CDlgCardReviewer::InitializeLoadMeter(){
	  unsigned char SouStr[2],DesStr[128];
	  m_loadMeter[0].cmdStart = 0x02;
	  m_loadMeter[0].address = 0x41; //'A'
	  m_loadMeter[0].cmd = 0x42;  //'B'称毛重
	   m_loadMeter[0].bCmd = TRUE;  //'B'称毛重
	  SouStr[0] = m_loadMeter[0].address;
	  SouStr[1] = m_loadMeter[0].cmd;
	   
	//  StrXor((BYTE*)&SouStr, 2,(BYTE*) &m_loadMeter[0].checkNum);
	  memset((void*)&DesStr,0,128);
	  UnsignedCharXor(SouStr, 2,(unsigned char*)&DesStr);

	  m_loadMeter[0].checkNum[0] = DesStr[0];
	   m_loadMeter[0].checkNum[1] = DesStr[1];
      m_loadMeter[0].cmdEnd = 0x03;
	 
	  memset((void*)&m_loadMeter[1],0,sizeof(m_loadMeter[1]));
	  m_loadMeter[1].bCmd = FALSE ;
	 
}
BOOL CDlgCardReviewer::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_EditWeight.SubclassDlgItem(IDC_EDITWeight, this);

	m_Edit.SubclassDlgItem(IDC_EDITStatus, this);

	CEdit  *pEdt= (CEdit*)GetDlgItem(IDC_EDITWeight);

	m_font.CreatePointFont(166,"Arial");

	pEdt->SetFont(&m_font);

	m_brush.CreateSolidBrush(RGB(126,126,126));

    InitializeLoadMeter();

	// init the ports
	
		if (m_Ports.InitPort(this, 10, 9600 ,'N',8,1))
			m_Ports.StartMonitoring();
		
		else
		{
			// port not found
			m_Edit.SetWindowText("NOT FOUND");
			m_Edit.EnableWindow(FALSE);
			m_EditWeight.EnableWindow(FALSE);
		}
    //    m_Edit.SetWindowText("NOT FOUND");
		m_EditWeight.SetWindowText("initial port cussess!");

		ConnectReader();

		//Findcard(&m_cardsnr);

		CreatMakeCardThread();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

LONG CDlgCardReviewer::OnCommunication(WPARAM ch, LPARAM port)
{
	
	
		CString string;
		char  weightValue[128];


		memset(weightValue,0,128);
		
		ReceiveStr2Loadmeter((unsigned char*)ch,WEIGHT0_CMD_RETURN_LEN,&m_loadMeter[1]);
		
		memcpy(weightValue,(char*)&(m_loadMeter[1].data[1]),7);
		
		//string += (char*)ch;
		double dWeight = atof(weightValue);
		//dWeight /=10;
		string.Format("%.3f",dWeight);
		//string += (char*)weightValue;
		m_EditWeight.SetWindowText(string);
		//m_ListBox.AddString(string);
	//	m_ListBox.SetSel(m_ListBox.GetCount()-1, TRUE);

	   return 0;
}

LONG CDlgCardReviewer::OnCTSDetected(WPARAM, LPARAM port)
{
	if (port < 10 || port > 14)
		return -1;

/*	CString string;
	string = "Clear To Send";
	m_ListBox[port-10].AddString(string);
	m_ListBox[port-10].SetSel(m_ListBox[port-10].GetCount()-1, TRUE);
	*/
	return 0;
}


HBRUSH CDlgCardReviewer::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	
	if(nCtlColor==CTLCOLOR_EDIT && pWnd->GetDlgCtrlID()==IDC_EDITWeight)

	{
		//LONG wndID=::GetWindowLong(pWnd->GetSafeHwnd(),GWL_ID);//获取窗口ID  
		
		//	if(wndID==IDC_EDITWeight)
			{
				pDC->SetTextColor(RGB(0,255,0));

			//	pDC->SetBkColor(RGB(255,255,0));

				pDC->SetBkMode(TRANSPARENT);

				hbr = (HBRUSH)m_brush;
				CRect rcClientRect;
				pWnd->GetClientRect(rcClientRect);    
				// CBrush br1(BkColor);                                       
			//	pDC->FillRect(rcClientRect,&m_brush);//通过填充的方式改变编辑框背景色 
		}
		 

	}
	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgCardReviewer::CloseReaderCom(void)
{
}


BOOL CDlgCardReviewer::InitReaderParam(void)
{

	BOOL initStatus;

	if((int)m_icdev > 0){
		initStatus = TRUE;
	}else{
		//初始化串口1，       
		m_icdev=dc_init(100,115200);
		if((int)m_icdev<=0)
		{
			AfxMessageBox("Init Com Error!");

			initStatus = FALSE;
		}
		else
		{
			//show("Init Com OK!");

			initStatus = TRUE;
		}
	}
	
	dc_beep(m_icdev,10);

	return initStatus;
}

//dc_load_key(int icdev,unsigned char _Mode,unsigned char _SecNr,unsigned char *_NKey);

BOOL CDlgCardReviewer::LoadReaderKey(unsigned char* key)
{
		BOOL bStatus;

	//下载密码，       
	int st;
//	unsigned char keyA[6]={0xff,0xff,0xff,0xff,0xff,0xff};
	st=dc_load_key(m_icdev,0,0,key);
	if(st!=0)
	{
		AfxMessageBox("Load Key Com Error!");

		bStatus = FALSE;
	}
	else
		bStatus = TRUE;

	return bStatus;
}

BOOL CDlgCardReviewer::ConnectReader(void)
{
	int st;
	CString linstr;
	BOOL bStatus;
	unsigned char keyA[6]={0xff,0xff,0xff,0xff,0xff,0xff};

	if(!InitReaderParam()) return FALSE;

	if(!LoadReaderKey(keyA))  return FALSE;

}
BOOL CDlgCardReviewer::ReaderAuthentic(int mode,int sector )
{
	//核对密码       
	int st;
	BOOL bStatus;
	st=dc_authentication(m_icdev,mode,sector);
	if(st!=0)
	{
		bStatus = FALSE;
		AfxMessageBox("Auth Card Error!");

	}
	else
		bStatus = TRUE;

	return bStatus;
}


BOOL CDlgCardReviewer::WriteBlock(int sector, int block, unsigned char* pData)
{
		//写数据     
	int st;
	unsigned char databuff[]={0x44,0x33,0x33,0x66,0x33,0x44,0x33,0x66,0x36,0x34,0x33,0x44,0x33,0x66,0x36,0x34,0x00};//
	char databuff2[33];
	BOOL bStatus;

	st=dc_write(m_icdev,block,pData);
    if(st!=0)
	{
   	   AfxMessageBox("Write Card Error!");
	   bStatus = FALSE;
	  
	}
    else
	{
	   bStatus = TRUE;
     //  show(databuff);
	}
	return bStatus;
}


BOOL CDlgCardReviewer::ReadBlock(int sector, int block, unsigned char* pData)
{
		//读数据     
	int st;
	unsigned char databuff[256]={0};//
	char databuff2[33];
	BOOL bStatus;

	st=dc_read(m_icdev,block,databuff);	
	if(st!=0){
		bStatus = FALSE;
        AfxMessageBox("Read Card Error!");
	}
		
	else
	{
		dc_beep(m_icdev,10);
		bStatus = TRUE;
		//show("Read Card Ok!");
		memset(databuff2,0,32);
		hex_a(databuff,(unsigned char *)databuff2,4);
		memcpy(pData,databuff2,16);
		AfxMessageBox(databuff2);
	}
	
	return bStatus;
}





BOOL CDlgCardReviewer::CloseReaderCom(int port)
{
	dc_exit(m_icdev);
	return 0;
}

DWORD WINAPI TreatThread(void * pParam)
{
	CDlgCardReviewer *dlgReviewer = (CDlgCardReviewer *)pParam;
	unsigned long ulSnr=0;
	if (NULL == dlgReviewer)
	{
		return -1;
	}
	bool bTrueIsIn = false;
	for(;; Sleep(1))
	{
		if (0 >= (int)dlgReviewer->m_icdev)
		{
			continue ;
		}
		if (bTrueIsIn)
		{
			if (!dlgReviewer->Findcard(&ulSnr))
			{
				dlgReviewer->CleanCardInfo();
				bTrueIsIn = false;
			}
			continue;
		}
		if (!dlgReviewer->Findcard(&ulSnr))
		{
			bTrueIsIn = false;
			continue;
		}
		bTrueIsIn = true;
		dlgReviewer->OnBUTTONReadCard();
	}
	
	return 0;
}
int CDlgCardReviewer::CreatMakeCardThread(void)
{
	DWORD threadId;
	HANDLE hThread;
	hThread  = ::CreateThread(0, 0x1000, TreatThread, (PVOID)this, 0, &threadId);
	//AfxBeginThread(TreatThread, (PVOID)this);
	return 0;
}
bool g_bTrueIsIn = true;



void CDlgCardReviewer::CleanCardInfo(void)
{
}


BOOL CDlgCardReviewer::Findcard(unsigned long *pSnr)
{
	int st;
	//unsigned char databuff[256]={0};//
	//char databuff2[33];
	BOOL bStatus;
	CString linstr;

	st=dc_card(m_icdev,0,pSnr);
	if(st!=0)
	{
		bStatus = FALSE;
		//AfxMessageBox("Find Card Error!");

	}
	else
	{

		bStatus = TRUE;
		linstr.Format("%d",m_cardsnr);
		//show(linstr);

		//AfxMessageBox(linstr);

	}
	return bStatus;
	
}


void CDlgCardReviewer::ShowCardInfo(void)
{
}


void CDlgCardReviewer::ReadCardContent(void)
{
}


void CDlgCardReviewer::OnBUTTONReadCard()
{
	// TODO: 在此添加控件通知处理程序代码
//	if(!ConnectReader()) return;

	if(!Findcard(&m_cardsnr)) return;

	if(!ReaderAuthentic(0,0)) return;

	
	unsigned char  databuf[256]={0};
	if(!ReadBlock(0,0,databuf)) return ;

}

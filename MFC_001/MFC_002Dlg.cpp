
// MFC_002Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_001.h"
#include "MFC_002Dlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma region DebugText调试函数，显示行数，函数名或文字
/*********************************************************************
配置：
1.新建Edit Control控件，设置多行显示，滚动条。
2.在XXX_XXDlg.h文件中声明 void DebugText(int line_temp, const char *func_temp);
3.在头文件定义中，定义 #define #include<sstream> ，using namespace std;

使用示例：
DebugText(__LINE__,__FUNCTION__); // 调试代码
DebugText(__LINE__,"未选中");// 调试代码

*********************************************************************/
#include<sstream>
using namespace std;

CString Debug_str;
stringstream Line_str; //需要添加 #define #include<sstream> ，using namespace std;

void MFC_002::DebugText(int line_temp, const char *func_temp)
{
	 Line_str<<line_temp; 
	 //string s1 = ss.str();
	 Debug_str += _T("L =" );
	 Debug_str += Line_str.str().c_str();
	 Debug_str += _T("," );
	 Debug_str += func_temp;
	 Debug_str += _T("\r\n");
	 SetDlgItemText(IDC_EDIT_debug,Debug_str);
	 Line_str.str(""); // 清空缓冲区
	 #pragma region edit control自动显示到最后一行
	 //*********edit control自动显示到最后一行***********************//
	 long len=Debug_str.GetLength();
	 ((CEdit*)GetDlgItem(IDC_EDIT_debug))->SetSel(len,len,false); // edit control自动显示到最后一行
	 //((CEdit*)GetDlgItem(IDC_EDIT_Debug1))->SetFocus();   // edit control自动将光标定位到最后一行
	 #pragma endregion
}
#pragma endregion


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


// MFC_002 对话框



MFC_002::MFC_002(CWnd* pParent /*=NULL*/)
	: CDialogEx(MFC_002::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MFC_002::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MFC_002, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &MFC_002::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MFC_002::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &MFC_002::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &MFC_002::OnBnClickedCheck2)
	ON_BN_CLICKED(IDOK, &MFC_002::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_PW, &MFC_002::OnEnChangeEditPw)
END_MESSAGE_MAP()


// MFC_002 消息处理程序

BOOL MFC_002::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	DebugText(__LINE__,__FUNCTION__); // 调试代码
	GetDlgItem(IDC_EDIT_PW)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PW)->ShowWindow(SW_HIDE);


	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void MFC_002::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void MFC_002::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	
		DebugText(__LINE__,__FUNCTION__); // 调试代码

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR MFC_002::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void MFC_002::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	DebugText(__LINE__,__FUNCTION__);// 调试代码
}


void MFC_002::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DebugText(__LINE__,__FUNCTION__);// 调试代码
}


void MFC_002::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
 	//下面是Checkbox的代码


	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
    int state = pBtn->GetCheck();
    if (state == 1) // 选中
    {
		DebugText(__LINE__,__FUNCTION__); // 调试代码
		GetDlgItem(IDC_EDIT_PW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PW)->ShowWindow(SW_SHOW);
		((CEdit*)GetDlgItem(IDC_EDIT_PW))->SetFocus();
    }
    else // 取消选中
    {
	   DebugText(__LINE__,"未选中");// 调试代码
	   
		GetDlgItem(IDC_EDIT_PW)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PW)->ShowWindow(SW_HIDE);
    }
	UpdateData(false);



}


void MFC_002::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	DebugText(__LINE__,__FUNCTION__);// 调试代码
}



void MFC_002::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MFC_002::OnEnChangeEditPw()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码



}

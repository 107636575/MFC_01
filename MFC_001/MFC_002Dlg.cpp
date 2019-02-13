
// MFC_002Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_001.h"
#include "MFC_002Dlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma region DebugText���Ժ�������ʾ������������������
/*********************************************************************
���ã�
1.�½�Edit Control�ؼ������ö�����ʾ����������
2.��XXX_XXDlg.h�ļ������� void DebugText(int line_temp, const char *func_temp);
3.��ͷ�ļ������У����� #define #include<sstream> ��using namespace std;

ʹ��ʾ����
DebugText(__LINE__,__FUNCTION__); // ���Դ���
DebugText(__LINE__,"δѡ��");// ���Դ���

*********************************************************************/
#include<sstream>
using namespace std;

CString Debug_str;
stringstream Line_str; //��Ҫ��� #define #include<sstream> ��using namespace std;

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
	 Line_str.str(""); // ��ջ�����
	 #pragma region edit control�Զ���ʾ�����һ��
	 //*********edit control�Զ���ʾ�����һ��***********************//
	 long len=Debug_str.GetLength();
	 ((CEdit*)GetDlgItem(IDC_EDIT_debug))->SetSel(len,len,false); // edit control�Զ���ʾ�����һ��
	 //((CEdit*)GetDlgItem(IDC_EDIT_Debug1))->SetFocus();   // edit control�Զ�����궨λ�����һ��
	 #pragma endregion
}
#pragma endregion


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


// MFC_002 �Ի���



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


// MFC_002 ��Ϣ�������

BOOL MFC_002::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	
	DebugText(__LINE__,__FUNCTION__); // ���Դ���
	GetDlgItem(IDC_EDIT_PW)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PW)->ShowWindow(SW_HIDE);


	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void MFC_002::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	
		DebugText(__LINE__,__FUNCTION__); // ���Դ���

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR MFC_002::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void MFC_002::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DebugText(__LINE__,__FUNCTION__);// ���Դ���
}


void MFC_002::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DebugText(__LINE__,__FUNCTION__);// ���Դ���
}


void MFC_002::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
 	//������Checkbox�Ĵ���


	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
    int state = pBtn->GetCheck();
    if (state == 1) // ѡ��
    {
		DebugText(__LINE__,__FUNCTION__); // ���Դ���
		GetDlgItem(IDC_EDIT_PW)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PW)->ShowWindow(SW_SHOW);
		((CEdit*)GetDlgItem(IDC_EDIT_PW))->SetFocus();
    }
    else // ȡ��ѡ��
    {
	   DebugText(__LINE__,"δѡ��");// ���Դ���
	   
		GetDlgItem(IDC_EDIT_PW)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PW)->ShowWindow(SW_HIDE);
    }
	UpdateData(false);



}


void MFC_002::OnBnClickedCheck2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DebugText(__LINE__,__FUNCTION__);// ���Դ���
}



void MFC_002::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void MFC_002::OnEnChangeEditPw()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������



}

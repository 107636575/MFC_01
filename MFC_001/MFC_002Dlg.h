
// MFC_002Dlg.h : 头文件
//

#pragma once


// MFC_002 对话框
class MFC_002 : public CDialogEx
{
// 构造
public:
	MFC_002(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_001_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	void DebugText(int line_temp, const char *func_temp,int Ctlr_ID);
	afx_msg void OnBnClickedBtnPwsubmit();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditPw();
	CString Edit_PW;
};
